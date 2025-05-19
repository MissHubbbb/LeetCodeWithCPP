/*
#include <iostream>
#include <vector>

using namespace std;

template<typename T>
struct ListNode<T> {
public:
    ListNode(T val)
    {
        value = val;
        last = nullptr;
        next = nullptr;
    }

    ~ListNode()
    {
        value = 0;
        last = nullptr;
        next = nullptr;
    }

    ListNode* last;
    ListNode* next;
    T value;
};

template<typename T>
class MyStack<T> {
public:
    MyStack(T val)
    {
        top = {nullptr, nullptr, val};
        bottom = top;
    }

    void push(T val)
    {
        ListNode<T>* cur = {nullptr, nullptr, val};
        cur->last = top;
        top->next = cur;
        top = cur;
        delete cur;
    }

    T pop()
    {

    }

private:
    ListNode<T>* top;
    ListNode<T>* bottom;
};

void main()
{
    cout << "test" << endl;
    vector<int> vi{1,2,3,4,5,6};
    for(int t : vi)
    {

    }

    cin.get();
}
*/