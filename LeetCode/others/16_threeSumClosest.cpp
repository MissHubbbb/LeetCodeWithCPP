#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    int n = nums.size();
    int best = 1e7;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {        
        int j = i + 1;
        int k = n - 1;
                

        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == target)
                return target;

            if (abs(sum - target) < abs(best - target))
            {
                best = sum;                
            }
            if (sum < target) {
                j++;
            }
            if (sum > target) {
                k--;
            }
        }        
    }
    return best;
}

void main1() {
    vector<int> nums = { 1,1,1,1 };
    int target = 0;
    int f = threeSumClosest(nums, target);
    cout << "final result: " << f << endl;
}