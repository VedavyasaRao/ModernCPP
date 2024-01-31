#include <iostream>
#include <cassert>
#include <memory>

using namespace std;
template<typename T>
struct doublelist
{
    struct node;
    using LLNODE = shared_ptr<node>;
    using LLNODEptr = shared_ptr<node>*;

    struct node
    {
        T data;
        ~node()
        {
            cout << "deleting\t" << data << endl;
        }

        LLNODEptr prev;
        LLNODE next;
    };

    void append(T data)
    {
        LLNODE p(new node());
        p.get()->data = data;
        cout << "adding\t" << data << endl;
        if (!head)
        {
            head = p;
            tail = &head;
        }
        else
        {
            auto temp = tail;
            p->prev = temp;
            temp->get()->next = p;
            tail = &temp->get()->next;
        }
          
    }

    void print()
    {
        for (auto *p=&head; (*p); p = &(p->get()->next))
        {
            cout << p->get()->data <<  endl;
        }
    }

   node* find(T data)
    {
        auto p=&head;
        for (; (p && (p->get()->data != data)); p = &(p->get()->next))
            ;
        return (p?p->get():nullptr);
    }

    void remove(T data)
    {
        auto p = find(data);
        if (p && head == *tail)
        {
            head.reset();
            tail = nullptr;
        }
        else if (head.get() == p)
        {
            head = head.get()->next;
        }
        else if (tail->get() == p)
        {
            tail =  p->prev;
            tail->get()->next.reset();
        }
        else
        {
            p->next->prev = p->prev;
            p->prev->get()->next = p->next;
        }
    }

    LLNODE head;
    LLNODEptr tail;

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