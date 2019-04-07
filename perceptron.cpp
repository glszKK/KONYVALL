#include "perceptron.hpp"
#include <iostream>
#include <png++/png.hpp>

using namespace std;

int main (int argc, char **argv) 
{
  png::image <png::rgb_pixel> png_image ( argv[1] );
 
  int size = png_image.get_width() *png_image.get_height();

  Perceptron* p = new Perceptron ( 3, size, 256, 1 );

  double* image = new double[size];

	for (int i=0; i < png_image.get_width(); ++i)
		for (int j=0; j < png_image.get_height(); ++j)
			image [ i*png_image.get_width() +j ] = png_image[i][j].green;

  double value = (*p) ( image );

  cout << value << endl;

  delete p;
  delete [] image;

return 0;
}

