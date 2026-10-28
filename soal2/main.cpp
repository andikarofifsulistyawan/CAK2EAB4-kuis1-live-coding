#include <iostream>
#include <exception>
#include "riwayat_perubahan_dokumen.h"

int main() {
    Stack stackPerubahan = createStack();
    std::string perubahan;

    std::cout << "==== MENAMBAHKAN PERUBAHAN ====" << std::endl;
    for (int i = 1; i <= 5; i++) {
        std::cout << "Perubahan " << ": ";
        std::getline(std::cin, perubahan);
        push(stackPerubahan, perubahan);
    }
    std::cout << std::endl;
    printIsiStack(stackPerubahan);
    
    for (int i = 1; i <= 2; i++) {
        try {
            std::string perubahanYangDibatalkan = pop(stackPerubahan);
            std::cout << "Perubahan: '" << perubahanYangDibatalkan << "' dibatalkan" << std::endl;
        } catch (std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    std::cout << std::endl;
    printIsiStack(stackPerubahan);

    return 0;
}