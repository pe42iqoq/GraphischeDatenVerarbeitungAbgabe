// GDV-Abgabe WiSe2021/2022 Gabriel, Nguyen

#include <iostream> 
#include <GL/freeglut.h>         //l�dt alles für OpenGL
#include <cmath>
#include <GL/soil.h>
#include <algorithm>

#include "Bird.h"

GLfloat extent = 1.0;  // Mass fuer die Ausdehnung des Modells
GLfloat winkel = 0.0;   // Rotationswinkel
GLuint backsteine;         // Textur-ID
GLuint honeycomb;
GLuint tree;
GLuint hexagon;
GLuint feder;
GLuint ocean;
GLuint gefieder;
GLuint textureSwitchFloor;
GLuint metallic;
GLboolean loop = false;
GLuint lightCase = 1;
GLuint steinmaserung;
GLuint gestein1;
GLuint holz;

static float birdSpeed = 0.5;
static float robotSpeed = 0.0;
static bool drop = false;

void mainMenu(int item)
{
	switch (item)
	{
	case 1:
		std::cout << "Exit" << std::endl;
		exit(0);
	}
}

void backGroundColor(int item)
{
	switch (item)
	{
	case 1:
	{
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);	// Hintergrundfarbe weiss definieren 
		// RenderScene aufrufen.
		glutPostRedisplay();
		break;
	}
	case 2:
	{
		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);	// Hintergrundfarbe rot definieren 
		// RenderScene aufrufen.
		glutPostRedisplay();
		break;
	}
	case 3:
	{
		glClearColor(0.33f, 0.225f, 0.0f, 1.0f);// Hintergrundfarbe gold definieren 
		// RenderScene aufrufen.
		glutPostRedisplay();
		break;
	}
	case 4:
	{
		glClearColor(0, 0, 0, 1); // Schwarz
		glutPostRedisplay();
		break;
	}
	}
}

void floorTexture(int item)
{
	switch (item)
	{
	case 1:
	{
		textureSwitchFloor = ocean;
		glutPostRedisplay();
		break;
	}
	case 2:
	{
		textureSwitchFloor = backsteine;
		// RenderScene aufrufen.
		glutPostRedisplay();
		break;
	}
	case 3:
	{
		textureSwitchFloor = tree;
		// RenderScene aufrufen.
		glutPostRedisplay();
		break;
	}
	}
}

void looping(int item)
{
	switch (item)
	{
	case 1:
	{
		loop = true;
		glutPostRedisplay();
		break;
	}
	case 2:
	{
		loop = false;
		glutPostRedisplay();
		break;
	}
	}
}

void lights(int item)
{
	switch (item)
	{
	case 1:
	{
		lightCase = 1;
		glutPostRedisplay();
		break;
	}
	case 2:
	{
		lightCase = 2;
		glutPostRedisplay();
		break;
	}
	case 3:
	{
		lightCase = 3;
		glutPostRedisplay();
		break;
	}
	}
}

void move(int item) {
	switch (item)
	{
	case 1:
	{
		birdSpeed = 0.5;
		glutPostRedisplay();
		break;
	}
	case 2:
	{
		birdSpeed = 4;
		glutPostRedisplay();
		break;
	}
	case 3:
	{
		robotSpeed = 0.001f;
		glutPostRedisplay();
		break;
	}
	case 4:
	{
		drop = true; //Zustellung
		robotSpeed = -1 * robotSpeed;
		glutPostRedisplay();
		break;
	}
	}
}

