//Semestre 2019 - 2
//*****             Lab. Computacion Gráfica                ************//
//*****************  Visual studio 2017                     ***********//
//************** Alumno (s): Bermudez Sotelo Gustavo       **********//
//*************	Practica 5: Ejercicio Clase					   ******//
//*************		Creacion de brazo, mano y dedos con rotaciones ******//
//************************************************************//
#include "Main.h"

float transZ = -5.0f;
float transX = 0.0f;
float angleX = 0.0f;
float angleY = 0.0f;
int screenW = 0.0;
int screenH = 0.0;
float angHombro = 0.0;
float angBrazo = 0.0;
float angPalma = 0.0;
float angDedo1 = 0.0;
float angDedo2 = 0.0;


GLfloat Position[] = { 0.0f, 3.0f, 0.0f, 1.0f };			// Light Position
GLfloat Position2[] = { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

void InitGL(void)     // Inicializamos parametros
{

	glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing

	//Configuracion luz
	glLightfv(GL_LIGHT0, GL_POSITION, Position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);


	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glEnable(GL_COLOR_MATERIAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(void)
{
	GLfloat vertice[8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
	};

	glBegin(GL_POLYGON);	//Front
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[2]);
	glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);  //Top
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[7]);
	glEnd();
}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(transX, 0.0f, transZ);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleX, 1.0, 0.0, 0.0);

	//Poner Código Aquí. (0,0,0)

	glPushMatrix();	// brazo
	glTranslatef(-2.5, 1.25, 0); //(-2.5,1.25,0) aqui se translada mi pivote para colocar la rotacion
	glRotatef(angHombro, 0, 0, 1); //rotacion en mi pivote (-2.5,1.25,0)

	glPushMatrix();//dibujar brazo
	glTranslatef(2.5, -1.25, 0);	//aqui regresamos al origen (0,0,0) para dibujar nuestro prisma
	glScalef(5, 2.5, 5);
	glColor3f(1, 1, 1);
	prisma();
	glPopMatrix();


	glPushMatrix(); //antebrazo
	glTranslatef(5, -1.25, 0); //pivote en (2.5,0,0)
	glRotatef(angBrazo, 0, 1, 0);

	glPushMatrix();//dibujar antebrazo
	glTranslatef(3, 0, 0);	//vamos al centro de mi nuevo prisma para dibujarlo
	glScalef(6, 2.5, 4);
	glColor3f(1, 0, 0);
	prisma();
	glPopMatrix();


	glPushMatrix(); //palma
	glTranslatef(6, 0, 0); //pivote en (8.5,0,0)
	glRotatef(angPalma, 0, 1, 0); //rotacion en mi pivote Y

	glPushMatrix();//dibujar palma
	glTranslatef(1, 0, 0);	//vamos al centro de mi nuevo prisma para dibujarlo
	glScalef(2, 2.5, 2);
	glColor3f(0, 1, 0);
	prisma();
	glPopMatrix();

	glPushMatrix(); //Dedo pulgar 1ra parte
	glTranslatef(1, 1.25, 0); //pivote en (9.5,1.25,0)
	glRotatef(angDedo1, -1, 0, 0);

	glPushMatrix();
	glTranslatef(0, 0.25, 0);
	glScalef(0.5, 0.5, 0.5);
	glColor3f(0, 0, 1);
	prisma();
	glPopMatrix();

	glPushMatrix();		//dedo pulgar 2d parte
	glTranslatef(0, 0.5, 0); //pivote en (9.5,1.75,0)
	glRotatef(angDedo1, -1, 0, 0);

	glPushMatrix();
	glTranslatef(0, 0.25, 0);
	glScalef(0.5, 0.5, 0.5);
	glColor3f(0.5, 0, 0.2);
	prisma();
	glPopMatrix();

	glPushMatrix();	//dedo indice 2da parte
	glTranslatef(1.5, -1, 0); //pivote (11,0.75,0)
	glRotatef(angDedo1, 0, 1, 0);

	glPushMatrix();
	glTranslatef(0.25, 0, 0);
	glScalef(0.5, 0.5, 0.5);
	glColor3f(0, 1, 1);
	prisma();
	glPopMatrix();

	glPushMatrix();//dedo indice 1ra parte
	glTranslatef(-0.25, 0, 0);
	glScalef(0.5, 0.5, 0.5);
	glColor3f(0, 1, 0);
	prisma();
	glPopMatrix();

	glPushMatrix(); //dedo indice 3er parte
	glTranslatef(0.5, 0, 0); //pivote en (11.5,0.75,0)
	glRotatef(angDedo1, 0, 1, 0);

	glPushMatrix();
	glTranslatef(0.25, 0, 0);
	glScalef(0.5, 0.5, 0.5);
	glColor3f(1, 0, 0);
	prisma();
	glPopMatrix();

	glPushMatrix();//dedo anular 3er parte
	glTranslatef(0, -1, 0); //pivote en (11.5,-0.25,0)
	glRotatef(angDedo1, 0, 1, 0);

	glPushMatrix();
	glTranslatef(0.25, 0, 0);
	glScalef(0.5, 0.5, 0.5);
	glColor3f(1, 1, 0);
	prisma();
	glPopMatrix();


	glPushMatrix();//dedo anular 2da parte
	glTranslatef(-0.5, 0, 0); //pivote en (11,-0.25,0)
	glRotatef(angDedo1, 0, 1, 0);

	glPushMatrix();
	glTranslatef(0.25, 0, 0);
	glScalef(0.5, 0.5, 0.5);
	glColor3f(0, 1, 0);
	prisma();
	glPopMatrix();

	glPushMatrix();//1ra parte
	glTranslatef(-0.25, 0, 0);
	glScalef(0.5, 0.5, 0.5);
	glColor3f(1, 1, 0);
	prisma();
	glPopMatrix();


	glPushMatrix();//dedo meñique 3er parte
	glTranslatef(0, -0.5, 0); //pivote en (11,-0.75,0)
	glRotatef(angDedo1, 0, 1, 0);

	glPushMatrix();
	glTranslatef(0.125, 0, 0);
	glScalef(0.25, 0.5, 0.5);
	glColor3f(0, 1, 0);
	prisma();
	glPopMatrix();


	glPushMatrix();//dedo meñique 2da parte
	glTranslatef(-0.25, 0, 0); //pivote en (10.75,-0.75,0)
	glRotatef(angDedo1, 0, 1, 0);

	glPushMatrix();
	glTranslatef(0.125, 0, 0);
	glScalef(0.25, 0.5, 0.5);
	glColor3f(1, 0, 0);
	prisma();
	glPopMatrix();

	glPushMatrix();//primera parte
	glTranslatef(-0.125, 0, 0);
	glScalef(0.25, 0.5, 0.5);
	prisma();
	glPopMatrix();


	glPushMatrix();//dedo medio 1ra parte
	glTranslatef(0.5, 1, 0); //pivote en (11.25,0.25,0)
	glRotatef(angDedo1, 0, 1, 0);

	glPushMatrix();
	glTranslatef(-0.375, 0, 0);
	glScalef(0.75, 0.5, 0.5);
	glColor3f(1, 1, 0);
	prisma();
	glPopMatrix();

	glPushMatrix();//2da parte dedo medio
	glTranslatef(0.375, 0, 0);
	glScalef(0.75, 0.5, 0.5);
	glColor3f(0, 1, 0);
	prisma();
	glPopMatrix();


	glPushMatrix();//dedo medio 3ra parte
	glTranslatef(0.75, 0, 0); //pivote en (12,0.25,0)
	glRotatef(angDedo1, 0, 1, 0);

	glPushMatrix();
	glTranslatef(0.375, 0, 0);
	glScalef(0.75, 0.5, 0.5);
	glColor3f(1, 0, 0);
	prisma();
	glPopMatrix();

	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();




	glutSwapBuffers();
	// Swap The Buffers
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
	//glOrtho(-5,5,-5,5,0.2,20);	
	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();									
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':
	case 'W':
		transZ += 0.2f;
		break;
	case 's':
	case 'S':
		transZ -= 0.2f;
		break;
	case 'a':
	case 'A':
		transX += 0.2f;
		break;
	case 'd':
	case 'D':
		transX -= 0.2f;
		break;
	case 'h':
		//para rotar el hombro en z, lim 90°
		if (angHombro < 90) {
			angHombro += 0.5f;
			printf("%f", angHombro);
		}
		break;
	case 'H':
		//para rotar el hombro en sentido negativo
		if (angHombro > -90) {
			angHombro -= 0.5f;
			printf("%f", angHombro);
		}
		break;
	case 'l':
		//para rotar el antebrazo en Y enfrente con lim90°
		if (angBrazo < 90) {
			angBrazo += 0.5f;
			printf("%f", angBrazo);
		}
		break;
	case 'L':
		//para rotar el antebrazo para atras
		if (angBrazo > -90) {
			angBrazo -= 0.5f;
		}
		break;
	case 'p':
		//para rotar palma en Y enfrente 90°
		if (angPalma < 90) {
			angPalma += 0.5f;
		}
		break;
	case 'P':
		//para rotar el palma atras 90°
		if (angPalma > -90) {
			angPalma -= 0.5f;
		}
		break;
	case 'm':
		//rotar los dedos
		if (angDedo1 < 10) {
			angDedo1 += 0.5f;
		}
		break;
	case 'M':
		//rotar los dedos
		if (angDedo1 > -10) {
			angDedo1 -= 0.5f;
		}
		break;

	case 'n':
		//rotar los dedos
		if (angDedo2 < 10) {
			angDedo2 += 0.5f;
		}
		break;
	case 'N':
		//rotar los dedos
		if (angDedo2 > -15) {
			angDedo2 -= 0.5f;
		}
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
	case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		angleX += 2.0f;
		break;
	case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		angleX -= 2.0f;
		break;
	case GLUT_KEY_LEFT:
		angleY += 2.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -= 2.0f;
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
	screenW = glutGet(GLUT_SCREEN_WIDTH);
	screenH = glutGet(GLUT_SCREEN_HEIGHT);
	glutInitWindowSize(500, 500);	// Tamaño de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("Practica 5"); // Nombre de la Ventana
	printf("Resolution H: %i \n", screenW);
	printf("Resolution V: %i \n", screenH);
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutMainLoop();          // 

	return 0;
}