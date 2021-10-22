#include<iostream>

using namespace std;

struct node{
    int data;
    node* next;
};

node* head1 = NULL;
node* head2 = NULL;

void find_duplicate()
{
    node* prev;
    node* cur;
    node* n1 = head1;
    node* n2 = head2;

    while(n1 != NULL)
    {
        n2 = head2;
        
        while(n2 != NULL)
        {
            if(n1->data == n2->data)
            {
                 if(n2 == head2)
                 {
                     prev = n2;
                     n2 = n2->next;
                     head2 = head2->next;
                     free(prev);
                     
                 }
                 else
                 {
                     n2 = n2->next;
                     free(prev);
                 }
                 

            }
            else{
            prev = n2;
            n2 = n2->next;
            }
        }
        n1 = n1->next;
    }
}

int main()
{
   int n1,n2;

   cout<<"Enter number of elements in list1:";
   cin>>n1;
   cout<<"Enter number of elements in list2:";
   cin>>n2;

   node* cur = head1;
   int t;
   node* temp;

   cout<<"Enter list1 elements: ";
   for(int i =0;i<n1;i++)
   {
       cin>>t;
       temp = new node();

       if(temp== NULL)
       {
           cout<<"memory full";
           exit(0);
       }
       temp->data = t;
       temp->next = NULL;

       if(head1 == NULL)
       {
           head1 = temp;
           cur = temp;
       }
       else{
           cur->next = temp;
           cur = temp;
       }
   }

   cur = head2;

    cout<<"Enter list2 elements: ";
   for(int i =0;i<n2;i++)
   {
       cin>>t;
       temp = new node();

       if(temp== NULL)
       {
           cout<<"memory full";
           exit(0);
       }
       temp->data = t;
       temp->next = NULL;

       if(head2 == NULL)
       {
           head2 = temp;
           cur = temp;
       }
       else{
           cur->next = temp;
           cur = temp;
       }
   }

   for(node* n = head1; n != NULL; n = n->next)
      cout<<n->data<<" ";
    cout<<endl;

    for(node* n = head2; n != NULL; n = n->next)
      cout<<n->data<<" ";
    cout<<endl;

    find_duplicate();
    for(node* n = head1; n != NULL; n = n->next)
      cout<<n->data<<" ";
    cout<<endl;

    for(node* n = head2; n != NULL; n = n->next)
      cout<<n->data<<" ";
    cout<<endl;


}