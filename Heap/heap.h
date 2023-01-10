#include<vector>
using namespace std;
class Heap{
    vector<int> v;
    void heapify(int i){
        int l = 2*i;
        int r = 2*i + 1;
        int min_index = i;
        if(l<v.size() and v[l]<v[i]){
            min_index = l;
        }
        if(r<v.size() and v[r]<v[min_index]){
            min_index = r;
        }
        if(min_index!=i){
            swap(v[i],v[min_index]);
            heapify(min_index);
        }   
    }
    public:
        Heap(int default_size = 10){
            v.reserve(default_size+1);
            v.push_back(-1);
        }
        void push(int data){
            v.push_back(data);
            int index = v.size()-1;
            int par = index/2;
            while (index>1 and v[index]<v[par])
            {
                swap(v[index],v[par]);
                index = par;
                par/=2;
            }
        }
        int top(){
            return v[1];
        }
        void pop(){
            int index = v.size()-1;
            swap(v[1],v[index]);
            v.push_back();
            heapify(1);
        }
        bool isEmpty(){
            return v.size()==1;
        }
};