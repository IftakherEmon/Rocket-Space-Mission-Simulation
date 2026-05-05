#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;


// Global Variables for Scene Control

int currentScene = 1;  // 1 = Launch Scene, 2 = Space Separation Scene, 3 = Moon Landing Scene

// Scene 1: Rocket Launch

float rocketY = 0;
string launchText = "Rocket is Launching...";
bool launchComplete = false;

void displayLaunchText() {
    glColor3f(0.0f, 0.0f, 0.0f);
    glRasterPos2f(20, 680);
    for(int i = 0; i < (int)launchText.length(); i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, launchText[i]);
    }
}

void f1rocket_tail() {
    glBegin(GL_POLYGON);
        glColor3ub(255, 150, 0);
        glVertex2f(535, 170);
        glVertex2f(565, 170);
        glColor3ub(255, 0, 0);
        glVertex2f(550, 135);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(255, 255, 255);
        glVertex2f(542, 170);
        glVertex2f(558, 170);
        glColor3ub(255, 255, 0);
        glVertex2f(550, 150);
    glEnd();

    glColor3ub(165, 175, 170);
    glBegin(GL_POLYGON);
        glVertex2f(530, 170);
        glVertex2f(535, 175);
        glVertex2f(565, 175);
        glVertex2f(570, 170);
    glEnd();
    glLineWidth(1); glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
        glVertex2f(530, 170);
        glVertex2f(535, 175);
        glVertex2f(565, 175);
        glVertex2f(570, 170);
    glEnd();

    glColor3ub(165, 175, 170);
    glBegin(GL_POLYGON);
        glVertex2f(535, 175);
        glVertex2f(535, 180);
        glVertex2f(565, 180);
        glVertex2f(565, 175);
    glEnd();
    glLineWidth(1); glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(535, 175);
        glVertex2f(535, 180);
        glVertex2f(565, 180);
        glVertex2f(565, 175);
    glEnd();

    glColor3ub(165, 175, 170);
    glBegin(GL_POLYGON);
        glVertex2f(535, 180);
        glVertex2f(540, 200);
        glVertex2f(560, 200);
        glVertex2f(565, 180);
    glEnd();
    glLineWidth(1); glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(535, 180);
        glVertex2f(540, 200);
        glVertex2f(560, 200);
        glVertex2f(565, 180);
    glEnd();
}

void f1rocket_bottom_mid() {
    glColor3ub(165, 175, 170);
    glBegin(GL_POLYGON);
        glVertex2f(540, 200);
        glVertex2f(535, 210);
        glVertex2f(565, 210);
        glVertex2f(560, 200);
    glEnd();
    glLineWidth(1); glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(540, 200);
        glVertex2f(535, 210);
        glVertex2f(565, 210);
        glVertex2f(560, 200);
    glEnd();

    glColor3ub(165, 175, 170);
    glBegin(GL_POLYGON);
        glVertex2f(535, 210);
        glVertex2f(535, 250);
        glVertex2f(565, 250);
        glVertex2f(565, 210);
    glEnd();
    glLineWidth(1); glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(535, 210);
        glVertex2f(535, 250);
        glVertex2f(565, 250);
        glVertex2f(565, 210);
    glEnd();
}

void f1rocket_top_mid() {
    glColor3ub(165, 175, 170);
    glBegin(GL_POLYGON);
        glVertex2f(535, 250);
        glVertex2f(530, 265);
        glVertex2f(570, 265);
        glVertex2f(565, 250);
    glEnd();
    glLineWidth(1); glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(535, 250);
        glVertex2f(530, 265);
        glVertex2f(570, 265);
        glVertex2f(565, 250);
    glEnd();

    glColor3ub(165, 175, 170);
    glBegin(GL_POLYGON);
        glVertex2f(530, 265);
        glVertex2f(530, 325);
        glVertex2f(570, 325);
        glVertex2f(570, 265);
    glEnd();
    glLineWidth(1); glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(530, 265);
        glVertex2f(530, 325);
        glVertex2f(570, 325);
        glVertex2f(570, 265);
    glEnd();

    glColor3ub(165, 175, 170);
    glBegin(GL_POLYGON);
        glVertex2f(530, 325);
        glVertex2f(525, 335);
        glVertex2f(575, 335);
        glVertex2f(570, 325);
    glEnd();
    glLineWidth(1); glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(530, 325);
        glVertex2f(525, 335);
        glVertex2f(575, 335);
        glVertex2f(570, 325);
    glEnd();
}

