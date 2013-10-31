#ifndef FRGR_COLOUR_H
#define FRGR_COLOUR_H

class Colour
{
public:
	Colour(unsigned short RED=0x0, unsigned short GREEN=0x0, unsigned short BLUE=0x0);
	Colour(const Colour &orig);
	virtual ~Colour();

	virtual void set_rgb(unsigned short r, unsigned short g, unsigned short b);

	virtual void set_red(unsigned short val);
	virtual void set_green(unsigned short val);
	virtual void set_blue(unsigned short val);
	virtual void read_from_stdin(const char* desc=NULL);
	
	inline virtual unsigned short get_red()
	{
		return RED;
	}

	inline virtual unsigned short get_green()
	{
		return GREEN;
	}

	inline virtual unsigned short get_blue()
	{
		return BLUE;
	}

	virtual unsigned short get_colour();
	virtual void make_colour();

protected:
	unsigned short RED;
	unsigned short GREEN;
	unsigned short BLUE;

private:
	unsigned short hex_colour;
};

#endif