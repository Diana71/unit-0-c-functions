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

static int make_resources(void)
{
    return 1;
}
static void update_fade_factor(void)
{
}
static void render(void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    
    glColor3f(0.0f, 0.0f, 1.0f); // Let it be blue
    glBegin(GL_QUADS); // 2x2 pixels
    glVertex2f(1.0f, 1.0f);
    glVertex2f(2.0f, 1.0f);
    glVertex2f(2.0f, 2.0f);
    glVertex2f(1.0f, 2.0f);
    glEnd();
    
    //    Now outline that in yellow keeping the 2x2 blue pixels intact:
    
    glColor3f(1.0f, 1.0f, 0.0f); // Let it be yellow.
    glBegin(GL_LINE_STRIP);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(2.5f, 0.5f);
    glVertex2f(2.5f, 2.5f);
    glVertex2f(0.5f, 2.5f);
    glVertex2f(0.5f, 0.5f);
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
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(400, 300);
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
