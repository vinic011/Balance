#include "balance.hpp"

bool chain::verify()
{
    if (!chain_.empty())
    {
        const auto x = chain_.top();
        for (char c : {'(', '[', '{',')',']','}'})
        {
            if (x == c)
                return false;
        }
    }
    return true;
}

std::istream &operator>>(std::istream &is, chain &a)
{
    std::string line;
    std::getline(is, line);
    auto ss = std::stringstream{line};
    char c;
    while (ss >> c)
    {
        if (c == '(' || c == '[' || c == '{')
            a.chain_.push(c);
    
        else if(!a.chain_.empty())
        {
            if (a.chain_.top() == '(' && c == ')')
                a.chain_.pop();
            else if (a.chain_.top() == '(' && c == ']')
                return is;
            else if (a.chain_.top() == '(' && c == '}')
                return is;

            else if (a.chain_.top() == '[' && c == ']')
                a.chain_.pop();
            else if (a.chain_.top() == '[' && c == '}')
                return is;
            else if (a.chain_.top() == '[' && c == ')')
                return is;

            else if (a.chain_.top() == '{' && c == '}')
                a.chain_.pop();
            else if (a.chain_.top() == '{' && c == ']')
                return is;
            else if (a.chain_.top() == '{' && c == ')')
                return is;
        }
        else if(a.chain_.empty())
        {
            if(c == ')' || c == ']' || c == '}')
            {
                a.chain_.push(c);
                return is;
            }
        }
    }
    return is;
}