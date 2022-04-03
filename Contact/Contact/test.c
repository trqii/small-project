#include "contact.h"

// 打印菜单
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
	// 创建通讯录
	contact con;	
	// 初始化通讯录
	InitContact(&con);	
	do
	{ 
		menu(); // 打印菜单
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case PRINT:
			PrintContact(&con);
			break;
		case REMOVE:
			RemoveContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case EXIT:
			printf("退出通讯录\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}

	} while (input);
}

int main()
{
	test();
	return 0;
}