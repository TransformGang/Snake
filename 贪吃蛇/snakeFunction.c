#include "snakeFunction.h"

void snake_init(struct snake* Snake) //初始化蛇的属性
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
void put_snake(struct snake* Snake)//蛇的打印
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
void put_food(struct snake* Snake)//随机出现食物
{
	Snake->coord.X = Snake->food.x;
	Snake->coord.Y = Snake->food.y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Snake->coord);
	printf("#");
}
void action_snake(struct snake* Snake) //蛇的各种行为
{
	while (Snake->body[0].x>=0&&Snake->body[0].x<WITH&&Snake->body[0].y>=0&&Snake->body[0].y<HIGHT)
	{
		eat_self(Snake);//吃到自己
		eat_food(Snake);//吃到食物
		put_snake(Snake);//打印蛇
		put_food(Snake);//随机出现食物
		direction_snake(Snake); //控制蛇的方向
		position_snake(Snake);//更新蛇的位置
		Sleep(200);
	}
	game_over(Snake);
}
void eat_food(struct snake*Snake) //吃到食物
{
	if (Snake->body[0].x == Snake->food.x&&Snake->body[0].y == Snake->food.y) 
	{
		Snake->size += 1;
		Snake->n += 1;
		Snake->food.x = rand() % WITH;
		Snake->food.y = rand() % HIGHT;
	}
}
void eat_self(struct snake* Snake) //吃到自己
{
	for (int i = 1; i < Snake->size; i++) 
	{
		if (Snake->body[i].x == Snake->body[0].x&&Snake->body[i].y == Snake->body[0].y)
		{
			game_over(Snake);//游戏结束函数
		}
		
	}
}
void game_over(struct snake * Snake) //游戏结束
{
	Snake->coord.X = WITH/2;
	Snake->coord.Y = HIGHT+1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Snake->coord);
	printf("游戏结束! 分数%d", Snake->n);
	exit(1);
	
}
void position_snake(struct snake* Snake)//更新蛇的位置
{
	Snake->list = Snake->body[Snake->size-1];
	for (int i = Snake->size-1; i > 0;i--) 
	{
		Snake->body[i] = Snake->body[i-1];
	}
	Snake->body[0].x += Snake->dx;
	Snake->body[0].y += Snake->dy;
}
void direction_snake(struct snake* Snake) //控制蛇的方向
{
	char  key = 0;
	char l = 0;
	while (_kbhit()) //判断是否按下按键,按下不等于0 
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
void show_ui()//围墙的范围
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
