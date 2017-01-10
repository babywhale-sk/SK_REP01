// TXL.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#define N 10
int i = 0;
struct STUDENT
{
	char num[10];
	char name[20];
	char tele[15];
	char add[20];
	char email[15];
}stu[N];
void menu();
void input();
void display();
void add();

void deleteTXL();
void deleteWithName();
void deletewithNum();
void find();
void findWithName();
void findWithNum();
void revise();
void reviseWithName();
void reviseWithNum();

void main()
{
	while (1)
	{
		menu();
	}
}

void menu()
{
	char c;
	system("cls");
	printf("\n\t********************欢迎使用通讯录管理系统 *****************");
	printf("\n\t***************************主菜单**************************");
	printf("\n\t\t\t\t0:输入通讯录");
	printf("\n\t\t\t\t1:显示通讯录");
	printf("\n\t\t\t\t2:删除通讯录");
	printf("\n\t\t\t\t3:查找通讯录");
	printf("\n\t\t\t\t4:修改通讯录");
	printf("\n\t\t\t\t5:添加通讯录");
	printf("\n\t\t\t\t6:退出通讯录");
	printf("\n\t\t\t\t请输入选项0-6");
	c = _getch();
	switch (c)
	{
	case '0': input(); break;
	case '1': display(); break;
	case '2': deleteTXL(); break;
	case '3': find(); break;
	case '4': revise(); break;
	case '5': add(); break;
	case '6': exit(0);
	default:	menu();

	}

}

void input()
{
	system("cls");
	if (i >= N)
	{
		printf("\n\t\t 已经到达通讯录上限");
		_getch();
		return;
	}
	printf("\n\t\t ************************请录入的学生信息*********************");
	printf("\n\t\t 输入学号:");
	scanf("%s", stu[i].num);
	printf("\n\t\t 输入姓名:");
	scanf("%s", stu[i].name);
	printf("\n\t\t 输入电话:");
	scanf("%s", stu[i].tele);
	printf("\n\t\t 输入地址:");
	scanf("%s", stu[i].add);
	printf("\n\t\t 输入eMail:");
	scanf("%s", stu[i].email);
	i++;
	printf("\n\t\t 是否继续输入联系人？(Y/N)");
	if (_getch() == 'y' || _getch() == 'Y')
		input();
	else return;

}
void display()
{
	int n;
	system("cls");
	if (i != 0)
	{
		printf("\n\t\t******************系统拼命通讯录联系人信息*********************");
		for (n = 0; n<i; n++)
		{
			printf("\n\t\t ********************NO. %d****************", n);
			printf("\n--");
			Sleep(200);
			printf("---");
			Sleep(200);
			printf("----");
			Sleep(200);
			printf("\n\t\t 学号: %s", stu[n].num);
			printf("\n\t\t 姓名: %s", stu[n].name);
			printf("\n\t\t 电话: %s", stu[n].tele);
			printf("\n\t\t 地址: %s", stu[n].add);
			printf("\n\t\t eMail: %s", stu[n].email);
			printf("\n\t\t ******************************************");

		}

	}
	else
		printf("\n\t\t通讯录中没有任何记录,按任意键返回主菜单");
	_getch();
	return;
}


void add()
{
	system("cls");
	int mark = 0;
	int n = 0;
	char number[10];
	if (i >= N)
	{
		printf("\n\t\t ************************已经到达存储上限*********************");
		_getch();
		return;
	}
	printf("\n\t\t ************************首先输入要添加的学生学号*********************");
	printf("\n\t\t 请输入学号 ： ");
	scanf("%s", number);
	for (n = 0; n<i; n++)
	{
		if (strcmp(stu[n].num, number) == 0)
		{
			printf("\n\t\t  ！学生信息已经存在请查证");
			_getch();
			return;
		}
		else
		{
			strcpy(stu[n].num, number);
			printf("\n\t\t 输入姓名:");
			scanf("%s", stu[n].name);
			printf("\n\t\t 输入电话:");
			scanf("%s", stu[n].tele);
			printf("\n\t\t 输入地址:");
			scanf("%s", stu[n].add);
			printf("\n\t\t 输入eMail:");
			scanf("%s", stu[n].email);

			mark++;
			i++;
		}



	}
	display();
	_getch();
	return;
}

