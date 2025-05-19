#include "VectorTool.h"

void PrintVector(string method, vector<int>& nums) {
    cout << method << endl;
    for (int cur : nums) {
        cout << cur << ' ';
    }
    cout << endl;
}

// rand() 返回一个随机数值，范围在[0, RAND_MAX]之间。rand()产生的是伪随机数，每次执行的结果是相同的。即上面的程序每次运行结果都一样。
// srand() 为了避免每次生成固定的随机数，引进srand()函数。该函数的功能是初始化随机数发生器，同样在头文件cstdlib中。
// 可使用srand((unsigned)time(NULL))的方法来产生不同的随机种子。需要引入头文件 time.h
// 可以把 rand() 想象成一个「随机数机器」，它内部有一张“看起来随机”的数字表，每次调用 rand() 就会从这个表里顺序拿一个数出来。而 “随机种子” 就是你从哪里开始读这张表的起始位置。
int GetRandomIntByRand() {
    srand((unsigned)time(NULL));
    return rand();
}

int GetRandomIntBySrand(int left, int right) {
    srand((unsigned)time(NULL));
    return (rand() % (right - left + 1)) + left;
}

// 使用seed初始化random engine，推荐std::random_device
//      它每次运行都会生成不同的随机bit流
//      如果要在每次启动时生成相同的序列，则需要用常量int初始化
// 使用min - max范围值初始化distribution对象
int GetRandomIntByRandomDevice(int min, int max) {
    std::random_device rd;  // 随机种子
    std::default_random_engine eng(rd());
    std::uniform_int_distribution<int> distr(min, max);

    return distr(eng);
}