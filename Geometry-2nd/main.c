//
//  main.c
//  Geometry-2nd
//
//  Created by C4Q on 6/11/15.
//  Copyright (c) 2015 C4Q. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

#define WINDOW_WIDTH 300
#define WINDOW_HEIGHT 400

int i = 0;
int increment = 1;

static int make_resources(void)
{
    return 1;
}
static void update_fade_factor(void)
{
}
static void render(void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0f, WINDOW_WIDTH, WINDOW_HEIGHT, 0.0f, 0.0f, 1.0f);
    
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    
    glColor3f(0.0f, 0.0f, 1.0f); // Let it be blue.
    glBegin(GL_LINE_STRIP);
    glVertex2i(i, i);
    glVertex2i(i, 200);
    glVertex2i(200, 200);
    glVertex2i(200, i);
    glVertex2i(i, i);
    glEnd();
    
    glColor3f(0.0f, 0.0f, 0.0f); // sets color to black.
    glBegin(GL_TRIANGLE_STRIP); // draw in triangle strips
    glVertex2f(-0.5f, 1.0f); // top of the roof
    glVertex2f(-0.5f, 1.0f); // left corner of the roof
    glVertex2f(0.5f, 0.25f); // right corner of the roof
    glVertex2f(-0.5f, -0.5f); // bottom left corner of the house
    glVertex2f(0.5f, -0.5f); //bottom right corner of the house
    glEnd();
    
    glFlush();
    glutSwapBuffers();
    
    if (i > WINDOW_WIDTH){
        increment = -1;
    }
    else if (i < 0){
        increment = 1;
    }
    
    i = i+increment;
    glutPostRedisplay();
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(WINDOW_HEIGHT, WINDOW_WIDTH);
    glutCreateWindow("Hello World");
    glutDisplayFunc(&render);
    glutIdleFunc(&update_fade_factor);
    
    if (!make_resources()) {
        fprintf(stderr, "Failed to load resources\n");
        return 1;
    }
    
    glutMainLoop();
    
    return 0;
}
