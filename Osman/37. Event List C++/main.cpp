#include <iostream>
using namespace std;

class Event
{
private:
    int time;
    string eventName;

public:
    Event()
    {
        time = 0;
        eventName = "Defualt";
    }
    Event(int t, string name)
    {
        time = t;
        eventName = name;
    }
    int getTime()
    {
        return time;
    }
    string getEventName()
    {
        return eventName;
    }
    void print()
    {
        cout << "Event : " << eventName << endl;
        cout << "Time : " << time << endl;
    }
    friend bool operator==(Event &, Event &);
};
bool operator==(Event &e1, Event &e2)
{
    return (e1.getTime() == e2.getTime() && e1.getEventName() == e2.getEventName());
}
class Node
{
public:
    Event x;
    Node *next;
    Node *previous;
    Node(Event x)
    {
        this->x = x;
        next = NULL;
        previous = NULL;
    }
    Node()
    {
        next = NULL;
        previous = NULL;
    }
};

class EventList
{
    Node *head;
    Node *tail;

public:
    EventList()
    {
        head = NULL;
        tail = NULL;
    }
    void append(Event val)
    {
        if (head == NULL)
        {
            head = new Node(val);
            tail = head;
        }
        else
        {
            Node *temp = new Node(val);
            tail->next = temp;
            temp->previous = tail;
            tail = temp;
        }
    }
    void insert_After(Node *prev_node, Event e)
    {
        //check if prev node is null
        if (prev_node == NULL)
        {
            cout << "Location Does not exists" << endl;
            return;
        }
        //allocate memory for new node
        Node *newNode = new Node;

        //assign data to new node
        newNode->x = e;

        //set next of newnode to next of prev node
        newNode->next = prev_node->next;

        //set next of prev node to newnode
        prev_node->next = newNode;

        //now set prev of newnode to prev node
        newNode->previous = prev_node;

        //set prev of new node's next to newnode
        if (newNode->next != NULL)
            newNode->next->previous = newNode;
    }
    void insert_before(Node *next_node, Event e)
    {
        //check if prev node is null
        if (next_node == NULL)
        {
            cout << "Location Does not exists" << endl;
            return;
        }
        //allocate memory for new node
        Node *newNode = new Node;

        //assign data to new node
        newNode->x = e;

        //set next of newnode to prev of next node
        newNode->previous = next_node->previous;

        //set prev of next node to newnode
        next_node->previous = newNode;

        //now set next of newnode to next node
        newNode->next = next_node;

        //set next of new node's prev to newnode
        if (newNode->previous != NULL)
            newNode->previous->next = newNode;
    }

    void preappend(Event val)
    {
        if (head == NULL)
        {
            head = new Node(val);
            tail = head;
        }
        else
        {
            Node *temp = new Node(val);
            temp->next = head;
            head->previous = temp;
            head = temp;
        }
    }
    void insertBefore(string loc, Event val)
    {
        Node *t = head;
        while (t != NULL)
        {
            cout << loc << " == " << t->x.getEventName() << endl;
            if (t->x.getEventName() == loc)
            {
                cout << "macth" << endl;
                break;
            }
            t = t->next;
        }
        if (t == head)
        {
            preappend(val);
            return;
        }
        insert_before(t, val);
    }
    void insertAfter(string loc, Event val)
    {
        Node *t = head;

        while (t != NULL)
        {
            if (t->x.getEventName() == loc)
            {
                break;
                break;
            }
            t = t->next;
        }
        insert_After(t, val);
    }
    void remove(Event e)
    {
        Node *temp = head;
        while (temp != NULL)
        {

            if (temp->x == e)
            {
                if (temp == head)
                {
                    Node *t = head;
                    head = head->next;
                    head->previous = NULL;
                    delete t;
                    return;
                }
                else if (temp == tail)
                {
                    Node *t = tail;
                    tail->previous->next = NULL;
                    tail = tail->previous;
                    delete t;
                    return;
                }
                Node *t = temp;
                temp->previous->next = temp->next;
                temp->next->previous = temp->previous;
                delete t;
                return;
            }
            temp = temp->next;
        }
        cout << "Specific Event Does not Find!" << endl;
    }
    void removeStart()
    {
        if (head == NULL)
        {
            return;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            head->previous = NULL;
            Event x = temp->x;
            delete temp;
        }
    }
    void display()
    {
        Node *temp = head;
        cout << "********** DISPLAY ********** \n";
        while (temp != NULL)
        {
            temp->x.print();
            temp = temp->next;
            cout << endl;
        }
        cout << "********** ******** ********** \n";
    }
    void displayUntil(int time)
    {

        Node *temp = head;
        cout << "********** DISPLAY UNTILL TIME ELASPED " << time << " ********** \n";
        while (temp != NULL)
        {
            if (temp->x.getTime() == time)
            {
                return;
            }
            temp->x.print();
            temp = temp->next;
            cout << endl;
        }
        cout << "********** ******** ********** \n";
    }
    void find(Event e)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->x == e)
            {
                cout << "******* EVENT FIND *********\n";
                temp->x.print();
                cout << "******* ********* *********\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Specific Event Does not Find ! " << endl;
    }
    int getLength()
    {
        int length = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            length++;
            temp = temp->next;
        }
        return length;
    }
    void clear()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            Node *t = temp;
            temp = temp->next;
            delete t;
        }
        head = tail = NULL;
    }
    ~EventList()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            Node *t = temp;
            temp = temp->next;
            delete t;
        }
        head = tail = NULL;
    }
};

