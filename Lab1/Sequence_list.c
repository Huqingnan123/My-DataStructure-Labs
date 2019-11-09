#include "Sequence_list.h"

SqList* ListArray;

int main()
{
	ListArray = (SqList*)malloc(LIST_INIT_SIZE * sizeof(SqList));    //���ڹ��������Ա�
	SqList *L = &ListArray[0];		//����Ҫ��ָ��L�����Ρ���ȥ����L��ָ��ַ�ϵ�ListArray[index]���Żᱣ������Ա�Ĳ���
	int index=1;   
	int option = 1, input_position;
	char filename[30];       
	ElemType element,pre_elment,next_element;
	while (option) 
	{
		system("cls");	
		printf("\n      Menu for Linear Table On Sequence Structure \n");
		printf("-------------------------------------------------------\n");
		printf("|    	  1.  InitList          8.  PriorElem	      |\n");
		printf("|    	  2.  DestroyList       9.  NextElem	      |\n");
		printf("|   	  3.  ClearList         10. ListInsert	      |\n");
		printf("|    	  4.  ListEmpty         11. ListDelete	      |\n");
		printf("|    	  5.  ListLength        12. ListTraverse      |\n");
		printf("|    	  6.  GetElem           13. InputFromFile     |\n");
		printf("|    	  7.  LocateElem        14. OutputToFile      |\n");
		printf("|    	  0. Exit               15. SelectList	      |\n");
		printf("-------------------------------------------------------\n");
		printf("\nDear users, you are operating the number %d list now!\n", index); printf("\n");
		printf("Please Select a function from [0--15] to operate:");
		scanf("%d", &option); 
		printf("\n");
		if (option == 0)
		{
			printf("Welcome to come back again!!!\n");
			return 0;
		}
		switch (option) {
		case 1:
			printf("You've chosen function InitList(), which initializes a list.\n");
			if (InitList(L) == OK)
				printf("Initialize a list successfully!\n");
			else
				printf("Failed to initialize a list or list has been initialized before!\n");
			getchar();
			break;
		case 2:
			printf("You've chosen function DestroyList(), which destroys a list.\n");
			if (DestroyList(L) == OK)
				printf("Destroy a list successfully!\n");
			else
				printf("Failed to destroy a list!\n");
			getchar();
			break;
		case 3:
			printf("You've chosen function ClearList(), which empties a list.\n");
			if (ClearList(L) == OK)
				printf("Clear a list successfully!\n");
			else
				printf("Failed to clear a list!\n");
			getchar();
			break;
		case 4:
			printf("You've chosen function ListEmpty(), which shows whether a list is empty.\n");
			if (ListEmpty(*L) == ERROR)
				printf("The list has not been initialized!\n");
			else if (ListEmpty(*L) == TRUE)
				printf("The list is empty!\n");
			else if (ListEmpty(*L) == FALSE)
				printf("The list is not empty!\n");
			getchar();
			break;
		case 5:
			printf("You've chosen function ListLength(), which shows the length of a list.\n");
			if (ListLength(*L) >= 0)
				printf("The length of list is %d!\n", ListLength(*L));
			else
				printf("Failed to get the length!\n");
			getchar();
			break;
		case 6:
			printf("You've chosen function GetElem(), which gets the specified element's value.\n");
			printf("Please input the index of the element:\n");
			if (!scanf("%d", &input_position)) {
				printf("Invalid value!\n");
				while (getchar() != '\n');
				break;
			}
			if (GetElem(*L, input_position, &element) == OK)
				printf("The value of this element is: %d\n", element);
			else
				printf("Failed to find!\n");
			getchar();
			break;
		case 7:
			printf("You've chosen function LocateElem(), which gets the specified element's index.\n");
			printf("Please input the value of the element:\n");
			if (!scanf("%d", &element)) 
			{
				printf("Invalid value!\n");
				while (getchar() != '\n');
				break;
			}
			if (LocateElem(*L, element) <= 0)            //ͨ������locate������֪Ԫ���Ƿ��ڱ���
				printf("This element doesn't exist!\n");
			else
				printf("The index of this element is: %d\n", LocateElem(*L, element));
			getchar();
			break;
		case 8:
			printf("You've chosen function PriorElem(), which gets the previous element of an element\n");
			printf("Please input the value of the element:\n");
			if (!scanf("%d", &element)) {
				printf("Invalid value!\n");
				while (getchar() != '\n');
				break;
			}
			if (PriorElem(*L, element, &pre_elment) == OK)
				printf("The previous element is: %d\n", pre_elment);
			else
				printf("This element doesn't have previous element!\n");
			getchar();
			break;
		case 9:
			printf("You've chosen function NextElem(), which gets the next element of an element.\n");
			printf("Please input the value of the element:\n");
			if (!scanf("%d", &element)) {
				printf("Invalid value!\n");
				while (getchar() != '\n');
				break;
			}
			if (NextElem(*L, element, &next_element) == OK)
				printf("The next element is: %d\n", next_element);
			else
				printf("This element doesn't have next element!\n");
			getchar();
			break;
		case 10:
			printf("You've chosen function ListInsert(), which inserts an element into a list.\n");
			printf("Please input the index of element to be inserted:\n");
			if (!scanf("%d", &input_position)) {
				printf("Invalid value!\n");
				while (getchar() != '\n');
				break;
			}
			printf("Please input the value of it:\n");
			if (!scanf("%d", &element)) {
				printf("Invalid value!\n");
				while (getchar() != '\n');
				break;
			}
			if (ListInsert(L, input_position, element) == OK)
				printf("Succeeded to insert element %d!\n", element);
			else
				printf("Failed to insert��Wrong position!\n this list hasn't been initialized!\n");
			getchar();
			break;
		case 11:
			printf("You've chosen function ListDelete(), which deletes an element from a list.\n");
			printf("Please input the index of element to be deleted:\n");
			if (!scanf("%d", &input_position)) {
				printf("Invalid value!\n");
				while (getchar() != '\n');
				break;
			}
			if (ListDelete(L, input_position, &element) == OK)
				printf("Succeed to delete element %d\n", element);
			else
				printf("Failed to delete!\n");
			getchar();
			break;
		case 12:
			printf("You've chosen function ListTraverse(), which traverses a list.\n");
			if (ListTraverse(L) != OK)
				printf("Failed to traverse!\n");
			else
				printf("Succeed to traverse this list\n");
			getchar();
			break;
		case 13:
			printf("You've chosen function InputFromFile(), which load datas from file to list.\n");
			printf("Please input your filename: ");
			scanf("%s", filename);
			if (InputFromFile(filename, L))
				printf("Input from file successfully\n");
			else
				printf("Failed to input!\n");
			getchar();
			break;
		case 14:
			printf("You've chosen function OutputToFile(), which write datas from list to file.\n");
			printf("Please input your filename: ");
			scanf("%s", filename);
			if (OutputToFile(filename, *L))
				printf("Output to file successfully\n");
			else
				printf("Failed to output!\n");
			getchar();
			break;
		case 15:
			printf("You've chosen function SelectList(), which chooses another list to operate.\n\n");
			printf("Please input a number between 1-100: ");
			scanf("%d", &index);
			getchar();
			SelectList(&L, index);      //�������Ӧ���������Ҫ&L������������Lʵ�������ã�����ָ�룩
			break;
		default:
			printf("You entered an invalid value!\n");
			getchar();
			break;
		}
		printf("\nPress Enter key to go back to menu...\n");
		while (getchar() != '\n');
	}
	return 0;
}

