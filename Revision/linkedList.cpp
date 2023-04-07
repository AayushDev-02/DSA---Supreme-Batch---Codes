#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node(){
        int value = this-> data;

        //code to free memory
        if(this-> next != NULL){
            delete next;
            this->next = NULL;

        }

        cout << "Memory is free for node with data" << value << endl; 
    }
};

// insertion at head
void insertAtHead(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void print(Node *&head)
{

    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << endl;
}

void insertAtTail(Node* &tail, int data ){
    Node* temp = new Node(data);

    tail->next = temp;
    temp = tail;
}

void insertAtPosition(Node* &tail, Node* &head, int position, int data){
    
    if(position == 1){
        insertAtHead(head, data);
    }
    
    Node* temp = head;
    int i=1;

    while(i!=position-1){
        temp = temp->next;
        i++;
    }

    if(temp->next == NULL){
        insertAtTail(tail, data);
    }

    Node* newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;

}

void deleteNode(Node* head, int position){
    Node* temp = head;

    int i = 1;
    while(i!=position - 1){
        temp = temp->next;
        i++;
    }

    Node
}

int main()
{

    Node *node = new Node(100);

    cout << node->data << endl;
    cout << node->next << endl;

    // creating a head
    Node *head = node;
    cout << head << endl;

    // creating a tail
    Node *tail = node;

    insertAtHead(head, 12);

    print(head);

    insertAtHead(head, 154);
    print(head);

    insertAtTail(tail, 44);
    print(head);

    insertAtPosition(tail, head, 2, 55);
    print(head);

    deleteNode(head , 8);
    print(head);
    

    return 0;
}