#include "Node_template.h"

template <class T>
class MyQueue
{
public:
    MyQueue() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    bool IsEmpty() {
        return size == 0;
    }

    int Size() {
        return size;
    }

    void AddElement(T value) {
        Node<T>* newEle = new Node<T>(value);
        if (tail == nullptr) {  // 如果末尾为空，说明目前这个队列没有任何元素
            head = newEle;      // 就让头和尾两个指针都指向当前这个新加入的元素
            tail = newEle;
        }
        else {  // 否则，让尾巴指针指向这个新元素
            tail->next = newEle;
            tail = newEle;
        }

        size++; // 队列数量加1
    }

    // 把队列头部元素推出去，并获取其值
    // 在使用的时候创建T，然后自己手动释放
    T Poll() {
        if (head == nullptr) {
            return T();
        }

        T ans = head->value;
        Node<T>* temp = head;
        head = head->next;
        size--;
        delete temp;
        temp = nullptr;


        if (head == nullptr) {
            tail = nullptr;
        }

        return ans;
    }

    // 获取顶部元素的值
    T Peek() {
        if (head == nullptr) {
            // T t = T(); 是值初始化，会清零； 
            // C++ 的 值初始化（value initialization） 规则
            return T();
        }

        T ans = head->value;

        return ans;
    }

    ~MyQueue() {
        FreeLinkedList(head);
        head = nullptr;
        tail = nullptr;
    }

private:
    Node<T>* head;
    Node<T>* tail;
    int size;
};

int main_class04_02() {
    /* Node类模板的使用测试
    Node<int>* testNode = new Node<int>(6);
    Node<int>* testNode1(testNode);
    PrintList(testNode1);
    FreeLinkedList(testNode1);
    */

    MyQueue<int> myqu;
    myqu.AddElement(1);
    myqu.AddElement(2);
    myqu.AddElement(3);
    myqu.AddElement(4);
    myqu.AddElement(5);

    cout << myqu.Peek() << endl;

    cout << myqu.Poll() << endl;
    cout << myqu.Poll() << endl;
    cout << myqu.Poll() << endl;
    cout << myqu.Poll() << endl;
    cout << myqu.Poll() << endl;

    return 0;
}