#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};
node *head = NULL;

void insertBeg(int a)
{
    node *temp = new node;
    temp->data = a;
    temp->next = head;
    head = temp;
}

void insertEnd(int a)
{
    node *temp = new node;
    node *temp1 = head;
    temp1->data = a;
    temp1->next = temp;
    temp = temp1;
}

void insertEnd()
{
    int a;
    cout << "Enter the element you want insert at the end\n";
    cin >> a;
    node *temp = new node;
    temp->data = a;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        node *temp1 = head;

        while (temp1->next != NULL)
        {
            temp1 = temp1->next;
            temp1->next = temp;
        }
    }
}
void display()
{
    if (head != NULL)
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data;
            temp = temp->next;
        }
    }
    else
    {
        cout << "Linked list is empty";
    }
}
int main()
{
    int count = 0, a = 0;
    cout << "No of elements in linked list:- ";
    cin >> count;

    for (int i = 0; i < count; i++)
    {
        cout << "enter the number to be inserted in linked list";
        cin >> a;
        insertEnd(a);
    }
    // for (int i = 0; i < count; i++)
    // {
    //     cout << "enter the number to be inserted in linked list";
    //     cin >> a;
    //     insertBeg(a);
    // }

    

    display();
    return 0;
}
