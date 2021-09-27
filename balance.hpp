#include <iostream>
#include <stack>
#include <sstream>

class chain{
public:
    bool verify();
    friend std::istream &operator>>(std::istream& ,chain&);
private:
    std::stack<char> chain_;
};