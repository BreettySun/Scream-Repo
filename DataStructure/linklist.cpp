/*
 * @Author: BreettySun
 * @Date: 2023-03-23 20:38:59
 * @LastEditors: BreettySun
 * @LastEditTime: 2023-03-30 20:30:04
 * @FilePath: \Scream-Repo\DataStructure\linklist.cpp
 * @Description:
 *
 * Copyright (c) 2023 by BreettySun, All Rights Reserved.
 */

#include <bits/stdc++.h>
#define ElemType int
using namespace std;

typedef struct LNode
{
  ElemType data = 0;
  struct LNode *next;
} LNode, *Linklist;

/**
 * @description: 头插法建立单链表
 * @param {Linklist} &L
 * @return {Linklist}
 */
Linklist List_HeadInsert(Linklist &L)
{
  cout << "List_HeadInsert: ";
  L = (Linklist)malloc(sizeof(LNode));
  LNode *s;
  int x;
  L->next = nullptr;
  scanf("%d", &x);
  while (x != 9999)
  {
    s = (LNode *)malloc(sizeof(LNode));
    s->data = x;
    s->next = L->next;
    L->next = s;
    scanf("%d", &x);
  }
  return L;
}

/**
 * @description: 尾插法建立单链表
 * @param {Linklist} &L
 * @return {Linklist}
 */
Linklist List_TailInsert(Linklist &L)
{
  cout << "List_TailInsert: ";
  L = (Linklist)malloc(sizeof(LNode));
  LNode *s, *r = L;
  int x;
  scanf("%d", &x);
  while (x != 9999)
  {
    s = (LNode *)malloc(sizeof(LNode));
    s->data = x;
    r->next = s;
    r = s;
    scanf("%d", &x);
  }
  r->next = nullptr;
  return L;
}

/**
 * @description: 根据序号查找元素
 * @param {Linklist} L
 * @param {int} i
 * @return {LNode}
 */
LNode *GetElem(Linklist L, int i)
{
  cout << "GetElem: ";
  int j = 1;
  LNode *p = L->next;
  if (i == 0)
  {
    return L;
  }
  else if (i < 1)
  {
    return nullptr;
  }
  while (p != nullptr && j < i)
  {
    p = p->next;
    j++;
  }
  return p;
}

/**
 * @description: 根据元素值查找元素
 * @param {Linklist} L
 * @param {ElemType} e
 * @return {LNode}
 */
LNode *LocateElem(Linklist L, ElemType e)
{
  cout << "LocateElem: ";
  LNode *p = L->next;
  while (p != nullptr && p->data != e)
  {
    p = p->next;
  }
  return p;
}

/**
 * @description: 在第i个位置插入元素
 * @param {Linklist} L
 * @param {int} i
 * @return {bool}
 */
void InsertElem(Linklist L, int i)
{
  cout << "InsertElem: ";
  LNode *p = GetElem(L, i - 1);
  LNode *s = (LNode *)malloc(sizeof(LNode));
  ElemType x;
  scanf("%d", &x);
  s->data = x;
  s->next = p->next;
  p->next = s;
}

/**
 * @description: 删除第i个元素
 * @param {Linklist} L
 * @param {int} i
 * @return {bool}
 */
void DeleteElem(Linklist L, int i)
{
  cout << "DeleteElem: ";
  LNode *p = GetElem(L, i - 1);
  LNode *q = p->next;
  p->next = q->next;
  free(q);
}

/**
 * @description: 单链表是否为空
 * @param {Linklist} L
 * @return {bool}
 */
bool Empty(Linklist L)
{
  return L->next == nullptr;
}

/**
 * @description: 无头结点单链表是否为空
 * @param {Linklist} L
 * @return {bool}
 */
bool EmptyNoHead(Linklist L)
{
  return L == nullptr;
}

/**
 * @description: 求单链表长度
 * @param {Linklist} L
 * @return {int}
 */
int ListLength(Linklist L)
{
  int length = 0;
  while (L->next != nullptr)
  {
    L = L->next;
    length++;
  }
  return length;
}

/**
 * @description: 重置单链表
 * @param {Linklist} &L
 * @return {bool}
 */
bool InitList(Linklist &L)
{
  L = (LNode *)malloc(sizeof(LNode));
  if (L == nullptr)
  {
    return false;
  }
  else
  {
    L->next = nullptr;
    return true;
  }
}

/**
 * @description: 重置无头结点单链表
 * @param {Linklist} &L
 * @return {bool}
 */
bool InitListNoHead(Linklist &L)
{
  L = nullptr;
  return true;
}

/**
 * @description: 打印单链表
 * @param {Linklist} L
 * @return {*}
 */
void PrintList(Linklist L)
{
  int length = ListLength(L);
  cout << "length: " << length << endl;
  LNode *p = L->next;
  for (int i = 0; i < length; i++)
  {
    cout << p->data << " ";
    p = p->next;
  }
  cout << endl;
}

int main()
{
  Linklist L;
  List_HeadInsert(L);
  PrintList(L);
  InsertElem(L, 5);
  PrintList(L);
  DeleteElem(L, 4);
  PrintList(L);
  return 0;
}
