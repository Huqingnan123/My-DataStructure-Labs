#include "Graph.h"
#include "Queue.h"

int index = 1;
Vertex Vertex_array[MAX_VERTEX_NUM];
Arc Arc_array[MAX_ARC_NUM];
status visited[MAX_VERTEX_NUM];
Graph* GraphArray;
FILE* fp;

int main()
{
	GraphArray = (Graph*)malloc(MAX_GRAPH_NUM * sizeof(Graph));    //用于管理多个图(只存放各个图的基址指针）
	Graph* G = &GraphArray[0];					//必须要用指针T“传参”，去操作T所指地址上的GraphArray[index]，才会保存后续对表的操作
	G->isInitial = FALSE;
	int option = 1;
	int key, v_key, w_key, Vex_number, Arc_number, status, start_key, end_key;
	char value, filename1[30], filename2[30], filename3[30];
	Vertex* v = (Vertex*)malloc(sizeof(Vertex));
	while (option)
	{
		system("cls");
		printf("\n        Menu for Binary graph On Link Structure \n");
		printf("------------------------------------------------------\n");
		printf("|    	1.  InitialGraph       9. DeleteVex          |\n");
		printf("|    	2.  CreateGraph        10. InsertArc         |\n");
		printf("|   	3.  DestroyGraph       11. DeleteArc         |\n");
		printf("|    	4.  LocateVex          12. DFSTraverse       |\n");
		printf("|    	5.  PutVex             13. BFSTraverse       |\n");
		printf("|    	6.  FirstAdjVex        14. InputFromFile     |\n");
		printf("|    	7.  NextAdjVex         15. OutputToFile      |\n");
		printf("|    	8.  InsertVex          16. SelectGraph       |\n");
		printf("|    	0.  Exit                                     |\n");
		printf("------------------------------------------------------\n");
		printf("*****************************************************");
		printf("\nDear users, you are operating the number %d Graph now!\n", index);
		printf("*****************************************************\n\n");
		printf("Please Select a function from [0--18] to operate:");
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
			printf("You've chosen function InitialGraph(), which initializes a Graph.\n");
			if (InitialGraph(G) == OK)
				printf("Initialize a Graph successfully!\n");
			else
				printf("Failed to initialize a Graph!\n");
			getchar();
			break;
		case 2:
			printf("You've chosen function CreateGraph(), which creates a graph in your definition.\n");
			printf("Please input the graph's Vex_number and Arc_number first!\n");
			scanf("%d %d", &Vex_number, &Arc_number);
			getchar();
			printf("Please input vex's information about key and value like (key,value).\n");
			while (scanf("(%d,%c)", &(Vertex_array[i].key), &(Vertex_array[i].value)) == 2 && (getchar()) != '\n')
				i++;
			printf("Please input arc's information and vex pairs like (key1,key2).\n");
			while (scanf("(%d,%d)", &(Arc_array[j].start_key), &(Arc_array[j].end_key)) == 2 && (getchar()) != '\n')
				j++;
			if (!G->isInitial)
			{
				printf("Failed! This graph has not been initialized!\n");
				break;
			}
			if (CreateGraph(G, Vertex_array, Arc_array,Vex_number,Arc_number) == OK)
				printf("Create a new graph constructed successfully!\n");
			else
				printf("Failed to Create a new graph!\n");
			break;
		case 3:
			printf("You've chosen function DestroyGraph(), which destroys a graph.\n");
			if (DestroyGraph(G) == OK)
				printf("Destroy this graph successfully!\n");
			else
				printf("Failed to destroy this graph!\n");
			getchar();
			break;
		case 4:
			printf("You've chosen function LocateVex(), which locate a vertex's position.\n");
			printf("Please input the Vertex's key you want to find!\n");
			scanf("%d", &key);
			status = LocateVex(G, key);
			if (status > 0)
				printf("The vertex's position you want find is %d!\n",status);
			else
				printf("Failed to Locate a vertex with this key!\n");
			getchar();
			break;
		case 5:
			printf("You've chosen function PutVex(), which assign value to a specified vertex.\n");
			printf("Please input the vertex's key you want to find!\n");
			if (!scanf("%d", &key))
			{
				printf("Invalid key!\n");
				while (getchar() != '\n');
				break;
			}
			printf("Please input the vertex's value you want to assign!\n");
			getchar();
			scanf("%c", &value);
			status = PutVex(G, key, value);
			if (status == UNINITIAL)
				printf("ERROR!This graph has not been initialized!\n");
			if (status == OK)
				printf("Assign value to specified vertex successfully!\n");
			else
				printf("Failed to assign!\n");
			getchar();
			break;
		case 6:
			printf("You've chosen function FirstAdjVex(), which gets the first adjvertex of a vertex.\n");
			if (G->isInitial == FALSE)
			{
				printf("ERROR!This graph has not been initialized!\n");
				break;
			}
			printf("Please input the vertex's key you want to find!\n");
			if (!scanf("%d", &key))
			{
				printf("Invalid key!\n");
				while (getchar() != '\n');
				break;
			}
			status = FirstAdjVex(G, key);
			if (status > 0)
			{
				key = G->vertices[status - 1].data.key;
				value = G->vertices[status - 1].data.value;
				printf("the first adjvertex's key and value are %d and %c!\n", key, value);
			}
			else
				printf("Can't find a adjvertex of this vertex!\n");
			getchar();
			break;
		case 7:
			printf("You've chosen function NextAdjVex(),  which gets a adjvertex after w of v!\n");
			printf("Please input the key of vertex v and w!\n");
			scanf("%d %d", &v_key, &w_key);
			if (G->isInitial == FALSE)
			{
				printf("ERROR!This graph has not been initialized!\n");
				getchar();
				break;
			}
			status = NextAdjVex(G, v_key, w_key);
			if (status > 0)
			{
				key = G->vertices[status - 1].data.key;
				value = G->vertices[status - 1].data.value;
				printf("the v's adjvertex's key and value after w are %d and %c!\n", key, value);
			}
			else
				printf("Can't find a adjvertex after w of v!");
			getchar();
			break;
		case 8:
			printf("You've chosen function InsertVex(), which insert a vertex to current graph!\n");
			printf("Please input the key and the value of the vertex you want to insert!\n");
			scanf("%d %c", &(v->key), &(v->value));
			if (G->isInitial == FALSE)
			{
				printf("ERROR!This graph has not been initialized!\n");
				getchar();
				break;
			}
			status = InsertVex(G, *v);
			if (status == OK)
				printf("Insert this vertex successfully!\n");
			else
				printf("Failed to insert!");
			getchar();
			break;
		case 9:
			printf("You've chosen function DeleteVex(), which delete a vertex and all arcs related to its!\n");
			printf("Please input the key and the value of the vertex you want to delete!\n");
			scanf("%d %c", &(v->key), &(v->value));
			if (G->isInitial == FALSE)
			{
				printf("ERROR!This graph has not been initialized!\n");
				getchar();
				break;
			}
			status = DeleteVex(G, *v, v->key);
			if (status = OK)
				printf("Delete a vertex and all arcs related to its successfully!\n");
			else
				printf("Failed to delete!\n");
			getchar();
			break;
		case 10:
			printf("You've chosen function InsertArc(), which insert a arc between two vertexs in current graph!\n");
			printf("Please input the start_key and the end_key of the Arc you want to insert!\n");
			scanf("%d %d", &start_key, &end_key);
			if (G->isInitial == FALSE)
			{
				printf("ERROR!This graph has not been initialized!\n");
				getchar();
				break;
			}
			status = InsertArc(G, start_key, end_key);
			if (status == OK)
				printf("Insert this Arc between start_key_v and end_key_v successfully!\n");
			else
				printf("Failed to insert!");
			getchar();
			break;
		case 11:
			printf("You've chosen function DeleteArc(), which delete a specified Arc between two vertexs!\n");
			printf("Please input the start_key and the end_key of the Arc you want to delete!\n");
			scanf("%d %d", &start_key, &end_key);
			if (G->isInitial == FALSE)
			{
				printf("ERROR!This graph has not been initialized!\n");
				getchar();
				break;
			}
			status = DeleteArc(G, start_key, end_key);
			if (status = OK)
				printf("Delete a specified Arc between two vertexs successfully!\n");
			else
				printf("Failed to delete!\n");
			getchar();
			break;
		case 12:
			printf("You've chosen function DFSTrasverse(), which traverses this graph in DFS order.\n");
			if (!G->isInitial)
			{
				printf("ERROR!This graph has not been initialized!\n");
				getchar();
				break;
			}
			if (DFSTraverse(G, Visit) == OK)
				printf("\nTraversed in DFS order successfully!\n");
			else
				printf("Failed to traverse.\n");
			getchar();
			break;
		case 13:
			printf("You've chosen function BFSTrasverse(), which traverses this graph in BFS order.\n");
			if (!G->isInitial)
			{
				printf("ERROR!This graph has not been initialized!\n");
				getchar();
				break;
			}
			if (BFSTraverse(G, Visit) == OK)
				printf("\nTraversed in BFS order successfully!\n");
			else
				printf("Failed to traverse.\n");
			getchar();
			break;
		case 14:
			printf("You've chosen function InputFromFile(), which load keys and values of vertexs from file.\n");
			printf("Please input your vertexs input-filename: ");
			scanf("%s", filename1);
			getchar();
			printf("Please input your arcs input-filename: ");
			scanf("%s", filename2);
			if (InputFromFile(filename1, filename2, G))
				printf("Input from file successfully\n");
			else
				printf("Failed to input!\n");
			getchar();
			break;
		case 15:
			printf("You've chosen function OutputToFile(), which write keys and values of vertexs to file.\n");
			if (G->isInitial == FALSE)
			{
				printf("ERROR!This graph has not been initialized!\n");
				getchar();
				break;
			}
			printf("Please input your output-filename: ");
			scanf("%s", filename3);
			if (OutputToFile(filename3, G))
				printf("Output to file successfully\n");
			else
				printf("Failed to output!\n");
			getchar();
			break;
		case 16:
			printf("You've chosen function SelectGraph(), which chooses another graph to operate.\n");
			printf("Please input a number [1-10] to select a graph to operate,if you input a bigger number,it's OK: ");
			scanf("%d", &index);
			if (SelectGraph(&G, index) == OK)      //这里必须要&L，才能真正对T（树指针）起作用（二级指针）
				printf("You have selected number %d graph to operate now!\n", index);
			getchar();
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
	return 0;
}

status InitialGraph(Graph* G)
{
	if (G->isInitial)
		return ERROR;
	G->ID = index;
	G->isInitial = TRUE;
	G->Vex_number = 0;
	G->Arc_number = 0;
	return OK;
}

status CreateGraph(Graph* G, Vertex* Vertex_array, Arc* Arc_array, int Vex_number, int Arc_number)
{
	if (!G->isInitial)
		return UNINITIAL;
	int status = OK;
	for (int i = 0; i < Vex_number; i++)
		status = InsertVex(G, Vertex_array[i]);
	for (int j = 0; j < Arc_number; j++)
		status = InsertArc(G, Arc_array[j].start_key, Arc_array[j].end_key);
	if (status != OK)
	{
		G->Vex_number = 0;
		G->Arc_number = 0;
		return status;
	}
	G->Vex_number = Vex_number;
	G->Arc_number = Arc_number;
	return status;
}

status DestroyGraph(Graph* G)
{
	if (!G->isInitial)
		return UNINITIAL;
	for (int i = 0; i < G->Vex_number; i++)
	{
		while (G->vertices[i].FirstArc != NULL)
		{ 
			Arcnode* Temp = G->vertices[i].FirstArc;
			G->vertices[i].FirstArc = G->vertices[i].FirstArc->NextArc;
			free(Temp);
		}
	}
	G->Vex_number = 0;
	G->Arc_number = 0;
	G->isInitial = FALSE;
	return OK;
}

status LocateVex(Graph* G, int key)
{
	if (!G->isInitial)
		return UNINITIAL;
	for (int i = 0; i < G->Vex_number; i++)
	{
		if (G->vertices[i].data.key == key)
			return i + 1;
	}
	return 0;
}

status PutVex(Graph* G, int key, char value)
{
	if (!G->isInitial)
		return UNINITIAL;
	int position = LocateVex(G, key);
	if (!position)
		return ERROR;
	G->vertices[position - 1].data.value = value;
	return OK;
}

status FirstAdjVex(Graph* G, int key)
{
	if (!G->isInitial)
		return UNINITIAL;
	int position = LocateVex(G, key);
	if (G->vertices[position - 1].FirstArc)
		return LocateVex(G, G->vertices[position - 1].FirstArc->key);
	else
		return 0;
}

status NextAdjVex(Graph* G, int v_key, int w_key)
{
	if (!G->isInitial)
		return UNINITIAL;
	int v_pos = LocateVex(G, v_key);
	int w_pos = LocateVex(G, w_key);
	if (G->vertices[v_pos - 1].FirstArc)
	{
		Arcnode* Temp = G->vertices[v_pos - 1].FirstArc;
		while (Temp != NULL && Temp->key != G->vertices[w_pos - 1].data.key)
			Temp = Temp->NextArc;
		if (Temp == NULL)
			return ERROR;
		if (Temp->NextArc == NULL)
			return 0;
		else
			return LocateVex(G,Temp->NextArc->key);
	}
	return ERROR;
}

status InsertVex(Graph* G, Vertex v)
{
	if (!G->isInitial)
		return UNINITIAL;
	if (LocateVex(G, v.key))
		return ERROR;
	G->vertices[G->Vex_number].data = v;
	G->vertices[G->Vex_number].FirstArc = NULL;
	G->Vex_number++;
	return OK;
}

status DeleteVex(Graph* G, Vertex v, int key)
{
	if (!G->isInitial)
		return UNINITIAL;
	int position = LocateVex(G, key);
	while (G->vertices[position - 1].FirstArc!= NULL)
	{
		Arcnode* Temp1 = G->vertices[position - 1].FirstArc;
		G->vertices[position - 1].FirstArc = G->vertices[position - 1].FirstArc->NextArc;
		free(Temp1);
		G->Arc_number--;
	}
	for (int i = position - 1; i < G->Vex_number-1; i++)   //头结点列表后面的顶点均前移一位
		G->vertices[i] = G->vertices[i + 1];
	G->Vex_number--;
	for (int i = 0; i < G->Vex_number; i++)
	{
		Arcnode* curArc = G->vertices[i].FirstArc;
		Arcnode* preArc = G->vertices[i].FirstArc;
		while (curArc != NULL && curArc->key != key)
		{
			preArc = curArc;
			curArc = curArc->NextArc;
		}
		if (curArc!=NULL && curArc == preArc)                //说明第一个弧结点就匹配到了待删除结点key值，需要删除第一条弧
		{
			G->vertices[i].FirstArc = G->vertices[i].FirstArc->NextArc;
			free(preArc);
			G->Arc_number--;
		}
		else if(curArc != NULL)				 //说明在中间的弧结点匹配成功，改变待删除弧结点前后的指针关系
		{
			preArc->NextArc = curArc->NextArc;
			free(curArc);
			G->Arc_number--;
		}
	}
	return OK;
}

status InsertArc(Graph* G, int start_key, int end_key)
{
	if (!G->isInitial)
		return UNINITIAL;
	if (start_key == end_key)
		return ERROR;
	int position = LocateVex(G, start_key);
	Arcnode* Temp = G->vertices[position - 1].FirstArc;
	if (Temp == NULL)                                         //当没有邻接点时，直接添加
	{
		G->vertices[position - 1].FirstArc = (Arcnode*)malloc(sizeof(Arcnode));
		G->vertices[position - 1].FirstArc->key = end_key;
		G->vertices[position - 1].FirstArc->NextArc = NULL;
	}
	else
	{
		while (Temp->key != end_key && Temp->NextArc != NULL)     //当Temp指到最后一个邻接点时退出循环，对Temp->NextArc开辟新空间
			Temp = Temp->NextArc;
		if (Temp->key == end_key)								  //若因为start_key顶点有邻接点的key与要插入的顶点key相同而退出循环，则报错，插入弧失败
			return ERROR;
		Temp->NextArc = (Arcnode*)malloc(sizeof(Arcnode));
		Temp->NextArc->key = end_key;
		Temp->NextArc->NextArc = NULL;
	}
	G->Arc_number++;
	return OK;
}

status DeleteArc(Graph* G, int start_key, int end_key)
{
	if (!G->isInitial)
		return UNINITIAL;
	int position = LocateVex(G, start_key);
	Arcnode* curArc = G->vertices[position -1].FirstArc;
	Arcnode* preArc = G->vertices[position -1].FirstArc;
	while (curArc != NULL && curArc->key != end_key)
	{
		preArc = curArc;
		curArc = curArc->NextArc;
	}
	if (curArc == NULL)             //表明start_key到end_key的弧并不存在！
		return ERROR;
	if (curArc == preArc)                //说明第一个弧结点就匹配到了待删除结点key值，需要删除第一条弧
	{
		G->vertices[position - 1].FirstArc = G->vertices[position - 1].FirstArc->NextArc;
		free(preArc);
		G->Arc_number--;
	}
	else if (curArc != NULL)				 //说明在中间的弧结点匹配成功，改变待删除弧结点前后的指针关系
	{
		preArc->NextArc = curArc->NextArc;
		free(curArc);
		G->Arc_number--;
	}
	return OK;
}

status Visit(Vertex v)
{
	printf("(key:%d, value:%c) ", v.key, v.value);
	return OK;
}

status DFSTraverse(Graph* G, status(*visit)(Vertex v))
{
	if (!G->isInitial)
		return UNINITIAL;
	for (int i = 0; i < G->Vex_number; i++)
		visited[i] = FALSE;
	for (int i = 0; i < G->Vex_number; i++)
		if (!visited[i])
			DFS(G, i+1 ,visit);
	return OK;
}

status DFS(Graph* G, int position, status(*visit)(Vertex v))
{
	visited[position -1] = TRUE;
	visit(G->vertices[position - 1].data);
	for (int pos = FirstAdjVex(G, G->vertices[position-1].data.key); 
		pos > 0; pos = NextAdjVex(G, G->vertices[position - 1].data.key, pos))    //从当前顶点的第一邻接点到最后一个邻接点依次查看是否被访问
		if (!visited[pos-1])
			DFS(G, pos, visit);
}

status BFSTraverse(Graph* G, status(*visit)(Vertex v))
{
	if (!G->isInitial)
		return UNINITIAL;
	for (int i = 0; i < G->Vex_number; i++)
		visited[i] = FALSE;
	LinkQueue* Q = (LinkQueue*)malloc(sizeof(LinkQueue));
	Vertex* vertex = (Vertex*)malloc(sizeof(Vertex));
	InitQueue(Q);
	for (int i = 0; i < G->Vex_number; i++)
	{
		if (!visited[i])
		{
			visited[i] = TRUE;
			visit(G->vertices[i].data);
			EnQueue(Q, &(G->vertices[i].data));
			while (!QueueEmpty(Q))                      //都被访问过后就没有顶点再入队，最终队列会空
			{
				DeQueue(Q, &vertex);
				for (int pos = FirstAdjVex(G, vertex->key); pos > 0; pos = NextAdjVex(G, vertex->key, pos))
				{
					if (!visited[pos - 1])				//未被访问过的所有邻接点都依次访问并入队，访问过的邻接点不再入队
					{
						visited[pos - 1] = TRUE;
						visit(G->vertices[pos - 1].data);
						EnQueue(Q, &(G->vertices[pos - 1].data));
					}
				}
			}
		}
	}
	return OK;
}

status InputFromFile(char* filename1, char* filename2, Graph* G)
{
	if (!G->isInitial)
		InitialGraph(G);
	FILE* fp1, * fp2;
	int i = 0;
	int j = 0;
	if ((fp1 = fopen(filename1, "r")) == NULL || (fp2 = fopen(filename2, "r")) == NULL)
	{
		printf("Open Error!\n");
		return ERROR;
	}
	while (fscanf(fp1, "(%d:%c) ", &((Vertex_array + i)->key), &((Vertex_array + i)->value)) == 2)        //先将文件中的keyֵ和data导入到Preorder_key和Preorder_data数组中
		i++;
	while (fscanf(fp2, "(%d,%d) ", &((Arc_array + j)->start_key), &((Arc_array+j)->end_key)) == 2)
		j++;
	fclose(fp1);
	fclose(fp2);
	CreateGraph(G, Vertex_array, Arc_array, i, j);			//再利用CreateGraph创建树的结构
	return OK;
}

status OutputToFile(char* filename, Graph* G)
{
	if (!G->isInitial)
		return UNINITIAL;
	if ((fp = fopen(filename, "w")) == NULL)
	{
		printf("Open Error!\n");
		return ERROR;
	}
	char vertex_info[30] = "Vertexs information:";
	char arc_info[30] = "Arcs information:";
	fprintf(fp, "%s\n", vertex_info);
	BFSTraverse(G, Print_To_File);
	fprintf(fp, "\n%s\n", arc_info);
	int start_key, end_key;
	Arcnode* Temp;
	for (int i = 0; i < G->Vex_number; i++)
	{
		start_key = G->vertices[i].data.key;
		Temp = G->vertices[i].FirstArc;
		while (Temp != NULL)
		{
			end_key = Temp->key;
			fprintf(fp, "(start_key:%d,end_key:%d) ", start_key, end_key);
			Temp = Temp->NextArc;
		}
	}
	fclose(fp);
	return OK;
}

status Print_To_File(Vertex v)
{
	fprintf(fp, "(key:%d, value:%c) ", v.key, v.value);
	return OK;
}

status SelectGraph(Graph** G, int index)
{
	if (index > MAX_GRAPH_NUM)     //当图的数量超过初始最大值100时，需要增加空间
	{
		Graph* newGraphArray;
		newGraphArray = (Graph*)realloc(GraphArray, (MAX_GRAPH_NUM + GRAPH_INCREMENT) * sizeof(Graph));
		if (!newGraphArray)
			return OVERFLOW;
		GraphArray = newGraphArray;
	}
	*G = &GraphArray[index - 1];
	(*G)->ID = index;
	if ((*G)->isInitial != TRUE)
		(*G)->isInitial = FALSE;
	return TRUE;
}

