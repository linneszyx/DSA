using namespace std;
class List;
class Node
{
    int data;

public:
    Node *next;
    Node(int d) : data(d), next(NULL) {}
    int getData()
    {
        return data;
    }
    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
    friend class List;
};
class List
{
    Node *head;
    Node *tail;
    int searchHelper(Node *start, int key)
    {
        if (start == NULL)
        {
            return -1;
        }
        if (start->data == key)
        {
            return 0;
        }
        int subIndex = searchHelper(start->next, key);
        if (subIndex == -1)
        {
            return -1;
        }
        return subIndex + 1;
    }

public:
    List() : head(NULL), tail(NULL) {}
    Node *begin()
    {
        return head;
    }
    void push_front(int data)
    {
        if (head == NULL)
        {
            Node *n = new Node(data);
            head = tail = n;
        }
        else
        {
            Node *n = new Node(data);
            n->next = head;
            head = n;
        }
    }
    void push_back(int data)
    {
        if (head == NULL)
        {
            Node *n = new Node(data);
            head = tail = n;
        }
        else
        {
            Node *n = new Node(data);
            tail->next = n;
            tail = n;
        }
    }
    void insert(int data, int pos)
    {
        if (pos == 0)
        {
            push_front(data);
            return;
        }
        Node *temp = head;
        for (int i = 1; i <= pos - 1; i++)
        {
            temp = temp->next;
        }
        Node *n = new Node(data);
        n->next = temp->next;
        temp->next = n;
    }
    int search(int key)
    {

        Node *temp = head;
        int idx = 0;

        while (temp != NULL)
        {
            if (temp->data == key)
            {
                return idx;
            }
            idx++;
            temp = temp->next;
        }
        return -1;
    }
    int recursiveSearch(int key)
    {
        int idx = searchHelper(head, key);
        return idx;
    }
    void pop_front()
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    void pop_back()
    {
        Node *temp = head;
        Node *prev = NULL;
        while (temp->next)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        delete temp;
    }
    void remove(int pos)
    {
        if (pos == 0)
        {
            pop_front();
        }
        Node *temp = head;
        Node *prev = head;
        for (int i = 1; i <= pos - 1; i++)
        {
            prev = temp;
            temp = temp->next;
            if (temp == NULL)
                break;
        }
        if (temp != NULL)
        {
            if (temp == NULL)
            {
                head = head->next;
            }
            prev->next = temp->next;
            temp->next = NULL;
            delete temp;
        }
    }
    ~List()
    {
        if (head != NULL)
        {
            delete head;
            head = NULL;
        }
    }
};