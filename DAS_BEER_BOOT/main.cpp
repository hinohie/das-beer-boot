
#include <stdio.h>
#include <stdlib.h>
#include <glut.h>
#include <Windows.h>
#include <time.h>

#include "vertex.h"
#include "meterial.h"
#include "flag.h"
#include "object.h"
#include "model.h"
#include "beer.h"

#include "funccollect.h"

#define SLEEP_TIME 16

Beer *butter;
Beer *beer_1;
Beer *beer_2;
Beer *beer_3;
Beer *beer_4;

int cur_state;
const int state_num = 3;
GLenum state_list[3] = {GL_POINT, GL_LINE, GL_FILL};
int cur_beer;
const int beer_num = 4;
Beer *beer_list[50];

int timer;

int sinario_timer[100] = {4000, 4000, 1000, 
							7400,2600, 5700,
							1300,3000,4000,
							//tired
							6000,4000, 7500,
							3600, 2200, 3400,
							1800, 4000, 3000,
							/// dinner is simple
							3000, 2700, 3000,
							// disert
							3000, 14000,
							20};
const int sinario_num = 30;

int cur_sinario = 0;

Model *test_model;

long t1,t2;
long proc_time = -1;

double M_PI;
int back;
Color back_c;
float ddd;
float angle;

void reshape(int w,int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1, 1, -1, 1, 0.5, 180.0);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	switch(cur_sinario)
	{
	case 0:
		sinario_test(test_model);		// sinario for test 
		break;
	case 1:
		sinario_intro(test_model);
		break;
	case 2:
		sinario_uya(test_model);
		break;
	case 3:
		sinario_1(test_model);
		break;
	case 4:
		sinario_2(test_model);			// vier
		break;
	case 5:
		draw_background();
		sinario_0(test_model);			// sinario for assignment
		break;
	case 6:
		draw_background();
		sinario_daas(test_model);
		break;
	case 7:
		sinario_3(test_model);
		break;
	case 8:
		sinario_cheese(test_model);		// pour cheese
		break;
	case 9:
		sinario_tired(test_model);
		break;
	case 10:
		sinario_drink_energy(test_model);
		break;
	case 11:							// energy drink
		draw_background();
		sinario_4(test_model);
		break;
	case 12:
		sinario_0(test_model);
		break;
	case 13:
		sinario_pancake(test_model);
		break;
	case 14:
		sinario_sugar(test_model);
		break;
	case 15:
		sinario_shunichel(test_model);
		break;
	case 16:
		sinario_butter(test_model);
		break;
	case 17:
		sinario_dinner(test_model);				// dinner
		break;
	case 18:
		sinario_5(test_model);
		break;
	case 19:
		sinario_mayo(test_model);
		break;
	case 20:
		sinario_milk(test_model);
		break;
	case 21:
		sinario_putin(test_model);
		break;
	case 22:
		draw_background();
		sinario_6(test_model);
		break;
	default:
		sinario_done();
		break;
	}
	if(cur_sinario < sinario_num && proc_time > sinario_timer[cur_sinario] )
	{
		printf("%d is done\n",cur_sinario);
		proc_time -= sinario_timer[cur_sinario];
		back = 0;
		cur_sinario++;
		if(cur_sinario == 8 )
			angle = 0;
		if(cur_sinario == 20 )
			angle = 0;
		timer = 0;
	}
	
	Sleep(SLEEP_TIME);
	glutPostRedisplay();
	t2 = clock();
	if(proc_time < 0) proc_time = 0;
	else {proc_time += (t2 - t1); timer += (t2 - t1);}
	t1 = clock();
}
void draw_background()
{
	if(proc_time > back)
	{
		back += 500;
		back_c.setd(rand()%256, rand()%256, rand()%256);
		ddd = (rand()%100 - 50)/200.0;
	}
	glPushMatrix();
	int i, j;
	glColor3f(back_c.R, back_c.G, back_c.B);
	for(i=0; i<360; i+=15)
	{
		for(j=0; j<4; j++)
		{
			glBegin(GL_LINE_LOOP);
			glVertex3d(angle * 10*cos((i+j) / M_PI), angle * 10*sin((i+j) / M_PI), -100);
			glVertex3d(1000*cos((i+j + angle) / M_PI), 1000*sin((i+j + angle) / M_PI), -100);
			glEnd();
		}
	}
	angle += ddd;
	glPopMatrix();
}
void data_init()
{
	beer_list[4] = butter_init(test_model, 0.0);
	beer_list[5] = energy_init(test_model, 10.0);
	beer_list[6] = beer_with_white_init(test_model, 1.0);
	beer_list[8] = chese_init(test_model, 1.0);

	beer_list[13] = pancake_init(test_model, 5.0);
	beer_list[14] = sosigy_init(test_model, 1.0);
	beer_list[15] = egg_init(test_model, 1.0);
	beer_list[16] = bakern_init(test_model, 3.0);

	beer_list[17] = sugar_init(test_model, 2.0);
	beer_list[18] = geapi_init(test_model, 7.0);

	beer_list[19] = sobrot_init(test_model, 3.0);
	beer_list[20] = gulasi_init(test_model, 1.0);
	beer_list[21] = burabt_init(test_model, 6.0);
	beer_list[22] = spotch_init(test_model, 0.5);
	beer_list[23] = hasen_init(test_model, 1.0);
	beer_list[24] = mayo_init(test_model, 1.0);

	beer_list[25] = cake_init(test_model, 0.0);
	
	for(int i=0; i<4; i++){
		beer_list[i] = beer_init(test_model, 3.0, i);
		beer_list[i+9] = pink_init(test_model, 1.0, i);
	}
	t1 = clock();
	srand(0);
	M_PI = acos(0.0) * 2;
}

DWORD WINAPI sound_thread(LPVOID data)
{
	Sleep(0);
	PlaySound(TEXT("01+Das+Beer+Boot.wav"), NULL, SND_FILENAME);
	printf("sound done");
	return 0;
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Das¢ÖBoots¢Ù");
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glutDisplayFunc( display );
	glutReshapeFunc( reshape );

	test_model = getModel("das_boots_back3.obj");
	if(test_model == NULL)
	{
		printf("Load model F.A.I.L. \n T^T\n");
		return 1;
	}
	PRINT(test_model);

	data_init();
	
	HANDLE thread1 = CreateThread(NULL, 0, sound_thread, NULL, 0, NULL);
	glutMainLoop();
	return 0;
}