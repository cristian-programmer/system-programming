
#include <iostream>
#include <stdbool.h>

template <typename T>
struct Stack {
    T value;
    struct Stack *next;
};

typedef struct Stack<char> stack;

template <typename T>
void push(stack **top, T value){
   
   stack *node = new stack();
   node->next = *top;
   *top = node;
   node->value = value;
}

stack* pop(stack **top){
    stack *temp =  *top;
    *top = temp->next;
    temp->next = nullptr;
    delete temp;
    return *top;
}

template <typename T>
T peek (stack *top){
    return top->value;
}

bool isEmpty(stack *top){
    return top == nullptr;
}


int main(){
    stack *top = nullptr;
    bool sw = false;
    push<char>(&top, '1');
    pop(&top);

    std::cout << "Termina aqui";
    const char *expression = "(8-4)";
    for(int i=0; expression[i]!= '\0' && sw == false; i++){
        std::cout << expression[i] << "\n";
        if(expression[i] == '(' || expression[i] == '[' || expression[i] == '{'){
            push<char>(&top, expression[i]);
        }else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}'){
            if(!isEmpty(top)){
                stack *s  = nullptr;
                s = pop(&top);
                std::cout <<"char" <<  expression[i];
                if(expression[i] == ')' && s->value != '(' ) sw = true;
                //if(expression[i] == ']' && s->value != '[' ) sw = true;
                //if(expression[i] == '}' && s->value != '{' ) sw = true; 
                //s->next = nullptr;
                //delete s;
            }
           
        }
    }
/*
    if(isEmpty(top) && sw == false){
        std::cout << "Sintaxis correcta";
    }else {
        std::cout << "Error de sintaxis";
    }
    */

    return 0;
}