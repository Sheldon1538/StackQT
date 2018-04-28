/*******************************************************
 * Copyright (C) 2018 Akchurin Konstantin <rfkao89@gmail.com>
 *
 * This file is part of stackLab1.
 *
 * stackLab1 can not be copied and/or distributed without the express
 * permission of Akchurin Konstantin
 *******************************************************/

#include "stack.h"
#include <iostream>
#include <QDebug>


    Stack::Stack() { // Initialize a class object.
        sizeOfTheStack = 10;
        currentItemIndex = 0;
        }


    void Stack::pushStackItem(int _inputValue) { // Pushing value to the stack.
        if (currentItemIndex < sizeOfTheStack) {
        stackArray[currentItemIndex] = _inputValue;
        currentItemIndex = currentItemIndex + 1;
        } else {
            qInfo("Stack is full!");
        }
    }

    int Stack::popStackItem() { // Popping item out of the stack. Returns popped value.
        int _returnValue = stackArray[0];
        for (int i = 0; i < sizeOfTheStack; i++) {
            stackArray[i] = stackArray[i+1];
        }
        currentItemIndex = currentItemIndex - 1;
        return _returnValue;
    }

    int Stack::outputLastStackItem() { // Method that will be used to output last item of the stack.
        int _item = stackArray[currentItemIndex-1]; // Last item of the stack.
        return _item;
    }

    bool Stack::checkIfEmpty() { // Check for empty array.
        bool _returnValue = false;
        if (currentItemIndex == 0) {
            _returnValue = true;
        }
        return _returnValue;
    }

    bool Stack::checkIfIntegers(QString _inputValue) { // Check for correct input.
        bool _returnValue = false;
        QRegExp dgCheck("\\d*");
        if (dgCheck.exactMatch(_inputValue)) {
            _returnValue = true;
        }
        return _returnValue;
    }

    Stack mainStack;
