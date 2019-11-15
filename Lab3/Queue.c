#include "Queue.h"
#include "BinaryTree.h"

Status InitQueue(LinkQueue* Q)
{
	Q->length = 0;
	Q->isInitial = TRUE;
	Q->front = (Queuenode*)malloc(sizeof(Queuenode));
	Q->rear = (Queuenode*)malloc(sizeof(Queuenode));
	Q->front = Q->rear;
	Q->front->next = NULL;                          //���ö���ͷ��㣨������Ϊ�գ�
	Q->rear->next = NULL;
}
Status QueueEmpty(LinkQueue* Q)
{
	if (Q->isInitial != TRUE)
		return UNINITIAL;         //δ��ʼ���Ĵ�����ʾ
	if (Q->length == 0)
		return TRUE;
	else
		return FALSE;
}
Status EnQueue(LinkQueue* Q, BiTNode* P)	//���½����Ϊ����β��㣬����
{
	if (Q->isInitial != TRUE)
		return UNINITIAL;
	Queuenode* new_node = (Queuenode*)malloc(sizeof(Queuenode));
	if (!new_node)
		exit(OVERFLOW);
	new_node->datas = P;
	new_node->next = NULL;
	Q->rear->next = new_node;
	Q->rear = new_node;
	Q->length++;
	return OK;
}
Status DeQueue(LinkQueue* Q, BiTNode** P)
{
	if (Q->isInitial != TRUE)
		return UNINITIAL;
	Queuenode* Temp_ptr = (Queuenode*)malloc(sizeof(Queuenode));
	(*P) = (BiTNode*)malloc(sizeof(BiTNode));
	Temp_ptr = Q->front->next;
	if (Temp_ptr == NULL)			//�����г�ͷ�ڵ����Ѿ�Ϊ��ʱ(��front==rearʱ�������ܽ��г��Ӳ���
		exit(OVERFLOW);
	Q->front->next = Q->front->next->next;

	(*P)->data = Temp_ptr->datas->data;
	strcpy((*P)->key, Temp_ptr->datas->key);	//��ȫ���ƣ���ֹTemp_ptr��free�����ݶ�ʧ
	(*P)->lchild = Temp_ptr->datas->lchild;
	(*P)->rchild = Temp_ptr->datas->rchild;

	if (Q->rear == Temp_ptr)    //��������ֻ�������һ�������������ʱ����Ҫ�ǵ��޸�rearָ���ֵΪfront����ֹβָ��rear��ʧ������
		Q->rear = Q->front;       
	free(Temp_ptr);
	Q->length--;
	return OK;
}
Status GetHead(LinkQueue* Q, BiTNode** P)
{
	if (!Q->isInitial)
		return UNINITIAL;
	if (Q->front == Q->rear)
		return ERROR;
	*P = Q->front->next->datas;       //ȡ��������Ԫ����ڵ�ָ��ֵ����*p
	return OK;
}