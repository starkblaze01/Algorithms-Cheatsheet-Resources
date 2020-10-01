#include<stdio.h>

int main(){

        int cha;
	int r;
	int num1;
	int num2;
	char option = 'y';


	

	printf("choose the operation do you want to do\n");
	printf("1 = Addition\n");
	printf("2 = Subtraction\n");
	printf("3 = Multiplication\n");
	printf("4 = Divition\n");
	printf("5 = Module\n\n");
	
        while(option == 'y'){
	char cha=0;
	int r=0;
        int num1=0;
        int num2=0;


	printf("enter the operater:");
	scanf("%d", &cha);

	if (cha != 1 && cha != 2 && cha != 3 && cha != 4 && cha != 5){
                printf("invalid operator...try again.\n");
		return 0;
	}


        else {

		printf("Enter a number:");
		scanf("%d", &num1);

		printf("Enter a second number:");
        	scanf("%d", &num2);

		switch(cha){
	
			case 1:r = num1 + num2;
			   	printf("Answer(+) = %d\n", r);
			   	break;

			case 2:r = num1 - num2;
                       	    	printf("Answer(-) = %d\n", r);
                           	break;
	
			case 3:r = num1 * num2;
                           	printf("Answer(*) = %d\n", r);
                           	break;

			case 4:r = num1 / num2;
                           	printf("Answer(/) = %d\n", r);
                           	break;
		
			case 5:r = num1 % num2;
                           	printf("Answer(%) = %d\n", r);
                           	break;

			default:
				printf("Invalid input...\n");


	}

	

	printf("Do you want to continue(y/n):");
	scanf(" %c", &option);
	printf("\n");
	}
	}


	printf("\n");
	return 0;

} 

