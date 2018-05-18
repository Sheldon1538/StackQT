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
        currentProgramMode = 0;
        modsArray[0] = "Stack";
        modsArray[1] = "Queue";
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
        int _returnValue;
        switch (currentProgramMode) {
        case 0: {
            _returnValue = stackArray[currentItemIndex-1];
            stackArray[currentItemIndex-1] = 0;
            currentItemIndex = currentItemIndex - 1;
            break;
        }

        case 1: {
            _returnValue = stackArray[0];
            for (int i = 0; i < sizeOfTheStack; i++) {
                stackArray[i] = stackArray[i+1];
            }
            currentItemIndex = currentItemIndex - 1;
            break;
        }

        default: {
            break;
        }
        }
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

    int Stack::checkCurrentMode() { // Returns 0 if current mode stack; returns 1 if current mode - queue.
        return currentProgramMode;
    }

    void Stack::setCurrentMode(int _programType) { // Set new program mode, 0 - stack, 1 - queue.
        if ((_programType == 0) || (_programType == 1)) {
             currentProgramMode = _programType;
        } else {
            qDebug("Invalid data.");
        }
    }

    QString Stack::getStringMode(int _index) {
        return modsArray[_index];
    }

    void Stack::resetData() {
        currentItemIndex = 0;
    }

    Stack mainStack;
