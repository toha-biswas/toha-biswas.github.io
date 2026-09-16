#include <stdio.h>

struct Expense {
    int id;
    char name[50];
    float amount;
};

int main() {
    struct Expense expenses[100];
    int count = 0;
    int choice;
    float total;

    do {
        printf("\n===== PERSONAL EXPENSE TRACKER =====\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Calculate Total\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                if (count < 100) {
                    expenses[count].id = count + 1;

                    printf("Enter expense name: ");
                    scanf("%49s", expenses[count].name);

                    printf("Enter amount: ");
                    scanf("%f", &expenses[count].amount);

                    count++;

                    printf("Expense added successfully!\n");
                } else {
                    printf("Expense limit reached.\n");
                }
                break;

            case 2:
                if (count == 0) {
                    printf("No expenses available.\n");
                } else {
                    printf("\nID\tExpense\t\tAmount\n");

                    for (int i = 0; i < count; i++) {
                        printf("%d\t%s\t\t%.2f\n",
                               expenses[i].id,
                               expenses[i].name,
                               expenses[i].amount);
                    }
                }
                break;

            case 3:
                total = 0;

                for (int i = 0; i < count; i++) {
                    total = total + expenses[i].amount;
                }

                printf("Total spending: %.2f\n", total);
                break;

            case 4:
                printf("Thank you for using the tracker!\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 4);

    return 0;
}