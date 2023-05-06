#include <iostream>
#include <vector>
using namespace std;

class Queue {
public:
    int *arr;
    int size;
    int front;
    int rear;

    //initializing the variables in constructor
    Queue(int n){
        this->size = n;
        arr= new int[size];
        front = 0;
        rear = 0;
    }

    void push(int data){
        if(rear == size){
            cout << "Queue is full " << endl;
        }
        else{
            arr[rear] = data;
            rear++;
        }
    }

    int getSize(){
        return rear-front;
    }

    void pop(){
        if(front == rear){
            cout << "Queue is empty" << endl;
        }
        else{
            arr[front]  = -1;
            front++;
            if(front == rear){
                front = 0;
                rear = 0;
            }
        }
    }

    bool isEmpty(){
        if(front == rear){
            return true;
        }else{
            return false;
        }
    }

    int getFront(){
        if(front == rear){
            cout << "Queue is empty" << endl;
            return -1;
        }else{
            return arr[front];
        }
    }

};


int main(){

    Queue q(10);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    cout << "Size of the queue :" << q.getSize() << endl;

    q.pop();
    q.pop();

    cout << "Size of the queue :" << q.getSize() << endl;

    cout << "Front element: " << q.getFront() << endl;

    if(q.isEmpty()){
        cout << "Queue is empty" << endl;
    }
    else{
        cout << "Queue is not empty" << endl;
    }




    return 0;
}