#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define INFEASIBLE -2
#define UNINITIAL -3
#define BITNODE_INIT_SIZE 1024
#define BITREE_INIT_SIZE 100
#define BITREE_INCREMENT 10

typedef int TElemtype;
typedef int Status;

typedef struct BiTNode
{
	char key[20];
	TElemtype data;
	struct BiTNode* lchild;
	struct BiTNode* rchild;
}BiTNode;

typedef struct BiTree
{
	int ID;
	int depth;
	int number;
	Status isInitial;
	struct BiTNode* root;
}BiTree;

Status InitTree(BiTree* T);
Status CreateBiTree(BiTree* T, char (*Preorder_key)[20], int* Preorder_data);
Status CreateHelper(BiTNode** P, char (*Preorder_key)[20],int* Preorder_data); 
Status DestroyBiTree(BiTree* T);
Status DestroyHelper(BiTNode* P);
Status ClearBiTree(BiTree* T);
Status BiTreeEmpty(BiTree T);
Status BiTreeDepth(BiTree T);
Status DepthHelper(BiTNode* P);
BiTNode* LocateNode(BiTree* T,char* e);
BiTNode* LocateHelper(BiTNode* P, char* e);
Status Assign(BiTree* T, char* e, TElemtype value);
BiTNode* Get_Parent(BiTree* T, char* e);
BiTNode* Get_Parent_Helper(BiTNode* P, char* e);
BiTNode* GetSibling(BiTree* T, char* e);
Status InsertNode(BiTree* T, char* e, int LR, BiTNode* c);
Status DeleteNode(BiTree* T, char* e);
Status Visit(BiTNode* c);
Status PreOrderTraverse(BiTree* T, Status(*visit)(BiTNode* c));
Status PreOrderTraverse_Helper(BiTNode* P, Status(*visit)(BiTNode* c));
Status PreOrderTraverse_Helper2(BiTNode* P, Status(*visit)(BiTNode* c));
Status InOrderTraverse(BiTree* T, Status(*visit)(BiTNode* c));
Status PostOrderTraverse(BiTree* T, Status(*visit)(BiTNode* c));
Status PostOrderTraverse_Helper(BiTNode* P, Status(*visit)(BiTNode* c));
Status LevelOrderTraverse(BiTree* T, Status(*visit)(BiTNode* c));
Status InputFromFile(char* filename1, char* filename2, BiTree* T);
Status OutputToFile(char* filename1, BiTree* T);
Status SelectTree(BiTree** T, int index);







