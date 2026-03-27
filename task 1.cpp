#include <iostream>
using namespace std;
template <typename T>
class AbstractStack {
public:
    virtual void push(T val) = 0;
    virtual T pop() = 0;
    virtual T top() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual ~AbstractStack() {}
};
template <typename T>
class myStack : public AbstractStack<T> {
private:
    T* arr;
    int topIdx;
    int capacity;

public:
    myStack(int cap) {
        capacity = cap;
        arr = new T[capacity];
        topIdx = -1;
    }
    ~myStack() {
        delete[] arr;
    }
    void push(T val) {
        if (isFull()) {
            cout << "Stack Full" << endl;
            return;
        }
        arr[++topIdx] = val;
        cout << "inserted: " << val << endl;
    }

    T pop() {
        if (isEmpty()) {
            cout << "Stack empty" << endl;
            return T(); 
        }
        return arr[topIdx--];
    }
    T top() const {
        if (isEmpty()) {
            cout << "Stack is Empty!" << endl;
            return T();
        }
        return arr[topIdx];
    }
    bool isEmpty() const {
        return topIdx == -1;
    }
    bool isFull() const {
        return topIdx == capacity - 1;
    }
    void display() const {
        if (isEmpty()) {
            cout << "sTack empty" << endl;
            return;
        }



        cout << "stack elements Tpo to bottom: ";
        for (int i = topIdx; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    int cap;
    cout << "Enter stack capacity: ";
    cin >> cap;

    myStack<int> s(cap);

    int choice, val;

    do {
        cout << endl;
        cout << "     Stack Menu      " << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Top" << endl;
        cout << "4. Display" << endl;
        cout << "5. Check Empty" << endl;
        cout << "6. Check Full" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            s.push(val);
            break;

        case 2:
            cout << "Removed: " << s.pop() << endl;
            break;

        case 3:
            cout << "Top: " << s.top() << endl;
            break;

        case 4:
            s.display();
            break;

        case 5:
            cout << (s.isEmpty() ? "Stack is Empty" : "Stack is Not Empty") << endl;
            break;

        case 6:
            cout << (s.isFull() ? "Stack is Full" : "Stack is Not Full") << endl;
            break;

        case 0:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 0);

    return 0;
}