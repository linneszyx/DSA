#include <vector>
using namespace std;
template <typename T>
class Stack
{
   vector<T> v;

public:
   void push(T data)
   {
      v.push_back(data);
   }
   void pop()
   {
      v.pop_back();
   }
   T top()
   {
      int lastIdx = v.size() - 1;
      return v[lastIdx];
   }
   bool empty()
   {
      return v.size() == 0;
   }
};