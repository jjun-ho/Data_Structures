#include "set.h"

using namespace std;

int main()
{
  set<int> BTree;

  BTree.insert(3);
  BTree.insert(4);
  BTree.insert(1);
  BTree.insert(2);
  BTree.insert(7);
  BTree.insert(8);
  BTree.insert(5);
  BTree.insert(6);

  BTree.show_contents(3);
  //cout << BTree.count(7) <<endl;

  cout << endl;
 
  BTree.erase(4);
  BTree.show_contents(3);
}