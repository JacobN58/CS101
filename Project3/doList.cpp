#include <iostream>
#include <string>
#include <vector>
using namespace std;

class doList {
public:
        doList(float speed[], float fuel[], int size);
        void out(char direction);
        void out(int i, char direction);
        int insert(float speed, float fuel);
        void increase_speed(int i, float s);
        void decrease_fuel(int i, float f);

private:
      struct  Node* first;
      struct  Node* last;
      struct  Node** entries;
};

struct Node {
	float avgSpeed;
  float fuelEfficiency;
	struct Node* next;
	struct Node* prev;
};

//mergeSort
struct Node *split(struct Node *head) {
      struct Node *fast = head,*slow = head;
      while(fast->next && fast->next->next) {
          fast = fast->next->next;
          slow = slow->next;
      }
      struct Node *temp = slow->next;
      slow->next = NULL;
      return temp;
  }
struct Node *merge(struct Node *first, struct Node *last) {
    if(!first)
        return last;

    if(!last)
        return first;

    if(first->avgSpeed < last->avgSpeed) {
        first->next = merge(first->next,last);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    }
    else {
        last->next = merge(first,last->next);
        last->next->prev = last;
        last->prev = NULL;
        return last;
    }
}
struct Node *mergeSort(struct Node *head) {
    if(!head || !head->next)
        return head;
    struct Node *tail = split(head);
    head = mergeSort(head);
    tail = mergeSort(tail);
    return merge(head,tail);
}

doList::doList(float speed[], float fuel[], int size) {
  for(int i = 0; i < size; i++) {
    Node *newNode = new Node;
    newNode->avgSpeed = speed[i];
    newNode->fuelEfficiency = fuel[i];
    newNode->next = NULL; newNode->prev = NULL;
  }

  first = mergeSort(first);
  while(last) {
    last = last->next;
  }
  /*allocate new Node
  set it's parameters
  keep doing that for each node
  sort nodes
  delete nodes that are dominated*/
}

void doList::out(char direction) {
  struct Node *temp = first;
  if(direction == 'd') {
    while(first) {
        cout << "Speed " << first->avgSpeed << "Fuel " << first->fuelEfficiency << endl;
        temp = first;
        first = first->next;
    }
  }
  if(direction == 'a') {
    while(last) {
      cout << "Speed " << temp->avgSpeed << "Fuel " << temp->fuelEfficiency << endl;
        temp = temp->prev;
    }
  }
}

void doList::out(int i, char direction) {
  struct Node *temp = first;
  if(direction == 'd') {
    for(int j = 0; j < i; j++) {
        cout << "Speed " << first->avgSpeed << "Fuel " << first->fuelEfficiency << endl;
        temp = first;
        first = first->next;
    }
  }
  if(direction == 'a') {
    for(int j = 0; j < i; j++) {
      cout << "Speed " << temp->avgSpeed << "Fuel " << temp->fuelEfficiency << endl;
        temp = temp->prev;
    }
  }
}

int doList::insert(float speed, float fuel) {

}

void doList::increase_speed(int i, float s) {

}

void doList::decrease_fuel(int i, float f) {

}
