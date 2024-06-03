#include<bits/stdc++.h>
using namespace std;

class Polish {
    stack<float> operands;
    inline bool isDigit(char) const;
    inline bool isOperator(char) const;
    int precedence(char) const;
    float operation(float, float, char) const;

    public:
    float prefix(string);
    float postfix(string);
    float infix(string);
};

inline bool Polish::isDigit(char c) const { return c >= '0' && c <= '9'; }

inline bool Polish::isOperator(char c) const { return c == '+' || c == '-' || c == '*' || c == '/' || c == '^'; }

int Polish::precedence(char c) const {
    switch(c) {
        case '^':
        return 3;

        case '*':
        case '/':
        return 2;

        case '+':
        case '-':
        return 1;
    }
    return -1;
}

float Polish::operation(float a, float b, char c) const {
    switch(c) {
        case '+':
        return a + b;

        case '-':
        return a - b;

        case '*':
        return a * b;

        case '/':
        return a / b;

        case '^':
        return pow(a, b);
    }
    cerr << "Invalid operator." << endl;
    return -1;
}

float Polish::prefix(string expression) {
    for (int i = expression.size() - 1; i >= 0; i--)
        if (isDigit(expression[i]))
            operands.push(expression[i] - '0');
        else if (isOperator(expression[i])) {
            float op1 = operands.top(); operands.pop();
            float op2 = operands.top(); operands.pop();
            operands.push(operation(op1, op2, expression[i]));
        } else if (expression[i] == ' ')
            continue;
        else {
            cerr << "Invalid expression." << endl;
            return -1;
        }
    return operands.top();
}

float Polish::postfix(string expression) {
    for (char c : expression)
        if (isDigit(c))
            operands.push(c - '0');
        else if (isOperator(c)) {
            float op2 = operands.top(); operands.pop();
            float op1 = operands.top(); operands.pop();
            operands.push(operation(op1, op2, c));
        } else if (c == ' ')
            continue;
        else {
            cerr << "Invalid expression." << endl;
            return -1;
        }
    return operands.top();
}

float Polish::infix(string expression) {
    stack<char> operators;
    string post = "";

    for (char c : expression) {
        if (isDigit(c))
            post += c;
        else if (c == '(')
            operators.push(c);
        else if (c == ')') {
            while (operators.top() != '(') {
                post += operators.top();
                operators.pop();
            }
            operators.pop();
        } else if (isOperator(c)) {
            while (!operators.empty() && precedence(c) <= precedence(operators.top())) {
                post += operators.top();
                operators.pop();
            }
            operators.push(c);
        } else if (c == ' ')
            continue;
        else {
            cerr << "Invalid expression." << endl;
            return -1;
        }
    }
    while (!operators.empty()) {
        post += operators.top();
        operators.pop();
    }
    return postfix(post);
}