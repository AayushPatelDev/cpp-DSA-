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

int height(Node* root){
  if(root == NULL){
    return 0;
  }
  int leftHeight = height(root->left);
  int rightHeight = height(root->right);
  return max(leftHeight, rightHeight) + 1;
}

int diameter(Node* root){
  if(root == NULL){
    return 0;
  }
  int leftDiameter = diameter(root->left);
  int rightDiameter = diameter(root->right);
  int currentDiameter = height(root->left) + height(root->right) + 1; // Diameter through the current node
  return max(currentDiameter, max(leftDiameter, rightDiameter)); // Return the maximum diameter found
}


int main(){
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);

  return 0;
}