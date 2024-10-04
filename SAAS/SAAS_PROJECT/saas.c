#include <stdio.h>
#include <string.h> 
#include <stdlib.h>  
#include <time.h>  

#define MAX 100  // Maximum number of reservations

// Struct for holding reservation information
struct Reservation {
    char names[MAX][50];
    char phones[MAX][15];
    int ages[MAX];
    int ids[MAX];
    char status[MAX][20];
    int num;  // Keeps track of the current number of reservations
};

struct Reservation res;  // Global reservation instance

void initializeReservations() {
    res.num = 0;  // Reset reservation count to zero
    const char* defaultNames[] = {"Rayan", "imane", "rachid","latifa", "mohamed", "khalid", "salma","kaoutar","youssef","fatima"};
    const char* defaultPhones[] = {"123456789", "65976570", "26546080°", "456123789", "045678876", "879675302", "2345679006", "6645819221", "876443219"};
    const int defaultAges[] = {22, 21, 43, 44, 31, 10, 36, 56, 47, 78};
    const char* defaultStatus[] = {"validated", "postponed", "cancelled", "pending", "validated", "postponed", "processed", "canceled", "pending", "validated"};

    // Adding 3 default reservations
    for (int i = 0; i < 10; i++) {
        strcpy(res.names[res.num], defaultNames[i]);
        strcpy(res.phones[res.num], defaultPhones[i]);
        res.ages[res.num] = defaultAges[i];
        strcpy(res.status[res.num], defaultStatus[i]);
        res.ids[res.num] = rand() % 1000;  // Generate a random ID between 0 and 999
        res.num++;  // Increase the reservation count
    }

    printf("Initialized 10 default reservations:\n");
    for (int i = 0; i < 10; i++) {
        printf("ID: %d, Name: %s, Phone: %s, Age: %d, Status: %s\n", 
            res.ids[i], res.names[i], res.phones[i], res.ages[i], res.status[i]);
    }
}

// Function to add a reservation
void addReservation() {
    if (res.num >= MAX) {
        printf("Reservations are out of order!\n");
        return;
    }

    printf("Enter name: ");
    getchar();  
    scanf("%[^\n]s", res.names[res.num]); 
    printf("Enter phone: ");
    scanf("%s", res.phones[res.num]);
    printf("Enter age: ");
    scanf("%d", &res.ages[res.num]);
    printf("Enter status (validated, postponed, canceled, processed): ");
    scanf("%s", res.status[res.num]);

    res.ids[res.num] = rand() % 1000;  // generate random ID
    res.num++;  // increment the reservation count
    printf("Reservation added successfully, ID: %d\n", res.ids[res.num - 1]);
}

// Function to display all reservations
void displayReservations() {
    if (res.num == 0) {
        printf("0 reservations to display.\n");
        return;
    }
    for (int i = 0; i < res.num; i++) {
        printf("Reservation ID: %d\n", res.ids[i]);
        printf("Name: %s\n", res.names[i]);
        printf("Phone: %s\n", res.phones[i]);
        printf("Age: %d\n", res.ages[i]);
        printf("Status: %s\n", res.status[i]);
        printf("\n");
    }
}

// Function to modify a reservation
void modifyReservation() {
    int reference;
    printf("Enter the reservation ID to modify: ");
    scanf("%d", &reference);

    int found = 0;
    for (int i = 0; i < res.num; i++) {
        if (res.ids[i] == reference) {
            found = 1;
            printf("Current Name: %s\n", res.names[i]);
            printf("Enter new name: ");
            scanf("%s", res.names[i]);

            printf("Current Phone: %s\n", res.phones[i]);
            printf("Enter new phone: ");
            scanf("%s", res.phones[i]);

            printf("Current Age: %d\n", res.ages[i]);
            printf("Enter new age: ");
            scanf("%d", &res.ages[i]);

            printf("Current Status: %s\n", res.status[i]);
            printf("Enter new status: ");
            scanf("%s", res.status[i]);

            printf("Reservation modified successfully!\n");
            return;
        }
    }

    if (!found) {
        printf("No reservation found with that ID.\n");
    }
}

