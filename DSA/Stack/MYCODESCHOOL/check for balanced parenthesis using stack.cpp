/*
  C++ Program to check for balanced parentheses in an expression using stack.
  Given an expression as string comprising of opening and closing characters
  of parentheses - (), curly braces - {} and square brackets - [], we need to 
  check whether symbols are balanced or not. 
*/

// WE CAN IMPLEMENT THE FOLLOWING CODE IN A SHORTER WAY ALSO ( LATER I WILL INCLUDE THAT CODE) 

#include<bits/stdc++.h> 
using namespace std;

// Function to check whether two characters are opening
// and closing of same type.

bool ArePair(char opening, char closing)
{
    if (opening == '(' && closing == ')')
        return true;
    else if (opening == '{' && closing == '}')
        return true;
    else if (opening == '[' && closing == ']')
        return true;
    return false;
}

bool AreParanthesesBalanced(string exp)
{
    stack<char> S;
    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            S.push(exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (S.empty() || !ArePair(S.top(), exp[i]))
                return false;
            else
                S.pop();
        }
    }
    return S.empty() ? true : false;
}

int main()
{
    
    string expression;
    cout << "Enter an expression:  "; // input expression from STDIN/Console
    cin >> expression;
    if (AreParanthesesBalanced(expression))
        cout << "Balanced\n";
    else
        cout << "Not Balanced\n";
}