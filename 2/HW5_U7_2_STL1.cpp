#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <utility>
#include <algorithm>

namespace data
{
    int Quntyty{};
    std::string text{};
    std::vector<std::pair<char, int>> quntyty{};
    std::set<int> q{};
    std::vector<int> RevQ{};
}



int main()
{
    std::cin >> data::Quntyty;
    for (int i = 0; i < data::Quntyty; ++i)
    {
        int buf{};
        std::cin >> buf;
        auto insert = data::q.insert(buf);
        if (insert.second) data::RevQ.push_back(*insert.first);
    }

    std::cout << std::endl;

    for (auto it = data::RevQ.rbegin(); it != data::RevQ.rend(); it++) std::cout << *it << std::endl;
        
    //std::cout << "Hello World!\n";
    return EXIT_SUCCESS;
}