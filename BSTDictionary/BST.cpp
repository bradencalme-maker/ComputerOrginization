#include "BSTNode.hpp"
#include "BST.hpp"
#include <iostream>

BST::BST(){
    root = nullptr;
}

BST::~BST(){
    if (root != nullptr){
        delete root;
        root = nullptr;
    }
}


BST::BST(const BST& other){
    if (other.root != nullptr) {
        root = new BSTNode(*other.root);
    } else {
        root = nullptr;
    }
}

BST& BST::operator=(const BST& other){
    if (root != nullptr){
        delete root;
        root = nullptr;
    }
    if (other.root != nullptr) {
        root = new BSTNode(*other.root);
    } else {
        root = nullptr;
    }
    return *this;
}

bool BST::is_empty(){
    return root == nullptr;
}

void BST::clear(){
    while (root != nullptr){
        remove(root->key, root,root);
    }
}

std::vector<int> BST::keys(){
    std::vector<int> v;
    keys(root, v);
    return v;
}

void BST::keys(BSTNode* c, std::vector<int>& v){
        if (c!=nullptr){
        if (c->left !=nullptr){
            keys(c->left, v);
        }
        v.push_back(c->key);
        if (c->right != nullptr){
            keys(c->right, v);
        }
    }
}

std::vector<double> BST::values(){
    std::vector<double> v;
    values(root, v);
    return v;
}

void BST::values(BSTNode* c, std::vector<double>& v){
        if (c!=nullptr){
        if (c->left !=nullptr){
            values(c->left, v);
        }
        v.push_back(c->value);
        if (c->right != nullptr){
            values(c->right, v);
        }
    }
}

std::vector<Pair<int, double>> BST::entries(){
    std::vector<Pair<int, double>> v;
    entries(root, v);
    return v;
}

void BST::entries(BSTNode* c, std::vector<Pair<int, double>>& v){
        if (c!=nullptr){
        if (c->left !=nullptr){
            entries(c->left, v);
        }
        Pair<int, double> p2 (c->key, c->value);
        v.push_back(p2);
        if (c->right != nullptr){
            entries(c->right, v);
        }
    }
}


bool BST::insert(int k, double v){
    return insert(k,v,root);
}

bool BST::insert(int k, double v, BSTNode* c){
    if (root == nullptr){
        root = new BSTNode(k,v);
        return true;
    }
    else if (k < c->key){
        if (c->left == nullptr){
            c->left = new BSTNode(k,v);
            return true;
        }
        else{
            return insert(k,v,c->left);
        }
    }
    else{
        if (c->right == nullptr){
            c->right = new BSTNode(k,v);
            return true;
        }
        else{
            return insert(k,v,c->right);
        }
    }
}

double BST::search(int k, double dflt){
    return search(k, dflt, root);
}

double BST::search(int k, double dflt, BSTNode* c){
    if (c->key == k){
        return c->value;
    }
    else if(k < c->key && c->left != nullptr){
        return search(k, dflt, c->left);
    }
    else if(k > c->key && c->right != nullptr){
        return search(k, dflt, c->right);
    }
        return(dflt);
}

void BST::inorder_traversal(){
    inorder_traversal(root);
    std::cout << std::endl;
}

void BST::inorder_traversal(BSTNode* c){
    if (c!=nullptr){
        if (c->left !=nullptr){
            inorder_traversal(c->left);
        }
        std::cout << "(" << c->key << "," << c->value << ") ";
        if (c->right != nullptr){
            inorder_traversal(c->right);
        }
    }
}

void BST::postorder_traversal(){
    postorder_traversal(root);
    std::cout << std::endl;
}

void BST::postorder_traversal(BSTNode* c){
    if (c!=nullptr){
        if (c->left !=nullptr){
            postorder_traversal(c->left);
        }
        if (c->right != nullptr){
            postorder_traversal(c->right);
        }
        std::cout << "(" << c->key << "," << c->value << ") ";
    }
}

void BST::preorder_traversal(){
    preorder_traversal(root);
    std::cout << std::endl;
}

void BST::preorder_traversal(BSTNode* c){
    if (c!=nullptr){
        std::cout << "(" << c->key << "," << c->value << ") ";
        if (c->left !=nullptr){
            preorder_traversal(c->left);
        }
        if (c->right != nullptr){
            preorder_traversal(c->right);
        }   
    }
}

bool BST::remove(int k){
    return remove(k, root, root);
}
BSTNode* BST::left_most(BSTNode* c){
    while(c->left != nullptr){
        c = c->left;
    }
    return c;
}
bool BST::remove(int k, BSTNode* c, BSTNode* r){
    if (c->key == k){
        if(c->right == nullptr && c->left == nullptr){
             //remove
            if (r==c){
                root = nullptr;
            }
            else if (r->left == c){
                r->left = nullptr;
            }
            else if (r->right == c){
                r->right = nullptr;
            }
            delete c; //have to write this still
        }
        else if (c->right == nullptr && c->left != nullptr){
            //replace with left node
            if (r->left == c){
                r->left = c->left;
            }
            else if (r->right == c){
                r->right = c->left;
            }
            else if (r == c){
                root = c->left;
            }
            c->left = nullptr;
            delete c; //have to write this still            
            return true;
        }
        else if (c->right != nullptr && c->left == nullptr){
            //replace with right node
            if (r->left == c){
                r->left = c->right;
            }
            else if (r->right == c){
                r->right = c->right;
            }
            else if (r == c){
                root = c->right;
            }
            c->right = nullptr;
            delete c; //have to write this still
            return true;
        }
        else{
            //replace with left most node of right sub tree
            BSTNode* temp = left_most(c->right);
            remove(left_most(c->right)->key);
            c->key = temp->key;
            c->value = temp->value;
            return true;
            
        }
    }
    else if(k < c->key && c->left != nullptr){
        if (c->left->key == k){
            r = c;
        }
        return remove(k,c->left,r);   // not sure about the return
    }
    else if(k > c->key && c->right != nullptr){
        if (c->right->key == k){
            r = c;
        }
        return remove(k,c->right,r);  //not sure about the return 
    }
    return false;
}

int BST::size(){
    return size(root);
}

int BST::size(BSTNode* c){
    if (c!=nullptr){
        return 1 + size(c->left) + size(c->right);
    }
    return 0;
}

int BST::height(){
    return height(root);
}

int BST::height(BSTNode* c){
    if (c == nullptr){
        return 0;
    }
    int left = height(c->left);
    int right = height(c->right);
    if (left > right){
        return 1+ left;
    }
    else {
        return 1+ right;
    }
}