#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <opencv/highgui.h>
#include <opencv/cv.h>

// OpenGL header files
#include <GL/glut.h>

#define WIDTH 400
#define HEIGHT 400

/** 
 * This is the GLUT display function that is called 
 * each time the scene is drawn to the screen.
 */
void display()
{
	glEnable(GL_TEXTURE_2D);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_FLAT);

	//load texture
	cv::Mat img = cv::imread("../texture.png");
	int width = img.cols;
	int height = img.rows;
	unsigned char* data = img.data;

	GLuint texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
//	gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, width, height, GL_RGB, GL_UNSIGNED_BYTE, data );

	glBegin(GL_TRIANGLES);


	glColor3f (1,1,1);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexCoord2d(1,1); glVertex3f(-0.5,-0.5,0);
	glTexCoord2d(0,0); glVertex3f(0.5,0.5,0);
	glTexCoord2d(1,0); glVertex3f(-0.5,0.5,0);

	glTexCoord2d(1,1); glVertex3f(-0.5,-0.5,0);
	glTexCoord2d(0,0); glVertex3f(0.5,0.5,0);
	glTexCoord2d(0,1); glVertex3f(0.5,-0.5,0);

	glEnd();

	glFlush();
}

using namespace std;


int main (int argc, char** argv)
{

	if (argc != 1)
	{
		cout<<"Usage: "<<argv[0]<<endl;
		return EXIT_FAILURE;	
	}
	else
	{
		  // Initialize OpenGL window
		  glutInit(&argc, argv);
		  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
		  glutInitWindowSize(WIDTH, HEIGHT);
		  glutCreateWindow("Texture Test");
		 
		  // Define GLUT callback functions
		  glutDisplayFunc(display);
		  
		  // This starts everything related to GLUT...
		  glutMainLoop();	

		return EXIT_SUCCESS;
	}

}
