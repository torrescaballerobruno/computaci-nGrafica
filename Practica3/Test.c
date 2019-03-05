#include<GL/glut.h>
void inicializar(void) {

  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glClearDepth(1.0f);
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}
void prisma(void) {
  GLfloat vertice[8][3] = {
  { 0.5,-0.5,0.5 },
  { -0.5,-0.5,0.5 },
  { -0.5,-0.5,-0.5},
  { 0.5,-0.5,-0.5 },
  { 0.5,0.5,0.5 },
  { 0.5,0.5,-0.5 },
  { -0.5,0.5,-0.5 },
  { -0.5,0.5,0.5 },
  };
  //enfrente
  glBegin(GL_POLYGON);
  glColor3f(0.7, 1.0, 0.1);
  glVertex3fv(vertice[0]);
  glVertex3fv(vertice[4]);
  glVertex3fv(vertice[7]);
  glVertex3fv(vertice[1]);
  glEnd();

  //Derecha
  glBegin(GL_POLYGON);
  glColor3f(1.0, 0.0, 0.0);
  glVertex3fv(vertice[0]);
  glVertex3fv(vertice[3]);
  glVertex3fv(vertice[5]);
  glVertex3fv(vertice[4]);
  glEnd();

  //Atras
  glBegin(GL_POLYGON);
  glColor3f(0.0, 1.0, 0.0);
  glVertex3fv(vertice[6]);
  glVertex3fv(vertice[5]);
  glVertex3fv(vertice[3]);
  glVertex3fv(vertice[2]);
  glEnd();


  glBegin(GL_POLYGON);//izquierda
  glColor3f(1.0, 1.0, 1.0);
  glVertex3fv(vertice[1]);
  glVertex3fv(vertice[7]);
  glVertex3fv(vertice[6]);
  glVertex3fv(vertice[2]);
  glEnd();

  glBegin(GL_POLYGON);//abajo
  glColor3f(0.725, 0.074, 0.117);
  glVertex3fv(vertice[0]);
  glVertex3fv(vertice[1]);
  glVertex3fv(vertice[2]);
  glVertex3fv(vertice[3]);
  glEnd();

  glBegin(GL_POLYGON);//arriba
  glColor3f(0.0, 1.0, 0.0);
  glVertex3fv(vertice[4]);
  glVertex3fv(vertice[5]);
  glVertex3fv(vertice[6]);
  glVertex3fv(vertice[7]);
  glEnd();
}

void dibujar(void) {

  glClearColor(0.035, 0.039, 0.043, 1);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glTranslatef(0.0f, 0.0f, -13.0f);

  glRotatef(-35.0, -1.0, 1.0, 0.0);
  glRotatef(-15.0, 0.0, 1.0, 1.0);
  glRotatef(15.0, 1.0, 0.0, 0.0);
  prisma();
  glTranslatef(2.0f, 0.0f, 0.0f);
  prisma();
  glTranslatef(-3.0f, 0.0f, 0.0f);
  prisma();
  glTranslatef(4.0f, 0.0f, 0.0f);
  prisma();
  glTranslatef(0.0f, 0.0f, 1.0f);
  prisma();
  glTranslatef(-4.0f, 0.0f, 0.0f);
  prisma();
  glTranslatef(3.0f, 1.0f, -1.0f);
  prisma();
  glTranslatef(-2.0f, 0.0f, 0.0f);
  prisma();
  glTranslatef(1.0f, 0.0f, 0.0f);
  prisma();
  glTranslatef(0.0f, 1.0f, 0.0f);
  prisma();
  glTranslatef(-1.0f, 0.0f, 0.0f);
  prisma();
  glTranslatef(2.0f, 0.0f, 0.0f);
  prisma();
  glTranslatef(0.0f, 1.0f, 0.0f);
  prisma();
  glTranslatef(-1.0f, 0.0f, 0.0f);
  prisma();
  glTranslatef(-1.0f, 0.0f, 0.0f);
  prisma();
  glTranslatef(0.0f, 1.0f, 0.0f);
  prisma();
  glTranslatef(1.0f, 0.0f, 0.0f);
  prisma();
  glTranslatef(1.0f, 0.0f, 0.0f);
  prisma();
  glTranslatef(0.0f, 1.0f, 0.0f);
  prisma();
  glTranslatef(-1.0f, 0.0f, 0.0f);
  prisma();
  glTranslatef(-1.0f, 0.0f, 0.0f);
  prisma();
  glTranslatef(0.0f, 0.0f, 1.0f);
  prisma();
  glTranslatef(2.0f, 0.0f, 0.0f);
  prisma();
  glTranslatef(-1.0f, 1.0f, -1.0f);
  prisma();
  glTranslatef(0.0f, 1.0f, 0.0f);
  prisma();
  glTranslatef(0.0f, 1.0f, 0.0f);
  prisma();
  glTranslatef(0.0f, -1.0f, 1.0f);
  prisma();
  glFlush();
}

void remodelar(int width, int height) {
  if (height == 0)
  {
    height = 1;
  }
  glViewport(0, 0, width, height);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  //  glOrtho(-5, 5, -5, 5, 0.1, 20);

  glFrustum(-5, 5, -5, 5, 4, 20.0);
  glutPostRedisplay();
}
void teclado(unsigned char key, int x, int y) {
  if (key == 27)
    exit(0);

  glutPostRedisplay();

}



int main(int argc, char *argv[]) {

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(400, 250);
  glutCreateWindow(argv[1]);
  inicializar();
  glutDisplayFunc(dibujar);
  glutReshapeFunc(remodelar);
  glutKeyboardFunc(teclado);
  glutMainLoop();
  return 0;
}
