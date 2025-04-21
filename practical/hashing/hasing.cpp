#include <iostream>
using namespace std;

class HashTable
{
public:
    int index;
    long int mobile;
};

class Hashing
{
    HashTable h[10];

public:
    Hashing()
    {
        for (int i = 0; i < 10; i++)
        {
            h[i].index = i;
            h[i].mobile = -1;
        }
    }

    void display();
    void insert(int);
    void search();
    int LinearProbing(int);
    int QuadraticProbing(long int);
};

int Hashing::QuadraticProbing(long int key)
{
    int a;

    for (int j = 0; j < 10; j++)
    {
        a = (key + (j * j)) % 10;
        if (h[a].mobile == -1)
        {
            return a;
        }
    }
    return -1;
}

int Hashing::LinearProbing(int collision_position)
{
    for (int i = collision_position; i < 10; i++)
    {
        if (h[i].mobile == -1)
            return i;

        if (i == 9)
            i = -1;
    }
    return -1;
}

void Hashing::display()
{
    for (int i = 0; i < 10; i++)
    {
        cout << h[i].index;
        cout << "  " << h[i].mobile;
        cout << endl;
    }
}

void Hashing::insert(int probchoice)
{
    long int key;
    int position;
    cout << "\nEnter mobile number to insert in to hash table : ";
    cin >> key;
    position = key % 10;

    cout << "\nPosition = " << position;

    if (h[position].mobile == -1)
    {
        h[position].mobile = key;
    }
    else if (probchoice == 1)
    {
        int temp_position;
        temp_position = LinearProbing(position);
        if (temp_position != -1)
            h[temp_position].mobile = key;
        else
            cout << "\nHash table is full. Cannot insert.\n";
    }
    else if (probchoice == 2)
    {
        int temp_position;
        temp_position = QuadraticProbing(key);
        if (temp_position != -1)
            h[temp_position].mobile = key;
        else
            cout << "\nHash table is full. Cannot insert.\n";
    }
}

void Hashing::search()
{
    long int key;
    int position, i;
    cout << "\nEnter mobile number to search in the hash table : ";
    cin >> key;
    position = key % 10;

    if (h[position].mobile == key)
    {
        cout << "\nGiven mobile number is found in the hash table ";
    }
    else
    {
        for (i = 0; i < 10; i++)
        {
            if (h[i].mobile == key)
            {
                cout << "\nGiven mobile number is found in the hash table  ";
                break;
            }
        }
        if (i == 10)
        {
            cout << "\nGiven mobile number is not found in the hash table ";
        }
    }
}

int main()
{
    Hashing H;
    int ch;

    do
    {
        cout << "\n Menu";
        cout << "\n 1.insert";
        cout << "\n 2.display";
        cout << "\n 3.search";
        cout << "\n 5. exit";
        cout << "\n Enter your choice : ";
        cin >> ch;

        switch (ch)
        {
        case 1:
        {
            int probchoice;
            cout << "\nEnter \n1 for LinearProbing and \n2 for Quadratic probing: ";
            cin >> probchoice;
            H.insert(probchoice);
            break;
        }
        case 2:
            H.display();
            break;

        case 3:
            H.search();
            break;

        case 5:
            break;

        default:
            cout << "\nWrong choice :";
            break;
        }

    } while (ch != 5);

    H.display();
}
