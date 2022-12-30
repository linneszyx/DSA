template<typename T>
class Vector
{
    // DATA MEMBERS
    T *arr;
    int cs;
    int ms;

public:
    Vector(int max_size = 1)
    {
        cs = 0;
        ms = max_size;
        arr = new T[ms];
    }
    void push_back(const T d)
    {
        if (cs == ms)
        {
            // create a new array and delete the old one , double the capacity
            T *oldarray = arr;
            ms = 2 * ms;
            arr = new T[ms];
            // copy th elements
            for (int i = 0; i < cs; i++)
            {
                arr[i] = oldarray[i];
            }
            delete[] oldarray;
        }
        arr[cs] = d;
        cs++;
    }
    void pop_back()
    {
        if (cs >= 0)
        {
            cs--;
        }
    }
    bool isEmpty() const
    {
        return cs == 0;
    }
    //Front,Back,At(i), []
    T front () const{
        return arr[0];
    }
    T back() const{
        return arr[cs-1];
    }
    T at(int i) const{
        return arr[i];
    }
    int size() const{
        return cs;
    }
    int capacity() const{
        return ms;
    }
    T operator[](const int i) const{
        return arr[i];
    }
};