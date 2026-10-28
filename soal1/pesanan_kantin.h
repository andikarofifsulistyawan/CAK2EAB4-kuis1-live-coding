#ifndef PESANAN_KANTIN_H
#define PESANAN_KANTIN_H

#include <string>

struct Pesanan {
    std::string nomorPesanan;
    std::string namaMenu;
};

struct Node {
    Pesanan data;
    Node* next;
};

struct Queue {
    Node* first;
    Node* rear;
};

Queue createQueue();
bool isEmpty(const Queue& queue);
void enqueuePesanan(Queue& queue, Pesanan pesanan);
Pesanan dequeuePesanan(Queue& queue);
void printIsiQueue(const Queue& queue);

#endif