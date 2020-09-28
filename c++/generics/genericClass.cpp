#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

using namespace std;

template <class T> 
class Stack {
    private: 
        vector<T> elements;

    public:
        void push(T const&);
        void pop();
        T top() const;
        bool empty() const {
            return elements.empty();
        }
};

template <class T>
void Stack<T>::push(T const& element){
    this->elements.push_back(element);
}

template <class T>
void Stack<T>::pop(){
    if(this->elements.empty())
        throw out_of_range("Stact<T>::pop(): empty stack");
    this->elements.pop_back();
}

template <class T>
T Stack<T>::top() const{
    if(this->elements.empty())
        throw out_of_range("Stact<T>::top(): empty stack");
    return this->elements.back();
}

int main(){
    try {
        Stack<int> intStack;
        Stack<string> stringStack;

        intStack.push(7);
        cout << intStack.top() <<endl;

        stringStack.push("Test Stack");
        cout << stringStack.top() << endl;
        stringStack.pop();
        stringStack.pop();
        
    } catch (exception const& ex)
    {
        cerr << "Exception: " << ex.what() << endl;
        return -1;
    }
}