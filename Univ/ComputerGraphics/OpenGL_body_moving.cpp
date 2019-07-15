#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include <stdio.h>


#define pi 3.14159265

const double SCREEN_WIDTH = 600.0;	//ȭ���� ũ�Ⱑ �� window size�� ����
const double SCREEN_HEIGHT = 600.0;

GLfloat theta = -60;	//�ּ� ������ 60���� �����Ѵ�
GLfloat max = 60;	//�ִ� �ø� �� �ִ� ������ 60���� �Ѵ�.
GLfloat min = -60;	//�ּҷ� ���� �� �ִ� ������ -60���� �����Ѵ�.

GLfloat flag = 1;	//���� �� ��� 1, �Ʒ��� �� ��� 0���� ����

void DrawHead(float cx, float cy, float r)	//�Ӹ��� �׸��� �Լ��� ������
{
	float x1, y1, x2, y2;
	float angle;
	double radius = r;


	x1 = cx, y1 = cy;
	glColor3f(0.5, 0.5, 0.5);

	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x1, y1);

	for (angle = 0.01f; angle <= 2 * 3.14f + 0.2; angle += 0.2)	//�ﰢ���� ������ ��ȯ�ϸ� ������ ���� ����� �׸�
	{
		x2 = x1 - sin(angle)*radius;
		y2 = y1 + cos(angle)*radius;

		glVertex2f(x2, y2);
	}

	glEnd();

}

void DrawBody() {	//���� �׸��� �Լ�
	glBegin(GL_POLYGON);

	glColor3f(0.6f, 0.6f, 0.6f);

	glVertex3f(-0.13, 0.13, 0.0);
	glVertex3f(-0.13, -0.26, 0.0);
	glVertex3f(0.13, -0.26, 0.0);
	glVertex3f(0.13, 0.13, 0.0);

	glEnd();
}

void DrawLeftUpperArm() {	//���� �� ���� �׸��� �Լ�
	glBegin(GL_POLYGON);
	glColor3f(0.5f, 0.5f, 0.5f);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(-0.13, 0.0, 0.0);
	glVertex3f(-0.13, -0.26, 0.0);
	glVertex3f(0.0, -0.26, 0.0);

	glEnd();

}

void DrawLeftLowerArm() {	//���� �Ʒ� ���� �׸��� �Լ�
	glBegin(GL_POLYGON);
	glColor3f(0.4f, 0.4f, 0.4f);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.13, 0.0, 0.0);
	glVertex3f(0.13, -0.26, 0.0);
	glVertex3f(0.0, -0.26, 0.0);

	glEnd();
}

void DrawLeftHand() {	//���� ���� �׸��� �Լ�
	glBegin(GL_POLYGON);
	glColor3f(0.3f, 0.3f, 0.3f);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(- 0.13, 0.0, 0.0);
	glVertex3f(- 0.17, - 0.12, 0.0);
	glVertex3f(- 0.065, -0.2, 0.0);
	glVertex3f(0.04, -0.12, 0.0);

	glEnd();

}


void DrawRightUpperArm() {	//������ �� ���� �׸��� �Լ�
	glBegin(GL_POLYGON);
	glColor3f(0.5f, 0.5f, 0.5f);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.13, 0.0, 0.0);
	glVertex3f(0.13, -0.26, 0.0);
	glVertex3f(0.0, -0.26, 0.0);

	glEnd();

}

void DrawRightLowerArm() {	//������ �Ʒ� ���� �׸��� �Լ�
	glBegin(GL_POLYGON);
	glColor3f(0.4f, 0.4f, 0.4f);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(-0.13, 0.0, 0.0);
	glVertex3f(-0.13, -0.26, 0.0);
	glVertex3f(0.0, -0.26, 0.0);

	glEnd();
}

void DrawRightHand() {	//������ ���� �׸��� �Լ�
	glBegin(GL_POLYGON);
	glColor3f(0.3f, 0.3f, 0.3f);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.13, 0.0, 0.0);
	glVertex3f(0.17, -0.12, 0.0);
	glVertex3f(0.065, -0.2, 0.0);
	glVertex3f(-0.04, -0.12, 0.0);

	glEnd();
}
void GoToLeftShoulderCoordinates()	//���� ����� ��ǥ�� �����ϴ� �Լ�
{
	glTranslatef(-0.13, 0.13, 0.0);
	glRotatef(-1 * theta, 0.0, 0.0, 1.0);	//���� �ø��� �ڿ������� ���ư����� ����
}

void GoToRightShoulderCoordinates()	//������ ����� ��ǥ�� �����ϴ� �Լ�
{
	glTranslatef(0.13, 0.13, 0.0);
	glRotatef(theta, 0.0, 0.0, 1.0);	//���� �ø��� �ڿ������� ���ư����� ����
}
void GoToLeftElbowCoordinates()	//���� �Ȳ�ġ�� ��ǥ�� �����ϴ� �Լ�
{
	glTranslatef(-0.13, -0.26, 0.0);
	glRotatef(-1 * theta, 0.0, 0.0, 1.0);	//���� �ø��� �ڿ������� ���ư����� ����
}

void GoToRightElbowCoordinates()	//������ �Ȳ�ġ�� ��ǥ�� �����ϴ� �Լ�
{
	glTranslatef(0.13, -0.26, 0.0);
	glRotatef(theta, 0.0, 0.0, 1.0);	//���� �ø��� �ڿ������� ���ư����� ����
}
void GoToLeftWristCoordinates()	//���� �ո��� ��ǥ�� �����ϴ� �Լ�
{
	glTranslatef(0.13, -0.26, 0.0);
}

void GoToRightWristCoordinates()	//������ �ո��� ��ǥ�� �����ϴ� �Լ�
{
	glTranslatef(-0.13, -0.26, 0.0);
}

void moveArms() {	//�ð��� ���Կ� ���� ������ �ٲپ� �ڿ������� �� ����� �������� ����
	if (theta <= max && flag == 1)
		theta++;
	else if (theta > max)	//�ִ� ������ ����� ��� ������ �Ʒ��� �ٲ۴�
		flag = 0;
	
	if (theta >= min && flag == 0)
		theta--;
	else if (theta < min)	//�ּ� ������ ����� ��� ������ ���� �ٲ۴�
		flag = 1;
}


void DrawLArm() {	//������ �׸��� �Լ��� ����
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

void DrawRArm() {	//�������� �׸��� �Լ��� ����
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

void DrawRobot() {	//�κ��� ��ü ���¸� ����ϴ� �Լ� ȣ��
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	DrawBody();
	glPushMatrix();
	DrawHead(0.0, 0.26, 0.13);
	glPushMatrix();
	DrawLArm();
	DrawRArm();

}

void MyTimer(int value) {	//�ð��� ���� �̺�Ʈ �߻�
	glutPostRedisplay();	//���÷��� �̺�Ʈ �߻�
	glutTimerFunc(10, MyTimer, 1);
}

void MyDisplay() {	//���÷��̿� ���� �Լ�
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
