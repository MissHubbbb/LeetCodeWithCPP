#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> re;
    int n = nums.size();
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        for (int j = i + 1; j < n; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            int k = j + 1;
            int f = n - 1;

            while (k < f) {
                if (nums[i] + nums[j] == (long long)target - nums[k] - nums[f])
                {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    temp.push_back(nums[f]);
                    re.push_back(temp);
                    k++;
                    f--;
                    while (k < f && nums[k] == nums[k - 1])   k++;
                    while (k < f && nums[f] == nums[f + 1])   f--;
                }
                if (nums[i] + nums[j] < (long long)target - nums[k] - nums[f]) {
                    k++;
                }
                if (nums[i] + nums[j] > (long long)target - nums[k] - nums[f]) {
                    f--;
                }
                if (k == f)
                    break;
            }
        }
    }

    return re;
}

int main4() {
    vector<int> nums = { 1,0,-1,0,-2,2 };
    vector<vector<int>> result = fourSum(nums, 0);   
    int n = result.size();
    for (int i = 0; i < n; i++)
    {
        int p = result[i].size();
        for (int j = 0; j < p; j++) {
            cout << result[i][j] << endl;
        }
    }

    return 0;
}