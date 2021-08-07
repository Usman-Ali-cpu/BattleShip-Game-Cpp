#include <iostream>
#include <string>
using namespace std;

class Car
{
public:
    string name;
    int price;
    Car *next;
    Car(string name, int num)
    {
        this->name = name;
        this->price = num;
        this->next = NULL;
    }
    Car()
    {
        this->name = "Unkown";
        this->price = 0;
        this->next = NULL;
    }
};

class CarList
{
    Car *head;
    Car *tail;

public:
    CarList()
    {
        head = tail = NULL;
    }
    void insert(string name, int num)
    {
        Car *temp = new Car(name, num);
        if (temp != NULL)
        {
            if (head == NULL && tail == NULL)
            {
                head = tail = temp;
            }
            else
            {
                tail->next = temp;
                tail = tail->next;
            }
        }
    }
    void remove(string name, int num)
    {
        Car *temp = head;
        Car *previous = NULL;
        while (temp != NULL)
        {
            if (temp->name == name)
            {
                break;
            }
            previous = temp;
            temp = temp->next;
        }

        if (temp == head)
        {
            if (head == NULL)
            {
                return;
            }
            if (head->next == NULL)
            {
                head = NULL;
            }
            else
            {
                Car *temp = head;
                head = head->next;
                delete temp;
            }
        }
        else
        {
            previous->next = temp->next;
            delete temp;
        }
    }
    void show()
    {
        Car *temp = head;
        cout << "Car Name\t  Car Price " << endl;
        cout << "*****************************\n";
        while (temp != NULL)
        {
            cout << temp->name << "  \t\t  " << temp->price << endl;
            temp = temp->next;
        }
        cout << "*****************************\n";
    }
    int getCount()
    {
        int count = 0;
        Car *temp = head;
        while (temp != NULL)
        {
            temp = temp->next;
            count++;
        }
        return count;
    }
};

int main()
{

    CarList list;

    while (true)
    {
        int choice;
        cout << "\n*****************************\n";
        cout << "Add Car Record : " << endl;
        cout << "Display All Car Records " << endl;
        cout << "Count Number Of Records " << endl;
        cout << "Exit" << endl;
        cout << "*****************************\n";
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string str;
            cout << "Enter Car name and price : ";
            cin.ignore();
            getline(cin, str);
            string name = str;
            string price;
            string::size_type pos = name.find(' ');
            if (name.npos != pos)
            {
                price = name.substr(pos + 1);
                name = name.substr(0, pos);
            }
            int p = stoi(price);

            list.insert(name, p);
        }
        break;
        case 2:
            list.show();
            /* code */
            break;
        case 3:
            cout << "\nNumber of records are : " << list.getCount();
            /* code */
            break;
        case 4:
            cout << "Program Ends" << endl;
            exit(0);
            /* code */
            break;
        default:
            cout << "Invalid Choice Try Again!" << endl;
            break;
        }
    }

    // string str;
    // cout<< "Enter : ";
    // getline(cin, str);
    // cout<< str;
    // int index = str.find_first_of(' ');
    // string name = str.substr(0, index);
    // string number = str.substr(index+1, str.length());
    // cout<< name<< endl;
    // cout<< number << endl;

    // list.insert("Car1", "24536");
    // list.insert("Car1", "24536");
    // list.insert("Car1", "24536");
    // list.insert("Car1", "24536");
    // list.show();

    return 0;
}