#include <iostream>
#include <cstdlib>

using namespace std;

struct Node{
    int data;
    Node *next;
};


void display_list_sum(struct Node *head);
void read_list(struct Node *&head);
void delete_evens(struct Node *&head);
//////////////////

int main()
{
     struct Node *head=NULL;

     read_list(head);
     display_list_sum(head);
     delete_evens(head);
     display_list_sum(head);

}
//////////////////////////////////////
void display_list_sum(struct Node *head)
{
   struct Node *temp;
   temp=head;

   cout<<"list items: ";
   while (temp != NULL)
   {
      cout<< temp->data <<" ";
      temp = temp->next ;
   }
}

///////////////////
void read_list(struct Node *&head)
{
     struct Node *temp;
     int num;

     cout<<"enter a number to be added to the list: ";
     cin >> num ;
     cout<<endl;
     while (num!=0)
     {
        temp = new (nothrow) struct Node ;
        if (temp == NULL)
           exit(EXIT_FAILURE);
        temp -> data = num ;
        temp -> next = head ;
        head = temp ;
        cout<<"enter a number to be added to the list: ";
        cin >> num ;
        cout<<endl;
     }
}


void delete_evens(struct Node *&head)
{
   struct Node *temp,*step,*prev ;
   if (head==NULL) return;

   while(head!=NULL && head->data%2==0)
   {
            temp = head ;
            head = head -> next ;
            delete temp ;
   }
   step=head;

   while (step!=NULL)
   {
      if (step-> data %2==0)
      {
         temp = step ;
         step = step -> next ;
         prev->next=step;
         delete temp ;
      }
      else
      {
         prev=step;
         step = step -> next ;
      }
   }
   step=NULL;

   cout<<"after deletion: ";
}
