#include <iostream>
#include <string>
#include <stack>

//using stack to evaluate infix expression
//can handle multi-digit numbers and parentheses

int precedence(char op){//return precedence of operators
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    return 0;
}

int applyOp(int a, int b, char op){//apply operator to two operands
    switch(op){
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

void Evaluation_Of_Infix_Main(std::string &input){
    std::stack<int> values;
    std::stack<char> ops;
    for(int i = 0; i < input.length(); i++){
        if(isspace(input[i]))
            continue;
        if(isdigit(input[i])){
            int val = 0;
            while(i < input.length() && isdigit(input[i])){
                val = (val * 10) + (input[i] - '0');//string to int conversion
                i++;
            }
            values.push(val);
            i--;
        } else if(input[i] == '('){
            ops.push(input[i]);
        } else if(input[i] == ')'){
            while(!ops.empty() && ops.top() != '('){
                int val2 = values.top(); 
                values.pop();
                int val1 = values.top();
                values.pop();
                char op = ops.top(); 
                ops.pop();
                values.push(applyOp(val1, val2, op));
            }
            ops.pop();
        } else {
            while(!ops.empty() && precedence(ops.top()) >= precedence(input[i])){
                int val2 = values.top(); 
                values.pop();
                int val1 = values.top(); 
                values.pop();
                char op = ops.top(); 
                ops.pop();
                values.push(applyOp(val1, val2, op));
            }
            ops.push(input[i]);
        }
    }
    while(!ops.empty()){
        int val2 = values.top(); 
        values.pop();
        int val1 = values.top(); 
        values.pop();
        char op = ops.top(); 
        ops.pop();
        values.push(applyOp(val1, val2, op));
    }
    std::cout << "The result of the Infix Expression is: " << values.top() << std::endl;
}

int main(){
    std::string infix_expression = "3 + 5 * ( 2 - 8 )";
    Evaluation_Of_Infix_Main(infix_expression);
    return 0;
}