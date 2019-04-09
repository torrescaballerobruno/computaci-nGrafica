//#include <Windows.h>
// al incluir a glut. h incluye a gl.h a  glu.h
#include <GL/glut.h>

#include "figuras.h"
#include "mar_textura.c"
#include "arena_textura.c"
#include "piso_textura.c"
#include "palmera_textura.c"
#include "tronco_textura.c"
#include "aje_texture.c"
#include "M_text.c"
#include "me_text.c"
#include "pared_textura.c"
#include "puerta_textura.c"
#include "torre_textura.c"
#include "sol_textura.c"
#include "letre_textura.c"

//variables para acumular traslación con teclas w,s (en z) a,d (en x) e,c (en y)
float transZ = -5.0f;
float transX = 0.0f;
float transY = -5.0f;

//variables para acumular rotación con flechas de dirección
float angleX = 0.0f;
float angleY = 0.0f;

//identificadores de textura

GLuint textura_piso;
GLuint textura_pared;
GLuint textura_m;
GLuint idT_mar;
GLuint idT_arena;
GLuint idT_piso;
GLuint idT_tronco;
GLuint idT_palmera;
GLuint idT_pared;
GLuint idT_puerta;
GLuint idT_torre;
GLuint idT_sol;
GLuint idT_letre;

//función para inicializar estados de gl
void inicializar(void)
{
	glClearColor(0.831, 0.949, 0.988, 1);
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glGenTextures(1,  textura_piso);
	glBindTexture(GL_TEXTURE_2D, textura_piso);

	gluBuild2DMipmaps(GL_TEXTURE_2D,
		M_text.bytes_per_pixel, M_text.width,
		M_text.height, GL_RGB, GL_UNSIGNED_BYTE,
		M_text.pixel_data);

	glGenTextures(1, &textura_pared);
	glBindTexture(GL_TEXTURE_2D, textura_pared);

	gluBuild2DMipmaps(GL_TEXTURE_2D,
		me_text.bytes_per_pixel, me_text.width,
		me_text.height, GL_RGB, GL_UNSIGNED_BYTE,
		me_text.pixel_data);

	glGenTextures(1, &textura_m);
	glBindTexture(GL_TEXTURE_2D, textura_m);

	gluBuild2DMipmaps(GL_TEXTURE_2D,
		ab_texture.bytes_per_pixel, ab_texture.width,
		ab_texture.height, GL_RGB, GL_UNSIGNED_BYTE,
		ab_texture.pixel_data);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	//carga textura mar
	glGenTextures(1, &idT_mar);
	glBindTexture(GL_TEXTURE_2D, idT_mar);

	gluBuild2DMipmaps(GL_TEXTURE_2D,
		mar_text.bytes_per_pixel, mar_text.width,
		mar_text.height, GL_RGB, GL_UNSIGNED_BYTE,
		mar_text.pixel_data);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	//carga textura arena
	glGenTextures(1, &idT_arena);
	glBindTexture(GL_TEXTURE_2D, idT_arena);

	gluBuild2DMipmaps(GL_TEXTURE_2D,
		ar_text.bytes_per_pixel, ar_text.width,
		ar_text.height, GL_RGB, GL_UNSIGNED_BYTE,
		ar_text.pixel_data);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	//carga textura piso
	glGenTextures(1, &idT_piso);
	glBindTexture(GL_TEXTURE_2D, idT_piso);

	gluBuild2DMipmaps(GL_TEXTURE_2D,
		p_text.bytes_per_pixel, p_text.width,
		p_text.height, GL_RGB, GL_UNSIGNED_BYTE,
		p_text.pixel_data);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);


	// En caso de no querer repetir las texturas, comentar estas
	// dos líneas
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	//carga textura tronco
	glGenTextures(1, &idT_tronco);
	glBindTexture(GL_TEXTURE_2D, idT_tronco);

	gluBuild2DMipmaps(GL_TEXTURE_2D,
		tr_text.bytes_per_pixel, tr_text.width,
		tr_text.height, GL_RGB, GL_UNSIGNED_BYTE,
		tr_text.pixel_data);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	//carga textura palmera
	glGenTextures(1, &idT_palmera);
	glBindTexture(GL_TEXTURE_2D, idT_palmera);

	gluBuild2DMipmaps(GL_TEXTURE_2D,
		palm_text.bytes_per_pixel, palm_text.width,
		palm_text.height, GL_RGB, GL_UNSIGNED_BYTE,
		palm_text.pixel_data);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	//carga textura pared
	glGenTextures(1, &idT_pared);
	glBindTexture(GL_TEXTURE_2D, idT_pared);

	gluBuild2DMipmaps(GL_TEXTURE_2D,
		w_text.bytes_per_pixel, w_text.width,
		w_text.height, GL_RGB, GL_UNSIGNED_BYTE,
		w_text.pixel_data);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	//carga textura puerta
	glGenTextures(1, &idT_puerta);
	glBindTexture(GL_TEXTURE_2D, idT_puerta);

	gluBuild2DMipmaps(GL_TEXTURE_2D,
		do_text.bytes_per_pixel, do_text.width,
		do_text.height, GL_RGB, GL_UNSIGNED_BYTE,
		do_text.pixel_data);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	//carga textura sol
	glGenTextures(1, &idT_sol);
	glBindTexture(GL_TEXTURE_2D, idT_sol);

	gluBuild2DMipmaps(GL_TEXTURE_2D,
		sun_text.bytes_per_pixel, sun_text.width,
		sun_text.height, GL_RGB, GL_UNSIGNED_BYTE,
		sun_text.pixel_data);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	//carga textura torre
	glGenTextures(1, &idT_torre);
	glBindTexture(GL_TEXTURE_2D, idT_torre);

	gluBuild2DMipmaps(GL_TEXTURE_2D,
		tower_text.bytes_per_pixel, tower_text.width,
		tower_text.height, GL_RGB, GL_UNSIGNED_BYTE,
		tower_text.pixel_data);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	//carga textura letrero
	glGenTextures(1, &idT_letre);
	glBindTexture(GL_TEXTURE_2D, idT_letre);

	gluBuild2DMipmaps(GL_TEXTURE_2D,
		l_text.bytes_per_pixel, l_text.width,
		l_text.height, GL_RGB, GL_UNSIGNED_BYTE,
		l_text.pixel_data);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);


	glEnable(GL_TEXTURE_2D);


}

