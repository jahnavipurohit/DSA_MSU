#include <iostream>
#include <string>
using namespace std;

// Node class for Doubly Linked List
class Node {
public:
    string songName;
    Node* prev;
    Node* next;

    Node(string name); // Constructor
};

// Constructor definition
Node::Node(string name) {
    songName = name;
    prev = nullptr;
    next = nullptr;
}

// Music Player class for Doubly Linked List operations
class MusicPlayer {
private:
    Node* head;
    Node* tail;
    Node* current;

public:
    MusicPlayer(); // Constructor

    void addSong(const string& name);
    void removeSong(const string& name);
    void playNext();
    void playPrevious();
    void displayPlaylist();

    ~MusicPlayer(); // Destructor
};

// Constructor definition
MusicPlayer::MusicPlayer() {
    head = nullptr;
    tail = nullptr;
    current = nullptr;
}

// Add song to end
void MusicPlayer::addSong(const string& name) {
    Node* newSong = new Node(name);
    if (!head) {
        head = tail = current = newSong;
    } else {
        tail->next = newSong;
        newSong->prev = tail;
        tail = newSong;
    }
    cout << "Song \"" << name << "\" added to the playlist.\n";
}

// Remove song by name
void MusicPlayer::removeSong(const string& name) {
    Node* temp = head;
    while (temp) {
        if (temp->songName == name) {
            if (temp->prev) temp->prev->next = temp->next;
            else head = temp->next;

            if (temp->next) temp->next->prev = temp->prev;
            else tail = temp->prev;

            if (current == temp) current = temp->next ? temp->next : temp->prev;

            delete temp;
            cout << "Song \"" << name << "\" removed from the playlist.\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Song \"" << name << "\" not found in the playlist.\n";
}

// Play next song
void MusicPlayer::playNext() {
    if (!current) {
        cout << "No songs in the playlist.\n";
        return;
    }
    if (current->next) {
        current = current->next;
        cout << "Now playing: " << current->songName << "\n";
    } else {
        cout << "You are at the end of the playlist.\n";
    }
}

// Play previous song
void MusicPlayer::playPrevious() {
    if (!current) {
        cout << "No songs in the playlist.\n";
        return;
    }
    if (current->prev) {
        current = current->prev;
        cout << "Now playing: " << current->songName << "\n";
    } else {
        cout << "You are at the beginning of the playlist.\n";
    }
}

// Display playlist
void MusicPlayer::displayPlaylist() {
    if (!head) {
        cout << "Playlist is empty.\n";
        return;
    }
    cout << "\nPlaylist:\n";
    Node* temp = head;
    while (temp) {
        if (temp == current)
            cout << ">> " << temp->songName << " << (current)\n";
        else
            cout << temp->songName << "\n";
        temp = temp->next;
    }
}

// Destructor to free memory
MusicPlayer::~MusicPlayer() {
    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

// Main function with menu
int main() {
    MusicPlayer player;
    int choice;
    string song;

    do {
        cout << "\n=== Music Playlist Menu ===\n";
        cout << "1. Add Song\n";
        cout << "2. Remove Song\n";
        cout << "3. Play Next Song\n";
        cout << "4. Play Previous Song\n";
        cout << "5. Display Playlist\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter song name: ";
                getline(cin, song);
                player.addSong(song);
                break;
            case 2:
                cout << "Enter song name to remove: ";
                getline(cin, song);
                player.removeSong(song);
                break;
            case 3:
                player.playNext();
                break;
            case 4:
                player.playPrevious();
                break;
            case 5:
                player.displayPlaylist();
                break;
            case 0:
                cout << "Exiting playlist...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}