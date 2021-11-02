#include <iostream>
#include <cassert>
#include <cstdlib>
#include <string>
#include <cctype>
#include <cstring>

#include "stack.h"

using namespace std;

const char DECIMAL = '.';
const char LEFT_PARENTHESIS = '(';
const char RIGHT_PARENTHESIS = ')';

template <class Item>
string read_expression() 
{
  stack<Item> numbers; 
  stack<char> operations; 
  Item number;
  char symbol;

  while (ins && ins.peek( ) != '\n')
  {
    if (isdigit(ins.peek( )) || (ins.peek( ) == DECIMAL)) 
    {
      ins >> number;
      numbers.push(number);
    }
    else if (strchr("+-*/", ins.peek( )) != NULL) 
    {
      ins >> symbol;
      operations.push(symbol);
    }
    else if (ins.peek( ) == RIGHT_PARENTHESIS) 
    {
      ins.ignore( );
      evaluate_stack_tops(numbers, operations); 
    }
    else
      ins.ignore( );
  }
  return numbers.top( );
}

template <class Item>
void evaluate_stack_tops(stack<Item>& numbers, stack<char>& operations)
{
  double operand1, operand2;
  operand2 = numbers.top( ); 
  numbers.pop( );
  operand1 = numbers.top( ); 
  numbers.pop( );
  switch (operations.top( )) 
  {
    case '+': numbers.push(operand1 + operand2); break;
    case '-': numbers.push(operand1 - operand2); break;
    case '*': numbers.push(operand1 * operand2); break;
    case '/': numbers.push(operand1 / operand2); break;
  }
  operations.pop( );
}


string convert_to_postfix(string s)
double evaluate_postfix(string s)



int main()
{
  double answer;
  cout << "arithmetic expression:" << endl;
  answer = read_and_evaluate(cin);
  cout << "That evaluates to " << answer << endl;

  return EXIT_SUCCESS; }
}