#include "Stack.h"
#include "BinaryTree.h"

Status InitStack(LinkStack* S)
{
	S->length = 0;
	S->isInitial = TRUE;
	S->Top = NULL;			//��δ���ÿյ�ͷ�����
}
Status StackEmpty(LinkStack* S)
{
	if (S->isInitial != TRUE)
		return UNINITIAL;         //δ��ʼ���Ĵ�����ʾ
	if (S->length == 0)
		return TRUE;
	else
		return FALSE;
}
Status Push(LinkStack* S, BiTNode* P)
{
	if (S->isInitial != TRUE)
		return UNINITIAL;
	Stacknode* Temp_ptr = (Stacknode*)malloc(sizeof(Stacknode));
	if (!Temp_ptr)
		exit(OVERFLOW);
	Temp_ptr->data = P;
	Temp_ptr->next = S->Top;       //���½����Ϊջ����㣬ѹջ
	S->Top = Temp_ptr;
	S->length++;
	return OK;
}
Status Pop(LinkStack* S, BiTNode** P)
{
	if (S->isInitial != TRUE)
		return UNINITIAL;
	Stacknode* Temp_ptr = S->Top;
	if (Temp_ptr == NULL)         //��ջ�Ѿ�Ϊ��ʱ������Pop
		return OVERFLOW;
	S->Top = S->Top->next;
	*P = Temp_ptr->data;
	free(Temp_ptr);
	S->length--;
	return OK;
}
Status GetTop(LinkStack* S, BiTNode** P)
{
	if (!S->isInitial)
		return UNINITIAL;
	if (S->Top == NULL)
		return ERROR;
	*P = S->Top->data;       //ȡ��ջ������ڵ�ָ��ֵ����*p
	return OK;
}