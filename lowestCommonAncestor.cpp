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

Node* lowestCommonAncestor(Node*root, Node* p, Node* q){
  if(root == NULL){
    return NULL;
  }

  if(root == p || root == q){
    return root;
  }
  Node* leftLCA = lowestCommonAncestor(root->left, p, q);
  Node* rightLCA = lowestCommonAncestor(root->right, p, q);

  if(leftLCA != NULL && rightLCA != NULL){
    return root;
  }
  return (leftLCA != NULL) ? leftLCA : rightLCA;
}


int main(){
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);

  Node* p = root->left;
  Node* q = root->right;
  Node* lca = lowestCommonAncestor(root, p, q);
  cout << "Lowest Common Ancestor: " << lca->data << endl;


  return 0;
}