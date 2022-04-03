#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_SIZE 1000 // 通讯录最大容量
#define NAME_MAX 10   // 名字最大容量
#define SEX_MAX  5    // 性别最大容量
#define TELE_MAX 12   // 电话最大容量
#define ADDR_MAX 30   // 地址最大容量

// 类型定义
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

// 联系人的信息
typedef struct PeoInfo
{
	char name[NAME_MAX]; // 名字
	int age;			 // 年龄
	char sex[SEX_MAX];   // 性别
	char tele[TELE_MAX]; // 电话
	char addr[ADDR_MAX]; // 住址
} PeoInfo;


// 通讯录
typedef struct contact
{
	PeoInfo data[MAX_SIZE]; // 存放添加进来的人的信息
	int sz; // 记录的是当前通讯录中有效信息的个数
} contact; 


// 函数声明

// 初始化通讯录
void InitContact(contact* pc);

// 增加联系人
void AddContact(contact* pc);

// 删除联系人
void DelContact(contact* pc);

// 查找指定联系人
void SearchContact(const contact* pc);

// 修改指定联系人
void ModifyContact(contact* pc);

// 打印联系人信息
void PrintContact(const contact* pc);

// 清空联系人
void RemoveContact(contact* pc);

// 排序
void SortContact(contact* pc);