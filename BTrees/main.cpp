#include "set.h"

using namespace std;

int main()
{
  set<int> BTree;
  //insert
  BTree.insert(1);
  BTree.insert(3);
  BTree.insert(5);
  BTree.insert(7);
  BTree.insert(9);
  BTree.insert(11);
  BTree.insert(13);

  cout << "Before insert: " << endl;
  BTree.show_contents();
  cout << endl;

  BTree.insert(4);
  BTree.insert(8);

  cout << "After insert(4,8): " << endl;
  BTree.show_contents();
  cout << endl;

  //erase
  BTree.erase(3);
  BTree.erase(9);
  cout << "After erase(3,9): " << endl;
  BTree.show_contents();
  cout << endl;

  //count
  cout << "3 count?: " << BTree.count(3) << endl;
  cout << "15 count?: " << BTree.count(15) <<endl;
}