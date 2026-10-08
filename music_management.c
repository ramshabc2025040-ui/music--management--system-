#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a song
struct Song {
    int id;
    char title[100];
    char artist[100];
    char album[100];
    int year;
    struct Song *next;
};

// Head pointer
struct Song *head = NULL;

// Function to add a song
void addSong() {
    struct Song *newSong;
    newSong = (struct Song *)malloc(sizeof(struct Song));

    if (newSong == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("\nEnter Song ID: ");
    scanf("%d", &newSong->id);

    printf("Enter Song Title: ");
    scanf(" %[^\n]", newSong->title);

    printf("Enter Artist Name: ");
    scanf(" %[^\n]", newSong->artist);

    printf("Enter Album Name: ");
    scanf(" %[^\n]", newSong->album);

    printf("Enter Release Year: ");
    scanf("%d", &newSong->year);

    newSong->next = NULL;

    if (head == NULL) {
        head = newSong;
    } else {
        struct Song *temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newSong;
    }

    printf("\nSong added successfully!\n");
}

// Function to display all songs
void displaySongs() {
    struct Song *temp = head;

    if (head == NULL) {
        printf("\nNo songs available.\n");
        return;
    }

    printf("\n========== ALL SONGS ==========\n");

    while (temp != NULL) {
        printf("\nSong ID     : %d", temp->id);
        printf("\nTitle       : %s", temp->title);
        printf("\nArtist      : %s", temp->artist);
        printf("\nAlbum       : %s", temp->album);
        printf("\nRelease Year: %d\n", temp->year);

        temp = temp->next;
    }
}

// Function to search a song
void searchSong() {
    char title[100];
    struct Song *temp = head;
    int found = 0;

    if (head == NULL) {
        printf("\nNo songs available.\n");
        return;
    }

    printf("\nEnter song title to search: ");
    scanf(" %[^\n]", title);

    while (temp != NULL) {
        if (strcmp(temp->title, title) == 0) {
            printf("\nSong Found!\n");
            printf("Song ID     : %d\n", temp->id);
            printf("Title       : %s\n", temp->title);
            printf("Artist      : %s\n", temp->artist);
            printf("Album       : %s\n", temp->album);
            printf("Release Year: %d\n", temp->year);

            found = 1;
            break;
        }

        temp = temp->next;
    }

    if (!found) {
        printf("\nSong not found.\n");
    }
}

// Function to delete a song
void deleteSong() {
    int id;
    struct Song *temp = head;
    struct Song *prev = NULL;

    if (head == NULL) {
        printf("\nNo songs available.\n");
        return;
    }

    printf("\nEnter Song ID to delete: ");
    scanf("%d", &id);

    // If first song needs to be deleted
    if (head->id == id) {
        head = head->next;
        free(temp);

        printf("\nSong deleted successfully!\n");
        return;
    }

    // Search for the song
    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("\nSong not found.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);

    printf("\nSong deleted successfully!\n");
}

// Function to sort songs by title
void sortSongs() {
    struct Song *i, *j;
    int tempId, tempYear;
    char tempTitle[100];
    char tempArtist[100];
    char tempAlbum[100];

    if (head == NULL || head->next == NULL) {
        printf("\nNot enough songs to sort.\n");
        return;
    }

    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {

            if (strcmp(i->title, j->title) > 0) {

                tempId = i->id;
                i->id = j->id;
                j->id = tempId;

                tempYear = i->year;
                i->year = j->year;
                j->year = tempYear;

                strcpy(tempTitle, i->title);
                strcpy(i->title, j->title);
                strcpy(j->title, tempTitle);

                strcpy(tempArtist, i->artist);
                strcpy(i->artist, j->artist);
                strcpy(j->artist, tempArtist);

                strcpy(tempAlbum, i->album);
                strcpy(i->album, j->album);
                strcpy(j->album, tempAlbum);
            }
        }
    }

    printf("\nSongs sorted by title successfully!\n");
}

// Function to count songs
void countSongs() {
    int count = 0;
    struct Song *temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    printf("\nTotal Number of Songs: %d\n", count);
}

// Main function
int main() {
    int choice;

    while (1) {

        printf("\n\n====================================");
        printf("\n       MUSIC MANAGEMENT SYSTEM");
        printf("\n====================================");
        printf("\n1. Add Song");
        printf("\n2. Display All Songs");
        printf("\n3. Search Song");
        printf("\n4. Delete Song");
        printf("\n5. Sort Songs by Title");
        printf("\n6. Count Total Songs");
        printf("\n7. Exit");
        printf("\n====================================");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                addSong();
                break;

            case 2:
                displaySongs();
                break;

            case 3:
                searchSong();
                break;

            case 4:
                deleteSong();
                break;

            case 5:
                sortSongs();
                break;

            case 6:
                countSongs();
                break;

            case 7:
                printf("\nThank you for using Music Management System!\n");
                exit(0);

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}