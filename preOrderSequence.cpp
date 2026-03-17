#include <iostream>
#include <vector>
using namespace std;

// Definition of the Node class for the binary tree
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

static int idx = -1;  // Global index to keep track of the current position in the pre-order traversal
// Function to build a binary tree from a given pre-order traversal
Node* buildTree(vector<int> preOrder){
  idx++;
  if(preOrder[idx] == -1){
    return NULL;
  }
  Node* newNode = new Node(preOrder[idx]);
  newNode->left = buildTree(preOrder);
  newNode->right = buildTree(preOrder);
  return newNode;
}

void printPreOrder(Node* root){
  if(root == NULL){
    return;
  }
  cout << root->data << " "; // Process the current node
  printPreOrder(root->left);       // Traverse the left subtree
  printPreOrder(root->right);      // Traverse the right subtree
}

//O(n) time complexity, where n is the number of nodes in the binary tree
int main(){
  vector<int> preOrder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
  Node* root = buildTree(preOrder);
  return 0;
}