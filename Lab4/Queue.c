#include "Queue.h"

Status InitQueue(LinkQueue* Q)
{
	Q->length = 0;
	Q->isInitial = TRUE;
	Q->front = (Queuenode*)malloc(sizeof(Queuenode));
	Q->rear = (Queuenode*)malloc(sizeof(Queuenode));
	Q->front = Q->rear;
	Q->front->next = NULL;                          //设置队列头结点（数据域为空）
	Q->rear->next = NULL;
}
Status QueueEmpty(LinkQueue* Q)
{
	if (Q->isInitial != TRUE)
		return UNINITIAL;         //未初始化的错误提示
	if (Q->length == 0)
		return TRUE;
	else
		return FALSE;
}
Status EnQueue(LinkQueue* Q, Vertex* v)	//将新结点作为队列尾结点，进队
{
	if (Q->isInitial != TRUE)
		return UNINITIAL;
	Queuenode* new_node = (Queuenode*)malloc(sizeof(Queuenode));
	if (!new_node)
		exit(OVERFLOW);
	new_node->data = v;
	new_node->next = NULL;
	Q->rear->next = new_node;
	Q->rear = new_node;
	Q->length++;
	return OK;
}
Status DeQueue(LinkQueue* Q, Vertex** v)
{
	if (Q->isInitial != TRUE)
		return UNINITIAL;
	Queuenode* Temp_ptr = (Queuenode*)malloc(sizeof(Queuenode));
	Temp_ptr = Q->front->next;
	if (Temp_ptr == NULL)			//当队列除头节点外已经为空时(即front==rear时），不能进行出队操作
		exit(OVERFLOW);
	Q->front->next = Q->front->next->next;

	(*v)->key = Temp_ptr->data->key;	//完全复制，防止Temp_ptr被free后数据丢失
	(*v)->value = Temp_ptr->data->value;

	if (Q->rear == Temp_ptr)    //当队列中只存在最后一个结点的特殊情况时，还要记得修改rear指针的值为front，防止尾指针rear丢失！！！
		Q->rear = Q->front;       
	free(Temp_ptr);
	Q->length--;
	return OK;
}
Status GetHead(LinkQueue* Q, Vertex** v)
{
	if (!Q->isInitial)
		return UNINITIAL;
	if (Q->front == Q->rear)
		return ERROR;
	*v = Q->front->next->data;       //取出队列首元结点内的指针值赋给*v
	return OK;
}