#include "color.h"
#include "vec3.h"

#include <iostream>

int main() {
	// image
	int image_width = 400;
	int image_height = 300;

	


	//Render

	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	for (int j = 0; j < image_height; j++) {
		std::clog << "\rScanlines remaining: " << image_height - j - 1 << ' ' << std::flush;
		for (int i = 0; i < image_width; i++) {
			auto pixel_color = color(double(i) / (image_width - 1), double(i) / (image_height - 1), 0);
		}

	}

	std::clog << "\rDone.\n";


	std::cout << "Rendered image.ppm\n";

	return 0;

}