void f1rocket_top() {
    glColor3ub(165, 175, 170);
    glBegin(GL_POLYGON);
        glVertex2f(525, 335);
        glVertex2f(530, 350);
        glVertex2f(570, 350);
        glVertex2f(575, 335);
    glEnd();
    glLineWidth(1); glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(525, 335);
        glVertex2f(530, 350);
        glVertex2f(570, 350);
        glVertex2f(575, 335);
    glEnd();

    glColor3ub(165, 175, 170);
    glBegin(GL_POLYGON);
        glVertex2f(530, 350);
        glVertex2f(530, 370);
        glVertex2f(570, 370);
        glVertex2f(570, 350);
    glEnd();
    glLineWidth(1); glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(530, 350);
        glVertex2f(530, 370);
        glVertex2f(570, 370);
        glVertex2f(570, 350);
    glEnd();

    glColor3ub(165, 175, 170);
    glBegin(GL_POLYGON);
        glVertex2f(515, 370);
        glVertex2f(530, 390);
        glVertex2f(570, 390);
        glVertex2f(585, 370);
    glEnd();
    glLineWidth(1); glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(515, 370);
        glVertex2f(530, 390);
        glVertex2f(570, 390);
        glVertex2f(585, 370);
    glEnd();

    glColor3ub(165, 175, 170);
    glBegin(GL_POLYGON);
        glVertex2f(530, 390);
        glVertex2f(530, 410);
        glVertex2f(570, 410);
        glVertex2f(570, 390);
    glEnd();
    glLineWidth(1); glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(530, 390);
        glVertex2f(530, 410);
        glVertex2f(570, 410);
        glVertex2f(570, 390);
    glEnd();

    glColor3ub(165, 175, 170);
    glBegin(GL_POLYGON);
        glVertex2f(530, 410);
        glVertex2f(550, 450);
        glVertex2f(570, 410);
    glEnd();
    glLineWidth(1); glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(530, 410);
        glVertex2f(550, 450);
        glVertex2f(570, 410);
    glEnd();
}

void f1wing1() {
    glColor3ub(165, 175, 170);
    glBegin(GL_POLYGON);
        glVertex2f(520, 275);
        glVertex2f(520, 285);
        glVertex2f(520, 290);
        glVertex2f(520, 275);
    glEnd();
    glLineWidth(1); glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(520, 275);
        glVertex2f(520, 285);
        glVertex2f(520, 290);
        glVertex2f(520, 275);
    glEnd();

    glColor3ub(165, 175, 170);
    glBegin(GL_POLYGON);
        glVertex2f(520, 285);
        glVertex2f(520, 310);
        glVertex2f(530, 325);
        glVertex2f(530, 295);
    glEnd();
    glLineWidth(1); glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(520, 285);
        glVertex2f(520, 310);
        glVertex2f(530, 325);
        glVertex2f(530, 295);
    glEnd();
}

void f1wing2() {
    glColor3ub(165, 175, 170);
    glBegin(GL_POLYGON);
        glVertex2f(570, 290);
        glVertex2f(570, 325);
        glVertex2f(580, 315);
        glVertex2f(580, 285);
    glEnd();
    glLineWidth(1); glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(570, 290);
        glVertex2f(570, 325);
        glVertex2f(580, 315);
        glVertex2f(580, 285);
    glEnd();

    glColor3ub(165, 175, 170);
    glBegin(GL_POLYGON);
        glVertex2f(580, 275);
        glVertex2f(580, 285);
        glVertex2f(580, 285);
        glVertex2f(580, 275);
    glEnd();
    glLineWidth(1); glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(580, 275);
        glVertex2f(580, 285);
        glVertex2f(580, 285);
        glVertex2f(580, 275);
    glEnd();
}

void f1Rocket() {
    f1rocket_tail();
    f1rocket_bottom_mid();
    f1rocket_top_mid();
    f1rocket_top();
    f1wing1();
    f1wing2();
}

