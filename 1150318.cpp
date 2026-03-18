#include <iostream>
using namespace std;

// ==================== Stack ====================
class Stack {
private:
    int top;
    int capacity;
    int* arr;

public:
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow，時間複雜度: O(1)\n";
            return;
        }
        arr[++top] = value;
        cout << "加入 " << value << " (push)，時間複雜度: O(1)\n";
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow，時間複雜度: O(1)\n";
            return;
        }
        cout << "移除 " << arr[top] << " (pop)，時間複雜度: O(1)\n";
        top--;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack 為空\n";
            return;
        }
        cout << "Stack (上→下): ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << "，時間複雜度: O(n)\n";
    }
};

// ==================== Queue ====================
class Queue {
private:
    int front;
    int rear;
    int capacity;
    int* arr;

public:
    Queue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = 0;
        rear = -1;
    }

    bool isEmpty() {
        return rear < front;
    }

    bool isFull() {
        return rear == capacity - 1;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow，時間複雜度: O(1)\n";
            return;
        }
        arr[++rear] = value;
        cout << "加入 " << value << " (enqueue)，時間複雜度: O(1)\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow，時間複雜度: O(1)\n";
            return;
        }
        cout << "移除 " << arr[front] << " (dequeue)，時間複雜度: O(1)\n";
        front++;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue 為空\n";
            return;
        }
        cout << "Queue (前→後): ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << "，時間複雜度: O(n)\n";
    }
};

// ==================== 主程式 ====================
int main() {
    int size, n, value;

    cout << "請輸入 Stack 容量: ";
    cin >> size;
    Stack s(size);

    cout << "請輸入要加入 Stack 的數量: ";
    cin >> n;

    cout << "請輸入 " << n << " 個數字:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        s.push(value);
    }

    s.display();

    cout << "\n執行 pop:\n";
    s.pop();
    s.display();

    cout << "\n========================\n";

    cout << "請輸入 Queue 容量: ";
    cin >> size;
    Queue q(size);

    cout << "請輸入要加入 Queue 的數量: ";
    cin >> n;

    cout << "請輸入 " << n << " 個數字:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        q.enqueue(value);
    }

    q.display();

    cout << "\n執行 dequeue:\n";
    q.dequeue();
    q.display();

    return 0;
}
