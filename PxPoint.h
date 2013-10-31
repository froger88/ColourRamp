#ifndef FRGR_PXPOINT_H
#define FRGR_PXPOINT_H

#include "colour.h"

class PxPoint
{
public:
	PxPoint(int X=0, int Y=0);
	PxPoint(const PxPoint &orig);
	virtual ~PxPoint(void);

	int X;
	int Y;
	Colour col;

	virtual void calc_colour(PxPoint &LT, PxPoint &LB,
		PxPoint &RT, PxPoint &RB);

	virtual bool operator==(const PxPoint &rvalue);
protected:
	virtual double calc_dist(const PxPoint &x);

private:

	double dist_a;
	double dist_b;
	double dist_c;
	double dist_d;
};

#endif