int main()
{
    EventList eventlist;
    Event e1(1, "name1");
    Event e2(2, "name2");
    Event e3(3, "name3");

    eventlist.append(e1);
    eventlist.append(e2);
    eventlist.append(e3);

    while (true)
    {
        int choice;
        cout << "Enter 1. To Exit" << endl;
        cout << "Enter 2. To Append Event" << endl;
        cout << "Enter 3. To Display Along With Time Elapsed" << endl;
        cout << "Enter 4. To Display Untill Time Elasped" << endl;
        cout << "Enter 5. To Find Event " << endl;
        cout << "Enter 6. To Insert Event After Location" << endl;
        cout << "Enter 7. To Insert Event Before Location" << endl;
        cout << "Enter 8. To Clear Event List" << endl;
        cout << "Enter 9. To Get Length" << endl;
        cout << "Enter 10. To Remove Event" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            exit(0);
            break;
        case 2:
        {
            string name;
            int time;
            cout << "Enter Event Name : ";
            cin >> name;
            cout << "Enter Time Elapsed:  ";
            cin >> time;
            Event e(time, name);
            eventlist.append(e);
        }

        break;
        case 3:
        {

            cout << endl;
            eventlist.display();
            cout << endl;
        }
        break;
        case 4:
        {
            int time;
            cout << "Enter time elapsed to display events until that time : ";
            cin >> time;
            cout << endl;
            eventlist.displayUntil(time);
            cout << endl;
        }
        break;
        case 5:
        {
            string name;
            int time;
            cout << "Enter Event Name : ";
            cin >> name;
            cout << "Enter Time Elapsed:  ";
            cin >> time;
            Event e(time, name);
            cout << endl;
            eventlist.find(e);
            cout << endl;
        }
        break;
        case 6:
        {
            string loc;
            cout << "Enter Location Event Name To insert After : ";
            cin >> loc;
            string name;
            int time;
            cout << "Enter Event Name : ";
            cin >> name;
            cout << "Enter Time Elapsed:  ";
            cin >> time;
            Event e(time, name);
            cout << endl;
            eventlist.insertAfter(loc, e);
            cout << "\n************* INSERTING ******************" << endl;
            cout << "Inserted Successfully " << endl;
            cout << "\n************* ********** ******************" << endl;
        }
        break;
        case 7:
        {
            string loc;
            cout << "Enter Location Event Name To insert before : ";
            cin >> loc;
            string name;
            int time;
            cout << "Enter Event Name : ";
            cin >> name;
            cout << "Enter Time Elapsed:  ";
            cin >> time;
            Event e(time, name);
            cout << endl;
            eventlist.insertBefore(loc, e);
            cout << "\n************* INSERTING ******************" << endl;
            cout << "Inserted Successfully " << endl;
            cout << "\n************* ********** ******************" << endl;
        }
        break;
        case 8:
        {
            cout << "\n************* CLEARED ******************" << endl;
            eventlist.clear();
            cout << "\n************* ******** ******************" << endl;
        }
        break;
        case 9:
        {
            cout << "\n************* LENGTH ******************" << endl;
            cout << "Length of Event List is : " << eventlist.getLength() << endl;
            cout << "\n************* ******* ******************" << endl;
        }
        break;
        case 10:
        {
            string name;
            int time;
            cout << "Enter Event Name To Remove: ";
            cin >> name;
            cout << "Enter Time Elapsed To Remove:  ";
            cin >> time;
            Event e(time, name);
            cout << "\n************* REMOVING ******************" << endl;
            eventlist.remove(e);
            cout << "REMOVED Successfully " << endl;
            cout << "\n************* ********** ******************" << endl;
        }
        break;

        default:
            cout << "Invalid Input !" << endl;
            break;
        }
    }

    return 0;
}