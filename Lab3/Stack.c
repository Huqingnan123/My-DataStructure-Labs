#include "Stack.h"
#include "BinaryTree.h"

Status InitStack(LinkStack* S)
{
	S->length = 0;
	S->isInitial = TRUE;
	S->Top = NULL;			//并未设置空的头顶结点
}
Status StackEmpty(LinkStack* S)
{
	if (S->isInitial != TRUE)
		return UNINITIAL;         //未初始化的错误提示
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
	Temp_ptr->next = S->Top;       //将新结点作为栈顶结点，压栈
	S->Top = Temp_ptr;
	S->length++;
	return OK;
}
Status Pop(LinkStack* S, BiTNode** P)
{
	if (S->isInitial != TRUE)
		return UNINITIAL;
	Stacknode* Temp_ptr = S->Top;
	if (Temp_ptr == NULL)         //当栈已经为空时，不能Pop
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
	*P = S->Top->data;       //取出栈顶结点内的指针值赋给*p
	return OK;
}