#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BinaryTree.h"

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define INFEASIBLE -2
#define UNINITIAL -3
#define BiTree_INIT_SIZE 100
#define BiTree_INCREMENT 10

typedef struct BiTNode* SElemtype;
typedef int Status;

typedef struct Stacknode
{
	SElemtype data;      //栈中存放树结点指针
	struct Stacknode* next;
}Stacknode;

typedef struct LinkStack
{
	int length;
	Status isInitial;
	struct Stacknode* Top;
}LinkStack;

Status InitStack(LinkStack* S);
Status StackEmpty(LinkStack* S);
Status Push(LinkStack* S, BiTNode* P);
Status Pop(LinkStack* S, BiTNode* P);
Status GetTop(LinkStack* S, BiTNode** P);