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

// To solve most tree problems, we can start with recusion.
// Take root as input, and find the height of left and right subtree, 
// and return the maximum of both + 1 (for root node).

int height(Node* root){
  if(root == NULL){
    return 0;
  }
  int leftHeight = height(root->left);
  int rightHeight = height(root->right);
  return max(leftHeight, rightHeight) + 1;
}

int main(){
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);

  return 0;

}