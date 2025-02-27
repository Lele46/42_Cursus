#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <unistd.h>
#include <limits.h>

class Span
{
    private:
        unsigned int _size;
        std::vector<int> _v;
    public:
        Span();
        Span(unsigned int size);
        Span(const Span &span);
        ~Span();
        Span &operator=(const Span &span);
        void addNumber(int size);
        unsigned int shortestSpan();
        unsigned int longestSpan();
        void addTot(int call);

        class MaxSize : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return "Max size reached";
                }
        };
        class NotEnoughValues : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return "Not enough values";
                }
        };
        class VectorEmpty : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return "Vector is empty";
                }
        };
};

#endif
