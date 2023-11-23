/* convert the string from Infix to Postfix
Given an infix expression, Your task is to convert the given infix expression to a postfix expression.
*/
#include<bits/stdc++.h>
using namespace std;

int check(char c) {
  if (c == '^') {
    return 3;
  } else if (c == '*' || c == '/') {
    return 2;
  } else if (c == '+' || c == '-') {
    return 1;
  }
  return -1;
}

string infixToPostfix(string exp) {
  stack<char> st;
  int n = exp.size();
  string result = "";
  for (int i = 0; i < n; i++) {
    char ch = exp[i];
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ||
        (ch >= '0' && ch <= '9')) {
      result += ch;
    } else if (ch == '(') {
      st.push(ch);
    } else if (ch == ')') {
      while (st.top() != '(') {
        result += st.top();
        st.pop();
      }
      st.pop();
    } else {
      while (!st.empty() && check(ch) <= check(st.top())) {
        result += st.top();
        st.pop();
      }
      st.push(ch);
    }
  }

  while (!st.empty()) {
    result += st.top();
    st.pop();
  }

  return result;
}
