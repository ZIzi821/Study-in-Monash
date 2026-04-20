#include <iostream>
#include "linked-list.cpp" // include the linked list implementation
using namespace std;

int main()
{
    LinkedList list;
    int choice, value, index;

    do
    {
        cout << "\n--- Linked List Menu ---\n";
        cout << "1. Display list\n";
        cout << "2. Add value to end\n";
        cout << "3. Delete a value\n";
        cout << "4. Insert value at index\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            list.display();
            break;
        case 2:
            cout << "Enter value to add: ";
            cin >> value;
            list.add_to_end(value);
            break;
        case 3:
            cout << "Enter value to delete: ";
            cin >> value;
            list.delete_value(value);
            break;
        case 4:
            cout << "Enter index: ";
            cin >> index;
            cout << "Enter value: ";
            cin >> value;
            list.insert_at(index, value);
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
