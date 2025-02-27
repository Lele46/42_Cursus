#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>

template <typename T>
class Array
{
    private:
        T *_array;
        size_t _size;
    public:
        Array() : _size(0) 
        {
            std::cout << "Empty array created" << std::endl;
            this->_array = new T[this->_size];
        }

        Array(unsigned int n) : _size(n)
        {
            int i = n;
            if (i < 0) {
                std::cerr << "Array size cannot be negative" << std::endl;
				throw Array<T>::OutOfLimits();
			}
			std::cout << "Array Unsigned int of size (" << n << ") created" << std::endl;
			this->_array = new T[this->_size];
        }

        Array(Array const &Data) : _size(Data._size)
        {
            std::cout << "Array copy created" << std::endl;
            this->_array = new T[this->_size];
            for (size_t i = 0; i < this->_size; ++i)
                this->_array[i] = Data._array[i];
        }

        Array &operator=(Array const &Data)
        {
            std::cout << "Array copy assigned" << std::endl;
            if (this->_array != NULL)
                delete[] this->array;
            if (this->size != 0)
            {
                this->_size = Data._size;
                this->array = new T[this->_size];
                for (size_t i = 0; i < this->_size; ++i)
                    this->array[i] = Data.array[i];
            }
            return *this;
        }

        ~Array()
        {
            std::cout << "Array destroyed" << std::endl;
            if (this->_array != NULL)
                delete[] this->_array;
        }

        T &operator[](size_t index)
        {
            if (index >= this->_size)
                throw Array<T>::OutOfLimits();
            return this->_array[index];
        }

        class OutOfLimits : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return "Out of limits";
                }
        };

        size_t size() const
        {
            return this->_size;
        }
};

#endif
