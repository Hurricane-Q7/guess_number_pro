//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<string.h>
//#include<time.h>
//#include<stdlib.h>
////目标数字生成要求：
////1. 首位不能是数字0！
////2. 一共生成4位数字！
////3. 不能有重复的数字！
//void generate_target(int target[])//目标数字生成器
//{
//	int num = 0;//num代表使用
//	int i = 0;
//	int used[10] = { 0 };//用一个数组来标记生成的数字有没有用过，用过标记为1，没有用过标记为0
//	//第一位数字生成
//	while (i == 0)
//	{
//		int num = rand() % 10;//用一个变量来存放生成的数字（0~9）;
//		if (num != 0 && !used[num])//!1为假，也就是代表用过了，!0为真，代表没有被标记，可以使用！
//		{
//			target[i++] = num;//赋值完即使调整
//			used[num] = 1;
//		}
//	}
//	//后三位数字生成
//	while (i < 4)
//	{
//		int num = rand() % 10;
//		if (!used[num])//后三位只要满足不重复即可
//		{
//			target[i++] = num;
//			used[num] = 1;
//		}
//	}
//
//}
//void calculate_ab(int target[], int guess[], int* a, int* b)
//{
//	//计算a与b
//	*a = 0;
//	*b = 0;
//	int i = 0;
//	int target_used[4] = { 0 };
//	int guess_used[4] = { 0 };
//	for (i = 0; i < 4; i++)
//	{
//		if (guess[i] == target[i])
//		{
//			(*a)++;
//			target_used[i] = 1;
//			guess_used[i] = 1;
//		}
//	}
//	for (i = 0; i < 4; i++)
//	{
//		if (guess_used[i] == 0)//先排查已经被计算过A的元素
//		{
//			for (int j = 0; j < 4; j++)
//			{
//				if (!target_used[j] && target[j] == guess[i])
//				{
//					(*b)++;
//					target_used[j] = 1;
//					break;
//				}
//			}
//		}
//	}
//}
//int is_valid(int guess[])//检验玩家输入是否合法（首位非零，没有重复数字）,返回1说明合法，返回0说明不合法
//{
//	//1232
//	int i = 0;
//	int used[10] = { 0 };//定义一个标记型数组
//	int num = 0;
//	if (guess[0] == 0)//先检查首位为不为非零
//	{
//		return 0;
//	}
//
//	for (i = 0; i < 4; i++)//检查重复部分
//	{
//		num = guess[i];
//		if (used[num] == 1)//num代表使用过的数字
//		{
//			return 0;
//		}
//		used[num] = 1;
//	}
//	return 1;
//
//}
//
//
//void give_hint(int target[], int guess[])//提示功能生成器
//{
//	int i = 0;
//	int select_index = rand() % 4;
//	int num = guess[select_index];
//	int exists = 0;
//	for (i = 0; i < 4; i++)
//	{
//		if (target[i] == num)
//		{
//			exists = 1;//用一个变量来标记是否找到线索
//			break;
//		}
//	}
//	printf("数字%d%s在目标数字中!", num, exists ? "" : "不");
//}
//int main()
//{
//	srand((unsigned int)time(NULL));
//	int a = 0;
//	int b = 0;
//	int target[4] = { 0 };//存放生成好对目标数字
//	int guess[4];//接收数字部分
//	char input[10];//用来接收玩家的输入信息（数字/重新开始/提示）
//	int guess_is_initialized = 0;//状态标记变量，用来检测玩家是否完成对guess数组初始化(0/1),0表示未初始化,1初始化完毕！
//	printf("==== 猜数字小游戏 ====\n");
//	printf("规则：输入4位不重复数字,首位不能为0（格式xxxx）\n");
//	printf("反馈：xAyB(x：数字和位置都正确，y:数字但正确位置不对)\n");
//	printf("帮助：输入“重新开始”可以以刷新目标数字，输入“提示”可以获得线索\n");
//	printf("==== 猜数字小游戏 ====\n");
//	generate_target(target);
//	while (1)
//	{
//		printf("\n请输入猜测(4位数字):>");
//		scanf("%s", input);
//		//处理输入特殊情况（重新开始/提示）
//		if (strcmp(input, "重新开始") == 0)
//		{
//			generate_target(target);
//			printf("已重新刷新目标数字,请重新猜测！\n");
//			guess_is_initialized = 0;//及时更新
//			continue;
//		}
//		if (strcmp(input, "提示") == 0)
//		{
//			if (guess_is_initialized == 0)
//			{
//				printf("请先输入4位有效数字，再来寻求提示！\n");
//				continue;
//			}
//			give_hint(target, guess);
//			continue;
//		}
//		//检验玩家输入问题（够不够）
//		if (strlen(input) != 4)//strlen只统计\0之前的字符个数
//		{
//			printf("输入错误！请输入4位数字\n");
//			continue;
//		}
//		int temp = getchar();//吃掉\n
//		int is_all_digit = 1;//定义一个标记型变量来看玩家输入的是不是全为数字，1则全为数字，0则不全为数字！
//		//检验玩家输入（纯不纯）
//		for (int i = 0; i < 4; i++)
//		{
//			if (input[i] < '0' || input[i] >'9')
//			{
//
//				is_all_digit = 0;
//				break;
//			}
//			guess[i] = input[i] - '0';//动态初始化guess数组
//		}
//		if (!is_all_digit)//检验全为数字的卡口
//		{
//			printf("只能输入4位纯数字，不能含有其他字符\n");
//			continue;
//		}
//		if (!is_valid(guess))//检验玩家输入的最后一步（首位非零且不能有重复数字）！
//		{
//			printf("输入不合法，首位不能为0且不能有重复数字！");
//			continue;
//		}
//		guess_is_initialized = 1;
//		calculate_ab(target, guess, &a, &b);//通过传地址的方式来间接改变a,b的值
//		printf("反馈：%dA%dB\n", a, b);
//		if (a == 4)
//		{
//			printf("恭喜你猜对了，游戏结束！");
//			break;
//		}
//	}
//	return 0;
//}
