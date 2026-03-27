#include <iostream>
#include <string>
using namespace std;

int main() {
    string text = "";          
    char undoType[100];      
    char undoChar[100];        
    int topUndo = -1;

    char redoType[100];
    char redoChar[100];
    int topRedo = -1;

    char choice;
    cout << "Welcome to Stack-based Text Editor!" << endl;

    do {
        cout << endl;
        cout << "Menu:" << endl;
        cout << "1. Type a character" << endl;
        cout << "2. Delete last character" << endl;
        cout << "3. Undo last action" << endl;
        cout << "4. Redo last undone action" << endl;
        cout << "5. Show current text" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case '1': { 
            char ch;
            cout << "Enter character: ";
            cin >> ch;

            text += ch;           
            topUndo++;            
            undoType[topUndo] = 'i';
            undoChar[topUndo] = ch;

            topRedo = -1;          
            cout << "Added '" << ch << "'" << endl;
            break;
        }

        case '2': { 
            if (!text.empty()) {
                char ch = text.back();
                text.pop_back();

                topUndo++;        
                undoType[topUndo] = 'd';
                undoChar[topUndo] = ch;

                topRedo = -1;      
                cout << "Deleted '" << ch << "'" << endl;
            }
            else {
                cout << "Nothing to delete!" << endl;
            }
            break;
        }

        case '3': { 
            if (topUndo >= 0) {
                char type = undoType[topUndo];
                char ch = undoChar[topUndo];
                topUndo--;        

                if (type == 'i') {
                    text.pop_back();
                    topRedo++;
                    redoType[topRedo] = 'i';
                    redoChar[topRedo] = ch;
                    cout << "Undo: Insert '" << ch << "'" << endl;
                }
                else {
                    text += ch;
                    topRedo++;
                    redoType[topRedo] = 'd';
                    redoChar[topRedo] = ch;
                    cout << "Undo: Delete '" << ch << "'" << endl;
                }
            }
            else {
                cout << "Nothing to undo!" << endl;
            }
            break;
        }

        case '4': { 
            if (topRedo >= 0) {
                char type = redoType[topRedo];
                char ch = redoChar[topRedo];
                topRedo--;        

                if (type == 'i') {
                    text += ch;
                    topUndo++;
                    undoType[topUndo] = 'i';
                    undoChar[topUndo] = ch;
                    cout << "Redo: Insert '" << ch << "'" << endl;
                }
                else {
                    text.pop_back();
                    topUndo++;
                    undoType[topUndo] = 'd';
                    undoChar[topUndo] = ch;
                    cout << "Redo: Delete '" << ch << "'" << endl;
                }
            }
            else {
                cout << "Nothing to redo!" << endl;
            }
            break;
        }

        case '5': 
            cout << "Current text: \"" << text << "\"" << endl;
            break;

        case '6': 
            cout << "Exiting editor" << endl;
            break;

        default:
            cout << "Invalid choice " << endl;
        }

    } while (choice != '6');

    return 0;
}