#include<stdio.h>
#include<stdbool.h>
#include<string.h>

int main() {
	char *a[3][3];
	int turn = 0, i, j, r, c,count=0;
	bool running = true;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			a[i][j] = "|___|";
		}
	}

	// Print board
	printf("Start: \n");
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			printf("%-5s", a[i][j]);
		}
		printf("\n\n");
	}
T:
		printf("Press 0 for X's turn and 1 for O's turn: ");
		scanf("%d", &turn);

	if (turn != 0 && turn != 1) {
		goto T;
	}

	while (running) {
		if ((strcmp(a[0][0], "| X |") == 0 && strcmp(a[0][1], "| X |") == 0 && strcmp(a[0][2], "| X |") == 0)
			|| (strcmp(a[1][0], "| X |") == 0 && strcmp(a[1][1], "| X |") == 0 && strcmp(a[1][2], "| X |") == 0)
			|| (strcmp(a[2][0], "| X |") == 0 && strcmp(a[2][1], "| X |") == 0 && strcmp(a[2][2], "| X |") == 0)
			|| (strcmp(a[0][0], "| X |") == 0 && strcmp(a[1][0], "| X |") == 0 && strcmp(a[2][0], "| X |") == 0)
			|| (strcmp(a[0][1], "| X |") == 0 && strcmp(a[1][1], "| X |") == 0 && strcmp(a[2][1], "| X |") == 0)
			|| (strcmp(a[0][2], "| X |") == 0 && strcmp(a[1][2], "| X |") == 0 && strcmp(a[2][2], "| X |") == 0)
			|| (strcmp(a[0][0], "| X |") == 0 && strcmp(a[1][1], "| X |") == 0 && strcmp(a[2][2], "| X |") == 0)
			|| (strcmp(a[0][2], "| X |") == 0 && strcmp(a[1][1], "| X |") == 0 && strcmp(a[2][0], "| X |") == 0)) {
			printf("The winner is X!\n");
			running = false;
		}
		else if ((strcmp(a[0][0], "| O |") == 0 && strcmp(a[0][1], "| O |") == 0 && strcmp(a[0][2], "| O |") == 0)
			|| (strcmp(a[1][0], "| O |") == 0 && strcmp(a[1][1], "| O |") == 0 && strcmp(a[1][2], "| O |") == 0)
			|| (strcmp(a[2][0], "| O |") == 0 && strcmp(a[2][1], "| O |") == 0 && strcmp(a[2][2], "| O |") == 0)
			|| (strcmp(a[0][0], "| O |") == 0 && strcmp(a[1][0], "| O |") == 0 && strcmp(a[2][0], "| O |") == 0)
			|| (strcmp(a[0][1], "| O |") == 0 && strcmp(a[1][1], "| O |") == 0 && strcmp(a[2][1], "| O |") == 0)
			|| (strcmp(a[0][2], "| O |") == 0 && strcmp(a[1][2], "| O |") == 0 && strcmp(a[2][2], "| O |") == 0)
			|| (strcmp(a[0][0], "| O |") == 0 && strcmp(a[1][1], "| O |") == 0 && strcmp(a[2][2], "| O |") == 0)
			|| (strcmp(a[0][2], "| O |") == 0 && strcmp(a[1][1], "| O |") == 0 && strcmp(a[2][0], "| O |") == 0)) {
			printf("The winner is O!\n");
			running = false;
		}
		// Check for draw
		else if (count == 9) {
			printf("It's a draw!\n");
			running = false;
		}
		else if (turn % 2 == 0) {
			printf("It's X's turn.\n");
		X:
			printf("Enter the row and column where you want to put X: ");
			scanf("%d%d", &r, &c);
			if (r < 1 || r > 3 || c < 1 || c > 3) {
				printf("Invalid move! Enter a row and column between 1 and 3.\n");
				goto X;
			}
			if (strcmp(a[r-1][c-1], "|___|") == 0) {
				a[r-1][c-1] = "| X |";
				turn++;
				count++;
				// Print the board after move
				for (i = 0; i < 3; i++) {
					for (j = 0; j < 3; j++) {
						printf("%-5s", a[i][j]);
					}
					printf("\n\n");
				}
			} else {
				printf("Cell is already occupied! Try again.\n");
				goto X;
			}
		}
		else {
			printf("It's O's turn.\n");
		Y:
			printf("Enter the row and column where you want to put O: ");
			scanf("%d%d", &r, &c);
			if (r < 1 || r > 3 || c < 1 || c > 3) {
				printf("Invalid move! Enter a row and column between 1 and 3.\n");
				goto Y;
			}
			if (strcmp(a[r-1][c-1], "|___|") == 0) {
				a[r-1][c-1] = "| O |";
				turn++;
				count ++;
				// Print the board after move
				for (i = 0; i < 3; i++) {
					for (j = 0; j < 3; j++) {
						printf("%-5s", a[i][j]);
					}
					printf("\n\n");
				}
			} else {
				printf("Cell is already occupied! Try again.\n");
				goto Y;
			}
		}

	}
	return 0;
}
