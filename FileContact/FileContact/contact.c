#include "contact.h"

void CheckCapacity(contact* pc)
{
	// ����
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
		printf("���ݳɹ�\n");
	}
}

// ����
void LoadContact(contact* pc)
{
	// ���ļ�
	FILE* pf = fopen("contact.dat", "rb");
	if (pf == NULL)
	{
		perror("LoadContact::fopen");
		return;
	}
	// ������
	PeoInfo tmp;
	while (fread(&tmp, sizeof(PeoInfo), 1, pf) > 0) 
	{
		CheckCapacity(pc);
		pc->data[pc->sz++] = tmp;
	}
	// �ر��ļ�
	fclose(pf);
	pf = NULL;
}

// ��ʼ��ͨѶ¼ - �ļ��İ汾
void InitContact(contact* pc)
{
	assert(pc); // ���Ա�ָ֤�벻Ϊ��	 
	pc->sz = 0;
	pc->capacity = DEFAULT_SZ;
	pc->data = (PeoInfo*)malloc(sizeof(PeoInfo) * pc->capacity);
	if (pc->data == NULL)
	{
		perror("InitContact::malloc");
		return;
	}
	LoadContact(pc); // ��������
}

// ����ͨѶ¼
void DestroyContact(contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->sz = 0;
	pc->capacity = 0;

	printf("���ٳɹ�\n");
}

//  ������ϵ��
void AddContact(contact* pc)
{
	assert(pc); // ���Ա�ָ֤�벻Ϊ��

	CheckCapacity(pc); // ����Ƿ���Ҫ����	

	// ����һ���˵���Ϣ
	printf("����������:>");
	scanf("%s", pc->data[pc->sz].name);
	printf("����������:>");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("�������Ա�:>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("������绰:>");
	scanf("%s", pc->data[pc->sz].tele);
	printf("�������ַ:>");
	scanf("%s", pc->data[pc->sz].addr);

	pc->sz++;
	printf("��ӳɹ�\n");
}

// ͨ�����ֲ��ң�ָ����ϵ��
// �ҵ��˷��ض�Ӧ�±�
// �Ҳ������� -1
static int FindByName(const contact* pc, char name[])
{
	assert(pc);
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0) // �Ƚ����������Ƿ���ͬ
		{
			return i; // �ҵ��ˣ������±�
		}
	}
	return -1; // �Ҳ���
}

// ɾ����ϵ��
void DelContact(contact* pc)
{
	assert(pc);
	char name[NAME_MAX] = { 0 };
	printf("������Ҫɾ���˵�����:>");
	scanf("%s", name);
	// ����Ҫɾ������ϵ��
	int pos = FindByName(pc, name);
	// û���ҵ�
	if (pos == -1)
	{
		printf("Ҫɾ�����˲�����\n");
		return;
	}
	// �ҵ��ˣ�ɾ��
	int i = 0;
	for (i = pos; i < pc->sz - 1; i++)
	{
		pc->data[i] = pc->data[i + 1]; // �Ӻ���ǰ����
	}

	pc->sz--;
	printf("ɾ���ɹ�\n");
}

// �޸�ָ����ϵ��
void ModifyContact(contact* pc)
{
	assert(pc);
	char name[NAME_MAX] = { 0 };
	printf("������Ҫ�޸��˵�����:>");
	scanf("%s", name);
	// ����Ҫ�޸ĵ���ϵ��
	int pos = FindByName(pc, name);
	// û���ҵ�
	if (pos == -1)
	{
		printf("Ҫ�޸ĵ��˲�����\n");
		return;
	}

	// ѯ��Ҫ��ʲô	
	printf("������Ҫ�޸�ʲô��Ϣ (1-���֣�2-���䣬3-�Ա�4-�绰��5-��ַ):>");
	int msg = 0;
	scanf("%d", &msg);
	switch (msg)
	{
	case 1:
		printf("�������µ�����:>");
		scanf("%s", pc->data[pos].name);
		break;
	case 2:
		printf("�������µ�����:>");
		scanf("%d", &(pc->data[pos].age));
		break;
	case 3:
		printf("�������µ��Ա�:>");
		scanf("%s", pc->data[pos].sex);
		break;
	case 4:
		printf("�������µĵ绰:>");
		scanf("%s", pc->data[pos].tele);
		break;
	case 5:
		printf("�������µĵ�ַ:>");
		scanf("%s", pc->data[pos].addr);
		break;
	default:
		printf("��������޸�ʧ��\n");
		return;
		break;
	}

	printf("�޸ĳɹ�\n");
}

