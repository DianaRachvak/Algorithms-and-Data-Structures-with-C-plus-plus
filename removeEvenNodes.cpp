#include <iostream>
#include <cstdlib>

using namespace std;

struct Node
{
   int data;
   struct Node *next;
};

void display_list(struct Node *head);
void read_list(struct Node *&head);
void delete_evens(struct Node *&head);

int main()
{
     struct Node*head=NULL;
     read_list(head);

     cout<<"List before deleting even nodes:"<<endl;
     display_list(head);

     delete_evens(head);

     cout<<"List after deleting even nodes:"<<endl;
     display_list(head);

}

void display_list(struct Node *head)
{
   struct Node *temp;
   temp = head;

   while (temp != NULL)
   {
      cout<< temp-> data<<" " ;
      temp = temp-> next ;
   }
   cout<<endl<<endl;
}

void read_list(struct Node *&head)
{
     struct Node *temp;
     int num;

     cout<<"Enter a number to the list: ";
     cin >> num;
     cout<<endl;
     while (num!=0)
     {
        temp = new (nothrow) struct Node ;
        if (temp == NULL) exit(EXIT_FAILURE);
        temp -> data = num ;
        temp -> next = head ;
        head = temp ;
        cout<<"Enter a number to the list: ";
        cin >> num;
        cout<<endl;
     }
}

void delete_evens(struct Node *&head)
{
   struct Node *temp,*another,*prev ;
   if (head == NULL) return;

   while(head!=NULL && head->data%2==0)
   {
            temp = head ;
            head = head -> next ;
            delete temp ;
   }
   another = head;

   while (another!=NULL)
   {
      if (another-> data %2==0)
      {
         temp = another ;
         another = another -> next ;
         prev->next = another;
         delete temp ;
      }
      else
      {
         prev = another;
         another = another -> next ;
      }
   }
   another = NULL;
}
