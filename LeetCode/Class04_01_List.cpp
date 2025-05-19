#include "VectorTool.h"

// ================= node class of list ====================
class Node {
public:
    int value;
    Node* next;

    Node(int data) :value(data), next(nullptr) {}
    Node(Node* dataNode) {
        value = dataNode->value;
        next = dataNode->next;
    }

    Node& operator=(Node& dataNode) {
        if (this == &dataNode) {
            return *this;
        }

        value = dataNode.value;
        next = dataNode.next;
        return *this;   // this本身是个指针，需要解析这个指针，才能返回引用
    }
};

class DoubleNode {
public:
    int value;
    DoubleNode* pre;
    DoubleNode* next;

    DoubleNode(int value) :value(value), pre(nullptr), next(nullptr) {}
    DoubleNode(DoubleNode* dataNode) {
        value = dataNode->value;
        pre = dataNode->pre;
        next = dataNode->next;
    }

    DoubleNode& operator=(DoubleNode& dataNode) {
        if (this == &dataNode) {
            return *this;   // 自赋值检查（地址一致就返回自己就行）
        }

        value = dataNode.value;
        pre = dataNode.pre;
        next = dataNode.next;

        return *this;
    }
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

int main_class04() {
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