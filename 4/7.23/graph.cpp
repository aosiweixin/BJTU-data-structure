#include "graph.h"
#include "Lqueue.h"
int LocateVex(ALGraph G, int v)
{
	for (int i = 0; i < G.vexnum; i++)
	{
		if (G.vertices[i].data == v)
		{
			return i;
		}
	}
	return -1;
}

bool CreateUDG(ALGraph& G)
{
	cout << "输入顶点数和边数:";
	cin >> G.vexnum >> G.arcnum;//输入顶点数和边数
	cout << "输入所有顶点的数据:" << endl;
	for (int i = 0; i < G.vexnum; ++i)
	{
		cin >> G.vertices[i].data;
		G.vertices[i].firstarc = NULL;//初始化表头结点的指针域为NULL
	}
	for (int k = 0; k < G.arcnum; ++k)
	{
		int v1, v2;
		cout << "输入第" << k + 1 << "条边依附的两个顶点：" << endl;
		cin >> v1 >> v2;//输入一条边依附的两个顶点
		int i = LocateVex(G, v1), j = LocateVex(G, v2);
		ArcNode* p1;
		p1 = new ArcNode;
		//p2 = new ArcNode;

		p1->adjvex = j;
		p1->nextarc = G.vertices[i].firstarc;
		G.vertices[i].firstarc = p1;

		//p2->adjvex = i;
		//p2->nextarc = G.vertices[j].firstarc;
		//G.vertices[j].firstarc = p2;
	}
	return true;
}
void BFS(ALGraph& G, int v)
{
	int w;
	ArcNode* p;
	int visited[MAX_VERTEX_NUM] = { 0 };
	Queue* Q = (LQueue)malloc(sizeof(Queue));
	InitQueue(Q);
	EnQueue(Q, v);
	while (!QueueisEmpty(Q))
	{
		w = DeQueue(Q);
		if (visited[w] == 1)continue;
		visited[w] = 1;
		cout << G.vertices[w].data << endl;
		p = G.vertices[w].firstarc;
		while (p != NULL)
		{
			if (visited[p->adjvex] == 0)
			{
				EnQueue(Q, p->adjvex);
			}
			p = p->nextarc;
		}
	}
	cout << endl;
}

void BfsJudge(ALGraph& G, int v, int s)
{
	int w;
	ArcNode* p;
	int visited[MAX_VERTEX_NUM] = { 0 };
	Queue* Q = (LQueue)malloc(sizeof(Queue));
	InitQueue(Q);
	EnQueue(Q, v);
	while (!QueueisEmpty(Q))
	{
		w = DeQueue(Q);
		if (visited[w] == 1)continue;
		visited[w] = 1;
		cout << G.vertices[w].data << endl;
		if (w==s)
		{
			cout << "YES!" << endl;
			break;
		}
		p = G.vertices[w].firstarc;
		while (p != NULL)
		{
			if (visited[p->adjvex] == 0)
			{
				EnQueue(Q, p->adjvex);
			}
			p = p->nextarc;
		}
	}
	cout << endl;
}
