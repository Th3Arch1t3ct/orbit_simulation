#include <stdlib.h>
#include <GL/glut.h>
#include <stdio.h>

#define INIT_VIEW_X   0.0
#define INIT_VIEW_Y   0.0
#define INIT_VIEW_Z  -4.5
#define VIEW_LEFT    -2.0
#define VIEW_RIGHT    2.0
#define VIEW_BOTTOM  -2.0
#define VIEW_TOP      2.0
#define VIEW_NEAR     1.0
#define VIEW_FAR    200.0

int fullscreen = 0;

GLfloat AmbientLight[]  = {0.3f, 0.3f, 0.3f, 1.0f};
GLfloat DiffuseLight[]  = {0.8f, 0.8f, 0.8f, 1.0f};
GLfloat SpecularLight[] = {1.0f, 1.0f, 1.0f, 1.0f};
GLfloat SpecRef[]       = {0.7f, 0.7f, 0.7f, 1.0f};
GLfloat LightPos[]      = {-50.0f, 50.0f, 100.0f, 1.0f};
GLubyte Shine           = 128;

void setupRend(){
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glLightfv(GL_LIGHT0, GL_AMBIENT, AmbientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, DiffuseLight);
    glLightfv(GL_LIGHT0, GL_SPECULAR, SpecularLight);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glMaterialfv(GL_FRONT, GL_SPECULAR, SpecRef);
    glMateriali(GL_FRONT, GL_SHININESS, Shine);
}

void Display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();

    // transform and drawing commands go here
    glRotatef(90.0, 1.0, 0.0, 0.0);
    
    glColor3ub(120,120,30);
    glutWireSphere(0.3,20,20);

    glPopMatrix();

    glutSwapBuffers();
}

void ChangeWindow(GLsizei w, GLsizei h){
    GLfloat ratio;
    if(h==0){
        h =1;
    }

    glViewport(0, 0, w, h);
    ratio = (GLfloat)w/(GLfloat)h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0f, ratio, VIEW_NEAR, VIEW_FAR);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(INIT_VIEW_X, INIT_VIEW_Y, INIT_VIEW_Z);
    glLightfv(GL_LIGHT0, GL_POSITION, LightPos);
}

void CheckRot(){
    // Used to keeo angles between 0.0 and 360.0
}

void SpecialKeys(int key, int x, int y){
    if(key == GLUT_KEY_LEFT){

    }

    if(key == GLUT_KEY_RIGHT){
        
    }

    if(key == GLUT_KEY_UP){
        
    }

    if(key == GLUT_KEY_DOWN){
        
    }
    CheckRot();
    glutPostRedisplay();
    
}

void KeyPress(unsigned char key, int x, int y){
    switch(key){
        case 'f':
        case 'F':
            if(fullscreen == 1){
                glutReshapeWindow(320,240);
                glutPositionWindow(5,30);
            } else {
                glutFullScreen();
            }
            fullscreen = 1-fullscreen;
            break;
        case 'Q':
        case 'q':
            exit(1);
            break;
    }
    glutPostRedisplay();
}

void animate(){
    // Motion between frames will be handled here. 
    // this functino is set to run on idle

    glutPostRedisplay();
}

int main(int argc, char* argv[]){
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInit(&argc, argv);
    glutCreateWindow("Orbits!");
    glutReshapeWindow(640,480);
    setupRend();
    glutReshapeFunc(ChangeWindow);
    glutKeyboardFunc(KeyPress);
    glutSpecialFunc(SpecialKeys);
    glutDisplayFunc(Display);
    glutIdleFunc(animate);
    glutMainLoop();

    return EXIT_SUCCESS;
}