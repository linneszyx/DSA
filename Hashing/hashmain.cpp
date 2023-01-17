#include<bits/stdc++.h>
#include "hashtable.h"
using namespace std;
int main()
{
    Hashtable<int> ht;
    ht.insert("Pen",10);
    ht.insert("Pencil",1001);
    ht.insert("Eraser",1034); 
    ht.insert("Sharpener",124);
    ht.insert("Scale",11);
    ht.insert("Dot Pen",19);
    ht.insert("Black Pen",1230);
    ht.print();
    string stationary;
    cout<<"Enter To Search : ";
    cin>>stationary;
    int *cost = ht.search(stationary);
    if(cost!=NULL){
        cout<<"Price Of Stationary is \n"<<*cost<<endl;
    }
    else{
        cout<<"Stationary not present\n";
    }
    ht["newpen"] = 2001;
    cout<<"New Pen cost : "<<ht["newpen"]<<endl;
    ht["newpen"] += 2002;
    cout<<"New Pen updated cost : "<<ht["newpen"]<<endl;
return 0;
}