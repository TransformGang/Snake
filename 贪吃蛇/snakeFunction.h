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
	struct coordinate body[WITH*HIGHT];//������ÿ�ڵ�����
	int size;//�ߵĳ���
	struct coordinate food;//ʳ�������
	COORD coord;//���ƹ���λ��
	int dx;//������ͷ��x����
	int dy;//������ͷ��y������
	struct coordinate list;//����仯�����β��λ��
	int n;//���Ƶ÷�
};
void snake_init(struct snake* Snake);//��ʼ���ߵ�����
void put_snake(struct snake* Snake);//�ߵĴ�ӡ
void put_food(struct snake* Snake);//�������ʳ��
void action_snake(struct snake* Snake); //�ߵĶ���
void position_snake(struct snake* Snake);//�����ߵ�λ��
void direction_snake(struct snake* Snake);//�����ߵķ���
void eat_food(struct snake*Snake); //�Ե�ʳ��
void eat_self(struct snake* Snake); //�Ե��Լ�
void game_over(struct snake* Snake); //��Ϸ����
void show_ui();//��ӡ����
