#include <iostream>
#include "Queue.cpp"
using namespace std;

struct Card
{
    string patientName;
    string city;
    string IDnum;
    Card()
    {
        patientName = "";
        city = "";
        IDnum = "";
    }
    void setName(string name)
    {
        patientName = name;
    }
    void setCity(string c)
    {
        city = c;
    }
    void setIDnum(string Id)
    {
        IDnum = Id;
    }
    string getName(string name)
    {
        return patientName;
    }
    string getCity(string c)
    {
        return city;
    }
    string getIDnum(string Id)
    {
        return IDnum;
    }
};

int main()
{
    Queue<Card> q;
    Queue<Card> q2;
    while (true)
    {
        int choice;
        cout << "1. Add New Card " << endl;
        cout << "2. Print First CARD " << endl;
        cout
            << "3. Comapare Queues" << endl;
        cout << "4.Print All Card " << endl;
        cout << "5. Remove Card from begining " << endl;
        cout
            << "Enter Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "Enter Pateint Name : ";
            string name;
            cin >> name;
            cout << "Enter Pateint City : ";
            string city;
            cin >> city;
            cout << "Enter Pateint ID Number : ";
            string id;
            cin >> id;
            Card c;
            c.setCity(city);
            c.setIDnum(id);
            c.setName(name);
            q.push(c);
        }

        break;
        case 2:
            if (q.isEmpty())
            {
                cout << "Queue is Empty !" << endl;
            }
            else
            {
                cout << q.front->x << endl;
            }
            break;
        case 3:
            if (false)
            {
                cout << "Queues Are Same " << endl;
            }
            else
            {
                cout << "Queues are not same " << endl;
            }
            break;
        case 4:
        {
            cout << "Enter 1 for Queue1 and 2 for Queue2: ";
            int n;
            cin >> n;
            if (n == 1)
            {
                if (q.isEmpty())
                {
                    cout << "Queue is Empty !" << endl;
                }
                else
                {
                    q.print();
                }
            }
            else
            {
                if (q2.isEmpty())
                {
                    cout << "Queue is Empty !" << endl;
                }
                else
                {
                    q2.print();
                }
            }
        }

        break;
        case 5:
        {
            cout << "removing From begining" << endl;
            if (!q.isEmpty())
            {
                q.pop();
            }
            if (!q2.isEmpty())
            {
                q2.pop();
            }
        }

        default:
            break;
        }
    }

    return 0;
}