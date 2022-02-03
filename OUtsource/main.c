#include <stdio.h>
#include <stdlib.h>
typedef struct item {
	int itemID;
	int numParts;
} item;

typedef struct recipe {
	int numItems;
	item* itemList;
	int totalParts;
} recipe;

// Pre-condition: 0 < numIngredients <= 100000
// Post-condition: Reads in numIngredients number of strings
// from standard input, allocates an array of
// strings to store the input, and sizes each
// individual string dynamically to be the
// proper size (string length plus 1), and 
// returns a pointer to the array.
char** readIngredients(int numIngredients);
// Pre-condition: 0 < numItems <= 100
// Post-condition: Reads in numItems number of items
// from standard input for a smoothie recipe,
// Dynamically allocates space for a single
// recipe, dynamically allocates an array of
// item of the proper size, updates the
// numItems field of the struct, fills the
// array of items appropriately based on the 
// input and returns a pointer to the struct
// dynamically allocated.
recipe* readRecipe(int numItems);
// Pre-condition: 0 < numRecipes <= 100000
// Post-condition: Dynamically allocates an array of pointers to
// recipes of size numRecipes, reads numRecipes
// number of recipes from standard input, creates
// structs to store each recipe and has the 
// pointers point to each struct, in the order 
// the information was read in. (Should call
// readRecipe in a loop.)
recipe** readAllRecipes(int numRecipes);
// Pre-condition: 0 < numSmoothies <= 100000, recipeList is 
// pointing to the list of all smoothie recipes and 
// numIngredients equals the number of total ingredients.
// Post-condition: Reads in information from standard input
// about numSmoothies number of smoothie orders and dynamically 
// allocates an array of doubles of size numIngredients such 
// that index i stores the # of pounds of ingredient i
// needed to fulfill all smoothie orders and returns a pointer 
// to the array.
double* calculateOrder(int numSmoothies, recipe** recipeList, int
	numIngredients);
// Pre-conditions: ingredientNames store the names of each
// ingredient and orderList stores the amount
// to order for each ingredient, and both arrays 
// are of size numIngredients.
// Post-condition: Prints out a list, in ingredient order, of each
// ingredient, a space and the amount of that
// ingredient to order rounded to 6 decimal
// places. One ingredient per line.
void printOrder(char** ingredientNames, double* orderList, int
	numIngredients);
// Pre-conditions: ingredientList is an array of char* of size 
// numIngredients with each char* dynamically allocated.
// Post-condition: all the memory pointed to by ingredientList is 
// freed.
void freeIngredients(char** ingredientList, int numIngredients);
// Pre-conditions: allRecipes is an array of recipe* of size 
// numRecipes with each recipe* dynamically allocated 
// to point to a single recipe.
// Post-condition: all the memory pointed to by allRecipes is 
// freed.
void freeRecipes(recipe** allRecipes, int numRecipes);

int main() {
	int numIngredients, numRecipes;
	char** ingredientList;
	recipe** smoothieList;
	double* amtOfEachItem;

	scanf("%d", &numIngredients);
	ingredientList = readIngredients(numIngredients);
	scanf("%d", &numRecipes);
	smoothieList = readAllRecipes(numRecipes);

	int numOfStores, numOfSmoothies, i;
	scanf("%d", &numOfStores);
	for (i = 1; i <= numOfStores; ++i) {
		scanf("%d", &numOfSmoothies);
		amtOfEachItem = calculateOrder(numOfSmoothies, smoothieList, numIngredients);
		printf("Store #%d:", i);
		printOrder(ingredientList, amtOfEachItem, numIngredients);
		free(amtOfEachItem);
	}
	freeRecipes(smoothieList, numRecipes);
	freeIngredients(ingredientList, numIngredients);
	return 0;
}

char** readIngredients(int numIngredients) {	
	int i, MAX_LENGTH = 30;
	char** ingredientList;
	ingredientList = (char**)malloc(sizeof(char*) * numIngredients);
	for (i = 0; i < numIngredients; ++i) {
		ingredientList[i] = (char*)malloc(sizeof(char) * MAX_LENGTH);
		scanf("%s", ingredientList[i]);
	}
	return ingredientList;
}

recipe* readRecipe(int numItems) {
	recipe* r = (recipe*) malloc (sizeof(recipe) * 1);
	r->itemList = (item*) malloc (sizeof(item) * numItems);
	r->numItems = numItems;
	
	int i;
	for (i = 0; i < numItems; ++i) {
		scanf("%d", &(r->itemList[i].itemID));
		scanf("%d", &(r->itemList[i].numParts));
	}

	r->totalParts = 0;
	for (i = 0; i < numItems; ++i) {
		r->totalParts = r->totalParts + r->itemList[i].numParts;
	}
	return r;
}

recipe** readAllRecipes(int numRecipes) {
	int i, numItems;
	recipe** recipeList = (recipe**)malloc(sizeof(recipe*) * numRecipes);
	for (i = 0; i < numRecipes; ++i) {
		scanf("%d", &numItems);
		recipeList[i] = readRecipe(numItems);
	}
	return recipeList;
}

double* calculateOrder(int numSmoothies, recipe** recipeList, int numIngredients) {
	double* pounds = (double*)malloc(sizeof(double) * numIngredients);
	int i, j, recipeNum;
	double amount;

	for (i = 0; i < numIngredients; ++i) {
		pounds[i] = 0;
	}
	for (i = 0; i < numSmoothies; i++) {
		scanf("%d %lf", &recipeNum, &amount);

		int numItems = recipeList[recipeNum]->numItems;
		item *list = recipeList[recipeNum]->itemList;
		for (j = 0; j < numItems; ++j) {
			pounds[list[j].itemID] += (list[j].numParts * (amount / recipeList[recipeNum]->totalParts));
		}
	}
	return pounds;
}

void printOrder(char** ingredientNames, double* orderList, int numIngredients) {
	int i;
	printf("\n");
	for (i = 0; i < numIngredients; i++) {
		if (orderList[i]) {
			printf("%s %lf\n", ingredientNames[i], orderList[i]);
		}
	}
	printf("\n");
}

void freeIngredients(char** ingredientList, int numIngredients) {
	int i;
	for (i = 0; i < numIngredients; ++i) {
		free(ingredientList[i]);
	}
	free(ingredientList);
}

void freeRecipes(recipe** allRecipes, int numRecipes) {
	int i;
	for (i = 0; i < numRecipes; ++i) {
		free(allRecipes[i]);
	}
	free(allRecipes);
}