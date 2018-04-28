#ifndef STACKCLASS_H
#define STACKCLASS_H

template <typename T>


class Stack {
private:
    const int sizeOfTheStack; // Size of the stack.
    int currentItemIndex; // Index of the current stack item.
public:
    Stack(int size) { // Initialize a class.
        sizeOfTheStack = size;
        currentItemIndex = 0;
        }


    void pushStackItem(int _inputValue) {
        // Pushing value to the stack.

    }

    void popStackItem() {
        // Popping item out of the stack.

    }

    int outputLastStackItem() { // Method that will be used to output last item of the stack.
        int _item = 0; // Last item of the stack
        return _item;
    }
}; // class


#endif // STACKCLASS_H
