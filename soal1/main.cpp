#include <iostream>
#include <exception>
#include "pesanan_kantin.h"

int main() {
    Queue queuePesanan = createQueue();
    Pesanan pesanan;

    std::cout << "==== MEMBUAT PESANAN ====" << std::endl;
    for (int i = 1; i <= 5; i++) {
        std::cout << "Pesanan " << i << ": " << std::endl;
        
        std::cout << "Nomor pesanan: ";
        std::cin >> pesanan.nomorPesanan;
        std::cin.ignore();
        
        std::cout << "Nama menu: ";
        std::getline(std::cin, pesanan.namaMenu);
        
        std::cout << std::endl;
        enqueuePesanan(queuePesanan, pesanan);
    }
    printIsiQueue(queuePesanan);
    
    std::cout << "==== MENYELESAIKAN DUA PESANAN ====" << std::endl;
    for (int i = 1; i <= 2; i++) {
        try {
            Pesanan pesananYangDiDequeue = dequeuePesanan(queuePesanan);
            std::cout << "Pesanan nomor " << pesananYangDiDequeue.nomorPesanan << " sudah selesai" << std::endl;
        } catch (std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    std::cout << std::endl;
    
    std::cout << "==== MENAMBAH SATU PESANAN ====" << std::endl;    
    std::cout << "Nomor pesanan: ";
    std::cin >> pesanan.nomorPesanan;
    std::cin.ignore();
    
    std::cout << "Nama menu: ";
    std::getline(std::cin, pesanan.namaMenu);
    
    std::cout << std::endl;
    
    enqueuePesanan(queuePesanan, pesanan);
    printIsiQueue(queuePesanan);

    return 0;
}