#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include <stdio.h>


#define pi 3.14159265

const double SCREEN_WIDTH = 600.0;	//화면의 크기가 될 window size를 정의
const double SCREEN_HEIGHT = 600.0;

GLfloat theta = -60;	//최소 각도를 60도로 설정한다
GLfloat max = 60;	//최대 올릴 수 있는 각도를 60도로 한다.
GLfloat min = -60;	//최소로 내릴 수 있는 각도를 -60도로 설정한다.

GLfloat flag = 1;	//위로 갈 경우 1, 아래로 갈 경우 0으로 설정

void DrawHead(float cx, float cy, float r)	//머리를 그리는 함수를 생성함
{
	float x1, y1, x2, y2;
	float angle;
	double radius = r;


	x1 = cx, y1 = cy;
	glColor3f(0.5, 0.5, 0.5);

	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x1, y1);

	for (angle = 0.01f; angle <= 2 * 3.14f + 0.2; angle += 0.2)	//삼각형을 방향을 전환하며 돌리며 원의 모습을 그림
	{
		x2 = x1 - sin(angle)*radius;
		y2 = y1 + cos(angle)*radius;

		glVertex2f(x2, y2);
	}

	glEnd();

}

void DrawBody() {	//몸을 그리는 함수
	glBegin(GL_POLYGON);

	glColor3f(0.6f, 0.6f, 0.6f);

	glVertex3f(-0.13, 0.13, 0.0);
	glVertex3f(-0.13, -0.26, 0.0);
	glVertex3f(0.13, -0.26, 0.0);
	glVertex3f(0.13, 0.13, 0.0);

	glEnd();
}

void DrawLeftUpperArm() {	//왼쪽 위 팔을 그리는 함수
	glBegin(GL_POLYGON);
	glColor3f(0.5f, 0.5f, 0.5f);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(-0.13, 0.0, 0.0);
	glVertex3f(-0.13, -0.26, 0.0);
	glVertex3f(0.0, -0.26, 0.0);

	glEnd();

}

void DrawLeftLowerArm() {	//왼쪽 아래 팔을 그리는 함수
	glBegin(GL_POLYGON);
	glColor3f(0.4f, 0.4f, 0.4f);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.13, 0.0, 0.0);
	glVertex3f(0.13, -0.26, 0.0);
	glVertex3f(0.0, -0.26, 0.0);

	glEnd();
}

void DrawLeftHand() {	//왼쪽 손을 그리는 함수
	glBegin(GL_POLYGON);
	glColor3f(0.3f, 0.3f, 0.3f);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(- 0.13, 0.0, 0.0);
	glVertex3f(- 0.17, - 0.12, 0.0);
	glVertex3f(- 0.065, -0.2, 0.0);
	glVertex3f(0.04, -0.12, 0.0);

	glEnd();

}


void DrawRightUpperArm() {	//오른쪽 위 팔을 그리는 함수
	glBegin(GL_POLYGON);
	glColor3f(0.5f, 0.5f, 0.5f);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.13, 0.0, 0.0);
	glVertex3f(0.13, -0.26, 0.0);
	glVertex3f(0.0, -0.26, 0.0);

	glEnd();

}

void DrawRightLowerArm() {	//오른쪽 아래 팔을 그리는 함수
	glBegin(GL_POLYGON);
	glColor3f(0.4f, 0.4f, 0.4f);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(-0.13, 0.0, 0.0);
	glVertex3f(-0.13, -0.26, 0.0);
	glVertex3f(0.0, -0.26, 0.0);

	glEnd();
}

