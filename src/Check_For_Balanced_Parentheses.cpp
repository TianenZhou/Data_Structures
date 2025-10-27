//(),[],{} are balanced or not

/*Using stack to check
count of opening == count of closing
special: )(  ({)}
last unclosed, first closed*/

#include <iostream>
#include <stack>
#include <string>

bool areParenthesesBalanced(const std::string& expr) {
    std::stack<char> s;
    for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty()) {
                return false; // No matching opening bracket
            }
            char top = s.top();
            s.pop();
            if ((ch == ')' && top != '(') || (ch == '}' && top != '{') || (ch == ']' && top != '[')) {
                return false; // Mismatched pair
            }
        }
    }
    return s.empty(); // If stack is empty, all parentheses were balanced
}

int main() {
    std::string expression;
    std::cout << "Enter an expression with parentheses: ";
    std::getline(std::cin, expression);

    if (areParenthesesBalanced(expression)) {
        std::cout << "The parentheses are balanced." << std::endl;
    } else {
        std::cout << "The parentheses are not balanced." << std::endl;
    }

    return 0;
}