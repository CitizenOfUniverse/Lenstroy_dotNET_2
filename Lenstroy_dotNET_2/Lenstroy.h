#pragma once
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forall(it, x) for(auto it = (x).begin(); it != (x).end(); it++)
#define OUT(x) {cout << x; exit(0);}
//#define sz size()
#define ft first
#define sd second
#define pb(x) push_back(x)
#define pb2(x, y) push_back(x, y)
#define mp(x, y) make_pair(x, y)
#define fora0(ITER, LIMIT) for(int ITER = 0; ITER < LIMIT; ITER++)
#define fora1(ITER, LIMIT) for(int ITER = 1; ITER <= LIMIT; ITER++)
#define ford0(ITER, LIMIT) for(int ITER = LIMIT - 1; ITER >= 0; ITER--)
#define ford1(ITER, LIMIT) for(int ITER = LIMIT; ITER >= 1; ITER--)

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <iomanip>
#include "assert.h"
#include <stack>
#include <queue>
#include <set>
#include <cstdio>
#include <array>
#include <list>
#include <sstream>
#include <cmath>
#include <tuple>

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

namespace Lenstroy {
	int lenstroy(int n, int limit);
	bool check_is_prime(int n);
}