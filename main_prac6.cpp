//Semestre 2019 - 1
//************************************************************//
//****************Visual Studio 2017******************//
//************** Alumno (s):  *********************************//
//************* Grupo 02  ******//
//*************			Practica 6 Ejercicio Clase:	Sistema solar			******//
//************************************************************//
#include "Main.h"


// Variables used to calculate frames per second: (Windows)
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;

//lunas un poco separadas de los planetas para que se vean correcctamente rotar en el planeta

//Variables used to create movement

int sol = 0;
int mercurio = 0;
int venus = 0;
int tierra = 0;
int luna = 0;
int marte = 0;
int luna1 = 0;
int luna2 = 0;
int jupiter = 0;
int luna1Jupiter = 0;
int luna2jupiter = 0;
int luna3jupiter = 0;
int saturno = 0;
int urano = 0;

float camaraZ = 0.0;
float camaraX = 0.0;

GLfloat SunDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat SunSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat SunPosition[] = { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position

GLfloat EarthDiffuse[] = { 0.2f, 0.2f, 1.0f, 1.0f };			// Tierra
GLfloat EarthSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat EarthShininess[] = { 50.0 };

GLfloat MoonDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };			// Luna
GLfloat MoonSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat MoonShininess[] = { 50.0 };

GLfloat MarsDiffuse[] = { 0.8f, 0.4f, 0.1f, 1.0f };			// Marte
GLfloat MarsSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MarsShininess[] = { 50.0 };

