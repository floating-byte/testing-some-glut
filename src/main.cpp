#include <include.h>

#include <star.h>

#define WIDTH 500
#define HEIGHT 500

int rand_seed = time(0);

void keydown(unsigned char key , int x , int y);
void keyup(unsigned char key , int x , int y);

int counter = 0;
int rotate;

std::vector<star> stars;
star point;
void update(int v)
{
	glutTimerFunc(1000/60,update,0);
	if(counter == 0){std::cout << "obj is created"<<std::endl;;counter = 0; star point;stars.push_back(point);}
	else{counter++;}

	float move_speed = 1;

	if(rotate == 360){rotate = 0;}
	else{rotate+=2;}

	for(int i = 0; i < stars.size();i++)
	{
		stars[i].rotate(rotate);
		stars[i].move(0,move_speed);
	}
	glutPostRedisplay();
}
void display();
void Start();

int main(int argc, char** argv) 
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE);

   glutInitWindowSize(WIDTH,HEIGHT);
   glutCreateWindow("testing ...");

   glutDisplayFunc(display);
   Start();
 

   glutKeyboardFunc(keydown);
   glutKeyboardUpFunc(keyup);
   glutTimerFunc(0,update,0);
   glutMainLoop();           
   return 0;
}
/*#################################- key press -#########################################*/
float ssx= 1;
void keydown(unsigned char that_key , int x , int y)
{	
	glutPostRedisplay();
}
void keyup(unsigned char key , int x , int y)
{

}
/*#################################- key press -#########################################*/
void glut_setup()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-WIDTH/2 , WIDTH/2,-HEIGHT/2,HEIGHT/2,1.0f, -1.0f);
	glMatrixMode(GL_MODELVIEW);
}
void Start()
{
	glut_setup();
	srand(rand_seed);
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	for (int i = 0; i < stars.size(); i++)
	{
		stars[i].draw();
	}
	glutSwapBuffers();
}
