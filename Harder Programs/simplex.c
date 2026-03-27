#include<stdio.h>

int main(){
	//variable declarations
	int n,i,j,PC = 0,O,PR = 0,C;float PE = 0,D,E,temp;
	float a[3][6];
	char *H[7] = {"BV","x","y","s1","s2","Z","RHS"};
	char *S[3] = {"s1","s2","-"};
	char *S1[3] = {"x","s2","-"};
	char *S2[3] = {"y","s2","-"};
	char *S3[3] = {"s1","x","-"};
	char *S4[3] = {"s1","y","-"};
	char *S5[3] = {"x","y","-"};
	char *S6[3] = {"y","x","-"};

	char *HM[7] = {"BV","u","v","x","y","Z","RHS"};
	char *SM[3] = {"x","y","-"};
	char *SM1[3] = {"u","y","-"};
	char *SM2[3] = {"v","y","-"};
	char *SM3[3] = {"x","u","-"};
	char *SM4[3] = {"x","v","-"};
	char *SM5[3] = {"u","v","-"};
	char *SM6[3] = {"v","u","-"};
	//Case determination
	printf("Enter 1 for Max and 2 for Min: ");
	scanf("%d",&n);

	switch (n) {
		case 1://for maximizing
			for (i = 0; i < 3; i++) {
				for (j  = 0; j < 6; j++) {
					if (i != 2  && j == 0 ) {
						printf("Enter the coefficient of x in inequality %d: ",i+1);
						scanf("%f",&a[i][j]);
					}else if(i != 2 && j == 1){
						printf("Enter the coefficient of y in inequality %d: ",i+1);
						scanf("%f",&a[i][j]);
					}else if(i != 2 && j == 5){
						printf("Enter the consant in inequality %d: ",i+1);
						scanf("%f",&a[i][j]);
					}
					else if (i == 2 && j == 0){
						printf("Enter the coefficient of x in the objective function: ");
						scanf("%f",&a[i][j]);
					}
					else if (i == 2 && j == 1){
						printf("Enter the coefficient of y in the objective function: ");
						scanf("%f",&a[i][j]);
					}
				}
			}
			//Printing the first steps
			printf("Max(Z) = %.0fx + %.0fy \n",a[2][0],a[2][1]);//Objective function
			printf("Subject to: \n");
			printf("%.0fx + %.0fy <= %.0f \n",a[0][0],a[0][1],a[0][5]);//Constraint
			printf("%.0fx + %.0fy <= %.0f \n",a[1][0],a[1][1],a[1][5]);//Constraint
			printf("\n");

			printf("Let s1 and s2 be two slack variables such that: \n \n");
			printf("%.0fx + %.0fy + s1 = %.0f \n",a[0][0],a[0][1],a[0][5]);
			printf("%.0fx + %.0fy + s2 = %.0f \n",a[1][0],a[1][1],a[1][5]);
			printf("\n");

			printf("Writing in standard LPP: \n \n");
			printf("%.0fx + %.0fy + s1 + 0s2 + 0z = %.0f \n",a[0][0],a[0][1],a[0][5]);
			printf("%.0fx + %.0fy + 0s1 + s2 + 0z = %.0f \n",a[1][0],a[1][1],a[1][5]);
			printf("%.0fx + %.0fy + 0s1 + 0s2 + 1z = 0 \n",-a[2][0],-a[2][1]);
			printf("\n");
			//giving values to the indexes which are always same initiallyl, ie the columns of s1,s2 ,and z
			a[0][2] = 1 ; a[0][3] = 0; a[0][4] = 0;
			a[1][2] = 0 ; a[1][3] = 1; a[1][4] = 0;
			a[2][2] = 0 ; a[2][3] = 0; a[2][4] = 1;
			a[2][0] = -a[2][0]; a[2][1] =-a[2][1];//changing coefficients of objective function to be opposite of the original as everything is brought to LHS so that Z is positive in the table.
			printf("Initial simple Tableau: \n\n");//printing the initial table
			for (i=  0; i < 7; i ++) {
				printf("%-10s",H[i]);
			}
			printf("\n");
			for (i = 0; i < 3; i++) {
				printf("%-10s",S[i]);
				for (j = 0; j < 6; j++) {
					printf("%-10.0f",a[i][j]);
				}
				printf("\n");
			}
			printf("\n");
			//calculating pivot column based on the smallest number in the third row
			if (a[2][0] < a[2][1]) {
				PC = 0;
				printf("Column %d is the piviot column \n",PC+1);
			}
			else if(a[2][0] > a[2][1]){
				PC = 1;
				printf("Column %d is the piviot column \n",PC+1);
			}
			else{
				PC = 0;
				printf("Column %d is the piviot column \n",PC+1);
			}
			//calculating piviot row based on the lowest ratio with the corresponding piviot column
			if (a[0][5]/a[0][PC] < a[1][5]/a[1][PC]) {
				PR = 0;
				printf("Row %d is the piviot row \n",PR+1);
			}
			else if(a[0][5]/a[0][PC] > a[1][5]/a[1][PC]){
				PR = 1;
				printf("Piviot Row is %d \n",PR+1);
			}
			else{
				PR = 0;
				printf("Piviot Row is %d \n",PR+1);
			}
			PE = a[PR][PC];//calculating piviot element
			printf("The piviot element is %.2f \n",PE);
			printf("Applying R%d --> R%d/%.2f \n",PR+1,PR+1,PE);
			for (j = 0; j < 6; j++) {
				a[PR][j] /= PE;//dividing piviot row by piviot elemrnt to make piviot element 1
			}
			for (i=  0; i < 7; i ++) {//printing after dividing
				printf("%-10s",H[i]);
			}
			printf("\n");
			if (PR == 0 && PC == 0) {
				for (i = 0; i < 3; i++) {
					printf("%-10s",S1[i]);
					for (j = 0; j < 6; j++) {
						printf("%-10.2f",a[i][j]);
					}
					printf("\n");
				}
				printf("\n");
			}
			else if (PR == 1 && PC == 0) {
				for (i = 0; i < 3; i++) {
					printf("%-10s",S3[i]);
					for (j = 0; j < 6; j++) {
						printf("%-10.2f",a[i][j]);
					}
					printf("\n");
				}
				printf("\n");
			}
			else if (PR == 0 && PC == 1) {
				for (i = 0; i < 3; i++) {
					printf("%-10s",S2[i]);
					for (j = 0; j < 6; j++) {
						printf("%-10.2f",a[i][j]);
					}
					printf("\n");
				}
				printf("\n");
			}
			else{
				for (i = 0; i < 3; i++) {
					printf("%-10s",S4[i]);
					for (j = 0; j < 6; j++) {
						printf("%-10.2f",a[i][j]);
					}
					printf("\n");
				}
				printf("\n");
			}
			printf("\n");
			if (PR == 0 && PC == 0) {
				D = a[1][0];
				E = -a[2][0];
				O = 2;
				C = 1;
			}
			else if (PR == 1 && PC == 0) {
				D = a[0][0];
				E = -a[2][0];
				O = 1;
				C = 2;
			}
			else if (PR == 0 && PC == 1) {
				D = a[1][1];
				E = -a[2][1];
				O = 2;
				C = 3;
			}
			else{
				D = a[0][1];
				E = -a[2][1];
				O = 1;
				C = 4;
			}

				for (j = 0; j < 6; j++) {
					a[O-1][j] -= a[PR][j]*D;
					a[2][j] += a[PR][j]*E;
				}

			printf("Applying R%d --> R%d - %.2fR%d and R3 --> R3 + %.2fR%d\n",O,O,D,PR + 1,E,PR + 1);
			for (i=  0; i < 7; i ++) {
				printf("%-10s",H[i]);
			}
			printf("\n");
			if (PR == 0 && PC == 0) {
				for (i = 0; i < 3; i++) {
					printf("%-10s",S1[i]);
					for (j = 0; j < 6; j++) {
						printf("%-10.2f",a[i][j]);
					}
					printf("\n");
				}
				printf("\n");
			}
			else if (PR == 1 && PC == 0) {
				for (i = 0; i < 3; i++) {
					printf("%-10s",S3[i]);
					for (j = 0; j < 6; j++) {
						printf("%-10.2f",a[i][j]);
					}
					printf("\n");
				}
				printf("\n");
			}
			else if (PR == 0 && PC == 1) {
				for (i = 0; i < 3; i++) {
					printf("%-10s",S2[i]);
					for (j = 0; j < 6; j++) {
						printf("%-10.2f",a[i][j]);
					}
					printf("\n");
				}
				printf("\n");
			}
			else{
				for (i = 0; i < 3; i++) {
					printf("%-10s",S4[i]);
					for (j = 0; j < 6; j++) {
						printf("%-10.2f",a[i][j]);
					}
					printf("\n");
				}
				printf("\n");
			}
			if (a[2][0] == 0 && a[2][1] > 0) {
				printf("The value of x is: %.2f\n",a[PR][5]);
				printf("The value of y is: 0\n");
				printf("The Max is: %.2f\n",a[2][5]);
				return 0;
			}
			else if(a[2][0] > 0 && a[2][1] == 0){
				printf("The value of x is: 0\n");
				printf("The value of y is: %.2f\n",a[PR][5]);
				printf("The Max is: %.2f\n",a[2][5]);
				return 0;
			}
			if (a[2][0] == 0) {
				PC = 1;
			}
			else{
				PC = 0;
			}
			printf("Piviot column is %d \n",PC+1);
			if (a[0][5]/a[0][PC] < a[1][5]/a[1][PC]) {
				PR = 0;
				printf("Row %d is the piviot row \n",PR+1);
			}
			else if(a[0][5]/a[0][PC] > a[1][5]/a[1][PC]){
				PR = 1;
				printf("Piviot Row is %d \n",PR+1);
			}
			else{
				PR = 0;
				printf("Piviot Row is %d \n",PR+1);
			}
			PE = a[PR][PC];
			printf("The piviot element is %.2f \n",PE);
			printf("Applying R%d --> R%d/%.2f \n",PR+1,PR+1,PE);
			for (j = 0; j < 6; j++) {
				a[PR][j] /= PE;
			}
			for (i=  0; i < 7; i ++) {
				printf("%-10s",H[i]);
			}
			printf("\n");
			if (PR == 0 && C == 1) {
				for (i = 0; i < 3; i++) {
					printf("%-10s",S2[i]);
					for (j = 0; j < 6; j++) {
						printf("%-10.2f",a[i][j]);
					}
					printf("\n");
				}
				printf("\n");
			}
			else if(PR == 0 && C == 2){
				for (i = 0; i < 3; i++) {
					printf("%-10s",S6[i]);
					for (j = 0; j < 6; j++) {
						printf("%-10.2f",a[i][j]);
					}
					printf("\n");
				}
				printf("\n");
			}
			else if(PR == 0 && C == 3){
				for (i = 0; i < 3; i++) {
					printf("%-10s",S1[i]);
					for (j = 0; j < 6; j++) {
						printf("%-10.2f",a[i][j]);
					}
					printf("\n");
				}
				printf("\n");
			}
			else if(PR == 0 && C == 4){
				for (i = 0; i < 3; i++) {
					printf("%-10s",S5[i]);
					for (j = 0; j < 6; j++) {
						printf("%-10.2f",a[i][j]);
					}
					printf("\n");
				}
				printf("\n");
			}
			else if(PR == 1 && C == 1){
				for (i = 0; i < 3; i++) {
					printf("%-10s",S5[i]);
					for (j = 0; j < 6; j++) {
						printf("%-10.2f",a[i][j]);
					}
					printf("\n");
				}
				printf("\n");
			}
			else if(PR == 1 && C == 2){
				for (i = 0; i < 3; i++) {
					printf("%-10s",S4[i]);
					for (j = 0; j < 6; j++) {
						printf("%-10.2f",a[i][j]);
					}
					printf("\n");
				}
				printf("\n");
			}else if(PR == 1 && C == 3){
				for (i = 0; i < 3; i++) {
					printf("%-10s",S6[i]);
					for (j = 0; j < 6; j++) {
						printf("%-10.2f",a[i][j]);
					}
					printf("\n");
				}
				printf("\n");
			}
			else if(PR == 1 && C == 4){
				for (i = 0; i < 3; i++) {
					printf("%-10s",S3[i]);
					for (j = 0; j < 6; j++) {
						printf("%-10.2f",a[i][j]);
					}
					printf("\n");
				}
				printf("\n");
			}
			printf("\n");
			if (PR == 0 && PC == 0) {
				D = a[1][0];
				E = -a[2][0];
				O = 2;
			}
			else if (PR == 1 && PC == 0) {
				D = a[0][0];
				E = -a[2][0];
				O = 1;
			}
			else if (PR == 0 && PC == 1) {
				D = a[1][1];
				E = -a[2][1];
				O = 2;
			}
			else{
				D = a[0][1];
				E = -a[2][1];
				O = 1;
			}

				for (j = 0; j < 6; j++) {
					a[O-1][j] -= a[PR][j]*D;
					a[2][j] += a[PR][j]*E;
				}

			printf("Applying R%d --> R%d - %.2fR%d and R3 --> R3 + %.2fR%d\n",O,O,D,PR + 1,E,PR + 1);
			for (i=  0; i < 7; i ++) {
				printf("%-10s",H[i]);
			}
			printf("\n");
			if (PR == 0 && C == 1) {
				for (i = 0; i < 3; i++) {
					printf("%-10s",S2[i]);
					for (j = 0; j < 6; j++) {
						printf("%-10.2f",a[i][j]);
					}
					printf("\n");
				}
				printf("The value of x is: 0\n");
				printf("The value of y is: %.2f\n",a[PR][5]);
				printf("The Max is: %.2f\n",a[2][5]);
				printf("\n");
			}
			else if(PR == 0 && C == 2){
				for (i = 0; i < 3; i++) {
					printf("%-10s",S6[i]);
					for (j = 0; j < 6; j++) {
						printf("%-10.2f",a[i][j]);
					}
					printf("\n");
				}
				printf("The value of y is: %.2f\n",a[PR+1][5]);
				printf("The value of x is: %.2f\n",a[PR][5]);
				printf("The Max is: %.2f\n",a[2][5]);
				printf("\n");
			}
			else if(PR == 0 && C == 3){
				for (i = 0; i < 3; i++) {
					printf("%-10s",S1[i]);
					for (j = 0; j < 6; j++) {
						printf("%-10.2f",a[i][j]);
					}
					printf("\n");
				}
				printf("The value of x is: %.2f\n",a[PR][5]);
				printf("The value of y is: 0\n");
				printf("The Max is: %.2f\n",a[2][5]);
				printf("\n");
			}
			else if(PR == 0 && C == 4){
				for (i = 0; i < 3; i++) {
					printf("%-10s",S5[i]);
					for (j = 0; j < 6; j++) {
						printf("%-10.2f",a[i][j]);
					}
					printf("\n");
				}
				printf("The value of x is: %.2f\n",a[PR][5]);
				printf("The value of y is: %.2f\n",a[PR+1][5]);
				printf("The Max is: %.2f\n",a[2][5]);
				printf("\n");
			}
			else if(PR == 1 && C == 1){
				for (i = 0; i < 3; i++) {
					printf("%-10s",S5[i]);
					for (j = 0; j < 6; j++) {
						printf("%-10.2f",a[i][j]);
					}
					printf("\n");
				}
				printf("The value of x is: %.2f\n",a[PR-1][5]);
				printf("The value of y is: %.2f\n",a[PR][5]);
				printf("The Max is: %.2f\n",a[2][5]);
				printf("\n");
			}
			else if(PR == 1 && C == 2){
				for (i = 0; i < 3; i++) {
					printf("%-10s",S4[i]);
					for (j = 0; j < 6; j++) {
						printf("%-10.2f",a[i][j]);
					}
					printf("\n");
				}
				printf("The value of x is: 0\n");
				printf("The value of y is: %.2f\n",a[PR][5]);
				printf("The Max is: %.2f\n",a[2][5]);
				printf("\n");
			}
			else if(PR == 1 && C == 3){
				for (i = 0; i < 3; i++) {
					printf("%-10s",S6[i]);
					for (j = 0; j < 6; j++) {
						printf("%-10.2f",a[i][j]);
					}
					printf("\n");
				}
				printf("The value of x is: %.2f\n",a[PR][5]);
				printf("The value of y is: %.2f\n",a[PR-1][5]);
				printf("The Max is: %.2f\n",a[2][5]);
				printf("\n");
			}

			else if(PR == 1 && C == 4){
				for (i = 0; i < 3; i++) {
					printf("%-10s",S3[i]);
					for (j = 0; j < 6; j++) {
						printf("%-10.2f",a[i][j]);
					}
					printf("\n");
				}
				printf("The value of x is: %.2f\n",a[PR][5]);
				printf("The value of y is: 0\n");
				printf("The Max is: %.2f\n",a[2][5]);
				printf("\n");
				printf("\n");
			}
			break;

		case 2:
			for (i = 0; i < 3; i++) {
				for (j  = 0; j < 6; j++) {
					if (i != 2  && j == 0 ) {
						printf("Enter the coefficient of x in inequality %d: ",i+1);
						scanf("%f",&a[i][j]);
					}else if(i != 2 && j == 1){
						printf("Enter the coefficient of y in inequality %d: ",i+1);
						scanf("%f",&a[i][j]);
					}else if(i != 2 && j == 5){
						printf("Enter the consant in inequality %d: ",i+1);
						scanf("%f",&a[i][j]);
					}
					else if (i == 2 && j == 0){
						printf("Enter the coefficient of x in the objective function: ");
						scanf("%f",&a[i][j]);
					}
					else if (i == 2 && j == 1){
						printf("Enter the coefficient of y in the objective function: ");
						scanf("%f",&a[i][j]);
					}
				}
			}
			temp = a[1][0];
			a[1][0] = a[0][1];
			a[0][1] = temp;

			temp = a[2][1];
			a[2][1] = a[1][5];
			a[1][5] = temp;

			temp = a[2][0];
			a[2][0] = a[0][5];
			a[0][5] = temp;
			printf("After transposing and changing variables we get: \n");
			printf("Max(Z) = %.0fu + %.0fv \n",a[2][0],a[2][1]);
			printf("Subject to: \n");
			printf("%.0fu + %.0fv <= %.0f \n",a[0][0],a[0][1],a[0][5]);
			printf("%.0fu + %.0fv <= %.0f \n",a[1][0],a[1][1],a[1][5]);
			printf("\n");

			printf("Let x and y be two slack variables such that: \n \n");
			printf("%.0fu + %.0fv + x = %.0f \n",a[0][0],a[0][1],a[0][5]);
			printf("%.0fu + %.0fv + y = %.0f \n",a[1][0],a[1][1],a[1][5]);
			printf("\n");

			printf("Writing in standard LPP: \n \n");
			printf("%.0fu + %.0fv + x + 0y + 0z = %.0f \n",a[0][0],a[0][1],a[0][5]);
			printf("%.0fu + %.0fv + 0x + y + 0z = %.0f \n",a[1][0],a[1][1],a[1][5]);
			printf("%.0fu + %.0fv + 0x + 0y + 1z = 0 \n",-a[2][0],-a[2][1]);
			printf("\n");

			a[0][2] = 1 ; a[0][3] = 0; a[0][4] = 0;
			a[1][2] = 0 ; a[1][3] = 1; a[1][4] = 0;
			a[2][2] = 0 ; a[2][3] = 0; a[2][4] = 1; a[2][0] = -a[2][0]; a[2][1] =-a[2][1];

			printf("Initial simple Tableau: \n\n");
			for (i=  0; i < 7; i ++) {
				printf("%-10s",HM[i]);
			}
			printf("\n");
			for (i = 0; i < 3; i++) {
				printf("%-10s",SM[i]);
				for (j = 0; j < 6; j++) {
					printf("%-10.0f",a[i][j]);
				}
				printf("\n");
			}
			printf("\n");
			if (a[2][0] < a[2][1]) {
				PC = 0;
				printf("Column %d is the piviot column \n",PC+1);
			}
			else if(a[2][0] > a[2][1]){
				PC = 1;
				printf("Column %d is the piviot column \n",PC+1);
			}
			else{
				PC = 0;
				printf("Column %d is the piviot column \n",PC+1);
			}
			if (a[0][5]/a[0][PC] < a[1][5]/a[1][PC]) {
				PR = 0;
				printf("Row %d is the piviot row \n",PR+1);
			}
			else if(a[0][5]/a[0][PC] > a[1][5]/a[1][PC]){
				PR = 1;
				printf("Piviot Row is %d \n",PR+1);
			}
			else{
				PR = 0;
				printf("Piviot Row is %d \n",PR+1);
			}
			PE = a[PR][PC];
			printf("The piviot element is %.2f \n",PE);
			printf("Applying R%d --> R%d/%.2f \n",PR+1,PR+1,PE);
				for (j = 0; j < 6; j++) {
					a[PR][j] /= PE;
				}
			for (i=  0; i < 7; i ++) {
				printf("%-10s",HM[i]);
			}
			printf("\n");
			if (PR == 0 && PC == 0) {
				for (i = 0; i < 3; i++) {
					printf("%-10s",SM1[i]);
					for (j = 0; j < 6; j++) {
						printf("%-10.2f",a[i][j]);
					}
					printf("\n");
				}
				printf("\n");
			}
			else if (PR == 1 && PC == 0) {
				for (i = 0; i < 3; i++) {
					printf("%-10s",SM3[i]);
					for (j = 0; j < 6; j++) {
						printf("%-10.2f",a[i][j]);
					}
					printf("\n");
				}
				printf("\n");
			}
			else if (PR == 0 && PC == 1) {
				for (i = 0; i < 3; i++) {
					printf("%-10s",SM2[i]);
					for (j = 0; j < 6; j++) {
						printf("%-10.2f",a[i][j]);
					}
					printf("\n");
				}
				printf("\n");
			}
			else{
				for (i = 0; i < 3; i++) {
					printf("%-10s",SM4[i]);
					for (j = 0; j < 6; j++) {
						printf("%-10.2f",a[i][j]);
					}
					printf("\n");
				}
				printf("\n");
			}
			if (PR == 0 && PC == 0) {
				D = a[1][0];
				E = -a[2][0];
				O = 2;
				C = 1;
			}
			else if (PR == 1 && PC == 0) {
				D = a[0][0];
				E = -a[2][0];
				O = 1;
				C = 2;
			}
			else if (PR == 0 && PC == 1) {
				D = a[1][1];
				E = -a[2][1];
				O = 2;
				C = 3;
			}
			else{
				D = a[0][1];
				E = -a[2][1];
				O = 1;
				C = 4;
			}

				for (j = 0; j < 6; j++) {
					a[O-1][j] -= a[PR][j]*D;
					a[2][j] += a[PR][j]*E;
				}

			printf("Applying R%d --> R%d - %.2fR%d and R3 --> R3 + %.2fR%d\n",O,O,D,PR + 1,E,PR + 1);
			for (i=  0; i < 7; i ++) {
				printf("%-10s",HM[i]);
			}
			printf("\n");
			if (PR == 0 && PC == 0) {
				for (i = 0; i < 3; i++) {
					printf("%-10s",SM1[i]);
					for (j = 0; j < 6; j++) {
						printf("%-10.2f",a[i][j]);
					}
					printf("\n");
				}
				printf("\n");
			}
			else if (PR == 1 && PC == 0) {
				for (i = 0; i < 3; i++) {
					printf("%-10s",SM3[i]);
					for (j = 0; j < 6; j++) {
						printf("%-10.2f",a[i][j]);
					}
					printf("\n");
				}
				printf("\n");
			}
			else if (PR == 0 && PC == 1) {
				for (i = 0; i < 3; i++) {
					printf("%-10s",SM2[i]);
					for (j = 0; j < 6; j++) {
						printf("%-10.2f",a[i][j]);
					}
					printf("\n");
				}
				printf("\n");
			}
			else{
				for (i = 0; i < 3; i++) {
					printf("%-10s",SM4[i]);
					for (j = 0; j < 6; j++) {
						printf("%-10.2f",a[i][j]);
					}
					printf("\n");
				}
				printf("\n");
			}
			if (a[2][0] == 0 && a[2][1] > 0) {
				printf("The value of x is: %.2f\n",a[2][2]);
				printf("The value of y is: 0\n");
				printf("The Max is: %.2f\n",a[2][5]);
				return 0;
			}
			else if(a[2][0] > 0 && a[2][1] == 0){
				printf("The value of x is: 0\n");
				printf("The value of y is: %.2f\n",a[2][3]);
				printf("The Max is: %.2f\n",a[2][5]);
				return 0;
			}
			if (a[2][0] == 0) {
				PC = 1;
			}
			else{
				PC = 0;
			}
			printf("Piviot column is %d \n",PC+1);
			if (a[0][5]/a[0][PC] < a[1][5]/a[1][PC]) {
				PR = 0;
				printf("Row %d is the piviot row \n",PR+1);
			}
			else if(a[0][5]/a[0][PC] > a[1][5]/a[1][PC]){
				PR = 1;
				printf("Piviot Row is %d \n",PR+1);
			}
			else{
				PR = 0;
				printf("Piviot Row is %d \n",PR+1);
			}
			PE = a[PR][PC];
			printf("The piviot element is %.2f \n",PE);
			printf("Applying R%d --> R%d/%.2f \n",PR+1,PR+1,PE);
				for (j = 0; j < 6; j++) {
					a[PR][j] /= PE;
				}
			for (i=  0; i < 7; i ++) {
				printf("%-10s",HM[i]);
			}
			printf("\n");
			if (PR == 0 && C == 1) {
				for (i = 0; i < 3; i++) {
					printf("%-10s",SM2[i]);
					for (j = 0; j < 6; j++) {
						printf("%-10.2f",a[i][j]);
					}
					printf("\n");
				}
				printf("\n");
			}
			else if(PR == 0 && C == 2){
				for (i = 0; i < 3; i++) {
					printf("%-10s",SM6[i]);
					for (j = 0; j < 6; j++) {
						printf("%-10.2f",a[i][j]);
					}
					printf("\n");
				}
				printf("\n");
			}
			else if(PR == 0 && C == 3){
				for (i = 0; i < 3; i++) {
					printf("%-10s",SM1[i]);
					for (j = 0; j < 6; j++) {
						printf("%-10.2f",a[i][j]);
					}
					printf("\n");
				}
				printf("\n");
			}
			else if(PR == 0 && C == 4){
				for (i = 0; i < 3; i++) {
					printf("%-10s",SM5[i]);
					for (j = 0; j < 6; j++) {
						printf("%-10.2f",a[i][j]);
					}
					printf("\n");
				}
				printf("\n");
			}
			else if(PR == 1 && C == 1){
				for (i = 0; i < 3; i++) {
					printf("%-10s",SM5[i]);
					for (j = 0; j < 6; j++) {
						printf("%-10.2f",a[i][j]);
					}
					printf("\n");
				}
				printf("\n");
			}
			else if(PR == 1 && C == 2){
				for (i = 0; i < 3; i++) {
					printf("%-10s",SM4[i]);
					for (j = 0; j < 6; j++) {
						printf("%-10.2f",a[i][j]);
					}
					printf("\n");
				}
				printf("\n");
			}
			else if(PR == 1 && C == 3){
				for (i = 0; i < 3; i++) {
					printf("%-10s",SM6[i]);
					for (j = 0; j < 6; j++) {
						printf("%-10.2f",a[i][j]);
					}
					printf("\n");
				}
				printf("\n");
			}
			else if(PR == 1 && C == 4){
				for (i = 0; i < 3; i++) {
					printf("%-10s",SM3[i]);
					for (j = 0; j < 6; j++) {
						printf("%-10.2f",a[i][j]);
					}
					printf("\n");
				}
				printf("\n");
			}
			printf("\n");
			if (PR == 0 && PC == 0) {
				D = a[1][0];
				E = -a[2][0];
				O = 2;
			}
			else if (PR == 1 && PC == 0) {
				D = a[0][0];
				E = -a[2][0];
				O = 1;
			}
			else if (PR == 0 && PC == 1) {
				D = a[1][1];
				E = -a[2][1];
				O = 2;
			}
			else{
				D = a[0][1];
				E = -a[2][1];
				O = 1;
			}

				for (j = 0; j < 6; j++) {
					a[O-1][j] -= a[PR][j]*D;
					a[2][j] += a[PR][j]*E;
				}

			printf("Applying R%d --> R%d - %.2fR%d and R3 --> R3 + %.2fR%d\n",O,O,D,PR + 1,E,PR + 1);

			for (i=  0; i < 7; i ++) {
				printf("%-10s",HM[i]);
			}
			printf("\n");
			if (PR == 0 && C == 1) {
				for (i = 0; i < 3; i++) {
					printf("%-10s",SM2[i]);
					for (j = 0; j < 6; j++) {
						printf("%-10.2f",a[i][j]);
					}
					printf("\n");
				}
				printf("The value of x is: %.2f\n",a[2][2]);
				printf("The value of y is: %.2f\n",a[2][3]);
				printf("The Min is: %.2f\n",a[2][5]);
				printf("\n");
			}
			else if(PR == 0 && C == 2){
				for (i = 0; i < 3; i++) {
					printf("%-10s",SM6[i]);
					for (j = 0; j < 6; j++) {
						printf("%-10.2f",a[i][j]);
					}
					printf("\n");
				}
				printf("The value of x is: %.2f\n",a[2][2]);
				printf("The value of y is: %.2f\n",a[2][3]);
				printf("The Min is: %.2f\n",a[2][5]);
				printf("\n");
			}
			else if(PR == 0 && C == 3){
				for (i = 0; i < 3; i++) {
					printf("%-10s",SM1[i]);
					for (j = 0; j < 6; j++) {
						printf("%-10.2f",a[i][j]);
					}
					printf("\n");
				}
				printf("The value of x is: %.2f\n",a[2][2]);
				printf("The value of y is: %.2f\n",a[2][3]);
				printf("The Min is: %.2f\n",a[2][5]);
				printf("\n");
			}
			else if(PR == 0 && C == 4){
				for (i = 0; i < 3; i++) {
					printf("%-10s",SM5[i]);
					for (j = 0; j < 6; j++) {
						printf("%-10.2f",a[i][j]);
					}
					printf("\n");
				}
				printf("The value of x is: %.2f\n",a[2][2]);
				printf("The value of y is: %.2f\n",a[2][3]);
				printf("The Min is: %.2f\n",a[2][5]);
				printf("\n");
			}
			else if(PR == 1 && C == 1){
				for (i = 0; i < 3; i++) {
					printf("%-10s",SM5[i]);
					for (j = 0; j < 6; j++) {
						printf("%-10.2f",a[i][j]);
					}
					printf("\n");
				}
				printf("The value of x is: %.2f\n",a[2][2]);
				printf("The value of y is: %.2f\n",a[2][3]);
				printf("The Min is: %.2f\n",a[2][5]);
				printf("\n");
			}
			else if(PR == 1 && C == 2){
				for (i = 0; i < 3; i++) {
					printf("%-10s",SM4[i]);
					for (j = 0; j < 6; j++) {
						printf("%-10.2f",a[i][j]);
					}
					printf("\n");
				}
				printf("The value of x is: %.2f\n",a[2][2]);
				printf("The value of y is: %.2f\n",a[2][3]);
				printf("The Min is: %.2f\n",a[2][5]);
				printf("\n");
			}
			else if(PR == 1 && C == 3){
				for (i = 0; i < 3; i++) {
					printf("%-10s",SM6[i]);
					for (j = 0; j < 6; j++) {
						printf("%-10.2f",a[i][j]);
					}
					printf("\n");
				}
				printf("The value of x is: %.2f\n",a[2][2]);
				printf("The value of y is: %.2f\n",a[2][3]);
				printf("The Min is: %.2f\n",a[2][5]);
				printf("\n");
			}
			else if(PR == 1 && C == 4){
				for (i = 0; i < 3; i++) {
					printf("%-10s",SM3[i]);
					for (j = 0; j < 6; j++) {
						printf("%-10.2f",a[i][j]);
					}
					printf("\n");
				}
				printf("The value of x is: %.2f\n",a[2][2]);
				printf("The value of y is: %.2f\n",a[2][3]);
				printf("The Min is: %.2f\n",a[2][5]);
				printf("\n");
			}
			break;
		default:
		break;
	}
	return 0;
}
