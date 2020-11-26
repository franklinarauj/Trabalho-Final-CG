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

    GLfloat light_ambient[] = { 255.0, 165.0, 0,0, 1,0 };
    GLfloat light_diffuse[] = { 1.0, 1.0, 0.0, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 75,0 };
    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };

    glClearColor(0.0, 0.0, 0.0, 01.0);
    glShadeModel(GL_SMOOTH);

    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
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

    glTranslatef(0.0, 0.0, 0.0); // (tx, ty, tz)
    glRotatef(angle, 0.0, 1.0, 0.0); // (Angulo, x, y, z) rodando apenas no eixo y

    glColor3f(255.0, 200.0, 0.0);
    glutSolidSphere(1.0, 20, 16);

    glTranslatef(0.0f, 1.0f, 0.0f);
    glutSolidSphere(0.15f, 20, 20);

    glTranslatef(.75, .5, -.75);
    glPushMatrix();                   
    glScalef(1, 3, 1);
    glutSolidCube(.25);
    //glutSolidCone(0.08f, 0.5f, 10, 2);
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

    angle += 0.8;
    if (angle > 360.0)
        angle = angle - 360.0;
};