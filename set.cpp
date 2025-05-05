#include <iostream>
using namespace std;

class Set_op
{
private:
    int Set[20];
    int cnt;

public:
    Set_op() : cnt(0) {}

    void insert();
    int contain(int x);
    void size();
    void remove();
    void Union(Set_op S1, Set_op S2);
    void intersection(Set_op S1, Set_op S2);
    void difference(Set_op S1, Set_op S2);
    bool isSubset(Set_op S1, Set_op S2);
    void display()
    {
        cout << "{ ";
        for (int i = 0; i < cnt; i++)
        {
            cout << Set[i] << " ";
        }
        cout << "}" << endl;
    }
};

void Set_op::insert()
{
    int num;
    cout << "Enter the number of elements to insert: ";
    cin >> cnt;
    cout << "Enter the elements: ";
    for (int i = 0; i < cnt; i++)
    {
        cin >> num;
        Set[i] = num;
    }
}

int Set_op::contain(int x)
{
    for (int i = 0; i < cnt; i++)
    {
        if (Set[i] == x)
            return i;
    }
    return -1;
}

void Set_op::size()
{
    cout << "The size of the set is: " << cnt << endl;
}

void Set_op::remove()
{
    int key;
    cout << "Enter the element to be removed: ";
    cin >> key;
    int index = contain(key);
    if (index == -1)
    {
        cout << "Element not found in the set.\n";
    }
    else
    {
        for (int i = index; i < cnt - 1; i++)
        {
            Set[i] = Set[i + 1];
        }
        cnt--;
        cout << "Element removed successfully.\n";
    }
}

void Set_op::Union(Set_op S1, Set_op S2)
{
    cnt = 0;
    for (int i = 0; i < S1.cnt; i++)
    {
        Set[cnt++] = S1.Set[i];
    }
    for (int i = 0; i < S2.cnt; i++)
    {
        if (S1.contain(S2.Set[i]) == -1)
        {
            Set[cnt++] = S2.Set[i];
        }
    }
}

void Set_op::intersection(Set_op S1, Set_op S2)
{
    cnt = 0;
    for (int i = 0; i < S2.cnt; i++)
    {
        if (S1.contain(S2.Set[i]) != -1)
        {
            Set[cnt++] = S2.Set[i];
        }
    }
}

void Set_op::difference(Set_op S1, Set_op S2)
{
    cnt = 0;
    for (int i = 0; i < S1.cnt; i++)
    {
        if (S2.contain(S1.Set[i]) == -1)
        {
            Set[cnt++] = S1.Set[i];
        }
    }
}

bool Set_op::isSubset(Set_op S1, Set_op S2)
{
    for (int i = 0; i < S1.cnt; i++)
    {
        if (S2.contain(S1.Set[i]) == -1)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    Set_op S1, S2, S3;
    int ch;
    do
    {
        cout << "\n---------MENU	";
        cout << "\n1. Insert ";
        cout << "\n2. Display ";
        cout << "\n3. Contain (Search)";
        cout << "\n4. Size ";
        cout << "\n5. Remove ";
        cout << "\n6. Union ";
        cout << "\n7. Intersection ";
        cout << "\n8. Difference ";
        cout << "\n9. Subset Check ";
        cout << "\n10. Exit ";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            S1.insert();
            break;
        case 2:
            S1.display();
            break;
        case 3:
        {
            int num, res;
            cout << "Enter element to search: ";
            cin >> num;
            res = S1.contain(num);
            if (res != -1)
            {
                cout << "Element found in the set.\n";
                cout << "Index of the element is : " << res << "\n";
            }
            else
            {
                cout << "Element not found in the set.\n";
            }
            break;
        }
        case 4:
            S1.size();
            break;
        case 5:
            S1.remove();
            break;
        case 6:
            cout << "Enter elements for Set 1:\n";
            S1.insert();
            cout << "Enter elements for Set 2:\n";
            S2.insert();
            S3.Union(S1, S2);
            cout << "Union of the sets: ";
            S3.display();
            break;
        case 7:
            cout << "Enter elements for Set 1:\n";
            S1.insert();
            cout << "Enter elements for Set 2:\n";
            S2.insert();
            S3.intersection(S1, S2);
            cout << "Intersection of the sets: ";
            S3.display();
            break;
        case 8:
            cout << "Enter elements for Set 1:\n";
            S1.insert();
            cout << "Enter elements for Set 2:\n";
            S2.insert();
            S3.difference(S1, S2);
            cout << "Difference of the sets (S1 - S2): ";
            S3.display();
            break;
        case 9:
            cout << "Enter elements for Set 1:\n";
            S1.insert();
            cout << "Enter elements for Set 2:\n";
            S2.insert();
            if (S1.isSubset(S1, S2))
            {
                cout << "Set 1 is a subset of Set 2.\n";
            }
            else
            {
                cout << "Set 1 is not a subset of Set 2.\n";
            }
            break;
        case 10:
            cout << "Thank you!\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (ch != 10);

    return 0;
}
