#include "VectorTool.h"

vector<int> GetPreSum(vector<int>& nums) {
    int n = nums.size();
    vector<int> help(n, 0);
    int curSum = 0;

    for (int i = 0; i < n; i++) {
        curSum += nums[i];
        help[i] = curSum;
    }

    return help;
}

int GetNeededSum(vector<int>& nums, int start, int end) {
    int res = nums[end] - nums[start - 1];

    return res;
}

int main_class02() {
    vector<int> arr = { 2, 8, -3, 4, 6, -1, 5 };

    vector<int> preSum = GetPreSum(arr);

    PrintVector("PreSum: ", preSum);
    cout << "Start from 2 to 6: " << GetNeededSum(preSum, 2, 6) << endl;
    cout << "print random int: " << GetRandomIntByRand() << endl;
    cout << "print random int: " << GetRandomIntBySrand(2, 20) << endl;

    return 0;
}