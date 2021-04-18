import cv2
import sys

with open(sys.argv[2], 'w+') as header:

    header.write('''#pragma once
#include<vector>
#include<string>
std::vector<std::vector<std::vector<unsigned char>>> array = {
''')

    mask = cv2.imread(sys.argv[1])

    height, width, depth = mask.shape

    for i in range(height):
        header.write('\t{\n')
        for j in range(width):
            header.write('\t\t{')
            for color in range(depth):
                header.write(f'{mask[i, j, color]}, ')
            header.write('},\n')
        header.write('\t},\n')

    header.write('};')







