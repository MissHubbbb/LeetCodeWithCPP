#include <iostream>

using namespace std;

template <class T>
class Node
{
public:
    Node() : value(T()), next(nullptr) {}
    Node(T data) :value(data), next(nullptr) {}
    Node(const Node& dataNode) {
        value = dataNode.value;
        next = dataNode.next ? new Node<T>(*dataNode.next) : nullptr;
    }

    Node<T>& operator=(const Node& curNode) {
        if (this == &curNode) {
            return *this;
        }

        value = curNode.value;
        delete next;
        next = curNode.next ? new Node<T>(*curNode.next) : nullptr;
        return *this;       // this本身是个指针，需要解析这个指针，才能返回引用
    }

    // 链表单个节点的析构函数有风险，最好还是在使用完后手动释放
    /*
    ~Node() {
        // 析构函数中 if (this != nullptr) 是无意义的，this 永远不可能是 nullptr，因为调用析构函数意味着对象已经存在，所以这句判断是冗余的。
        // if (this != nullptr)

        delete next;    // 这里的析构方式是「递归释放整个链表」，这在某些场景中是危险的
        next = nullptr; // 应该置空指针防止野指针
    }*/

    /* 安全版本
    ~Node() {
        next = nullptr;     // 不做递归delete
    }*/

    T value;
    Node<T>* next;
};

template <class T>
void PrintList(Node<T>* node) {
    while (node != nullptr) {
        cout << node->value << endl;
        node = node->next;
    }
}

template <class T>
void FreeLinkedList(Node<T>* node) {
    if (node == nullptr) {
        return;
    }

    while (node != nullptr) {
        Node<T>* temp = node;
        node = node->next;
        delete temp;
    }

    if (node == nullptr)
        cout << "Node cleaned!" << endl;
}

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

int main() {
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