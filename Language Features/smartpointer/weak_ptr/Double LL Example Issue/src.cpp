#include <iostream>
#include <cassert>
#include <memory>


using namespace std;
template<typename T>
struct doublelist
{
    struct node
    {
        shared_ptr<node> prev;
        shared_ptr<node> next;
        T data;
    };

    void append(T data)
    {   
        auto p = shared_ptr<node>(new node(), [data](node *p){cout << "deleting\t" << data << endl;delete p;});
        p->data = data;
        cout << "adding\t" << data << endl;
        if (!head)
        {
            head = p;
            tail = p;
        }
        else
        {
            tail->next = p;
            p->prev = tail;
            tail = p;
        }
    }

    shared_ptr<node> find(T data)
    {
        auto p=head;
        for (; p->data != data; p= p->next)
            ;
        return p;
    }

    void print()
    {
        for (auto p=head; p; p= p->next)
        {
            cout << p->data << "\tuse_count:\t" << p.use_count()-1 << endl;
        }
    }

    void remove(T data)
    {
        auto p = find(data);
        if (head == p && tail ==p)
        {
            head.reset();
            tail.reset();
        }
        else if (head == p)
        {
            head = head->next;
        }
        else if (tail == p)
        {
            //tail = tail->prev.lock();
            tail = tail->prev;
            tail->next.reset();
        }
        else
        {
            //p->prev.lock()->next = p->next;
            //p->next->prev =  p->prev.lock();
            p->prev->next = p->next;
            p->next->prev =  p->prev;

        }
    }

    shared_ptr<node> head;
    shared_ptr<node> tail;

};

int main()
{
    doublelist<int> ll;
    cout << "adding..." << endl;
    ll.append(10);
    ll.append(20);
    ll.append(30);
    cout << endl;

    cout << "printing..." << endl;
    ll.print();
    cout << endl;
  
    cout << "cleanup..." << endl;
    return 0;
}