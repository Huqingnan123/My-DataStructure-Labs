#include "BinaryTree.h"
#include "Stack.h"
#include "Queue.h"

int index = 1;
BiTree* TreeArray;
char Preorder_key[BITNODE_INIT_SIZE][20];
int Preorder_data[BITNODE_INIT_SIZE];
char e[20], e_c[20];
TElemtype value;

int main()
{
	TreeArray = (BiTree*)malloc(BITREE_INIT_SIZE * sizeof(BiTree));    //用于管理多个树(只存放各个树的基址指针）
	BiTree* T = &TreeArray[0];					//必须要用指针T“传参”，去操作T所指地址上的TreeArray[index]，才会保存后续对表的操作
	T->isInitial = FALSE;
	int option = 1, input_position, LR;
	char filename1[30], filename2[30], filename3[30];
	BiTNode* c = (BiTNode*)malloc(sizeof(BiTNode));
	while (option)
	{
		system("cls");
		printf("\n      Menu for Binary Tree On Link Structure \n");
		printf("-------------------------------------------------------\n");
		printf("|    	 1.  InitTree          10. GetSibling	      |\n");
		printf("|    	 2.  CreateBiTree      11. InsertNode	      |\n");
		printf("|   	 3.  DestroyBiTree     12. DeleteNode	      |\n");
		printf("|    	 4.  ClearBiTree       13. PreOrderTraverse   |\n");
		printf("|    	 5.  BiTreeEmpty       14. InOrderTraverse    |\n");
		printf("|    	 6.  BiTreeDepth       15. PostOrderTraverse  |\n");
		printf("|    	 7.  LocateNode        16. LevelOrderTraverse |\n");
		printf("|    	 8.  Assign            17. InputFromFile      |\n");
		printf("|    	 9.  Get_Parent        18. OutputToFile       |\n");
		printf("|    	 0.  Exit              19. SelectTree	      |\n");
		printf("-------------------------------------------------------\n");
		printf("\nDear users, you are operating the number %d Tree now!\n", index); printf("\n");
		printf("Please Select a function from [0--15] to operate:");
		scanf("%d", &option);
		printf("\n");
		int i = 0, j = 0;
		if (option == 0)
		{
			printf("Welcome to come back again!!!\n");
			return 0;
		}
		switch (option) {
		case 1:
			printf("You've chosen function InitTree(), which initializes a Tree.\n");
			if (InitTree(T) == OK)
				printf("Initialize a Tree successfully!\n");
			else
				printf("Failed to initialize a Tree!\n");
			getchar();
			break;
		case 2:
			printf("You've chosen function CreateBiTree(), which creates a tree in your definition.\n");
			printf("Please input your Preorder definition ('@' is a symbol of NULL): \n");
			while (scanf("%s", Preorder_key[i]) == 1 && (getchar()) != '\n')
				i++;
			printf("Please input your Preorder datas for every node: \n");
			while (scanf("%d", Preorder_data + j) == 1 && (getchar()) != '\n')     //读取的时候自动跳过空格符
				j++;
			T->number = j + 1;
			if (!T->isInitial)
			{
				printf("Failed! This tree has not been initialized!\n");
				break;
			}
			if (CreateBiTree(T, Preorder_key, Preorder_data) == OK)
				printf("Create a new tree constructed successfully!\n");
			else
				printf("Failed to Create a new tree!\n");
			break;
		case 3:
			printf("You've chosen function DestroyBiTree(), which destroys a tree.\n");
			if (DestroyBiTree(T) == OK)
				printf("Destroy this tree successfully!\n");
			else
				printf("Failed to destroy this tree!\n");
			getchar();
			break;
		case 4:
			printf("You've chosen function ClearBiTree(), which clears a tree's nodes.\n");
			if (ClearBiTree(T) == OK)
				printf("Clear this tree successfully!\n");
			else
				printf("Failed to clear this tree!\n");
			getchar();
			break;
		case 5:
			printf("You've chosen function BiTreeEmpty(), which shows whether this tree is empty.\n");
			if (BiTreeEmpty(*T) == UNINITIAL)
				printf("Failed! This tree has not been initialized!\n");
			else if (BiTreeEmpty(*T) == FALSE)
				printf("This tree is not empty!\n");
			else if (BiTreeEmpty(*T) == TRUE)
				printf("This tree is empty!\n");
			getchar();
			break;
		case 6:
			printf("You've chosen function BiTreeDepth(), which gets the depth of this tree.\n");
			if (T->isInitial == FALSE)
				printf("Failed to get the depth of this uninitialized tree!\n");
			else if (BiTreeDepth(*T) >= 0)
				printf("The depth of this tree is %d!\n", BiTreeDepth(*T));
			getchar();
			break;
		case 7:
			printf("You've chosen function LocateNode(), which gets the pointer of the node whose key is same as e.\n");
			printf("Please input the key of the node:\n");
			if (!scanf("%s", e))
			{
				printf("Invalid key!\n");
				while (getchar() != '\n');
				break;
			}
			if (T->isInitial == FALSE)
				printf("ERROR!This tree has not been initialized!\n");
			if (LocateNode(T, e) == NULL)
				printf("This node doesn't exist!\n");
			else
				printf("Find the node and return its pointer successfully! The pointer address is: %p , this node's data is %d.\n", LocateNode(T, e), LocateNode(T, e)->data);
			getchar();
			break;
		case 8:
			printf("You've chosen function Assign(), which assign value to the node whose key is same as e.\n");
			printf("Please input the key of the node:\n");
			if (!scanf("%s", e))
			{
				printf("Invalid key!\n");
				while (getchar() != '\n');
				break;
			}
			printf("Please input the value you want to assign:\n");
			scanf("%d", &value);
			if (Assign(T, e, value) == UNINITIAL)
				printf("ERROR!This tree has not been initialized!\n");
			if (Assign(T, e, value) == TRUE)
				printf("Assign value to specified node successfully!\n");
			else
				printf("Failed to assign!\n");
			getchar();
			break;
		case 9:
			printf("You've chosen function Get_Parent(), which gets the pointer of a parent node whose child's key is same as e.\n");
			printf("Please input the key of the node:\n");
			if (!scanf("%s", e))
			{
				printf("Invalid key!\n");
				while (getchar() != '\n');
				break;
			}
			if (T->isInitial == FALSE)
				printf("ERROR!This tree has not been initialized!\n");
			if (Get_Parent(T, e) == NULL)
				printf("This node whose key is e doesn't has parent!\n");
			else
				printf("Find its parent and return its parent's pointer successfully! Its parent's key is %s.\n", Get_Parent(T, e)->key);
			getchar();
			break;
		case 10:
			printf("You've chosen function GetSibling(), which gets the pointer of a node whose sibling's key is same as e.\n");
			printf("Please input the key of the node:\n");
			if (!scanf("%s", e))
			{
				printf("Invalid key!\n");
				while (getchar() != '\n');
				break;
			}
			if (T->isInitial == FALSE)
				printf("ERROR!This tree has not been initialized!\n");
			if (GetSibling(T, e) == NULL)
				printf("This node whose key is e doesn't has sibling!\n");
			else
				printf("Find its sibling and return its sibling's pointer successfully!Its Sibling's key is %s.\n", GetSibling(T, e)->key);
			getchar();
			break;
		case 11:
			printf("You've chosen function InsertNode(), which insert a node to this tree.\n");
			if (T->isInitial == FALSE)
				printf("ERROR!This List has not been initialized!\n");
			printf("Please input the key of the node you want to find:\n");
			if (!scanf("%s", e))
			{
				printf("Invalid key!\n");
				while (getchar() != '\n');
				break;
			}
			printf("Please input the \"key\", the \"data\" and the \"LR\" of the node you want to insert:\n");
			if (scanf("%s %d %d", e_c, &value, &LR) != 3)
			{
				printf("Invalid input!\n");
				while (getchar() != '\n');
				break;
			}
			if (InsertNode(T, e, LR, c) == OK)
				printf("Insert a node successfully!\n");
			else
				printf("Failed to insert!\n");
			getchar();
			break;
		case 12:
			printf("You've chosen function DeleteNode(), which deletes a node in this tree.\n");
			if (!T->isInitial)
				printf("ERROR!This List has not been initialized!\n");
			printf("Please input the key of the node:\n");
			if (!scanf("%s", e))
			{
				printf("Invalid key!\n");
				while (getchar() != '\n');
				break;
			}
			if (DeleteNode(T, e) == OK)
				printf("Delete this node successfully!\n");
			else
				printf("Failed to delete node whose key is same as e.");
			getchar();
			break;
		case 13:
			printf("You've chosen function PreOrderTrasverse(), which traverses this tree in preorder.");
			if (!T->isInitial)
				printf("ERROR!This List has not been initialized!\n");
			if (PreOrderTraverse(T, Visit) == OK)
				printf("Traversed in preorder successfully!\n");
			else
				printf("Failed to traverse.\n");
			getchar();
			break;
		case 14:
			printf("You've chosen function InOrderTrasverse(), which traverses this tree in inorder.");
			if (!T->isInitial)
				printf("ERROR!This List has not been initialized!\n");
			if (InOrderTraverse(T, Visit) == OK)
				printf("Traversed in inorder successfully!\n");
			else
				printf("Failed to traverse.\n");
			getchar();
			break;
		case 15:
			printf("You've chosen function PostOrderTrasverse(), which traverses this tree in postorder.");
			if (!T->isInitial)
				printf("ERROR!This List has not been initialized!\n");
			if (PostOrderTraverse(T, Visit) == OK)
				printf("Traversed in postorder successfully!\n");
			else
				printf("Failed to traverse.\n");
			getchar();
			break;
		case 16:
			printf("You've chosen function LevelOrderTrasverse(), which traverses this tree in levelorder.");
			if (!T->isInitial)
				printf("ERROR!This List has not been initialized!\n");
			if (LevelOrderTraverse(T, Visit) == OK)
				printf("Traversed in levelorder successfully!\n");
			else
				printf("Failed to traverse.\n");
			getchar();
			break;
		case 17:
			printf("You've chosen function InputFromFile(), which load keys and datas from file to create a tree.\n");
			printf("Please input your key's input-filename: ");
			scanf("%s", filename1);
			getchar();
			printf("Please input your data's input-filename: ");
			scanf("%s", filename2);
			if (InputFromFile(filename1, filename2, T))
				printf("Input from file successfully\n");
			else
				printf("Failed to input!\n");
			getchar();
			break;
		case 18:
			printf("You've chosen function OutputToFile(), which write keys and datas from tree to file.\n");
			if (T->isInitial == FALSE)
				printf("ERROR!This List has not been initialized!STOP!\n\n");
			printf("Please input your output-filename: ");
			scanf("%s", filename3);
			if (OutputToFile(filename3, T))
				printf("Output to file successfully\n");
			else
				printf("Failed to output!\n");
			getchar();
			break;
		case 19:
			printf("You've chosen function SelectTree(), which chooses another tree to operate.\n\n");
			printf("Please input a number [1-100] to select a tree to operate,if you input a bigger number,it's OK: ");
			scanf("%d", &index);
			getchar();
			SelectTree(&T, index);      //这里必须要&L，才能真正对T（树指针）起作用（二级指针）
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

Status InitTree(BiTree* T)
{
	T->ID = index;
	T->depth = 0;
	T->number = 0;
	T->isInitial = TRUE;      //将Initial设置为TRUE
	T->root = NULL;
	return OK;
}
Status CreateBiTree(BiTree* T, char(*Preorder_key)[20], int* Preorder_data)    //每个Preorder_key都指向一个容量为20个char的数组
{
	if (!T->isInitial)
		return UNINITIAL;
	CreateHelper(&(T->root), Preorder_key, Preorder_data);					//调用CreateHelper来帮助完成创建树
	return OK;
}
Status CreateHelper(BiTNode** P, char(*Preorder_key)[20], int* Preorder_data) //key_index和data_index是全局变量
{
	static int key_index = 0;
	static int data_index = 0;
	(*P) = (BiTNode*)malloc(sizeof(BiTNode));
	if (!(*P))
		exit(OVERFLOW);
	if (strcmp(Preorder_key[key_index], "@") == 0)							//当keyֵ为@时，将当前指针置空，只把key_index加一，data_index不变	
	{
		(*P) = NULL;
		key_index++;
	}
	else																//当key值不为@时，则可以对应着一个结点赋值
	{
		strcpy((*P)->key, Preorder_key[key_index]);
		(*P)->data = Preorder_data[data_index];
		key_index++;
		data_index++;
		CreateHelper(&((*P)->lchild), Preorder_key, Preorder_data);
		CreateHelper(&((*P)->rchild), Preorder_key, Preorder_data);	//然后再继续对左后孩子创建结构
	}
	if ((*P) != NULL && (*P)->data == Preorder_data[0])
	{
		key_index = 0;
		data_index = 0; 										//最后创建完成回到第一个根结点时，将两个index重新置0，便于下次的CreateBiTree
	}
	return OK;
}
Status DestroyBiTree(BiTree* T)
{
	if (!T->isInitial)
		return UNINITIAL;
	DestroyHelper(T->root);     //调用DestroyHelper来销毁
	T->isInitial = FALSE;		//将isInitial置为FALSE
	return OK;
}
Status DestroyHelper(BiTNode* P)
{
	if (P == NULL)      //如果P为空指针，则不用再销毁，return OK
		return OK;
	if (P->lchild)
		DestroyHelper(P->lchild);
	if (P->rchild)
		DestroyHelper(P->rchild);    //如果左右孩子不为空，继续对左右孩子调用DestroyHelper
	free(P);                         //将根结点free
	return OK;
}
Status ClearBiTree(BiTree* T)
{
	if (!T->isInitial)
		return UNINITIAL;
	DestroyHelper(T->root);    //ͬ与DestroyHelper逻辑相同，一步步进行free
	T->depth = 0;
	T->number = 0;
	T->root = NULL;           //但是不同的是，T->isInitial仍然TRUE
	return OK;
}
Status BiTreeEmpty(BiTree T)
{
	if (!T.isInitial)
		return UNINITIAL;
	if (T.root == NULL)		  //判断是否为空即判断根指针为空
		return TRUE;
	else
		return FALSE;
}
Status BiTreeDepth(BiTree T)
{
	if (!T.isInitial)
		return UNINITIAL;
	if (T.root == NULL)
		return 0;
	T.depth = DepthHelper(T.root);   //DepthHelper帮助递归调用
	return T.depth;
}
Status DepthHelper(BiTNode* P)
{
	if (P == NULL)
		return 0;
	int ldepth = DepthHelper(P->lchild);          //分别再对左右子树求深度
	int rdepth = DepthHelper(P->rchild);
	return (ldepth > rdepth ? ldepth : rdepth) + 1;
}
BiTNode* LocateNode(BiTree* T, char* e)
{
	if (!T->isInitial)
		exit(UNINITIAL);
	return LocateHelper(T->root, e);       //利用LocateHelper来实现递归调用
}
BiTNode* LocateHelper(BiTNode* P, char* e)
{
	if (P == NULL)
		return NULL;
	if (strcmp(P->key, e) == 0)							//如果key值成功匹配，那么直接返回当前P指针
		return P;
	BiTNode* Temp1 = LocateHelper(P->lchild, e);					//若当前结点没有成功匹配，则继续对左右孩子继续调用LocateHelper
	BiTNode* Temp2 = LocateHelper(P->rchild, e);
	if (Temp1 == NULL && Temp2 == NULL)
		return NULL;
	else
		return (Temp1 != NULL) ? Temp1 : Temp2;     //返回Temp1和Temp2中非空的那一个
}
Status Assign(BiTree* T, char* e, TElemtype value)
{
	if (!T->isInitial)
		return UNINITIAL;
	BiTNode* Temp = LocateHelper(T->root, e);         //先利用LocateHelper找到keyֵ为e的结点
	if (Temp == NULL)
		return ERROR;
	else
	{
		Temp->data = value;
		return OK;
	}
}
BiTNode* Get_Parent(BiTree* T, char* e)
{
	if (!T->isInitial)
		exit(UNINITIAL);
	if ((T->root != NULL && strcmp(T->root->key, e) == 0) || LocateNode(T, e) == NULL)  //当key值为e的结点是根节点或者树中不存在key值为e的结点
		return NULL;
	return Get_Parent_Helper(T->root, e);
}
BiTNode* Get_Parent_Helper(BiTNode* P, char* e)
{
	if (P == NULL)
		return NULL;
	if ((P->lchild != NULL && strcmp(P->lchild->key, e) == 0) || P->rchild != NULL && strcmp(P->rchild->key, e) == 0)
		return P;
	BiTNode* Temp1 = Get_Parent_Helper(P->lchild, e);
	BiTNode* Temp2 = Get_Parent_Helper(P->rchild, e);
	return (Temp1 != NULL) ? Temp1 : Temp2;				//当key值为e的结点存在且在分支中时，Temp1和Temp2必有一个非空
}
BiTNode* GetSibling(BiTree* T, char* e)
{
	if (!T->isInitial)
		return UNINITIAL;
	BiTNode* Temp1 = Get_Parent(T, e);				//先用Get_Parent找到key值为e的结点的父节点，即可找兄弟结点
	if (Temp1 == NULL)								//当key值为e的结点没有父结点时，一定没有兄弟结点
		return NULL;
	else if (strcmp(Temp1->lchild->key, e) == 0)
		return (Temp1->rchild ? Temp1->rchild : NULL);
	else if (strcmp(Temp1->rchild->key, e) == 0)
		return (Temp1->lchild ? Temp1->lchild : NULL);
}
Status InsertNode(BiTree* T, char* e, int LR, BiTNode* c)
{
	if (!T->isInitial)
		return UNINITIAL;
	c = (BiTNode*)malloc(sizeof(BiTNode));            //插入结点时注意分配新的空间给新增结点，以防数据丢失
	c->data = value;
	strcpy(c->key, e_c);
	c->lchild = NULL;
	c->rchild = NULL;
	if (T->root == NULL)
	{
		T->root = (BiTNode*)malloc(sizeof(BiTNode));
		T->root = c;
	}
	else
	{
		BiTNode* Temp = LocateNode(T, e);           //先利用LocateNode求到key值为e的结点的位置
		if (Temp == NULL)
			return ERROR;
		else if (LR == 0)                     //当找到key值为e的结点之后，再看LR的值来决定创建插去哪一边
		{
			if (Temp->lchild == NULL)
			{
				Temp->lchild = (BiTNode*)malloc(sizeof(BiTNode));
				Temp->lchild = c;
			}
			else
			{
				c->rchild = Temp->lchild;
				Temp->lchild = c;
			}
		}
		else if (LR == 1)
		{
			if (Temp->rchild == NULL)
			{
				Temp->rchild = (BiTNode*)malloc(sizeof(BiTNode));         //传入的参数为c结点副本，复制c中数据到新增加的结点中
				Temp->rchild = c;
			}
			else
			{
				c->rchild = Temp->rchild;
				Temp->rchild = c;
			}
		}
	}
	T->number++;
	return OK;
}
Status DeleteNode(BiTree* T, char* e)
{
	if (!T->isInitial)
		return UNINITIAL;
	BiTNode* Temp = LocateNode(T, e);					//利用LocateNode找到key值为e的结点
	if (T->root == NULL)
		return ERROR;
	else
	{
		if (Temp == T->root)									  //当需要删除根结点的特殊情形
		{
			if (Temp->lchild == NULL && Temp->rchild == NULL)     //度为0时
			{
				free(Temp);
				T->root = NULL;
				return OK;                                        //每次free之后记得直接return
			}
			if (Temp->lchild == NULL && Temp->rchild != NULL)	  //度为1时且为右孩子时
			{
				T->root = Temp->rchild;
				free(Temp);
				return OK;
			}
			if (Temp->rchild == NULL && Temp->lchild != NULL)	  //度为1时且为左孩子时
			{
				T->root = Temp->lchild;
				free(Temp);
				return OK;
			}
			if (Temp->lchild != NULL && Temp->rchild != NULL)		   //度为2时
			{
				BiTNode* LeftTree_MostRight = (BiTNode*)malloc(sizeof(BiTNode));
				LeftTree_MostRight = Temp->lchild;
				while (LeftTree_MostRight != NULL)
					LeftTree_MostRight = LeftTree_MostRight->rchild;   //找到左子树的最右结点
				T->root = Temp->lchild;
				LeftTree_MostRight = Temp->rchild;
				free(Temp);
				return OK;
			}
		}
		else													      //一般删除中间结点的情形
		{
			BiTNode* Temp = (BiTNode*)malloc(sizeof(BiTNode));
			Temp = LocateNode(T, e);
			BiTNode* parent = Get_Parent(T, e);					  //再找到key值为e的结点的父结点，方便后续改变指针关系
			if (Temp->lchild == NULL && Temp->rchild == NULL)     //度为0时
			{
				if (parent->lchild == Temp)
				{
					parent->lchild = NULL;
					free(Temp);
					return OK;
				}
				if (parent->rchild == Temp)
				{
					parent->rchild = NULL;
					free(Temp);
					return OK;
				}
			}
			if (Temp->lchild == NULL && Temp->rchild != NULL)	  //度为1时且为右孩子时
			{
				if (parent->lchild == Temp)
				{
					parent->lchild = Temp->rchild;
					free(Temp);
					return OK;
				}
				if (parent->rchild == Temp)
				{
					parent->rchild = Temp->rchild;
					free(Temp);
					return OK;
				}
			}
			if (Temp->rchild == NULL && Temp->lchild != NULL)			//度为1时且为左孩子时
			{
				if (parent->lchild == Temp)
				{
					parent->lchild = Temp->lchild;
					free(Temp);
					return OK;
				}
				if (parent->rchild == Temp)
				{
					parent->rchild = Temp->lchild;
					free(Temp);
					return OK;
				}
			}
			if (Temp->lchild != NULL && Temp->rchild != NULL)			//度为2时（也需要分该结点是parent结点的左孩子还是右孩子）
			{
				BiTNode* LeftTree_MostRight = (BiTNode*)malloc(sizeof(BiTNode));
				LeftTree_MostRight = Temp->lchild;
				while (LeftTree_MostRight != NULL)
					LeftTree_MostRight = LeftTree_MostRight->rchild;   //找到需删除结点的左子树的最右结点
				if (parent->lchild == Temp)
				{
					parent->lchild = Temp->lchild;
					LeftTree_MostRight = Temp->rchild;
					free(Temp);
					return OK;
				}
				if (parent->rchild == Temp)
				{
					parent->rchild = Temp->lchild;
					LeftTree_MostRight = Temp->rchild;
					free(Temp);
					return OK;
				}
			}
		}
	}
	T->number--;
	return OK;
}
Status Visit(BiTNode* c)
{
	printf("(%s: %d) ", c->key, c->data);
	return TRUE;
}
Status PreOrderTraverse(BiTree* T, Status(*visit)(BiTNode* c))
{
	if (!T->isInitial)
		return UNINITIAL;
	if (!T->root)
		return OK;
	printf("\n-----------all elements -----------------------\n");
	PreOrderTraverse_Helper(T->root, visit);                         //利用PreOrderTraverse_Helper来实现递归调用
	printf("\n------------------ end ------------------------\n");
	return OK;
}
Status PreOrderTraverse_Helper(BiTNode* P, Status(*visit)(BiTNode* c))
{
	if (P)
	{
		if (visit(P))
			if (PreOrderTraverse_Helper(P->lchild, visit))
				if (PreOrderTraverse_Helper(P->rchild, visit))
					return OK;										//先对根结点visit访问之后，再对左右孩子进行相同的遍历操作
		return ERROR;
	}
	else
		return OK;
}
Status InOrderTraverse(BiTree* T, Status(*visit)(BiTNode* c))         //利用栈操作来实现中序遍历的非递归算法
{
	if (!T->isInitial)
		return UNINITIAL;
	if (!T->root)
		return OK;
	LinkStack* S = (LinkStack*)malloc(sizeof(LinkStack));
	BiTNode* P = (BiTNode*)malloc(sizeof(BiTNode));
	printf("\n-----------all elements -----------------------\n");
	InitStack(S);
	Push(S, T->root);
	while (!StackEmpty(S))                                             //当栈不为空时，遍历未完成
	{
		while (GetTop(S, &P) && P)                                    //若栈顶元素非空，则继续将左孩子入栈，否则弹出栈顶空指针（入空即弹）
			Push(S, P->lchild);
		Pop(S, &P);													  //弹出一次空指针后，若栈不为空，再连续弹出一个非空结点，对其访问
		if (!StackEmpty(S))
		{
			Pop(S, &P);
			if (!visit(P))											  //再转向P->rchild
				return ERROR;
			Push(S, P->rchild);
		}
	}
	printf("\n------------------ end ------------------------\n");
	return OK;
}
Status PostOrderTraverse(BiTree* T, Status(*visit)(BiTNode* c)) //后序遍历的非递归算法和中序遍历的算法类似，只是有判断条件（需要标记pre弹出结点）
{																//在弹出非空结点之前，若其右孩子为空或者右孩子刚被弹出才将其也弹出，否则是右孩子入栈
	if (!T->isInitial)
		return UNINITIAL;
	if (!T->root)
		return OK;
	printf("\n-----------all elements -----------------------\n");
	PostOrderTraverse_Helper(T->root, visit);
	printf("\n------------------ end ------------------------\n");
	return OK;
}
Status PostOrderTraverse_Helper(BiTNode* P, Status(*visit)(BiTNode* c))
{
	if (P)                                                          //当p不为空时继续对左右孩子调用，若孩子为空，直接返回OK
	{
		if (PostOrderTraverse_Helper(P->lchild, visit))
			if (PostOrderTraverse_Helper(P->rchild, visit))
				if (visit(P))
					return OK;										//先对左右孩子调用遍历函数，再对自身根节点访问
		return ERROR;
	}
	else
		return OK;
}
Status LevelOrderTraverse(BiTree* T, Status(*visit)(BiTNode* c))
{
	if (!T->isInitial)
		return UNINITIAL;
	if (!T->root)
		return OK;
	LinkQueue* Q = (LinkQueue*)malloc(sizeof(LinkQueue));
	BiTNode* P = (BiTNode*)malloc(sizeof(BiTNode));
	InitQueue(Q);
	EnQueue(Q, T->root);
	printf("\n-----------all elements -----------------------\n");
	while (!QueueEmpty(Q))
	{
		DeQueue(Q, &P);				//只要队列不空，则每次将队头元素出队
		if (!visit(P))
			return ERROR;
		if (P->lchild != NULL)               //有左孩子则继续入队，有右孩子也继续入队
			EnQueue(Q, P->lchild);
		if (P->rchild != NULL)				//每一次上一层刚好都出队时，下一层的左右孩子也从左至右都入队了
			EnQueue(Q, P->rchild);
	}
	printf("\n------------------ end ------------------------\n");
	return OK;
}
Status InputFromFile(char* filename1, char* filename2, BiTree* T)
{
	if (!T->isInitial)
		InitTree(T);
	FILE* fp1, * fp2;
	int i = 0;
	int j = 0;
	if ((fp1 = fopen(filename1, "r")) == NULL || (fp2 = fopen(filename2, "r")) == NULL)
	{
		printf("Open Error!\n");
		return ERROR;
	}
	while (fscanf(fp1, "%s", Preorder_key + i) == 1)        //先将文件中的keyֵ和data导入到Preorder_key和Preorder_data数组中
		i++;
	while (fscanf(fp2, "%d", Preorder_data + j) == 1)
		j++;
	fclose(fp1);
	fclose(fp2);
	CreateBiTree(T, Preorder_key, Preorder_data);			//再利用CreateBiTree创建树的结构
	return OK;
}
Status OutputToFile(char* filename1, BiTree* T)
{
	if (!T->isInitial)
		return UNINITIAL;
	FILE* fp;
	if ((fp = fopen(filename1, "w")) == NULL)
	{
		printf("Open Error!\n");
		return ERROR;
	}
	int i = 0, j = 0;
	while(j < T->number)
	{
		if (strcmp(Preorder_key[i],"@"))
			fprintf(fp, "(%s: %d) ", Preorder_key[i++], Preorder_data[j++]);
		else
			i++;
	}
	fclose(fp);
	return OK;
}
Status SelectTree(BiTree** T, int index)
{
	if (index > BITREE_INIT_SIZE)     //当树的数量超过初始最大值100时，需要增加空间
	{
		BiTree* newTreeArray;
		newTreeArray = (BiTree*)realloc(TreeArray, (BITREE_INIT_SIZE + BITREE_INCREMENT) * sizeof(BiTree));
		if (!newTreeArray)
			return OVERFLOW;
		TreeArray = newTreeArray;
	}
	*T = &TreeArray[index - 1];
	(*T)->ID = index;
	if ((*T)->isInitial != TRUE)
	{
		(*T)->isInitial = FALSE;
		(*T)->root = NULL;
	}
	return TRUE;
}