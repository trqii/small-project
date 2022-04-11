#include "contact.h"

void CheckCapacity(contact* pc)
{
	// 增容
	if (pc->sz == pc->capacity)
	{
		PeoInfo* tmp = (PeoInfo*)realloc(pc->data, sizeof(PeoInfo) * (pc->capacity + 2));
		if (tmp == NULL)
		{
			perror("CheckCapacity::reallc");
			return;
		}

		pc->data = tmp;
		pc->capacity += 2;
		printf("增容成功\n");
	}
}

// 载入
void LoadContact(contact* pc)
{
	// 打开文件
	FILE* pf = fopen("contact.dat", "rb");
	if (pf == NULL)
	{
		perror("LoadContact::fopen");
		return;
	}
	// 读数据
	PeoInfo tmp;
	while (fread(&tmp, sizeof(PeoInfo), 1, pf) > 0) 
	{
		CheckCapacity(pc);
		pc->data[pc->sz++] = tmp;
	}
	// 关闭文件
	fclose(pf);
	pf = NULL;
}

// 初始化通讯录 - 文件的版本
void InitContact(contact* pc)
{
	assert(pc); // 断言保证指针不为空	 
	pc->sz = 0;
	pc->capacity = DEFAULT_SZ;
	pc->data = (PeoInfo*)malloc(sizeof(PeoInfo) * pc->capacity);
	if (pc->data == NULL)
	{
		perror("InitContact::malloc");
		return;
	}
	LoadContact(pc); // 载入数据
}

// 销毁通讯录
void DestroyContact(contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->sz = 0;
	pc->capacity = 0;

	printf("销毁成功\n");
}

//  增加联系人
void AddContact(contact* pc)
{
	assert(pc); // 断言保证指针不为空

	CheckCapacity(pc); // 检查是否需要增容	

	// 增加一个人的信息
	printf("请输入名字:>");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入年龄:>");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("请输入性别:>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入电话:>");
	scanf("%s", pc->data[pc->sz].tele);
	printf("请输入地址:>");
	scanf("%s", pc->data[pc->sz].addr);

	pc->sz++;
	printf("添加成功\n");
}

// 通过名字查找，指定联系人
// 找到了返回对应下标
// 找不到返回 -1
static int FindByName(const contact* pc, char name[])
{
	assert(pc);
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0) // 比较两个名字是否相同
		{
			return i; // 找到了，返回下标
		}
	}
	return -1; // 找不到
}

// 删除联系人
void DelContact(contact* pc)
{
	assert(pc);
	char name[NAME_MAX] = { 0 };
	printf("请输入要删除人的名字:>");
	scanf("%s", name);
	// 查找要删除的联系人
	int pos = FindByName(pc, name);
	// 没有找到
	if (pos == -1)
	{
		printf("要删除的人不存在\n");
		return;
	}
	// 找到了，删除
	int i = 0;
	for (i = pos; i < pc->sz - 1; i++)
	{
		pc->data[i] = pc->data[i + 1]; // 从后往前覆盖
	}

	pc->sz--;
	printf("删除成功\n");
}

// 修改指定联系人
void ModifyContact(contact* pc)
{
	assert(pc);
	char name[NAME_MAX] = { 0 };
	printf("请输入要修改人的名字:>");
	scanf("%s", name);
	// 查找要修改的联系人
	int pos = FindByName(pc, name);
	// 没有找到
	if (pos == -1)
	{
		printf("要修改的人不存在\n");
		return;
	}

	// 询问要改什么	
	printf("请输入要修改什么信息 (1-名字，2-年龄，3-性别，4-电话，5-地址):>");
	int msg = 0;
	scanf("%d", &msg);
	switch (msg)
	{
	case 1:
		printf("请输入新的名字:>");
		scanf("%s", pc->data[pos].name);
		break;
	case 2:
		printf("请输入新的年龄:>");
		scanf("%d", &(pc->data[pos].age));
		break;
	case 3:
		printf("请输入新的性别:>");
		scanf("%s", pc->data[pos].sex);
		break;
	case 4:
		printf("请输入新的电话:>");
		scanf("%s", pc->data[pos].tele);
		break;
	case 5:
		printf("请输入新的地址:>");
		scanf("%s", pc->data[pos].addr);
		break;
	default:
		printf("输入错误，修改失败\n");
		return;
		break;
	}

	printf("修改成功\n");
}

