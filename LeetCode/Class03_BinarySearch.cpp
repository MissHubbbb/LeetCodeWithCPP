#include "VectorTool.h"
#include "unordered_map"

// 1. 二分：查找当前数组中是否存在target，返回值是bool
bool BinarySearchExist(vector<int>& nums, int target) {
    int n = nums.size();
    if (n == 0) {
        return false;
    }

    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return true;
        }
        else if (nums[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return false;
}

// 2. 二分：查找当前数组中的target的索引，必须是第一次出现的索引
//   （有序数组中找到>=target最左的位置）
//    解决方法：使用一个变量存储每次新出现的符合target的元素的索引
int BinarySearchLeftFirstIndex(vector<int>& nums, int target) {
    int n = nums.size();
    if (n == 0) {   // 没有这个元素
        return -1;
    }

    int left = 0;
    int right = n - 1;
    int resIndex = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            resIndex = mid;
            // 找到了target后还需要进一步进行更新，往左边找
            right = mid - 1;
        }
        else if (nums[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return resIndex;
}

//  3.二分：查找当前数组中的target的索引，必须是最后一次出现的索引
//   （有序数组中找到<=target最右的位置）
//    解决方法：使用一个变量存储每次新出现的符合target的元素的索引
int BinarySearchRightFirstIndex(vector<int>& nums, int target) {
    int n = nums.size();
    if (n == 0) {
        return -1;
    }

    int left = 0;
    int right = n - 1;
    int resIndex = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            resIndex = mid;
            left = mid + 1;     // 因为要找符合target的最后一个元素的索引，所以即使找到了符合的，首先记下来，然后左指针往右移
        }
        else if (nums[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return resIndex;
}

// 4.二分：找到局部最小值，其中每两个相邻的元素不一样
//      这个算法用到二分算法，但并不是有序数组
int BinarySearchLocalMinIndex(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return -1;
    if (n == 1) return 0;
    if (nums[0] < nums[1])   return 0;
    if (nums[n - 1] < nums[n - 2])   return n - 1;

    int left = 0;
    int right = n - 1;

    // 要想循环继续，至少得有 left、right-1、right三个数
    // 终止条件是 left >= right-1，至少有两个数
    while (left < right - 1) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < nums[mid + 1] && nums[mid] < nums[mid - 1]) {
            return mid;
        }
        else {
            if (nums[mid] > nums[mid + 1]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
    }

    return nums[left] < nums[right];
}

// 得到相邻元素不重复的随机数组
// maxLen:      最大长度
// maxValue:    元素所能取到的最大上限
vector<int> GetRandomVector(int maxLen, int maxValue) {
    int len = GetRandomIntByRandomDevice(0, maxLen);
    vector<int> arr(len, 0);
    arr[0] = GetRandomIntByRandomDevice(0, maxValue);
    for (int i = 1; i < len; i++) {
        do {
            arr[i] = GetRandomIntByRandomDevice(0, maxValue);
        } while (arr[i] == arr[i - 1]);
    }

    return arr;
}

// 第四个二分算法的对数器（有bug应该）
bool Check_BinarySearchLocalMinIndex(vector<int>& nums, int minIndex) {
    int n = nums.size();
    if (n == 0)  return false;
    if (n == 1)   return true;
    if (minIndex == 0) {
        return nums[minIndex] < nums[minIndex + 1];
    }

    if (minIndex == n - 1) {
        return nums[minIndex] < nums[minIndex - 1];
    }

    int leftIndex = minIndex - 1;
    int rightIndex = minIndex + 1;

    int isLeftBigger = leftIndex >= 0 ? nums[leftIndex] > nums[minIndex] : false;
    int isRightBigger = rightIndex < n ? nums[rightIndex] > nums[minIndex] : false;

    cout << "isLeftBigger" << isLeftBigger << endl;
    cout << "isRightBigger" << isRightBigger << endl;

    return isLeftBigger && isRightBigger;
}

class Node {
public:
    int value;
    Node() :value(-1) {}
    Node(int Value) { value = Value; }

    bool operator==(const Node& other) const {
        return other.value == value;
    }
};

namespace std {
    template<>
    struct hash<Node> {
        size_t operator()(const Node& node) const {
            return hash<int>()(node.value);
        }
    };
}

int main_class03() {
    /*
    vector<int> arr = { 2, 8, -3, 5, 4, 6, -1, 5 , 5 };
    PrintVector("before sort: ", arr);

    sort(arr.begin(), arr.end());
    PrintVector("after sort: ", arr);

    // cout << "7 exsit? " << BinarySearchExist(arr, 7) << endl;
    // cout << "4 exsit? " << BinarySearchExist(arr, 4) << endl;

    int leftIndex = BinarySearchLeftFirstIndex(arr, 5);
    cout << "first index of 5 in arr is: " << leftIndex << endl;

    int rightIdex = BinarySearchRightFirstIndex(arr, 5);
    cout << "end index of 5 in arr is: " << rightIdex << endl;
    */
    // cout << endl;


    /*
    int testTime = GetRandomIntByRandomDevice(0, 10);
    for (int i = 0; i < testTime; i++) {
        cout << endl;
        cout << "current time is: " << i << endl;
        vector<int> arr1 = GetRandomVector(10, 100);
        PrintVector("current array: ", arr1);
        int minIndex = BinarySearchLocalMinIndex(arr1);
        cout << "my method result: " << minIndex << endl;
        cout << "result's correct: " << Check_BinarySearchLocalMinIndex(arr1, minIndex) << endl;
        cout << "current over!" << endl;
    }*/

    unordered_map<Node, string> my;
    Node node1(3);
    Node node2(3);
    my.insert({ node1, "我进来咯" });
    cout << my.at(node1) << endl;
    cout << my.at(node2) << endl;
    // cout << my.count(node2) << endl;

    return 0;
}