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
// Take root as input, and find the count of left and right subtree, 
// and return the sum of both + 1 (for root node).
int count(Node* root){
  if(root == NULL){
    return 0;
  }
  int leftCount = count(root->left);
  int rightCount = count(root->right);
  return leftCount + rightCount + 1; // +1 for the current node
}

int main(){
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);

  return 0;

}