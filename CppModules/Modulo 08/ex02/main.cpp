#include "MutantStack.hpp"

int main()
{
    std::cout << "\n<<---- Test MutantStack int ---->>\n" << std::endl;

    MutantStack<int> mstack;

    std::cout << ">> Push 5, 17" << std::endl;
    mstack.push(5);
    mstack.push(17);

    std::cout << "Size: " << mstack.size() << std::endl;
    std::cout << "Top: " << mstack.top() << std::endl;

    std::cout << ">> Test Pop" << std::endl;
    mstack.pop();
    std::cout << "Top: " << mstack.top() << std::endl;

    std::cout << ">> Push other numbers: 3-5-737" << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    std::cout << ">> test iterator increase" << std::endl;
    std::cout << "Before ++: " << *it << std::endl;
    ++it;
    std::cout << "After ++: " << *it << std::endl;
    --it;
    std::cout << ">> Print stack" << std::endl;
    int index = 0;
    while (it != ite)
    {
        std::cout << index << " >> " << *it << std::endl;
        ++it;
        index++;
    }
    std::stack<int> s(mstack);
    std::cout << "\n<<---- Test MutantStack string ---->>\n" << std::endl;
    MutantStack<std::string> mstack2;
    mstack2.push("Hello");
    mstack2.push("World");
    mstack2.push("Ciao");
    mstack2.push("Mondo");

    MutantStack<std::string>::iterator it_str = mstack2.begin();
    MutantStack<std::string>::iterator ite_str = mstack2.end();

    ++it;
    --it;
    std::cout << ">> Print stack" << std::endl;
    index = 0;
    while (it_str != ite_str)
    {
        std::cout << index << " >> " << *it_str << std::endl;
        ++it_str;
        index++;
    }
    std::cout << "Size: " << mstack2.size() << std::endl;
    std::cout << "Top: " << mstack2.top() << std::endl;

    std::cout << ">> Test Pop" << std::endl;
    mstack2.pop();
    std::cout << "Top: " << mstack2.top() << std::endl;
    return 0;
}