/*
 * @Author: BreettySun
 * @Date: 2023-03-23 20:38:59
 * @LastEditors: BreettySun
 * @LastEditTime: 2023-03-27 21:36:40
 * @FilePath: \Scream-Repo\DataStructure\linklist.cpp
 * @Description:
 *
 * Copyright (c) 2023 by BreettySun, All Rights Reserved.
 */

#include <bits/stdc++.h>
#define ElemType int
using namespace std;

typedef struct LNode {
	ElemType data;
	struct LNode *next;
} LNode, *Linklist;

/**
 * @description:
 * @param {Linklist} &L
 * @return {bool}
 */
bool InitListNoHead(Linklist &L) {
	L = nullptr;
	return true;
}

/**
 * @description:
 * @param {Linklist} L
 * @return {bool}
 */
bool EmptyNoHead(Linklist L) {
	return L == nullptr;
}

/**
 * @description:
 * @param {Linklist} &L
 * @return {bool}
 */
bool InitList(Linklist &L) {
	L = (LNode *)malloc(sizeof(LNode));
	if (L == nullptr) {
		return false;
	} else {
		L->next = nullptr;
		return true;
	}
}

/**
 * @description:
 * @param {Linklist} L
 * @return {bool}
 */
bool Empty(Linklist L) {
	return L->next == nullptr;
}

/**
 * @description:
 * @param {Linklist} L
 * @param {int} i
 * @return {LNode}
 */
LNode *GetElem(Linklist L, int i) {
	int j = 1;
	LNode *p = L->next;
	if (i == 0) {
		return L;
	} else if (i < 1) {
		return nullptr;
	}
	while (p != nullptr && j < i) {
		p = p->next;
		j++;
	}
	return p;
}

int main() {
	cout << "hello world" << endl;
	return 0;
}
