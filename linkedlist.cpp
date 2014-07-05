#include "linkedList.h"
#include <iostream>
using namespace std;

Node::Node(string nomen, int val):data(val), name(nomen)
{
next= NULL;
}
Node::~Node(){
if(next)
delete next;
}
LinkedList::LinkedList(){
	head=NULL;
}
LinkedList::~LinkedList()
{
if(head)
delete head;
}
void LinkedList::remove(string toGo){
//firsr if there is nothing in the list, delete nothing
if(!head){
	cout<<"Error: tried to delete from empty list"<<endl;
	return;
}
Node*toDelete=NULL;
if(!toGo.compare(head->getName())){//recall that compare returns 0 for equal
	toDelete=head;
	head=head->next;
}else //we have to look for it.
{
Node* current=head;
while (current->next){
	if(!toGo.compare(current->next->getName()))
{
	toDelete=current->next;
	//remove current->next from the list(since it is the one to delete)
	current->next=current->next->next;
	break;
}
}
}
if(!toDelete){
cout<<"You wanted me to delete"<<toGo<<"bt its not in the list"<<endl;
return;
}
//now delete it.
toDelete->next=NULL;
delete toDelete;
}
void LinkedList::insert(Node* newNode){
if(!head){
head=newNode;
return;
}
if(newName.compare(head->getName())>0){
newNode->next=head;
head=newNode;
return;
}
Node* temp=head;
//while there is a nextNode
while (temp->next){
if(newName.compare(temp->next->getName())>0)
break; // we found where to put the new node
temp=temp->next;
}
newNode->next=temp->next;
temp->next=newNode;
}
void LinkedList::printData(){
Node*temp=head;
while(temp){//same as while (temp!=NULL)
cout<<"Node with name"<<temp->getName()<<"and number"<<temp->getData()<<endl;
temp=temp->next;
}
}
int main(){
LinkedList list;
int choice=0;
string name;
int data;
Node*newNode=NULL;
while(true){
	cout<<"What would you like to do? Please enter one of the numbers below:"<<endl;
	cout<<"1) add a new list item."<<endl;
	cout<<"2) Remove a list item."<<endl;
	cout<<"3) print the list"<<endl;
	cout<<"4) Quit the program"<<endl;
	cin>>choice;
	switch(choice){
	case 1:
		cout<<"Enter the name for the new item:";
		cin>>name;
		cout<</*endl<<*/"enter the number for the new item:";
		cin>>data;
		newNode=new Node(name,data);
		list.insert(newNode);
		break;
	case 2:
		cout<<"Enter name of node to delete:";
		cin>>name;
		list.remove(name);
		break;
	case 3:
		cout<<"The list contains:"<<endl;
		list.printData();
		break;
	case 4:
		cout<<"Goodbye"<<endl;
		return 0;
	default:
		cout<<"That was invalid input, please choose a value from 1-4 from the list"<<endl;
	}
}
return 0;
}