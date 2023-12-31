#pragma once
#include <iostream>
//#include <concepts>
#include <memory>

template <class T>
//concept Arrayable = std::is_default_constructible<T>::value;
//template <Arrayable T>
class Array
{
public:
    Array() : _size(0), _array{nullptr} {}

    Array(const std::initializer_list<T> &t)
    {
        // std::cout << "Initializer list constructor" << std::endl;
        _array = std::shared_ptr<T[]>(new T[t.size()]);
        size_t i{0};
        for (auto &c : t)
            _array[i++] = c;
        _size = t.size();
    }

    Array(const Array &other)
    {
        // std::cout << "Copy constructor" << std::endl;
        _size = other._size;
        _array = std::shared_ptr<T[]>(new T[_size]);

        for (size_t i{0}; i < _size; ++i)
            _array[i] = other._array[i];
    }

    Array(Array &&other) noexcept
    {
        // std::cout << "Move constructor" << std::endl;
        _size = other._size;
        _array = other._array;

        other._size = 0;
        other._array = nullptr;
    }

    T& operator[](size_t index){
        if((index < 0) || (index >= _size)){
            throw std::logic_error("Invalid array index!");
        }
        return _array[index];
    }

    size_t size() const{
        return _size;
    }

    void remove(size_t index) {               //удаление элемента из массива
        if((index < 0) || (index >= this->_size)) {
            throw std::logic_error("Invalid array index!");
        }
        std::shared_ptr<T[]> new_array = std::shared_ptr<T[]>(new T[this->_size - 1]);
        int move = 0;
        for (size_t i = 0; i < _size; i++) {
            if(i == index) {
                move = 1;
                continue;
            }
            new_array[i - move] = _array[i];
        }
        this->_size--;
        this->_array = new_array;
    }

    ~Array() noexcept
    {
        // std::cout << "destructor:" << _array.use_count() << std::endl;
        if (_size > 0)
        {
            _size = 0;
            for (int i = 0; i < _size; i++) {
                delete _array[i].get();
            }
            
            // delete[] _array;
            _array = nullptr;
        }
    }

private:
    size_t _size;
    std::shared_ptr<T[]> _array;
};
