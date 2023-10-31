#ifndef _MyVector_HPP_
#define _MyVector_HPP_

#include <iostream>
#include <type_traits>
#include <algorithm>

template <typename T>
class MyVector
{
private:
	T* data_;
	size_t size_;
	size_t capacity_;
public:

	using iterator = T*;

	using const_iterator = const T*;

	explicit MyVector() noexcept: size_(0), capacity_(1)
	{
		data_ = reinterpret_cast<T*>(new char[1 * sizeof(T)]);
	};

	explicit MyVector(size_t count)noexcept : capacity_(count * 2), size_(count)
	{
		data_ = reinterpret_cast<T*>(new char[(count * 2) * sizeof(T)]);
	}

	MyVector(size_t count, const T& value) : MyVector(count)
	{
		for (iterator i = begin(); i != end(); i++)
		{
			*i = value;
		}
	}

	MyVector(const std::initializer_list<T>& l) : capacity_(l.size() * 2), size_(l.size())
	{
		data_ = reinterpret_cast<T*>(new char[(l.size() * 2) * sizeof(T)]);
		std::uninitialized_copy(l.begin(), l.end(), data_);
	};

	MyVector(const MyVector<T>& v)
	{
		try
		{
			data_ = reinterpret_cast<T*>(new char[(v.size() * 2) * sizeof(T)]);
		}
		catch (...)
		{
			size_ = 0;
			capacity_ = 0;
			delete[] reinterpret_cast<char*>(data_);
			throw;
		}
		size_ = v.size_;
		capacity_ = v.capacity_;
		std::uninitialized_copy(v.data_, v.data_ + size_,data_);
	}

	MyVector& operator = (const MyVector<T>& v)
	{
		if (this != &v)
		{
			T* new_data = reinterpret_cast<T*>(new char[v.size() * sizeof(T)]);
			try
			{
				std::uninitialized_copy(v.data_, v.data_ + v.size_, new_data);
			}
			catch (...)
			{
				delete[] reinterpret_cast<char*>(new_data);
				throw;
			}
			for (size_t j = 0; j < size_; j++)
			{
				(data_ + j)->~T();
			}
			delete[] reinterpret_cast<char*>(data_);
			size_ = v.size_;
			capacity_ = v.capacity_;
			data_ = new_data;
		}
		return *this;
	}

	MyVector(MyVector<T>&& v) noexcept : size_(v.size()), capacity_(v.capacity()), data_(v.data_)
	{
		v.capacity_ = 0;
		v.size_ = 0;
		v.data_ = nullptr;
	}

	MyVector& operator =(MyVector<T>&& v) noexcept
	{
		size_ = v.size_;
		capacity_ = v.capacity_;
		deallocate();
		data_ = v.data_;
		v.capacity_ = 0;
		v.size_ = 0;
		v.data_ = nullptr;
		return *this;
	}

	~MyVector()
	{
		clear();
		deallocate();
	}
	
	void deallocate()
	{
		delete[] reinterpret_cast<char*>(data_);
		data_ = nullptr;
	}

	void clear() noexcept
	{
		for (std::size_t i = 0; i < size_; i++) {
			data_[i].~T();
		}
		size_ = 0;
	}

	constexpr size_t size() const noexcept
	{
		return size_;
	}

	constexpr size_t capacity() const noexcept
	{
		return capacity_;
	}

	void reserve(size_t n)
	{
		if (n <= capacity_) return;
		T* new_data = reinterpret_cast<T*>(new char[n * sizeof(T)]);
		try
		{
			std::uninitialized_copy(data_, data_ + size_, new_data);
		}
		catch (...)
		{
			delete[] reinterpret_cast<char*>(new_data);
			throw;
		}
		for (size_t k = 0; k < size_; ++k)
		{
			(data_ + k)->~T();
		}
		delete[] reinterpret_cast<char*>(data_);
		data_ = new_data;
		capacity_ = n;
	}

	void resize(size_t n, const T& value = T())
	{
		if (n > capacity_) reserve(n);
		size_t i = size_;
		try
		{
			for (; i < n; i++)
			{
				new(data_ + i) T(value); 
			}
		}
		catch (...)
		{
			for (size_t j = 0; j < i; j++)
			{
				(data_ + i)->~T();
			}
			delete[] reinterpret_cast<char*>(data_);
			throw;
		}
		if (n < size_)
		{
			size_ = n;
		}
	}

	void push_back(const T& value) 
	{
		if (capacity_ == size_)
		{
			reserve(2 * size_);
		}
		new(data_ + size_) T(value);
		++size_;
	}

	void pop_back()
	{
		(data_ + size_)->~T();
		size_--;
	}

	void insert(const int index, const T& value)
	{
		if (index >= size_ || index < 0)
		{
			throw std::runtime_error("Segmentation Fault\n");
		}
		if (size_ == capacity_)
		{
			reserve(capacity_ * 2);
		}
		new(data_ + size_) T(value);
		for (size_t i = size_; i > index; i--)
		{
			my_swap(data_[i], data_[i - 1]);
		}
		++size_;
	}

	void my_swap(T& one, T& two)
	{
		T t = std::move(one);
		one = std::move(two);
		two = std::move(t);
	}

	void swap(MyVector<T>& v) noexcept
	{
		using std::swap;
		swap(data_, v.data_);
		swap(size_, v.size_);
		swap(capacity_, v.capacity_);
	}

	T& front()
	{
		return data_[0];
	}

	T& back()
	{
		if (empty)
		{
			return data_[size_ - 1];
		}
		throw std::runtime_error("Vector is empty\n");
	}

	T* data()
	{
		return &data_[0];
	}

	bool empty()
	{
		return size_ <= 0 ? false : true;
	}

	T& operator[](const int index)
	{
		return data_[index];
	}

	const T& operator [] (const int index) const
	{
		return data_[index];
	}

	T& at(const int index)
	{
		if (index < 0 || index >= size_)
		{
			throw std::out_of_range("Incorrect index\n");
		}
		return data_[index];
	}

	const T& at(const int index) const
	{
		if (index < 0 || index >= size_)
		{
			throw std::out_of_range("Incorrect index\n");
		}
		return data_[index];
	}

	friend std::ostream& operator <<(std::ostream& s, const MyVector<T>& v)
	{
		for (iterator i = v.begin(); i != v.end(); i++)
		{
			s << *i << ' ';
		}
		s << '\n';
		return s;
	}

	void print() noexcept
	{
		for (size_t i = 0; i < size_; i++)
		{
			std::cout << data_[i] << ' ';
		}
	}

	iterator begin() const
	{
		return data_;
	}

	iterator end() const
	{
		return data_ + size_;
	}

};

#endif

