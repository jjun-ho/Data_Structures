#include "set.h"

using namespace std;

int main()
{
  set<int> BTree;

  BTree.insert(1);
  BTree.insert(3);
  BTree.insert(5);
  BTree.insert(7);
  BTree.insert(9);
  BTree.insert(11);
  BTree.insert(13);

  BTree.show_contents();
  cout << endl;

  BTree.insert(4);
  BTree.insert(8);

  BTree.show_contents();
  cout << endl;

  cout << BTree.contains(3) << endl;
 /*
  BTree.erase(3);
  BTree.erase(9);
  BTree.show_contents();
  cout << endl;

  //cout << BTree.count(9) <<endl;
*/
}