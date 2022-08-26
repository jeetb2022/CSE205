
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
struct Node
{
  int data;
  struct Node *next;
};

void Isrch(Node *head, int searchValue)
{
  Node *temp = head;
  int found = 0;
  int i = 0;

  if (temp != NULL)
  {
    while (temp != NULL)
    {
      i++;
      if (temp->data == searchValue)
      {
        found++;
        break;
      }
      temp = temp->next;
    }
    if (found == 1)
    {
      cout <<  "The element is found at index = " << i << ".\n";
    }
    else
    {
      cout <<  "The element is not found in the list.\n";
    }
  }
  else
  {
    cout << "The list is empty.\n";
  }
}

int main()
{
  struct Node *head = NULL;
  struct Node *second = NULL;
  struct Node *third = NULL;

  head = (struct Node *)malloc(sizeof(struct Node));
  second = (struct Node *)malloc(sizeof(struct Node));
  third = (struct Node *)malloc(sizeof(struct Node));

  head->data = 1;
  head->next = second;

  second->data = 2;

  second->next = third;

  third->data = 3;
  third->next = NULL;

  Isrch(head, 1);

  return 0;
}