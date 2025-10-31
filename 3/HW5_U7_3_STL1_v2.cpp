// Для лучшего понимания работы std::vector в этом задании вам нужно написать собственную шаблонную упрощённую реализацию std::vector.
// У вашего контейнера должны работать функции :

// at(int index) — доступ к элементу контейнера по индексу;
// push_back(T value) — размер контейнера неизвестен заранее, вам нужно правильно увеличивать выделенную память;
// size() — количество элементов в контейнере;
// capacity() — количество элементов, которое может вместить контейнер до нового выделения памяти.

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

template <typename T>
class Vector
{
private:
public:
    T* vec{ nullptr };
    int size{ 0 };
    int capasity{ 0 };

    void copyVector(const Vector& other)
    {
        capasity = other.capasity;
        size = other.size();
        vec = new T[capasity];
        for (int i= 0; i < size; ++i)
        {
            vec[i] = other.vec[i];
        }
    }
    void freeArray() { delete[] vec; }
public:
    explicit Vector(int init_capasity) :capasity(init_capasity), size(0) {
        vec = new T[capasity];
    }
    Vector() = default;
    Vector(const Vector& other) { copyVector(other); }

    Vector& operator =(const Vector& other)
    {
        if (this != &other)
        {
            freeArray();
            copyVector(other);
        }
        return *this;
    }

    void push_back(T v)
    {
        if (size >= capasity) reserve(capasity == 0 ? 1 : capasity * 2);
        vec[size] = v;
        ++size;
    }

    void reserve(int capasity_init)
    {
        capasity = capasity_init;
        T* new_vec = new T[capasity_init];
        for (int i = 0; i < size; ++i) new_vec[i] = vec[i];
        vec = new_vec;
    }

    int Size()
    {
        return size;
    }

    int Capasity()
    {
        return capasity;
    }

    T at(int index)
    {
        if (index <= size)return vec[index];
        else throw std::out_of_range("Index out of range");
    }
};


int main()
{
    Vector<int> v1{ 1 };
    v1.push_back(5);
    v1.push_back(4);
    v1.push_back(3);
    v1.push_back(2);
    v1.push_back(1);
    v1.push_back(0);
    v1.push_back(-1);
    v1.push_back(-2);
    v1.push_back(-3);
    std::cout << "One" << v1.vec[0] << "; Two " << v1.vec[1] << "; Three " << v1.vec[2] << "; Four " << v1.vec[3] << "; Five " << v1.vec[4] << "; Six " << v1.vec[5]\
        << "; Seven " << v1.vec[6] << "; Eght " << v1.vec[7]<< "; Nine " << v1.vec[8] << std::endl;

    std::cout << "Size " << v1.Size() << std::endl;
    std::cout << "Capasity " << v1.Capasity() << std::endl;
    try
    {
        //std::cout << "At " << v1.at(1) << '\t' << v1.at(40) << std::endl;
        std::cout << "At " << v1.at(1) << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what();
    }
    return EXIT_SUCCESS;
}
