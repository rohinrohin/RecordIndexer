#include "BST.h"

void BST::init(){
    this->_root = NULL;
}

void BST::insert(int a){
    Node* tmp = new Node;
    tmp->key = a;
    tmp->left = NULL;
    tmp->right = NULL;

    if(this->_root == NULL){
        tmp->p = NULL;
        this->_root = tmp;
    }else{
        Node* cElem = this->_root;
        Node* parent = NULL;

        while(cElem != NULL){
            parent = cElem;
            cElem = (a < cElem->key) ? cElem->left : cElem->right;
        }

        tmp->p = parent;
        if(a < parent->key){
            parent->left = tmp;
        }else{
            parent->right = tmp;
        }
    }
}

void BST::preorderWalk(Node* p) {
    if (p != NULL) {
       cout << p->key << " ";
       this->preorderWalk(p->left);
       this->preorderWalk(p->right);
    }
}

void BST::preorderWalk(){
    cout << "Preorder walk: ";
    this->preorderWalk(this->_root);
    cout << endl;
}

void BST::postorderWalk(Node* p) {
        if (p != NULL) {
           this->postorderWalk(p->left);
           this->postorderWalk(p->right);
           cout << p->key << " ";
        }
}

void BST::postorderWalk(){
    cout << "Postorder walk: ";
    this->postorderWalk(this->_root);
    cout << endl;
}

void BST::inorderWalk(Node* p){
        if (p != NULL) {
           this->inorderWalk(p->left);
           cout << p->key << " ";
           this->inorderWalk(p->right);
        }
}

void BST::inorderWalk(){
    cout << "Inorder walk: ";
    this->inorderWalk(this->_root);
    cout << endl;
}

Node* BST::findElem(int val, Node* p){
    if(p != NULL){
        if(val == p->key) return p;

        if(val < p->key){
            return findElem(val, p->left);
        }else{
            return findElem(val, p->right);
        }
    }else{
        return NULL;
    }
}

Node* BST::findElem(int val){
    return this->findElem(val, this->_root);
}

Node* BST::findSuccessor(int val){
    Node* startNode = this->findElem(val);
    Node* parent = startNode;

    startNode = startNode->right;
    while(startNode != NULL && startNode->left != NULL){
        parent = startNode;
        startNode = startNode->left;
    }

    return startNode;
}

void BST::deleteNode(Node* p){
    Node *q = NULL;
    Node *r = NULL;

    if (p->left == NULL || p->right == NULL){
        q = p;
    }else{
        q = this->findSuccessor(p->key);
    }

    if (q->left != NULL){
        r = q->left;
    }else{
        r = q->right;
    }

    if (r != NULL){
        r->p = q->p;
    }

    if (q->p == NULL){
        this->_root = r;
    }else if (q == q->p->left){
        q->p->left = r;
    }else{
        q->p->right = r;
    }

    if (q != p){
        p->key = q->key;
    }
}

void BST::deleteNode(int val){
    this->deleteNode(this->findElem(val));
}

int BST::countLevels(Node* p){
        int h1 = 0, h2 = 0;

        if(p == NULL) return 0;

        if(p->left){
            h1 = countLevels(p->left);
        }

        if(p->right){
            h2 = countLevels(p->right);
        }

        return(max(h1,h2)+1);
}

int BST::countLevels(){
    return this->countLevels(this->_root);
}

int BST::countNodes(Node* p){
      if(p == NULL){
            return 0;
      }else{
            return (countNodes(p->left) + countNodes(p->right)+1);
      }
}

int BST::countNodes(){
    return this->countNodes(this->_root);
}

int BST::countLeftNodes(Node* p) {
    if(p == NULL){
          return 0;
    }else{
        return (countLeftNodes(p->left) + countLeftNodes(p->right)) + (p->left != NULL && p->right == NULL)? 1 : 0;
    }
}

int BST::countLeftNodes(){
    return this->countLeftNodes(this->_root);
}