void f1backGround() {
    glBegin(GL_POLYGON);
    glColor3ub(250, 213, 165);
    glVertex2f(0, 0);
    glVertex2f(0, 720);
    glVertex2f(1100, 720);
    glVertex2f(1100, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(135, 206, 235);
    glVertex2f(0, 720);
    glVertex2f(1100, 720);
    glVertex2f(1100, 500);
    glVertex2f(0, 500);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(77, 179, 204);
    glVertex2f(0, 0);
    glVertex2f(0, 100);
    glVertex2f(1100, 100);
    glVertex2f(1100, 0);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2f(0, 95);
    glVertex2f(1100, 95);
    glVertex2f(1100, 100);
    glVertex2f(0, 100);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(70, 70, 70);
    glVertex2f(0, 150);
    glVertex2f(1100, 150);
    glVertex2f(1100, 100);
    glVertex2f(0, 100);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(128, 128, 128);
    glVertex2f(100, 150);
    glVertex2f(200, 400);
    glVertex2f(300, 150);
    glVertex2f(300, 150);
    glVertex2f(400, 400);
    glVertex2f(500, 150);
    glVertex2f(700, 150);
    glVertex2f(800, 400);
    glVertex2f(900, 150);
    glVertex2f(900, 150);
    glVertex2f(1000, 400);
    glVertex2f(1100, 150);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(50, 50, 50);
    glVertex2f(0, 150);
    glVertex2f(100, 400);
    glVertex2f(200, 150);
    glVertex2f(200, 150);
    glVertex2f(300, 400);
    glVertex2f(400, 150);
    glVertex2f(600, 150);
    glVertex2f(700, 400);
    glVertex2f(800, 150);
    glVertex2f(800, 150);
    glVertex2f(900, 400);
    glVertex2f(1000, 150);
    glEnd();
}

void f1RocketStand() {
    glBegin(GL_POLYGON);
    glColor3ub(100, 100, 100);
    glVertex2f(500, 150);
    glVertex2f(520, 150);
    glVertex2f(520, 285);
    glVertex2f(500, 285);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(100, 100, 100);
    glVertex2f(580, 150);
    glVertex2f(600, 150);
    glVertex2f(600, 285);
    glVertex2f(580, 285);
    glEnd();
}

void f1RocketSmoke() {
    if (rocketY > 5) {
        glBegin(GL_POLYGON);
            glColor3ub(80, 80, 80);
            glVertex2f(540, 150);
            glVertex2f(560, 150);
            glColor3ub(180, 180, 180);
            glVertex2f(580, 150  -rocketY);
            glVertex2f(520, 150  -rocketY);
        glEnd();
    }
}

void updateScene1(int value) {
    if (currentScene == 1) {
        rocketY += 2.0f;
        if (rocketY > 720) {
            launchText = "Rocket is Launched Successfully!";
            launchComplete = true;
        }
        glutPostRedisplay();
    }
    glutTimerFunc(30, updateScene1, 0);
}

void displayScene1() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 1100, 0, 720);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClear(GL_COLOR_BUFFER_BIT);
    f1backGround();

    glPushMatrix();
    glTranslatef(0, rocketY, 0);
    f1Rocket();
    f1RocketSmoke();
    glPopMatrix();

    f1RocketStand();
    displayLaunchText();
    glutSwapBuffers();
}

// Scene 2: Rocket Separation in Space


void rocket_tail() {
    float r = 0.63f, g = 0.69f, b = 0.63f;

    glColor3f(r, g, b);
    glBegin(GL_QUADS);
        glVertex2f(-0.95f, 0.22f);
        glVertex2f(-0.83f, 0.22f);
        glVertex2f(-0.83f, -0.22f);
        glVertex2f(-0.95f, -0.22f);
    glEnd();
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
        glVertex2f(-0.95f, 0.22f);
        glVertex2f(-0.83f, 0.22f);

        glVertex2f(-0.83f, 0.22f);
        glVertex2f(-0.83f, -0.22f);

        glVertex2f(-0.83f, -0.22f);
        glVertex2f(-0.95f, -0.22f);

        glVertex2f(-0.95f, -0.22f);
        glVertex2f(-0.95f, 0.22f);
    glEnd();

    glColor3f(r, g, b);
    glBegin(GL_QUADS);
        glVertex2f(-0.83f, 0.15f);
        glVertex2f(-0.78f, 0.15f);
        glVertex2f(-0.78f, -0.15f);
        glVertex2f(-0.83f, -0.15f);
    glEnd();
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
        glVertex2f(-0.83f, 0.15f);
        glVertex2f(-0.78f, 0.15f);

        glVertex2f(-0.78f, 0.15f);
        glVertex2f(-0.78f, -0.15f);

        glVertex2f(-0.78f, -0.15f);
        glVertex2f(-0.83f, -0.15f);

        glVertex2f(-0.83f, -0.15f);
        glVertex2f(-0.83f, 0.15f);
    glEnd();

    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
        glVertex2f(-0.78f, 0.15f);
        glVertex2f(-0.62f, 0.22f);
        glVertex2f(-0.62f, -0.22f);
        glVertex2f(-0.78f, -0.15f);
    glEnd();
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
        glVertex2f(-0.78f, 0.15f);
        glVertex2f(-0.62f, 0.22f);

        glVertex2f(-0.62f, 0.22f);
        glVertex2f(-0.62f, -0.22f);

        glVertex2f(-0.62f, -0.22f);
        glVertex2f(-0.78f, -0.15f);

        glVertex2f(-0.78f, -0.15f);
        glVertex2f(-0.78f, 0.15f);
    glEnd();
}

