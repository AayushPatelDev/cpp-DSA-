#include <iostream>
#include <map>
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


void kthLevel(Node* root, int k){
  if(root == NULL){
    return;
  }

  if(k == 1){
    cout << root->data << " ";
    return;
  }
  kthLevel(root->left, k-1);
  kthLevel(root->right, k-1);
}

int main(){
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);

  int k = 2;
  kthLevel(root, k);
}