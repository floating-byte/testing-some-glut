#include <star.h>

float rand_FloatRange(float a, float b)
{
    return ((b - a) * ((float)rand() / RAND_MAX)) + a;
}
star::star()
{
	m_size = 32;
	m_scale = 1;
	m_rotate = 0;

	m_posx = -rand_FloatRange(-125,125);
	m_posy = -125;

	std::cout << m_posx<< " " <<m_posy << std::endl;
}

void star::draw()
{
	glPushMatrix();

		glColor3f(1,1,0);

		float org_pos_x = (m_posx * m_scale)-(m_size/2);
		float org_pos_y = (m_posy * m_scale)-(m_size/2);
		
		//glScalef(m_scale,m_scale,1);

		glTranslatef(-org_pos_x  ,-org_pos_y ,0);
		glRotatef(m_rotate,0,0,1);

		//glTranslatef(m_posx   , m_posy ,0);

		glTranslatef(org_pos_x  ,org_pos_y ,0);

		glBegin(GL_QUADS);
			glVertex2f(m_posx,m_posy);
			glVertex2f(m_posx+m_size,m_posy);
			glVertex2f(m_posx+m_size,m_posy+m_size);
			glVertex2f(m_posx,m_posy+m_size);
		glEnd();

	glPopMatrix();
}
void star::scale(float multi)
{	
	m_scale = multi;
}
void star::move(int x,int y)
{
	m_posx += x;
	m_posy += y;
}
void star::rotate(int angle)
{
	m_rotate = angle;
}