#include "graphics.h"
#include "Quad.h"
#include "circle.h"
#include <iostream>
#include <vector>
#include <cstdlib>     /* srand, rand */
#include <ctime>

using namespace std;

vector<Circle> food;
Quad user;
GLdouble width, height;
int wd;
int points;
int totalPoints;
int state;

bool isOverlapping(Quad& circle) {
    // Get the distance between the center of the user box and the circle
    double dist = sqrt((circle.getCenterX()-user.getCenterX())*(circle.getCenterX()-user.getCenterX()) + (circle.getCenterY()-user.getCenterY())*(circle.getCenterY()-user.getCenterY()));
    // Slightly inaccurate collision model where corners of square are not fully checked but it gets the job done
    return dynamic_cast<Circle&>(circle).getRadius() + (user.getCenterX() - user.getLeftX()) > dist; // Polymorphism!
}

void checkCollisions() {
    for(int i = 0; i < food.size(); i++) {
        if(isOverlapping(food[i])) {
            cout << "Yum!" << endl;
            food.erase(food.begin() + i);
            points++;
        }
    }
}

void drawGame() {
    for(Circle foo : food) {
        foo.draw();
    }
    user.draw();
    checkCollisions();
    glPushMatrix();
    glMatrixMode(GL_PROJECTION); // DO NOT CHANGE THIS LINE
    glLoadIdentity(); // DO NOT CHANGE THIS LINE
    glOrtho(0.0, width, 0.0, height, -1.f, 1.f); // DO NOT CHANGE THIS LINE
    glTranslatef(0, 5, 0);
    glScalef(.1,.1,1);
    glColor3f(0.0f,0.0f,0.0f);
    glutStrokeString(GLUT_STROKE_MONO_ROMAN, (unsigned char*)"Press space to open or close the help menu!");
    glPopMatrix();
}

void drawHelp() {
    glPushMatrix();
    glMatrixMode(GL_PROJECTION); // DO NOT CHANGE THIS LINE
    glLoadIdentity(); // DO NOT CHANGE THIS LINE
    glOrtho(0.0, width, 0.0, height, -1.f, 1.f); // DO NOT CHANGE THIS LINE
    glTranslatef(width/2 - 220, height/2, 0);
    glScalef(.1,.1,1);
    glColor3f(0.0f,0.0f,0.0f);
    glutStrokeString(GLUT_STROKE_MONO_ROMAN, (unsigned char*)"Press space to open or close the help menu!");
    glPopMatrix();
    glPushMatrix();
    glMatrixMode(GL_PROJECTION); // DO NOT CHANGE THIS LINE
    glLoadIdentity(); // DO NOT CHANGE THIS LINE
    glOrtho(0.0, width, 0.0, height, -1.f, 1.f); // DO NOT CHANGE THIS LINE
    glTranslatef(width/2 - 220, height/2 + 100, 0);
    glScalef(.1,.1,1);
    glColor3f(0.0f,0.0f,0.0f);
    glutStrokeString(GLUT_STROKE_MONO_ROMAN, (unsigned char*)"Eat all the dots by crashing into them!!!");
    glPopMatrix();
}

void drawEndScreen() {
    glPushMatrix();
    glMatrixMode(GL_PROJECTION); // DO NOT CHANGE THIS LINE
    glLoadIdentity(); // DO NOT CHANGE THIS LINE
    glOrtho(0.0, width, 0.0, height, -1.f, 1.f); // DO NOT CHANGE THIS LINE
    glTranslatef(width/2 - 100, height/2, 0);
    glScalef(.1,.1,1);
    glColor3f(0.0f,0.0f,0.0f);
    glutStrokeString(GLUT_STROKE_MONO_ROMAN, (unsigned char*)"The game is over!");
    glPopMatrix();
}

void init() {
    width = 600;
    height = 600;
    points = 0;
    totalPoints = 10;
    srand(time(0));
    state = 0;
}

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Black and opaque
    user = Quad({0.0f, 0.0f, 1.0f},{static_cast<int>(width/2), static_cast<int>(height/2)},50,50);
    for(int i = 0; i < totalPoints; i++) {
        int randX = rand()%(570-30)+30;
        int randY = rand()%(570-30)+30;
        food.push_back(Circle({1.00,0.73,0.20},{randX, randY}, 25));
    }
}

/* Handler for window-repaint event. Call back when the window first appears and
 whenever the window needs to be re-painted. */
void display() {
    // Tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height); // DO NOT CHANGE THIS LINE (unless you're on a Mac running Catalina)
    
    // Do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION); // DO NOT CHANGE THIS LINE
    glLoadIdentity(); // DO NOT CHANGE THIS LINE
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f); // DO NOT CHANGE THIS LINE

    // Clear the color buffer with current clearing color
    glClear(GL_COLOR_BUFFER_BIT); // DO NOT CHANGE THIS LINE
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // DO NOT CHANGE THIS LINE
    
    /*
     * Draw here
     */

    if(points != totalPoints && state == 0) {
        drawGame();
    } else if(points == totalPoints) {
        drawEndScreen();
    } else if(state == 1) {
        drawHelp();
    }

    
    glFlush();  // Render now
}

// http://www.theasciicode.com.ar/ascii-control-characters/escape-ascii-code-27.html
void kbd(unsigned char key, int x, int y)
{
    if(key == 103) { // lowercase g to grow
        user.resize(user.getWidth() * 1.3, user.getHeight() * 1.3);
    }

    if(key == 115) { // lowercase s to shrink
        user.resize(user.getWidth()/1.3, user.getHeight()/1.3);
    }

    if(key == 32 && state == 0) {
        state = 1;

        cout << "state to 1" << endl;
    } else if(key == 32 && state == 1) {
        state = 0;

        cout << "state to 0" << endl;
    }

    // escape to exit program
    if (key == 27) {
        glutDestroyWindow(wd);
        exit(0);
    }
    
    glutPostRedisplay();
}

void kbdS(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_DOWN:
            user.move(0,10);
            break;
        case GLUT_KEY_LEFT:
            user.move(-10,0);
            break;
        case GLUT_KEY_RIGHT:
            user.move(10,0);
            break;
        case GLUT_KEY_UP:
            user.move(0,-10);
            break;
    }
    
    glutPostRedisplay();
}

void cursor(int x, int y) {
    user.setCenter({x,y});
    glutPostRedisplay();
}

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
void mouse(int button, int state, int x, int y) {
    
    glutPostRedisplay();
}

void timer(int dummy) {
    
    glutPostRedisplay();
    glutTimerFunc(60, timer, dummy);
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
    
    init();
    
    glutInit(&argc, argv); // Initialize GLUT
    
    glutInitDisplayMode(GLUT_RGBA);
    
    glutInitWindowSize((int)width, (int)height);
    glutInitWindowPosition(0, 0); // Position the window's initial top-left corner
    /* create the window and store the handle to it */
    wd = glutCreateWindow("A Very Hungry Square!" /* title */ );
    
    // Register callback handler for window re-paint event
    glutDisplayFunc(display);
    
    // Our own OpenGL initialization
    initGL();
    
    // register keyboard press event processing function
    // works for numbers, letters, spacebar, etc.
    glutKeyboardFunc(kbd);
    
    // register special event: function keys, arrows, etc.
    glutSpecialFunc(kbdS);
    
    // handles mouse movement
    glutPassiveMotionFunc(cursor);
    
    // handles mouse click
    glutMouseFunc(mouse);
    
    // handles timer
    glutTimerFunc(0, timer, 0);
    
    // Enter the event-processing loop
    glutMainLoop();
    return 0;
}
