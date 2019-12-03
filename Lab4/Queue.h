#pragma once
#include "Graph.h"

typedef int Status;

typedef struct Queuenode
{
	Vertex* data;      //�����д��ͼ����ָ��
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
Status EnQueue(LinkQueue* Q, Vertex* v);
Status DeQueue(LinkQueue* Q, Vertex** v);
Status GetHead(LinkQueue* Q, Vertex** v);