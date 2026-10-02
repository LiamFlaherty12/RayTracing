#include <iostream>
#include <fstream>
#include <cmath>
#include <filesystem>

int main() {

	const int width = 400;
	const int height = 300;

	std::ofstream image("image.ppm");


	//PPM header

	image << "P3\n";
	image << width << " " << height << "\n";
	image << "255\n";

	for (int y = 0; y < height; y++) {
		std::clog << "\rScanlines remaining: " << height - y - 1 << ' ' << std::flush;
		for (int x = 0; x < width; x++) {
			double r = static_cast<double>(x) / (width - 1);
			double g = static_cast<double>(y) / (height - 1);
			double b = 0.2;

			int ir = static_cast<int>(255.999 * r);
			int ig = static_cast<int>(255.999 * g);
			int ib = static_cast<int>(255.999 * b);

			image << ir << " " << ig << " " << ib << "\n";

		}

	}

	std::clog << "\nDone.\n";

	image.close();

	std::cout << "Rendered image.ppm\n";

	return 0;

}