void InitGL(GLvoid)     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);


}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(camaraX, 0.0, -5.0 + camaraZ);			//camara

	glPushMatrix(); //Sistema solar, es el general para todo


	glPushMatrix();//sol
	glRotatef(sol, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje pero para ello el rotatef queda fuera para que mueva a todo
	glColor3f(1.0, 1.0, 0.0);	//Sol amarillo
	glutSolidSphere(1.9, 18, 18);  //Draw Sun (radio,H,V); mientras mas puntos tenga aqui mas circular se vera

	glPopMatrix();

	glPushMatrix();//mercurio
	glRotatef(mercurio, 0, 1, 0);
	glTranslatef(3.2, 0, 0);
	glRotatef(mercurio, 0, 1, 0);
	glColor3f(0.5, 0.5, 0.5);
	glutSolidSphere(0.3, 8, 8);
	glPopMatrix();

	glPushMatrix();//venus
	glRotatef(venus, 0, 1, 0);
	glTranslatef(4.7, 0, 0);
	glRotatef(venus, 0, 1, 0);
	glColor3f(0.0, 0.8, 1.0);
	glutSolidSphere(0.5, 9, 8);
	glPopMatrix();

	glPushMatrix();//tierra
	glRotatef(tierra, 0, 1, 0);
	glTranslatef(6.4, 0, 0);
	glRotatef(tierra, 0, 1, 0);
	glColor3f(0.7, 0.8, 1.0);
	glutSolidSphere(0.7, 8, 8);

	glPushMatrix();//luna tierra
	glRotatef(luna, 0, 1, 0);
	glTranslatef(1.0, 0, 0);
	glRotatef(luna, 0, 1, 0);
	glColor3f(7.7, 7.8, 7.0);
	glutSolidSphere(0.1, 8, 8);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();//marte
	glRotatef(marte, 0, 1, 0);
	glTranslatef(8.4, 0, 0);
	glRotatef(marte, 0, 1, 0);
	glColor3f(1.0, 0.0, 0.0);
	glutSolidSphere(0.4, 8, 8);

	glPushMatrix();//luna1 marte
	glRotatef(luna1, 0, 1, 0);
	glTranslatef(0.5, 0, 0);
	glRotatef(luna1, 0, 1, 0);
	glColor3f(0.1, 0.8, 0.8);
	glutSolidSphere(0.1, 8, 8);


	glPushMatrix();//jupiter
	glRotatef(jupiter, 0, 1, 0);
	glTranslatef(11, 0, 0);
	glRotatef(jupiter, 0, 1, 0);
	glColor3f(1.0, 1.0, 0.7);
	glutSolidSphere(1, 8, 9);

	glPushMatrix();//luna1Jupiter
	glRotatef(luna1Jupiter, 0, 1, 0);
	glTranslatef(1.2, 0, 0);
	glRotatef(luna1Jupiter, 0, 1, 0);
	glColor3f(1.0, 0.4, 0.7);
	glutSolidSphere(0.1, 8, 9);

	glPushMatrix();//luna2Jupiter
	glRotatef(luna2jupiter, 0, 1, 0);
	glTranslatef(1.4, 0, 0);
	glRotatef(luna2jupiter, 0, 1, 0);
	glColor3f(1.0, 0.4, 0.7);
	glutSolidSphere(0.2, 9, 9);

	glPushMatrix();//saturno
	glRotatef(saturno, 0, 1, 0);
	glTranslatef(16, 0, 0);
	glRotatef(saturno, 0, 1, 0);
	glColor3f(0.2, 0.6, 1.0);
	glutSolidSphere(0.9, 9, 9);
	glRotatef(30, 1, 0, 0); //anillo1
	glColor3f(1, 0, 0);
	glutSolidTorus(0.5, 2, 9, 9);
	//glPopMatrix();
	glRotatef(90, 1, 0, 0); //anillo2
	glColor3f(1, 1, 0);
	glutSolidTorus(0.4, 1.3, 10, 10);
	glPopMatrix();

	glPushMatrix();//urano
	glRotatef(urano, 0, 1, 0);
	glTranslatef(20, 0, 0);
	glRotatef(urano, 0, 1, 0);
	glColor3f(0.0, 1.0, 1.0);
	glutSolidSphere(0.8, 9, 9);
	glPopMatrix();

	glPopMatrix();

	glRotatef(sol, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje
	glColor3f(1.0, 1.0, 0.0);	//Sol amarillo
	glutSolidSphere(1.9, 12, 12);  //Draw Sun (radio,H,V); mientras mas puntos tenga aqui mas circular se vera

	glutSwapBuffers();

}

void animacion()
{
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if (dwElapsedTime >= 30)
	{
		sol = (sol - 5) % 360;	//cuando llegue a 360° se vuelve a inicializar la variable y sigue girando //su el 5 le ponemos menos gira mas lento
		mercurio = (mercurio - 8) % 360;
		venus = (venus - 8) % 360;
		tierra = (tierra - 8) % 360;
		luna = (luna - 8) % 360;
		marte = (marte - 8) % 360;
		luna1 = (luna1 - 9) % 360;
		luna2 = (luna2 - 10) % 360;
		jupiter = (jupiter - 9) % 360;
		luna1Jupiter = (luna1Jupiter - 9) % 360;
		luna2jupiter = (luna2jupiter - 8) % 360;
		saturno = (saturno - 8) % 360;
		urano = (urano - 8) % 360;


		dwLastUpdateTime = dwCurrentTime;
	}

	glutPostRedisplay();
}

void reshape(int width, int height)   // Creamos funcion Reshape
{
	if (height == 0)										// Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista

	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
														//glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':   //Movimientos de camara
	case 'W':
		camaraZ += 0.5f;
		break;
	case 's':
	case 'S':
		camaraZ -= 0.5f;
		break;
	case 'a':
	case 'A':
		camaraX -= 0.5f;
		break;
	case 'd':
	case 'D':
		camaraX += 0.5f;
		break;

	case 'i':		//Movimientos de Luz
	case 'I':

		break;
	case 'k':
	case 'K':

		break;

	case 'l':   //Activamos/desactivamos luz
	case 'L':
		break;
	case 27:        // Cuando Esc es presionado...
		exit(0);   // Salimos del programa
		break;
	default:        // Cualquier otra
		break;
	}
	glutPostRedisplay();
}

void arrow_keys(int a_keys, int x, int y)  // Funcion para manejo de teclas especiales (arrow keys)
{
	switch (a_keys) {
	case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...

		break;
	case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...

		break;
	case GLUT_KEY_LEFT:

		break;
	case GLUT_KEY_RIGHT:

		break;
	default:
		break;
	}
	glutPostRedisplay();
}


int main(int argc, char** argv)   // Main Function
{
	glutInit(&argc, argv); // Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	glutInitWindowSize(500, 500);	// Tamaño de la Ventana
	glutInitWindowPosition(20, 60);	//Posicion de la Ventana
	glutCreateWindow("Sistema Solar"); // Nombre de la Ventana
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutIdleFunc(animacion);
	glutMainLoop();          // 

	return 0;
}