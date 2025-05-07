#include <iostream>
#include <string.h>
using namespace std;

class Node {
public:
    char data;
    Node *left, *right;
};

class Stack {
    Node *data[30];
    int top;

public:
    Stack() { top = -1; }

    bool empty() { return top == -1; }

    void push(Node *p) { data[++top] = p; }

    Node *pop() { return data[top--]; }
};

class Tree {
    Node *root;

public:
    Tree() { root = nullptr; }

    void buildFromPrefix(char prefix[]) {
        Stack s;
        int len = strlen(prefix);
        for (int i = len - 1; i >= 0; i--) {
            Node *newNode = new Node;
            newNode->left = newNode->right = nullptr;
            newNode->data = prefix[i];

            if (isalpha(prefix[i])) {
                s.push(newNode);
            } else {
                // FIX: Correct child assignment
                Node* right = s.pop();
                Node* left = s.pop();
                newNode->left = left;
                newNode->right = right;
                s.push(newNode);
            }
        }
        root = s.pop();
        cout << "\nExpression tree built successfully.\n";
    }

    void nonRecursivePostOrder() {
        if (!root) {
            cout << "\nTree is empty.\n";
            return;
        }

        Stack s1, s2;
        s1.push(root);

        while (!s1.empty()) {
            Node *temp = s1.pop();
            s2.push(temp);

            if (temp->left) s1.push(temp->left);
            if (temp->right) s1.push(temp->right);
        }

        cout << "\nPost-order traversal (non-recursive): ";
        while (!s2.empty()) {
            cout << s2.pop()->data << " ";
        }
        cout << endl;
    }

    void deleteTree(Node *temp) {
        if (!temp) return;
        deleteTree(temp->left);
        deleteTree(temp->right);
        cout << "Deleting Node: " << temp->data << endl;
        delete temp;
    }

    void deleteEntireTree() {
        if (!root) {
            cout << "\nTree is already empty.\n";
            return;
        }
        deleteTree(root);
        root = nullptr;
        cout << "\nExpression tree deleted successfully.\n";
    }

    ~Tree() {
        deleteEntireTree();
    }
};

int main() {
    Tree t;
    int choice;
    char expr[30];

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Build Expression Tree from Prefix\n";
        cout << "2. Post-order Traversal (Non-Recursive)\n";
        cout << "3. Delete Expression Tree\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\nEnter prefix expression: ";
            cin >> expr;
            t.buildFromPrefix(expr);
            break;
        case 2:
            t.nonRecursivePostOrder();
            break;
        case 3:
            t.deleteEntireTree();
            break;
        case 4:
            cout << "\nExiting program.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