Status InitList(SqList* L)		//����һ���пռ���Ԫ�ص����Ա�
{
	L->elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L->elem)
		exit(OVERFLOW);
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
	return OK;
}

Status DestroyList(SqList* L)	//����ʼ���������Ա�ռ��ͷţ����ݻ�ԭΪ0  
{
	if (!L->elem)
		return OK;
	free(L->elem);
	L->elem = NULL;
	L->length = 0;
	L->listsize = 0;
	return OK;
}

Status ClearList(SqList* L)		//����ǰ���Ա���Ԫ����գ������ع��ʼ��
{
	if (!L->elem)
		exit(ERROR);
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
	return OK;
}

Status ListEmpty(SqList L)		//�жϵ�ǰ���Ա��Ƿ�Ϊ��
{
	if (!L.elem)
	{
		printf("This list hasn't been initialized!\n");
		exit(ERROR);
	}
	if (L.length == 0)
		return TRUE;
	else
		return FALSE;
}

int ListLength(SqList L)		//���ص�ǰ���Ա�ĳ���
{
	if (!L.elem)
		exit(ERROR);
	return L.length;
}

Status GetElem(SqList L, int i, ElemType* e)	//��ȡ��ǰ���Ա��i��λ���ϵ�Ԫ��	
{
	if (!L.elem)
		exit(ERROR);
	if (i > L.length)
		exit(OVERFLOW);
	*e = L.elem[i - 1];
	return OK;
}

