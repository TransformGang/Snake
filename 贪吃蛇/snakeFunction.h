#pragma once
#define WITH 60
#define HIGHT 20
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
struct coordinate
{
	int x;
	int y;
};
//typedef struct _COORD {
//	SHORT X;
//	SHORT Y;
//} COORD;
struct snake
{
	struct coordinate body[WITH*HIGHT];//保存蛇每节的坐标
	int size;//蛇的长度
	struct coordinate food;//食物的坐标
	COORD coord;//控制光标的位置
	int dx;//控制蛇头的x坐标
	int dy;//控制蛇头的y轴坐标
	struct coordinate list;//保存变化后的蛇尾的位置
	int n;//控制得分
};
void snake_init(struct snake* Snake);//初始化蛇的属性
void put_snake(struct snake* Snake);//蛇的打印
void put_food(struct snake* Snake);//随机出现食物
void action_snake(struct snake* Snake); //蛇的动作
void position_snake(struct snake* Snake);//更新蛇的位置
void direction_snake(struct snake* Snake);//控制蛇的方向
void eat_food(struct snake*Snake); //吃到食物
void eat_self(struct snake* Snake); //吃到自己
void game_over(struct snake* Snake); //游戏结束
void show_ui();//打印界限
