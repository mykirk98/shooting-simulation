#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <conio.h>
#include <Windows.h>
#define RANGE 10

int main()
{
	srand((unsigned)time(NULL));

	int i, j, k, l, left_shot_count = 20, make_shot = 0;
	int length = 0, width = 0;
	int key;
	char coordinate[10][10];
	
	printf(" ");

	for (i = 0; i < RANGE; i++)
	{
		printf("  %d", i);
	}
	printf(" ¡æWIDTH\n");
	for (i = 0; i < RANGE; i++)
	{
		for (j = 0; j < RANGE + 1; j++)
		{
			printf(" ¦« ");
		}
		printf("\n%d  ", i);
		k = i;
		for (l = 0; l < RANGE; l++)
		{
			printf("%c  ", coordinate[k][l] = ' ');
		}
		printf("\n");

	}
	printf("¡éLENGTH\n");
	printf("Shooting start!\nIf you READY, press any ¡ç¡è¡æ¡é\n");

	while ((width >= 0 && width < RANGE) && (length >= 0) && (length < RANGE))
	{
		
	AIM_POINT:
		left_shot_count--;

		int x_target = rand() % 6 + 2, y_target = rand() % 6 + 2;
		coordinate[x_target][y_target] = 'V';

		int wind = rand() % 4 - 2;

		printf(" ");
		
		while (1)
		{
			if (_kbhit())
			{
				key = _getch();
				if (key == 224 || key == 0)
				{
					key = _getch();
					switch (key)
					{
					case 72:
						if (length == 0)
							break;
						system("cls");
						coordinate[length][width] = ' ';
						coordinate[length - 1][width] = 'O';
						length--;

						if (wind > 0)
							printf("East ¡æ %d (m/s)\n", wind);
						else if (wind < 0)
							printf("West ¡ç %0.0lf (m/s)\n", fabs(wind));
						else
							printf("No wind\n");

						printf(" ");
						for (i = 0; i < RANGE; i++)
						{
							printf("  %d", i);
						}
						printf(" ¡æWIDTH\n");
						for (i = 0; i < RANGE; i++)
						{
							for (j = 0; j < RANGE + 1; j++)
							{
								printf(" ¦« ");
							}
							printf("\n%d  ", i);

							k = i;
							for (l = 0; l < RANGE; l++)
							{
								printf("%c  ", coordinate[k][l]);
							}
							printf("\n");
						}
						printf("¡éLENGTH\n");
						break;
					case 75:
						if (width == 0)
							break;
						system("cls");
						coordinate[length][width] = ' ';
						coordinate[length][width - 1] = 'O';
						width--;

						if (wind > 0)
							printf("East ¡æ %d (m/s)\n", wind);
						else if (wind < 0)
							printf("West ¡ç %0.0lf (m/s)\n", fabs(wind));
						else
							printf("No wind\n");

						printf(" ");
						for (i = 0; i < RANGE; i++)
						{
							printf("  %d", i);
						}
						printf(" ¡æWIDTH\n");
						for (i = 0; i < RANGE; i++)
						{
							for (j = 0; j < RANGE + 1; j++)
							{
								printf(" ¦« ");
							}
							printf("\n%d  ", i);

							k = i;
							for (l = 0; l < RANGE; l++)
							{
								printf("%c  ", coordinate[k][l]);
							}
							printf("\n");
						}
						printf("¡éLENGTH\n");
						break;
					case 77:
						if (width == 9)
							break;
						system("cls");
						coordinate[length][width] = ' ';
						coordinate[length][width + 1] = 'O';
						width++;

						if (wind > 0)
							printf("East ¡æ %d (m/s)\n", wind);
						else if (wind < 0)
							printf("West ¡ç %0.0lf (m/s)\n", fabs(wind));
						else
							printf("No wind\n");

						printf(" ");
						for (i = 0; i < RANGE; i++)
						{
							printf("  %d", i);
						}
						printf(" ¡æWIDTH\n");
						for (i = 0; i < RANGE; i++)
						{
							for (j = 0; j < RANGE + 1; j++)
							{
								printf(" ¦« ");
							}
							printf("\n%d  ", i);

							k = i;
							for (l = 0; l < RANGE; l++)
							{
								printf("%c  ", coordinate[k][l]);
							}
							printf("\n");
						}
						printf("¡éLENGTH\n");
						break;
					case 80:
						if (length == 9)
							break;
						system("cls");
						coordinate[length][width] = ' ';
						coordinate[length + 1][width] = 'O';
						length++;
						
						if (wind > 0)
							printf("East ¡æ %d (m/s)\n", wind);
						else if (wind < 0)
							printf("West ¡ç %0.0lf (m/s)\n", fabs(wind));
						else
							printf("No wind\n");

						printf(" ");
						for (i = 0; i < RANGE; i++)
						{
							printf("  %d", i);
						}
						printf(" ¡æWIDTH\n");
						for (i = 0; i < RANGE; i++)
						{
							for (j = 0; j < RANGE + 1; j++)
							{
								printf(" ¦« ");
							}
							printf("\n%d  ", i);

							k = i;
							for (l = 0; l < RANGE; l++)
							{
								printf("%c  ", coordinate[k][l]);
							}
							printf("\n");
						}
						printf("¡éLENGTH\n");
						break;
					defualt:
						return 0;
					}
				}
				else if(key==13)
				break;
			}
		}
		if (length == x_target && width + wind == y_target)
		{
			make_shot++;
			printf("YOU MAKE THE %d  SHOT!!\n", make_shot);
		}
		else
			printf("YOU MISS!!");
		coordinate[length][width + wind] = ' ';
		printf("\n\n%d left\n", left_shot_count);
		if (left_shot_count == 0)
			break;
	}
	return 0;
}
