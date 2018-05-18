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
        int stackArray[10]; // Representing stack as an array.
        int currentProgramMode; // Current program mode. 0 - stack, 1 - queue.
        QString modsArray[2]; // List of program mods.
    public:
        Stack(); // Initialize a class.

        void pushStackItem(int _inputValue);  // Pushing value to the stack.

        int popStackItem(); // Popping item out of the stack. Returns popped value.

        int outputLastStackItem(); // Method that will be used to output last item of the stack.

        bool checkIfEmpty(); // Returns true if stack is emoty.

        bool checkIfIntegers(QString _inputValue); // Returns true if there is an integer value in input field.

        int checkCurrentMode(); // Returns 0 if current mode stack; returns 1 if current mode - queue.

        void setCurrentMode(int _programType); // Set new program mode, 0 - stack, 1 - queue.

        QString getStringMode(int _index); // Get name of the mode.

        void resetData(); // Reset data when the mode is changed.

}; // stack class

extern Stack mainStack;

#endif // STACK_H
