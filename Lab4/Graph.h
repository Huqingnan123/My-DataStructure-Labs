#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
#define UNINITIAL -3
#define MAX_VERTEX_NUM 100
#define MAX_ARC_NUM 9900
#define MAX_GRAPH_NUM 10
#define GRAPH_INCREMENT 10

typedef int status;

typedef struct Vertex 
{
	int key;
	char value;
}Vertex;

typedef struct Arc
{
	int start_key;
	int end_key;
}Arc;

typedef struct Arcnode
{
	int key;
	struct Arcnode* NextArc;
}Arcnode;

typedef struct Vexnode
{
	Vertex data;
	struct Arcnode* FirstArc;
}Vexnode,Vexnode_Array[MAX_VERTEX_NUM];

typedef struct Graph
{
	int ID;
	int Vex_number;
	int Arc_number;
	status isInitial;
	Vexnode_Array vertices;
}Graph;

status InitialGraph(Graph* G);
status CreateGraph(Graph* G, Vertex* Vertex, Arc* Arc, int Vex_number, int Arc_number);
status DestroyGraph(Graph* G);
status LocateVex(Graph* G, int key);
status PutVex(Graph* G, int key, char value);
status FirstAdjVex(Graph* G, int key);
status NextAdjVex(Graph* G, int v_key, int w_key);
status InsertVex(Graph* G, Vertex v);
status DeleteVex(Graph* G, Vertex v, int key);
status InsertArc(Graph* G, int start_key, int end_key);
status DeleteArc(Graph* G, int start_key, int end_key);
status Visit(Vertex v);
status DFSTraverse(Graph* G, status(*visit)(Vertex v));
status DFS(Graph* G, int position, status(*visit)(Vexnode* v));
status BFSTraverse(Graph* G, status(*visit)(Vexnode* v));
status InputFromFile(char* filename, Graph* G);
status OutputToFile(char* filename, Graph* G);
status Print_To_File(Vertex v);
status SelectGraph(Graph** G, int index);
