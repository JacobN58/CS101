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
      struct  Node* entries;
};

struct Node {
	float avgSpeed;
  float fuelEfficiency;
	struct Node* next;
	struct Node* prev;
};

struct Node *split(struct Node *head) {
      struct Node *fast = head,*slow = head;
      while(fast->next && fast->next->next) {
          fast = fast->next->next;
          slow = slow->next;
      }
      struct Node *current = slow->next;
      slow->next = NULL;
      return current;
  }

struct Node *merge(struct Node *first, struct Node *last) {
    if(!first)
        return last;

    if(!last)
        return first;

    if(first->avgSpeed > last->avgSpeed) {
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

  first = new Node;
  // Node *last;
  first->avgSpeed = speed[0];
  first->fuelEfficiency = fuel[0];
  first->next = NULL;
  first->prev = NULL;
  last = first;


  for(int i = 1; i < size; i++) {
      Node *temp = new Node;
      temp->avgSpeed = speed[i];
      temp->fuelEfficiency = fuel[i];
      temp->next = NULL;
      temp->prev = last;
      last->next = temp;
      last = temp;
  }

  first = mergeSort(first);
  while(last->next != NULL) {
    last = last->next;
  }

//Dominates
Node *temp = first;
Node *comp = temp->next;
while(temp->next->next != NULL) {
  if(temp->avgSpeed > comp->avgSpeed && temp->fuelEfficiency <= comp->fuelEfficiency) {
    comp = temp->next;
    temp->next = comp->next;
    comp->next->prev = temp;
  }
  else {
    comp = temp->next;
    temp = temp->next;
  }
  comp = temp->next;
}

  // Node* temp = first;
  // for(int i = 0; i < size; i++) {
  //     cout << "Speed " << temp->avgSpeed << "Fuel " << temp->fuelEfficiency << endl;
  //     temp = temp->next;
  // }
  // for(int i = 0; i < size; i++) {
  //   cout << "Speed " << last->avgSpeed << "Fuel " << last->fuelEfficiency << endl;
  //     last = last->prev;
  // }

  /*allocate new Node
  set it's parameters
  keep doing that for each node
  sort nodes
  delete nodes that are dominated*/
}

void doList::out(char direction) {
  struct Node *temp = first;
  if(direction == 'd') {
    while(temp) {
        cout << "Speed " << temp->avgSpeed << " Fuel " << temp->fuelEfficiency << endl;
        // temp = first;
        temp = temp->next;
    }
  }

  if(direction == 'a') {
    temp = last;
    while(temp) {
      cout << "Speed " << temp->avgSpeed << " Fuel " << temp->fuelEfficiency << endl;
        temp = temp->prev;
    }
  }
}

void doList::out(int i, char direction) {
  struct Node *temp = first;
  if(direction == 'd') {
    for(int j = 0; j < i; j++) {
        cout << "Speed " << first->avgSpeed << " Fuel " << first->fuelEfficiency << endl;
        temp = first;
        first = first->next;
    }
  }
  if(direction == 'a') {
    for(int j = 0; j < i; j++) {
      cout << "Speed " << temp->avgSpeed << " Fuel " << temp->fuelEfficiency << endl;
        temp = temp->prev;
    }
  }
}

int doList::insert(float speed, float fuel) {
  Node *temp = first;
  Node *newNode = new Node;
  int num = 0, i = 0;
  newNode->avgSpeed = speed;
  newNode->fuelEfficiency = fuel;
    if(newNode->avgSpeed > temp->avgSpeed) {
      newNode->next = first;
      newNode->prev = NULL;
      first->prev = newNode;
      first = newNode;
      num = 0;
    }
    while(temp != NULL && temp->next != NULL) {
      if(temp->avgSpeed > newNode->avgSpeed && temp->next->avgSpeed < newNode->next->avgSpeed) {
        newNode->next = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
        temp->next->prev = newNode;
      }
      temp = temp->next;
      i++;
    }
    if(temp->next == NULL && newNode->avgSpeed < temp->avgSpeed) {
      newNode->next = NULL;
      temp->next = newNode;
      newNode->prev = temp;
      last = newNode;
    }
//Dominates
    Node *temp = first;
    Node *comp = temp->next;
    while(temp->next->next != NULL) {
      if(temp->avgSpeed > comp->avgSpeed && temp->fuelEfficiency <= comp->fuelEfficiency) {
        comp = temp->next;
        temp->next = comp->next;
        comp->next->prev = temp;
      }
      else {
        comp = temp->next;
        temp = temp->next;
      }
      comp = temp->next;
    }
    num = i;
    return num;
}

void doList::increase_speed(int i, float s) {
  
}

void doList::decrease_fuel(int i, float f) {

}
