/*
 * @Author: BreettySun
 * @Date: 2023-04-10 20:37:52
 * @LastEditors: BreettySun
 * @LastEditTime: 2023-04-10 21:02:20
 * @FilePath: \DataStructure\LinkQueue.cpp
 * @Description:
 *
 * Copyright (c) 2023 by BreettySun, All Rights Reserved.
 */
#include <bits/stdc++.h>
#define ElemType int
using namespace std;

typedef struct LinkNode {
	ElemType data;
	struct LinkNode *next;
} LinkNode;
typedef struct {
	LinkNode *front, *rear;
} LinkQueue;

/**
 * @description: 初始化队列
 * @param {LinkQueue} &Q
 * @return {*}
 */
void InitQueue(LinkQueue &Q) {
	Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));
	Q.front->next = nullptr;
}

/**
 * @description: 判断队列是否为空
 * @param {LinkQueue} Q
 * @return {bool}
 */
bool QueueEmpty(LinkQueue Q) {
	if (Q.front == Q.rear) {
		return true;
	} else {
		return false;
	}
}

/**
 * @description: 入队
 * @param {LinkQueue} &Q
 * @param {ElemType} e
 * @return {*}
 */
void Push(LinkQueue &Q, ElemType e) {
	LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
	s->data = e;
	s->next = nullptr;
	Q.rear->next = s; // 插入到链尾
	Q.rear = s;
}

/**
 * @description: 出队
 * @param {LinkQueue} &Q
 * @param {ElemType} &e
 * @return {bool}
 */
bool Pop(LinkQueue &Q, ElemType &e) {
	if (Q.front == Q.rear) {
		return false;
	} else {
		LinkNode *p = Q.front->next;
		e = p->data;
		Q.front->next = p->next;
		if (Q.rear == p) {
			Q.rear = Q.front;
		}
		free(p);
		return true;
	}
}

/**
 * @description: 获取队头元素
 * @param {LinkQueue} Q
 * @param {ElemType} &e
 * @return {bool}
 */
bool GetFront(LinkQueue Q, ElemType &e) {
	if (Q.front == Q.rear) {
		return false;
	} else {
		e = Q.front->next->data;
		return true;
	}
}

int main() {
	LinkQueue Q;
	InitQueue(Q);
	ElemType a[5] = {1, 2, 3, 4, 5};
	for (int i = 0; i < 5; i++) {
		Push(Q, a[i]); // 1 2 3 4 5
	}
	ElemType QueueFront = 0;
	ElemType PopElem = 0;
	while (!QueueEmpty(Q)) {
		GetFront(Q, QueueFront);
		cout << QueueFront << " ";
		Pop(Q, PopElem);
		cout << PopElem << endl;
	}
	return 0;
}
