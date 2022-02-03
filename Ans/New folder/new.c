#include <stdio.h>
#include <string.h>

struct Account
{
    char name[30];
    int id;
    float balance;
};

void getAccount(struct Account *acc)
{
    char name[30];
    int id;
    float balance;
    printf("Enter account name : ");
    scanf("%s", acc->name);
    getchar();
    printf("Enter account id : ");
    scanf("%d", &id);
    printf("Enter account balance : ");
    scanf("%f", &balance);
    acc->balance = balance;
    acc->id = id;
}

float minBalance(struct Account acc[], int len)
{
    float b = acc[0].balance;
    for (int i = 0; i < len; i++)
    {
        if (acc[i].balance < b)
        {
            b = acc[i].balance;
        }
    }
    return b;
}

int main()
{
    struct Account acc1;
    getAccount(&acc1);
    printf("%s", acc1.name);
    struct Account accLsit[10];
    for (int i = 0; i < 10; i++)
    {
        getAccount(&accLsit[i]);
    }
    float lowBal = minBalance(accLsit, 10);
    printf("Min Balance is :  %.2f ", lowBal);

    return 0;
}