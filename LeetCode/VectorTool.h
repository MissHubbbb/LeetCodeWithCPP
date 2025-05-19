#ifndef VECTOR_TOOL
#define VECTOR_TOOL

#include <vector>
#include <algorithm>
#include <cstdlib>  // 随机数
#include <time.h>   // 辅助生成随机数
#include <random>
#include <iostream>

using namespace std;

void PrintVector(string method, vector<int>& nums);

int GetRandomIntByRand();
int GetRandomIntBySrand(int left, int right);
int GetRandomIntByRandomDevice(int min, int max);

#endif
