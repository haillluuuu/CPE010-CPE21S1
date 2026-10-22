#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
#include <string>

using namespace std;

//==============================
// Node
//==============================
struct Node
{
    string song;
    Node* next;
    Node* prev;
};

//==============================
// Create New Node
//==============================
Node* newNode(string title)
{
    Node* temp = new Node;

    temp->song = title;
    temp->next = temp;
    temp->prev = temp;

    return temp;
}

//==============================
// Add Song
//==============================
void addSong(Node** head, string title)
{
    Node* temp = newNode(title);

    if (*head == nullptr)
    {
        *head = temp;
        return;
    }

    Node* last = (*head)->prev;

    last->next = temp;
    temp->prev = last;

    temp->next = *head;
    (*head)->prev = temp;
}

//==============================
// Remove Song
//==============================
void removeSong(Node** head, string title)
{
    if (*head == nullptr)
        return;

    Node* current = *head;

    do
    {
        if (current->song == title)
        {
            if (current->next == current)
            {
                delete current;
                *head = nullptr;
                return;
            }

            current->prev->next = current->next;
            current->next->prev = current->prev;

            if (current == *head)
                *head = current->next;

            delete current;
            return;
        }

        current = current->next;

    } while (current != *head);
}

//==============================
// Play All Songs
//==============================
void playSongs(Node* head)
{
    if (head == nullptr)
        return;

    Node* current = head;

    do
    {
        cout << current->song << endl;
        current = current->next;

    } while (current != head);

    cout << endl;
}

//==============================
// Next Song
//==============================
void nextSong(Node** current)
{
    *current = (*current)->next;
    cout << "Current Song: " << (*current)->song << endl;
}

//==============================
// Previous Song
//==============================
void previousSong(Node** current)
{
    *current = (*current)->prev;
    cout << "Current Song: " << (*current)->song << endl;
}

#endif