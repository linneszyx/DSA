using namespace std;
// A template class.
template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node(T d)
    {
        data = d;
    }
};
template <typename T>
class Stack
{
    Node<T> *head;

public:
    Stack()
    {
        head = NULL;
    }
    void push(T data)
    {
        Node<T> *n = new Node<T>(data);
        n->next = head;
        head = n;
    }
    bool isEmpty()
    {
        return head == NULL;
    }
    // Returning the data of the head node.
    T top()
    {
        return head->data;
    }
    // Deleting the head node.
    void pop()
    {
        if (head != NULL)
        {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
        }
    }
};
