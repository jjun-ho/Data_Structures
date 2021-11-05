#include "calculator.h"

using namespace std;

int main()
{
  string infix;
  double cal;

	cout<<"Enter the infix empression :" << endl;
  getline(cin,infix);
	string postfix = convert_to_postfix(infix);
  cout<<"The postfix expression is : "<< postfix << endl;

	cal = evaluate_postfix(postfix);
  cout<<"calculate postfix : " << cal << endl;

  return 0;
}