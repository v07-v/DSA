
// 4.Expression Tree
#include <iostream>
using namespace std;
class node
{
public:
    char data;
    node *left;
    node *right;
};
class stack
{
public:
    node *a[20];
    node *temp;
    int top;
    stack()
    {
        top = -1;
    }
    bool isEmpty();
    bool isFull();
    void push(node *temp);
    node *pop();
};
bool stack::isEmpty()
{
    if (top == -1)
    {
        return (1);
    }
    else
    {
        return (0);
    }
}
bool stack::isFull()
{
    if (top == 19)
    {
        return (1);
    }
    else
    {
        return (0);
    }
}
void stack::push(node *temp)
{
    if (!isFull())
    {
        a[++top] = temp;
    }
    else
    {
        cout << "Stack is Full";
    }
}
node *stack::pop()
{
    if (!isEmpty())
    {
        return a[top--];
    }
    else
    {
        cout << "Stack is Empty";
    }
}

class expressionTree
{
public:
    node *root;
    expressionTree()
    {
        root = NULL;
    }
    void createTree();
    void prefix(node *root);
    void infix(node *root);
    void postfix(node *root);
};
void expressionTree::createTree()
{
    int i;
    char ch;
    stack s;
    string exp_str;
    node *new_node, *temp;

    cout << "Enter Prefix Expression :";
    cin >> exp_str;

    for (i = (exp_str.length() - 1); i >= 0; i--)
    {
        ch = exp_str[i];
        new_node = new node();
        new_node->data = ch;
        new_node->left = NULL;
        new_node->right = NULL;

        if (ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z')
        {
            s.push(new_node);
        }
        else
        {
            temp = s.pop();
            new_node->left = temp;
            temp = s.pop();
            new_node->right = temp;
            s.push(new_node);
        }
    }
    root = s.pop();
}

void expressionTree ::prefix(node *root)
{
    if (root != NULL)
    {
        cout << root->data;
        prefix(root->left);
        prefix(root->right);
    }
}
void expressionTree ::infix(node *root)
{
    if (root != NULL)
    {
        infix(root->left);
        cout << root->data;
        infix(root->right);
    }
}
void expressionTree ::postfix(node *root)
{
    if (root != NULL)
    {
        postfix(root->left);
        postfix(root->right);
        cout << root->data;
    }
}
int main()
{
    expressionTree e;
    e.createTree();

    cout << "\nInfix Expression : ";
    e.infix(e.root);

    cout << "\nPrefix Expression : ";
    e.prefix(e.root);

    cout << "\nPostfix Expression : ";
    e.postfix(e.root);

    return 0;
}