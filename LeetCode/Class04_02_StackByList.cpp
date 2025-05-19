#include <iostream>

using namespace std;

template <class T>
class Node
{
public:
    Node();
    Node(T data);
    Node(const Node& dataNode);
    Node<T>& operator=(const Node& curNode);
    ~Node();

    T value;
    Node* next;
};

template <class T>
Node<T>::Node()
{
    value = 0;
    next = nullptr;
}

template <class T>
Node<T>::Node(T data) {
    value = data;
    next = nullptr;
}

template <class T>
Node<T>::Node(const Node& dataNode) {
    value = dataNode.value;
    next = dataNode.next ? new Node<T>(*dataNode.next) : nullptr;
}

template <class T>
Node<T>& Node<T>::operator=(const Node<T>& curNode) {
    if (this == &curNode) {
        return *this;
    }

    value = curNode.value;
    next = curNode.next ? new Node<T>(*curNode.next) : nullptr;
    return *this;       // this本身是个指针，需要解析这个指针，才能返回引用
}

template <class T>
Node<T>::~Node()
{
    // 析构函数中 if (this != nullptr) 是无意义的，this 永远不可能是 nullptr，因为调用析构函数意味着对象已经存在，所以这句判断是冗余的。
    // if (this != nullptr)

    delete next;    // 这里的析构方式是「递归释放整个链表」，这在某些场景中是危险的
    next = nullptr; // 应该置空指针防止野指针
}

template <class T>
class MyStack
{
public:
    MyStack();
    ~MyStack();

private:

};

template <class T>
MyStack<T>::MyStack()
{
}

template <class T>
MyStack<T>::~MyStack()
{
}

int main() {
    Node<int>* testNode = new Node<int>(6);
    Node<int>* testNode1(testNode);
    cout << testNode1->value << endl;

    return 0;
}