#include "Serializer.hpp"
#include <iostream>

int main() {
    Data d;
    d.index = 42;
    d.serialNumber = 123456;
    d.coefficient = 3.14159;
    std::cout << "Original Data object:" << std::endl;
    std::cout << "  address      : " << &d << std::endl;
    std::cout << "  index        : " << d.index << std::endl;
    std::cout << "  serialNumber : " << d.serialNumber << std::endl;
    std::cout << "  coefficient  : " << d.coefficient << std::endl;
    uintptr_t raw = Serializer::serialize(&d);
    std::cout << "\nSerialized value (uintptr_t): " << raw << std::endl;
    Data* restored = Serializer::deserialize(raw);
    std::cout << "\nRestored Data object:" << std::endl;
    std::cout << "  address      : " << restored << std::endl;
    std::cout << "  index        : " << restored->index << std::endl;
    std::cout << "  serialNumber : " << restored->serialNumber << std::endl;
    std::cout << "  coefficient  : " << restored->coefficient << std::endl;
    if (restored == &d)
        std::cout << "\n✅ Success: pointers match!" << std::endl;
    else
        std::cout << "\n❌ Error: pointers do not match!" << std::endl;

    return 0;
}
