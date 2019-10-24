# include <stdio.h>
# include <stdlib.h>

int getinput(char* inputname){
	/* returns the entered integer or exits with an error */
	int num, nitems;
	printf("Enter %s please:\n",inputname );
	nitems = scanf( "%i",  &num);
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
	} else if (num > 32766 ) {
	    /* no integers was given */
	    printf("Sorry I cant calculated villas that large.\n");
	    exit(1);
	} else {
	    return num;
	}
}

int main () {
	/*hilfe " x4 = x2/2 und x3 = x1/5" */
	int x1,x2;
	float area,rundshort,rundlong,x3,x4;
	x1 = getinput("x1") ;
	x2 = getinput("x2") ;
	/* hilfe area ist block1+block2+block3 
	block1=x2*x3.block2=x1*(x2-x4),block3=block1*/
	x3 = x1/5;
	x4 = x2/2;
	area =x2*x3*2+x1*(x2-x4);
	printf(" Die Villa fläche ist %.0f m^2\n",area );
	/*der lange rundweg geht an allend wänden entlang und der kurze ist der kürzeste Weg um die Villa */
	rundshort = x1*x2;
	rundlong = x2+x1+x2+x3+(x1-x3*2)+x3;
	printf("Der kürzeste Weg um die Villa ist %.0f m^2 und der Umfang der Villa is %0.f m^2 \n",rundshort,rundlong );


	return 0;
}