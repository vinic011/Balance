#include "balance.hpp"

int main()
{
    chain s;
    std::cin >> s;
    if(s.verify() == true)
        std::cout << "OK"<<"\n";
    else
        std::cout << "ERR"<<"\n";
}