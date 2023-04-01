/*
 * @Author: BreettySun
 * @Date: 2023-04-01 17:02:54
 * @LastEditors: BreettySun
 * @LastEditTime: 2023-04-01 23:55:02
 * @FilePath: \Scream-Repo\DataStructure\Queue.cpp
 * @Description: 
 * 
 * Copyright (c) 2023 by BreettySun, All Rights Reserved. 
 */
#include<bits/stdc++.h>
#define ElemType int
#define MaxSize 50
using namespace std;

typedef struct {
	ElemType data[MaxSize];
	int front, rear;
} SqQueue;

/**
 * @description: 初始化队列
 * @param {SqQueue} &Q
 * @return {*}
 */
void InitQueue(SqQueue &Q) {
	Q.rear = Q.front = 0;
}

/**
 * @description: 判断队列是否为空
 * @param {SqQueue} Q
 * @return {bool}
 */
bool QueueEmpty(SqQueue Q) {
	if (Q.rear == Q.front) {
		return true;
	} else {
		return false;
	}
}

/**
 * @description: 入队
 * @param {SqQueue} &Q
 * @param {ElemType} e
 * @return {bool}
 */
bool Push(SqQueue &Q, ElemType e) {
	if ((Q.rear + 1) % MaxSize == Q.front) {
		return false;
	} else {
		Q.data[Q.rear] = e;
		Q.rear = (Q.rear + 1) % MaxSize;
		return true;
	}
}

/**
 * @description: 出队
 * @param {SqQueue} &Q
 * @param {ElemType} &e
 * @return {bool}
 */
bool Pop(SqQueue &Q, ElemType &e) {
	if (Q.rear == Q.front) {
		return false;
	} else {
		e = Q.data[Q.front];
		Q.front = (Q.front + 1) % MaxSize;
		return true;
	}
}

/**
 * @description: 获取队头元素
 * @param {SqQueue} Q
 * @param {ElemType} &e
 * @return {bool}
 */
bool GetFront(SqQueue Q, ElemType &e) {
	if (Q.rear == Q.front) {
		return false;
	} else {
		e = Q.data[Q.front];
		return true;
	}
}

int main() {
	SqQueue Q;
	InitQueue(Q);
	ElemType a[] = {1, 2, 3, 4, 5};
	for (int i = 0; i < 5; i++) {
		Push(Q, a[i]);
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
