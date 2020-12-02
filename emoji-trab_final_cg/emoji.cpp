#include <windows.h>
/* Inclui os headers do OpenGL, GLU, e GLUT */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>

void display();
void reshape(int, int);
void timer(int);

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glEnable(GL_DEPTH_TEST);
};

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowSize(500, 500);
    glutInitWindowPosition(200, 100);

    glutCreateWindow("Emoji");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);
    init();

    glutMainLoop();
};

float angle = 0.0;

void display() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glRotatef(angle, 0.0, 1.0, 0.0); // (Angulo, x, y, z) rodando apenas no eixo y

    // CORPO
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.0); // (tx, ty, tz)
    glColor3f(255.0, 200.0, 0.0);
    glutSolidSphere(1.0, 30, 24);
    glPopMatrix();

    // CHAPEU DE FESTA
    glPushMatrix();
    glColor3f(0.0, 0.0, 102.0);
    glTranslatef(-0.50f, 0.60f, 0.0f);
    glRotatef(-90.0, 6.0, 2.5, -2.0);
    glutSolidCone(0.5, 1.0, 20, 15);
    glPopMatrix();

    // OLHO ESQUERDO BRANCO
    glPushMatrix();
    glColor3f(255.0, 255.0, 255.0);
    glTranslatef(-0.5f, 0.35f, 0.65f);
    glutSolidSphere(0.25f, 20, 20);
    glPopMatrix();

    // OLHO ESQUERDO PRETO
    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(-0.52f, 0.35f, 0.71f);
    glutSolidSphere(0.20f, 20, 20);
    glPopMatrix();

    // OLHO DIREITO BRANCO
    glPushMatrix();
    glColor3f(255.0, 255.0, 255.0);
    glTranslatef(0.5f, 0.35f, 0.65f);
    glutSolidSphere(0.25f, 20, 20);
    glPopMatrix();

    // OLHO DIREIO PRETO
    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(0.52f, 0.35f, 0.71f);
    glutSolidSphere(0.20f, 20, 20);
    glPopMatrix();

    // BOCA
    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(-0.25f, -0.15f, 0.75f);
    glutSolidSphere(0.25f, 30, 25);
    glPopMatrix();

    // LINGUA DE SOGRA PARTE 1
    glPushMatrix();
    glColor3f(0.0, 0.0, 255.0);
    glTranslatef(-0.30f, -0.20f, 1.0f);
    glutSolidCube(0.20f);
    glPopMatrix();

    // LINGUA DE SOGRA PARTE 2
    glPushMatrix();
    glColor3f(0.0, 255.0, 0.0);
    glTranslatef(-0.30f, -0.20f, 1.2f);
    glScalef(1.0, 1.0, 3.0);
    glutSolidCube(0.15f);
    glPopMatrix();

    // LINGUA DE SOGRA PARTE 3
    glPushMatrix();
    glColor3f(255.0, 0.0, 0.0);
    glTranslatef(-0.30f, -0.20f, 1.5f);
    glScalef(1.0, 1.0, 3.0);
    glutSolidCube(0.10f);
    glPopMatrix();

    // LINGUA DE SOGRA PARTE 4
    glPushMatrix();
    glColor3f(255.0, 0.0, 255.0);
    glTranslatef(-0.30f, -0.20f, 1.75f);
    glScalef(1.0, 1.0, 3.0);
    glutSolidCube(0.05f);
    glPopMatrix();

    glFlush();
    glutSwapBuffers();
};

void reshape(int w, int h) {

    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-1.5, 1.5, -1.5 * (GLfloat)h / (GLfloat)w,
            1.5 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);
    else
        glOrtho(-1.5 * (GLfloat)w / (GLfloat)h,
            1.5 * (GLfloat)w / (GLfloat)h, -1.5, 1.5, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

};

void timer(int) {
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, timer, 0);

    angle += 1.0;
    if (angle > 360.0)
        angle = angle - 360.0;
};