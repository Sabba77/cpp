#include <iostream>
#include <string>
#include <cctype>

static std::string toUppercase(const std::string &s)
{
    std::string out = s;

    for (std::string::size_type i = 0; i < out.size(); ++i)
    {
        // Buona pratica: cast a unsigned char prima di passare a toupper
        unsigned char c = static_cast<unsigned char>(out[i]);
        out[i] = static_cast<char>(std::toupper(c));
    }
    return out;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }

    for (int i = 1; i < argc; ++i)
    {
        std::cout << toUppercase(argv[i]);
        if (i + 1 < argc)
            std::cout << " ";
    }
    std::cout << std::endl;

    return 0;
}