void DrawRightHand() {	//오른쪽 손을 그리는 함수
	glBegin(GL_POLYGON);
	glColor3f(0.3f, 0.3f, 0.3f);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.13, 0.0, 0.0);
	glVertex3f(0.17, -0.12, 0.0);
	glVertex3f(0.065, -0.2, 0.0);
	glVertex3f(-0.04, -0.12, 0.0);

	glEnd();
}
void GoToLeftShoulderCoordinates()	//왼쪽 어깨의 죄표를 설정하는 함수
{
	glTranslatef(-0.13, 0.13, 0.0);
	glRotatef(-1 * theta, 0.0, 0.0, 1.0);	//팔을 올릴때 자연스럽게 돌아가도록 설정
}

void GoToRightShoulderCoordinates()	//오른쪽 어깨의 죄표를 설정하는 함수
{
	glTranslatef(0.13, 0.13, 0.0);
	glRotatef(theta, 0.0, 0.0, 1.0);	//팔을 올릴때 자연스럽게 돌아가도록 설정
}
void GoToLeftElbowCoordinates()	//왼쪽 팔꿈치의 죄표를 설정하는 함수
{
	glTranslatef(-0.13, -0.26, 0.0);
	glRotatef(-1 * theta, 0.0, 0.0, 1.0);	//팔을 올릴때 자연스럽게 돌아가도록 설정
}

void GoToRightElbowCoordinates()	//오른쪽 팔꿈치의 죄표를 설정하는 함수
{
	glTranslatef(0.13, -0.26, 0.0);
	glRotatef(theta, 0.0, 0.0, 1.0);	//팔을 올릴때 자연스럽게 돌아가도록 설정
}
void GoToLeftWristCoordinates()	//왼쪽 손목의 죄표를 설정하는 함수
{
	glTranslatef(0.13, -0.26, 0.0);
}

void GoToRightWristCoordinates()	//오른쪽 손목의 죄표를 설정하는 함수
{
	glTranslatef(-0.13, -0.26, 0.0);
}

void moveArms() {	//시간에 변함에 따라 각도를 바꾸어 자연스럽게 팔 모양이 나오도록 설정
	if (theta <= max && flag == 1)
		theta++;
	else if (theta > max)	//최대 각도에 닿았을 경우 방향을 아래로 바꾼다
		flag = 0;
	
	if (theta >= min && flag == 0)
		theta--;
	else if (theta < min)	//최소 각도에 닿았을 경우 방향을 위로 바꾼다
		flag = 1;
}


void DrawLArm() {	//왼팔을 그리는 함수를 생성
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	DrawBody();
	glPushMatrix();

	GoToLeftShoulderCoordinates();
	DrawLeftUpperArm();
	glPushMatrix();

	GoToLeftElbowCoordinates();
	DrawLeftLowerArm();
	glPushMatrix();

	GoToLeftWristCoordinates();
	DrawLeftHand();

	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}

void DrawRArm() {	//오른팔을 그리는 함수를 생성
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	DrawBody();
	glPushMatrix();

	GoToRightShoulderCoordinates();
	DrawRightUpperArm();
	glPushMatrix();

	GoToRightElbowCoordinates();
	DrawRightLowerArm();
	glPushMatrix();

	GoToRightWristCoordinates();
	DrawRightHand();

	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

}

void DrawRobot() {	//로봇의 전체 형태를 출력하는 함수 호출
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	DrawBody();
	glPushMatrix();
	DrawHead(0.0, 0.26, 0.13);
	glPushMatrix();
	DrawLArm();
	DrawRArm();

}

void MyTimer(int value) {	//시간에 따른 이벤트 발생
	glutPostRedisplay();	//디스플레이 이벤트 발생
	glutTimerFunc(10, MyTimer, 1);
}

void MyDisplay() {	//디스플레이에 띄우는 함수
	glClear(GL_COLOR_BUFFER_BIT);
	moveArms();
	DrawRobot();
	glEnd();
	glutSwapBuffers();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutInitWindowPosition(200, 0);
	glutCreateWindow("OpenGL Drawing Example");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0);
	glutDisplayFunc(MyDisplay);
	glutTimerFunc(40, MyTimer, 1);
	glutMainLoop();
	return 0;
}
