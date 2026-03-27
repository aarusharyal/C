#include <stdio.h>
#include <math.h>

int main() {
	float a[3][4], D, E;
	int i, j,s;
	float epsilon = 1e-6; //Value extremely close to 0


	printf("Enter 1 for two variables and 2 for three variables: ");
	scanf("%d",&s);
	switch (s) {
		case 1:
			for (i = 0; i < 2; i++) {
				for (j = 0; j < 3; j ++) {
					if (j == 0) {
						printf("Enter the coefficient of X for equation %d:",i+1);
						scanf("%f",&a[i][j]);
					}
					else if (j == 1){
						printf("Enter the coefficient Y for equation %d: ",i+1);
						scanf("%f",&a[i][j]);
					}
					else{
						printf("Enter the constant for equation %d: ",i+1);
						scanf("%f",&a[i][j]);
					}
				}
			}
			printf("\n");
			printf("The augmented matrix [A:B] is:\n");
			for (i = 0; i < 2; i++) {
				for (j = 0; j < 3; j++) {
					if (j == 2) {
						printf(" : ");
					}
					printf("%-7.2f", fabs(a[i][j]) < epsilon ? 0.00 : a[i][j]);
				}
				printf("\n");
			}
			D = a[0][0];
			for (j = 0; j < 3; j++) {
				a[0][j] /= D;
			}
			printf("\n");
			printf("Applying R1 --> R1/%.2f\n", D);
			for (i = 0; i < 2; i++) {
				for (j = 0; j < 3; j++) {
					if (j == 2) {
						printf(" : ");
					}
					printf("%-7.2f", fabs(a[i][j]) < epsilon ? 0.00 : a[i][j]);
				}
				printf("\n");
			}
			D = a[1][0];
			for (j = 0; j < 3; j++) {
				a[1][j] -= (D * a[0][j]);
			}
			printf("\n");
			printf("Applying R2 --> R2 - %.2fR1 \n", D);
			for (i = 0; i < 2; i++) {
				for (j = 0; j < 3; j++) {
					if (j == 2) {
						printf(" : ");
					}
					printf("%-7.2f", fabs(a[i][j]) < epsilon ? 0.00 : a[i][j]);
				}
				printf("\n");
			}
			D = a[1][1];
			for (j = 0; j < 3; j++) {
				a[1][j] /= D;
			}
			printf("\n");
			printf("Applying R2 --> R2/%.2f\n", D);
			for (i = 0; i < 2; i++) {
				for (j = 0; j < 3; j++) {
					if (j == 2) {
						printf(" : ");
					}
					printf("%-7.2f", fabs(a[i][j]) < epsilon ? 0.00 : a[i][j]);
				}
				printf("\n");
			}
			D = a[0][1];
			for (j = 0; j < 3; j++) {
				a[0][j] -= (D * a[1][j]);
			}
			printf("\n");
			printf("Applying R1 --> R1 + %.2fR2 \n", D);
			for (i = 0; i < 2; i++) {
				for (j = 0; j < 3; j++) {
					if (j == 2) {
						printf(" : ");
					}
					printf("%-7.2f", fabs(a[i][j]) < epsilon ? 0.00 : a[i][j]);
				}
				printf("\n");
			}
			printf("\n");
			printf("The value of X is %.2f\n", a[0][2]);
			printf("The value of Y is %.2f\n", a[1][2]);
			break;

		case 2:
			for (i = 0; i < 3; i++) {
				for (j = 0; j < 4; j ++) {
					if (j == 0) {
						printf("Enter the coefficient of X for equation %d:",i+1);
						scanf("%f",&a[i][j]);
					}
					else if (j == 1){
						printf("Enter the coefficient Y for equation %d: ",i+1);
						scanf("%f",&a[i][j]);
					}
					else if (j == 2){
						printf("Enter the coefficient of Z for equation %d: ",i+1);
						scanf("%f",&a[i][j]);
					}
					else{
						printf("Enter the constant for equation %d: ",i+1);
						scanf("%f",&a[i][j]);
					}
				}
			}

		printf("\n");
		printf("The augmented matrix [A:B] is:\n");
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 4; j++) {
				if (j == 3) {
					printf(" : ");
				}
				printf("%-7.2f", fabs(a[i][j]) < epsilon ? 0.00 : a[i][j]);
			}
			printf("\n");
		}
		D = a[0][0];
		for (j = 0; j < 4; j++) {
			a[0][j] /= D;
		}
		printf("\n");
		printf("Applying R1 --> R1/%.2f\n", D);
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 4; j++) {
				if (j == 3) {
					printf(" : ");
				}
				printf("%-7.2f", fabs(a[i][j]) < epsilon ? 0.00 : a[i][j]);
			}
			printf("\n");
		}
		D = a[1][0];
		E = a[2][0];
		for (j = 0; j < 4; j++) {
			a[1][j] -= (D * a[0][j]);
			a[2][j] -= (E * a[0][j]);
		}
		printf("\n");
		printf("Applying R2 --> R2 - %.2fR1 and R3 --> R3 - %.2fR1\n", D, E);
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 4; j++) {
				if (j == 3) {
					printf(" : ");
				}
				printf("%-7.2f", fabs(a[i][j]) < epsilon ? 0.00 : a[i][j]);
			}
			printf("\n");
		}
		D = a[1][1];
		for (j = 0; j < 4; j++) {
			a[1][j] /= D;
		}
		printf("\n");
		printf("Applying R2 --> R2/%.2f\n", D);
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 4; j++) {
				if (j == 3) {
					printf(" : ");
				}
				printf("%-7.2f", fabs(a[i][j]) < epsilon ? 0.00 : a[i][j]);
			}
			printf("\n");
		}
		D = a[0][1];
		E = a[2][1];
		for (j = 0; j < 4; j++) {
			a[0][j] -= (D * a[1][j]);
			a[2][j] -= (E * a[1][j]);
		}
		printf("\n");
		printf("Applying R1 --> R1 - %.2fR2 and R3 --> R3 - %.2fR2\n", D, E);
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 4; j++) {
				if (j == 3) {
					printf(" : ");
				}
				printf("%-7.2f", fabs(a[i][j]) < epsilon ? 0.00 : a[i][j]);
			}
			printf("\n");
		}
		D = a[2][2];
		for (j = 0; j < 4; j++) {
			a[2][j] /= D;
		}
		printf("\n");
		printf("Applying R3 --> R3/%.2f\n", D);
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 4; j++) {
				if (j == 3) {
					printf(" : ");
				}
				printf("%-7.2f", fabs(a[i][j]) < epsilon ? 0.00 : a[i][j]);
			}
			printf("\n");
		}
		D = a[0][2];
		E = a[1][2];
		for (j = 0; j < 4; j++) {
			a[0][j] -= (D * a[2][j]);
			a[1][j] -= (E * a[2][j]);
		}
		printf("\n");
		printf("Applying R1 --> R1 - %.2fR3 and R2 --> R2 - %.2fR3\n", D, E);
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 4; j++) {
				if (j == 3) {
					printf(" : ");
				}
				printf("%-7.2f",fabs(a[i][j]) < epsilon ? 0.00 : a[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		printf("The value of X is %.2f\n", a[0][3]);
		printf("The value of Y is %.2f\n", a[1][3]);
		printf("The value of Z is %.2f\n", a[2][3]);

		default:
			break;
	}
	return 0;
}
