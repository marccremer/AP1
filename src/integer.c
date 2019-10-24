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
	int a,b;
	a = 3276612231;
	b = 3276612231;
	printf("3276612231 + 3276612231 = %i\n",(a+b));
	/*wir haben einen overflow und bekommen negative zahlen da wir denn speicherbereich von integer verlassen habben
	Bei großen zahlen wird das Vorzeichen bit überschrieben und der cpu liest den speicher nun als negative zahl*/
	printf("lets add large negative values\n");
	a = -3276612211;
	b = -3276612211;
	printf("-327661221 + -327661221 = %i\n",(a+b));	
	/*hier warnte mich der compiler [-Woverflow] und das vorzeichen bit wurde wieder geflippt aber diesmal ins positive*/
	return 0;
}