// 查找指定联系人
void SearchContact(const contact* pc)
{
	assert(pc);
	char name[NAME_MAX];
	printf("请输入要查找人的名字:>");
	scanf("%s", name);
	// 查找指定的联系人
	int pos = FindByName(pc, name);
	// 没有找到
	if (pos == -1)
	{
		printf("要查找的人不存在\n");
		return;
	}
	// 找到了，打印
	printf("%-15s %-5s %-5s %-11s %-30s\n", "名字", "年龄", "性别", "电话", "地址");
	printf("%-15s %-5d %-5s %-11s %-30s\n",
		pc->data[pos].name,
		pc->data[pos].age,
		pc->data[pos].sex,
		pc->data[pos].tele,
		pc->data[pos].addr);
}

// 打印联系人信息
void PrintContact(const contact* pc)
{
	assert(pc);
	int i = 0;
	// 打印标题
	printf("%-15s %-5s %-5s %-11s %-30s\n", "名字", "年龄", "性别", "电话", "地址");
	// 打印记录
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-15s %-5d %-5s %-11s %-30s\n",
			pc->data[i].name,
			pc->data[i].age,
			pc->data[i].sex,
			pc->data[i].tele,
			pc->data[i].addr);
	}
}

// 清空联系人
void RemoveContact(contact* pc)
{
	assert(pc);
	free(pc->data);
	pc->data = NULL;
	InitContact(pc);
}

// 按名字升序
static int cmp_name(const void* e1, const void* e2)
{
	if (strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name) > 0)
		return 1;
	else if (strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name) < 0)
		return -1;
	else
		return 0;
}

// 按年龄升序
static int cmp_age(const void* e1, const void* e2)
{
	return ((PeoInfo*)e1)->age - ((PeoInfo*)e1)->age;
}

// 按性别升序
static int cmp_sex(const void* e1, const void* e2)
{
	if (strcmp(((PeoInfo*)e1)->sex, ((PeoInfo*)e2)->sex) > 0)
		return 1;
	else if (strcmp(((PeoInfo*)e1)->sex, ((PeoInfo*)e2)->sex) < 0)
		return -1;
	else
		return 0;
}

// 按电话升序
static int cmp_tele(const void* e1, const void* e2)
{
	if (strcmp(((PeoInfo*)e1)->tele, ((PeoInfo*)e2)->tele) > 0)
		return 1;
	else if (strcmp(((PeoInfo*)e1)->tele, ((PeoInfo*)e2)->tele) < 0)
		return -1;
	else
		return 0;
}

// 按地址升序
static int cmp_addr(const void* e1, const void* e2)
{
	if (strcmp(((PeoInfo*)e1)->addr, ((PeoInfo*)e2)->addr) > 0)
		return 1;
	else if (strcmp(((PeoInfo*)e1)->addr, ((PeoInfo*)e2)->addr) < 0)
		return -1;
	else
		return 0;
}

// 按指定信息排序
void SortContact(contact* pc)
{
	assert(pc);
	int input = 0;
	// 函数指针数组，存储对应用于排序的函数指针
	int(*p[])(const void*, const void*) = { 0, cmp_name, cmp_age, cmp_sex, cmp_tele, cmp_addr };
	printf("请输入您要按什么排序 (1-名字，2-年龄，3-性别，4-电话，5-地址):>");
	scanf("%d", &input);

	if (input >= 1 && input <= 5)
	{
		qsort(pc->data, pc->sz, sizeof(pc->data[0]), p[input]);
		PrintContact(pc); // 打印显示出来
	}
	else
	{
		printf("选择错误\n");
		return;
	}
}

// 保存通讯录
void SaveContact(const contact* pc)
{
	// 打开文件
	FILE* pf = fopen("contact.dat", "wb");
	if (pf == NULL)
	{
		perror("SaveContact::fopen");
		return;
	}
	// 写入文件
	fwrite(pc->data, sizeof(PeoInfo), pc->sz, pf);
	// 关闭文件
	fclose(pf);
	pf = NULL;
}