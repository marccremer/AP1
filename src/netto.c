# include <stdio.h>
# include <stdlib.h>

float getinput(char* inputname){
	/*returns the entered integer or exits with an error */
	int  nitems;
	float num;

	printf("%s ",inputname );
	nitems = scanf( "%f",  &num);
	if (nitems == EOF) {
	    /* no input */
	    printf("End of file was reached while nothing was read\n" );
	} else if (nitems == 0) {
	    /* no integers was given */
	    printf("Please enter only integers\n");
	    exit(1);
	} else if (num < 0 ) {
	    /* no integers was given */
	    printf("Please enter only positve numbers\n");
	    exit(1);
	} else if (num > 2147483646 ) {
	    /* no integers was given */
	    printf("Sorry I cant calculated values that large.\n");
	    exit(1);
	} else {
	    return num;
	}
}

int  main()
{
	float netto,brutto,steuer;
	printf("Programm zur Berechnung eines Bruttobetrages\n \n");
	netto = getinput("Bitte geben Sie den Nettobetrag in EUR ein:");
	brutto = netto/1.19;
	steuer = netto-brutto;
	printf("Nettobetrag                 = %.2f€\n",netto);
	printf("Mehrwertsteuersatz  19.00 %   = %.2f€\n",steuer);
	printf("Bruttobetrag                = %.2f€\n",brutto);
	return 0;
}