#include <stdio.h>
#include <stdlib.h>					//문자열 배열
#include <time.h>
#include <math.h>					//절댓값 사용
#define Variety 10
#define SR_data 3
#define RANGE 10

int main()
{
	srand((unsigned)time(NULL));
	
	int i, j, k, l, choice, left_shot_count = 21;					//left_shot_count는 20발 중 몇 발 남았는지를 의미한다.
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

	printf("\t\t\t총열(mm)\t유효사거리(m)\t무게(kg)\n");
	for (i = 0; i < Variety; i++)
	{
		printf("%d %s", i + 1, SR_name[i]);
		for (j = 0; j < SR_data; j++)
		{
			printf("\t\t%0.1f", SNIPER_RIFLE[i][j]);					//제원값 나열
		}
		printf("\n");
	}
	AGAIN_SR:
	printf("\nSelect sniper Rifle 1 to 10 : ");
	scanf_s(" %d", &choice);
	if (choice > 10 || choice < 0)
	{
		printf("WRONG NUMBER!!");
		goto AGAIN_SR;								//goto를 사용한 이유 : 간단한 문장 표현을 사용하는데 for나 while 반복문을 사용하기는 아쉬워서 간단한 goto를 이용
	}
		printf("\nYour select %s. And your guns barrel : %0.0f mm, range : %0.0f m, weight : %0.1f kg\n", SR_name[choice - 1], SNIPER_RIFLE[choice - 1][0], SNIPER_RIFLE[choice - 1][1], SNIPER_RIFLE[choice - 1][2]);

	printf("\nDistance to target : ");
	scanf_s("%lf", &distance);
	
	printf("Fire blank shot\n");
	printf(" ");

	for (i = 0; i < RANGE; i++)					//표적지 예시를 첫화면에 보여주어 어느 표적지가 어떻게 생겼는지 보여준다.
	{											//표적지의 자세한 설명은 뒤에 사격시작했을 때 설명하겠다.
		printf("  %d", i);
	}
	printf(" →WIDTH\n");
	for (i = 0; i < RANGE; i++)
	{
		for (j = 0; j < RANGE + 1; j++)
		{
			printf(" ┿ ");
		}
		printf("\n%d  ", i);
		k = i;
			for (l = 0; l < RANGE; l++)
			{
				printf("%c  ", coordinate[k][l] = ' ');					//값이 없던 배열을 초기화
			}
			printf("\n");

	}
	printf("↓LENGTH\n");
	printf("Shooting start!\n");

	while (((width >= 0 && width < RANGE) && (length >= 0) && (length < RANGE)))					//width(가로)값과 length(세로)값이 0~9사이의 값일 때 반복한다.
	{	

	AIM_POINT:
		left_shot_count--;						//20발로 시작해서 쏠 떄마다 한발씩 차감한다.

		int x_target = rand() % 6 + 2, y_target = rand() % 6 + 2;				//원래 배열은 10X10의 2차원 배열이지만, 목표물의 배열값이 가로세로 1~7사이에서만 랜덤하게 나오도록 한다.
		coordinate[x_target][y_target] = 'V';							//목표물이 해당 배열에만 V로 저장
		
		int wind = rand() % 4 - 2;					//풍속의 영향이 반복할 때 마다 값으로 좌우 편차 2씩 랜덤값으로 주어진다.
		
			if (wind > 0)
				printf("East → %d (m/s)\n", wind);					//풍향이 (+)값이면 동풍
			else if (wind < 0)
				printf("West ← %0.0lf (m/s)\n", fabs(wind));				//풍향이 (-)이면절댓값을 씌워서 화면에 출력한다.
			else
				printf("No wind\n");					//풍향이 0일 때 화면에 출력

			printf("Where do you wanna make a shot ? (exit = negative number) (LENGTH, WIDTH) : ");				//내가 조준하고 있는 좌표를 적는다,,,음수를 기입하면 while루프가 종료된다.
			scanf_s(" %d, %d", &length, &width);
			if ((width >= 0 && width < RANGE) && (length >= 0 && length < RANGE))
			{
				coordinate[length][width + wind] = 'O';				//내가 조준해서 쏜 값에 풍향을 더해서 O를 배열에 저장한다.
																	//풍향이 가로에만 적용된 것은 하강기류,상승기류는 없다고 가정했기 때문이다.
			}
			else if (length >= RANGE && width >= RANGE)
			{
				printf("Wrong Aiming Point, try again\n");					//만약 조준한 좌표값이 가로세로 +10이 넘어가면 다시 쏘도록 한다.
				goto AIM_POINT;							//조건문이 참이면 AIM_POINT로 돌아간다.
			}
		printf(" ");
		for (i = 0; i < RANGE; i++)
		{
			printf("  %d", i);
		}
		printf(" →WIDTH\n");
		for (i = 0; i < RANGE; i++)						//표적지 출력
		{
			for (j = 0; j < RANGE + 1; j++)
			{
				printf(" ┿ ");
			}
			printf("\n%d  ", i);

			k = i;
				for (l = 0; l < RANGE; l++)
				{
					printf("%c  ", coordinate[k][l]);					//저장되있던 랜덤하게 나오던 'V'값과 내가 쏜 'O'값과 초기값 ' '을 모두 표현한다.
				}
				printf("\n");
		}
		printf("↓LENGTH\n");
			coordinate[length][width + wind] = ' ';						//출력을 마치고나서 내가 쏜 좌표를 다시 ' '로 초기화 해준다.
			printf("\n\n%d left\n", left_shot_count);					//잔여 총알 수 표현
			if (left_shot_count==0)
				break;
	}
	return 0;
}