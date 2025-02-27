#include "Span.hpp"

int main()
{
    std::cout << "\n---- Test with 5 numbers ----\n" << std::endl;
    Span s(5);
    try
    {
        s.addNumber(10);
        s.addNumber(25);
        s.addNumber(5);
        s.addNumber(11);
        s.addNumber(25);
        //s.addNumber(77);
    }
    catch (const Span::MaxSize &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "pushed 5 values: 10-25-5-11-25" << std::endl;
    try
    {
        s.shortestSpan();
        std::cout << "Shortest span: " << s.shortestSpan() << std::endl;
    }
    catch (const Span::NotEnoughValues &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (const Span::VectorEmpty &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        s.longestSpan();
        std::cout << "Longest span: " << s.longestSpan() << std::endl;
    }
    catch(const Span::NotEnoughValues &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (const Span::VectorEmpty &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "\n---- Test with 10000 numbers ----\n" << std::endl;
    Span s2(10000);
    try
    {
        s2.addTot(10000);
    }
    catch (const Span::MaxSize &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        s2.shortestSpan();
        std::cout << "Shortest span: " << s2.shortestSpan() << std::endl;
    }
    catch (const Span::NotEnoughValues &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (const Span::VectorEmpty &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        s2.longestSpan();
        std::cout << "Longest span: " << s2.longestSpan() << std::endl;
    }
    catch(const Span::NotEnoughValues &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (const Span::VectorEmpty &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}