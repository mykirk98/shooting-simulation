#include <stdio.h>
#include <stdlib.h>					//���ڿ� �迭
#include <time.h>
#include <math.h>					//���� ���
#define Variety 10
#define SR_data 3
#define RANGE 10

int main()
{
	srand((unsigned)time(NULL));
	
	int i, j, k, l, choice, left_shot_count = 21;					//left_shot_count�� 20�� �� �� �� ���Ҵ����� �ǹ��Ѵ�.
	int length = 0, width = 0;
	double distance;
	char SR_name[Variety][20] = { "FD338-SRR","LaRueOBR","R11 RSASS","Mk.20 SCAR-SR","Mk14_EBR","Mk12_SPR","M110_SASS","M107_LRSR","M14SE_CH","M82-SRR V.2"  };
	char coordinate[10][10];
	double SNIPER_RIFLE[Variety][SR_data] = { { 635, 1400, 3.93 },			//FD338-SRR
											{ 409, 800, 4.3 },				//LaRue OBR
											{ 558,1400,7.1 },				//R11 RSASS
											{ 508,1000,4.84 },				//Mk.20 SCAR-SR
											{ 457,850,6.1 },				//Mk.14 EBR
											{ 457,549,4.5 },				//Mk.12 SPR
											{ 508,800,7.3 },				//M110 SASS
											{ 736,1800,12.9 },				//M107 LRSR
											{ 506,822,5.62 },				//M14SE CH
											{ 740,1800,14 } };				//M82

	printf("\t\t\t�ѿ�(mm)\t��ȿ��Ÿ�(m)\t����(kg)\n");
	for (i = 0; i < Variety; i++)
	{
		printf("%d %s", i + 1, SR_name[i]);
		for (j = 0; j < SR_data; j++)
		{
			printf("\t\t%0.1f", SNIPER_RIFLE[i][j]);					//������ ����
		}
		printf("\n");
	}
	AGAIN_SR:
	printf("\nSelect sniper Rifle 1 to 10 : ");
	scanf_s(" %d", &choice);
	if (choice > 10 || choice < 0)
	{
		printf("WRONG NUMBER!!");
		goto AGAIN_SR;								//goto�� ����� ���� : ������ ���� ǥ���� ����ϴµ� for�� while �ݺ����� ����ϱ�� �ƽ����� ������ goto�� �̿�
	}
		printf("\nYour select %s. And your guns barrel : %0.0f mm, range : %0.0f m, weight : %0.1f kg\n", SR_name[choice - 1], SNIPER_RIFLE[choice - 1][0], SNIPER_RIFLE[choice - 1][1], SNIPER_RIFLE[choice - 1][2]);

	printf("\nDistance to target : ");
	scanf_s("%lf", &distance);
	
	printf("Fire blank shot\n");
	printf(" ");

	for (i = 0; i < RANGE; i++)					//ǥ���� ���ø� ùȭ�鿡 �����־� ��� ǥ������ ��� ������� �����ش�.
	{											//ǥ������ �ڼ��� ������ �ڿ� ��ݽ������� �� �����ϰڴ�.
		printf("  %d", i);
	}
	printf(" ��WIDTH\n");
	for (i = 0; i < RANGE; i++)
	{
		for (j = 0; j < RANGE + 1; j++)
		{
			printf(" �� ");
		}
		printf("\n%d  ", i);
		k = i;
			for (l = 0; l < RANGE; l++)
			{
				printf("%c  ", coordinate[k][l] = ' ');					//���� ���� �迭�� �ʱ�ȭ
			}
			printf("\n");

	}
	printf("��LENGTH\n");
	printf("Shooting start!\n");

	while (((width >= 0 && width < RANGE) && (length >= 0) && (length < RANGE)))					//width(����)���� length(����)���� 0~9������ ���� �� �ݺ��Ѵ�.
	{	

	AIM_POINT:
		left_shot_count--;						//20�߷� �����ؼ� �� ������ �ѹ߾� �����Ѵ�.

		int x_target = rand() % 6 + 2, y_target = rand() % 6 + 2;				//���� �迭�� 10X10�� 2���� �迭������, ��ǥ���� �迭���� ���μ��� 1~7���̿����� �����ϰ� �������� �Ѵ�.
		coordinate[x_target][y_target] = 'V';							//��ǥ���� �ش� �迭���� V�� ����
		
		int wind = rand() % 4 - 2;					//ǳ���� ������ �ݺ��� �� ���� ������ �¿� ���� 2�� ���������� �־�����.
		
			if (wind > 0)
				printf("East �� %d (m/s)\n", wind);					//ǳ���� (+)���̸� ��ǳ
			else if (wind < 0)
				printf("West �� %0.0lf (m/s)\n", fabs(wind));				//ǳ���� (-)�̸������� ������ ȭ�鿡 ����Ѵ�.
			else
				printf("No wind\n");					//ǳ���� 0�� �� ȭ�鿡 ���

			printf("Where do you wanna make a shot ? (exit = negative number) (LENGTH, WIDTH) : ");				//���� �����ϰ� �ִ� ��ǥ�� ���´�,,,������ �����ϸ� while������ ����ȴ�.
			scanf_s(" %d, %d", &length, &width);
			if ((width >= 0 && width < RANGE) && (length >= 0 && length < RANGE))
			{
				coordinate[length][width + wind] = 'O';				//���� �����ؼ� �� ���� ǳ���� ���ؼ� O�� �迭�� �����Ѵ�.
																	//ǳ���� ���ο��� ����� ���� �ϰ����,��±���� ���ٰ� �����߱� �����̴�.
			}
			else if (length >= RANGE && width >= RANGE)
			{
				printf("Wrong Aiming Point, try again\n");					//���� ������ ��ǥ���� ���μ��� +10�� �Ѿ�� �ٽ� ��� �Ѵ�.
				goto AIM_POINT;							//���ǹ��� ���̸� AIM_POINT�� ���ư���.
			}
		printf(" ");
		for (i = 0; i < RANGE; i++)
		{
			printf("  %d", i);
		}
		printf(" ��WIDTH\n");
		for (i = 0; i < RANGE; i++)						//ǥ���� ���
		{
			for (j = 0; j < RANGE + 1; j++)
			{
				printf(" �� ");
			}
			printf("\n%d  ", i);

			k = i;
				for (l = 0; l < RANGE; l++)
				{
					printf("%c  ", coordinate[k][l]);					//������ִ� �����ϰ� ������ 'V'���� ���� �� 'O'���� �ʱⰪ ' '�� ��� ǥ���Ѵ�.
				}
				printf("\n");
		}
		printf("��LENGTH\n");
			coordinate[length][width + wind] = ' ';						//����� ��ġ���� ���� �� ��ǥ�� �ٽ� ' '�� �ʱ�ȭ ���ش�.
			printf("\n\n%d left\n", left_shot_count);					//�ܿ� �Ѿ� �� ǥ��
			if (left_shot_count==0)
				break;
	}
	return 0;
}