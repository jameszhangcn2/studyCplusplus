#include <iostream>

void f()
{
    int a[2] = {1, 0};
    int b = a[5];
    int* test = (int*)malloc(100);
    std::cout << b << std::endl;
}

int main()
{
    f();
    return 0;
}
