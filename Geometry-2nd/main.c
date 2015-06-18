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

static int make_resources(void)
{
    return 1;
}
static void update_fade_factor(void)
{
}

void changeColor(float r, float g, float b) {
    glColor3f(r, g, b);
}

void drawRect(int x, int y, int width, int height) {
    glBegin(GL_LINE_STRIP);
    glVertex2i(x, y); // top left
    glVertex2i(x + width, y); // top right
    glVertex2i(x + width, y + height); // bottom right
    glVertex2i(x, y + height); // bottom left
    glVertex2i(x, y); // top right (close the rect)
    glEnd();
}

static void render(void)
{
    
    // ignore this
    // http://stackoverflow.com/a/2602693
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0f, WINDOW_WIDTH, WINDOW_HEIGHT, 0.0f, 0.0f, 1.0f);
    
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    //
    
    
    /* THIS IS WHERE YOU CODE */
    
     
    changeColor(0.0, 0.0, 1.0); // blue
    drawRect(10, 10, 200, 200);
    
    
    /* ---------------------- */
    
    
    // ignore this
    glFlush();
    glutSwapBuffers();
    //

    // uncomment the following line if you want to continuously loop the `render` function
    // this will make it possible to animate your shapes
    
    // glutPostRedisplay();
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    // IGNORE
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(WINDOW_HEIGHT, WINDOW_WIDTH);
    glutCreateWindow("");
    glutDisplayFunc(&render);
    glutIdleFunc(&update_fade_factor);
    
    if (!make_resources()) {
        fprintf(stderr, "Failed to load resources\n");
        return 1;
    }
    
    glutMainLoop();
    
    return 0;
}
