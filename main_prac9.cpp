//*****************Semestre 2019-2*****************************//
//****************Visual Studio 2017**********************************************************//
//************** Alumno (s): Bermudez Sotelo Gustavo *****************************************//
//*************	Lab. Computación Gráfica   Gpo: 02						
//*************Pinoski de Navidad******************//
//************************************************************//

#include "texture.h"
#include "figuras.h"
#include "Camera.h"


//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////
static GLuint ciudad_display_list;	//Display List for the Monito


int w = 500, h = 500;
int frame = 0, time, timebase = 0;
int deltaTime = 0;
char s[30];

CCamera objCamera;	//Create objet Camera

GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

int font = (int)GLUT_BITMAP_HELVETICA_18;

GLfloat Diffuse[] = { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[] = { 0.0f, 7.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[] = { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

CTexture text1;
CTexture text2;
CTexture text3;	//Flecha
CTexture text4;	//Pavimento
CTexture text5;	//Pasto01
CTexture text6;	//Casa01

CTexture regalo;
CTexture regalo1;
CTexture regalo2;

CTexture esfera0;
CTexture esfera1;

CTexture pino;
CTexture tronco;

CTexture tree;
CTexture edificio;

CFiguras cubo;
CFiguras sky;

//END NEW//////////////////////////////////////////


CFiguras fig1;
CFiguras fig2;
CFiguras fig3;
CFiguras fig4;	//Pasto01
CFiguras fig5;	//Casa01
CFiguras fig6;
CFiguras fig7;	//Para crear Monito

void ciudad()
{

	glPushMatrix(); //Camino1
	glTranslatef(23.5, 0.0, 0.0);
	glScalef(40, 0.1, 7);
	glDisable(GL_LIGHTING);
	fig3.prisma2(text4.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Camino2
	glTranslatef(-23.5, 0.0, 0.0);
	glScalef(40, 0.1, 7);
	glDisable(GL_LIGHTING);
	fig3.prisma2(text4.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Pasto
	glTranslatef(0.0, 0.0, -4.0);
	glScalef(87, 0.1, 1);
	glDisable(GL_LIGHTING);
	fig4.prisma2(text5.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Pasto
	glTranslatef(0.0, 0.0, 4.0);
	glScalef(87, 0.1, 1);
	glDisable(GL_LIGHTING);
	fig4.prisma2(text5.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Casa01
	glTranslatef(0.0, 3.0, 7.0);
	glRotatef(90, 1, 0, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(6, 5.0, 6);
	glDisable(GL_LIGHTING);
	fig5.prisma2(text6.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Casa01
	glTranslatef(0.0, 3.0, -7.0);
	glRotatef(90, 1, 0, 0);
	//glRotatef(180,0,0,1);
	glScalef(6, 5.0, 6);
	glDisable(GL_LIGHTING);
	fig5.prisma2(text6.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();
}

void arbol()
{
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glEnable(GL_ALPHA_TEST);
	//glDisable(GL_DEPTH_TEST);   // Turn Depth Testing Off
	glAlphaFunc(GL_GREATER, 0.1);
	//glEnable(GL_BLEND);     // Turn Blending On
	//glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glBindTexture(GL_TEXTURE_2D, tree.GLindex);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotatef(45, 0, 1, 0);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotatef(-45, 0, 1, 0);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
	glEnd();
	glDisable(GL_ALPHA_TEST);
	//glDisable(GL_BLEND);        // Turn Blending Off
	//glEnable(GL_DEPTH_TEST);    // Turn Depth Testing On
	glEnable(GL_LIGHTING);

	glPopMatrix();
}

GLuint createDL()
{
	GLuint ciudadDL;
	//GLuint cieloDL;

	// Create the id for the list
	ciudadDL = glGenLists(1);
	// start list
	glNewList(ciudadDL, GL_COMPILE);
	// call the function that contains 
	// the rendering commands
	ciudad();
	//monito();
// endList
	glEndList();

	return(ciudadDL);
}

void InitGL(GLvoid)     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel(GL_SMOOTH);
	//Para construir la figura comentar esto
	glLightfv(GL_LIGHT1, GL_POSITION, Position);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Diffuse);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable(GL_COLOR_MATERIAL);

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);

	text1.LoadBMP("01.bmp");
	text1.BuildGLTexture();
	text1.ReleaseImage();

	text2.LoadBMP("logopumas.bmp");
	text2.BuildGLTexture();
	text2.ReleaseImage();

	text3.LoadTGA("city/arrow.tga");
	text3.BuildGLTexture();
	text3.ReleaseImage();

	text4.LoadTGA("city/pavimento.tga");
	text4.BuildGLTexture();
	text4.ReleaseImage();

	text5.LoadTGA("city/pasto01.tga");
	text5.BuildGLTexture();
	text5.ReleaseImage();

	text6.LoadTGA("city/casa01.tga");
	text6.BuildGLTexture();
	text6.ReleaseImage();
	///////////////////////regalos
	regalo.LoadTGA("regalo.tga");
	regalo.BuildGLTexture();
	regalo.ReleaseImage();

	regalo1.LoadTGA("regalo1.tga");
	regalo1.BuildGLTexture();
	regalo1.ReleaseImage();

	regalo2.LoadTGA("regalo2.tga");
	regalo2.BuildGLTexture();
	regalo2.ReleaseImage();
	////////////////////////////////////////esferas
	esfera0.LoadTGA("esferas.tga");
	esfera0.BuildGLTexture();
	esfera0.ReleaseImage();

	esfera1.LoadTGA("esferas1.tga");
	esfera1.BuildGLTexture();
	esfera1.ReleaseImage();

	//////////////////////////////////////////
	pino.LoadTGA("verde.tga");
	pino.BuildGLTexture();
	pino.ReleaseImage();

	tronco.LoadTGA("papel10.tga");
	tronco.BuildGLTexture();
	tronco.ReleaseImage();



	tree.LoadTGA("tree01.tga");
	tree.BuildGLTexture();
	tree.ReleaseImage();

	edificio.LoadTGA("edificio.tga");
	edificio.BuildGLTexture();
	edificio.ReleaseImage();

	//END NEW//////////////////////////////

	objCamera.Position_Camera(0, 2.5f, 3, 0, 2.5f, 0, 0, 1, 0);

	//NEW Crear una lista de dibujo
	ciudad_display_list = createDL();

}

void pintaTexto(float x, float y, float z, void *font, char *string)
{

	char *c;     //Almacena los caracteres a escribir
	glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
	//glWindowPos2i(150,100);
	for (c = string; *c != '\0'; c++) //Condicion de fin de cadena
	{
		glutBitmapCharacter(font, *c); //imprime
	}
}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();


	glPushMatrix();
	glRotatef(g_lookupdown, 1.0f, 0, 0);

	gluLookAt(objCamera.mPos.x, objCamera.mPos.y, objCamera.mPos.z,
		objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,
		objCamera.mUp.x, objCamera.mUp.y, objCamera.mUp.z);


	glPushMatrix();
	glPushMatrix(); //Creamos cielo
	glDisable(GL_LIGHTING);
	glTranslatef(0, 60, 0);
	fig1.skybox(130.0, 130.0, 130.0, text1.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(1, 1, 1);
	glCallList(ciudad_display_list);
	glDisable(GL_COLOR_MATERIAL);
	glPopMatrix();

	glPushMatrix(); //Flecha
	glScalef(7, 0.1, 7);
	glDisable(GL_LIGHTING);
	fig3.prisma_anun(text3.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glEnable(GL_COLOR_MATERIAL);
	/*glPushMatrix();
		glTranslatef(-30, 0, 10);
		arbol();
	glPopMatrix();*/

	glPushMatrix();
	glTranslatef(17, 0, -10);
	glColor3f(1.0, 1.0, 1.0);
	fig1.esfera(4, 20, 20, text2.GLindex);
	glPopMatrix();

	glColor3f(1.0, 1.0, 1.0);



	glPopMatrix();

	glPushMatrix(); //ARBOL  //ejercicio casa uno con blend otro con alpha
	//glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA)
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glTranslatef(45, 1.5, 0);
	fig1.cono(40, 10, 10, pino.GLindex);
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();//ARBOL

	glPushMatrix();
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glTranslatef(45, 0, 0);
	fig1.cilindro(5.0, 1.5, 10, tronco.GLindex);
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();//tronco


	glPushMatrix();
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glTranslatef(33, 1, 0);
	fig1.prisma(2.5, 1.5, 1, regalo.GLindex);
	glDisable(GL_ALPHA_TEST);
	glPopMatrix(); //regalo1

	glPushMatrix();
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glTranslatef(33, 1.5, -1.5);
	fig1.prisma(3.0, 0.5, 1, regalo1.GLindex);
	glDisable(GL_ALPHA_TEST);
	glPopMatrix(); //regalo2


	glPushMatrix();
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glTranslatef(33, 0.5, 1.5);
	fig1.prisma(1.8, 0.5, 1, regalo2.GLindex);
	glDisable(GL_ALPHA_TEST);
	glPopMatrix(); //regalo3


	glPushMatrix();
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//glEnable(GL_ALPHA_TEST);
	//glAlphaFunc(GL_GREATER, 0.1);
	glTranslatef(39, 18, -0.5);
	fig1.esfera(1, 10, 10, esfera0.GLindex);
	//glDisable(GL_ALPHA_TEST);
	glDisable(GL_BLEND);
	glPopMatrix(); //ESFERA1

	glPushMatrix();
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//glEnable(GL_ALPHA_TEST);
	//glAlphaFunc(GL_GREATER, 0.1);
	glTranslatef(41, 25, -0.2);
	fig1.esfera(1, 10, 10, esfera0.GLindex);
	//glDisable(GL_ALPHA_TEST);
	glDisable(GL_BLEND);
	glPopMatrix(); //ESFERA2


	glPushMatrix();
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//glEnable(GL_ALPHA_TEST);
	//glAlphaFunc(GL_GREATER, 0.1);
	glTranslatef(42, 30, 0.5);
	fig1.esfera(1, 10, 10, esfera1.GLindex);
	//glDisable(GL_ALPHA_TEST);
	glDisable(GL_BLEND);
	glPopMatrix(); //ESFERA3


	glPushMatrix();
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//glEnable(GL_ALPHA_TEST);
	//glAlphaFunc(GL_GREATER, 0.1);
	glTranslatef(38, 15, -0.8);
	fig1.esfera(1, 10, 10, esfera0.GLindex);
	//glDisable(GL_ALPHA_TEST);
	glDisable(GL_BLEND);
	glPopMatrix(); //ESFERA4


	glPushMatrix();
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//glEnable(GL_ALPHA_TEST);
	//glAlphaFunc(GL_GREATER, 0.1);
	glTranslatef(37, 10, 0.35);
	fig1.esfera(1, 10, 10, esfera1.GLindex);
	//glDisable(GL_ALPHA_TEST);
	glDisable(GL_BLEND);
	glPopMatrix(); //ESFERA5


	glPushMatrix();
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//glEnable(GL_ALPHA_TEST);
	//glAlphaFunc(GL_GREATER, 0.1);
	glTranslatef(36, 5, 0.6);
	fig1.esfera(1, 10, 10, esfera0.GLindex);
	//glDisable(GL_ALPHA_TEST);
	glDisable(GL_BLEND);
	glPopMatrix(); //ESFERA6







	glPopMatrix();




	glPopMatrix();



	glutSwapBuffers();
	//TODO ESTA DENTRO DE UN PUCH Y POP
}

void animacion()
{

	fig3.text_izq -= 0.001;
	fig3.text_der -= 0.001;
	if (fig3.text_izq < -1)
		fig3.text_izq = 0;
	if (fig3.text_der < 0)
		fig3.text_der = 1;


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

	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 170.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {

	case 'w':   //Movimientos de camara
	case 'W':
		objCamera.Move_Camera(CAMERASPEED + 0.2);
		break;

	case 's':
	case 'S':
		objCamera.Move_Camera(-(CAMERASPEED + 0.2));
		break;

	case 'a':
	case 'A':
		objCamera.Strafe_Camera(-(CAMERASPEED + 0.4));
		break;

	case 'd':
	case 'D':
		objCamera.Strafe_Camera(CAMERASPEED + 0.4);
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
	case GLUT_KEY_PAGE_UP:
		objCamera.UpDown_Camera(CAMERASPEED);
		break;

	case GLUT_KEY_PAGE_DOWN:
		objCamera.UpDown_Camera(-CAMERASPEED);
		break;

	case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		g_lookupdown -= 1.0f;
		break;

	case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		g_lookupdown += 1.0f;
		break;

	case GLUT_KEY_LEFT:
		objCamera.Rotate_View(-CAMERASPEED);
		break;

	case GLUT_KEY_RIGHT:
		objCamera.Rotate_View(CAMERASPEED);
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
	glutInitWindowSize(1000, 1000);	// Tamaño de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("Arbol de Navidick"); // Nombre de la Ventana
	//glutFullScreen     ( );         // Full Screen
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutIdleFunc(animacion);


	glutMainLoop();          // 

	return 0;
}