void rocket_bottom_mid() {
    float r = 0.63f, g = 0.69f, b = 0.63f;

    glColor3f(0.4f, 0.4f, 0.4f);
    glBegin(GL_QUADS);
        glVertex2f(-0.62f, 0.28f);
        glVertex2f(-0.35f, 0.28f);
        glVertex2f(-0.35f, 0.22f);
        glVertex2f(-0.62f, 0.22f);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2f(-0.62f, -0.28f);
        glVertex2f(-0.35f, -0.28f);
        glVertex2f(-0.35f, -0.22f);
        glVertex2f(-0.62f, -0.22f);
    glEnd();

    glColor3f(r, g, b);
    glBegin(GL_QUADS);
        glVertex2f(-0.62f, 0.22f);
        glVertex2f(-0.35f, 0.22f);
        glVertex2f(-0.35f, -0.22f);
        glVertex2f(-0.62f, -0.22f);
    glEnd();
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
        glVertex2f(-0.62f, 0.28f);
        glVertex2f(-0.35f, 0.28f);

        glVertex2f(-0.35f, 0.28f);
        glVertex2f(-0.35f, -0.28f);

        glVertex2f(-0.35f, -0.28f);
        glVertex2f(-0.62f, -0.28f);

        glVertex2f(-0.62f, -0.28f);
        glVertex2f(-0.62f, 0.28f);
    glEnd();

    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
        glVertex2f(-0.35f, 0.22f);
        glVertex2f(-0.25f, 0.30f);
        glVertex2f(-0.25f, -0.30f);
        glVertex2f(-0.35f, -0.22f);
    glEnd();
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
        glVertex2f(-0.35f, 0.22f);
        glVertex2f(-0.25f, 0.30f);

        glVertex2f(-0.25f, 0.30f);
        glVertex2f(-0.25f, -0.30f);

        glVertex2f(-0.25f, -0.30f);
        glVertex2f(-0.35f, -0.22f);

        glVertex2f(-0.35f, -0.22f);
        glVertex2f(-0.35f, 0.22f);
    glEnd();
}

void rocket_top_mid() {
    float r = 0.63f, g = 0.69f, b = 0.63f;

    glColor3f(r, g, b);
    glBegin(GL_QUADS);
        glVertex2f(-0.25f, 0.30f);
        glVertex2f(0.10f, 0.30f);
        glVertex2f(0.10f, -0.30f);
        glVertex2f(-0.25f, -0.30f);
    glEnd();
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
        glVertex2f(-0.25f, 0.30f);
        glVertex2f(0.10f, 0.30f);

        glVertex2f(0.10f, 0.30f);
        glVertex2f(0.10f, -0.30f);

        glVertex2f(0.10f, -0.30f);
        glVertex2f(-0.25f, -0.30f);

        glVertex2f(-0.25f, -0.30f);
        glVertex2f(-0.25f, 0.30f);
    glEnd();

    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
        glVertex2f(0.10f, 0.30f);
        glVertex2f(0.20f, 0.40f);
        glVertex2f(0.20f, -0.40f);
        glVertex2f(0.10f, -0.30f);
    glEnd();
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
        glVertex2f(0.10f, 0.30f);
        glVertex2f(0.20f, 0.40f);

        glVertex2f(0.20f, 0.40f);
        glVertex2f(0.20f, -0.40f);

        glVertex2f(0.20f, -0.40f);
        glVertex2f(0.10f, -0.30f);

        glVertex2f(0.10f, -0.30f);
        glVertex2f(0.10f, 0.30f);
    glEnd();

    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
        glVertex2f(0.20f, 0.40f);
        glVertex2f(0.30f, 0.30f);
        glVertex2f(0.30f, -0.30f);
        glVertex2f(0.20f, -0.40f);
    glEnd();
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
        glVertex2f(0.20f, 0.40f);
        glVertex2f(0.30f, 0.30f);

        glVertex2f(0.30f, 0.30f);
        glVertex2f(0.30f, -0.30f);

        glVertex2f(0.30f, -0.30f);
        glVertex2f(0.20f, -0.40f);

        glVertex2f(0.20f, -0.40f);
        glVertex2f(0.20f, 0.40f);
    glEnd();
}

