#include <iostream>

int main()
{
    int age = 10;

    std::cout << "Value:   " << age << '\n';
    std::cout << "Address: " << &age << '\n';
    std::cout << "Size:    " << sizeof(age) << " bytes\n";

    age = 2000;

    std::cout << "\nAfter changing age:\n";
    std::cout << "Value:   " << age << '\n';
    std::cout << "Address: " << &age << '\n';

    return 0;
}
