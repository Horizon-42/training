#include <string>
#include <regex>
using namespace std;
std::string disemvowel(std::string str)
{
    std::regex pattern("[AaEeIiOoUu]", regex::icase);
    return regex_replace(str, pattern, "");
}