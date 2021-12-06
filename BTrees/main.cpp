#include "set.h"

using namespace std;

int main()
{
  set<int> BTree;
  int num;
  string mode;
    
  while(1)
  {
    cout << "Mode Select (1. insert / 2. erase / 3. count / 4. show_contents / quit ) ? : " ;
    cin >> mode; 
    if(mode == "1")
    {
      cout << "insert number?: ";
      cin >> num;
      BTree.insert(num);
      cout << num << " insert!!!" << endl;
    }
    else if (mode == "2")
    {
      cout << "erase number?: ";
      cin >> num;
      BTree.erase(num);
      cout << num << " erase!!!" << endl;
    }
    else if(mode == "3")
    {
      cout << "count number?: ";
      cin >> num;
      cout << num << " count(1: True / 2: False ) : " << BTree.count(num) << endl;
    }
    else if(mode == "4")
    {
      cout << "show_contents" << endl;
      BTree.show_contents();
    }
    else if(mode == "quit")
    {
      cout << "quit";
      break;
    }
    else
    {       
      cout << "Wrong Mode";
      break;
    }   
  }
}  
