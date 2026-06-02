#include <iostream>
#include <vector>
using namespace std;

class Node{
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
      data = val;
      left = NULL;
      right = NULL;
    }
};

int search(vector<int>& inOrder, int left, int right, int value){
  for (int i = left; i <= right; i++){
    if (inOrder[i] == value){
      return i;
    }
  }
  return -1;
}

void buildTree(vector<int>& preOrder, vector<int>& inOrder, int& preIndex, int left, int right, Node* &root){
  if (left > right){
    return;
  }
  root = new Node(preOrder[preIndex]);
  preIndex++;

  int inIndex = search(inOrder, left, right, preOrder[preIndex - 1]);
  buildTree(preOrder, inOrder, preIndex, left, inIndex - 1, root->left);
  buildTree(preOrder, inOrder, preIndex, inIndex + 1, right, root->right);

}

void printInOrder(Node* root){
  if (root == NULL){
    return;
  }
  printInOrder(root->left);
  cout << root->data << " ";
  printInOrder(root->right);
}

int main(){
  vector<int> preOrder = {1, 2, 4, 5, 3};
  vector<int> inOrder = {4, 2, 5, 1, 3};
  int preIndex = 0;
  Node* root = NULL;

  buildTree(preOrder, inOrder, preIndex, 0, inOrder.size() - 1, root);
  
  cout << "In-order Traversal: ";
  printInOrder(root);
  cout << endl;

  return 0;
}