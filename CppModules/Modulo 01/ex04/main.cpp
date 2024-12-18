#include <iostream>
#include <string>
#include <fstream>

int string_replace (const std::string& filename, const std::string& tofind, const std::string& replace)
{
    std::string newfile = filename + ".replace";
    std::ifstream infile(filename.c_str());
    if (!infile.is_open())
    {
        std::cout << "File not found" << std::endl;
        return 1;
    }
    std::ofstream outfile(newfile.c_str());
    if (!outfile.is_open())
    {
        std::cout << "File copy not found" << std::endl;
        infile.close();
        return 1;
    }
    std::string line;
    while (std::getline(infile, line))
    {
        std::string newline;
        size_t pos = 0;
        size_t found;
        while ((found = line.find(tofind, pos)) != std::string::npos)
        {
            newline += line.substr(pos, found - pos);
            newline += replace;
            pos = found + tofind.length();
        }
        newline += line.substr(pos);
        outfile << newline << std::endl;
    }
    infile.close();
    outfile.close();
    return 0;
}

int main(int argc, char **argv)
{
    std::string newfile;
    if (argc != 4)
    {
        std::cout << "Wrong number of arguments" << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    std::string tofind = argv[2];
    std::string replace = argv[3];
    string_replace(filename, tofind, replace);
}