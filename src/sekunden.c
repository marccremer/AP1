# include <stdio.h>

int main () {
	int tage;
	float result;
	tage  = 31;
	result =24 * 31 * 60 *60;
	printf("Der Monat Oktober mit %i tagen hat %8.0f sekunden \n",tage,result);
	return 0;
}