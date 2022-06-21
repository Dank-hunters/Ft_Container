#include <iostream>
# include <list>
int main()
{
    std::list<std::string> bite;
    std::list<std::string>::iterator  it;
    bite.push_back("lol");
    bite.push_back("lal");
    bite.push_back("lswl");
    bite.push_back("lsl");
    it = rbegin(bite);
    std::cout << *it << std::endl;

}