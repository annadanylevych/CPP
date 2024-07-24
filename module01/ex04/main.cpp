#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Wrong number of parameters." <<std::endl;
        return (1);
    }
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    if(s1.empty() || s1.empty())
    {
        std::cerr << "Strings should not be empty!😡";
        return (1);
    }
    std::ifstream file(argv[1]);
    std::ofstream newFile(std::string(argv[1]) + ".replace");
    if (!file.is_open())
    {
        std::cerr << "Error opening the file." <<std::endl;
        return (1);
    }
    if (!newFile.is_open()) {
        std::cerr << "Error: Could not create file " << std::string(argv[1]) << ".replace" << std::endl;
        return (1);
    }
    std::string line;
    while (std::getline(file, line))
    {
        size_t  pos = 0;
        std::string res;
        while(1)
        {
            size_t start = line.find(s1, pos);
            if (start == std::string::npos)
                break;
            res += line.substr(pos, start - pos);
            res +=s2;
            pos = start + s1.length();
        }
        res += line.substr(pos);
        newFile << res << std::endl;
    }
    return (0);
}