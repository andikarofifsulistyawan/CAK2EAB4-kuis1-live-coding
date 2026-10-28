#include <iostream>
#include <stdexcept>
#include "pesanan_kantin.h"

Queue createQueue() {
    return {nullptr, nullptr};
}
bool isEmpty(const Queue& queue) {
    return queue.first == nullptr;
}
void enqueuePesanan(Queue& queue, Pesanan pesanan) {
    Node* newNode = new Node{pesanan, nullptr};

    if (isEmpty(queue)) {
        queue.first = newNode;
        queue.rear = newNode;
    } else {
        queue.rear->next = newNode;
        queue.rear = newNode;
    }
}
Pesanan dequeuePesanan(Queue& queue) {
    if (isEmpty(queue)) {
        throw std::underflow_error("Tidak bisa melakukan dequeue saat queue masih kosong");
    }

    Node* temp = queue.first;
    Pesanan pesanan = temp->data;
    queue.first = queue.first->next;
    if (queue.first == nullptr) {
        queue.rear = nullptr;
    }
    temp->next = nullptr;
    delete temp;
    return pesanan;
}
void printIsiQueue(const Queue& queue) {
    std::cout << "==== Pesanan yang sedang Menunggu ====" << std::endl;
    if (isEmpty(queue)) {
        std::cout << "Queue pesanan kosong" << std::endl;
    } else {
        Node* currentNode = queue.first;
        while (currentNode != nullptr) {
            std::cout << "Nomor pesanan: " << currentNode->data.nomorPesanan << std::endl;
            std::cout << "Nama menu: " << currentNode->data.namaMenu << std::endl;
            std::cout << std::endl;
            currentNode = currentNode->next;
        }
    }
}