void deleteTXL()
{
	char c;
	system("cls");
	printf("\n\t\t****************删除学生记录****************");
	printf("\n\t\t|     1-根据姓名删除	   2-根据学号删除	|");
	c = _getch();
	switch (c)
	{
	case '1': deleteWithName(); break;
	case '2': deletewithNum(); break;
	default:menu();

	}


}


void deleteWithName()
{
	int mark = 0;
	int n;
	int temp;
	char name[20];
	printf("\n\t\t***********************按照姓名删除学生记录***************");
	printf("n\t\t 请输入要查找的姓名：");
	scanf("%s", name);
	for (n = 0; n<i; n++)
	{
		if (strcmp(stu[n].name, name) == 0)
		{
			printf("\n\t\t***************以下是查询结果***************");
			printf("\n\t\t 学号: %s", stu[n].num);
			printf("\n\t\t 姓名: %s", stu[n].name);
			printf("\n\t\t 电话: %s", stu[n].tele);
			printf("\n\t\t 地址: %s", stu[n].add);
			printf("\n\t\t eMail: %s", stu[n].email);
			printf("\n\t\t******************按任意键删除*************************");
			mark++;
			_getch();
			for (temp = n; temp<i - 1; temp++)
			{
				stu[temp] = stu[temp + 1];
			}
			i--;
			display();

		}
	}
	if (mark == 0)
	{
		printf("\n\t\t 没有找到联系人，按任意键返回主菜单");
		_getch();
		return;
	}
}

void deletewithNum()
{
	int mark = 0;
	int n;
	int temp;
	char number[10];
	printf("\n\t\t***********************按照学号删除学生记录***************");
	printf("n\t\t 请输入要查找的学号：");
	scanf("%s", number);
	for (n = 0; n<i; n++)
	{
		if (strcmp(stu[n].num, number) == 0)
		{
			printf("\n\t\t***************以下是查询结果***************");
			printf("\n\t\t 学号: %s", stu[n].num);
			printf("\n\t\t 姓名: %s", stu[n].name);
			printf("\n\t\t 电话: %s", stu[n].tele);
			printf("\n\t\t 地址: %s", stu[n].add);
			printf("\n\t\t eMail: %s", stu[n].email);
			printf("\n\t\t******************按任意键删除*************************");
			mark++;
			_getch();
			for (temp = n; temp<i - 1; temp++)
			{
				stu[temp] = stu[temp + 1];
			}
			i--;
			display();

		}
	}
	if (mark == 0)
	{
		printf("\n\t\t 没有找到联系人，按任意键返回主菜单");
		_getch();
		return;
	}
}
void find()
{
	char c;
	system("cls");
	printf("\n\t\t***************显示和查询学生信息***********");
	printf("\n\t\t|     1-根据姓名查找	   2-根据学号查找	|");
	c = _getch();
	switch (c)
	{
	case '1': findWithName(); break;
	case '2': findWithNum(); break;
	default:menu();

	}

}

void findWithName()
{
	int mark = 0;
	int n;
	char name[20];
	printf("\n\t\t***********************按照姓名查找***************");
	printf("n\t\t 请输入要查找的姓名：");
	scanf("%s", name);
	for (n = 0; n<i; n++)
	{
		if (strcmp(stu[n].name, name) == 0)
		{
			printf("\n\t\t***************以下是查询结果***************");
			printf("\n\t\t 学号: %s", stu[n].num);
			printf("\n\t\t 姓名: %s", stu[n].name);
			printf("\n\t\t 电话: %s", stu[n].tele);
			printf("\n\t\t 地址: %s", stu[n].add);
			printf("\n\t\t eMail: %s", stu[n].email);
			printf("\n\t\t*******************************************");
			mark++;
			_getch();
			return;
		}
	}
	if (mark == 0)
	{
		printf("\n\t\t 没有找到联系人，按任意键返回主菜单");
		_getch();
		return;
	}
}


