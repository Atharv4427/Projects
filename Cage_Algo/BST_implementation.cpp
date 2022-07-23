#include <bits/stdc++.h>
using namespace std;

//Creating a Tree Node class
class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }


//searching for a key
Node* search(Node* root, int key) {
        if(root == NULL || root->data == key)        
            return root;
        if(root->data < key) 
            return search(root->right,key);
        return search(root->left,key);
}

//insert node
Node* insert(Node* root, int data) {
    if(root == NULL){
        return new Node(data);
    }
    else{
        Node* cur;
        if(data <= root->data) {
            cur = insert(root->left, data);
            root->left = cur;
        }
        else {
            cur = insert(root->right, data);
            root->right = cur;
        }
    return root;
    }
}

    Node* deletenode(Node* root, int k){ 
        // Base case 
        if (root == NULL) 
            return root; 
        //If root->data is greater than k then we delete the root's subtree
        if(root->data > k){ 
            root->left = deletenode(root->left, k); 
            return root; 
        } 
        else if(root->data < k){ 
            root->right = deletenode(root->right, k); 
            return root; 
        } 
  

        // If one of the children is empty 
        if (root->left == NULL) { 
            Node* temp = root->right;
            delete root; 
            return temp; 
        } 
        else if (root->right == NULL) { 
            Node* temp = root->left; 
            delete root; 
            return temp; 
        } 
        else {
          Node* Parent = root;
          // Find successor of the node
          Node *succ = root->right; 
          while (succ->left != NULL) { 
              Parent = succ; 
              succ = succ->left; 
          } 

          if (Parent != root) 
              Parent->left = succ->right; 
          else
              Parent->right = succ->right; 

          // Copy Successor Data  
          root->data = succ->data; 

          // Delete Successor and return root 
          delete succ;          
          return root; 
      } 
} 

// Inorder traversal
void inorder(Node* root){
        if(root == NULL)
            return;
        
        //First recur on left subtree 
        inorder(root->left);
        //Then read the data of child
        cout << root->data << " ";
        // Recur on the right subtree
        inorder(root->right);
}

};

int main(){
    Node Tree(0);
    Node* root = NULL;
    //Number of nodes to be inserted
    int t;
    cin>>t;
    while(t--){
        int data;
        cin>>data;
        root = Tree.insert(root,data);
    }

    Tree.inorder(root);

    //Searching data
    cout << "Enter the data to find:";
    int data;
    cin>>data;
    Node* find_element = Tree.search(root,data);
    if(find_element != NULL){
        cout<<"Found "<<find_element->data;
    } else {
        cout<< "Not found";
    }
    

    int delete_data;
    cout<< "\nEnter data to delete:";
    cin>>delete_data;
    Node* deleteelement = Tree.deletenode(root,delete_data);
    Tree.inorder(root);
    return 0;
}