void rocket_top() {
    float r = 0.63f, g = 0.69f, b = 0.63f;

    glColor3f(r, g, b);
    glBegin(GL_QUADS);
        glVertex2f(0.30f, 0.30f);
        glVertex2f(0.60f, 0.30f);
        glVertex2f(0.60f, -0.30f);
        glVertex2f(0.30f, -0.30f);
    glEnd();
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
        glVertex2f(0.30f, 0.30f);
        glVertex2f(0.60f, 0.30f);

        glVertex2f(0.60f, 0.30f);
        glVertex2f(0.60f, -0.30f);

        glVertex2f(0.60f, -0.30f);
        glVertex2f(0.30f, -0.30f);

        glVertex2f(0.30f, -0.30f);
        glVertex2f(0.30f, 0.30f);
    glEnd();

    glColor3f(r, g, b);
    glBegin(GL_TRIANGLES);
        glVertex2f(0.35f, 0.30f);
        glVertex2f(0.35f, 0.55f);
        glVertex2f(0.55f, 0.30f);
    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex2f(0.35f, -0.30f);
        glVertex2f(0.35f, -0.55f);
        glVertex2f(0.55f, -0.30f);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
        glVertex2f(0.35f, 0.30f);
        glVertex2f(0.35f, 0.55f);

        glVertex2f(0.35f, 0.55f);
        glVertex2f(0.55f, 0.30f);

        glVertex2f(0.55f, 0.30f);
        glVertex2f(0.35f, 0.30f);
    glEnd();

    glBegin(GL_LINES);
        glVertex2f(0.35f, -0.30f);
        glVertex2f(0.35f, -0.55f);

        glVertex2f(0.35f, -0.55f);
        glVertex2f(0.55f, -0.30f);

        glVertex2f(0.55f, -0.30f);
        glVertex2f(0.35f, -0.30f);
    glEnd();

    glColor3f(r, g, b);
    glBegin(GL_TRIANGLES);
        glVertex2f(0.60f, 0.30f);
        glVertex2f(0.85f, 0.00f);
        glVertex2f(0.60f, -0.30f);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
        glVertex2f(0.60f, 0.30f);
        glVertex2f(0.85f, 0.00f);

        glVertex2f(0.85f, 0.00f);
        glVertex2f(0.60f, -0.30f);

        glVertex2f(0.60f, -0.30f);
        glVertex2f(0.60f, 0.30f);
    glEnd();

    glColor3f(0.75f, 0.78f, 0.95f);
    glBegin(GL_POLYGON);
    for(int i = 0; i < 100; i++) {
        float angle = (i * 2 * 3.1416f) / 100;
        glVertex2f(0.11f * cos(angle) + 0.68f, 0.11f * sin(angle));
    }
    glEnd();
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    for(int i = 0; i < 100; i++) {
        float angle = (i * 2 * 3.1416f) / 100;
        glVertex2f(0.11f * cos(angle) + 0.68f, 0.11f * sin(angle));
    }
    glEnd();
}

void wing1() {
    float r = 0.63f, g = 0.69f, b = 0.63f;

    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
        glVertex2f(-0.15f, 0.30f);
        glVertex2f(-0.20f, 0.40f);
        glVertex2f(-0.05f, 0.40f);
        glVertex2f(0.10f, 0.30f);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
        glVertex2f(-0.15f, 0.30f);
        glVertex2f(-0.20f, 0.40f);

        glVertex2f(-0.20f, 0.40f);
        glVertex2f(-0.05f, 0.40f);

        glVertex2f(-0.05f, 0.40f);
        glVertex2f(0.10f, 0.30f);

        glVertex2f(0.10f, 0.30f);
        glVertex2f(-0.15f, 0.30f);
    glEnd();
}

