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

typedef int Status;

typedef struct Queuenode
{
	BiTNode* datas;      //队列中存放树结点指针
	struct Queuenode* next;
}Queuenode;

typedef struct LinkQueue
{
	int length;
	Status isInitial;
	struct Queuenode* front;
	struct Queuenode* rear;
}LinkQueue;

Status InitQueue(LinkQueue* Q);
Status QueueEmpty(LinkQueue* Q);
Status EnQueue(LinkQueue* Q, BiTNode* P);
Status DeQueue(LinkQueue* Q, BiTNode** P);
Status GetHead(LinkQueue* Q, BiTNode** P);