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

template<class Item>
string read_expression(istream& ins);
string convert_to_postfix(string s);
double evaluate_postfix(string s);

double scanNum(char ch);
int precedence(char op);
bool isOperand(char c) ;
bool isOperator(char c) ;
double operation (double val1, double val2, char op);

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

double scanNum(char ch)
{
   int value;
   value = ch;
   return double(value-'0');
}

//operator 우선순위
int precedence(char op)
{
  if (op == '*' || op == '/')
    return 2;
  if (op == '+' || op == '-')
    return 1;
  return -1;
}

bool isOperand(char c) 
{
	if(c >='0' &&  c <= '9') return true;
	if(c>= 'a' && c<='z') return true;
	if(c>= 'A' && c<= 'Z') return true;
	return false;
}

bool isOperator(char c) 
{
	if(c == '+' || c == '-' || c == '*' || c=='/' )
		return true;
	return false;
}

double operation (double val1, double val2, char op)
{
  if(op == '+')
    return val2 + val1;
  else if(op == '-')
    return val2 - val1;
   else if(op == '*')
    return val2 * val1;
  else if(op == '/')
    return val2 / val1;
  else
    cout<<"Unexpected Error "<< endl;
  return -1;
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
      st.pop();
    }
  }
  while (!st.empty())
  {
    postfix += st.top();
    st.pop();
  }
  return postfix;
}

double evaluate_postfix(string s)
{
  double val1, val2;
  stack<double> result;

  string postfix = convert_to_postfix(s);

  string::iterator it;
  for(it = postfix.begin(); it != postfix.end(); it++)
  {
    if(isOperator(*it) != false)
    {
      val1 = result.top();
      result.pop();
      val2 =result.top();
      result.pop();
      result.push(operation(val1, val2, *it));
    }
    else if(isOperand(*it) == true )
      result.push(scanNum(*it));
  }
  return result.top();
}

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