void Init()
{
	// Hier finden jene Aktionen statt, die zum Programmstart einmalig 
	// durchgeführt werden müssen	
	glClearColor(0, 0, 0, 1);

	glEnable(GL_LIGHT0);

	GLfloat light_position[] = { 0.0, 1.0, 1.0, 0.0 };	// Position der Lichtquelle
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);	// Licht Nr. 0 rechts oben


	// Unter-Menu
	int submenu1;
	submenu1 = glutCreateMenu(backGroundColor);
	glutAddMenuEntry("BackgroundColor WHITE", 1);
	glutAddMenuEntry("BackgroundColor RED", 2);
	glutAddMenuEntry("BackgroundColor GOLD", 3);
	glutAddMenuEntry("BackgroundColor BLACK", 4);
	// Unter-Menu
	int submenu2;
	submenu2 = glutCreateMenu(floorTexture);
	glutAddMenuEntry("Ocean", 1);
	glutAddMenuEntry("Backsteine", 2);
	glutAddMenuEntry("Tree", 3);

	// Unter-Menu
	int submenu3;
	submenu3 = glutCreateMenu(looping);
	glutAddMenuEntry("Spin around", 1);
	glutAddMenuEntry("Stop", 2);

	// Unter-Menu
	int submenu4;
	submenu4 = glutCreateMenu(lights);
	glutAddMenuEntry("Light Rotation", 1);
	glutAddMenuEntry("Light Horizontal", 2);
	glutAddMenuEntry("Light Stationary", 3);

	// Unter-Menu
	int submenu5;
	submenu5 = glutCreateMenu(move);
	glutAddMenuEntry("Normal Speed", 1);
	glutAddMenuEntry("2Fast2Furious", 2);
	glutAddMenuEntry("Deliver Package", 3);
	glutAddMenuEntry("Drop and Leave", 4);

	// Haupt-Menu
	glutCreateMenu(mainMenu);
	glutAddSubMenu("Background color", submenu1);
	glutAddSubMenu("Floor Texture", submenu2);
	glutAddSubMenu("Bird Loopings", submenu3);
	glutAddSubMenu("Light", submenu4);
	glutAddSubMenu("Events", submenu5);
	glutAddMenuEntry("Exit", 1);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	// Texturen einlesen
	backsteine = SOIL_load_OGL_texture("./backsteine.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	tree = SOIL_load_OGL_texture("./TREE1.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	feder = SOIL_load_OGL_texture("./feder.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	ocean = SOIL_load_OGL_texture("./ocean3.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	gefieder = SOIL_load_OGL_texture("./gefieder.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	steinmaserung = SOIL_load_OGL_texture("./steinmaserung.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	metallic = SOIL_load_OGL_texture("./metallic.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	gestein1 = SOIL_load_OGL_texture("./gestein2.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	holz = SOIL_load_OGL_texture("./holz.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	textureSwitchFloor = ocean;

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_SPOT_DIRECTION);
	glEnable(GL_SPOT_CUTOFF);
	glEnable(GL_AMBIENT);
	glEnable(GL_SPECULAR);
	glEnable(GL_POSITION);
	glEnable(GL_COLOR_MATERIAL);

	// z-Buffer
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
}

void birdAnimation() {
	float scale = 0.15;
	static float leftLeg = 0;
	static float rightLeg = 0;
	static float leftWing = 90;
	static float rightWing = -90;
	static float head = 0;
	static float body = 0;
	static float tailRotate = 0;
	static float movement = 0;
	static float loopA = 0;

	glPushMatrix();
	if (loop) {
		glRotatef(loopA += 2, 0, 0, 1);
	}
	else {
		glRotatef(0, 0, 0, 1);
	}


	glPushMatrix();
	glScaled(scale, scale, scale);
	glTranslatef(0, 0, 0.5);
	glTranslatef(0, sin(body += 0.001), 0);  //Bird in Motion

	glPushMatrix();					// Oberkörper
	glRotatef(22, sin(body += 0.1), 1, 1);
	glRotatef(42, 0, 1, 0);
	glTranslatef(0, 0, 0);
	Quader(0.2, 0.1, 0.75, gefieder);

	glPushMatrix();					//Kopf
	glTranslatef(0, 0.15, 0.35);
	Quader(0.15, 0.15, 0.15, gefieder);
	glTranslatef(0, -0.05, 0.2);	//Schnabel
	beak();
	glPopMatrix();

	glPushMatrix();				//Schwanz
	glTranslatef(0, -0.05, -0.55);
	glRotatef(12 * sin(tailRotate -= 0.1), 1, 0, 0);
	tail();
	glPopMatrix();

	glPushMatrix();						// linker Flügel
	glTranslatef(0, 0, 0);
	glRotatef(42 * sin(leftWing -= 0.05), 0, 0, 1);
	glTranslatef(0.3, 0, 0);
	Quader(0.3, 0.02, 0.5, gefieder);
	glPushMatrix();
	glRotatef(42 * sin(leftWing -= 0.05), 0, 0, 1);
	glTranslatef(0.4, 0, 0);
	Quader(0.5, 0.02, 0.2, gefieder);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();						// rechter Flügel
	glTranslatef(0, 0, 0);
	glRotatef(42 * cos(rightWing -= 0.05), 0, 0, 1);
	glTranslatef(-0.3, 0, 0);
	Quader(0.3, 0.02, 0.5, gefieder);
	glPushMatrix();
	glRotatef(42 * cos(rightWing -= 0.05), 0, 0, 1);
	glTranslatef(-0.4, 0, 0);
	Quader(0.5, 0.02, 0.2, gefieder);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();						// Bein
	glRotatef(22 * sin(leftLeg += 0.1), 1, 0, 0);
	glTranslatef(0.1, -0.3, 0);
	Pinkers(0.05, 0.4, 0.05);
	glTranslatef(0, -0.27, 0);
	foot();
	glPopMatrix();

	glPushMatrix();						// Bein
	glRotatef(22 * sin(rightLeg -= 0.1), 1, 0, 0);
	glTranslatef(-0.1, -0.3, 0);
	Pinkers(0.05, 0.4, 0.05);
	glTranslatef(0, -0.27, 0);
	foot();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}

float roboPosition(float i) {
	float z;
	z = -(i * i * i * i);
	return z;
}

void delivery(float speed, bool drop) {
	static float movement = -1.25;
	float scale = 0.35;

	if (roboPosition(movement) > -0.001f && drop == false) {
		movement = 0;
	}
	if (roboPosition(movement) < -5) {
		movement = -5;
	}

	movement += speed;

	if (drop == true) { //zugestellt
		glPushMatrix();
		glTranslatef(0, -0.25, 0);
		glScaled(scale, scale, scale);
		Quader(0.3, 0.3, 0.3, holz);
		glPopMatrix();
	}
	else {
		glPushMatrix();
		glTranslatef(0, -0.25, roboPosition(movement));
		glScaled(scale, scale, scale);
		Quader(0.3, 0.3, 0.3, holz);
		glPopMatrix();
	}
}

void robot(float speed, bool drop) {
	float scale = 0.35;
	static float movement = -1.25;
	static float rotor = 0;

	if (roboPosition(movement) > -0.001f && drop == false) {
		movement = 0;
	}
	if (roboPosition(movement) < -5) {
		movement = -1.5;
	}
	movement += speed;
	glPushMatrix();

	glTranslatef(0, 0, roboPosition(movement)); //motion

	glScaled(scale, scale, scale);



	glPushMatrix();					// body
	Quader(0.35, 0.35, 0.35, metallic);

	glPushMatrix();						// Transmition
	glTranslatef(0, 0.35, 0);
	glRotatef(rotor += 9, 0, 1, 0);
	Quader(0.03, 0.9, 0.03, metallic);
	glPushMatrix();						// Rotor 1
	glTranslatef(0, 0.5, 0.3);
	glRotatef(22, 0, 0, 1);
	Quader(0.3, 0.02, 0.6, metallic);
	glPopMatrix();
	glPushMatrix();						// Rotor 2
	glTranslatef(0, 0.5, -0.3);
	glRotatef(-22, 0, 0, 1);
	Quader(0.3, 0.02, 0.6, metallic);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();						// linker Arm
	glTranslatef(0.18, 0, 0);
	glTranslatef(0, -0.3, 0);
	glRotatef(300, 0, 0, 1);
	Quader(0.3, 0.02, 0.3, metallic);
	glPushMatrix();
	if (drop == true) {				//zugestellt
		glRotatef(23, 0, 0, 1);
	}
	else {
		glRotatef(-22, 0, 0, 1);
	}
	glTranslatef(0.4, 0, 0);
	Quader(0.3, 0.02, 0.2, metallic);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();						// rechter Arm
	glTranslatef(-0.18, 0, 0);
	glTranslatef(0, -0.3, 0);
	glRotatef(60, 0, 0, 1);
	Quader(0.3, 0.02, 0.3, metallic);
	glPushMatrix();
	if (drop == true) {			//zugestellt
		glRotatef(-23, 0, 0, 1);
	}
	else {
		glRotatef(22, 0, 0, 1);
	}
	glTranslatef(-0.4, 0, 0);
	Quader(0.3, 0.02, 0.2, metallic);
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();
	glPopMatrix();
}

void floor() {
	float scale = 0.5;

	glPushMatrix();
	glScaled(scale, scale, scale);
	glPushMatrix();
	glTranslatef(0.0, -1.5f, 0.0);
	Plane(1.5, 1.5, textureSwitchFloor);
	glPopMatrix();
	glPopMatrix();
}

void pileOfRocks() {
	float scale = 0.35;

	glPushMatrix();
	glScaled(scale, scale, scale);
	glTranslatef(0, 0, 0);
	Quader(1, 0.5, 1, gestein1);
	glTranslatef(0, -0.15, 0.5);
	Quader(0.7, 0.2, 1, gestein1);
	glTranslatef(0.5, 0.1, 0);
	Quader(0.5, 0.35, 0.35, gestein1);
	glTranslatef(-1, 0, -0.6);
	Quader(0.5, 0.35, 0.35, gestein1);
	glTranslatef(0.8, 0, -0.5);
	Quader(0.5, 0.35, 0.35, gestein1);
	glTranslatef(0, -0.05, -0.3);
	Quader(0.3, 0.25, 0.4, gestein1);
	glTranslatef(0.3, -0.05, 0.5);
	Quader(0.3, 0.25, 0.4, gestein1);
	glTranslatef(0.2, -0.01, 0.5);
	Quader(0.7, 0.2, 1, gestein1);
	glTranslatef(-0.8, 0.15, -0.7);
	Quader(0.4, 0.4, 0.6, gestein1);
	glTranslatef(-0.4, 0.0, 1.1);
	Quader(0.4, 0.4, 0.6, gestein1);
	glTranslatef(0.3, -0.13, -1.3);
	Quader(0.7, 0.2, 1, gestein1);
	glTranslatef(-0.5, 0.07, 0.6);
	Quader(0.7, 0.3, 1, gestein1);
	glTranslatef(0.2, 0.05, -0.3);
	Quader(0.5, 0.4, 1, gestein1);
	glTranslatef(-0.2, -0.1, 0.7);
	Quader(1, 0.2, 1, gestein1);
	glPopMatrix();
}

void house() {
	float scale = 0.3;

	glPushMatrix();				//Boden
	glScaled(scale, scale, scale);
	glTranslatef(0, 0, 0);
	Quader(1, 0.1, 1, backsteine);
	glPushMatrix();							//Saeule1
	glTranslatef(0.45, 0.55, 0.45);
	Quader(0.1, 1, 0.1, backsteine);
	glPopMatrix();
	glPushMatrix();						//Saeule2
	glTranslatef(-0.45, 0.55, 0.45);
	Quader(0.1, 1, 0.1, backsteine);
	glPopMatrix();
	glPushMatrix();							//Saeule3
	glTranslatef(0.45, 0.55, -0.45);
	Quader(0.1, 1, 0.1, backsteine);
	glPopMatrix();
	glPushMatrix();							//Saeule4
	glTranslatef(-0.45, 0.55, -0.45);
	Quader(0.1, 1, 0.1, backsteine);
	glPopMatrix();
	glPushMatrix();							//Dach
	glTranslatef(0, 1.05, 0);
	roof();
	glPopMatrix();
	glPopMatrix();
}

void lighthouse() {

	glPushMatrix();
	glTranslatef(0, 0.6, 0);
	sphere(0.1, 32, 32);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0.5, 0);
	house();
	glPopMatrix();
	glPushMatrix();
	glRotatef(90, -1, 0, 0);
	glPushMatrix();
	glTranslatef(0, 0, -1);
	cylinder(0.2, 0.15, 1.5, 32, 32);
	glPopMatrix();
	glPopMatrix();
}

void RenderScene() //Zeichenfunktion
{
	static float rotation = 0;

	// Hier befindet sich der Code der in jedem Frame ausgefuehrt werden muss
	glLoadIdentity();   // Aktuelle Model-/View-Transformations-Matrix zuruecksetzen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glRotatef(-25, 1, 0, 0);
	glRotatef(72, 0, 1, 0);
	glRotatef(-12, 0, 0, 1);

	static float lightTurn = 0;
	if (lightTurn > 360) { lightTurn = 0; }

	switch (lightCase)
	{
	case 1:
	{
		glEnable(GL_LIGHT0);
		glPushMatrix();
		glTranslatef(0, 0.85, 0);
		glRotatef(rotation, 0, 1, 0);
		GLfloat light_position[] = { 0.0, 1, 1, 0.0 };	// Position der Lichtquelle
		glLightfv(GL_LIGHT0, GL_POSITION, light_position);	// Licht Nr. 0 rechts oben
		glPopMatrix();
		glutPostRedisplay();
		break;
	}
	case 2:
	{
		GLfloat light_specular[] = { 1.0, 0.0, 1.0, 0.0 };
		glLightfv(GL_LIGHT0, GL_POSITION, light_specular);
		glutPostRedisplay();
		break;
	}
	case 3:
	{
		GLfloat spot_direction[] = { 1.0, 1.0, -1.0, 0.0 };
		glLightfv(GL_LIGHT0, GL_POSITION, spot_direction);
		glutPostRedisplay();
		break;
	}
	}

	floor();
	glPushMatrix();
	glTranslatef(0, -0.4f, 0);
	robot(robotSpeed, drop);
	delivery(robotSpeed, drop);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-0.3, 0, 0.3); // 3. Translate to the object's position.
	glPushMatrix();
	glTranslatef(0, -0.7, 0);
	pileOfRocks();
	glPopMatrix();
	lighthouse();
	glRotatef(rotation += birdSpeed, 0.0, 1.0, 0.0); // 2. Rotate the object.
	glTranslatef(0.5, 0.0, 0.5); // 1. Translate to the origin.
	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	birdAnimation();
	glPopMatrix();
	glPopMatrix();

	if (rotation > 360) { rotation = 0; };

	glutSwapBuffers();
}

void Reshape(int width, int height)
{
	// Hier finden die Reaktionen auf eine Veränderung der Größe des 
	// Graphikfensters statt
	 // Matrix fuer Transformation: Frustum -> viewport
	glMatrixMode(GL_PROJECTION);
	// Aktuelle Transformations-Matrix zuruecksetzen
	glLoadIdentity();
	// Viewport definieren
	glViewport(0, 0, width, height);
	// Kameraposition, Blickwinkel und Up-Vector
	// gluLookAt(1, 1, 1, 0, 0, 0, 0, 1, 0); // extrinsische Kameraparameter
	// Kamera definieren (intrinsische Kameraparameter)
	// gluPerspective(30, 1, 0.1, 10); // perspektivische Kamera
	// Matrix fuer Modellierung/Viewing
	glMatrixMode(GL_MODELVIEW);

}

void Animate(int value)
{
	// Hier werden Berechnungen durchgeführt, die zu einer Animation der Szene  
	// erforderlich sind. Dieser Prozess läuft im Hintergrund und wird alle 
	// 1000 msec aufgerufen. Der Parameter "value" wird einfach nur um eins 
	// inkrementiert und dem Callback wieder uebergeben. 
	// std::cout << "value=" << value << std::endl;
	// RenderScene aufrufen

	// Berechnungen, die zu einer Animation der Szene erforderlich sind

	glutPostRedisplay();
	// Timer wieder registrieren - Animate wird so nach 10 msec mit value+=1 aufgerufen.
	int wait_msec = 10;
	glutTimerFunc(wait_msec, Animate, ++value);
}

int main(int argc, char** argv)
{
	std::cout << "Grundlegende Interaktionen:" << std::endl;
	std::cout << "Rechte Maustaste (ueber dem Graphik-Fenster)" << std::endl;
	std::cout << "zum Oeffnen des Menus verwenden" << std::endl << std::endl;
	std::cout << "Beenden: Graphik-Fenster schliessen oder per Menu!" << std::endl << std::endl;

	glutInit(&argc, argv);                // GLUT initialisieren
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 800);         // Fenster-Konfiguration
	glutCreateWindow("Nam; Gabriel");   // Fenster-Erzeugung
	glutDisplayFunc(RenderScene);         // Zeichenfunktion bekannt machen
	glutReshapeFunc(Reshape);
	// TimerCallback registrieren; wird nach 10 msec aufgerufen mit Parameter 0  
	glutTimerFunc(10, Animate, 0);
	Init();
	glutMainLoop();
	return 0;
}