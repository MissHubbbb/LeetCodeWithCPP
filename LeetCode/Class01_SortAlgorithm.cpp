#include "VectorTool.h"

void Swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// 1. 选择排序：每次遍历选中其中最小的数的索引，结束遍历后再进行交换，最小数放在最前面不变，指针向右移
void SelectionSort(vector<int>& arr) {
    int n = arr.size();
    if (n == 0 || n < 2) {
        return;
    }

    for (int i = 0; i < n; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            minIndex = arr[j] < arr[minIndex] ? j : minIndex;
        }
        Swap(arr[i], arr[minIndex]);
    }
}

// 2. 冒泡排序：元素两两进行排序，最大数放在最后不再变动，然后指针往左移
void BubbleSort(vector<int>& nums) {
    int n = nums.size();
    if (n < 2) {
        return;
    }

    for (int end = n - 1; end >= 0; end--) {
        for (int begin = 1; begin <= end; begin++) {
            if (nums[begin - 1] > nums[begin]) {
                Swap(nums[begin - 1], nums[begin]);
            }
        }
    }
}

// 3. 插入排序：当前这个数是要插入到这个数之前的有序数组中的
// 只需要遍历 0-i 中，符合前一个数大于后一个数的情况，遍历次数变少了(相对于选择和冒泡来说)
void InsertionSort1(vector<int>& nums) {
    int n = nums.size();
    if (n < 2) {
        return;
    }

    for (int i = 1; i < n; i++) {
        int moveIndex = i;
        while (moveIndex > 0 && nums[moveIndex] < nums[moveIndex - 1]) {
            Swap(nums[moveIndex], nums[moveIndex - 1]);
            moveIndex--;    // 指针向左移动
        }
    }
}

// 3. 插入排序：当前这个数是要插入到这个数之前的有序数组中的
// 只需要遍历 0-i 中，符合前一个数大于后一个数的情况，遍历次数变少了(相对于选择和冒泡来说)
void InsertionSort2(vector<int>& nums) {
    int n = nums.size();
    if (n < 2) {
        return;
    }

    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0 && nums[j - 1] > nums[j]; j--) {
            Swap(nums[j], nums[j - 1]);
        }
    }
}

int main_class1() {
    vector<int> arr = { 6, 3,1,7,2,9,4 };
    PrintVector("before sort: ", arr);

    // SelectionSort(arr);
    // PrintVector("select sort: ", arr);

    // BubbleSort(arr);
    // PrintVector("bubble sort: ", arr);

    InsertionSort2(arr);
    PrintVector("insertion sort2: ", arr);

    return 0;
}