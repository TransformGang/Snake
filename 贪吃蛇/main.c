#include "snakeFunction.h"
//1 ��ʼ���� ��ʼ��ʳ��
//2 ��ʾ���ն�
//3 �����ƶ�
//�Ƿ�����ǽ
//�Ƿ�ҧ���Լ�����
//�Ե�ʳ��
//�ߵ���������һ��
//ԭʳ����ʧ, �����µ�ʳ��
//ͳ�Ʒ���
//
//4 �ߵ�����
//��ӡ�÷ֺ�����
int main() 
{
	struct snake *Snake = NULL;
	Snake = (struct snake*)malloc(sizeof(struct snake));//�����߽ṹ���С���ڴ�ռ�
	snake_init(Snake);
	show_ui();
	action_snake(Snake); 
	system("pause");
	return 0;
}