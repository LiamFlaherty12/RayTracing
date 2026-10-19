#include "color.h"
#include "ray.h"
#include "vec3.h"

#include <iostream>

color ray_color(const ray& r) {
	return color(0, 0, 0);
}

int main() {

	// image

	auto aspect_ratio = 16.0 / 9.0;
	int image_width = 400;

	// calculate image height, make sure it is at least 1 pixel high

	int image_height = int(image_width / aspect_ratio);;
	image_height = (image_height < 1) ? 1 : image_height;

	// Camera

	auto focal_length = 1.0;
	auto viewport_height = 2.0;
	auto viewport_width = viewport_height * (double(image_width) / image_width);
	auto camera_center = point3(0, 0, 0);

	// Calculate vectors across the horizontal and down the vertical viewport edges

	auto viewport_u = vec3(viewport_width, 0, 0);
	auto viewport_v = vec3(0, -viewport_height, 0);

	// Calculate the horizontal and vertical delta vectors from pixel to pixel

	auto pixel_delta_u = viewport_u / image_width;
	auto pixel_delta_v = viewport_v / image_height;




	

	


	//Render

	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	for (int j = 0; j < image_height; j++) {
		std::clog << "\rScanlines remaining: " << image_height - j - 1 << ' ' << std::flush;
		for (int i = 0; i < image_width; i++) {
			auto pixel_color = color(double(i) / (image_width - 1), double(i) / (image_height - 1), 0);
			write_color(std::cout, pixel_color);
		}

	}

	std::clog << "\rDone.\n";


	std::cout << "Rendered image.ppm\n";

	return 0;

}