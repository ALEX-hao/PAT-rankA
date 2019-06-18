// PAT 1002 A+B for Polynomials.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

class node
{
public:
	double data;
	int e;
	node *next = NULL;
};

class stack
{
public:
	node *top = NULL;
	void push(int a, double b);
	void print();
};
void stack::push(int a, double b)
{
	if (top == NULL)
	{
		node *s = new node;
		s->data = b;
		s->e = a;
		top = s;
	}
	else
	{
		node *s = new node;
		s->data = b;
		s->e = a;
		s->next = top;
		top = s;
	}
}
void stack::print()
{
	node *p = top;
	while (p != NULL)
	{
		if (p->data != 0)
		{
			cout << p->e << ' ' << p->data << ' ';
		}
		p = p->next;
	}
}

int compare(int a, int b)
{
	if (a > b) return 1;
	else if (a == b) return 0;
	else return -1;
}

stack *add(stack A,stack B)
{
	stack *c = new stack;
	node *p1 = A.top, *p2 = B.top;
	while (p1&&p2)
	{
		switch (compare(p1->e, p2->e))
		{
		case 1: c->push(p1->e, p1->data); p1 = p1->next; break;
		case 0: c->push(p1->e, p1->data + p2->data); p1 = p1->next; p2 = p2->next; break;
		case -1: c->push(p2->e, p2->data); p2 = p2->next; break;
		}
	}
	if (p1 == NULL)
	{
		while (p2 != NULL)
		{
			c->push(p2->e, p2->data);
			p2 = p2->next;
		}
	}
	else if (p2 == NULL)
	{
		while (p1 != NULL)
		{
			c->push(p1->e, p1->data);
			p1 = p1->next;
		}
	}
	return c;
}

int main()
{		
	stack A, B, *C;
	int a = 0, e = 0;
	double  d = 0;
	printf("输入A组内容\n");
	cin >> a;
	for (int i = 1; i <= a ; i++)
	{
		cin >> e >> d;
		A.push(e, d);
	}
	printf("输入B组内容\n");
	int b = 0;
	cin >> b;
	for (int i = 1; i <= b; i++)
	{
		cin >> e >> d;
		B.push(e, d);
	}
	C = add(A, B); int amount = 0;
	for (node *p = C->top; p; p = p->next)
	{
		amount++;
	}
	cout << amount << ' ';
	C->print();

	return 0;
}