void wing2() {
    float r = 0.63f, g = 0.69f, b = 0.63f;

    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
        glVertex2f(-0.15f, -0.30f);
        glVertex2f(-0.20f, -0.40f);
        glVertex2f(-0.05f, -0.40f);
        glVertex2f(0.10f, -0.30f);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
        glVertex2f(-0.15f, -0.30f);
        glVertex2f(-0.20f, -0.40f);

        glVertex2f(-0.20f, -0.40f);
        glVertex2f(-0.05f, -0.40f);

        glVertex2f(-0.05f, -0.40f);
        glVertex2f(0.10f, -0.30f);

        glVertex2f(0.10f, -0.30f);
        glVertex2f(-0.15f, -0.30f);
    glEnd();
}

// Scene 2 Animation Variables
float togetherMove = -2.0f;
float tailOffset = 0.0f;
float bottomMidOffset = 0.0f;
float topMidOffset = 0.0f;
float wing1Offset = 0.0f;
float wing2Offset = 0.0f;
float topOffset = 0.0f;
int step = 0;

string scene2Messages[7] = {
    "Rocket Approaching...",
    "Stage 1: Engine Nozzle Separating",
    "Stage 2: Cargo Section Detaching",
    "Stage 3: Wings Detaching",
    "Stage 4: Main Body Breaking Apart",
    "Stage 5: Nose Cone Moving Forward",
    "Mission Accomplished! Capsule Heading to Moon"
};
string scene2Text = scene2Messages[0];

void displayScene2Text() {
    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos2f(-0.9f, 0.85f);
    for(int i = 0; i < (int)scene2Text.length(); i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, scene2Text[i]);
    }
}

void updateScene2(int value) {
    if (currentScene == 2) {
        if(step == 0) {
            togetherMove += 0.008f;
            if(togetherMove >= 0.3f) {
                togetherMove = 0.3f;
                step = 1;
                scene2Text = scene2Messages[1];
            }
        }
        else if(step == 1) {
            tailOffset -= 0.03f;
            if(tailOffset <= -2.0f) {
                step = 2;
                scene2Text = scene2Messages[2];
            }
        }
        else if(step == 2) {
            bottomMidOffset -= 0.03f;
            if(bottomMidOffset <= -1.8f) {
                step = 3;
                scene2Text = scene2Messages[3];
            }
        }
        else if(step == 3) {
            wing1Offset += 0.035f;
            wing2Offset -= 0.035f;
            if(wing1Offset >= 1.5f) {
                step = 4;
                scene2Text = scene2Messages[4];
            }
        }
        else if(step == 4) {
            topMidOffset -= 0.03f;
            if(topMidOffset <= -1.8f) {
                step = 5;
                scene2Text = scene2Messages[5];
            }
        }
        else if(step == 5) {
            topOffset += 0.012f;
            if(topOffset >= 1.2f) {
                scene2Text = scene2Messages[6];
            }
        }
    }
    glutPostRedisplay();
    glutTimerFunc(20, updateScene2, 0);
}

void resetScene2() {
    togetherMove = -2.0f;
    tailOffset = 0.0f;
    bottomMidOffset = 0.0f;
    topMidOffset = 0.0f;
    wing1Offset = 0.0f;
    wing2Offset = 0.0f;
    topOffset = 0.0f;
    step = 0;
    scene2Text = scene2Messages[0];
}

void displayScene2() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.2, 1.2, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(2.0f);
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f);
    for(int i = 0; i < 1000; i++) {
        float x = -1.2f + (rand() % 2400) / 1000.0f;
        float y = -1.0f + (rand() % 2000) / 1000.0f;
        glVertex2f(x, y);
    }
    glEnd();

    glPushMatrix();
    glTranslatef(togetherMove + tailOffset, 0.0f, 0.0f);
    rocket_tail();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(togetherMove + bottomMidOffset, 0.0f, 0.0f);
    rocket_bottom_mid();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(togetherMove + topMidOffset, 0.0f, 0.0f);
    rocket_top_mid();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(togetherMove + topOffset, 0.0f, 0.0f);
    rocket_top();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(togetherMove, wing1Offset, 0.0f);
    wing1();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(togetherMove, wing2Offset, 0.0f);
    wing2();
    glPopMatrix();

    displayScene2Text();
    glFlush();
}

// Scene 3: Moon Landing


struct Star {
    float x, y, size;
    bool visible;
};

const int MAX_STARS = 450;
Star stars[MAX_STARS];

float rocketPosY = 600.0f;
bool landed = false;
bool astronautOut = false;

