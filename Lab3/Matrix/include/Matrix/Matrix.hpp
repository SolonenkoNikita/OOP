#ifndef _MATRIX_HPP_
#define _MATRIX_HPP_

#include <vector>
#include <iterator>
#include <cstddef>

#include <MyVector/MyVector.hpp>

template<typename T, bool is_const>
class Iterator
{
public:
    using iterator_category = std::random_access_iterator_tag;

    using difference_type = std::ptrdiff_t;

    using value_type = T;

    friend Iterator<T, !is_const>;

    typedef std::conditional_t<is_const, const T, T>& reference;

    typedef std::conditional_t<is_const, const T, T>* pointer;
    
    using line = std::vector<T>*;

private:
    line line_ptr_;

    pointer ptr_;

    void moving_on_the_left()
    {
        if (ptr_ == line_ptr_->begin())
        {
            line_ptr_--;
            ptr_ = line_ptr_->end();
        }
        line_ptr_--;
    }

    void moving_on_the_right()
    {
        ptr_++;
        if (ptr_ == line_ptr_->end())
        {
            line_ptr_++;
            ptr_ = line_ptr_->begin();
        }
    }

public:

    Iterator() = default;

    Iterator(pointer p, line l) : ptr_(p), line_ptr_(l) {};

    template<bool another> 
    Iterator(Iterator<T, another>& it) noexcept: ptr_(it.ptr_), line_ptr_(it.line_ptr_) {};

    template<bool another>
    Iterator(Iterator<T, another>&& it) noexcept
    {
        ptr_ = it.ptr_;
        line_ptr_ = it.line_ptr_;
        it.ptr_ = nullptr;
        it.line_ptr_ = nullptr;
    }

    template<bool another>
    Iterator& operator=(Iterator<T, another>& it) noexcept
    {
        line_ptr_ = it.line_ptr_;
        ptr_ = it.ptr_;
        return *this;
    }

    template<bool another>
    Iterator& operator=(Iterator<T, another>&& it) noexcept
    {
        line_ptr_ = it.line_ptr_;
        ptr_ = it.ptr_;
        it.ptr_ = nullptr;
        it.line_ptr_ = nullptr;
        return *this;
    }

    template<bool another>
    bool operator==(const Iterator<T, another>& it) const noexcept
    {
        return (ptr_ == it.ptr_);
    }

    template<bool another>
    bool operator!=(const Iterator<T, another>& it) const noexcept
    {
        return (ptr_ != it.ptr_);
    }

    reference operator[](size_t index)
    {
        return *(this + index);
    }

    pointer operator->() noexcept
    {
        return ptr_;
    }

    reference operator*() noexcept
    {
        return *ptr_;
    }

    Iterator& operator++() noexcept
    {
        moving_on_the_right();
        return *this;
    }

    Iterator operator++(int)
    {
        Iterator it = *this;
        moving_on_the_right();
        return it;
    }

    Iterator& operator--() noexcept
    {
        moving_on_the_left();
        return *this;
    }

    Iterator operator --(int)
    {
        Iterator it = *this;
        moving_on_the_left();
        return it;
    }
};

template<typename T>
class Matrix
{
private:
	std::vector<std::vector<T>> data_;

public:

    typedef Iterator<T, true> const_iterator;

    typedef Iterator<T, false> iterator;

    iterator begin()
    {
        return iterator(data_.begin()->begin(), data_.begin());
    }

    iterator end()
    {
        return iterator(data_.end()->begin(), data_.end());
    }

    const_iterator cbegin() const
    {
        return const_iterator(data_.begin()->begin(), data_.begin());
    }
    const_iterator cend() const
    {
        return const_iterator(data_.end()->begin(), data_.end());
    }

    Matrix(size_t colomns, size_t lines)
    {
        for (size_t i = 0; i < lines; i++)
        {
            data_.emplace_back(lines);
            for (size_t j = 0; j < colomns; j++)
            {
                data_[i].emplace_back();
            }
        }
    }

    Matrix(const Matrix& other) = default;

    Matrix(Matrix&& other) = default;

    Matrix& operator=(const Matrix& other) = default;

    Matrix& operator=(Matrix&& other) = default;

    std::vector<T>& operator[](size_t i)
    {
        return  data_[i];
    }

    const std::vector<T>& operator[](size_t i) const
    {
        return  data_[i];
    }

    T& at(size_t i, size_t j)
    {
        if (i > data_.size() || j > data_[i].size())
        {
            throw std::runtime_error("Segmentation fault\n");
        }
        return data_[i][j];
    }

    const T& at(size_t i, size_t j) const
    {
        if (i > data_.size() || j > data_[i].size())
        {
            throw std::runtime_error("Segmentation fault\n");
        }
        return data_[i][j];
    }
    
    size_t size_matrix() const
    {
        return data_.size();
    }

    size_t size_line() const
    {
        return data_.size() > 0 ? data_[0].size() : 0ull;
    }

};

#endif