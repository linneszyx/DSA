#include <iostream>
#include <string>
using namespace std;

template <typename T>
//A node class that is used to create a linked list.
class Node
{
public:
    string key;
    T value;
    Node *next;

    Node(string key, T value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }

    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

template <typename T>
class Hashtable
{

    Node<T> **table;
    int current_size;
    int ts;

    int hashFn(string key)
    {

        int idx = 0;
        int power = 1;

        for (auto ch : key)
        {
            idx = (idx + ch * power) % ts;
            power = (power * 29) % ts;
        }
        return idx;
    }

    
    void rehash()
    {

        Node<T> **oldTable = table;
        int oldTs = ts;

        current_size = 0;
        ts = 2 * ts + 1;
        table = new Node<T> *[ts];

        for (int i = 0; i < ts; i++)
        {
            table[i] = NULL;
        }

        for (int i = 0; i < oldTs; i++)
        {

            Node<T> *temp = oldTable[i];

            while (temp != NULL)
            {
                string key = temp->key;
                T value = temp->value;

                insert(key, value);
                temp = temp->next;
            }

            if (oldTable[i] != NULL)
            {
                delete oldTable[i];
            }
        }
        delete[] oldTable;
    }

public:
    Hashtable(int default_size = 7)
    {
        current_size = 0;
        ts = default_size;

        table = new Node<T> *[ts];

        for (int i = 0; i < ts; i++)
        {
            table[i] = NULL;
        }
    }
    void insert(string key, T val)
    {
       
        int idx = hashFn(key);

        Node<T> *n = new Node<T>(key, val);

        n->next = table[idx];
        table[idx] = n;

        current_size++;
        float load_factor = current_size / float(ts);
        if (load_factor > 0.7)
        {
            rehash();
        }
    }

    T *search(string key)
    {
        int idx = hashFn(key);

        Node<T> *temp = table[idx];

        while (temp != NULL)
        {
            if (temp->key == key)
            {
                return &temp->value;
            }
            temp = temp->next;
        }

        return NULL;
    }

    T &operator[](string key)
    {

        T *valueFound = search(key);
        if (valueFound == NULL)
        {
            T object;
            insert(key, object);
            valueFound = search(key);
        }

        return *valueFound;
    }

    void print()
    {

        for (int i = 0; i < ts; i++)
        {
            cout << "Bucket " << i << "->";

            Node<T> *temp = table[i];
            while (temp != NULL)
            {
                cout << temp->key << "->";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};