#include "VectorTool.h"

// 浅拷贝（shallow copy）：只是拷贝指针的地址，多个对象指向同一块内存。（某个地方释放了，但是其他地方还在用，就会导致其他指针悬空或者崩溃）
// 深拷贝（deep copy）：会重新分配内存并复制内容，两个对象互不影响。

// ================= node class of list ====================
class Node {
public:
    int value;
    Node* next;

    Node(int data) :value(data), next(nullptr) {}
    Node(const Node& dataNode) {    // 深拷贝
        value = dataNode.value;
        // 每次调用 Node(*dataNode.next)，其实是处理链表中的“下一个节点”，所以不会死循环
        next = dataNode.next ? new Node(*dataNode.next) : nullptr;
    }

    Node& operator=(const Node& dataNode) {
        if (this == &dataNode) {
            return *this;
        }

        value = dataNode.value;
        delete next;
        next = dataNode.next ? new Node(*dataNode.next) : nullptr;
        return *this;   // this本身是个指针，需要解析这个指针，才能返回引用
    }

    /* 因为后面有设置释放函数，所以这个析构函数可写可不写
    ~Node() {
        delete next;    // 因为是链表结构，所以这里的析构其实是有问题的
        next = nullptr;
    }*/
};

class DoubleNode {
public:
    int value;
    DoubleNode* pre;
    DoubleNode* next;

    DoubleNode(int value) :value(value), pre(nullptr), next(nullptr) {}
    DoubleNode(const DoubleNode& dataNode) {    // 浅拷贝
        value = dataNode.value;
        pre = dataNode.pre ? new DoubleNode(*dataNode.pre) : nullptr;
        next = dataNode.next ? new DoubleNode(*dataNode.next) : nullptr;
    }

    DoubleNode& operator=(const DoubleNode& dataNode) {
        if (this == &dataNode) {
            return *this;   // 自赋值检查（地址一致就返回自己就行）
        }

        value = dataNode.value;
        pre = dataNode.pre ? new DoubleNode(*dataNode.pre) : nullptr;
        next = dataNode.next ? new DoubleNode(*dataNode.next) : nullptr;

        return *this;
    }

    /* 因为后面有设置释放函数，所以这个析构函数可写可不写
    ~DoubleNode() {
        delete pre;
        pre = nullptr;

        delete next;
        next = nullptr;
    }*/
};

// ================= print ==================
void PrintList(Node* node) {
    while (node != nullptr) {
        cout << node->value << endl;
        node = node->next;
    }
}

void PrintDoubleListNormally(DoubleNode* node) {
    while (node != nullptr) {
        cout << node->value << endl;
        node = node->next;
    }
}

void PrintDoubleListUnNormally(DoubleNode* node) {
    while (node != nullptr) {
        cout << node->value << endl;
        node = node->pre;
    }
}

// ===================== free ===================
void FreeLinkedList(Node* node) {
    if (node == nullptr) {
        return;
    }

    while (node != nullptr) {
        Node* temp = node;
        node = node->next;
        delete temp;
    }
}

void FreeDoubleNodeList(DoubleNode* node) {
    if (node == nullptr) {
        return;
    }

    while (node != nullptr) {
        DoubleNode* temp = node;
        node = node->next;
        delete temp;
        temp = nullptr;
    }
}

// ================== reverse function ===================
Node* ReverseLinkedList(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }

    Node* preNode = nullptr;
    Node* nextNode = nullptr;

    while (head != nullptr) {
        nextNode = head->next;
        head->next = preNode;
        preNode = head;
        head = nextNode;
    }

    return preNode;
}

DoubleNode* ReverseDoubleList(DoubleNode* head) {
    if (head == nullptr) {
        return nullptr;
    }

    DoubleNode* nextNode = nullptr;
    DoubleNode* preNode = nullptr;

    while (head != nullptr) {
        nextNode = head->next;
        head->next = preNode;
        head->pre = nextNode;
        preNode = head;
        head = nextNode;
    }

    return preNode;
}

int main_class04_01() {
    /* Node
    Node* first = new Node(1);
    first->next = new Node(2);
    first->next->next = new Node(3);
    first->next->next->next = new Node(4);

    cout << "Before reverse: " << endl;
    Node* printNode = new Node(first);
    PrintList(printNode);

    cout << endl;
    cout << "After reverse: " << endl;
    Node* test = ReverseLinkedList(first);
    PrintList(test);

    FreeLinkedList(test);
    */

    DoubleNode* first = new DoubleNode(1);
    first->pre = nullptr;
    first->next = new DoubleNode(2);
    first->next->pre = first;
    first->next->next = new DoubleNode(3);
    first->next->next->pre = first->next;
    first->next->next->next = new DoubleNode(4);
    first->next->next->next->pre = first->next->next;

    DoubleNode* endNode = first->next->next->next;

    cout << "print double node normally: " << endl;
    PrintDoubleListNormally(first);

    cout << endl;
    cout << "print double node unnormally: " << endl;
    PrintDoubleListUnNormally(endNode);

    cout << endl;
    cout << "after reverse double list: " << endl;
    DoubleNode* reverseDoubleNode = ReverseDoubleList(first);
    PrintDoubleListNormally(reverseDoubleNode);

    FreeDoubleNodeList(reverseDoubleNode);

    return 0;
}