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
			AddContact(&con); // 增
			break;
		case DEL:
			DelContact(&con); // 删	
			break;
		case SEARCH:
			SearchContact(&con); // 查
			break;
		case MODIFY:
			ModifyContact(&con); // 改
			break;
		case PRINT:
			PrintContact(&con); // 显示
			break;
		case REMOVE: 
			RemoveContact(&con); // 清除
			break;
		case SORT:
			SortContact(&con); // 排序
			break;
		case EXIT:
			DestroyContact(&con); // 销毁
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