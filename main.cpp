#include <iostream>
#include <ctype.h>
using namespace std;

//Stack Implementation

#define MAX 200

class Stack {
    int top;
 
    public:
        char a[MAX];
    
        Stack(){
        top = -1;
        }
        bool push(char x);
        char pop();
        char peek();
        bool isEmpty();
        int getSize();
};
 
bool Stack::push(char x){
    if (top >= (MAX - 1)) {
        return false;
    }
    else {
        a[++top] = x;
        return true;
    }
}
 
char Stack::pop(){
    if (top < 0) {
        return 0;
    }
    else {
        char x = a[top--];
        return x;
    }
}
char Stack::peek(){
    if (top < 0) {
        return 0;
    }
    else {
        char x = a[top];
        return x;
    }
}
 
bool Stack::isEmpty(){
    return (top < 0);
}

int Stack::getSize(){
  return top;
}

//custom function to check precedence
int precedence(char symbol){
	if(symbol == '^'){
		return(4);
	} else if(symbol == '*'){
		return(3);
	}
  else if(symbol == '/'){
		return(2);
	} else if(symbol == '+' || symbol == '-'){
		return(1);
	} else {
		return(0);
	}
}

//custom function to check op
bool is_op(char symbol){
	if(symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^'){
    return true;
	} else {
		return false;
	}
}


int main() {
  Stack stack;

  string input = "";
  cout<<"Enter Infix expression: ";
  cin>>input;
  string exp = "(";
  string result = "";

  //removing spaces and adding ')' at the end
  for(int i = 0; i<input.length(); i++){
    if(input[i] != ' '){
      exp+=input[i];
    }
  }

  exp += ')';

  //scanning
  for(int i = 0; i<exp.length(); i++){

    //checking alphabet or digit
    if(isalpha(exp[i]) || isdigit(exp[i])){
      result += exp[i];
    }

    //checking operators and their precedence
    else if(is_op(exp[i])) {
      if(precedence(exp[i]) < precedence(stack.peek())){
        result += stack.pop();
      }
      stack.push(exp[i]);
    }
    
    //checking '('
    else if(exp[i] == '(' || stack.peek() == '('){
      stack.push((int)exp[i]);
    }
    
    //checking ')'
    else if(exp[i] == ')'){
      for(int ii = 0; ii <= stack.getSize(); ii++){
        if(stack.peek() != '('){
          result += stack.pop();
        } else if(stack.peek() == '(') {
          stack.pop();
          break;
        }
      }
    }
  }

  //printing result
  cout << "Infix expression: " << input << endl;
  cout << "Postfix expression: " << result << endl;

  return 0;
}