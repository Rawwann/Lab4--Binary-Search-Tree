#include <iostream>
using namespace std;
#include "tree.h"

int main() {
  Tree t;
  t.add(50);
  t.add(50);
  t.add(40);
  t.add(30);
  t.add(45);
  t.add(60);
  t.add(70);
  t.add(65);
  /*
            50
          /    \
        40      60
       /  \       \
     30    45      70
                  /
                65
  */

  int parentData = t.getParentData(60);
  cout << "Parent of 60: " << t.getParentData(60) << endl;
  cout << "Parent of 50: " << t.getParentData(50) << endl;
  cout << "Parent of 65: " << t.getParentData(65) << endl;
  cout << "Parent of 30: " << t.getParentData(30) << endl;
  cout << "Parent of 45: " << t.getParentData(45) << endl;
  t.getNodeData(60) ? cout << "Found" << endl : cout << "NotFound" << endl;
  t.getNodeData(50) ? cout << "Found" << endl : cout << "NotFound" << endl;
  t.getNodeData(30) ? cout << "Found" << endl : cout << "NotFound" << endl;
  t.getNodeData(100) ? cout << "Found" << endl : cout << "NotFound" << endl;
  cout << t.maxRightData(40) << endl;
  cout << t.maxRightData(50) << endl;
  cout << t.maxRightData(30) << endl;
  cout << "Depth: " << t.getMaxDepth() << endl;
  t.DisplayLDR();
  cout << "node 70 deleted" << endl;
  t.removeNode(70);
  t.getNodeData(70) ? cout << "Found" << endl : cout << "NotFound" << endl;
  /*
            50
          /    \
        40      60
       /  \       \
     30    45      65
  */
  t.DisplayLDR();
  cout << "Depth: " << t.getMaxDepth() << endl;
  cout << "root is deleted" << endl;
  t.removeNode(50);
  t.getNodeData(50) ? cout << "Found" << endl : cout << "NotFound" << endl;
  /*
            40
           /  \
         30    45
                 \
                  60
                    \
                     65
  */
  t.DisplayLDR();
  cout << "Depth: " << t.getMaxDepth() << endl;
  return 0;
}