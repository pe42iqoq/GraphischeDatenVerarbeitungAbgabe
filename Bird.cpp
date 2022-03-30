/*
	wuerfel.cpp definiert einen W�rfel �ber seine 6 Seiten
	Last Update:  13.10.2011   W.-D. Groch
*/
#include <GL/freeglut.h>
#include <GL/soil.h>
#include "Bird.h"


void Wuerfel(GLfloat fSeitenL)
{
	glBegin(GL_POLYGON);   //Vorderseite
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f);	//ROT
	glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glColor4f(1.0f, 1.0f, 0.0f, 1.0f); //GELB
	glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f); //WEISS
	glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glColor4f(1.0f, 0.0f, 1.0f, 1.0f); //MAGENTA
	glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glEnd();


	glBegin(GL_POLYGON);   //Rechte Seite
	glColor4f(1.0f, 1.0f, 0.0f, 1.0f); //GELB
	glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glColor4f(0.0f, 1.0f, 0.0f, 1.0f); //GRUEN
	glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glColor4f(0.0f, 1.0f, 1.0f, 1.0f);	//CYAN
	glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f); //WEISS
	glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glEnd();


	glBegin(GL_POLYGON);   //Rueckseite
	glColor4f(0.0f, 1.0f, 1.0f, 1.0f); //CYAN
	glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glColor4f(0.0f, 1.0f, 0.0f, 1.0f); //GRUEN
	glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f); //SCHWARZ
	glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f); //BLAU
	glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glEnd();


	glBegin(GL_POLYGON);   //Linke Seite
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f); //BLAU
	glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f); //SCHWARZ
	glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f); //ROT	
	glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glColor4f(1.0f, 0.0f, 1.0f, 1.0f); //MAGENTA
	glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glEnd();

	glBegin(GL_POLYGON);   //Deckflaeche
	glColor4f(1.0f, 0.0f, 1.0f, 1.0f); //MAGENTA
	glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f); //WEISS
	glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glColor4f(0.0f, 1.0f, 1.0f, 1.0f); //CYAN
	glVertex3f(+fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f); //BLAU
	glVertex3f(-fSeitenL / 2.0f, +fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glEnd();

	glBegin(GL_POLYGON);   //Bodenflaeche
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f); //SCHWARZ
	glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glColor4f(0.0f, 1.0f, 0.0f, 1.0f); //GRUEN
	glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, -fSeitenL / 2.0f);
	glColor4f(1.0f, 1.0f, 0.0f, 1.0f); //GELB
	glVertex3f(+fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f); //ROT
	glVertex3f(-fSeitenL / 2.0f, -fSeitenL / 2.0f, +fSeitenL / 2.0f);
	glEnd();

	return;
}

