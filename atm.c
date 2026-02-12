#include <stdio.h>
// Predefined account details (constants)
#define ACCOUNT_NUMBER "123456"   // Correct account number
#define PIN "123456"                // Correct PIN
#define INITIAL_BALANCE 1000.0    // Starting balance
int main() {
    // Variables to store user input
    char entered_account_number[20];
    char entered_pin[10];
    // Balance and withdrawal amount
    double balance = INITIAL_BALANCE;
    double withdrawal_amount;
    // Welcome message
    printf("Welcome to the ATM!\n");
    // Ask user for account number
    printf("Enter your account number: ");
    scanf("%s", entered_account_number);
    // Ask user for PIN
    printf("Enter your PIN: ");
    scanf("%s", entered_pin);
    // Authentication flag (1 = true, 0 = false)
    int authenticated = 1;
    // Compare entered account number and PIN with stored values
    for (int i = 0; i < 6; ++i) {
        if (entered_account_number[i] != ACCOUNT_NUMBER[i] || entered_pin[i] != PIN[i]) {
            authenticated = 0;
			// If any character doesn't match, fail authentication
            break;
        }
    }
    // If authentication is successful
    if (authenticated){
        // Show current balance
        printf("Your current account balance: $%.2f\n", balance);
        // Ask for withdrawal amount
        printf("Enter the amount to withdraw: $");
        scanf("%lf", &withdrawal_amount);
        // Check if user has enough balance
        if (withdrawal_amount > balance) {
            printf("Insufficient funds. Withdrawal failed.\n");
        } 
		else{
            // Deduct withdrawal amount
            balance -= withdrawal_amount;
            printf("Withdrawal successful. Remaining balance: $%.2f\n", balance);
        }
    } 
    // If authentication fails
    else{
        printf("Authentication failed. Invalid account number or PIN.\n");
    }
    return 0;
	// End of program
}
