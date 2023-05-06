#include <iostream>
#include <queue>
using namespace std;

int main(){

    //stl queue - FIFO
    queue<int> q;

    //insertion 
    q.push(5);
    q.push(15);
    q.push(25);
    q.push(35);

    //size
    cout << "Size of the queue is :" <<  q.size() << endl;

    //popping
    q.pop();

    cout << "Size of the queue is :" <<  q.size() << endl;


    //check empty
    if(q.empty()){
        cout << "Queue is empty"  << endl;
    }
    else{
        cout << "Queue is not empty" << endl;
    }


    //front element
    cout << "Front element is :" << q.front();
    return 0;
}