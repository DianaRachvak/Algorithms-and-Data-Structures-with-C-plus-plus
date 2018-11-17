#include <iostream>
#include <cstdlib>

using namespace std;

struct node{
    int data;
    node* next, *prev;
};

void print(node *head)
{
    node *temp;
    temp = head;
    while (temp!=0)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main()
{
    node *head, *tail, *n;

    n = new node;
    n->data = 1;
    n->prev = NULL;
    head = n;
    tail = n;

    n = new node;
    n->data = 2;
    n->prev = tail;
    tail->next = n;
    tail = n;

    n = new node;
    n->data = 3;
    n->prev = tail;
    tail->next = n;
    tail = n;

    n = new node;
    n->data = 4;
    n->prev = tail;
    tail->next = n;
    tail = n;
    tail-> next = NULL;

    print(head);

}
