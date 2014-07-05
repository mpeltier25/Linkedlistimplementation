#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_
#include "node.h"

using namespace std;
class LinkedList{
private:
Node* head;
public:
void insert(Node* newNode);
void remove(string toGo);
void printData();
LinkedList();
~LinkedList();

};
#endif