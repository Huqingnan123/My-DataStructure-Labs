#include "Link_list.h"

int index = 1;
Linklist* ListArray;  //用于存放各个子链表的基址指针

int main()
{
	ListArray = (Linklist*)malloc(LIST_INIT_SIZE * sizeof(Linklist));    //用于管理多个线性表(只存放各个链表的基址指针）
	Linklist* L = &ListArray[0];		//必须要用指针L“传参”，去操作L所指地址上的ListArray[index]，才会保存后续对表的操作
	L->isInitial = FALSE;
	int option = 1, input_position;
	char filename[30];
	ElemType element, pre_element, next_element;
	while (option)
	{
		system("cls");
		printf("\n      Menu for Linear Table On Linklist Structure \n");
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
				printf("Failed to destroy an uninitialized list!\n");        //当链表未初始化时执行销毁操作，则会提示操作错误！
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
			if (ListEmpty(*L) == FALSE)
				printf("The list is not empty!\n");
			else
				printf("The list is empty!\n");
			getchar();
			break;
		case 5:
			printf("You've chosen function ListLength(), which shows the length of a list.\n");
			if (L->isInitial == FALSE)
				printf("Failed to get the length of this uninitialized list!\n");
			else if(ListLength(*L) >= 0)
				printf("The length of list is %d!\n", ListLength(*L));
			getchar();
			break;
		case 6:
			printf("You've chosen function GetElem(), which gets the specified element's value.\n");
			printf("Please input the index of the element:\n");
			if (!scanf("%d", &input_position)) {            //输入想要获取第几个元素
				printf("Invalid value!\n");
				while (getchar() != '\n');
				break;
			}
			if (GetElem(*L, input_position, &element) == OK)
				printf("The value of this element is: %d\n", element);
			else
				printf("Failed to find!\n");              //当未找到时，提示Failed to find
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
			if (L->isInitial == FALSE)
				printf("ERROR!This List has not been initialized!\n");
			if (LocateElem(*L, element) <= 0)					//通过调用LocateElem函数得知元素是否在表中
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
			if (L->isInitial == FALSE)
				printf("ERROR!This List has not been initialized!\n");
			if (PriorElem(*L, element, &pre_element) == OK)
				printf("The previous element is: %d\n", pre_element);
			else if(LocateElem(*L, element) > 0)                 //获取前驱元素失败的原因有两种，其一为输入元素为首元素，其二为输入元素不在链表中
				printf("This element doesn't have previous element!\n");
			else if (LocateElem(*L, element) <= 0)				 
				printf("This element doesn't exist in this list!\n");
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
			if (L->isInitial == FALSE)
				printf("ERROR!This List has not been initialized!\n");
			if (NextElem(*L, element, &pre_element) == OK)
				printf("The next element is: %d\n", next_element);
			else if (LocateElem(*L, element) > 0)				//获取后继元素失败的原因有两种，其一为输入元素为末尾元素，其二为输入元素不在链表中
				printf("This element doesn't have next element!\n");
			else if (LocateElem(*L, element) <= 0)
				printf("This element doesn't exist in this list!\n");
			getchar();
			break;
		case 10:
			printf("You've chosen function ListInsert(), which inserts an element into a list.\n");
			if (L->isInitial == FALSE)
				printf("ERROR!This List has not been initialized!\n");
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
			else if (ListInsert(L, input_position, element) == ERROR)       //当未初始化时执行插入操作，则ERROR
				printf("Failed to insert, this list hasn't been initialized!\n");
			else if (ListInsert(L, input_position, element) == OVERFLOW)	//当输入位置不合法时。则OVERFLOW
				printf("Failed to insert, this position is wrong!\n");
			getchar();
			break;
		case 11:
			printf("You've chosen function ListDelete(), which deletes an element from a list.\n");
			if (L->isInitial == FALSE)
				printf("ERROR!This List has not been initialized!\n");
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
			if (L->isInitial == FALSE)
				printf("ERROR!This List has not been initialized!STOP!\n");
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
			printf("Please input a number [1-100] to select a list to operate,if you input a bigger number,it's OK: ");
			scanf("%d", &index);
			getchar();
			SelectList(&L, index);      //与上面对应，这里必须要&L，才能真正对L实参起作用（二级指针）
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

Status InitList(Linklist* L)		//初始化L所指向的子链表
{
	L->ID = index;
	L->length = 0;
	L->isInitial = TRUE;
	L->head = NULL;					//head指向当前子链表的第一个结点
	return OK;
}

Status DestroyList(Linklist* L)		//将L指向的子链表中的所有结点空间释放,并将L->isInitial置为FALSE
{
	if (!L->isInitial)
		return ERROR;
	Linknode* Currentnode = L->head;
	while (Currentnode != NULL)
	{
		Linknode* Tempnode = Currentnode;
		Currentnode = Currentnode->next;
		free(Tempnode);
	}
	L->length = 0;
	L->isInitial = FALSE;
	return OK;
}

Status ClearList(Linklist* L)		//将L指向的子链表中的所有结点空间释放,最后L指向的子链表为空链表 
{
	if (!L->isInitial)
		return ERROR;
	Linknode* Currentnode = L->head;
	while (Currentnode != NULL)
	{
		Linknode* Tempnode = Currentnode;
		Currentnode = Currentnode->next;
		free(Tempnode);
	}
	L->length = 0;
	L->head = NULL;
	return OK;
}

Status ListEmpty(Linklist L)		//判断当前子链表是否为空
{
	if (!L.isInitial)
	{
		printf("This list hasn't been initialized!\n");
		exit(ERROR);
	}
	if (L.length == 0)
		return TRUE;
	else
		return FALSE;
}

Status ListLength(Linklist L)		//返回当前子链表的长度
{
	if (!L.isInitial)
		return ERROR;
	else
		return L.length;
}

Status GetElem(Linklist L, int i, ElemType* e)	//获取当前子链表第i个结点上的元素值	
{
	if (!L.isInitial)
		return ERROR;
	if (i > L.length)
		return(OVERFLOW);
	Linknode* Currentnode = L.head;
	while (i > 1)
	{
		Currentnode = Currentnode->next;
		i--;
	}
	*e = Currentnode->data;
	return OK;
}

Status LocateElem(Linklist L, ElemType e)	//若找到，返回值元素值为e的元素位置，没找到，则返回FALSE
{
	if (!L.isInitial)
		return ERROR;
	Linknode* Currentnode = L.head;
	int i = 1;
	while (i <= L.length && !compare(Currentnode->data, e))
	{
		Currentnode = Currentnode->next;
		i++;
	}
	if (i <= L.length)
		return i;
	else
		return FALSE;
}

Status PriorElem(Linklist L, ElemType cur_e, ElemType* pre_e)    //返回合法的cur_e之前的结点内的元素值
{
	if (!L.isInitial)
		return ERROR;
	int return_number = LocateElem(L, cur_e);
	if (return_number && return_number != 1)
	{
		Linknode* Currentnode = L.head;
		while (Currentnode->next->data != cur_e)
			Currentnode = Currentnode->next;
		*pre_e = Currentnode->data;
		return OK;
	}
	else
		return FALSE;
}

Status NextElem(Linklist L, ElemType cur_e, ElemType* next_e)		//返回合法的cur_e之后的结点内的元素值
{
	if (!L.isInitial)
		return ERROR;
	int return_number = LocateElem(L, cur_e);
	if (return_number && return_number != L.length)
	{
		Linknode* Currentnode = L.head;
		while (Currentnode->data != cur_e)
			Currentnode = Currentnode->next;
		*next_e = Currentnode->next->data;
		return OK;
	}
	else
		return FALSE;
}

Status ListInsert(Linklist* L, int i, ElemType e)     //在第i个结点之前插入一个内部元素值为e的结点
{
	if (!L->isInitial)
		return ERROR;
	if (i<1 || i>ListLength(*L) + 1)  //i值不合法
		return OVERFLOW;
	Linknode* prevnode = L->head;
	Linknode* newnode = (Linknode*)malloc(sizeof(Linknode));
	if (i == 1)                       //当插在第一个位置时，直接被头指针指向
	{
		newnode->data = e;
		Linknode* tempnode = L->head;
		L->head = newnode;
		newnode->next = tempnode;
	}
	else                              ////当插在中间位置时，找出前驱结点prevnode，进行插入操作
	{
		for (int number = 1; number < i - 1; number++)
			prevnode = prevnode->next;
		newnode->data = e;
		Linknode* tempnode = prevnode->next;
		prevnode->next = newnode;
		newnode->next = tempnode;
	}
	L->length++;
	return OK;
}

Status ListDelete(Linklist* L, int i, ElemType* e)     //删除位于第i个位置上的结点并用e返回结点内data值
{
	if (!L->isInitial || L->length == 0)
		return ERROR;
	if (i<1 || i>L->length)
		return ERROR;
	Linknode* prevnode = L->head;
	if (i == 1)
	{
		Linknode* Tempnode = L->head;
		*e = Tempnode->data;
		L->head = L->head->next;
		free(Tempnode);
	}
	else
	{
		for (int number = 1; number < i - 1; number++)
			prevnode = prevnode->next;					   //找出需要删除结点的前驱结点，进行删除操作
		Linknode* Tempnode = prevnode->next;
		*e = Tempnode->data;
		prevnode->next = prevnode->next->next;
		free(Tempnode);
	}
	L->length--;
	return OK;
}

Status ListTraverse(Linklist* L)			//遍历线性表对每个元素调用visit
{
	if (!L->isInitial)
		return ERROR;
	Linknode* Tempnode = L->head;
	printf("\n-----------all elements -----------------------\n");
	while (Tempnode)
	{
		visit(Tempnode->data);
		Tempnode = Tempnode->next;
	}
	printf("\n------------------ end ------------------------\n");
	return OK;
}

Status InputFromFile(char* filename, Linklist* L)      //从文件中读取数据储存到线性表结构中
{
	if (!L->isInitial)
		InitList(L);
	L->head =(Linknode*)malloc(sizeof(Linknode));	   //给头指针先分配一定空间
	Linknode* Tempnode = L->head;
	Linknode* prevnode=NULL;
	FILE* fp;
	if ((fp = fopen(filename, "r")) == NULL)
	{
		printf("Open Error!\n");
		return ERROR;
	}
	while (fscanf(fp, "%d ", &Tempnode->data) != EOF)    //一个一个数据从文件读入
	{
		Linknode* newnode = (Linknode*)malloc(sizeof(Linknode));     //继续创造新结点添加到链表末尾
		Tempnode->next = newnode;
		prevnode = Tempnode;
		Tempnode=newnode;
		L->length++;
	} 
	free(prevnode->next);
	prevnode->next = NULL;		//当最后读取数据失败，则要free最后一个加上去的newnode，将之前记住的prevnode->next赋为NULL
	fclose(fp);
	return OK;
}

Status OutputToFile(char* filename, Linklist L)		//将当前子链表中每个结点中元素依次输出到文件中
{
	if (!L.isInitial)
		return ERROR;
	Linknode* Tempnode = L.head;
	FILE* fp;
	if ((fp = fopen(filename, "w")) == NULL)
	{
		printf("Open Error!");
		return ERROR;
	}
	while(Tempnode)
	{
		fprintf(fp, "%d ", Tempnode->data);     //将L中元素一个一个输出到文件
		Tempnode = Tempnode->next;
	}
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

Status SelectList(Linklist** L, int index)		//用于选择操作第几个线性表，随时可选择切换
{
	if (index>LIST_INIT_SIZE)     //需要增加空间
	{
		Linklist* newListArray;
		newListArray = (Linklist *)realloc(ListArray, (LIST_INIT_SIZE + LIST_INCREMENT) * sizeof(Linklist));
		if (!newListArray)
			return OVERFLOW;
		ListArray = newListArray;           //新的父链表ListArray
	}
	*L = &ListArray[index - 1];
	(*L)->ID = index;
	if ((*L)->isInitial != TRUE)
	{
		(*L)->isInitial = FALSE;
		(*L)->head = NULL;
	}
	return TRUE;
}
