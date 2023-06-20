#include <iostream>

class DataConverter
{
public:
    template <typename T>
    static void convert(T* source, T* destination, int size)
    {
        const long long* pointer1 = (const long long*)source;
        long long* t_pointer1 = (long long*)destination;
        int m = sizeof(T) * size / sizeof(long long);
        for (int i = 0; i < m; i++) {
            *(t_pointer1++) = *(pointer1++);
        }
        char* pointer2 = (char*)pointer1;
        char* t_pointer2 = (char*)t_pointer1;
        m = (sizeof(T) * size) % sizeof(long long);
        for (int i = 0; i < m; i++)
        {
            *(t_pointer2++) = *(pointer2++);
        }

    }
};

int main()
{
    const int n = 5;
    std::string mas1[n] = { "lia", "copis", "antonio", "kris", "cool" };
    std::string mas2[n] = {};
    DataConverter::convert(mas1, mas2, n);
    std::cout << "mas1: ";
    for (int i = 0; i < 5; i++)
    {
        std::cout << mas1[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "mas2: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << mas2[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}