void prisma(void)
{
	GLfloat vertice[8][3] = {
		{ 0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 0 V0
	{ -0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 1 V1
	{ -0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 2 V2
	{ 0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 3 V3
	{ 0.5 ,0.5, 0.5 },    //Coordenadas Vértice 4 V4
	{ 0.5 ,0.5, -0.5 },    //Coordenadas Vértice 5 V5
	{ -0.5 ,0.5, -0.5 },    //Coordenadas Vértice 6 V6
	{ -0.5 ,0.5, 0.5 },    //Coordenadas Vértice 7 V7
	};
	glBindTexture(GL_TEXTURE_2D, textura_piso);
	glBegin(GL_POLYGON);	//Enfrente

	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[1]);
	glEnd();


	glBindTexture(GL_TEXTURE_2D, textura_pared
	);
	glBegin(GL_POLYGON);	//Derecha
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura_m
	);
	glBegin(GL_POLYGON);	//Atrás
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura_piso);
	glBegin(GL_POLYGON);  //Izquierda
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura_pared
	);
	glBegin(GL_POLYGON);  //Abajo
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura_piso);
	glBegin(GL_POLYGON);  //Arriba
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0, 1.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[7]);
	glEnd();
}

void prisma2()  //Funcion creacion prisma
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


	glBindTexture(GL_TEXTURE_2D, idT_arena);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Front
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[1]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, idT_piso);
	glBegin(GL_POLYGON);	//Right
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, idT_pared);
	glBegin(GL_POLYGON);	//Back
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, idT_puerta);
	glBegin(GL_POLYGON);  //Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, idT_letre);
	glBegin(GL_POLYGON);  //Bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, idT_mar);   // choose the texture to use.
	glBegin(GL_POLYGON);  //Top
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[7]);
	glEnd();
}

