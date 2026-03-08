//// *************************************************************************************
//// FileName: main.c
//// Description: 程序入库文件
//// 
//// Version: v1.0.0
//// Creator: li
//// CreationTime: 2026-03-7 
//// ==============================================================
//// History update record:
//// 1. 2026.3.6号发现隐藏bug,当玩家先输入合法数字后，再次输入时输入非数字字符时（汉字或字母）后，使用提示功能此时提示功能异常，
//// 出现不符合常理的提示。
//// 解决方法：每次当输出提醒玩家合法输入信息时，对guess_is_initialized重新赋值为0，强迫玩家重新输入4为数字！
//// ==============================================================
//// *************************************************************************************
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//#include<string.h>
//void generate_target(int target[])
//{
//	int i = 0;
//	int used[10] = { 0 };//定义一个标记型数组，结果为0/1，0表示没有用过，1表示已经用过了
//
//	while (i == 0)
//	{
//		int num = rand() % 10;//生成0~9
//		if (num != 0 && !used[num])
//		{
//			target[i++] = num;
//			used[num] = 1;
//		}
//	}
//	while (i < 4)
//	{
//		int num = rand() % 10;
//		if (!used[num])
//		{
//			target[i++] = num;
//			used[num] = 1;
//		}
//	}
//}
//int is_valid(int guess[])//来检验玩家最终输入的合法性，首位数字不能为0，而且也不能有重复数字！
//{
//	int i = 0;
//	int num = guess[i];
//	int used[10] = { 0 };//定义一个标记型数组，结果为0/1，0表示没有用过，1表示已经用过了
//	if (guess[i] == 0)
//	{
//		return 0;//返回零表示玩家输入不对
//	}
//	while (i < 4)
//	{
//		num = guess[i];
//		if (!used[num])
//		{
//			used[num] = 1;
//		}
//		else
//		{
//			return 0;
//		}
//		i++;
//	}
//	return 1;
//}
//void calculate_ab(int target[], int guess[], int* a, int* b)
//{
//	*a = 0;
//	*b = 0;
//	int i = 0;
//	int j = 0;
//	int target_used[4] = { 0 };//定义两个标记型数组，用来标记数组元素是否已经统计过A或B了，0:未统计,1:已统计
//	int guess_used[4] = { 0 };//
//	for (i = 0; i < 4; i++)//计算A的数量(A代表正确的数字在正确的位置上)
//	{                      //计算逻辑：只需要将guess与target中的元素一一比较即可，相等就加一，不相等就继续
//		if (guess[i] == target[i])
//		{
//			(*a)++;
//			target_used[i] = 1;//对统计过的数组元素进行标记
//			guess_used[i] = 1;
//		}
//	}
//	//i 代表target的索引
//	//j 代表guess的索引
//	for (i = 0; i < 4; i++)//计算B(B代表正确的数字在错误的位置上)
//	{                      //计算逻辑：遍历target中「没算过A」的位，去guess里找「没算过A」且数字相同的位
//		if (!target_used[i])
//		{
//			for (j = 0; j < 4; j++)
//			{
//				if (!guess_used[j] && target[i] == guess[j])
//				{
//					(*b)++;
//					guess_used[j] = 1;
//					break;
//				}
//			}
//		}
//	}
//	printf("反馈：%dA%dB\n", *a, *b);
//}
//void give_hint(int target[], int guess[])//提示功能,随机从guess中选取一个元素依次与target[0]~target[3]进行比较
//{
//	//如果有相等的则exits标记为1，退出循环，输出结果，
//	int rand_index = rand() % 4;
//	int j = 0;
//	int i = 0;
//	int exits = 0;
//		for (j = 0; j < 4; j++)
//		{
//			if (guess[rand_index] == target[j])
//			{
//				exits = 1;
//				break;
//			}
//		}
//	printf("数字%d%s在目标数字当中！\n", guess[rand_index], exits ? "" : "不");
//}
//
//int main()
//{
//
//	srand((unsigned int)time(NULL));
//	int target[4] = { 0 };
//	char input[10] = { 0 };
//	int guess[4] = { 0 };
//	int guess_is_initialized = 0;//用一个标记型变量来检测玩家是否输入完毕，即已经初始化！
//	int a = 0;
//	int b = 0;
//	generate_target(target);
//	printf("===== Guess number pro =====\n");
//	printf("规则：随机生成4位目标数字，首位不为零且没有重复数字！\n");
//	printf("反馈：xAyB(x：数字和位置都正确，y:数字但正确位置不对)\n");
//	printf("帮助：输入“重新开始”以刷新目标数字，输入“提示”可获得线索\n");
//	printf("===== Guess number pro =====\n");
//	while (1)
//	{
//		printf("\n请输入猜测数字:>");
//		scanf("%s", input);//检验玩家输入部分，看看输入的够不够、存不存在非数字字符、有无重复或首位非
//		while (getchar() != '\n');//清理缓冲区，清理到'\n'结束
//		if (strcmp(input, "提示") == 0)
//		{
//			if (!guess_is_initialized)
//			{
//				printf("请先输入4位数字，再使用提示！\n");
//				continue;
//			}
//			else
//			{
//				give_hint(target, guess);
//				continue;
//			}
//
//		}
//		if (strcmp(input, "重新开始") == 0)
//		{
//			guess_is_initialized = 0;
//			generate_target(target);
//			printf("目标数字已刷新！\n");
//			continue;
//		}
//		if (strlen(input) != 4)//检验够不够4位数字
//		{
//			guess_is_initialized = 0;
//			printf("输入合法4位数字，听不懂吗！\n");
//			continue;//跳过剩余代码回到while循环开头，重新执行任务！
//		}
//		//检验玩家输入的是不是全为数字
//		int is_all_digit = 1;//定义一个标记变量，结果为（0/1），结果为1表示玩家输入全为数字，为0表示有非数字字符
//		for (int i = 0; i < 4; i++)
//		{
//			if (input[i] < '0' || input[i]>'9')
//			{
//				is_all_digit = 0;//表示input数组中有非数字字符
//			}
//			guess[i] = input[i] - '0';//对guess进行动态初始化，利用数字与字符零的ASCII指来实现字符转化数字！
//		}
//		if (!is_all_digit)
//		{
//			guess_is_initialized = 0;
//			printf("输入错误，包含非数字字符！\n");
//			continue;
//		}
//		if (!is_valid(guess))//返回0表示，玩家输入错误，执行if语句块，返回1表示玩家输入正确，不执行语句块
//		{
//			guess_is_initialized = 0;
//			printf("输入错误，首数字为零或有重复数字！\n");
//			continue;
//		}
//		guess_is_initialized = 1;
//		calculate_ab(target, guess, &a, &b);
//		if (a == 4)
//		{
//			printf("恭喜你猜对了，游戏结束！");
//			break;
//		}
//	}
//	return 0;
//}