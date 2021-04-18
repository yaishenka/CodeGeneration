/** @author yaishenka
    @date 18.04.2021 */

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <iostream>
#include "GeneratedArray.h"

int main(int argc, char* argv[]) {
  if (argc < 3) {
    std::cout << "Program requires 2 arguments: path to image, path to output" << std::endl;
    return 1;
  }

  cv::Mat image = cv::imread(argv[1]);

  for (int i = 0; i < image.rows; ++i) {
    for (int j = 0; j < image.cols; ++j) {
      auto& current_pixel = image.at<cv::Vec3b>(i, j);

      for (int color = 0; color < image.channels(); ++color) {
        current_pixel[color] = array[std::abs(image.channels() - 1 - color)][current_pixel[color]][color];
      }
    }
  }

  cv::imwrite(argv[2], image);
}