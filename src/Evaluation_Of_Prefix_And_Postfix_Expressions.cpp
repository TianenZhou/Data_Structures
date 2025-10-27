#include <iostream>
#include <string>
#include <stack>


void Evaluation_Of_Prefix_Expressions_Main(std::string &input){
    std::stack<int> s;
    for(int i = input.length() - 1; i >= 0; i--){
        if(isdigit(input[i])){
            s.push(input[i] - '0');
            
        } else {
            int op1 = s.top(); s.pop();
            int op2 = s.top(); s.pop();
            switch(input[i]){
                case '+':
                    s.push(op1 + op2);
                    break;
                case '-':
                    s.push(op1 - op2);
                    break;
                case '*':
                    s.push(op1 * op2);
                    break;
                case '/':
                    s.push(op1 / op2);
                    break;
            }
        }
    }    std::cout << "The result of the Prefix Expression is: " << s.top() << std::endl;
};

void Evaluation_Of_Postfix_Expressions_Main(std::string &input){
    std::stack<int> s;
    for(int i = 0; i < input.length(); i++){
        if(isdigit(input[i])){
            s.push(input[i] - '0');
            
        } else {
            int op2 = s.top(); s.pop();
            int op1 = s.top(); s.pop();
            switch(input[i]){
                case '+':
                    s.push(op1 + op2);
                    break;
                case '-':
                    s.push(op1 - op2);
                    break;
                case '*':
                    s.push(op1 * op2);
                    break;
                case '/':
                    s.push(op1 / op2);
                    break;
            }
        }
    }    std::cout << "The result of the Postfix Expression is: " << s.top() << std::endl;
};

int main(){
    std::string prefix_expression = "*+23-45"; // Example Prefix Expression
    Evaluation_Of_Prefix_Expressions_Main(prefix_expression);
    std::string postfix_expression = "23+45-*"; // Example Postfix Expression
    Evaluation_Of_Postfix_Expressions_Main(postfix_expression);
    return 0;
}