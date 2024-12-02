#include <iostream>
#include <fstream>
#include "IntBinaryTree.h"
using namespace std;

int CHOICES = 5;

int main_menu();

int main() {
    ifstream reader;
    string fobj;
    IntBinaryTree tree;
    
    reader.open("codes.txt");
    if (!reader)
        cout << "ERROR, unable to open file\n";
    else {
            while (reader) {
                reader >> fobj;
                tree.insertNode(fobj);
            }
        }
    reader.close();
    
    int sel = main_menu();    // user selection from the main menu function
    string entry;
   
    while (sel != CHOICES) {    // while loop to run the main menu options
        switch (sel) {
            case 1:
                cout << "Enter the string do you want to add: ";    // case 1 runs the insert member function
                cin >> entry;
                tree.insertNode(entry);
                cout << "----------------------------" << endl;
                break;
            case 2:
                cout << "Enter the string do you want to delete: ";    // case 2 runs the remove member function
                cin >> entry;
                tree.remove(entry);
                cout << entry << " removed from the tree\n";
                break;
            case 3:
                cout << "Enter the string do you want to search: ";    // case 3 runs the search member function
                cin >> entry;
                if(tree.searchNode(entry)) {
                    cout << entry << " is in the tree\n";
                    cout << "----------------------------" << endl;
                }
                else {
                    cout << entry << " is not in the tree\n";
                    cout << "----------------------------" << endl;
                }
                break;
            case 4:
                cout << "Enter the string do you want to modify: ";    // case 4 runs the search and insert functions to modify a node
                cin >> entry;
                if (tree.searchNode(entry)) {
                    cout << entry << " is in the tree\n";
                    cout << "Enter the string do you want to add: ";
                    cin >> entry;
                    tree.insertNode(entry);
                    cout << "----------------------------" << endl;
                }
                else
                    cout << entry << " is not in the tree\n";
                cout << "----------------------------" << endl;
                break;
            default:
                cout << "Invalid selection.\n";
                break;
        }
        sel = main_menu();    // user enters another option, if the user enters 5 the loop terminates
    }
    
    cout << "Thanks for using the Tree Manager" << endl;    // exit message
    cout << "----------------------------" << endl;

    return 0;
}

int main_menu() {    // main menu function definition
    cout << "MAIN MENU\n";
    cout << "[1] Insert node \n";
    cout << "[2] Delete node\n";
    cout << "[3] Search node\n";
    cout << "[4] Modfy node\n";
    cout << "[5] Quit\n";
    cout << "Choice --> ";
    
    int choice;
    cin >> choice;
    
    while (choice < 1 || choice > CHOICES) {
        cout << "Invalid, again --> ";
        cin >> choice;
    }
    
    cout << "----------------------------" << endl;
    return choice;
    
}
