#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

struct stud
{
    int roll;
    char name[10];
    char div;
    char add[10];
} rec;

class student
{
public:
    void create();
    void display();
    int search();
    void Delete();
};

void student::create()
{
    char ans;
    ofstream fout;
    fout.open("stud.dat", ios::app | ios::binary);
    if (!fout)
    {
        cout << "Error opening file!" << endl;
        return;
    }
    do
    {
        cout << "Enter Roll No of Student: ";
        cin >> rec.roll;
        cout << "Enter a Name of Student: ";
        cin.ignore();
        cin.getline(rec.name, sizeof(rec.name));
        cout << "Enter a Division of Student: ";
        cin >> rec.div;
        cout << "Enter an Address of Student: ";
        cin.ignore();
        cin.getline(rec.add, sizeof(rec.add));
        fout.write((char *)&rec, sizeof(stud));
        cout << "Do You Want to Add More Records (y/n): ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
    fout.close();
}

void student::display()
{
    ifstream fin;
    fin.open("stud.dat", ios::in | ios::binary);
    if (!fin)
    {
        cout << "Error opening file!" << endl;
        return;
    }
    fin.seekg(0, ios::beg);
    cout << "\n\tThe Content of File are:\n";
    cout << "\n\tRoll\tName\tDiv\tAddress";
    while (fin.read((char *)&rec, sizeof(stud)))
    {
        if (rec.roll != -1)
            cout << "\n\t" << rec.roll << "\t" << rec.name << "\t" << rec.div << "\t" << rec.add;
    }
    fin.close();
}

int student::search()
{
    int r, i = 0;
    ifstream fin;
    fin.open("stud.dat", ios::in | ios::binary);
    if (!fin)
    {
        cout << "Error opening file!" << endl;
        return 0;
    }
    fin.seekg(0, ios::beg);
    cout << "Enter a Roll No: ";
    cin >> r;
    while (fin.read((char *)&rec, sizeof(stud)))
    {
        if (rec.roll == r)
        {
            cout << "\n\tRecord Found...\n";
            cout << "\n\tRoll\tName\tDiv\tAddress";
            cout << "\n\t" << rec.roll << "\t" << rec.name << "\t" << rec.div << "\t" << rec.add;
            return i;
        }
        i++;
    }
    fin.close();
    return 0;
}

void student::Delete()
{
    int pos;
    pos = search();
    fstream f;
    f.open("stud.dat", ios::in | ios::out | ios::binary);
    if (!f)
    {
        cout << "Error opening file!" << endl;
        return;
    }
    f.seekg(0, ios::beg);
    if (pos == 0)
    {
        cout << "\n\tRecord Not Found";
        return;
    }
    int offset = pos * sizeof(stud);
    f.seekp(offset);
    rec.roll = -1;
    strcpy(rec.name, "NULL");
    rec.div = 'N';
    strcpy(rec.add, "NULL");
    f.write((char *)&rec, sizeof(stud));
    f.seekg(0);
    f.close();
    cout << "\n\tRecord Deleted";
}

int main()
{
    student obj;
    int ch, key;
    char ans;
    do
    {
        cout << "\n\t***** Student Information *****";
        cout << "\n\t1. Create\n\t2. Display\n\t3. Delete\n\t4.  Search\n\t5. Exit";
        cout << "\n\t..... Enter Your Choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            obj.create();
            break;
        case 2:
            obj.display();
            break;
        case 3:
            obj.Delete();
            break;
        case 4:
            key = obj.search();
            break;
        case 5:
            break;
        }
        cout << "\n\t..... Do You Want to Continue in Main Menu: ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
    return 0;
}