// Function to delete a reservation
void deleteReservation() {
    int reference;
    printf("Enter reservation ID to delete: ");
    scanf("%d", &reference);

    int found = 0;
    for (int i = 0; i < res.num; i++) {
        if (res.ids[i] == reference) {
            found = 1;
            for (int j = i; j < res.num - 1; j++) {
                strcpy(res.names[j], res.names[j + 1]);
                strcpy(res.phones[j], res.phones[j + 1]);
                res.ages[j] = res.ages[j + 1];
                strcpy(res.status[j], res.status[j + 1]);
                res.ids[j] = res.ids[j + 1];
            }

            res.num--;
            printf("Reservation deleted successfully!\n");
            return;
        }
    }

    if (!found) {
        printf("No reservation found with that ID.\n");
    }
}

// Function to search reservation by name
void searchReservationByName() {
    char searchName[50];
    printf("Enter the name to search: ");
    scanf("%s", searchName);

    for (int i = 0; i < res.num; i++) {
        if (strcmp(res.names[i], searchName) == 0) {
            printf("Reservation found:\n");
            printf("ID: %d\n", res.ids[i]);
            printf("Name: %s\n", res.names[i]);
            printf("Phone: %s\n", res.phones[i]);
            printf("Age: %d\n", res.ages[i]);
            printf("Status: %s\n", res.status[i]);
            return;
        }
    }
    printf("No reservation found with that name.\n");
}

// Function to search reservation by ID
void searchReservationByReference() {
    int reference;
    printf("Enter the reservation ID: ");
    scanf("%d", &reference);

    for (int i = 0; i < res.num; i++) {
        if (res.ids[i] == reference) {
            printf("Reservation found:\n");
            printf("ID: %d\n", res.ids[i]);
            printf("Name: %s\n", res.names[i]);
            printf("Phone: %s\n", res.phones[i]);
            printf("Age: %d\n", res.ages[i]);
            printf("Status: %s\n", res.status[i]);
            return;
        }
    }

    printf("No reservation found with that ID.\n");
}

// Function to calculate average age of reservations
void calculateAverageAge() {
    if (res.num == 0) {
        printf("No reservations to calculate average age.\n");
        return;
    }

    int totalAge = 0;
    for (int i = 0; i < res.num; i++) {
        totalAge += res.ages[i];
    }

    double averageAge = (double) totalAge / res.num;
    printf("The average age is %.2f years.\n", averageAge);
}

// Function to count people by age group
void countByAgeGroup() {
    int minors = 0, adults = 0, super_adults = 0;

    for (int i = 0; i < res.num; i++) {
        if (res.ages[i] < 18) {
            minors++;
        } else if (res.ages[i] <= 40) {
            adults++;
        } else {
            super_adults++;
        }
    }

    printf("Patients under 18: %d\n", minors);
    printf("Patients aged 18 to 40: %d\n", adults);
    printf("Patients over 40: %d\n", super_adults);
}

// Function to count reservations by status
void countByStatus() {
    int validated = 0, postponed = 0, canceled = 0, processed = 0;

    for (int i = 0; i < res.num; i++) {
        if (strcmp(res.status[i], "validated") == 0) {
            validated++;
        } else if (strcmp(res.status[i], "postponed") == 0) {
            postponed++;
        } else if (strcmp(res.status[i], "canceled") == 0) {
            canceled++;
        } else if (strcmp(res.status[i], "processed") == 0) {
            processed++;
        }
    }

    printf("Validated: %d\n", validated);
    printf("Postponed: %d\n", postponed);
    printf("Canceled: %d\n", canceled);
    printf("Processed: %d\n", processed);
}

// Main function
int main() {
    srand(time(NULL)); // Seed the random number generator

    int choice, sortBy;
    do {
        printf("\nReservation Management System\n");
        printf("1. Add Reservation\n");
        printf("2. Display Reservations\n");
        printf("3. Modify Reservation\n");
        printf("4. Delete Reservation\n");
        printf("5. Search Reservation by Name\n");
        printf("6. Search Reservation by ID\n"); //unique reference number
        printf("7. Calculate Average Age\n");
        printf("8. Count People by Age Group\n");
        printf("9. Count Reservations by Status\n");
        printf("10. Initialize default reservations\n"); // New option for initialization
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addReservation();
                break;
            case 2:
                displayReservations();
                break;
            case 3:
                modifyReservation();
                break;
            case 4:
                deleteReservation();
                break;
            case 5:
                searchReservationByName();
                break;
            case 6:
                searchReservationByReference();
                break;
            case 7:
                calculateAverageAge();
                break;
            case 8:
                countByAgeGroup();
                break;
            case 9:
                countByStatus();
                break;
            case 10:
                initializeReservations(); // Call to initialize default reservations
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