float manPosX = 480.0f;
float manPosY = 130.0f;
float jumpHeight = 0.0f;
float jumpAngle = 0.0f;
float manDirection = 1.0f;

string moonText = "Rocket is landing to the Moon";
bool moonLandingComplete = false;

void initStars() {
    for (int i = 0; i < MAX_STARS; i++) {
        stars[i].x = rand() % 1080;
        stars[i].y = rand() % 720;
        stars[i].size = (rand() % 3) + 1.0f;
        stars[i].visible = true;
    }
}

void drawStars3() {
    glColor3f(1.0f, 1.0f, 1.0f);
    for (int i = 0; i < MAX_STARS; i++) {
        if (stars[i].visible) {
            glPointSize(stars[i].size);
            glBegin(GL_POINTS);
            glVertex2f(stars[i].x, stars[i].y);
            glEnd();
        }
    }
}

void drawMoonSurface() {
    glColor3f(0.3f, 0.3f, 0.3f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 200; i++) {
        float pi = 3.14159;
        float A = (i * 2 * pi) / 200;
        float r = 1530;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + 550, y - 1400);
    }
    glEnd();
}

void displayMoonText() {
    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos2f(20, 680);
    for(int i = 0; i < (int)moonText.length(); i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, moonText[i]);
    }
}

void f6_p_rocket() {
    glBegin(GL_POLYGON); glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(120, 494); glVertex2f(130, 505); glVertex2f(170, 505); glVertex2f(180, 494);
    glEnd();
    glBegin(GL_LINE_LOOP); glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(120, 494); glVertex2f(130, 505); glVertex2f(170, 505); glVertex2f(180, 494);
    glEnd();

    glBegin(GL_POLYGON); glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(130, 505); glVertex2f(130, 540); glVertex2f(170, 540); glVertex2f(170, 505);
    glEnd();
    glBegin(GL_LINE_LOOP); glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(130, 505); glVertex2f(130, 540); glVertex2f(170, 540); glVertex2f(170, 505);
    glEnd();

    glBegin(GL_POLYGON); glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(100, 540); glVertex2f(135, 560); glVertex2f(165, 560); glVertex2f(200, 540);
    glEnd();
    glBegin(GL_LINE_LOOP); glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(100, 540); glVertex2f(135, 560); glVertex2f(165, 560); glVertex2f(200, 540);
    glEnd();

    glBegin(GL_POLYGON); glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(135, 560); glVertex2f(135, 590); glVertex2f(165, 590); glVertex2f(165, 560);
    glEnd();
    glBegin(GL_LINE_LOOP); glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(135, 560); glVertex2f(135, 590); glVertex2f(165, 590); glVertex2f(165, 560);
    glEnd();

    glBegin(GL_POLYGON); glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(135, 590); glVertex2f(150, 620); glVertex2f(165, 590);
    glEnd();
    glBegin(GL_LINE_LOOP); glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(135, 590); glVertex2f(150, 620); glVertex2f(165, 590);
    glEnd();
}

void drawMan() {
    glPushMatrix();
    glTranslatef(manPosX - 480, (manPosY - 130) + jumpHeight, 0.0f);

    if (manDirection < 0) {
        glTranslatef(480, 0, 0);
        glScalef(-1.0, 1.0, 1.0);
        glTranslatef(-480, 0, 0);
    }

    glBegin(GL_POLYGON); glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(474, 116); glVertex2f(486, 116); glVertex2f(486, 128); glVertex2f(474, 128);
    glEnd();
    glBegin(GL_LINE_LOOP); glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(474, 116); glVertex2f(486, 116); glVertex2f(486, 128); glVertex2f(474, 128);
    glEnd();

    glBegin(GL_POLYGON); glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(468, 86); glVertex2f(492, 86); glVertex2f(492, 116); glVertex2f(468, 116);
    glEnd();
    glBegin(GL_LINE_LOOP); glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(468, 86); glVertex2f(492, 86); glVertex2f(492, 116); glVertex2f(468, 116);
    glEnd();

    glBegin(GL_POLYGON); glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(459, 92); glVertex2f(468, 92); glVertex2f(468, 113); glVertex2f(459, 113);
    glEnd();
    glBegin(GL_LINE_LOOP); glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(459, 92); glVertex2f(468, 92); glVertex2f(468, 113); glVertex2f(459, 113);
    glEnd();

    glBegin(GL_POLYGON); glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(492, 92); glVertex2f(501, 92); glVertex2f(501, 113); glVertex2f(492, 113);
    glEnd();
    glBegin(GL_LINE_LOOP); glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(492, 92); glVertex2f(501, 92); glVertex2f(501, 113); glVertex2f(492, 113);
    glEnd();

    glBegin(GL_POLYGON); glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(469, 56); glVertex2f(479, 56); glVertex2f(479, 86); glVertex2f(469, 86);
    glEnd();
    glBegin(GL_LINE_LOOP); glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(469, 56); glVertex2f(479, 56); glVertex2f(479, 86); glVertex2f(469, 86);
    glEnd();

    glBegin(GL_POLYGON); glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(481, 56); glVertex2f(491, 56); glVertex2f(491, 86); glVertex2f(481, 86);
    glEnd();
    glBegin(GL_LINE_LOOP); glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(481, 56); glVertex2f(491, 56); glVertex2f(491, 86); glVertex2f(481, 86);
    glEnd();

    glPopMatrix();
}

