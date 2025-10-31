// HW5_U7_STL1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <utility>
#include <algorithm>

namespace data 
{
    std::string text{}; 
    std::vector<std::pair<char, int>> quntyty{};
    std::unordered_map<char, int> q{};
}


bool cmp(std::pair<char, int>& a, std::pair<char, int>& b)
{
    return a.second > b.second;
}

void sort(std::unordered_map<char, int>& M)
{

    std::vector<std::pair<char, int>> A;

    for (const auto& it : M) {
        A.push_back(it);
    }

    std::sort(A.begin(), A.end(), cmp);

    for (auto& it : A) {

        std::cout << it.first << ' '
            << it.second << std::endl;
    }
}

int main()
{
    //std::cin >> data::text;
    data::text = { "Hello world!!" };


    for (int i = 0; i < data::text.size(); ++i)
    {
        //std::cout << data::text[i];
        if (data::text.find(data::text[i]) != std::string::npos) data::q[data::text[i]]+=1;
    }
    
    sort(data::q);

    //std::cout << "Hello World!\n";
    return EXIT_SUCCESS;
}