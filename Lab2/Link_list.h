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

typedef int ElemType;	  //元素类型定义
typedef int Status;

typedef struct Linknode   //每个子链表中的结点
{
	ElemType data;
	struct Linknode* next;
}Linknode;

typedef struct Linklist    //子链表内部结构
{
	int ID;
	int length;			//length表示该子链表内有多少个结点
	Status isInitial;   //isInitial表示是否被初始化过
	struct Linknode* head;
}Linklist;

Status InitList(Linklist* L);
Status DestroyList(Linklist* L);
Status ClearList(Linklist* L);
Status ListEmpty(Linklist L);
Status ListLength(Linklist L);
Status GetElem(Linklist L, int i, ElemType* e);
Status LocateElem(Linklist L, ElemType e);
Status PriorElem(Linklist L, ElemType cur_e, ElemType* pre_e);
Status NextElem(Linklist L, ElemType cur_e, ElemType* next_e);
Status ListInsert(Linklist* L, int i, ElemType e);
Status ListDelete(Linklist* L, int i, ElemType* e);
Status ListTraverse(Linklist* L);
Status InputFromFile(char* filename, Linklist* L);
Status OutputToFile(char* filename, Linklist L);
Status visit(ElemType e);
Status compare(ElemType temp, ElemType e);
Status SelectList(Linklist** L, int index);

