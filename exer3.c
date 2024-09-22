#include <stdio.h>


void bankMenu() {
    printf("============================== Welcome to MAZE Bank MENU ============================== \n");
    printf("[1] - Check Balance\n");
    printf("[2] - Deposit\n");
    printf("[3] - Withdraw\n");
    printf("[4] - Change PIN\n");
    printf("[5] - Set Account Name\n");
    printf("[6] - End Transaction\n");
}

int checkPIN() {
    int pin = 1234;
    int inputPin;
    while (1) {
        printf("Enter your PIN: ");
        scanf("%d", &inputPin);
        if (pin == inputPin) {
            printf("PIN is correct\n");
            break;
        } else {
            printf("PIN is incorrect\n");
        }
    }
}

void checkBalance(char *accountName, float balance) {
    if(checkPIN()) {
        printf("Account name:  %s\n", accountName);
        printf("Your current balance is: $%f\n", balance);
    }
    
}

float userDeposit(float amountDeposit, float balance) {
    float newBalance = balance + amountDeposit;
    return newBalance;
}

float userWithdraw(float amountWithraw, float balance) {
    float newBalance = balance - amountWithraw;
    return newBalance;
}

int main () {

    char accountName[] = "savings";
    float balance = 0;
    int userPIN;

    while (1) {
        printf("============================== Welcome to MAZE Bank ============================== \n");
        printf("Please enter your PIN: ");
        scanf("%d", &userPIN);
            if (userPIN == 1234) {
                
                while (1) {
                    bankMenu();
                    int choice;
                    printf("Please enter your choice: ");
                    scanf("%d", &choice);

                    switch (choice) {
                        case 1:
                            checkBalance(accountName, balance);
                            break;
                        case 2:
                            float amountDeposit;
                            printf("Enter Amount to Deposit: ");
                            scanf("%f", &amountDeposit);
                            balance = userDeposit(amountDeposit, balance);
                            printf("Your new balance is: $%f\n", balance);
                            break;
                        case 3:
                            float amountWithdraw;
                            printf("Enter Amount to Withdraw: ");
                            scanf("%f", &amountWithdraw);
                            if (amountWithdraw > balance) {
                                printf("Insufficient Funds\n");
                            }

                            else {
                                balance = userWithdraw(amountWithdraw, balance);
                                printf("Your new balance is: $%f\n", balance);
                            }
                            break;
                    }    
                }
                
            }

            else {
                printf("Invalid PIN! Try Again\n");
                continue;
            }
    }
    
    
    return 0;
}
