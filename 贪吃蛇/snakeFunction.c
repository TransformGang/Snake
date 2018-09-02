#include "snakeFunction.h"

void snake_init(struct snake* Snake) //��ʼ���ߵ�����
{
	Snake->size = 2;
	Snake->body[0].x = WITH / 2;
	Snake->body[0].y = HIGHT / 2;
	Snake->body[1].x = WITH / 2 - 1;
	Snake->body[1].y = HIGHT / 2;
	srand((unsigned int)time(NULL));
	Snake->food.x = rand() % WITH;
	Snake->food.y = rand() % HIGHT;
	Snake->dx = 0;
	Snake->dy = -1;
	Snake->n = 0;
}
void put_snake(struct snake* Snake)//�ߵĴ�ӡ
{
	for (int i = 0; i < Snake->size; i++)
	{
		Snake->coord.X = Snake->body[i].x;
		Snake->coord.Y = Snake->body[i].y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Snake->coord);
		if (0 == i)
		{
			printf("@");
		}
		else
		{
			printf("*");
		}
	}
	Snake->coord.X = Snake->list.x;
	Snake->coord.Y = Snake->list.y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Snake->coord);
	printf(" ");
}
void put_food(struct snake* Snake)//�������ʳ��
{
	Snake->coord.X = Snake->food.x;
	Snake->coord.Y = Snake->food.y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Snake->coord);
	printf("#");
}
void action_snake(struct snake* Snake) //�ߵĸ�����Ϊ
{
	while (Snake->body[0].x>=0&&Snake->body[0].x<WITH&&Snake->body[0].y>=0&&Snake->body[0].y<HIGHT)
	{
		eat_self(Snake);//�Ե��Լ�
		eat_food(Snake);//�Ե�ʳ��
		put_snake(Snake);//��ӡ��
		put_food(Snake);//�������ʳ��
		direction_snake(Snake); //�����ߵķ���
		position_snake(Snake);//�����ߵ�λ��
		Sleep(200);
	}
	game_over(Snake);
}
void eat_food(struct snake*Snake) //�Ե�ʳ��
{
	if (Snake->body[0].x == Snake->food.x&&Snake->body[0].y == Snake->food.y) 
	{
		Snake->size += 1;
		Snake->n += 1;
		Snake->food.x = rand() % WITH;
		Snake->food.y = rand() % HIGHT;
	}
}
void eat_self(struct snake* Snake) //�Ե��Լ�
{
	for (int i = 1; i < Snake->size; i++) 
	{
		if (Snake->body[i].x == Snake->body[0].x&&Snake->body[i].y == Snake->body[0].y)
		{
			game_over(Snake);//��Ϸ��������
		}
		
	}
}
void game_over(struct snake * Snake) //��Ϸ����
{
	Snake->coord.X = WITH/2;
	Snake->coord.Y = HIGHT+1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Snake->coord);
	printf("��Ϸ����! ����%d", Snake->n);
	exit(1);
	
}
void position_snake(struct snake* Snake)//�����ߵ�λ��
{
	Snake->list = Snake->body[Snake->size-1];
	for (int i = Snake->size-1; i > 0;i--) 
	{
		Snake->body[i] = Snake->body[i-1];
	}
	Snake->body[0].x += Snake->dx;
	Snake->body[0].y += Snake->dy;
}
void direction_snake(struct snake* Snake) //�����ߵķ���
{
	char  key = 0;
	char l = 0;
	while (_kbhit()) //�ж��Ƿ��°���,���²�����0 
	{
		key = _getch();
		l = _getch();
	}
	switch (key) 
	{
	case 'w':
		Snake->dx=0;
		Snake->dy=-1;
		break;
	case 's':
		Snake->dx = 0;
		Snake->dy = 1;
		break;
	case 'a':
		Snake->dx = -1;
		Snake->dy = 0;
		break;
	case 'd':
		Snake->dx = 1;
		Snake->dy = 0;
		break;
	}
}
void show_ui()//Χǽ�ķ�Χ
{
	for (int i = 0; i <= HIGHT; i++) 
	{
		for (int j = 0; j <= WITH-1; j++) 
		{
			if(i<HIGHT)
			{
				printf(" ");
			}
			else
			{
				printf("$");
			}
		}
		printf("$");
		printf("\n");
	}

}
