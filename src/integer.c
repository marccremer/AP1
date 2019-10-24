# include <stdio.h>
# include <stdlib.h>

int getinput(char* inputname,int arr[]){
	/*returns the entered integer or exits with an error*/
	int num1,num2, nitems;
	printf("Enter %s please:\n",inputname );
	nitems = scanf( "%i %i",  &num1, &num2);
	if (nitems == EOF) {
	    /* no input */
	    printf("End of file was reached while nothing was read\n" );
	} else if (nitems == 0 ) {
	    /* no integers was given */
	    printf("Please enter only integers\n");
	    exit(1);
	} else if (num1 < 0 | num2 < 0) {
	    /* no integers was given */
	    printf("Please enter only positve num1bers\n");
	    exit(1);
	} else if (num1 > 2147483647  | num2 > 2147483647) {
	    /* no integers was given */
	    printf("Sorry I cant calculated values that large.\n");
	    exit(1);
	} else {
	    arr[0] = num1;
	    arr[1] = num2;
	}
}

int main()
{
	int x,y,result;
	int arr[2];
	printf("Programm Bereichsüberschreitungen\n\n");
	getinput("Geben Sie bitte zwei Integerzahlen ein: x, y",arr);
	result = arr[0] + arr[1] ;
	printf("Die Summe von %i und %i ist: %i\n",arr[0],arr[1],result );
	printf("Lets do some funky values\n");
	printf("lets add large values\n");
	int a,b,c;
	a = 3276612231;
	b = 3276612231;
	c = a+b;
	printf("3276612231 + 3276612231 = %i sizeof(%i)\n",c,sizeof(c));
	/*wir haben einen overflow und bekommen negative zahlen da wir denn speicherbereich von integer verlassen haben.
	Bei großen zahlen wird in den benachbarten speicher geschrieben ,aber nur 4 bytes gelesen(int) und die variable 
	erscheint negative
	c = 6553224462 in base 2  = (1) 10000110 10011010 01000101 00001110 ,wir haben mehr als 4 byte des integer
	Die  (1) wird nicht mitgelesen->10000110 10011010 01000101 00001110=-2036710130 */
	printf("lets add large negative values\n");
	a = -3276612211;
	b = -3276612211;
	c = a+b;
	printf("-327661221 + -327661221 = %i sizeof(%i)\n",c,sizeof(c));	
	/*hier warnte mich der compiler mit  [-Woverflow] und der Speicher läuft wieder über und liest nun die zahl als negative
	c = -6553224422 in base 2 als 2-er Komplement = 11111111111111111111111111111110 01111001 01100101 10111011 00011010
	Die (1..1) werden nicht mitgelesen -> 01111001 01100101 10111011 00011010 = 2036710170*/
	return 0;
}