#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for doubly linked list
typedef struct Song {
    char name[100];
    struct Song *prev;
    struct Song *next;
} Song;

Song *head = NULL;  // start of playlist
Song *tail = NULL;  // end of playlist
Song *current = NULL; // currently playing song

// Function to create a new song node
Song* createSong(char *name) {
    Song *newSong = (Song*)malloc(sizeof(Song));
    strcpy(newSong->name, name);
    newSong->prev = newSong->next = NULL;
    return newSong;
}

// Add a song to the end of the playlist
void addSong(char *name) {
    Song *newSong = createSong(name);
    if (head == NULL) {
        head = tail = current = newSong;
    } else {
        tail->next = newSong;
        newSong->prev = tail;
        tail = newSong;
    }
    printf("Song '%s' added to playlist.\n", name);
}

// Remove a song by name
void removeSong(char *name) {
    Song *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            if (temp == head) head = temp->next;
            if (temp == tail) tail = temp->prev;
            if (temp->prev) temp->prev->next = temp->next;
            if (temp->next) temp->next->prev = temp->prev;

            if (current == temp) current = temp->next ? temp->next : temp->prev;

            free(temp);
            printf("Song '%s' removed from playlist.\n", name);
            return;
        }
        temp = temp->next;
    }
    printf("Song '%s' not found in playlist.\n", name);
}

// Play next song
void playNext() {
    if (current && current->next) {
        current = current->next;
        printf("Playing next song: %s\n", current->name);
    } else {
        printf("You are at the last song. No next song available.\n");
    }
}

// Play previous song
void playPrev() {
    if (current && current->prev) {
        current = current->prev;
        printf("Playing previous song: %s\n", current->name);
    } else {
        printf("You are at the first song. No previous song available.\n");
    }
}

// Display the playlist
void displayPlaylist() {
    Song *temp = head;
    if (!temp) {
        printf("Playlist is empty.\n");
        return;
    }
    printf("\nPlaylist:\n");
    while (temp != NULL) {
        if (temp == current)
            printf("-> %s (Currently Playing)\n", temp->name);
        else
            printf("   %s\n", temp->name);
        temp = temp->next;
    }
}

int main() {
    int choice;
    char songName[100];

    do {
        printf("\n=== Music Playlist Menu ===\n");
        printf("1. Add Song\n");
        printf("2. Remove Song\n");
        printf("3. Play Next Song\n");
        printf("4. Play Previous Song\n");
        printf("5. Display Playlist\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to consume newline left by scanf

        switch (choice) {
            case 1:
                printf("Enter song name to add: ");
                fgets(songName, sizeof(songName), stdin);
                songName[strcspn(songName, "\n")] = 0; // remove newline
                addSong(songName);
                break;
            case 2:
                printf("Enter song name to remove: ");
                fgets(songName, sizeof(songName), stdin);
                songName[strcspn(songName, "\n")] = 0;
                removeSong(songName);
                break;
            case 3:
                playNext();
                break;
            case 4:
                playPrev();
                break;
            case 5:
                displayPlaylist();
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 6);

    return 0;
}