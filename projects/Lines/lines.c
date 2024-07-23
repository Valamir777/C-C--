#include <stdio.h>
#include <stdlib.h>

#define PNG_SETJMP_NOT_SUPPORTED
#include <png.h>

#define WIDTH 500
#define HEIGHT 500
#define COLOR_DEPTH 8
#define INTERVAL 5

struct Pixel {
	png_byte r, g, b, a;
};

int main(int argc, char *argv[]) {
	srand(time(NULL));
	/* Declare PNG file for writing */
	FILE *pngImage;
	/* Check if an argument was passed */
	if (!argv[1]) {
        fprintf(stderr, "An argument was not passed\n");
	}
	else {
        pngImage = fopen(argv[1], "wb");
	}

	if (!pngImage) {
		fprintf(stderr, "could not open out.png\n");
		return 1;
	}

	/* initialize png data structures */
	png_structp png_ptr;
	png_infop info_ptr;

	png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (!png_ptr) {
		fprintf(stderr, "could not initialize png struct\n");
		return 1;
	}

	info_ptr = png_create_info_struct(png_ptr);
	if (!info_ptr) {
		png_destroy_write_struct(&png_ptr, (png_infopp)NULL);
		fclose(pngImage);
		return 1;
	}

	/* begin writing PNG File */
	png_init_io(png_ptr, pngImage);
	png_set_IHDR(png_ptr, info_ptr, WIDTH, HEIGHT, COLOR_DEPTH,
	             PNG_COLOR_TYPE_RGB_ALPHA, PNG_INTERLACE_NONE,
	             PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);
	png_write_info(png_ptr, info_ptr);

	/* allocate image data */
	struct Pixel *pixel_pointers[WIDTH];
    for (int row = 0; row < WIDTH; row++) {
            pixel_pointers[row] = calloc(WIDTH*2, sizeof(struct Pixel));
	}

	/* Draw Graph*/
	for (int row = 0; row < WIDTH; row++) {
        for (int col = 0; col < HEIGHT; col++) {
            if (row%25==0||col%25==0) {
                pixel_pointers[row][col].r = 0; //red
                pixel_pointers[row][col].g = 0; //green
                pixel_pointers[row][col].b = 0; //blue
                pixel_pointers[row][col].a = 225; //alpha
            } else {
                pixel_pointers[row][col].r = 225; //red
                pixel_pointers[row][col].g = 225; //green
                pixel_pointers[row][col].b = 225; //blue
                pixel_pointers[row][col].a = 180; //alpha
            }
        }
	}

	/* draw vertical lines */
	//for (int col = 0; col < WIDTH; col++) {
		//int bar_height = rand() % HEIGHT;
		//for (int row = 0; row < HEIGHT; row++) {
			//if (HEIGHT - row <= bar_height) {
				//row_pointers[row][col].r = 50; // red
				//row_pointers[row][col].g = 50; // green
				//row_pointers[row][col].b = 50; // blue
				//row_pointers[row][col].a = 255; // alpha (opacity)
			//} else {
				//row_pointers[row][col].r = 225; // red
				//row_pointers[row][col].g = 225; // green
				//row_pointers[row][col].b = 225; // blue
				//row_pointers[row][col].a = 0; // alpha (opacity)
			//}
		//}
	//}
	/* Draw horizontal lines*/
    //for (int row = 0; row < HEIGHT; row++) {
        //int bar_width = WIDTH;
        //for (int col = 0; col < WIDTH; col++) {
            //if (row%50==0) {
                //row_pointers[row][col].r = 0; //red
                //row_pointers[row][col].g = 0; //green
                //row_pointers[row][col].b = 0; //blue
                //row_pointers[row][col].a = 225; //alpha (opacity)
            //} else {
                //row_pointers[row][col].r = 0; //red
                //row_pointers[row][col].g = 0; //green
                //row_pointers[row][col].b = 0; //blue
                //row_pointers[row][col].a = 0; //alpha (opacity)
            //}
        //}
    //}

	/* write image data to disk */
	png_write_image(png_ptr, (png_byte **)pixel_pointers);

	/* finish writing PNG file */
	png_write_end(png_ptr, NULL);

	/* clean up PNG-related data structures */
	png_destroy_write_struct(&png_ptr, &info_ptr);

	/* close the file */
	fclose(pngImage);
	pngImage = NULL;

	/* Clear memory*/
	for (int row = 0; row < WIDTH; row++) {
        //for (int col = 0; col < HEIGHT; col++) {
            free(pixel_pointers[row]);
        //}
	}

	return 0;
}
