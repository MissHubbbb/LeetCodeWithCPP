#ifndef NODE_TEMPLATE

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

/*  关于函数编译链接的问题
*   正常情况下
*   1. 普通函数，可以延迟到链接阶段再找定义
*/

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

#endif // !NODE_TEMPLATE