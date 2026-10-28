#ifndef RIWAYAT_PERUBAHAN_DOKUMEN_H
#define RIWAYAT_PERUBAHAN_DOKUMEN_H

#include <string>

struct Node {
    std::string data;
    Node* next;
};

struct Stack {
    Node* top;
};

Stack createStack();
bool isEmpty(const Stack& stack);
void push(Stack& stack, std::string data);
std::string pop(Stack& stack);
void printIsiStack(const Stack& stack);

#endif