#include <iostream>

int main()
{
    const int n = 5;
    std::string mas1[n] = { "lia", "copis", "antonio", "kris", "cool" };
    std::string mas2[n] = {};

    for (int i = 0; i < 5; i++)
    {
        std::string* u = &mas1[i];
        mas2[i] = *u;
    }

    std::cout << sizeof(&mas1[3]) << std::endl;
    std::cout << sizeof(mas1[3]) << std::endl;
}