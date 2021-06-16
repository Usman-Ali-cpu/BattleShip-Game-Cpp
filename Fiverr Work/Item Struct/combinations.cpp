#include<bits/stdc++.h>
#include <vector>
using namespace std;



struct Item{
    string name;
    unsigned int value;
    Item(string n, unsigned int v){
        this->name = n;
        this->value = v;
    }
    Item(){
        this->name = "none";
        this->value = 0;
    }
    void display(){
        cout<< "Name : " << this->name << endl;
        cout<< "Value : " << this->value<< endl<< endl;
    }
};






void combinationUtil(vector<Item>&arr, Item data[],
					int start, int end,
					int index, int r, int checksum);


void printCombination(vector<Item>&arr, int n, int r, int checksum)
{
	// A temporary array to store
	// all combination one by one
	Item data[r];

	// Print all combination using
	// temprary array 'data[]'
	combinationUtil(arr, data, 0, n-1, 0, r, checksum);
}

int getsum(Item arr[], int s){
    int sum = 0;
    for (int i = 0; i < s; i++){
        sum += arr[i].value;
    }
    return sum;
}

void combinationUtil(vector<Item>&arr , Item data[],
					int start, int end,
					int index, int r, int checksum)
{
	// Current combination is ready
	// to be printed, print it
	if (index == r)
	{
        if(getsum(data, r) == checksum)
        {
            cout << "{ ";
            for (int j = 0; j < r; j++)
            {
                cout << data[j].name << " : " << data[j].value << ", ";
            }
            cout <<" }" << endl;
        }
		return;
	}

	// replace index with all possible
	// elements. The condition "end-i+1 >= r-index"
	// makes sure that including one element
	// at index will make a combination with
	// remaining elements at remaining positions
	for (int i = start; i <= end &&
		end - i + 1 >= r - index; i++)
	{
		data[index] = arr[i];
		combinationUtil(arr, data, i+1,
						end, index+1, r, checksum);
	}
}

// Driver code
int main()
{
    vector<Item> vect;
    vect.push_back({"name1", 1});
    vect.push_back({ "name2", 2});
    vect.push_back({ "name3", 3});
    vect.push_back({ "name4", 4});
    vect.push_back({ "name5", 5});
    vect.push_back({ "name6", 6});
    vect.push_back({ "name7", 7});

    vect.push_back({ "name8", 8});
    vect.push_back({ "name9", 9});
    vect.push_back({ "name10", 10});

    vect.push_back({ "name11", 15});
    vect.push_back({ "name12", 20});
    vect.push_back({ "name13", 30});

	int r = 5;
    int n = vect.size();

     cout << "\n\t*********** WORKING ***********\n" << endl;

    cout << "\n\t*********** RESULTS ***********\n" << endl;

    // Function call
    printCombination(vect, n, r, 31);

    cout << "\n\t*********** COMPLETED ***********\n" << endl;
    
}
