﻿#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        int sum = -1;
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1])   continue;
            if (nums[i] + nums[i + 1] + nums[i + 2] > 0) break;
            if (nums[i] + nums[n - 1] + nums[n - 2] < 0) continue;
            int left = i + 1, right = n - 1;
            while (left < right) {
                sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    res.push_back({ nums[i], nums[left], nums[right] });
                    for (left++; left < right && nums[left] == nums[left - 1]; left++);
                    for (right--; left < right && nums[right] == nums[right + 1]; right--);
                }
                else if (sum < 0) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }
        return res;
    }
};

int main111() {
    Solution Sl;
    vector<int> test{ -1,0,1,2,-1,-4 };
    cout << "out";
    vector<vector<int>> res = Sl.threeSum(test);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}