void updateScene3(int value) {
    if (currentScene == 3) {
        // Blink stars
        for (int i = 0; i < MAX_STARS; i++) {
            if (rand() % 100 < 5) {
                stars[i].visible = !stars[i].visible;
            }
        }

        // Rocket descent
        if (!landed) {
            rocketPosY -= 2.0f;
            if (rocketPosY < -364.0f) {
                rocketPosY = -364.0f;
                landed = true;
                moonText = "Rocket has landed Successfully on the Moon! Press 'A' to release Astronaut";
                moonLandingComplete = true;
            }
        }

        // Astronaut movement after landing and when released
        if (landed && astronautOut) {
            jumpAngle += 0.04f;
            jumpHeight = abs(sin(jumpAngle)) * 50.0f;
            manPosX += (1.2f * manDirection);
            if (manPosX > 950.0f) manDirection = -1.0f;
            if (manPosX < 480.0f) manDirection = 1.0f;
        }

        glutPostRedisplay();
    }
    glutTimerFunc(16, updateScene3, 0);
}

void resetScene3() {
    rocketPosY = 600.0f;
    landed = false;
    astronautOut = false;
    manPosX = 480.0f;
    manPosY = 130.0f;
    jumpHeight = 0.0f;
    jumpAngle = 0.0f;
    manDirection = 1.0f;
    moonText = "Rocket is landing to the Moon";
    moonLandingComplete = false;

    for (int i = 0; i < MAX_STARS; i++) {
        stars[i].x = rand() % 1080;
        stars[i].y = rand() % 720;
        stars[i].visible = true;
    }
}

void displayScene3() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 1080, 0, 720);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClearColor(0.0f, 0.0f, 0.05f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    drawStars3();
    drawMoonSurface();

    glPushMatrix();
    glTranslatef(350.0f, rocketPosY, 0.0f);
    f6_p_rocket();
    glPopMatrix();

    if (landed && astronautOut) {
        drawMan();
    }

    displayMoonText();
    glutSwapBuffers();
}

// Main Display Function (Scene Switcher)

void display() {
    switch(currentScene) {
        case 1:
            displayScene1();
            break;
        case 2:
            displayScene2();
            break;
        case 3:
            displayScene3();
            break;
        default:
            displayScene1();
            break;
    }
}


// Keyboard Control

void keyboard(unsigned char key, int x, int y) {
    switch(key) {
        case '1':
            currentScene = 1;
            rocketY = 0;
            launchText = "Rocket is Launching...";
            launchComplete = false;
            glutPostRedisplay();
            break;
        case '2':
            currentScene = 2;
            resetScene2();
            glutPostRedisplay();
            break;
        case '3':
            currentScene = 3;
            resetScene3();
            glutPostRedisplay();
            break;
        case 'a':
        case 'A':
            if (currentScene == 3 && landed && !astronautOut) {
                astronautOut = true;
                moonText = "Astronaut is exploring the Moon!";
            }
            glutPostRedisplay();
            break;
        case 27:
            exit(0);
            break;
    }
}


// Main Function

int main(int argc, char** argv) {
    srand(time(NULL));

    glutInit(&argc, argv);
    glutInitWindowSize(1100, 720);
    glutInitWindowPosition(200, 50);
    glutCreateWindow("Rocket Project");

    initStars();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutTimerFunc(30, updateScene1, 0);
    glutTimerFunc(20, updateScene2, 0);
    glutTimerFunc(16, updateScene3, 0);

    glutMainLoop();
    return 0;
}
