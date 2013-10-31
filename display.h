#ifndef FRGR_DISPLAY_H
#define FRGR_DISPLAY_H
#include <string>

#include "PxPoint.h"
#include "colour.h"
using namespace std;

#define POW(x) (x)*(x)

class Display {

public:
	bool connect(const char *display_name);
	void get_size(int &width, int &height);
	void draw_raster(int x, int y, const unsigned short *pixels, int width);

	inline void set_up(int Width, int Height) {
		this->WIDTH = Width;
		this->HEIGHT = Height;
		this->frame_buffer = new unsigned short[WIDTH * HEIGHT];
		memset(frame_buffer, 0, sizeof(unsigned short)*WIDTH*HEIGHT);
		DIAGONAL = sqrt((double)POW(WIDTH) + (double)POW(HEIGHT));
	}

	void set_pixel(PxPoint &point);
	virtual ~Display();
	inline virtual double get_diagonal()
	{
		return DIAGONAL;
	}
	virtual void save_bitmap(const char *filename);
	Display(const char* display_name=NULL);

protected:
	int WIDTH;
	int HEIGHT;
	double DIAGONAL;

private:
	Display(const Display &orig);
	unsigned short *frame_buffer;
	string display_name;
};

#endif // FRGR_DISPLAY_H