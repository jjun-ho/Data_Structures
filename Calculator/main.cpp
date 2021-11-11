#include "calculator.h"

using namespace std;

int main()
{
  string infix;
  double cal;

	cout<< "Enter the infix empression : " << endl;
  infix = read_expression();
  cout<< "The infix expression : " << infix << endl;

	string postfix = convert_to_postfix(infix);
  cout<<"The postfix expression : "<< postfix << endl;

	cal = evaluate_postfix(postfix);
  cout<<"calculate postfix : " << cal << endl;

  return 0;
}