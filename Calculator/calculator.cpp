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
string read_expression(istream& ins) 
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

/*
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
*/

//우선순위
int precedence(char c)
{
  if (c == '^')
    return 3;
  if (c == '*' || c == '/')
    return 2;
  if (c == '+' || c == '-')
    return 1;
  return -1;
}

bool isOperand(char c) {
	if(c >='0' &&  c <= '9') return true;
	if(c>= 'a' && c<='z') return true;
	if(c>= 'A' && c<= 'Z') return true;
	return false;
}

bool isOperator(char c) {
	if(c == '+' || c == '-' || c == '*' || c=='/' )
		return true;
	return false;
}


string convert_to_postfix(string s)
{
  int len = s.length();
  stack<char> st;
  string postfix = " ";
  
  for(int i=0; i<s.length(); i++)
  {
    if(s[i]==' ' || s[i]==',') continue;
    
    else if (isOperator(s[i]))
    {
      while(!st.empty() && st.top() != LEFT_PARENTHESIS && ((precedence(s[i])) <= (precedence(st.top()))))
      {
        postfix += st.top();
        st.pop();
      }
      st.push(s[i]);
    }

    else if (isOperand(s[i]))
    {
      postfix += s[i];
    }

    else if (s[i] == LEFT_PARENTHESIS)
    {
      st.push(s[i]);
    }

    else if (s[i] == RIGHT_PARENTHESIS)
    {
      while(!st.empty() && st.top() != LEFT_PARENTHESIS) 
      {
        postfix += st.top();
        st.pop();
      }
    }
  }
  while (!st.empty())
  {
    postfix += st.top();
    st.pop();
  }
}

//double evaluate_postfix(string s)



int main()
{
  string infix;
	cout<<"Enter the infix empression" <<endl;

  getline(cin,infix);
	string postfix = convert_to_postfix(infix);
	
	cout<<"The postfix expression is :"<<postfix<<endl;

  return 0;
}