void Quader(GLfloat fSeitenLX, GLfloat fSeitenLY, GLfloat fSeitenLZ, GLuint texture)
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);


	glBegin(GL_POLYGON);   //Vorderseite
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-fSeitenLX / 2.0f, -fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(+fSeitenLX / 2.0f, -fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(+fSeitenLX / 2.0f, +fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-fSeitenLX / 2.0f, +fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
	glEnd();


	glBegin(GL_POLYGON);   //Rechte Seite
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(+fSeitenLX / 2.0f, -fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(+fSeitenLX / 2.0f, -fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(+fSeitenLX / 2.0f, +fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(+fSeitenLX / 2.0f, +fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
	glEnd();


	glBegin(GL_POLYGON);   //Rueckseite
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(+fSeitenLX / 2.0f, +fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(+fSeitenLX / 2.0f, -fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-fSeitenLX / 2.0f, -fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-fSeitenLX / 2.0f, +fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
	glEnd();


	glBegin(GL_POLYGON);   //Linke Seite
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-fSeitenLX / 2.0f, +fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-fSeitenLX / 2.0f, -fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-fSeitenLX / 2.0f, -fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-fSeitenLX / 2.0f, +fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
	glEnd();

	glBegin(GL_POLYGON);   //Deckflaeche
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-fSeitenLX / 2.0f, +fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(+fSeitenLX / 2.0f, +fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(+fSeitenLX / 2.0f, +fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-fSeitenLX / 2.0f, +fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
	glEnd();

	glBegin(GL_POLYGON);   //Bodenflaeche
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-fSeitenLX / 2.0f, -fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(+fSeitenLX / 2.0f, -fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(+fSeitenLX / 2.0f, -fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-fSeitenLX / 2.0f, -fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
	glEnd();

	glDisable(GL_TEXTURE_2D);

	return;
}

void beak() {

	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(1, 0.5, 0); glVertex3f(0, 0.1, -0.1);
	glColor3f(1, 0.25, 0); glVertex3f(0.05, 0, -0.1);
	glColor3f(1, 0.5, 0); glVertex3f(-0.05, 0, -0.1);
	glColor3f(1, 1, 0); glVertex3f(0, 0, 0.2);
	glColor3f(1, 0.25, 0); glVertex3f(0, 0.1, -0.1);
	glColor3f(1, 1, 0); glVertex3f(0.05, 0, -0.1);
	glEnd();

	return;
}

void tail() {

	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(1, 1, 1); glVertex3f(0, 0.1, 0.1);
	glColor3f(0.5, 0.5, 0.5); glVertex3f(0.05, 0, 0.1);
	glColor3f(0.5, 0.5, 0.5); glVertex3f(-0.05, 0, 0.1);
	glColor3f(0.1, 0.1, 0.1); glVertex3f(0, 0, -0.2);
	glColor3f(1, 1, 1); glVertex3f(0, 0.1, 0.1);
	glColor3f(0.7, 0.7, 0.7); glVertex3f(0.05, 0, 0.1);
	glEnd();

	return;
}

void Pinkers(GLfloat fSeitenLX, GLfloat fSeitenLY, GLfloat fSeitenLZ)
{
	glBegin(GL_POLYGON);   //Vorderseite
	glColor4f(0.6f, 0.5f, 0.5f, 1.0f);	//ROT
	glVertex3f(-fSeitenLX / 2.0f, -fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
	glColor4f(0.8f, 0.7f, 0.7f, 1.0f); //GELB
	glVertex3f(+fSeitenLX / 2.0f, -fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
	glColor4f(1.0f, 0.9f, 0.9f, 1.0f); //WEISS
	glVertex3f(+fSeitenLX / 2.0f, +fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
	glColor4f(0.4f, 0.3f, 0.3f, 1.0f); //MAGENTA
	glVertex3f(-fSeitenLX / 2.0f, +fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
	glEnd();


	glBegin(GL_POLYGON);   //Rechte Seite
	glColor4f(0.8f, 0.7f, 0.7f, 1.0f); //GELB
	glVertex3f(+fSeitenLX / 2.0f, -fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
	glColor4f(0.9f, 0.8f, 0.8f, 1.0f); //GRUEN
	glVertex3f(+fSeitenLX / 2.0f, -fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
	glColor4f(1.0f, 0.9f, 0.9f, 1.0f);	//CYAN
	glVertex3f(+fSeitenLX / 2.0f, +fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
	glColor4f(1.0f, 0.9f, 0.9f, 1.0f); //WEISS
	glVertex3f(+fSeitenLX / 2.0f, +fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
	glEnd();


	glBegin(GL_POLYGON);   //Rueckseite
	glColor4f(1.0f, 0.9f, 0.9f, 1.0f);	//CYAN
	glVertex3f(+fSeitenLX / 2.0f, +fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
	glColor4f(0.9f, 0.8f, 0.8f, 1.0f); //GRUEN
	glVertex3f(+fSeitenLX / 2.0f, -fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
	glColor4f(0.3f, 0.1f, 0.1f, 1.0f); //SCHWARZ
	glVertex3f(-fSeitenLX / 2.0f, -fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
	glColor4f(0.5f, 0.0f, 0.0f, 1.0f); //BLAU
	glVertex3f(-fSeitenLX / 2.0f, +fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
	glEnd();


	glBegin(GL_POLYGON);   //Linke Seite
	glColor4f(0.5f, 0.0f, 0.0f, 1.0f); //BLAU
	glVertex3f(-fSeitenLX / 2.0f, +fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
	glColor4f(0.3f, 0.1f, 0.1f, 1.0f); //SCHWARZ
	glVertex3f(-fSeitenLX / 2.0f, -fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
	glColor4f(0.7f, 0.5f, 0.5f, 1.0f);	//ROT
	glVertex3f(-fSeitenLX / 2.0f, -fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
	glColor4f(0.5f, 0.3f, 0.3f, 1.0f); //MAGENTA
	glVertex3f(-fSeitenLX / 2.0f, +fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
	glEnd();

	glBegin(GL_POLYGON);   //Deckflaeche
	glColor4f(0.5f, 0.3f, 0.3f, 1.0f); //MAGENTA
	glVertex3f(-fSeitenLX / 2.0f, +fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
	glColor4f(1.0f, 0.9f, 0.9f, 1.0f); //WEISS
	glVertex3f(+fSeitenLX / 2.0f, +fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
	glColor4f(1.0f, 0.9f, 0.9f, 1.0f);	//CYAN
	glVertex3f(+fSeitenLX / 2.0f, +fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
	glColor4f(0.5f, 0.0f, 0.0f, 1.0f); //BLAU
	glVertex3f(-fSeitenLX / 2.0f, +fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
	glEnd();

	glBegin(GL_POLYGON);   //Bodenflaeche
	glColor4f(0.3f, 0.1f, 0.1f, 1.0f); //SCHWARZ
	glVertex3f(-fSeitenLX / 2.0f, -fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
	glColor4f(0.9f, 0.8f, 0.8f, 1.0f); //GRUEN
	glVertex3f(+fSeitenLX / 2.0f, -fSeitenLY / 2.0f, -fSeitenLZ / 2.0f);
	glColor4f(0.8f, 0.7f, 0.7f, 1.0f); //GELB
	glVertex3f(+fSeitenLX / 2.0f, -fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
	glColor4f(0.7f, 0.5f, 0.5f, 1.0f);	//ROT
	glVertex3f(-fSeitenLX / 2.0f, -fSeitenLY / 2.0f, +fSeitenLZ / 2.0f);
	glEnd();

	return;
}

void roof() {

	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(1, 1, 1); glVertex3f(0, 0.5, 0);
	glColor3f(0.5, 0.5, 0.5); glVertex3f(-0.5, 0, 0.5);
	glColor3f(0.5, 0.5, 0.5); glVertex3f(0.5, 0, 0.5);
	glColor3f(0.1, 0.1, 0.1); glVertex3f(0.5, 0, -0.5);
	glColor3f(1, 1, 1); glVertex3f(0, 0.5, 0);
	glColor3f(0.7, 0.7, 0.7); glVertex3f(-0.5, 0, 0.5);

	glColor3f(1, 1, 1); glVertex3f(0, 0.5, 0);
	glColor3f(0.5, 0.5, 0.5); glVertex3f(0.5, 0, -0.5);
	glColor3f(0.5, 0.5, 0.5); glVertex3f(-0.5, 0, -0.5);
	glColor3f(0.1, 0.1, 0.1); glVertex3f(-0.5, 0, 0.5);
	glColor3f(1, 1, 1); glVertex3f(0, 0.5, 0);
	glColor3f(0.7, 0.7, 0.7); glVertex3f(0.5, 0, -0.5);
	glEnd();

	return;
}

void foot() {

	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(1, 1, 1); glVertex3f(0, 0.1, 0.1);
	glColor3f(0.7, 0.5, 0.5); glVertex3f(0.05, 0, 0.1);
	glColor3f(0.7, 0.5, 0.5); glVertex3f(-0.05, 0, 0.1);
	glColor3f(0.5, 0.1, 0.1); glVertex3f(0, 0, -0.1);
	glColor3f(1, 1, 1); glVertex3f(0, 0.1, 0.1);
	glColor3f(0.9, 0.7, 0.7); glVertex3f(0.05, 0, 0.1);
	glEnd();

	return;
}

void Plane(GLfloat fSeitenLX, GLfloat fSeitenLZ, GLuint texture)
{

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);

	glBegin(GL_POLYGON);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);   glVertex3f(-fSeitenLX, 0.0f, -fSeitenLZ);
	glTexCoord2f(1.0f, 0.0f);   glVertex3f(fSeitenLX, 0.0f, -fSeitenLZ);
	glTexCoord2f(1.0f, 1.0f);   glVertex3f(fSeitenLX, 0.0f, fSeitenLZ);
	glTexCoord2f(0.0f, 1.0f);   glVertex3f(-fSeitenLX, 0.0f, fSeitenLZ);
	glEnd();


	glDisable(GL_TEXTURE_2D);


	return;
}

void cylinder(GLdouble base, GLdouble top, GLdouble height, GLint slices, GLint stacks)
{
	GLUquadricObj* quadratic;
	quadratic = gluNewQuadric();

	// glColor3f(1.0, 0.0, 0.0);
	gluCylinder(quadratic, base, top, height, slices, stacks);

	return;
}

void sphere(GLdouble radius, GLint slices, GLint stacks) {
	GLUquadricObj* quad;
	quad = gluNewQuadric();
	gluSphere(quad, radius, slices, stacks);
	return;
};