void dibujar(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limpiamos pantalla y Depth Buffer

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	//se debe recorrer hacia z negativo xq la cara de enfrente está mi espalda
	//si no lo recorro lo suficiente las caras de los lados se verán largas
	glTranslatef(transX, transY, transZ);

	glRotatef(angleY, 0.0, 1.0, 0.0);	 //gira sobre y sentido horario
	glRotatef(angleX, 1.0, 0.0, 0.0);	 //gira sobre x sentido antihorario


									//dibujar
	//MESA DE AJEDREZ
	glPushMatrix();
	glTranslatef(0,0,-4);
	glPushMatrix();
	//patas

	glRotatef(90, 0, 1, 0);
	glScalef(1.0f, 4.0f, 1.0f);
	prisma();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.0, -5.0);
	glScalef(1.0f, 4.0f, 1.0f);
	glRotatef(90, 0, 1, 0);
	prisma();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(5.0, 0.0, 0.0);
	glScalef(1.0f, 4.0f, 1.0f);
	prisma();

	glPopMatrix();

	glPushMatrix();
	glTranslatef(5.0, 0.0, -5.0);
	glScalef(1.0f, 4.0f, 1.0f);
	prisma();
	glPopMatrix();

	// marco metal
	glPushMatrix();

	glTranslatef(2.5, 1.5, 0.0);
	glRotatef(-90, 1, 0, 0);
	glRotatef(-90, 0, 1, 0);
	glScalef(1.0f, 1.0f, 4.0f);
	prisma();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 1.5, -2.5);
	glRotatef(-90, 1, 0, 0);
	glRotatef(-90, 0, 1, 0);
	glScalef(1.0f, 4.0f, 1.0f);
	prisma();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(5, 1.5, -2.5);
	glRotatef(-90, 1, 0, 0);
	glRotatef(-90, 0, 1, 0);
	glScalef(1.0f, 4.0f, 1.0f);
	prisma();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.5, 1.5, -5.0);
	glRotatef(-90, 1, 0, 0);
	glRotatef(-90, 0, 1, 0);
	glScalef(1.0f, 1.0f, 4.0f);
	prisma();
	glPopMatrix();


	// tablero
	glPushMatrix();
	glTranslatef(1, 1.5, -1);
	glRotatef(90, 1, 0, 0);
	prisma();
	glTranslatef(0, -1, 0);
	prisma();
	glTranslatef(0, -1, 0);
	prisma();
	glTranslatef(0, -1, 0);
	prisma();
	glTranslatef(1, 0, 0);
	prisma();
	glTranslatef(0, 1, 0);
	prisma();
	glTranslatef(0, 1, 0);
	prisma();
	glTranslatef(0, 1, 0);
	prisma();
	glTranslatef(1, 0, 0);
	prisma();
	glTranslatef(0, -1, 0);
	prisma();
	glTranslatef(0, -1, 0);
	prisma();
	glTranslatef(0, -1, 0);
	prisma();
	glTranslatef(1, 0, 0);
	prisma();
	glTranslatef(0, 1, 0);
	prisma();
	glTranslatef(0, 1, 0);
	prisma();
	glTranslatef(0, 1, 0);
	prisma();
	glPopMatrix();
	
	glPopMatrix();
	//mar
	glPushMatrix();
	glScalef(20.0f, 0.1f, -10.0f);
	prisma2();
	glPopMatrix();

	//arena
	glPushMatrix();
	glTranslatef(0,0,-5.5);
	glScalef(20.0f,0.2f,8.0f);
	glRotatef(-90,1,0,0);
	prisma2();
	glPopMatrix();
	//piso
	glPushMatrix();
	glTranslatef(0.0,0.0,-12.0);
	glRotatef(90,0,0,1);
	glScalef(0.5f,20.0f,5.0f);
	prisma2();
	glPopMatrix();

	//palmeras y troncos
	glPushMatrix();
	glTranslatef(-5,0.2,-7);
	cilindro(0.5,4,20, idT_tronco);

	//palmera
	glTranslatef(0,5,0);
	esfera(2,20,20,idT_palmera);

	glPopMatrix();
	//tronco 2
	glPushMatrix();
	glTranslatef(7.5, 0.2, -9);
	cilindro(0.5, 4, 20, idT_tronco);

	//palmera
	glTranslatef(0, 3.5, 0);
	cono(4, 2.5, 20, idT_palmera);
	glPopMatrix();

	//hotel
	glPushMatrix();
	glTranslatef(0,5,-14);
	glRotatef(180,0,1,0);
	glScalef(19.0f,9.4f,0.2f);
	prisma2();
	glPopMatrix();

	//puerta
	glPushMatrix();
	glTranslatef(1.5,2,-13);
	glRotatef(90,0,1,0);
	glRotatef(90,1,0,0);
	glScalef(0.1f,2.0f,4.0f);
	prisma2();
	glPopMatrix();

	//sol
	glPushMatrix();
	glTranslatef(-5,15,-8);
	esfera(1.2,20,20,idT_sol);
	glPopMatrix();

	//torres hotel
	glPushMatrix();
	glTranslatef(-9.4,0,-14);
	cilindro(1,10,15,idT_torre);

	glTranslatef(18.8, 0, 0);
	cilindro(1, 10, 15, idT_torre);
	glPopMatrix();

	//letrero
	glPushMatrix();
	glTranslatef(-2.5, 5, -13);
	glScalef(4.0f, 2.1f, 0.1f);
	glRotatef(-90, 1, 0, 0);
	prisma2();
	glPopMatrix();
	glFlush();
}

