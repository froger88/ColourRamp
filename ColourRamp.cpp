// ColourRamp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "display.h"
#include <iostream>

#include "PxPoint.h"
#include "colour.h"

#define W 16
#define H  9

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{

	{
		// left-top
		PxPoint LT(0,0);
		//LT.col.set_rgb(0, 0, 3);
		LT.col.read_from_stdin("Left Top");

		//left-bottom
		PxPoint LB(0, H-1);
		//LB.col.set_rgb(0, 0, 3);
		LB.col.read_from_stdin("Left Bottom");

		// right-top
		PxPoint RT(W-1, 0);
		RT.col.read_from_stdin("Right Top");
		//RT.col.set_rgb(0, 0, 0);
		
		// right-bottom
		PxPoint RB(W-1, H-1);
		RB.col.read_from_stdin("Right Bottom");
		//RB.col.set_rgb(0, 0, 0);
		
		// setup display
		Display x("display.test");
		x.set_up(W, H);
		x.set_pixel(LT);
		x.set_pixel(LB);
		x.set_pixel(RB);
		x.set_pixel(RT);

		// fill display
		for(int Py=0;Py < H; ++Py) {
			for(int Px=0; Px<W; ++Px) {
				PxPoint tmp(Px,Py);
				if(tmp == LT || tmp == LB || tmp == RT || tmp == RB)
					continue;

				tmp.calc_colour(LT, LB, RT, RB);
				x.set_pixel(tmp);
			}
		}
		x.save_bitmap("file_out.rgb565");
	}
	system("pause");
	return EXIT_SUCCESS;
}