void findWithNum()
{
	int mark = 0;
	int n;
	char number[10];
	printf("\n\t\t***********************按照学号查找***************");
	printf("n\t\t 请输入要查找的学号：");
	scanf("%s", number);
	for (n = 0; n<i; n++)
	{
		if (strcmp(stu[n].num, number) == 0)
		{
			printf("\n\t\t***************以下是查询结果***************");
			printf("\n\t\t 学号: %s", stu[n].num);
			printf("\n\t\t 姓名: %s", stu[n].name);
			printf("\n\t\t 电话: %s", stu[n].tele);
			printf("\n\t\t 地址: %s", stu[n].add);
			printf("\n\t\t eMail: %s", stu[n].email);
			printf("\n\t\t*******************************************");
			mark++;
			_getch();
			return;
		}
	}
	if (mark == 0)
	{
		printf("\n\t\t 没有找到联系人，按任意键返回主菜单");
		_getch();
		return;
	}
}
void revise()
{
	char c;
	system("cls");
	printf("\n\t\t***************显示和查询学生信息***********");
	printf("\n\t\t|     1-根据姓名查找并修改	   2-根据学号查找并修改	|");
	c = _getch();
	switch (c)
	{
	case '1': reviseWithName(); break;
	case '2': reviseWithNum(); break;
	default:menu();

	}

}

void reviseWithName()
{
	int mark = 0;
	int n;
	char name[20];
	printf("\n\t\t***********************按照姓名查找***************");
	printf("n\t\t 请输入要查找的姓名：");
	scanf("%s", name);
	for (n = 0; n<i; n++)
	{
		if (strcmp(stu[n].name, name) == 0)

		{
			printf("\n\t\t***************以下是查询结果***************");
			printf("\n\t\t 学号: %s", stu[n].num);
			printf("\n\t\t 姓名: %s", stu[n].name);
			printf("\n\t\t 电话: %s", stu[n].tele);
			printf("\n\t\t 地址: %s", stu[n].add);
			printf("\n\t\t eMail: %s", stu[n].email);
			printf("\n\t\t***************请输入新的结果*****************");
			printf("\n\t\t 输入学号:");
			scanf("%s", stu[n].num);
			printf("\n\t\t 输入姓名:");
			scanf("%s", stu[n].name);
			printf("\n\t\t 输入电话:");
			scanf("%s", stu[n].tele);
			printf("\n\t\t 输入地址:");
			scanf("%s", stu[n].add);
			printf("\n\t\t 输入eMail:");
			scanf("%s", stu[n].email);
			mark++;
			printf("\n\t\t***************显示新的通讯录*****************");
			display();
			_getch();
			return;
		}
	}
	if (mark == 0)
	{
		printf("\n\t\t 没有找到联系人，按任意键返回主菜单");
		_getch();
		return;
	}
}

void reviseWithNum()
{
	int mark = 0;
	int n;
	char number[10];
	printf("\n\t\t***********************按照学号查找***************");
	printf("n\t\t 请输入要查找的学号：");
	scanf("%s", number);
	for (n = 0; n<i; n++)
	{
		if (strcmp(stu[n].num, number) == 0)
		{
			printf("\n\t\t***************以下是查询结果***************");
			printf("\n\t\t 学号: %s", stu[n].num);
			printf("\n\t\t 姓名: %s", stu[n].name);
			printf("\n\t\t 电话: %s", stu[n].tele);
			printf("\n\t\t 地址: %s", stu[n].add);
			printf("\n\t\t eMail: %s", stu[n].email);
			printf("\n\t\t***************请输入新的结果*****************");
			printf("\n\t\t 输入学号:");
			scanf("%s", stu[n].num);
			printf("\n\t\t 输入姓名:");
			scanf("%s", stu[n].name);
			printf("\n\t\t 输入电话:");
			scanf("%s", stu[n].tele);
			printf("\n\t\t 输入地址:");
			scanf("%s", stu[n].add);
			printf("\n\t\t 输入eMail:");
			scanf("%s", stu[n].email);
			mark++;
			printf("\n\t\t***************显示新的通讯录*****************");
			display();
			_getch();
			return;
		}
	}
	if (mark == 0)
	{
		printf("\n\t\t 没有找到联系人，按任意键返回主菜单");
		_getch();
		return;
	}
}

