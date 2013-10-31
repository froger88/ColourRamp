#include "StdAfx.h"
#include "PxPoint.h"
#include <math.h>

#define POW(x) (x)*(x)

PxPoint::PxPoint(int X, int Y)
{
	this->X = X;
	this->Y = Y;
}

PxPoint::PxPoint(const PxPoint &orig)
{
	this->X = orig.X;
	this->Y = orig.Y;
}

PxPoint::~PxPoint(void)
{
	// nothing to do
}


void PxPoint::calc_colour(PxPoint &LT, PxPoint &LB,
	PxPoint &RT, PxPoint &RB)
{
	this->dist_a = calc_dist(LT);
	this->dist_b = calc_dist(LB);
	this->dist_c = calc_dist(RT);
	this->dist_d = calc_dist(RB);
	
	double sum_dist = dist_a + dist_b + dist_c + dist_d;

	// invert
	double tmp_dist = dist_a;
	dist_a =  dist_d;
	dist_d = tmp_dist;

	tmp_dist = dist_c;
	dist_c =  dist_b;
	dist_b = tmp_dist;

	// calculate RED
	this->col.set_red((LT.col.get_red() * dist_a +
		LB.col.get_red() * dist_b +
		RT.col.get_red() * dist_c +
		RB.col.get_red() * dist_d)/sum_dist);

	// calculate GREEN
	this->col.set_green((LT.col.get_green() * dist_a +
		LB.col.get_green() * dist_b +
		RT.col.get_green() * dist_c +
		RB.col.get_green() * dist_d)/sum_dist);

	// calculate BLUE
	this->col.set_blue((LT.col.get_blue() * dist_a +
		LB.col.get_blue() * dist_b +
		RT.col.get_blue() * dist_c +
		RB.col.get_blue() * dist_d)/sum_dist);

	this->col.make_colour();
}

double PxPoint::calc_dist(const PxPoint &x)
{
	return (double)sqrt(  (double)POW((this->X - x.X)) + (double)POW(this->Y - x.Y)  );
}

bool PxPoint::operator==(const PxPoint &rvalue)
{
	if(X == rvalue.X && Y == rvalue.Y)
		return true;
	return false;
}