#include "snakeFunction.h"
//1 初始化蛇 初始化食物
//2 显示在终端
//3 让蛇移动
//是否碰到墙
//是否咬到自己身体
//吃到食物
//蛇的身体增加一节
//原食物消失, 产生新的食物
//统计分数
//
//4 蛇的死亡
//打印得分和排名
int main() 
{
	struct snake *Snake = NULL;
	Snake = (struct snake*)malloc(sizeof(struct snake));//申请蛇结构体大小的内存空间
	snake_init(Snake);
	show_ui();
	action_snake(Snake); 
	system("pause");
	return 0;
}