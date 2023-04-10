/*
 * @Author: BreettySun
 * @Date: 2023-04-01 14:35:32
 * @LastEditors: BreettySun
 * @LastEditTime: 2023-04-01 15:08:36
 * @FilePath: \Scream-Repo\DataStructure\Stack.cpp
 * @Description:
 *
 * Copyright (c) 2023 by BreettySun, All Rights Reserved.
 */
#include <bits/stdc++.h>
#define ElemType int
#define MaxSize 50
using namespace std;

typedef struct {
	ElemType data[MaxSize];
	int top;
} SqStack;

/**
 * @description: 初始化栈
 * @param {SqStack} &S
 * @return {*}
 */
void InitStack(SqStack &S) {
	S.top = -1;
}

/**
 * @description: 判断栈是否为空
 * @param {SqStack} S
 * @return {bool}
 */
bool StackEmpty(SqStack S) {
	if (S.top == -1) {
		return true;
	} else {
		return false;
	}
}

/**
 * @description: 入栈
 * @param {SqStack} &S
 * @param {ElemType} e
 * @return {bool}
 */
bool Push(SqStack &S, ElemType e) {
	if (S.top == MaxSize - 1) {
		return false;
	} else {
		S.data[++S.top] = e;
		return true;
	}
}

/**
 * @description: 出栈
 * @param {SqStack} &S
 * @param {ElemType} &e
 * @return {bool}
 */
bool Pop(SqStack &S, ElemType &e) {
	if (S.top == -1) {
		return false;
	} else {
		e = S.data[S.top--];
		return true;
	}
}

/**
 * @description: 获取栈顶元素
 * @param {SqStack} S
 * @param {ElemType} &e
 * @return {bool}
 */
bool GetTop(SqStack S, ElemType &e) {
	if (S.top == -1) {
		return false;
	} else {
		e = S.data[S.top];
		return true;
	}
}

int main() {
	SqStack S;
	InitStack(S);
	int a[] = {1, 2, 3, 4, 5};
	for (int i = 0; i < 5; i++) {
		Push(S, a[i]); // 1 2 3 4 5
	}
	ElemType StackTop = 0;
	ElemType PopElem = 0;
	while (!StackEmpty(S)) {
		GetTop(S, StackTop);
		cout << StackTop << " ";
		Pop(S, PopElem);
		cout << PopElem << endl;
	}
	return 0;
}
