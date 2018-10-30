#include <iostream>
#include <string>
#include <vector>
using namespace std;

class doList {
public:
        dolist(float speed[], float fuel[], int size);
        void out(char direction);
        void out(int i, char direction);
        int insert(float speed, float fuel);
        void increase_speed(int i, float s);
        void decrease_fuel(int i, float f);

private:
        Node* first;
        Node* last;
        Node** entries;
};

struct Node {
	float avgSpeed;
  float fuelEfficiency;
	struct Node* next;
	struct Node* prev;
};

doList::doList(float speed[], float fuel[], int size) {
  float sorted;
  sort(speed.begin, speed.end, sorted);

  /*allocate new Node
  set it's parameters
  keep doing that for each node
  sort nodes
  delete nodes that are dominated*/
}

void doList::out(char direction) {

}

void doList::out(int i, char direction) {

}

int doList::insert(float speed, float fuel) {

}

void doList::increase_speed(int i, float s) {

}

void doList::decrease_fuel(int i, float f) {

}