void remodelar(int width, int height)   // Creamos funcion Reshape
{
	if (height == 0)										// Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	//glFrustum (-5, 5, -5, 5, 4, 20.0);
	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 50.0);

	glutPostRedisplay();
}

void teclado(unsigned char key, int x, int y)
{
	switch (key) {
	case 'w': case 'W':  //acerca al objeto con traslación en z pos
		transZ += 0.2f;
		break;

	case 's': case 'S':  //aleja al objeto con traslación en z neg
		transZ -= 0.2f;
		break;

	case 'a': case 'A':  //traslada objeto hacia la derecha en x pos
		transX += 0.2f;
		break;

	case 'd': case 'D':  //traslada objeto hacia la izquierda en x neg
		transX -= 0.2f;
		break;

	case 'e': case 'E':  //traslada objeto hacia arriba en y pos
		transY += 0.2f;
		break;

	case 'c': case 'C':  //traslada objeto hacia abajo en y neg
		transY -= 0.2f;
		break;


	case 27:  //Si presiona tecla ESC (ASCII 27) sale
		exit(0);
		break;

	default:  //Si es cualquier otra tecla no hace nada
		break;
	}

	glutPostRedisplay();
}


void teclasFlechas(int tecla, int x, int y)  // Funcion para manejo de teclas especiales (arrow keys)
{
	switch (tecla) {
	case GLUT_KEY_UP:  //gira sobre x sentido antihorario, valor positivo
		angleX += 2.0f;
		break;
	case GLUT_KEY_DOWN:  //gira sobre x sentido horario, valor negativo
		angleX -= 2.0f;
		break;
	case GLUT_KEY_LEFT:  //gira sobre y sentido antihorario, valor positivo
		angleY += 2.0f;
		break;
	case GLUT_KEY_RIGHT:  //gira sobre y sentido horario, valor negativo
		angleY -= 2.0f;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}


int main(int argc, char *argv[])
{
	//inicializa GLUT con el sistema de ventanas pasando los argumentos del main
	glutInit(&argc, argv);

	//Buffer simple para dibujar
	//Colores RGB y alpha
	//Buffer de profundidad
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH);

	//Define ventana de 500 pixeles de ancho por 500 de alto
	glutInitWindowSize(600, 600);

	//Posiciona la ventana de izquierda a derecha 50 pixeles y de arriba a abajo 25
	glutInitWindowPosition(400, 100);

	//Crea y abre la ventana y recibe el nombre que va en su barra de título
	glutCreateWindow("Práctica 8 - Texturas");

	//Llamada a función propia para inicializar estados de opengl
	inicializar();

	//Llamada a la función a ser dibujada y redibujada
	glutDisplayFunc(dibujar);

	glutReshapeFunc(remodelar);

	//Lamada a función que maneja eventos del teclado
	glutKeyboardFunc(teclado);

	glutSpecialFunc(teclasFlechas);

	//Llamada a función que cede el control a GLUT y procesa eventos de ventana, ratón
	glutMainLoop();

	//termina la ejecución devolviendo cero
	return 0;
}
