#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_USERS 3
#define NUM_CATEGORIES 3
#define NUM_DEVICES 2
#define NUM_CONTENT_ITEMS 3

typedef struct {
    char title[50];
    double rating;
    int runtime;
    char format[20];
} ContentMetadata;

typedef struct {
    char resolution[20];
    int playbackPosition; 
    double bandwidthUsage; 
} DevicePreference;

void initializeEngagementMatrix(double**, int, int);
void initializeContentMetadata(ContentMetadata**, int, int);
void initializeDevicePreferences(DevicePreference**, int, int);
void updateEngagement(double**, int, int, double);
void updateContentMetadata(ContentMetadata**, int, int);
void updateDevicePreferences(DevicePreference**, int, int);
void printEngagementMatrix(double**, int, int);
void printContentMetadata(ContentMetadata**, int, int);
void printDevicePreferences(DevicePreference**, int, int);

int main() {
    double **engagementMatrix = malloc(sizeof(double*)*NUM_USERS);
    for (int i = 0; i < NUM_USERS; i++) {
        engagementMatrix[i] = malloc(NUM_CATEGORIES * sizeof(double));
    }
    initializeEngagementMatrix(engagementMatrix, NUM_USERS, NUM_CATEGORIES);

    ContentMetadata **contentMetadataMatrix = malloc(NUM_CATEGORIES * sizeof(ContentMetadata *));
    for (int i = 0; i < NUM_CATEGORIES; i++) {
        contentMetadataMatrix[i] = malloc(NUM_CONTENT_ITEMS * sizeof(ContentMetadata));
    }
    initializeContentMetadata(contentMetadataMatrix, NUM_CATEGORIES, NUM_CONTENT_ITEMS);

    DevicePreference **deviceMatrix = malloc(NUM_USERS * sizeof(DevicePreference *));
    for (int i = 0; i < NUM_USERS; i++) {
        deviceMatrix[i] = malloc(NUM_DEVICES * sizeof(DevicePreference));
    }
    initializeDevicePreferences(deviceMatrix, NUM_USERS, NUM_DEVICES);

    int choice;
    while (1) {
        printf("1. Update Engagement Score\n"
        "2. Update Content Metadata\n"
        "3. Update Device Preferences\n"
        "4. Print Engagement Matrix\n"
        "5. Print Content Metadata\n"
        "6. Print Device Preferences\n"
        "7. Exit\n"
        "Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 7) {
            printf("Exiting program...\n");
            break;
        }

        int userIndex, categoryIndex, deviceIndex, itemIndex;
        double newScore;

        switch (choice) {
            case 1:
                printf("Enter User Index (0-%d): ", NUM_USERS - 1);
                scanf("%d", &userIndex);
                printf("Enter Category Index (0-%d): ", NUM_CATEGORIES - 1);
                scanf("%d", &categoryIndex);
                printf("Enter New Engagement Score: ");
                scanf("%lf", &newScore);
                updateEngagement(engagementMatrix, userIndex, categoryIndex, newScore);
                break;

            case 2:
                printf("Enter Category Index (0-%d): ", NUM_CATEGORIES - 1);
                scanf("%d", &categoryIndex);
                printf("Enter Content Item Index (0-%d): ", NUM_CONTENT_ITEMS - 1);
                scanf("%d", &itemIndex);
                updateContentMetadata(contentMetadataMatrix, categoryIndex, itemIndex);
                break;

            case 3:
                printf("Enter User Index (0-%d): ", NUM_USERS - 1);
                scanf("%d", &userIndex);
                printf("Enter Device Index (0-%d): ", NUM_DEVICES - 1);
                scanf("%d", &deviceIndex);
                updateDevicePreferences(deviceMatrix, userIndex, deviceIndex);
                break;

            case 4:
                printEngagementMatrix(engagementMatrix, NUM_USERS, NUM_CATEGORIES);
                break;

            case 5:
                printContentMetadata(contentMetadataMatrix, NUM_CATEGORIES, NUM_CONTENT_ITEMS);
                break;

            case 6:
                printDevicePreferences(deviceMatrix, NUM_USERS, NUM_DEVICES);
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    // Free memory
    for (int i = 0; i < NUM_USERS; i++) {
        free(engagementMatrix[i]);
        free(deviceMatrix[i]);
    }
    free(engagementMatrix);
    free(deviceMatrix);

    for (int i = 0; i < NUM_CATEGORIES; i++) {
        free(contentMetadataMatrix[i]);
    }
    free(contentMetadataMatrix);

    return 0;
}

void initializeEngagementMatrix(double **engagementMatrix, int numUsers, int numCategories) {
    for (int i = 0; i < numUsers; i++) {
        for (int j = 0; j < numCategories; j++) {
            engagementMatrix[i][j] = 0.0;
        }
    }
}

void initializeContentMetadata(ContentMetadata **contentMatrix, 
int numCategories, int numItems){
    for (int i = 0; i < numCategories; i++) {
        for (int j = 0; j < numItems; j++) {
            snprintf(contentMatrix[i][j].title, 50, "Content not added yet");
            contentMatrix[i][j].rating = 0.0;
            contentMatrix[i][j].runtime = 0;
            strcpy(contentMatrix[i][j].format, "N/A");
        }
    }
}

void initializeDevicePreferences(DevicePreference **deviceMatrix, 
int numUsers, int numDevices){
    for (int i = 0; i < numUsers; i++) {
        for (int j = 0; j < numDevices; j++) {
            snprintf(deviceMatrix[i][j].resolution, 20, "N/A");
            deviceMatrix[i][j].playbackPosition = 0;
            deviceMatrix[i][j].bandwidthUsage = 0.0;
        }
    }
}

void updateEngagement(double **engagementMatrix, 
int userIndex, int categoryIndex, double newScore){
    engagementMatrix[userIndex][categoryIndex] = newScore;
    printf("Engagement score updated.\n");
}

void updateContentMetadata(ContentMetadata **contentMatrix, int categoryIndex, int itemIndex) {
    printf("Enter new title: ");
    getchar();
    fgets(contentMatrix[categoryIndex][itemIndex].title,
    sizeof(contentMatrix[categoryIndex][itemIndex].title), stdin);
    contentMatrix[categoryIndex][itemIndex].title
    [strcspn(contentMatrix[categoryIndex][itemIndex].title, 
    "\n")] = '\0';
    printf("Enter new rating: ");
    scanf("%lf", &contentMatrix[categoryIndex][itemIndex].rating);
    printf("Enter new runtime (minutes): ");
    scanf("%d", &contentMatrix[categoryIndex][itemIndex].runtime);
    printf("Enter new format: ");
    scanf("%s", contentMatrix[categoryIndex][itemIndex].format);
    printf("Content metadata updated.\n");
}

void updateDevicePreferences(DevicePreference **deviceMatrix, 
int userIndex, int deviceIndex){
    printf("Enter new resolution: ");
    scanf("%s", deviceMatrix[userIndex][deviceIndex].resolution);
    printf("Enter new playback position (seconds): ");
    scanf("%d", &deviceMatrix[userIndex][deviceIndex].playbackPosition);
    printf("Enter new bandwidth usage (MB): ");
    scanf("%lf", &deviceMatrix[userIndex][deviceIndex].bandwidthUsage);
    printf("Device preferences updated.\n");
}

void printEngagementMatrix(double **engagementMatrix, 
int numUsers, int numCategories){
    for (int i = 0; i < numUsers; i++) {
        for (int j = 0; j < numCategories; j++) {
            printf("%.2f ", engagementMatrix[i][j]);
        }
        printf("\n");
    }
}

void printContentMetadata(ContentMetadata **contentMatrix, 
int numCategories, int numItems){
    for (int i = 0; i < numCategories; i++) {
        printf("Category %d:\n", i + 1);
        for (int j = 0; j < numItems; j++) {
            printf("Title: %s, Rating: %.1f, Runtime: %d min, Format: %s\n",
                   contentMatrix[i][j].title, contentMatrix[i][j].rating,
                   contentMatrix[i][j].runtime, contentMatrix[i][j].format);
        }
    }
}

void printDevicePreferences(DevicePreference **deviceMatrix, 
int numUsers, int numDevices){
    for (int i = 0; i < numUsers; i++) {
        printf("User %d:\n", i + 1);
        for (int j = 0; j < numDevices; j++) {
            printf("  Device %d: Resolution: %s, Playback Position: %d sec, Bandwidth Usage: %.2f MB\n",
                   j + 1, deviceMatrix[i][j].resolution, deviceMatrix[i][j].playbackPosition,
                   deviceMatrix[i][j].bandwidthUsage);
        }
    }
}
