#include <iostream>
using namespace std;

void sale_coffee(int &small, int &medium, int &large)
{
    int nsmal, nmedium, nlarge;
    int num, choice;
    while (1)
    {
        cout << "1.Small ( 8oz) - $1.79\n2.Medium(12oz) - $2 .59 \n3.Large(16oz) - $3 .99 \n0.DONE\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "Enter number of cups : ";
            cin >> num;
            nsmal += num;
            small += num;
            cout << "small " << small << endl;
        }
        break;
        case 2:
        {
            cout << "Enter number of cups : ";
            cin >> num;
            nmedium += num;
            medium += num;
            cout << "medium " << medium << endl;
        }
        break;
        case 3:
        {
            cout << "Enter number of cups : ";
            cin >> num;
            nlarge += num;
            large += num;
            cout << "large " << large << endl;
        }
        break;
        case 0:
        {
            float ts, tm, tl;
            float total;
            ts = nsmal * 1.79;
            tm = nmedium * 2.59;
            tl = nlarge * 3.99;
            total = ts + tm + tl;
            float tax = 0.0825 * total;

            cout << "\n\nFA2021_CoffeeShopApplication_Smith.cpp" << endl;
            cout << "SALE RECEIPT - JAMES – JAMES SMITH Today 10 / 15 / 21" << endl;
            cout << "-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -" << endl;
            cout << "SIZE\tNUMBER\tMONEY\n";
            cout << "SMALL($1 .79)\t" << nsmal << "\t" << nsmal * 1.79 << "\n";
            cout << "MEDIUM($2 .59)\t" << nmedium << "\t" << nmedium * 2.59 << "\n";
            cout << "LARGE($3 .99)\t" << nlarge << "\t" << nlarge * 3.99 << " " << endl;
            cout << "-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -\n";
            cout << "Subtotal : \t\t" << total << " " << endl;
            cout << "Tax(8.25 %) :\t\t " << tax << " " << endl;
            cout << "Total : \t\t" << total + tax << " " << endl;
            return;
        }
        break;
        default:
            cout << "Invalid input" << endl;
            break;
        }
    }
}

void totalcupSold(int small, int medium, int large)
{
    cout << "\n\nFA2021_CoffeeShopApplication_Smith.cpp" << endl;
    cout << "SALE RECEIPT - JAMES SMITH Today 10 / 15 / 21" << endl;
    cout << "-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -" << endl;
    cout << "SMALL SIZE ( 8oz)\t" << small << " cups\n";
    cout
        << "MEDIUM SIZE(12oz)\t" << medium << " cups\n";
    cout
        << "LARGE SIZE(16oz)\t" << large << " cups\n";
}
void calculate_coffeeOZ(int nsmall, int nmedium, int nlarge)
{
    cout << "\n\nFA2021_CoffeeShopApplication_Smith.cpp" << endl;
    cout << "SALE RECEIPT - JAMES – JAMES SMITH Today 10 / 15 / 21" << endl;
    cout << "-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -" << endl;
    cout << "Size \t"
         << "\tNUMBER OF CUP\t"
         << "COFFEE AMOUNT" << endl;
    cout << "Small (8oz)"
         << "\t\t" << nsmall << "\t" << nsmall * 8 << endl;
    cout << "Medium (12oz)"
         << "\t\t" << nsmall << "\t" << nmedium * 12 << endl;
    cout << "Large (16oz)"
         << "\t\t" << nsmall << "\t" << nlarge * 16 << endl;
}

void reportTotalMoney(int nsmall, int nmedium, int nlarge)
{

    float ts = nsmall * 1.79;
    float tm = nmedium * 2.59;
    float tl = nlarge * 3.99;
    float total = ts + tm + tl;
    float tax = 0.0825 * total;
    cout << "\n\nFA2021_CoffeeShopApplication_Smith.cpp" << endl;
    cout << "SALE RECEIPT - JAMES – JAMES SMITH Today 10 / 15 / 21" << endl;
    cout << "-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -" << endl;
    cout << "SIZE\tUNIT PRICE\tNUMBER\tMONEY\n";
    cout << "SMALL\t " << 1.79 << "\t\t" << nsmall << "\t" << nsmall * 1.79 << "\n";
    cout << "MEDIUM\t " << 2.59 << "\t\t" << nmedium << "\t" << nmedium * 2.59 << "\n";
    cout << "LARGE\t " << 3.99 << "\t\t" << nlarge << "\t" << nlarge * 3.99 << " " << endl;
    cout << "-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -\n";
    cout << "SUM : \t\t\t" << total << " " << endl;
    cout << "Tax(8.25 %) :\t\t " << tax << " " << endl;
    cout << "Total : \t\t" << total + tax << " " << endl;
}
int main()
{
    int numsmall = 0, nummedium = 0, numlarge = 0;
    while (1)
    {
        int choice;

        cout << "\n\nFA2021_CoffeeShopApplication_Smith.cpp\nSALE COFFEE – JAMES SMITH\tToday 10 /15 / 21\n -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --" << endl;
        cout << "1.Sale coffee \n2.Report total number of cups sold in the day \n3.Report total amount of coffee in OZ sold in the day \n4.Report total money sold in the day \n0.EXIT " << endl;
        cout << "Enter choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "\n\nFA2021_CoffeeShopApplication_Smith.cpp\nSALE COFFEE – JAMES SMITH\tToday 10 /15 / 21\n -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --" << endl;
            sale_coffee(numsmall, nummedium, numlarge);
        }
        break;
        case 2:
        {
            totalcupSold(numsmall, nummedium, numlarge);
        }
        break;
        case 3:
            calculate_coffeeOZ(numsmall, nummedium, numlarge);
            break;
        case 4:
            reportTotalMoney(numsmall, nummedium, numlarge);
            break;
        case 0:
            exit(0);
            break;
        default:
            break;
        }
    }

    return 0;
}