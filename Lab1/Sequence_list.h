#pragma once
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define LIST_INIT_SIZE 100
#define LIST_INCREMENT 10
#define OVERFLOW -2

typedef int ElemType;    //元素类型定义
typedef int Status;

typedef struct list
{
	ElemType* elem;
	int length;
	int listsize;
}SqList;

Status InitList(SqList* L);
Status DestroyList(SqList* L);
Status ClearList(SqList* L);
Status ListEmpty(SqList L);
int ListLength(SqList L);
Status GetElem(SqList L, int i, ElemType* e);
Status LocateElem(SqList L, ElemType e);
Status PriorElem(SqList L, ElemType cur_e, ElemType* pre_e);
Status NextElem(SqList L, ElemType cur_e, ElemType* next_e);
Status ListInsert(SqList* L, int i, ElemType e);
Status ListDelete(SqList* L, int i, ElemType* e);
Status ListTraverse(SqList* L);
Status InputFromFile(char* filename, SqList* L);
Status OutputToFile(char* filename, SqList L);
Status visit(ElemType e);
Status compare(ElemType temp, ElemType e);
Status SelectList(SqList** L, int index);
