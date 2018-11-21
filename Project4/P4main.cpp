#include <iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<algorithm>

using namespace std;

struct Node {
	int data;
	Node *left, *right;
};

Node* newNode(int data);

int search(int array[], int start, int end, int value);

Node* construct(int inorder[], int postorder[], int start, int end, int* index) {
	if (start > end)
		return NULL;

	Node* node = newNode(postorder[*index]);
	(*index)--;

	if (start == end)
		return node;

  int iIndex = search(inorder, start, end, node->data);

	node->right = construct(inorder, postorder, iIndex + 1, end, index);
	node->left = construct(inorder, postorder, start, iIndex - 1, index);

	return node;
}

Node* buildTree(int inorder[], int postorder[], int n) {
	int index = n - 1;
	return construct(inorder, postorder, 0, n - 1, &index);
}

int search(int array[], int start, int end, int value) {
  int i;
    for (i = start; i <= end; i++) {
      if (array[i] == value)
        break;
    }
  return i;
}

Node* newNode(int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}

int main(int argc, char *argv[]) {
  ifstream file1, file2, file3;
  file1.open(argv[1]);
  file2.open(argv[2]);
  file3.open(argv[3]);

  int count1 = 0, count2 = 0;
  int temp = 0;
  while(file1 >> temp) {
    count1++;
    count2++;
  }
  file1.close();


  int inorder[count1], postorder[count2];
  string encoded;
  file1.open(argv[1]);

  for(int i=0; i < count1; i++) {
    file1 >> inorder[i];
  }
  file1.close();

  for(int i=0; i < count2; i++) {
    file2 >> postorder[i];
  }
  file2.close();

  while(file3 >> encoded) {
    file3 >> encoded;
  }
  file3.close();

	Node* root = buildTree(inorder, postorder, count1);

  Node* tempRoot = root;
  int n = encoded.size();
  char letter;
for(int i=0; i < n; i++) {
  // cout << "START " << i << endl;
  //cout << encoded[i] << endl;

  if(tempRoot->left != NULL || tempRoot->right != NULL) {
    if(encoded[i] == '1') {
      tempRoot = tempRoot->right;
      // cout << "RIGHT" << endl;
    }
    else if(encoded[i] == '0') {
      tempRoot = tempRoot->left;
      // cout << "LEFT" << endl;
    }
    else {
      cout << "ERROR" << endl;
    }
  }

  if(tempRoot->left == NULL && tempRoot->right == NULL) {
    letter = tempRoot->data;
    cout << letter;
    tempRoot = root;
  }

}
cout << endl;

	return 0;
}
