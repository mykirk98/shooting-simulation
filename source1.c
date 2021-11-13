#include <stdio.h>
#include <conio.h>
#include <Windows.h>

int pan[10][10];
int main()
{
	int x = 0, y = 0;
	pan[x][y] = 1;
	int key;
	int i = 0;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			printf("%d ", pan[i][j]);
		}
		printf("\n");
	}
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
					if (x == 0)
						break;
					system("cls");
					pan[x][y] = 0;
					pan[x - 1][y] = 1;
					x--;
					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							printf("%d", pan[i][j]);
						}
						printf("\n");
					}
					break;
				case 75:
					if (y == 0)
						break;
					system("cls");
					pan[x][y] = 0;
					pan[x][y - 1] = 1;
					y--;
					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							printf("%d", pan[i][j]);
						}
						printf("\n");
					}
					break;
				case 77:
					if (y == 9)
						break;
					system("cls");
					pan[x][y] = 0;
					pan[x][y + 1] = 1;
					y++;
					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							printf("%d", pan[i][j]);
						}
						printf("\n");
					}
					break;
				case 80:
					if (x == 9)
						break;
					system("cls");
					pan[x][y] = 0;
					pan[x + 1][y] = 1;
					x++;
					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							printf("%d", pan[i][j]);
						}
						printf("\n");
					}
					break;
				}
			}
		}
	}
}