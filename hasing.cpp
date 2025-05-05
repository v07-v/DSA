#include <iostream>
using namespace std;

class Hashtable
{
public:
    int key;
    int index;
};

class Hashing
{
private:
    Hashtable H[10];
    int m;

public:
    Hashing(int size)
    {
        m = size;
        for (int i = 0; i < 10; i++)
        {
            H[i].key = -1;
            H[i].index = i;
        }
    }

    void display();
    void insert();
    int Linear_Probing(int position);
    long int Quadratic_Probing(int position);
};

void Hashing::display()
{
    cout << "NUMBER \t\tINDEX\n";
    for (int i = 0; i < 10; i++)
    {
        cout << H[i].key << "\t\t" << H[i].index << "\n";
    }
}

void Hashing::insert()
{
    long int mb_no;
    int position, probe_choice;

    cout << "Enter mobile number: ";
    cin >> mb_no;

    cout << "1. Linear Probing\n2. Quadratic Probing\n";
    cout << "Enter your choice: ";
    cin >> probe_choice;
    position = mb_no % 10;
    if (H[position].key == -1)
    {
        H[position].key = mb_no;
    }
    else if (probe_choice == 1)
    {
        int newPos = Linear_Probing(position);
        if (newPos != -1)
        {
            H[newPos].key = mb_no;
        }
        else
        {
            cout << "Table is full, cannot insert!\n";
        }
    }
    else if (probe_choice == 2)
    {
        int newPos = Quadratic_Probing(position);
        if (newPos != -1)
        {
            H[newPos].key = mb_no;
        }
        else
        {
            cout << "Table is full, cannot insert!\n";
        }
    }
    else
    {
        cout << "Invalid choice!\n";
    }
}

int Hashing::Linear_Probing(int position)
{
    for (int i = 0; i < 10; i++)
    {
        int newPos = (position + i) % 10;
        if (H[newPos].key == -1)
        {
            return newPos;
        }
    }
    return -1;
}

long int Hashing::Quadratic_Probing(int position)
{
    for (int i = 1; i < 10; i++)
    {
        int newPos = (position + i * i) % 10;
        if (H[newPos].key == -1)
        {
            return newPos;
        }
    }
    return -1;
}

int main()
{
    int size;
    cout << "Enter the size of hash table (max 10): ";
    cin >> size;
    if (size > 10)
    {
        cout << "Size exceeds maximum limit of 10. Setting to 10.\n";
        size = 10;
    }

    Hashing T1(size);
    int choice;

    do
    {
        cout << "-----------MENU\t";
        cout << "\n1. Insert ";
        cout << "\n2. Display ";
        cout << "\n3. Exit ";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            T1.insert();
            break;

        case 2:
            T1.display();
            break;

        case 3:
            cout << "THANK YOU!!\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 3);

    return 0;
}
