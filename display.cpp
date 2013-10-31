#include "StdAfx.h"
#include <string.h>
#include <cstdio>
#include <cassert>
#include <memory.h>
#include <iostream>
#include <fstream>
using namespace std;

#include "display.h"

Display::Display(const char *display_name)
{
	if(display_name) {
		this->display_name.assign(display_name, strlen(display_name));
	}
}

Display::~Display()
{
	unsigned short *pix = frame_buffer;
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			if (x > 0) {
				printf(" ");
			}
			//printf("%d", *pix++);
			printf("%04X", *pix++);
		}
		printf("\n");
	}

	delete [] frame_buffer;
}

bool Display::connect(const char *display_name)
{
	if(this->display_name.size() && (string)display_name == this->display_name)
		return true;
	return false;
}

void Display::get_size(int &width, int &height)
{
	width = WIDTH;
	height = HEIGHT;
}

void Display::draw_raster(int x, int y, const unsigned short *pixels, int width)
{
	memcpy(&frame_buffer[y*WIDTH+x], pixels, width*sizeof(unsigned short));
}

void Display::set_pixel(PxPoint &point)
{
	// cout << "(" << point.X << ", " << point.Y << ") = " << point.col.get_colour() << " @ frame_buffer[" << WIDTH * point.Y + point.X << "]" << endl;
	frame_buffer[WIDTH * point.Y + point.X] = point.col.get_colour();
}

void Display::save_bitmap(const char *filename)
{
	fstream f;
	f.open(filename, ios::binary|ios::out);
	f.write((const char*)frame_buffer, sizeof(unsigned short) * WIDTH*HEIGHT);
	f.close();
}