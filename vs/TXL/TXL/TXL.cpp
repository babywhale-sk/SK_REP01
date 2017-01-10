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
	printf("\n\t********************��ӭʹ��ͨѶ¼����ϵͳ *****************");
	printf("\n\t***************************���˵�**************************");
	printf("\n\t\t\t\t0:����ͨѶ¼");
	printf("\n\t\t\t\t1:��ʾͨѶ¼");
	printf("\n\t\t\t\t2:ɾ��ͨѶ¼");
	printf("\n\t\t\t\t3:����ͨѶ¼");
	printf("\n\t\t\t\t4:�޸�ͨѶ¼");
	printf("\n\t\t\t\t5:���ͨѶ¼");
	printf("\n\t\t\t\t6:�˳�ͨѶ¼");
	printf("\n\t\t\t\t������ѡ��0-6");
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
		printf("\n\t\t �Ѿ�����ͨѶ¼����");
		_getch();
		return;
	}
	printf("\n\t\t ************************��¼���ѧ����Ϣ*********************");
	printf("\n\t\t ����ѧ��:");
	scanf("%s", stu[i].num);
	printf("\n\t\t ��������:");
	scanf("%s", stu[i].name);
	printf("\n\t\t ����绰:");
	scanf("%s", stu[i].tele);
	printf("\n\t\t �����ַ:");
	scanf("%s", stu[i].add);
	printf("\n\t\t ����eMail:");
	scanf("%s", stu[i].email);
	i++;
	printf("\n\t\t �Ƿ����������ϵ�ˣ�(Y/N)");
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
		printf("\n\t\t******************ϵͳƴ��ͨѶ¼��ϵ����Ϣ*********************");
		for (n = 0; n<i; n++)
		{
			printf("\n\t\t ********************NO. %d****************", n);
			printf("\n--");
			Sleep(200);
			printf("---");
			Sleep(200);
			printf("----");
			Sleep(200);
			printf("\n\t\t ѧ��: %s", stu[n].num);
			printf("\n\t\t ����: %s", stu[n].name);
			printf("\n\t\t �绰: %s", stu[n].tele);
			printf("\n\t\t ��ַ: %s", stu[n].add);
			printf("\n\t\t eMail: %s", stu[n].email);
			printf("\n\t\t ******************************************");

		}

	}
	else
		printf("\n\t\tͨѶ¼��û���κμ�¼,��������������˵�");
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
		printf("\n\t\t ************************�Ѿ�����洢����*********************");
		_getch();
		return;
	}
	printf("\n\t\t ************************��������Ҫ��ӵ�ѧ��ѧ��*********************");
	printf("\n\t\t ������ѧ�� �� ");
	scanf("%s", number);
	for (n = 0; n<i; n++)
	{
		if (strcmp(stu[n].num, number) == 0)
		{
			printf("\n\t\t  ��ѧ����Ϣ�Ѿ��������֤");
			_getch();
			return;
		}
		else
		{
			strcpy(stu[n].num, number);
			printf("\n\t\t ��������:");
			scanf("%s", stu[n].name);
			printf("\n\t\t ����绰:");
			scanf("%s", stu[n].tele);
			printf("\n\t\t �����ַ:");
			scanf("%s", stu[n].add);
			printf("\n\t\t ����eMail:");
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
	printf("\n\t\t****************ɾ��ѧ����¼****************");
	printf("\n\t\t|     1-��������ɾ��	   2-����ѧ��ɾ��	|");
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
	printf("\n\t\t***********************��������ɾ��ѧ����¼***************");
	printf("n\t\t ������Ҫ���ҵ�������");
	scanf("%s", name);
	for (n = 0; n<i; n++)
	{
		if (strcmp(stu[n].name, name) == 0)
		{
			printf("\n\t\t***************�����ǲ�ѯ���***************");
			printf("\n\t\t ѧ��: %s", stu[n].num);
			printf("\n\t\t ����: %s", stu[n].name);
			printf("\n\t\t �绰: %s", stu[n].tele);
			printf("\n\t\t ��ַ: %s", stu[n].add);
			printf("\n\t\t eMail: %s", stu[n].email);
			printf("\n\t\t******************�������ɾ��*************************");
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
		printf("\n\t\t û���ҵ���ϵ�ˣ���������������˵�");
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
	printf("\n\t\t***********************����ѧ��ɾ��ѧ����¼***************");
	printf("n\t\t ������Ҫ���ҵ�ѧ�ţ�");
	scanf("%s", number);
	for (n = 0; n<i; n++)
	{
		if (strcmp(stu[n].num, number) == 0)
		{
			printf("\n\t\t***************�����ǲ�ѯ���***************");
			printf("\n\t\t ѧ��: %s", stu[n].num);
			printf("\n\t\t ����: %s", stu[n].name);
			printf("\n\t\t �绰: %s", stu[n].tele);
			printf("\n\t\t ��ַ: %s", stu[n].add);
			printf("\n\t\t eMail: %s", stu[n].email);
			printf("\n\t\t******************�������ɾ��*************************");
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
		printf("\n\t\t û���ҵ���ϵ�ˣ���������������˵�");
		_getch();
		return;
	}
}
void find()
{
	char c;
	system("cls");
	printf("\n\t\t***************��ʾ�Ͳ�ѯѧ����Ϣ***********");
	printf("\n\t\t|     1-������������	   2-����ѧ�Ų���	|");
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
	printf("\n\t\t***********************������������***************");
	printf("n\t\t ������Ҫ���ҵ�������");
	scanf("%s", name);
	for (n = 0; n<i; n++)
	{
		if (strcmp(stu[n].name, name) == 0)
		{
			printf("\n\t\t***************�����ǲ�ѯ���***************");
			printf("\n\t\t ѧ��: %s", stu[n].num);
			printf("\n\t\t ����: %s", stu[n].name);
			printf("\n\t\t �绰: %s", stu[n].tele);
			printf("\n\t\t ��ַ: %s", stu[n].add);
			printf("\n\t\t eMail: %s", stu[n].email);
			printf("\n\t\t*******************************************");
			mark++;
			_getch();
			return;
		}
	}
	if (mark == 0)
	{
		printf("\n\t\t û���ҵ���ϵ�ˣ���������������˵�");
		_getch();
		return;
	}
}


void findWithNum()
{
	int mark = 0;
	int n;
	char number[10];
	printf("\n\t\t***********************����ѧ�Ų���***************");
	printf("n\t\t ������Ҫ���ҵ�ѧ�ţ�");
	scanf("%s", number);
	for (n = 0; n<i; n++)
	{
		if (strcmp(stu[n].num, number) == 0)
		{
			printf("\n\t\t***************�����ǲ�ѯ���***************");
			printf("\n\t\t ѧ��: %s", stu[n].num);
			printf("\n\t\t ����: %s", stu[n].name);
			printf("\n\t\t �绰: %s", stu[n].tele);
			printf("\n\t\t ��ַ: %s", stu[n].add);
			printf("\n\t\t eMail: %s", stu[n].email);
			printf("\n\t\t*******************************************");
			mark++;
			_getch();
			return;
		}
	}
	if (mark == 0)
	{
		printf("\n\t\t û���ҵ���ϵ�ˣ���������������˵�");
		_getch();
		return;
	}
}
void revise()
{
	char c;
	system("cls");
	printf("\n\t\t***************��ʾ�Ͳ�ѯѧ����Ϣ***********");
	printf("\n\t\t|     1-�����������Ҳ��޸�	   2-����ѧ�Ų��Ҳ��޸�	|");
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
	printf("\n\t\t***********************������������***************");
	printf("n\t\t ������Ҫ���ҵ�������");
	scanf("%s", name);
	for (n = 0; n<i; n++)
	{
		if (strcmp(stu[n].name, name) == 0)

		{
			printf("\n\t\t***************�����ǲ�ѯ���***************");
			printf("\n\t\t ѧ��: %s", stu[n].num);
			printf("\n\t\t ����: %s", stu[n].name);
			printf("\n\t\t �绰: %s", stu[n].tele);
			printf("\n\t\t ��ַ: %s", stu[n].add);
			printf("\n\t\t eMail: %s", stu[n].email);
			printf("\n\t\t***************�������µĽ��*****************");
			printf("\n\t\t ����ѧ��:");
			scanf("%s", stu[n].num);
			printf("\n\t\t ��������:");
			scanf("%s", stu[n].name);
			printf("\n\t\t ����绰:");
			scanf("%s", stu[n].tele);
			printf("\n\t\t �����ַ:");
			scanf("%s", stu[n].add);
			printf("\n\t\t ����eMail:");
			scanf("%s", stu[n].email);
			mark++;
			printf("\n\t\t***************��ʾ�µ�ͨѶ¼*****************");
			display();
			_getch();
			return;
		}
	}
	if (mark == 0)
	{
		printf("\n\t\t û���ҵ���ϵ�ˣ���������������˵�");
		_getch();
		return;
	}
}

void reviseWithNum()
{
	int mark = 0;
	int n;
	char number[10];
	printf("\n\t\t***********************����ѧ�Ų���***************");
	printf("n\t\t ������Ҫ���ҵ�ѧ�ţ�");
	scanf("%s", number);
	for (n = 0; n<i; n++)
	{
		if (strcmp(stu[n].num, number) == 0)
		{
			printf("\n\t\t***************�����ǲ�ѯ���***************");
			printf("\n\t\t ѧ��: %s", stu[n].num);
			printf("\n\t\t ����: %s", stu[n].name);
			printf("\n\t\t �绰: %s", stu[n].tele);
			printf("\n\t\t ��ַ: %s", stu[n].add);
			printf("\n\t\t eMail: %s", stu[n].email);
			printf("\n\t\t***************�������µĽ��*****************");
			printf("\n\t\t ����ѧ��:");
			scanf("%s", stu[n].num);
			printf("\n\t\t ��������:");
			scanf("%s", stu[n].name);
			printf("\n\t\t ����绰:");
			scanf("%s", stu[n].tele);
			printf("\n\t\t �����ַ:");
			scanf("%s", stu[n].add);
			printf("\n\t\t ����eMail:");
			scanf("%s", stu[n].email);
			mark++;
			printf("\n\t\t***************��ʾ�µ�ͨѶ¼*****************");
			display();
			_getch();
			return;
		}
	}
	if (mark == 0)
	{
		printf("\n\t\t û���ҵ���ϵ�ˣ���������������˵�");
		_getch();
		return;
	}
}

