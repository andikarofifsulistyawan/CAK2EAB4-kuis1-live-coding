#include <iostream>
#include <stdexcept>
#include <string>
#include "riwayat_perubahan_dokumen.h"

Stack createStack() {
    return {nullptr};
}
bool isEmpty(const Stack& stack) {
    return stack.top == nullptr;
}
void push(Stack& stack, std::string data) {
    stack.top = new Node{data, stack.top};
}
std::string pop(Stack& stack) {
    if (isEmpty(stack)) {
        throw std::underflow_error("Tidak bisa melakukan pop saat stack masih kosong");
    }

    Node* temp = stack.top;
    std::string data = temp->data;
    stack.top = stack.top->next;
    temp->next = nullptr;
    delete temp;
    return data;
}
void printIsiStack(const Stack& stack) {
    std::cout << "==== Perubahan yang Bisa Dibatalkan ====" << std::endl;
    if (isEmpty(stack)) {
        std::cout << "Stack perubahan kosong" << std::endl;
    } else {
        Node* currentNode = stack.top;
        while (currentNode != nullptr) {
            std::cout << "Perubahan " << ": " << currentNode->data << std::endl;
            currentNode = currentNode->next;
        }
        std::cout << std::endl;
    }
}