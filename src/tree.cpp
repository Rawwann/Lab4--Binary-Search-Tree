#include "tree.h"

#include <iostream>
using namespace std;

NodeTree::NodeTree(int data) {
  this->data = data;
  this->left = NULL;
  this->right = NULL;
}

Tree::Tree() { root = nullptr; }

void Tree::add(int data) {
  NodeTree* newNode = new NodeTree(data);
  // tree empty
  if (root == NULL) {
    root = newNode;
    root->left = NULL;
    root->right = NULL;
  } else {
    NodeTree* current = root;
    NodeTree* parent = NULL;

    while (current != NULL) {
      parent = current;
      if (data < current->data) {
        current = current->left;
      } else if (data > current->data) {
        current = current->right;

      } else {
        delete newNode;
        return;
      }
    }
    if (parent != NULL) {
      if (data > parent->data) {
        parent->right = newNode;
      } else {
        parent->left = newNode;
      }
    }
  }
};
NodeTree* Tree::getNodeByData(int data) {
  NodeTree* current = root;
  while (current != NULL) {
    if (data == current->data) {
      return current;
    } else if (data > current->data) {
      current = current->right;
    } else {
      current = current->left;
    }
  }
  return NULL;
}
bool Tree::getNodeData(int data) {
  NodeTree* current = getNodeByData(data);
  if (current != NULL) {
    return true;
  } else {
    return false;
  }
}
NodeTree* Tree::getParent(int data) {
  NodeTree* current = getNodeByData(data);
  if (current == NULL || current == root) {
    return NULL;
  } else {
    NodeTree* parent = root;  // Counter
    while (parent != NULL) {
      if (parent->left == current || parent->right == current) {
        return parent;
      } else {
        // JUMP ==> check data ??
        if (current->data > parent->data) {
          parent = parent->right;
        } else {
          parent = parent->left;
        }
      }
    }
  }
  return NULL;
}
int Tree::getParentData(int data) {
  NodeTree* current = getParent(data);
  if (current != NULL) {
    return current->data;
  } else {
    return -1;
  }
}
NodeTree* Tree::maxRight(int data) {
  NodeTree* current = getNodeByData(data);
  // Root
  if (current == NULL) {
    return NULL;
  }
  while (current->right != NULL) {
    current = current->right;
  }

  return current;
}
NodeTree* Tree::maxRight(NodeTree* current) {
  if (current == NULL) return NULL;

  while (current->right != NULL) {
    current = current->right;
  }

  return current;
}

int Tree::maxRightData(int data) {
  NodeTree* current = maxRight(data);
  if (current == NULL) {
    return -1;
  } else {
    return current->data;
  }
}

void Tree::removeNode(int data) {
  NodeTree* current = getNodeByData(data);
  if (current == NULL) {
    return;
  }
  if (current == root) {
    // ROOT Only
    if (current->right == NULL && current->left == NULL) {
      root = NULL;
    } else if (current->right == NULL) {  // ROOT & leftSide
      root = root->left;

    } else if (current->left == NULL) {  // Root & Right Side
      root = root->right;
    } else {
      NodeTree* newRoot = root->left;          // Arwa
      NodeTree* rightMax = maxRight(newRoot);  // Skills
      rightMax->right = root->right;           // Team2
      root = newRoot;                          //
    }

    // RooT Right Side &Left Side

  } else {
    // node is not the root
    NodeTree* parent = getParent(data);

    if (current->right == NULL && current->left == NULL) {
      if (parent->left == current) {
        parent->left = NULL;
      } else {
        parent->right = NULL;
      }
    } else if (current->right == NULL) {
      if (parent->left == current) {
        parent->left = current->left;
      } else {
        parent->right = current->left;
      }
    } else if (current->left == NULL) {
      if (parent->left == current) {
        parent->left = current->right;
      } else {
        parent->right = current->right;
      }
    } else {
      NodeTree* newRoot = current->left;
      NodeTree* rightMax = maxRight(newRoot);
      rightMax->right = current->right;
      if (parent->left == current) {
        parent->left = newRoot;
      } else {
        parent->right = newRoot;
      }
    }
  }
  delete current;
};

void Tree::displayLDR(NodeTree* current) {
  if (current == NULL) {
    return;
  }
  displayLDR(current->left);
  cout << current->data << " ";
  displayLDR(current->right);
}
void Tree::DisplayLDR() {
  displayLDR(root);
  cout << endl;
}

int Tree::getMaxDepth(NodeTree* current) {
  if (current == NULL) {
    return 0;
  }
  int leftHeight = getMaxDepth(current->left);
  int rightHeight = getMaxDepth(current->right);
  if (leftHeight > rightHeight) {
    return leftHeight + 1;
  }
  return rightHeight + 1;
}
int Tree::getMaxDepth() { return getMaxDepth(root); }