// ����ָ����ϵ��
void SearchContact(const contact* pc)
{
	assert(pc);
	char name[NAME_MAX];
	printf("������Ҫ�����˵�����:>");
	scanf("%s", name);
	// ����ָ������ϵ��
	int pos = FindByName(pc, name);
	// û���ҵ�
	if (pos == -1)
	{
		printf("Ҫ���ҵ��˲�����\n");
		return;
	}
	// �ҵ��ˣ���ӡ
	printf("%-15s %-5s %-5s %-11s %-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	printf("%-15s %-5d %-5s %-11s %-30s\n",
		pc->data[pos].name,
		pc->data[pos].age,
		pc->data[pos].sex,
		pc->data[pos].tele,
		pc->data[pos].addr);
}

// ��ӡ��ϵ����Ϣ
void PrintContact(const contact* pc)
{
	assert(pc);
	int i = 0;
	// ��ӡ����
	printf("%-15s %-5s %-5s %-11s %-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	// ��ӡ��¼
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

// �����ϵ��
void RemoveContact(contact* pc)
{
	assert(pc);
	free(pc->data);
	pc->data = NULL;
	InitContact(pc);
}

// ����������
static int cmp_name(const void* e1, const void* e2)
{
	if (strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name) > 0)
		return 1;
	else if (strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name) < 0)
		return -1;
	else
		return 0;
}

// ����������
static int cmp_age(const void* e1, const void* e2)
{
	return ((PeoInfo*)e1)->age - ((PeoInfo*)e1)->age;
}

// ���Ա�����
static int cmp_sex(const void* e1, const void* e2)
{
	if (strcmp(((PeoInfo*)e1)->sex, ((PeoInfo*)e2)->sex) > 0)
		return 1;
	else if (strcmp(((PeoInfo*)e1)->sex, ((PeoInfo*)e2)->sex) < 0)
		return -1;
	else
		return 0;
}

// ���绰����
static int cmp_tele(const void* e1, const void* e2)
{
	if (strcmp(((PeoInfo*)e1)->tele, ((PeoInfo*)e2)->tele) > 0)
		return 1;
	else if (strcmp(((PeoInfo*)e1)->tele, ((PeoInfo*)e2)->tele) < 0)
		return -1;
	else
		return 0;
}

// ����ַ����
static int cmp_addr(const void* e1, const void* e2)
{
	if (strcmp(((PeoInfo*)e1)->addr, ((PeoInfo*)e2)->addr) > 0)
		return 1;
	else if (strcmp(((PeoInfo*)e1)->addr, ((PeoInfo*)e2)->addr) < 0)
		return -1;
	else
		return 0;
}

// ��ָ����Ϣ����
void SortContact(contact* pc)
{
	assert(pc);
	int input = 0;
	// ����ָ�����飬�洢��Ӧ��������ĺ���ָ��
	int(*p[])(const void*, const void*) = { 0, cmp_name, cmp_age, cmp_sex, cmp_tele, cmp_addr };
	printf("��������Ҫ��ʲô���� (1-���֣�2-���䣬3-�Ա�4-�绰��5-��ַ):>");
	scanf("%d", &input);

	if (input >= 1 && input <= 5)
	{
		qsort(pc->data, pc->sz, sizeof(pc->data[0]), p[input]);
		PrintContact(pc); // ��ӡ��ʾ����
	}
	else
	{
		printf("ѡ�����\n");
		return;
	}
}

// ����ͨѶ¼
void SaveContact(const contact* pc)
{
	// ���ļ�
	FILE* pf = fopen("contact.dat", "wb");
	if (pf == NULL)
	{
		perror("SaveContact::fopen");
		return;
	}
	// д���ļ�
	fwrite(pc->data, sizeof(PeoInfo), pc->sz, pf);
	// �ر��ļ�
	fclose(pf);
	pf = NULL;
}