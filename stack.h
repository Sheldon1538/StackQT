/*******************************************************
 * Copyright (C) 2018 Akchurin Konstantin <rfkao89@gmail.com>
 *
 * This file is part of stackLab1.
 *
 * stackLab1 can not be copied and/or distributed without the express
 * permission of Akchurin Konstantin
 *******************************************************/

#ifndef STACK_H
#define STACK_H
#include <QDebug>


class Stack
{
    private:
        int sizeOfTheStack; // Size of the stack.
        int currentItemIndex; // Index of the current stack item.
        int stackArray[10]; // Representing queue as an array.
    public:
        Stack(); // Initialize a class.

        void pushStackItem(int _inputValue);  // Pushing value to the stack.

        int popStackItem(); // Popping item out of the stack. Returns popped value.

        int outputLastStackItem(); // Method that will be used to output last item of the stack.

        bool checkIfEmpty(); // Returns true if stack is emoty.

        bool checkIfIntegers(QString _inputValue); // Returns true if there is an integer value in input field.

}; // stack class

extern Stack mainStack;

#endif // STACK_H
