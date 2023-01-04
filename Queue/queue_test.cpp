#include<iostream>
#include "queue.h"
using namespace std;
int main(){
    Queue myq(6);
    myq.push(1);
    myq.push(2);
    myq.push(3);
    myq.push(4);
    myq.push(5);
    myq.push(6);
    myq.pop();
    myq.pop();
    myq.pop();
    myq.push(7);
    while(!myq.empty()){
        cout<<myq.getFront()<<endl;
        myq.pop();
    }
    return 0;
}