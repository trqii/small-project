#include "contact.h"

// ��ӡ�˵�
void menu()
{
	printf("*****************************\n");
	printf("***** 1.add    2.del    *****\n");
	printf("***** 3.search 4.modify *****\n");
	printf("***** 5.print  6.remove *****\n");
	printf("***** 7.sort   0.exit   *****\n");
	printf("*****************************\n");
}

void test()
{
	int input = 0;
	// ����ͨѶ¼
	contact con;
	// ��ʼ��ͨѶ¼
	InitContact(&con);
	do
	{
		menu(); // ��ӡ�˵�
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con); // ��
			break;
		case DEL:
			DelContact(&con); // ɾ	
			break;
		case SEARCH:
			SearchContact(&con); // ��
			break;
		case MODIFY:
			ModifyContact(&con); // ��
			break;
		case PRINT:
			PrintContact(&con); // ��ʾ
			break;
		case REMOVE: 
			RemoveContact(&con); // ���
			break;
		case SORT:
			SortContact(&con); // ����
			break;
		case EXIT:
			DestroyContact(&con); // ����
			printf("�˳�ͨѶ¼\n");
			break;
		default: 
			printf("ѡ�����\n");
			break;
		}

	} while (input);
}	

int main()
{
	test();
	return 0;
}