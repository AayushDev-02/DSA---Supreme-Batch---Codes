#include <iostream>
using namespace std;

class CircularQueue {
    public: 
        int size;
        int *arr;
        int front;
        int rear;

        CircularQueue(int size){
            this->size = size;
            arr = new int[size];
            front = -1;
            rear = -1;
        }

        void push(int data){

            //check if queue is full
            //TODO: Add one more condition in the full queue condition - { rear == (front-1) % size - 1 }
            if( ( front==0 && rear == size-1 ) || (rear == (front - 1) % size - 1 ) ){
                cout << "Queue is full" << endl;
            }

            //first element
            else if(front==-1 && rear == -1){
                rear = 0;
                front=0; 
                arr[rear] = data;
            }

            //circular nature
            else if(front != 0 && rear==size-1){
                rear=0;
                arr[rear] = data;
            }
            

            //default case
            else{
                rear++;
                arr[rear] = data;
            }

        }

        void pop(){
            if(front == -1 ){
                cout << "Queue is empty" << endl;
            }
            else if(front == rear){
                arr[front] = -1;
                front = -1;
                rear = -1;
            }
            else if(front == size-1){
                front = 0;
            }
            else{
                front++;
            }
        }
};


int main(){


}