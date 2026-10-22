#include <iostream>
#include "singly_LL.h"
#include "double_LL.h"

int main() {

    //'C' 'P' 'E'

    //CREATION OF HEAD NODE:
    doubleList<char>* head = new_node('C');

    //CREATION OF OTHER NODES:
    doubleList<char>* second = new_node('P');
    doubleList<char>* third = new_node('E');

    //LINK THE NODES
    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    std::cout << "Initial Traversal" << std::endl;
    dllTraverse(head);

    std::cout << std::endl;

    //INSERTION AT HEAD
    dllInsertHead('G', &head);

    std::cout << "Insertion at Head" << std::endl;
    dllTraverse(head);

    std::cout << std::endl;

    //INSERTION AT ANY PART
    dllInsertMiddle('E', second);

    std::cout << "Insertion at Any Part" << std::endl;
    dllTraverse(head);

    std::cout << std::endl;

    //INSERTION AT THE END
    dllInsertEnd('1', head);

    std::cout << "Insertion at the End" << std::endl;
    dllTraverse(head);

    std::cout << std::endl;

    //DELETE C
    dllDelete('C', &head);

    std::cout << "Delete C" << std::endl;
    dllTraverse(head);

    std::cout << std::endl;

    //DELETE P
    dllDelete('P', &head);

    std::cout << "Delete P" << std::endl;
    dllTraverse(head);

    return 0;
}