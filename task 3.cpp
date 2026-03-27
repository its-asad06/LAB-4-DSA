#include <iostream>
using namespace std;

class myCarStack {
private:
    string* arr;
    int topIdx;
    int capacity;

public:
    myCarStack(int size) {
        capacity = size;
        arr = new string[capacity];
        topIdx = -1;
    }
    ~myCarStack() {
        delete[] arr;
    }
    bool isEmpty() {
        return topIdx == -1;
    }

    bool isFull() {
        return topIdx == capacity - 1;
    }
    void push(string car) {
        if (isFull()) {
            cout << "Parking full" << endl;
            return;
        }
        arr[++topIdx] = car;
        cout << "Car Parked: " << car << endl;
    }
    string pop() {
        if (isEmpty()) return "";
        return arr[topIdx--];
    }
    void display() {
        if (isEmpty()) {
            cout << "No cars parked" << endl;
            return;
        }

        cout << "Cars Top to bottom:" << endl;
        for (int i = topIdx; i >= 0; i--) {
            cout << arr[i] << endl;
        }
    }
    int count() {
        return topIdx + 1;
    }

    bool search(string car) {
        for (int i = 0; i <= topIdx; i++) {
            if (arr[i] == car)
                return true;
        }
        return false;
    }
    void removeCar(string car) {
        myCarStack temp(capacity);
        bool found = false;
        while (!isEmpty()) {
            string c = pop();
            if (c == car) {
                cout << "Car Removed: " << car << endl;
                found = true;
                break;
            }
            else {
                temp.push(c);
            }
        }
        if (!found) {
            cout << "Car not found!" << endl;
        }

        while (!temp.isEmpty()) {
            push(temp.pop());
        }
    }
};

int main() {
    int size = 8; 
    myCarStack parking(size);
    int choice;
    string car;
    do {
        cout << endl;
        cout << "1. Park Car" << endl;
        cout << "2. Remove Car" << endl;
        cout << "3. Display Cars" << endl;
        cout << "4. Total Cars" << endl;
        cout << "5. Search Car" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter car number: ";
            cin >> car;
            parking.push(car);
            break;

        case 2:
            cout << "Enter car to remove: ";
            cin >> car;
            parking.removeCar(car);
            break;

        case 3:
            parking.display();
            break;

        case 4:
            cout << "Total Cars: " << parking.count() << endl;
            break;

        case 5:
            cout << "Enter car to search: ";
            cin >> car;
            if (parking.search(car))
                cout << "car found" << endl;
            else
                cout << "car fot found" << endl;
            break;

        case 6:
            cout << "exit" << endl;
            break;

        default:
            cout << "nivalid" << endl;
        }

    } while (choice != 6);

    return 0;
}