#include <iostream>
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

bool isIdentical(Node* root1, Node* root2){
  if(root1 == NULL && root2 == NULL){
    return true; // Both trees are empty, they are identical
  }
  if(root1 == NULL || root2 == NULL){
    return false; // One tree is empty and the other is not, they are not identical
  }
  // Check if the current nodes have the same data and recursively check left and right subtrees
  return (root1->data == root2->data) && 
         isIdentical(root1->left, root2->left) && 
         isIdentical(root1->right, root2->right);
}


int main(){
  Node* root1 = new Node(1);
  root1->left = new Node(2);
  root1->right = new Node(3);

  Node* root2 = new Node(1);
  root2->left = new Node(2);
  root2->right = new Node(3);

  return 0;
}