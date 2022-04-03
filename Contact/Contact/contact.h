#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_SIZE 1000 // ͨѶ¼�������
#define NAME_MAX 10   // �����������
#define SEX_MAX  5    // �Ա��������
#define TELE_MAX 12   // �绰�������
#define ADDR_MAX 30   // ��ַ�������

// ���Ͷ���
enum Option
{
	EXIT,   // 0
	ADD,    // 1
	DEL,    // 2
	SEARCH, // 3
	MODIFY,	// 4
	PRINT,  // 5
	REMOVE, // 6
	SORT    // 7
};

// ��ϵ�˵���Ϣ
typedef struct PeoInfo
{
	char name[NAME_MAX]; // ����
	int age;			 // ����
	char sex[SEX_MAX];   // �Ա�
	char tele[TELE_MAX]; // �绰
	char addr[ADDR_MAX]; // סַ
} PeoInfo;


// ͨѶ¼
typedef struct contact
{
	PeoInfo data[MAX_SIZE]; // �����ӽ������˵���Ϣ
	int sz; // ��¼���ǵ�ǰͨѶ¼����Ч��Ϣ�ĸ���
} contact; 


// ��������

// ��ʼ��ͨѶ¼
void InitContact(contact* pc);

// ������ϵ��
void AddContact(contact* pc);

// ɾ����ϵ��
void DelContact(contact* pc);

// ����ָ����ϵ��
void SearchContact(const contact* pc);

// �޸�ָ����ϵ��
void ModifyContact(contact* pc);

// ��ӡ��ϵ����Ϣ
void PrintContact(const contact* pc);

// �����ϵ��
void RemoveContact(contact* pc);

// ����
void SortContact(contact* pc);