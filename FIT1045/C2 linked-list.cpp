#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList
{
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList()
    {
        Node* current = head;
        while (current != nullptr)
        {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    void display() const
    {
        Node* current = head;
        cout << "List: ";
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void add_to_end(int value)
    {
        Node* newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
    }

    void delete_value(int value)
    {
        if (head == nullptr) return;

        if (head->data == value)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->data != value)
        {
            current = current->next;
        }

        if (current->next != nullptr)
        {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    void insert_at(int index, int value)
    {
        Node* newNode = new Node(value);
        if (index == 0)
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* current = head;
        for (int i = 0; current != nullptr && i < index - 1; i++)
        {
            current = current->next;
        }

        if (current == nullptr)
        {
            cout << "Index out of range, inserting at end." << endl;
            add_to_end(value);
            delete newNode; // avoid leak, since add_to_end already created one
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
    }
};
