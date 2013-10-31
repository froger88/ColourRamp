#include "StdAfx.h"
#include "colour.h"
#include <iostream>

using namespace std;

Colour::Colour(unsigned short RED, unsigned short GREEN, unsigned short BLUE)
{
	this->RED = RED;
	this->GREEN = GREEN;
	this->BLUE = BLUE;

	make_colour();
}

Colour::Colour(const Colour &orig)
{
	this->RED = orig.RED;
	this->GREEN = orig.GREEN;
	this->BLUE = orig.BLUE;
}

Colour::~Colour()
{
	// nothing to do
}

void Colour::make_colour()
{
	hex_colour = 0;
	hex_colour = RED;
	hex_colour <<= 6;
	hex_colour += GREEN;
	hex_colour <<= 5;
	hex_colour += BLUE;
}

unsigned short Colour::get_colour()
{
	return this->hex_colour;
}

void Colour::set_red(unsigned short val)
{
	if(val > 31)
		throw "Not in range <0;31>";
	RED = val;
}

void Colour::set_green(unsigned short val)
{
	if(val > 63)
		throw "Not in range <0;63>";
	GREEN = val;
}

void Colour::set_blue(unsigned short val)
{
	if(val > 31)
		throw "Not in tange <0;31>";
	BLUE = val;
}

void Colour::set_rgb(unsigned short r, unsigned short g, unsigned short b)
{
	set_red(r);
	set_green(g);
	set_blue(b);
	make_colour();
}

void Colour::read_from_stdin(const char* desc)
{
	short a,b,c;
	try { 
		if (desc) {
			cout << "["<<desc <<"] ";
		}
		cout << "Podaj kolory oddzielone spacja: ";
		cin >> a >> b >> c;
	} catch(...) { 
		throw;
	}
	// in future we may want to have different exception handling
	try {
		set_rgb(a,b,c);
	} catch(...) {
		throw;
	}
}