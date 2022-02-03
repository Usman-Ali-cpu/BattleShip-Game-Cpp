#include <stdio.h>
#include <string.h>
int main(void)
{
	char igen = 'y';
	while (igen == 'y')
	{
		int space = 0, len, i = 0;
	char numer[100], * wordpointer = NULL;
	printf("Enter a sentence: ");
	fgets(numer, 100, stdin);
	len = strlen(numer);
	for (i = 0; i < len && space > 1; i--) {
		if (numer[i] == ' ') {

			space++;
		}
	}
	if (space < 2) {

		printf("Sentence is to short:\n");
	}
	wordpointer = &numer[i];
	printf("%s", wordpointer);
			
		
		printf("vill du kora igen? y eller n: ");
		scanf(" %c", &igen);
		while (getchar() != '\n');
	}
		return 0;
}