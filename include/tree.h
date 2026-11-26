#include <iostream>
using namespace std;

class NodeTree {
 public:
  int data;
  NodeTree* left;
  NodeTree* right;
  NodeTree(int value);
};

class Tree {
 private:
  NodeTree* root;
  NodeTree* getNodeByData(int data);
  NodeTree* getParent(int data);
  void displayLDR(NodeTree* current);
  int getMaxDepth(NodeTree* current);

 public:
  Tree();
  void add(int data);
  bool getNodeData(int data);
  int getParentData(int data);
  NodeTree* maxRight(int data);
  NodeTree* maxRight(NodeTree* current);
  int maxRightData(int data);
  void removeNode(int data);
  void DisplayLDR();
  int getMaxDepth();
};
