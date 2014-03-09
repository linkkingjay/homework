#include <GL/glut.h>
#include <math.h>
void Initial(void) {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 200, 0.0, 150.0);
}

void drawBigTriangle(float x, float y, float size) {
    float offset = size / 4 * sqrt(3);
    glBegin(GL_TRIANGLES);
        glVertex2f(x, y + offset);
        glVertex2f(x + size / 2, y - offset);
        glVertex2f(x - size / 2, y - offset);
    glEnd();
}

void draw(float x, float y, float size) {
    if (size < 3) {
        return;
    }

    float offset = size / 4 * sqrt(3);
    glBegin(GL_TRIANGLES);
        glVertex2f(x, y - offset);
        glVertex2f(x + size / 4, y);
        glVertex2f(x - size / 4, y);
    glEnd();


    draw(x, y + offset / 2, size / 2);
    draw(x - size / 4, y - offset / 2, size / 2);
    draw(x + size / 4, y - offset / 2, size / 2);
}

void myDisplay(void) {
    float x = 100;
    float y = 80;
    float size = 150;

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0f, 0.0f, 0.0f);
    drawBigTriangle(x, y, size);

    glColor3f(1.0f, 1.0f, 1.0f);
    draw(x, y, size);
    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(1000, 1000);
    glutCreateWindow("Sierpinski Triangle");
    glutDisplayFunc(&myDisplay);
    Initial();
    glutMainLoop();
    return 0;
}
