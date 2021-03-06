#include "list.h"

int InitList(Linklist& L)
{
	L = new Lnode;
	L->next = NULL;
	return 1;
}

int ListInsert(Linklist L, int i, Lnode e)
{
	Linklist p = L;
	Lnode* s;
	int j = 0;
	while (p != NULL && j < i - 1)
	{
		p = p->next;
		++j;
	}
	if (p == NULL || j > i - 1)return 0;
	s = new Lnode;
	s->ID = e.ID;
	strcpy_s(s->job, e.job);
	strcpy_s(s->name, e.name);
	s->next = p->next;
	p->next = s;
	return 0;
}

void DisplayAll(const Linklist L)
{
	Lnode* p = L->next;
	while (p != NULL)
	{
		DisplayLnode(p);
		p = p->next;
	}
}

void DisplayLnode(const Lnode* L)
{
	printf("ID:%d\t", L->ID);
	printf("name:%s\t", L->name);
	printf("Job:%s\n", L->job);
}

int FindByID(const Linklist L, int id)
{
	Lnode* p = L->next;
	int j = 1;
	while (p != NULL)
	{
		if (p->ID == id)
		{
			return j;
		}
		j++;
		p = p->next;
	}
	printf("cant find this id\n");
	return 0;
}

int DeleteByID(Linklist& L, int id)
{
	try
	{
		Lnode* p = L->next;
		int x = FindByID(L, id) - 1, j = 1;
		if (x == -1)throw -1;
		if (x!=0)
		{
			while (p->next != NULL && j < x)
			{
				j++;
				p = p->next;
			}
			if (p->next == NULL)throw - 2;
			Lnode* temp = p->next;
			p->next = temp->next;
			return 1;
		}
		if (x==0)
		{
			L->next = p->next;
			return 1;
		}
	}
	catch(int e)
	{
		printf("cant find!");
		return 0;
	}
	catch (...) 
	{
		printf("delete error!");
		return 0;
	}
}