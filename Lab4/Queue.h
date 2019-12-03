#pragma once
#include "Graph.h"

typedef int Status;

typedef struct Queuenode
{
	Vertex* data;      //队列中存放图顶点指针
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