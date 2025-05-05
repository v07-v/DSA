#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

class node
{
public:
     char data;
     node *left;
     node *right;
};

class tree
{
public:
     node *root;
     void expression(char[]);
     void display(node *);
     void inorder(node *);
     void preorder(node *);
     void postorder(node *);
     void remove(node *);
     void non_rec_postorder(node *);
};

class stack1
{
     node *data[30];
     int top;

public:
     stack1()
     {
          top = -1;
     }
     int empty()
     {
          if (top == -1)
               return 1;
          return 0;
     }
     void push(node *p)
     {
          data[++top] = p;
     }
     node *pop()
     {
          return (data[top--]);
     }
};

void tree::expression(char prefix[])
{
     stack1 s;
     int len;
     node *t1, *t2;
     len = strlen(prefix);
     for (int i = len - 1; i >= 0; i--)
     {
          root = new node;
          root->left = NULL;
          root->right = NULL;
          if (isalpha(prefix[i]))
          {
               root->data = prefix[i];
               s.push(root);
          }
          else if (prefix[i] == '+' || prefix[i] == '-' || prefix[i] == '*' || prefix[i] == '/')
          {
               root->data = prefix[i];
               t2 = s.pop();
               t1 = s.pop();
               root->left = t2;
               root->right = t1;
               s.push(root);
          }
     }
     root = s.pop();
}

void tree::inorder(node *temp)
{
     if (temp != NULL)
     {
          inorder(temp->left);
          cout << temp->data << " ";
          inorder(temp->right);
     }
}

void tree::postorder(node *temp)
{
     if (temp != NULL)
     {
          postorder(temp->left);
          postorder(temp->right);
          cout << temp->data << " ";
     }
}

void tree::non_rec_postorder(node *top)
{
     stack1 s1, s2;
     node *t = top;
     cout << "\n";
     s1.push(t);
     while (!s1.empty())
     {
          t = s1.pop();
          s2.push(t);
          if (t->left != NULL)
          {
               s1.push(t->left);
          }
          if (t->right != NULL)
          {
               s1.push(t->right);
          }
     }
     while (!s2.empty())
     {
          top = s2.pop();
          cout << top->data;
     }
}

void tree::preorder(node *temp)
{
     if (temp != NULL)
     {
          cout << temp->data << " ";
          preorder(temp->left);
          preorder(temp->right);
     }
}

void tree::remove(node *temp)
{
     if (temp == NULL)
     {
          return;
     }
     remove(temp->left);
     remove(temp->right);
     cout << "\nDeleting Node : " << temp->data << endl;
     delete temp;
}

void tree::display(node *temp)
{
     if (temp != NULL)
     {
          cout << temp->data;
          display(temp->left);
          display(temp->right);
     }
}

int main()
{
     tree t1;
     int ch;
     do
     {
          cout << "\nMENU";
          cout << "\n1. Expression ";
          cout << "\n2. Display";
          cout << "\n3. Display Inorder";
          cout << "\n4. Display Postorder";
          cout << "\n5. Display Preorder";
          cout << "\n6. Display Non-Recursive Postorder";
          cout << "\n7. Delete Node";
          cout << "\n8. Exit";
          cout << "\nEnter your choice: ";
          cin >> ch;

          cout << "You entered: " << ch << endl;

          switch (ch)
          {
          case 1:
               char expr[30];
               cout << "\nEnter Expression: ";
               cin >> expr;
               t1.expression(expr);
               break;
          case 2:
               cout << "\nExpression : ";
               t1.display(t1.root);
               break;
          case 3:
               cout << "Inorder : ";
               t1.inorder(t1.root);
               break;
          case 4:
               cout << "Postorder : ";
               t1.postorder(t1.root);
               break;
          case 5:
               cout << "Preorder : ";
               t1.preorder(t1.root);
               break;
          case 6:
               cout << "Non-Recursive Postorder : ";
               t1.non_rec_postorder(t1.root);
               break;
          case 7:
               t1.remove(t1.root);
               break;
          case 8:
               cout << "\nThe End!!!";
               cout << "\nThank You for using the Program !!!!";
               break;
          default:
               cout << "Invalid choice!!" << endl;
          }

          cout << "End of choice: " << ch << endl;

     } while (ch != 8);
     return 0;
}
