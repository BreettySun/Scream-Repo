/*
 * @Author: BreettySun
 * @Date: 2023-03-30 20:36:35
 * @LastEditors: BreettySun
 * @LastEditTime: 2023-03-30 21:24:45
 * @FilePath: \Scream-Repo\DataStructure\doublelinklist.cpp
 * @Description:
 *
 * Copyright (c) 2023 by BreettySun, All Rights Reserved.
 */

#include <bits/stdc++.h>
#define ElemType int
using namespace std;

typedef struct DNode {
	ElemType data;
	struct DNode *prior, *next;
} DNode, *DLinkList;

/**
 * @description: 头插法建立双链表
 * @param {DLinkList} &L
 * @return {DLinkList}
 */
DLinkList List_HeadInsert(DLinkList &L) {
	cout << "List_HeadInsert: ";
	L = (DLinkList)malloc(sizeof(DNode));
	L->prior = nullptr;
	L->next = nullptr;
	DNode *s;
	int x;
	scanf("%d", &x);
	while (x != 9999) {
		s = (DNode *)malloc(sizeof(DNode));
		s->data = x;
		s->next = L->next;
		if (L->next != nullptr) {
			L->next->prior = s;
		}
		L->next = s;
		s->prior = L;
		scanf("%d", &x);
	}
	return L;
}

/**
 * @description: 尾插法建立双链表
 * @param {DLinkList} &L
 * @return {DLinkList}
 */
DLinkList List_TailInsert(DLinkList &L) {
	cout << "List_TailInsert: ";
	L = (DLinkList)malloc(sizeof(DNode));
	L->prior = nullptr;
	L->next = nullptr;
	DNode *s, *r = L;
	int x;
	scanf("%d", &x);
	while (x != 9999) {
		s = (DNode *)malloc(sizeof(DNode));
		s->data = x;
		r->next = s;
		s->prior = r;
		r = s;
		scanf("%d", &x);
	}
	r->next = nullptr;
	return L;
}

/**
 * @description: 根据位置对双链表的查找
 * @param {DLinkList} L
 * @param {int} i
 * @return {DNode*}
 */
DNode *GetElem(DLinkList L, int i) {
	DNode *p = L->next;
	int j = 1;
	while (p != nullptr && j < i) {
		p = p->next;
		j++;
	}
	return p;
}

/**
 * @description: 双链表在第i个位置插入元素e
 * @param {DLinkList} L
 * @param {int} i
 * @param {ElemType} e
 * @return {*}
 */
void InsertElem(DLinkList L, int i, ElemType e) {
	cout << "InsertElem: ";
	DNode *p = GetElem(L, i - 1);
	DNode *s = (DNode *)malloc(sizeof(DNode));
	s->data = e;
	s->next = p->next;
	s->prior = p;
	p->next->prior = s;
	p->next = s;
}

/**
 * @description: 双链表删除第i个元素
 * @param {DLinkList} L
 * @param {int} i
 * @return {*}
 */
void DeleteElem(DLinkList L, int i) {
	cout << "DeleteElem: ";
	DNode *p = GetElem(L, i - 1);
	DNode *q = p->next;
	p->next = q->next;
	q->next->prior = p;
	free(q);
}

/**
 * @description: 双链表的打印
 * @param {DLinkList} L
 * @return {*}
 */
void PrintList(DLinkList L) {
	DNode *p = L->next;
	while (p != nullptr) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

int main() {
	DLinkList L;
	List_HeadInsert(L);
	PrintList(L);
	InsertElem(L, 5, 10);
	PrintList(L);
	DeleteElem(L, 4);
	PrintList(L);
	return 0;
}
