#include <iostream>
#include <cstddef> // for NULL

using namespace std;

// Node structure for linked list
struct Node
{
    int data;
    Node *next;

    Node(int value) : data(value), next(NULL) {}
};

// Linked list class
class LinkedList
{
private:
    Node *head; // Head of the linked list

public:
    LinkedList() : head(NULL) {}

    // Function to add a node to the linked list
    void addNode(int value)
    {
        Node *newNode = new Node(value);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Function to sort the linked list using merge sort
    Node *merge(Node *left, Node *right)
    {
        if (left == NULL)
            return right;
        if (right == NULL)
            return left;

        Node *result = NULL;

        if (left->data <= right->data)
        {
            result = left;
            result->next = merge(left->next, right);
        }
        else
        {
            result = right;
            result->next = merge(left, right->next);
        }

        return result;
    }

    // Function to perform merge sort on linked list
    Node *mergeSort(Node *start)
    {
        if (start == NULL || start->next == NULL)
        {
            return start;
        }

        Node *middle = getMiddle(start);
        Node *nextToMiddle = middle->next;

        middle->next = NULL;

        Node *left = mergeSort(start);
        Node *right = mergeSort(nextToMiddle);

        return merge(left, right);
    }

    // Function to find the middle of linked list
    Node *getMiddle(Node *start)
    {
        if (start == NULL)
            return NULL;

        Node *slow = start;
        Node *fast = start->next;

        while (fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }

        return slow;
    }

    // Function to sort the linked list
    void sortList()
    {
        head = mergeSort(head);
    }

    // Function to delete the last element from the linked list
    void deleteLast()
    {
        if (head == NULL)
        {
            cout << "Linked list is empty. Cannot delete.\n";
            return;
        }
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }
        Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }

    // Function to add multiple elements to the linked list
    void addElements(int numElements)
    {

        for (int i = 0; i < numElements; ++i)
        {
            cout << "Enter value for Node " << i + 1 << ": ";
            int value;
            cin >> value;
            addNode(value);
        }
    }
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

// Stack class using array
class Stack
{
private:
    static const int MAX_SIZE = 5; // Maximum size of the stack
    int arr[MAX_SIZE];             // Array to store elements
    int top;                       // Index of the top element

public:
    Stack() : top(-1) {}

    // Function to check if the stack is empty
    bool isEmpty()
    {
        return top == -1;
    }

    // Function to check if the stack is full
    bool isFull()
    {
        return top == MAX_SIZE - 1;
    }

    // Function to push an element onto the stack
    void push(int value)
    {
        if (isFull())
        {
            cout << "Stack is full. Cannot push.\n";
            return;
        }
        arr[++top] = value;
    }

    // Function to pop an element from the stack
    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty. Cannot pop.\n";
            return;
        }
        --top;
    }

    // Function to add multiple elements to the stack
    void addElements(int numElements)
    {
        for (int i = 0; i < numElements; ++i)
        {
            cout << "Enter value to push onto stack: ";
            int value;
            cin >> value;
            push(value);
        }
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty.\n";
            return;
        }

        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Queue class using array
class Queue
{
private:
    static const int MAX_SIZE = 5; // Maximum size of the queue
    int arr[MAX_SIZE];             // Array to store elements
    int front;                     // Index of the front element
    int rear;                      // Index of the rear element

public:
    Queue() : front(-1), rear(-1) {}

    // Function to check if the queue is empty
    bool isEmpty()
    {
        return front == -1;
    }

    // Function to check if the queue is full
    bool isFull()
    {
        return (rear + 1) % MAX_SIZE == front;
    }

    // Function to add an element to the queue
    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue is full. Cannot enqueue.\n";
            return;
        }
        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % MAX_SIZE;
        }
        arr[rear] = value;
    }

    // Function to remove an element from the queue
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % MAX_SIZE;
        }
    }

    // Function to add multiple elements to the queue
    void addElements(int numElements)
    {

        for (int i = 0; i < numElements; ++i)
        {
            cout << "Enter value to add to queue : ";
            int value;
            cin >> value;
            enqueue(value);
        }
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty.\n";
            return;
        }

        int i = front;
        while (i != rear)
        {
            cout << arr[i] << " ";
            i = (i + 1) % MAX_SIZE;
        }
        cout << arr[rear] << endl;
    }
};

int main()
{
    LinkedList linkedList;
    Stack stack;
    Queue queue;

    // Perform operations based on user's choice
    int choice;
    do
    {
        cout << "\nEnter your choice \n";
        cout << "1. Operate on  Linked List \n";
        cout << "2. Operate on  Stack \n";
        cout << "3. Operate on  Queue \n";
        cout << "0. exit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            linkedList.addElements(4); // Add 4 elements to linked list
            cout << "Linked list after adding 4 elements : ";
            linkedList.display();
            linkedList.sortList();
            linkedList.deleteLast();
            cout << "\nLinked list after sorting its elements and deletion of the last element: ";
            linkedList.display();
            cout << "\n";

            break;
        case 2:
            stack.addElements(5); // Add 5 elements to stack
            stack.pop();          // Pop one element from the stack
            cout << "Stack elements after 5 pushing and 1 pop operations: ";
            stack.display();
            cout << "\n";
            break;
        case 3:
            queue.addElements(5); // Add 5 elements to queue
            queue.dequeue();
            queue.display(); // Dequeue one element from the queue
            cout << "Queue elements after  5 enqueue and 1 dequeue operations: ";
            queue.display();
            cout << "\n";
            break;
        case 0:
            cout << "Exiting program  ...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}

