#ifndef STAR_H
#include <include.h>
#define STAR_H

class star
{
private:
	float m_posx , m_posy;
	float m_size;
	float m_speed , m_scale , m_rotate;
	
public:
	star();

	void draw();
	void scale(float multi);
	void move(int new_x,int new_y);
	void rotate(int angle);
};

#endif