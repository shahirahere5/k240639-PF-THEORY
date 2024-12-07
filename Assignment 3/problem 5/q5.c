#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct petDetails {
    char** speciesSupply; 
    char* speciesName;   
    int numSupplies;     
};

struct petDetails* pets = NULL; 
int numSpc = 0;                


void init_inventory();
void add_supplies();
void update_supplies();
void remove_species();
void display_inventory();

int main() {
    int choice;

    while (1) {
        printf("\nPet Shop Inventory System\n");
        printf("1. Initialize Inventory\n"
               "2. Add Supplies\n"
               "3. Update Supplies\n"
               "4. Remove Species\n"
               "5. Display Inventory\n"
               "6. Exit\n"
               "Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                init_inventory();
                break;
            case 2:
                add_supplies();
                break;
            case 3:
                update_supplies();
                break;
            case 4:
                remove_species();
                break;
            case 5:
                display_inventory();
                break;
            case 6:
                printf("\t\t\t\tSee Y'all\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

void init_inventory() {
    printf("Enter number of species: ");
    scanf("%d", &numSpc);


    pets = malloc(numSpc * sizeof(struct petDetails));
    for (int i = 0; i < numSpc; i++) {
        pets[i].speciesName = malloc(50 * sizeof(char)); 
        pets[i].speciesSupply = NULL;                   
        pets[i].numSupplies = 0;                        
        printf("Enter name of species %d: ", i + 1);
        scanf("%s", pets[i].speciesName);
    }
    printf("Inventory initialized with %d species.\n", numSpc);
}

void add_supplies() {
    int numSup;
    for (int i = 0; i < numSpc; i++) {
        printf("Enter number of supplies for species %s: ", pets[i].speciesName);
        scanf("%d", &numSup);

        pets[i].speciesSupply = malloc(numSup * sizeof(char*)); 
        pets[i].numSupplies = numSup;                          

        printf("Enter supplies:\n");
        for (int j = 0; j < numSup; j++) {
            pets[i].speciesSupply[j] = malloc(50 * sizeof(char)); 
            scanf("%s", pets[i].speciesSupply[j]);
        }
    }
    printf("Supplies added.\n");
}

void update_supplies() {
    int speciesIndex, supplyIndex;
    char newSupply[50];

    printf("Enter species index (1 to %d): ", numSpc);
    scanf("%d", &speciesIndex);
    speciesIndex--;

    if (speciesIndex < 0 || speciesIndex >= numSpc) {
        printf("Invalid species index.\n");
        return;
    }

    printf("Enter supply index (1 to %d): ", pets[speciesIndex].numSupplies);
    scanf("%d", &supplyIndex);
    supplyIndex--;

    if (supplyIndex < 0 || supplyIndex >= pets[speciesIndex].numSupplies) {
        printf("Invalid supply index.\n");
        return;
    }

    printf("Enter new supply name: ");
    scanf("%s", newSupply);

    strcpy(pets[speciesIndex].speciesSupply[supplyIndex], newSupply);
    printf("Supply updated.\n");
}

void remove_species() {
    int speciesIndex;
    printf("Enter species index to remove (1 to %d): ", numSpc);
    scanf("%d", &speciesIndex);
    speciesIndex--;

    if (speciesIndex < 0 || speciesIndex >= numSpc) {
        printf("Invalid species index.\n");
        return;
    }

    for (int i = 0; i < pets[speciesIndex].numSupplies; i++) {
        free(pets[speciesIndex].speciesSupply[i]);
    }
    free(pets[speciesIndex].speciesSupply);
    free(pets[speciesIndex].speciesName);

    for (int i = speciesIndex; i < numSpc - 1; i++) {
        pets[i] = pets[i + 1];
    }

    numSpc--;
    pets = realloc(pets, numSpc * sizeof(struct petDetails));
    printf("Species removed.\n");
}

void display_inventory() {
    for (int i = 0; i < numSpc; i++) {
        printf("\nSpecies: %s\n", pets[i].speciesName);
        printf("Supplies: ");
        for (int j = 0; j < pets[i].numSupplies; j++) {
            printf("%s\t", pets[i].speciesSupply[j]);
        }
        printf("\n");
    }
}
