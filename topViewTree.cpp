#include <iostream>
#include <vector>
#include <queue>
#include <map>
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

//top view of a binary tree
void topView(Node* root){
  queue<pair<Node*, int>> q; // Queue to store nodes along with their horizontal distance
  map<int, int> m; //map to store the first node at each horizontal distance
  
  q.push({root, 0}); //start with root node at horizontal distance 0
  while(q.size() > 0){
    Node* curr = q.front().first; //current node
    int currHD = q.front().second; //current horizontal distance 
    q.pop();

    if(m.find(currHD) == m.end()){ //if HD is not already present in the map, add it
      m[currHD] = curr->data;
    }

    if(curr->left != NULL){ //if left child exists, add it to the queue with HD - 1
      q.push({curr->left, currHD - 1});
    }
    if(curr->right != NULL){ //if right child exits, add it to queue with HD+1
      q.push({curr->right, currHD +1});
    }
  }
  //print the top view from the map
  for(auto i : m){
    cout << i.second << " ";
  }
}

int main(){
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);

  topView(root);
  return 0;
}