#include <iostream>
#include <stack>
using namespace std;
 
int prec(char c) {
	if (c == '^') return 3;
	else if (c == '*' || c == '/') return 2;
	else if (c == '+' || c == '-') return 1;
	else return -1;
}
bool isOperand(char c) {
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) return true;
	else return false;
}
void infixToPostfix(string exp) {
	stack<char> st;
	string postfix;
 
	for(int i = 0; i<exp.length(); i++) {
    
		if (isOperand(exp[i])) {
			postfix += exp[i];
		} else if (exp[i] == '(') {      // push onto stack if opening parenthesis
			st.push(exp[i]);
		} else if (exp[i] == ')') {      // check while stack is not empty and stack top is not closing parenthesis
			while(!st.empty() && st.top() != '(') {
				postfix += st.top();
				st.pop();
			}
			if (st.top() == '(') {
				st.pop();
			}
		} else {
			while (!st.empty() && prec(exp[i]) <= prec(st.top())) {
				postfix += st.top();
				st.pop();
			}
			st.push(exp[i]);
		}
	}
	while(!st.empty()) {
		postfix += st.top();
		st.pop();
	}
	cout<< postfix;
}
int main() {
	string exp = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(exp);
    return 0;
	return 0;
}