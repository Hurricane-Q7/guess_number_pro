//猜数字pro
//编程核心逻辑：先生成一个合法目标数字(首位不能为0、不能有重复数字),然后玩家去输入猜测目标数字，并对玩家的输入进行多次检测，
//看输入的够不够、纯不纯、合不合法，合法的话，进入判断对错环节（计算AB，A为4的时候，猜对了游戏结束），不合法的话，提醒玩家再次输入！
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
void generate_target(int target[])
{
	int i = 0;
	int target_used[10] = { 0 };
	while (i == 0)
	{
		int rand_num = rand() % 10;
		//先生成第一位数字
		if (rand_num != 0 && !target_used[i])
		{
			target[i++] = rand_num;
			target_used[rand_num] = 1;
		}
	}
	while (i < 4)
	{
		//生成后三位数字
		int rand_num = rand() % 10;
		if (!target_used[rand_num])
		{
			target[i++] = rand_num;
			target_used[rand_num] = 1;
		}
	}
}
void cal_AB(int target[],int guess[],int* a,int* b)
{
	*a = 0;
	*b = 0;
	int i = 0;//target
	int j = 0;//guess
	int target_used[4] = { 0 };
	int guess_used[4] = { 0 };
	for (i = 0; i < 4; i++)
	{
		if (guess[i] == target[i])
		{
			(*a)++;
			target_used[i] = 1;
			guess_used[i] = 1;
		}
	}
	for (i = 0; i < 4; i++)
	{
		if (!target_used[i])
		{
			for (j = 0; j < 4; j++)
			{
				if (!guess_used[j] && guess[j] == target[i])
				{
					(*b)++;
					guess_used[j];
					break;
				}
			}
		}
	}
	printf("反馈：%dA%dB\n", *a, *b);
}
void give_hint(int target[], int guess[])
{
	int rand_index = rand() % 4;
	int exits = 0;
	for (int i = 0; i < 4; i++)
	{
		if (guess[rand_index] == target[i])
		{
			exits = 1;
		}
	}
	printf("提示：数字%d%s在目标数字中!\n", guess[rand_index], exits?"":"不");
}
int is_valid(int guess[])
{ 
	//看玩家输入有无重复数字,首位是不是有零
	//返回值：返回值为0代表有错误，返回1代表正确
	int i = 0;
	int guess_used[10] = { 0 };
	if (guess[i] == 0)
	{
		return 0;
	}
	while (i < 4)
	{
		int num = guess[i];
		if (!guess_used[num])
		{
			guess_used[num] = 1;
		}
		else
		{
			return 0;
		}
		i++;
	}
	return 1;
}
void print_target(int target[])
{
	int i = 0;
	for (i = 0; i < 4; i++)
	{
		printf("%d", target[i]);
	}
	printf("\n");
}
int main()
{
	srand((unsigned int)time(NULL));//设置时间起点
	int i = 0;
	int a = 0;
	int b = 0;
	int target[4] = { 0 };
	char input[10] = { 0 };
	int guess[4] = { 0 };
	int guess_is_initialized = 0;//0:未初始化，1：已经初始化
	generate_target(target);
	printf("===== Guess number pro =====\n");
	printf("规则：随机生成4位目标数字，首位不为零且没有重复数字！\n");
	printf("反馈：xAyB(x：数字和位置都正确，y:数字但正确位置不对)\n");
	printf("帮助：输入“重新开始”以刷新目标数字，输入“提示”可获得线索\n");
	printf("===== Guess number pro =====\n");
	print_target(target);
	while (1)
	{
		printf("请输入你的猜测:>\n");
		scanf("%s", input);
		while (getchar() != '\n');
		if (strcmp(input, "提示") == 0)
		{
			if (guess_is_initialized == 0)
			{
				printf("请先输入4位数字，在用提示功能！\n");
				continue;
			}
			if (guess_is_initialized == 1)
			{
				give_hint(target, guess);
				continue;
			}
		}
		if (strcmp(input, "重新开始") == 0)
		{
			generate_target(target);
			guess_is_initialized = 0;
			printf("已刷新目标数字！\n");
			continue;
		}
		if (strlen(input) != 4)//够不够
		{
			guess_is_initialized = 0;
			printf("请输入4位合法数字!\n");
			continue;
		}
		//检验纯不纯，看玩家输入的有没有别的字符
		int is_all_digit = 0;//0:全为数字，1:表示存在非数字字符
		for (i = 0; i < 4; i++)
		{
			if (input[i] < '0' || input[i]>'9')
			{
				is_all_digit = 1;
			}
			guess[i] = input[i] - '0';
		}
		if (is_all_digit==1)
		{
			printf("发现非数字字符，请重新输入！\n");
			guess_is_initialized = 0;
			continue;
		}
		if (!is_valid(guess))
		{
			guess_is_initialized = 0;
			printf("输入错误，首位为0或有重复数字！\n");
			continue;
		}
		guess_is_initialized = 1;
		cal_AB(target, guess, &a, &b);
		if (a == 4)
		{
			printf("恭喜你猜对了，游戏结束！");
			break;
		}
	}
	return 0;
}