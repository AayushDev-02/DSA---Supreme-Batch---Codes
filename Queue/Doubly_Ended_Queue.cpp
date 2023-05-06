#include <iostream>
using namepspace std;

class Double_Queue
{
public:
    int size;
    int *arr;
    int front;
    int rear;

    Double_Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        rear = -1;
        front = -1;
    }

    void pushRear(int data)
    {
        // check if queue is full
        // TODO: Add one more condition in the full queue condition - { rear == (front-1) % size - 1 }
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % size - 1))
        {
            cout << "Queue is full" << endl;
        }

        // first element
        else if (front == -1 && rear == -1)
        {
            rear = 0;
            front - 0;
            arr[rear] = data;
        }

        // circular nature
        else if (front != 0 && rear == size - 1)
        {
            rear = 0;
            arr[rear] = data;
        }

        // default case
        else
        {
            rear++;
            arr[rear] = data;
        }
    }

    void pushFront(int data){
            //check if queue is full
            //TODO: Add one more condition in the full queue condition - { rear == (front-1) % size - 1 }
            if( ( front==0 && rear == size-1 ) || (rear == (front - 1) % size - 1 ) ){
                cout << "Queue is full" << endl;
                return;
            }

            //first element
            else if(front==-1 && rear == -1){
                rear = 0;
                front=0; 
                arr[front] = data;
            }

            //circular nature
            else if(front == 0 && rear != size-1){
                front = size-1;
                arr[front] = data;
            }
            

            //default case
            else{
                front--;
                arr[front] = data;
            }
    }
};

int
main()
{

    return 0;
}