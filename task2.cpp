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
    T* minArr;    
    int topIdx;
    int minTop;
    int capacity;
public:
    myStack(int cap) {
        capacity = cap;
        arr = new T[capacity];
        minArr = new T[capacity];
        topIdx = -1;
        minTop = -1;
    }
    ~myStack() {
        delete[] arr;
        delete[] minArr;
    }
    void push(T val) {
        if (isFull()) {
            cout << "stack full" << endl;
            return;
        }
        arr[++topIdx] = val;
     
        if (minTop == -1 || val <= minArr[minTop]) {
            minArr[++minTop] = val;
        }

        cout << "Inserted: " << val << endl;
    }
    T pop() {
        if (isEmpty()) {
            cout << "stack empty" << endl;
            return T();
        }
        T val = arr[topIdx--];
        if (val == minArr[minTop]) {
            minTop--;
        }
        return val;
    }
    T top() const {
        if (isEmpty()) {
            cout << " Stack  empty" << endl;
            return T();
        }
        return arr[topIdx];
    }

    T getMin() const {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return T();
        }
        return minArr[minTop];
    }

    bool isEmpty() const {
        return topIdx == -1;
    }
    bool isFull() const {
        return topIdx == capacity - 1;
    }
    void display() const {
        if (isEmpty()) {
            cout << "Stack  empty" << endl;
            return;
        }
        cout << "Stack top to bottom: ";
        for (int i = topIdx; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    int cap;
    cout << "Enter cap: ";
    cin >> cap;
    myStack<int> s(cap);

    int choice, val;

    do {
        cout << endl;
        cout << "    Stack Menu    " << endl;
        cout << "1- Push element" << endl;
        cout << "2- Pop element" << endl;
        cout << "3- Show top element" << endl;
        cout << "4- Check if stack is empty" << endl;
        cout << "5- Check if stack is full" << endl;
        cout << "6- Display stack elements" << endl;
        cout << "7- Show minimum element" << endl;
        cout << "8- Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter val: ";
            cin >> val;
            s.push(val);
            break;

        case 2:
            cout << "removed: " << s.pop() << endl;
            break;

        case 3:
            cout << "Top: " << s.top() << endl;
            break;

        case 4:
            if (s.isEmpty()) {
                cout << "Stack is empty" << endl;
            }
            else {
                cout << "Stack is not empty" << endl;
            }
            break;

        case 5:
            if (s.isFull()) {
                cout << "Stack is full" << endl;
            }
            else {
                cout << "Stack is not full" << endl;
            }
            break;
            break;

        case 6:
            s.display();
            break;

        case 7:
            cout << "Minimum: " << s.getMin() << endl;
            break;

        case 8:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 8);

    return 0;
}