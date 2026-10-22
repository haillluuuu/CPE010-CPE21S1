#include <iostream>
#include "playlist.h"

using namespace std;

int main()
{
    Node* head = nullptr;

    //==============================
    // Create Playlist
    //=============+=================
    addSong(&head, "Best Part");
    addSong(&head, "Get You");
    addSong(&head, "Japanese Denim");

    cout << "PLAYLIST" << endl;
    playSongs(head);

    //==============================
    // Next Song
    //==============================
    Node* current = head;

    cout << "Current Song: " << current->song << endl;

    cout << "\nNext Song" << endl;
    nextSong(&current);

    //==============================
    // Previous Song
    //==============================
    cout << "\nPrevious Song" << endl;
    previousSong(&current);

    //==============================
    // Add Song
    //==============================
    cout << "\nAdding Song: Always" << endl;
    addSong(&head, "Always");

    cout << "\nPLAYLIST" << endl;
    playSongs(head);

    //==============================
    // Remove Song
    //==============================
    cout << "Removing Song: Get You" << endl;
    removeSong(&head, "Get You");

    cout << "\nPLAYLIST" << endl;
    playSongs(head);

    return 0;
}