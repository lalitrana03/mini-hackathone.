#include <stdio.h>
#include <string.h>

int main() {
    float budget, amount, totalSpending = 0;
    float categoryTotal[4] = {0};
    int n, choice;
    
    char categories[4][20] = {"Food", "Travel", "Books", "Entertainment"};

    printf("Enter monthly budget: ");
    scanf("%f", &budget);

    printf("Enter number of expenses: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nExpense %d\n", i + 1);
        printf("1. Food\n2. Travel\n3. Books\n4. Entertainment\n");
        printf("Choose category (1-4): ");
        scanf("%d", &choice);

        printf("Enter amount: ");
        scanf("%f", &amount);

        if (choice >= 1 && choice <= 4) {
            categoryTotal[choice - 1] += amount;
            totalSpending += amount;
        } else {
            printf("Invalid category!\n");
        }
    }

    float remainingBudget = budget - totalSpending;

    int maxIndex = 0;
    for (int i = 1; i < 4; i++) {
        if (categoryTotal[i] > categoryTotal[maxIndex]) {
            maxIndex = i;
        }
    }

    printf("\n========== EXPENSE SUMMARY ==========\n");
    printf("Monthly Budget   : %.2f\n", budget);
    printf("Total Spending   : %.2f\n", totalSpending);
    printf("Remaining Budget : %.2f\n", remainingBudget);

    printf("\nCategory-wise Totals:\n");
    for (int i = 0; i < 4; i++) {
        printf("%s : %.2f\n", categories[i], categoryTotal[i]);
    }

    printf("\nHighest Expenditure Category: %s (%.2f)\n",
           categories[maxIndex], categoryTotal[maxIndex]);

    if (totalSpending > budget) {
        printf("\nWARNING: Budget Exceeded!\n");
    } else {
        printf("\nBudget is within limit.\n");
    }

    return 0;
}