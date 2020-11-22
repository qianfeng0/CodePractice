#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

GLsizei winWidth = 400, winHeight = 400;
GLint regHex;
const double TWO_PI = 6.2831853;

#define CHECK_GL_ERR() \
{\
    for(GLenum err; (err = glGetError()) != GL_NO_ERROR;)\
    {\
        printf("glerror, %d, %s\n", err, gluErrorString(err));\
    }\
}\

class screenPt
{
    private:
        GLint x, y;
    public:
        screenPt() {
            x = y = 0;
        }
        void setCoords(GLint xc, GLint yc) {
            x = xc;
            y = yc;
        }
        GLint getx() const {
            return x;
        }
        GLint gety() const {
            return y;
        }
};

void init()
{
    screenPt hexVertext, circCtr;
    GLdouble theta;
    GLint k;

    circCtr.setCoords(winWidth / 2, winHeight / 2);

    glClearColor(1.0, 1.0, 1.0, 1.0);   // white

    regHex = glGenLists(1);
    glNewList(regHex, GL_COMPILE);
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_POLYGON);
            for (k = 0; k < 6; k++) {
                theta = TWO_PI * k / 6.0;
                hexVertext.setCoords(circCtr.getx() + 150 * cos(theta), circCtr.gety() + 150 * sin(theta));
                glVertex2i(hexVertext.getx(), hexVertext.gety());
            }
        glEnd();
    glEndList();
}

void regHexagon()
{
    printf("regHexagon\n");
    glClear(GL_COLOR_BUFFER_BIT);

    glCallList(regHex);

    glFlush();

    CHECK_GL_ERR();
}

void winReshapeFunc(int newWidth, int newHeight)
{
    printf("winReshapeFunc %d, %d \n", newWidth, newHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble) newWidth, 0.0, (GLdouble)newHeight);

    glClear(GL_COLOR_BUFFER_BIT);
}

int main(int argc, char** argv)
{
    printf("fengqian\n");
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(winWidth, winHeight);
    glutCreateWindow("reshape-Function & Display-List example");

    init();

    glutDisplayFunc(regHexagon);
    glutReshapeFunc(winReshapeFunc);
    glutMainLoop();
    printf("exit\n");
    return 0;
}