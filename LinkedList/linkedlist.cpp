#include <bits/stdc++.h>
#include "list.h"
using namespace std;
int main()
{
    List l;
    l.push_front(1);
    l.push_front(2);
    l.push_front(3);
    l.push_front(4);
    l.push_front(5);
    l.push_front(6);
    l.push_back(3);
    l.push_back(4);
    l.insert(2,2);
    l.insert(11,0);
    l.pop_front();
    l.pop_back();
    l.remove(2);
    Node *head = l.begin();
    while (head != NULL)
    {
        cout << head->getData() << "->";
        head = head->next;
    }
    int key;
    cin>>key;
    cout<<l.search(key)<<endl;
    cout<<l.recursiveSearch(key)<<endl;
    return 0;
}