Status LocateElem(SqList L, ElemType e)	//���ҵ�������ֵԪ��ֵΪe��Ԫ��λ�ã�û�ҵ����򷵻�FALSE
{
	if (!L.elem)
		exit(ERROR);
	int i = 1;
	while (i <= L.length && !compare(L.elem[i - 1], e))
		i++;
	if (i != (L.length + 1))
		return i;
	else
		return FALSE;
}

Status PriorElem(SqList L, ElemType cur_e, ElemType* pre_e)    //���غϷ���cur_e֮ǰ��Ԫ��
{
	if (!L.elem)
		exit(ERROR);
	int return_number = LocateElem(L, cur_e);
	if (return_number && return_number != 1)
	{
		*pre_e = L.elem[return_number - 2];
		return OK;
	}
	else
		return FALSE;
}

Status NextElem(SqList L, ElemType cur_e, ElemType* next_e)		//���غϷ���cur_e֮���Ԫ��
{
	if (!L.elem)
		exit(ERROR);
	int return_number = LocateElem(L, cur_e);
	if (return_number && return_number != L.length)
	{
		*next_e = L.elem[return_number];
		return OK;
	}
	else
		return FALSE;
}

Status ListInsert(SqList* L, int i, ElemType e)     //�ڵ�i��λ��֮ǰ����һ��Ԫ�أ�ԭ���ĵ�i�����Ժ��Ԫ��˳�κ���
{
	if (!L->elem)
		exit(ERROR);
	if (i<1 || i>ListLength(*L) + 1)  //iֵ���Ϸ�
		return ERROR;
	if (L->length >= L->listsize)     //��Ҫ���ӿռ�
	{
		ElemType* newbase;
		newbase = (ElemType*)realloc(L->elem, (L->listsize + LIST_INCREMENT) * sizeof(ElemType));
		if (!newbase)
			exit(OVERFLOW);
		L->elem = newbase;           //�»�ַnewbase
		L->listsize += LIST_INCREMENT;
	}
	ElemType* position = &L->elem[i - 1];
	for (ElemType* last = &L->elem[L->length - 1]; position <= last; last--)	//�����һ��Ԫ�ص���i��Ԫ����������ƶ�һ��
		* (last + 1) = *last;
	*position = e;
	L->length++;
	return OK;
}

Status ListDelete(SqList* L, int i, ElemType* e)     //ɾ��λ�ڵ�i��λ���ϵ�Ԫ�ز���e������ֵ
{
	if (!L->elem && L->length != 0)
		exit(ERROR);
	if (i<1 || i>L->length)
		return ERROR;
	ElemType* position = &L->elem[i - 1];
	*e = *position;
	for (ElemType* last = &L->elem[L->length - 1]; position <= last - 1; position++)
		* position = *(position + 1);                //��i��λ��֮���Ԫ��˳��ǰ��
	L->length--;  
	return OK;
}

Status ListTraverse(SqList* L)			//�������Ա��ÿ��Ԫ�ص���visit
{
	printf("\n-----------all elements -----------------------\n");
	for (int i = 0; i < L->length; i++)
		visit(L->elem[i]);
	printf("\n------------------ end ------------------------\n");
	return L->length;
}

Status InputFromFile(char* filename, SqList* L)      //���ļ��ж�ȡ���ݴ��浽���Ա�ṹ��
{
	InitList(L);
	FILE* fp;
	if ((fp = fopen(filename, "r")) == NULL)
	{
		printf("Open Error!\n");
		return ERROR;
	}
	while (fscanf(fp, "%d ", &L->elem[L->length])!=EOF)   //һ��һ�����ݴ��ļ�����
		L->length++;
	fclose(fp);
	return OK;
}

Status OutputToFile(char* filename, SqList L)		//�����Ա�ṹ��Ԫ������������ļ���
{	
	FILE* fp;
	if ((fp = fopen(filename, "w")) == NULL)
	{
		printf("Open Error!");
		return ERROR;
	}
	for(int i=0;i<=L.length-1;i++)
		fprintf(fp,"%d ", L.elem[i]);     //��L��Ԫ��һ��һ��������ļ�
	fclose(fp);
	return OK;
}

Status visit(ElemType e)
{
	printf("%d ", e);
	return TRUE;
}

Status compare(ElemType e, ElemType temp)
{
	if (e == temp)
		return TRUE;
	else
		return FALSE;
}

Status SelectList(SqList **L,int index)		//����ѡ������ڼ������Ա���ʱ��ѡ���л�
{
	*L = &ListArray[index-1];
	return TRUE;
}
