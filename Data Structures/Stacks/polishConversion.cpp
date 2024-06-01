#include<bits/stdc++.h>
using namespace std;

inline bool isOperator(char c) { return c == '^' || c == '*' || c == '/' || c == '+' || c == '-'; }

inline bool isDigit(char c) { return c >= 'A' && c <= 'Z'; }

unsigned int precedence(char c) {
    switch (c) {
        case '^': return 3;
        case '*': case '/': return 2;
        case '+': case '-': return 1;
    }
    return 0;
}

float evaluate(float a, float b, char c) {
    switch (c) {
        case '^': return pow(a, b);
        case '*': return a * b;
        case '/': return a / b;
        case '+': return a + b;
        case '-': return a - b;
    }
    cerr << "Invalid operator." << endl;
    return -1;
}

string infixToPostfix(string infix) {
    stack<char> operators;
    string result = "";

    for (char c : infix) {
        if (isDigit(c))
            result += c;
        else if (isOperator(c)) {
            while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
                result += operators.top();
                operators.pop();
            }
            operators.push(c);
        } else if (c == '(')
            operators.push(c);
        else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                result += operators.top();
                operators.pop();
            }
            operators.pop();
        } else if (c == ' ')
            continue;
        else {
            cerr << "Invalid character." << endl;
            return "";
        }        
    }

    while (!operators.empty()) {
        result += operators.top();
        operators.pop();
    }
    return result;
}

string infixToPrefix(string infix) {
    reverse(infix.begin(), infix.end());

    string result = infixToPostfix(infix);

    reverse(result.begin(), result.end());    
    return result;
}