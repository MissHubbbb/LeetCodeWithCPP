#include "Node_template.h"

template <class T>
class MyStack
{
public:
    MyStack() {
        head = nullptr;
        size = 0;
    }

    int Size() {
        return size;
    }

    void Push(T value) {
        Node<T>* temp = new Node<T>(value);
        if (head == nullptr) {
            head = temp;
        }
        else {
            temp->next = head;
            // 这里的 head 和 temp 都是 Node<T>* 类型的指针，做的只是指针之间的浅拷贝，只是在内存中拷贝地址
            // 所以不需要释放temp
            head = temp;
        }

        size++;
    }

    T Pop() {
        if (head == nullptr) {
            return T();
        }

        Node<T>* temp = head;
        T ans = temp->value;
        head = head->next;
        delete temp;
        temp = nullptr;
        size--;

        return ans;
    }

    ~MyStack() {
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            temp = nullptr;
        }
    }

private:
    Node<T>* head;
    int size;
};

int main() {
    MyStack<int> ms;
    ms.Push(78);
    ms.Push(12);
    ms.Push(9);
    ms.Push(6);
    ms.Push(1);

    cout << "current stack size: " << ms.Size() << endl;

    cout << ms.Pop() << endl;
    cout << ms.Pop() << endl;
    cout << ms.Pop() << endl;

    cout << "current stack size: " << ms.Size() << endl;

    cout << ms.Pop() << endl;
    cout << ms.Pop() << endl;

    return 0;
}
