#include <stdio.h>

struct Product {
    int id;
    char name[50];
    int quantity;
    float price;
};

int main() {
    struct Product products[100];
    int count = 0;
    int choice;
    int searchId;
    int found;

    do {
        printf("\n====================================\n");
        printf("       INVENTORY MANAGEMENT SYSTEM\n");
        printf("====================================\n");

        printf("1. Add Product\n");
        printf("2. View Products\n");
        printf("3. Search Product\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                if (count >= 100) {
                    printf("Inventory is full!\n");
                    break;
                }

                printf("\n--- Add New Product ---\n");

                printf("Enter product ID: ");
                scanf("%d", &products[count].id);

                printf("Enter product name: ");
                scanf("%49s", products[count].name);

                printf("Enter quantity: ");
                scanf("%d", &products[count].quantity);

                printf("Enter price: ");
                scanf("%f", &products[count].price);

                count++;

                printf("Product added successfully!\n");
                break;

            case 2:
                printf("\n--- Product List ---\n");

                if (count == 0) {
                    printf("No products available.\n");
                } else {
                    for (int i = 0; i < count; i++) {
                        printf("\nProduct Number: %d\n", i + 1);
                        printf("Product ID: %d\n", products[i].id);
                        printf("Name: %s\n", products[i].name);
                        printf("Quantity: %d\n", products[i].quantity);
                        printf("Price: %.2f\n", products[i].price);
                    }
                }
                break;

            case 3:
                printf("\nEnter product ID to search: ");
                scanf("%d", &searchId);

                found = 0;

                for (int i = 0; i < count; i++) {
                    if (products[i].id == searchId) {
                        printf("\nProduct found!\n");
                        printf("ID: %d\n", products[i].id);
                        printf("Name: %s\n", products[i].name);
                        printf("Quantity: %d\n", products[i].quantity);
                        printf("Price: %.2f\n", products[i].price);

                        found = 1;
                        break;
                    }
                }

                if (found == 0) {
                    printf("Product not found.\n");
                }
                break;

            case 4:
                printf("\nThank you for using the system!\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}