#ifndef DOUBLE_LL_H
#define DOUBLE_LL_H

#include <iostream>

template <typename T>
class doubleList {
public:
    T data;
    doubleList<T>* next = nullptr;
    doubleList<T>* prev = nullptr;
};

//==============================
// Create New Node
//==============================
template <typename T>
doubleList<T>* new_node(T newData)
{
    doubleList<T>* newNode = new doubleList<T>;

    newNode->data = newData;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    return newNode;
}

//==============================
// Traversal
//==============================
template <typename T>
void dllTraverse(doubleList<T>* currentNode)
{
    doubleList<T>* tail = nullptr;

    while (currentNode != nullptr)
    {
        std::cout << currentNode->data << " ";
        tail = currentNode;
        currentNode = currentNode->next;
    }

    std::cout << std::endl;

    std::cout << "Reverse Traversal" << std::endl;

    while (tail != nullptr)
    {
        std::cout << tail->data << " ";
        tail = tail->prev;
    }

    std::cout << std::endl;
}

//==============================
// Insertion at Head
//==============================
template <typename T>
void dllInsertHead(T newData, doubleList<T>** currentHead)
{
    doubleList<T>* newNode = new_node(newData);

    newNode->next = *currentHead;
    (*currentHead)->prev = newNode;

    *currentHead = newNode;
}

//==============================
// Insertion at Any Part
//==============================
template <typename T>
void dllInsertMiddle(T newData, doubleList<T>* previousNode)
{
    if (previousNode == nullptr)
    {
        std::cout << "Previous node cannot be NULL" << std::endl;
        return;
    }

    doubleList<T>* newNode = new_node(newData);

    newNode->next = previousNode->next;
    newNode->prev = previousNode;

    if (previousNode->next != nullptr)
    {
        previousNode->next->prev = newNode;
    }

    previousNode->next = newNode;
}

//==============================
// Insertion at End
//==============================
template <typename T>
void dllInsertEnd(T newData, doubleList<T>* currentHead)
{
    doubleList<T>* newNode = new_node(newData);

    while (currentHead->next != nullptr)
    {
        currentHead = currentHead->next;
    }

    currentHead->next = newNode;
    newNode->prev = currentHead;
}

//==============================
// Delete Node
//==============================
template <typename T>
void dllDelete(T targetData, doubleList<T>** currentHead)
{
    doubleList<T>* currentNode = *currentHead;

    while (currentNode != nullptr)
    {
        if (currentNode->data == targetData)
        {
            if (currentNode->prev != nullptr)
            {
                currentNode->prev->next = currentNode->next;
            }
            else
            {
                *currentHead = currentNode->next;
            }

            if (currentNode->next != nullptr)
            {
                currentNode->next->prev = currentNode->prev;
            }

            delete currentNode;
            break;
        }

        currentNode = currentNode->next;
    }
}

#endif