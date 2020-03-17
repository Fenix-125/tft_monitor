from PIL import Image
from argparse import ArgumentParser, RawTextHelpFormatter
from typing import List, Tuple

PICTURE_OUTPUT_FILE = "../include/display/pure_pixel_back_image.h"

option_parser = ArgumentParser(prog='update_background_img.py',
                               formatter_class=RawTextHelpFormatter,
                               description='Update the background image of the monitor interface.',
                               usage='%(prog)s [options]')

option_parser.add_argument('input_image', nargs=1,
                           help='image to source as the background image for the monitor interface')

option_parser.add_argument('--width', '-W', default=None, type=int,
                           help='width of the image. If it is smaller then the actual width, image will\n'
                                'be cropped form the left. Else it is set to the image width')
option_parser.add_argument('--height', '-H', default=None, type=int,
                           help='height of the image. If it is smaller then the actual height, image will\n'
                                'be cropped form the bottom. Else it is set to the image height')


class ImageComponents:
    """ well structured image components representation """

    def __init__(self, bit_map: List[str] or Tuple[str], w: int, h: int):
        self.bit_map = bit_map
        self.w = w
        self.h = h

    def __len__(self):
        return len(self.bit_map)

    def __getitem__(self, item):
        return self.bit_map[item]


def rgb565(r: int, g: int, b: int) -> int:
    """
    transform decimal RGB to hex RGB565
    """
    return ((r & 0b11111000) << 8) | (g & 0b11111100) << 3 | (b >> 3)


def parse_bin_file(file_name: str) -> ImageComponents:
    im = Image.open(file_name)
    px = im.load()
    res = []
    for line in range(im.size[0]):  # W
        for col in range(im.size[1] - 1, -1, -1):  # H
            px_inf = px[line, col][:3]  # out o 4 pixel info array
            res.append(str(hex(rgb565(*px_inf))))
    return ImageComponents(res, im.size[0], im.size[1])


def get_valid_source(image: ImageComponents, w: int = None, h: int = None) -> str:
    """
    Create an c++ header file with an array (c++ file content) representation of an image
    """
    res = "#ifndef TFT_MONITOR_PURE_PIXEL_BACK_IMAGE_H\n" \
          "#define TFT_MONITOR_PURE_PIXEL_BACK_IMAGE_H\n\n" \
          "#include <cstdint>\n\n" \
          f"#define BACK_IMAGE_W {320 if w is None or w > 320 else w}\n" \
          f"#define BACK_IMAGE_H {240 if h is None or h > 240 else h}\n\n" \
          "const uint16_t BACK_IMAGE_BITMAP[] = {"

    for i in range(len(image) - 1):
        res += image[i] + ', '

    res += image[len(image) - 1] + '};\n\n#endif //TFT_MONITOR_PURE_PIXEL_BACK_IMAGE_H\n'
    return res


def rectangular(x: int, y: int, w: int, h: int, color: int, image_w: int, image_h: int) -> ImageComponents:
    """ TODO: consider to add possibility to create an rectangular from command line
    generate an array of hex pixels, that represent in image
    """
    res = ['0x0000' for _ in range(image_h * image_w)]

    for dy in range(h):
        for dx in range(w):
            res[image_w * (y + dy) + x + dx] = color
    return ImageComponents(res, w, h)


if __name__ == '__main__':
    args = option_parser.parse_args()
    with open(PICTURE_OUTPUT_FILE, 'w+', encoding='utf-8') as f:
        f.write(get_valid_source(parse_bin_file(args.input_image[0]), args.width, args.height))
    print("SUCCESS")
