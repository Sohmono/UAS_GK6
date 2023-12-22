#include <GL/glut.h>
#include <GL/glu.h>

//atur angle
float angleX = 0.0f;
float angleY = 0.0f;

float carMoveX = 0.0;

//atur posisi utama garasi
float garagePosX = 1.0f;
float garagePosY = 0.0f;
float garagePosZ = 2.0f;

//atur Jeep
float jeepPosX = 0.0f;
float jeepPosY = 0.0f;
float jeepPosZ = 0.0f;


void drawJeep(float carMove) {
    // Badan jeep
    glColor3f(0.8f, 0.5f, 0.2f); // Warna cokelat
    glPushMatrix();
    glTranslatef(carMoveX, 0.0, 0.0);
    glScalef(2.0, 1.0, 1.5);
    glutSolidCube(1.0);
    glPopMatrix();
    
    // Badan depan jeep
    glColor3f(0.8f, 0.5f, 0.2f); // Warna cokelat
    glPushMatrix();
    glTranslatef(carMove+1.0, -0.25, 0.0);
    glScalef(1.2, 0.5, 1.5);
    glutSolidCube(1.0);
    glPopMatrix();

    // Atap jeep
    glColor3f(0.1f, 0.1f, 0.1f); // Warna hitam
    glPushMatrix();
    glTranslatef(carMove+0.0, 0.5, 0.0);
    glScalef(1.5, 0.5, 1.0);
    glutSolidCube(1.0);
    glPopMatrix();

    // Jendela jeep kanan
    glColor3f(0.7f, 0.7f, 0.8f); //warna abu2 biru
    glPushMatrix();
    glTranslatef(carMove+0.0, 0.25, 0.75);
    glScalef(1.49, 0.40, 0.01);
    glutSolidCube(1.0);
    glPopMatrix();
    
    // Jendela jeep kiri
    glColor3f(0.7f, 0.7f, 0.8f); //warna abu2 biru
    glPushMatrix();
    glTranslatef(carMove+0.0, 0.25, -0.75);
    glScalef(1.49, 0.40, 0.01);
    glutSolidCube(1.0);
    glPopMatrix();
    
    // Jendela jeep depan
    glColor3f(0.7f, 0.7f, 0.8f); //warna abu2 biru
    glPushMatrix();
    glTranslatef(carMove+1.0, 0.25, 0.0);
    glScalef(0.01, 0.4, 1.2);
    glutSolidCube(1.0);
    glPopMatrix();
    
    // Jendela jeep belakang
    glColor3f(0.7f, 0.7f, 0.8f); //warna abu2 biru
    glPushMatrix();
    glTranslatef(carMove+(-1.0), 0.25, 0.0);
    glScalef(0.01, 0.4, 1.2);
    glutSolidCube(1.0);
    glPopMatrix();
    
    // Kap jeep depan
    glColor3f(0.1f, 0.1f, 0.1f); //warna hitam
    glPushMatrix();
    glTranslatef(carMove+1.25, 0.0, 0.0);
    glScalef(0.4, 0.01, 1.2);
    glutSolidCube(1.0);
    glPopMatrix();
    
    // Roda belakang
    glColor3f(0.1f, 0.1f, 0.1f); // Warna hitam
    glPushMatrix();
    glTranslatef((carMove+(-1.1)), 0.0, 0.0);
    glRotatef(90.0, 0.0, 1.0, 0.0);
    glutSolidTorus(0.1, 0.2, 20, 25);
    glPopMatrix();

    // Roda kiri belakang
    glColor3f(0.1f, 0.1f, 0.1f); // Warna hitam
    glPushMatrix();
    glTranslatef(carMove+(-0.5), -0.5, 0.75);
    glutSolidTorus(0.1, 0.2, 10, 25);
    glPopMatrix();

    // Roda kanan belakang
    glPushMatrix();
    glTranslatef(carMove+(-0.5), -0.5, -0.75);
    glutSolidTorus(0.1, 0.2, 10, 25);
    glPopMatrix();

    // Roda kiri depan
    glPushMatrix();
    glTranslatef(carMove+1.25, -0.5, 0.75);
    glutSolidTorus(0.1, 0.2, 10, 25);
    glPopMatrix();

    // Roda kanan depan
    glPushMatrix();
    glTranslatef(carMove+1.25, -0.5, -0.75);
    glutSolidTorus(0.1, 0.2, 10, 25);
    glPopMatrix();
}

void drawGarage() {
    // Garasi kiri
    glColor3f(0.4f, 0.4f, 0.4f); // Warna abu-abu untuk garasi
    glPushMatrix();
    glTranslatef(1.0, 0.0, 2.0);
    glScalef(2.0, 3.0, 1.0); // Ukuran garasi
    glutSolidCube(1.0);
    glPopMatrix();

    // Garasi kanan
    glPushMatrix();
    glTranslatef(1.0, 0.0, -2.0);
    glScalef(2.0, 3.0, 1.0); // Ukuran garasi
    glutSolidCube(1.0);
    glPopMatrix();
    
    // Garasi atap
    glPushMatrix();
    glTranslatef(1.0, 2.0, 0.0);
    glScalef(2.0, 1.0, 3.0); // Ukuran garasi
    glutSolidCube(1.0);
    glPopMatrix();
    
     // jalan
    glPushMatrix();
    glColor3f(0.2f, 0.2f, 0.2f); //warna hitam
    glTranslatef(1.0, -1.1, 0.0);
    glScalef(10.0, 0.75, 3.0); // Ukuran jalan
    glutSolidCube(1.0);
    glPopMatrix();
}

//Mobil ke depan
void moveForwardCar() {
    carMoveX += 0.1f; 
}

//mobil mundur
void moveBackwardCar() {
    carMoveX -= 0.1f;
}


//tampilkan semua
void display() {
	glClearColor(1.0, 1.0, 1.0, 1.0);  // Warna latar belakang putih
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 5.0,  // Posisi kamera
              0.0, 0.0, 0.0,  // Titik yang dilihat
              0.0, 1.0, 0.0);  // Vektor atas

    glTranslatef(jeepPosX, jeepPosY, jeepPosZ);
    glRotatef(angleX, 1.0f, 0.0f, 0.0f);
    glRotatef(angleY, 0.0f, 1.0f, 0.0f);

    drawJeep(carMoveX);
    
    glTranslatef(garagePosX, garagePosY, 0.0);
    drawGarage();

    glutSwapBuffers();
}

//Jika ukuran jendela berubah
void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
}

//fungsi keyboard
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'a':
        angleY -= 5.0f;
        break;
    case 'd':
        angleY += 5.0f;
        break;
    case 'w':
        angleX -= 5.0f;
        break;
    case 's':
        angleX += 5.0f;
        break;
    case 'i':
        moveForwardCar();
        break;
    case 'k':
        moveBackwardCar();
        break;
    case 27: // Tombol Esc untuk keluar
        exit(0);
        break;
    }

    glutPostRedisplay();
}

//specialkey
void specialKeys(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_LEFT:
        jeepPosX -= 0.1f;
        break;
    case GLUT_KEY_RIGHT:
        jeepPosX += 0.1f;
        break;
    case GLUT_KEY_UP:
        jeepPosZ += 0.1f;
        break;
    case GLUT_KEY_DOWN:
        jeepPosZ -= 0.1f;
        break;
    }

    glutPostRedisplay();
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("Jeep 3D dengan Keyboard");
    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);

    glutMainLoop();
    return 0;
}

