#include "Array.hpp"
#include <cstdlib>

int main()
{

    std::cout << "\n---- Empty array ----\n" << std::endl;
    Array<int> emptyArray;
    std::cout << "intArray = " << emptyArray.size() << std::endl;

    std::cout << "\n---- Array of 5 ----\n" << std::endl;
    try 
	{
        Array<int> intArray(5);
        for (size_t i = 0; i < intArray.size(); ++i)
                intArray[i] = (rand() % 6) + 1;
        std::cout << "intArray = " << intArray.size() << std::endl;
        for (size_t i = 0; i < intArray.size(); ++i)
            std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;

        std::cout << "\n---- Test *a() ----\n" << std::endl;
        int *a = new int();
        std::cout << "Value of *a(): " << *a << std::endl;
        delete a;
        std::cout << "\n---- Array copy and modifying data ----\n" << std::endl;
        Array<int> intArrayCopy(intArray);
        for (size_t i = 0; i < intArrayCopy.size(); ++i)
            intArrayCopy[i] = 1;
        std::cout << "\n---- Setting ArrayCopy values ----\n" << std::endl;
        for (size_t i = 0; i < intArray.size(); ++i)
            std::cout << "intArrayOriginal[" << i << "] = " << intArray[i] << std::endl;
        for (size_t i = 0; i < intArrayCopy.size(); ++i)
            std::cout << "intArrayCopy[" << i << "] = " << intArrayCopy[i] << std::endl;

        std::cout << "\n---- Array copyOperator and modifying data ----\n" << std::endl;
        Array<int> intArrayCopyOperator(intArray);
        for (size_t i = 0; i < intArrayCopyOperator.size(); ++i)
            intArrayCopyOperator[i] = 1;
        std::cout << "\n---- Setting ArrayCopyOperator values ----\n" << std::endl;
        for (size_t i = 0; i < intArray.size(); ++i)
            std::cout << "intArrayOriginal[" << i << "] = " << intArray[i] << std::endl;
        for (size_t i = 0; i < intArrayCopyOperator.size(); ++i)
            std::cout << "intArrayCopyOperator[" << i << "] = " << intArrayCopyOperator[i] << std::endl;

        std::cout << "\n---- Out of limits Test ----\n" << std::endl;
        try
        {
            for (size_t i = 0; i < intArray.size() + 1; ++i)
                std::cout << "intArrayOriginal[" << i << "] = " << intArray[i] << std::endl;
        }
        catch (const Array<int>::OutOfLimits &e)
        {
            std::cerr << e.what() << std::endl;
        }

        std::cout << "\n---- Destroying Arrays ----\n" << std::endl;
    }
    catch (const Array<int>::OutOfLimits &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}