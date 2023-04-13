/*
 * @Author: BreettySun
 * @Date: 2023-04-10 21:27:23
 * @LastEditors: BreettySun
 * @LastEditTime: 2023-04-13 21:00:07
 * @FilePath: \DataStructure\String.cpp
 * @Description:
 *
 * Copyright (c) 2023 by BreettySun, All Rights Reserved.
 */
#include <bits/stdc++.h>
#define MAXLEN 255
using namespace std;

/**
 * @description: 字符串暴力匹配
 * @param {string} s
 * @param {string} t
 * @return {int}
 */
int Index(string s, string t) {
	unsigned i = 0, j = 0;
	while (i < s.length() && j < t.length()) {
		if (s[i] == t[j]) {
			i++;
			j++;
		} else {
			i = i - j + 1;
			j = 0;
		}
	}
	if (j >= t.length()) {
		return i - t.length();
	} else {
		return -1;
	}
}

/**
 * @description: 获取next数组
 * @param {int} next[]
 * @param {string} t
 * @return {int[]}
 */
int *getNext(int next[], string t) {
	unsigned j = 0; // 前缀末尾
	unsigned i;     // 后缀末尾 & 最长相等前后缀长度
	for (i = 0; i < t.length(); i++) {
		while (j > 0 && t[i] != t[j]) {
			j = next[j - 1];
		}
		if (t[i] == t[j]) {
			j++;
		}
		next[i] = j; // 更新next数组
	}
	return next;
}

/**
 * @description: KMP算法
 * @param {string} s
 * @param {string} t
 * @return {int}
 */
int IndexKMP(string s, string t) {
	int next[MAXLEN];
	getNext(next, t);
	unsigned i = 0, j = 0;
	while (i < s.length() && j < t.length()) {
		if (s[i] == t[j]) {
			i++;
			j++;
		} else {
			if (j == 0) {
				i++;
			} else {
				j = next[j - 1];
			}
		}
	}
	if (j >= t.length()) {
		return i - t.length();
	} else {
		return -1;
	}
}

int main() {
	string s;
	string t;
	cin >> s;
	cin >> t;
	cout << Index(s, t) << endl;
	cout << IndexKMP(s, t) << endl;
	return 0;
}
