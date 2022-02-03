#include <iostream>
#include <string>
using namespace std;

bool isOperator(char c)
{
    if (c == '!' || c == '&' || c == '|' || c == '(' || c == ')')
    {
        return true;
    }
    return false;
}
bool isOperend(char c)
{
    if (c == 'T' || c == 'F')
    {
        return true;
    }
    return false;
}
int preference(char c)
{
    if (c == '!')
    {
        return 3;
    }
    if (c == '&')
    {
        return 2;
    }
    if (c == '|')
    {
        return 1;
    }
    return 0;
}

class Node
{
public:
    char x;
    Node *next;
    Node(char x)
    {
        this->x = x;
        next = NULL;
    }
    Node()
    {
        next = NULL;
    }
};

class Stack
{
    Node *head;
    int top;

public:
    Stack()
    {
        top = -1;
        head = NULL;
    }
    void push(char val)
    {
        if (head == NULL)
        {
            head = new Node(val);
            top = 0;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new Node(val);
            ++top;
        }
    }
    char pop()
    {
        Node *temp = head;
        char x;
        if (temp == NULL)
        {
            return 'N';
        }
        if (head->next == NULL)
        {
            x = temp->x;
            head = NULL;
            top = -1;
            return x;
        }
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        x = temp->next->x;
        temp->next = NULL;
        return x;
        top--;
    }
    char peek()
    {
        Node *temp = head;
        char x;
        if (head == NULL)
        {
            return 'N';
        }
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        x = temp->x;
        return x;
    }
    bool isEmpty()
    {
        return head == NULL;
    }
    void show()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->x << endl;
            temp = temp->next;
        }
    }
    ~Stack()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            Node *t = temp;
            temp = temp->next;
            delete t;
        }
        head = NULL;
    }
};

char doAND(char a, char b)
{
    if (a == 'T' && b == 'T')
    {
        return 'T';
    }
    else
        return 'F';
}
char doOR(char a, char b)
{
    if (a == 'F' && b == 'F')
    {
        return 'F';
    }
    else
        return 'T';
}
char doNOT(char a)
{
    if (a == 'F')
    {
        return 'T';
    }
    else
        return 'F';
}

int main()
{
    string str;
    string postfix;
    Stack st;
    cout << "Enter expression in infix : ";
    getline(cin, str);
    char d;
    int count = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str.at(i) == ' ')
        {
            continue;
        }
        else if (str.at(i) == '!')
        {
            if (str.at(i + 1) == 'T')
            {
                str.at(i + 1) = 'F';
                str.at(i) = ' ';
            }
            else if (str.at(i + 1) == 'F')
            {
                str.at(i + 1) = 'T';
                str.at(i) = ' ';
            }
            else
            {
                st.push(str.at(i));
            }
        }
        else if (str.at(i) == ')')
        {
            while (!st.isEmpty() && st.peek() != '(')
            {
                postfix += st.peek();
                st.pop();
            }
            st.pop();
        }
        else if (isOperator(str.at(i)))
        {

            if (st.isEmpty())
            {
                st.push(str.at(i));
            }
            else if (!st.isEmpty())
            {
                d = st.peek();
                if (preference(str.at(i)) > preference(d) || str.at(i) == '(')
                {
                    st.push(str.at(i));
                }
                else if (preference(str.at(i)) <= preference(d))
                {
                    while (!st.isEmpty() && st.peek() != '(')
                    {
                        postfix += st.pop();
                    }
                    st.push(str.at(i));
                }
            }
        }
        else if (isOperend(str.at(i)))
        {
            postfix += str.at(i);
        }
        count++;
    }
    while (!st.isEmpty())
    {
        postfix += st.pop();
    }

    // Evaluate

    Stack eval;
    int a, b;
    int j = 0;
    for (int i = 0; i < postfix.length(); i++)
    {
        if (isOperend(postfix.at(i)))
        {
            eval.push(postfix.at(i));
        }
        else if (postfix.at(i) == '!')
        {
            char c = eval.pop();
            if (c == 'T')
            {
                eval.push('F');
            }
            else
            {
                eval.push('T');
            }
        }
        else if (isOperator(postfix.at(i)))
        {
            a = eval.pop();
            b = eval.pop();
            switch (postfix.at(i))
            {
            case '&':
                eval.push(doAND(b, a));
                break;
            case '|':
                eval.push(doOR(b, a));
                break;
            default:
                break;
            }
        }
    }
    cout << "Answer: ";
    while (!eval.isEmpty())
        cout << eval.pop() << " ";
    return 0;

    return 0;
}