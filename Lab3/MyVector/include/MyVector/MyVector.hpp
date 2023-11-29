#ifndef _MyVector_HPP_
#define _MyVector_HPP_

#include <iostream>
#include <type_traits>
#include <algorithm>

/**
* @brief template class MyVector
* @param data_ - pointer in the type
* @param size_ - size
* @param capacity_ - capacity, needed for memory allocation
*/

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

	/**
	* @brief explicit constructor without parametrs
	*/

	explicit MyVector() noexcept: size_(0), capacity_(1)
	{
		data_ = reinterpret_cast<T*>(new char[1 * sizeof(T)]);
	};

	/**
	* @brief explicit constructor with count
	* @param count - how much memory should be allocated
	*/

	explicit MyVector(size_t count) noexcept: size_(count), capacity_(count * 2)
	{
		data_ = reinterpret_cast<T*>(new char[(count * 2) * sizeof(T)]);
	}

	/**
	* @brief constructor with count and value
	* @param count - how much memory should be allocated
	* @param value - how to initialize the entire vector
	*/

	MyVector(size_t count, const T& value) : MyVector(count)
	{
		for (iterator i = begin(); i != end(); i++)
		{
			*i = value;
		}
	}

	/**
	* @brief constructor with initializer_list
	*/

	MyVector(const std::initializer_list<T>& l) : capacity_(l.size() * 2), size_(l.size())
	{
		data_ = reinterpret_cast<T*>(new char[(l.size() * 2) * sizeof(T)]);
		std::uninitialized_copy(l.begin(), l.end(), data_);
	};

	/**
	* @brief copy constructor
	* @param const reference on the MyVector type
	* @throw - in case of any exception
	*/

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

	/**
	* @brief copy operator =
	* @param const reference on the MyVector type
	* @throw - in case of any exception
	* @return reference on the MyVector
	*/

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

	/**
	* @brief moving constructor
	*/

	MyVector(MyVector<T>&& v) noexcept : size_(v.size()), capacity_(v.capacity()), data_(v.data_)
	{
		v.capacity_ = 0;
		v.size_ = 0;
		v.data_ = nullptr;
	}

	/**
	* @brief moving operator =
	* @param rvalue reference on the MyVector
	*/

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

	/**
	* @brief destructor
	*/

	~MyVector()
	{
		clear();
		deallocate();
	}
	
	void deallocate() noexcept
	{
		delete[] reinterpret_cast<char*>(data_);
		data_ = nullptr;
	}

	void clear() noexcept
	{
		for (std::size_t i = 0; i < size_; i++) 
		{
			data_[i].~T();
		}
		size_ = 0;
	}

	/**
	* @brief method returning size
	* @return size
	*/

	constexpr size_t size() const noexcept
	{
		return size_;
	}

	/**
	* @brief method returning capacity
	* @return capacity
	*/

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

	template<typename... Args>
	void emplace_back(const Args&...args)
	{
		if (capacity_ == size_)
		{
			reserve(2 * size_);
		}
		new(data_ + size_) T(args...);
		++size_;
	}

	void push_back(const T& value) 
	{
		emplace_back(value);
	}

	/**
	* @brief removing an element from the end
	*/

	void pop_back() noexcept 
	{
		(data_ + size_)->~T();
		size_--;
	}

	/**
	* @brief inserting an element by index
	* @param index - index for insert
	* @param value - value for insert 
	* @throw std::runtime_error
	*/

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

	/**
	* @brief using std::swap
	*/

	void my_swap(T& one, T& two)
	{
		T t = std::move(one);
		one = std::move(two);
		two = std::move(t);
	}

	/**
	* @brief swaps two vectors
	* @param reference on MyVector
	*/

	void swap(MyVector<T>& v) noexcept
	{
		using std::swap;
		swap(data_, v.data_);
		swap(size_, v.size_);
		swap(capacity_, v.capacity_);
	}

	/**
	* @brief returns a reference to the first element
	* @return reference
	*/

	T& front()
	{
		return data_[0];
	}

	/**
	* @brief returns a reference to the last element
	* @return reference
	* @throw std::runtime_error
	*/

	T& back()
	{
		if (empty)
		{
			return data_[size_ - 1];
		}
		throw std::runtime_error("Vector is empty\n");
	}

	/**
	* @brief returns a pointer to the first element
	* @return pointer 
	*/

	T* data()
	{
		return &data_[0];
	}

	/**
	* @brief checks the emptiness of the vector
	* @return bool
	*/

	bool empty()
	{
		return size_ == 0;
	}

	/**
	* @brief operator[] returns a  reference by index
	* @return T&
	*/

	T& operator[](const int index)
	{
		return data_[index];
	}

	/**
	* @brief const operator[] returns a const reference by index
	* @return const T&
	*/

	const T& operator [] (const int index) const
	{
		return data_[index];
	}

	/**
	* @brief the method returns a reference by index
	* @return T&
	* @throw std::out_of_range
	*/

	T& at(const int index)
	{
		if (index < 0 || index >= size_)
		{
			throw std::out_of_range("Incorrect index\n");
		}
		return data_[index];
	}

	/**
	* @brief the method returns a const reference by index
	* @return const T&
	* @throw std::out_of_range
	*/

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

	/**
	* @brief returns the iterator to the beginning of the vector
	* @return iterator
	*/

	iterator begin() const
	{
		return data_;
	}

	/**
	* @brief returns the iterator to the ending of the vector
	* @return iterator
	*/

	iterator end() const
	{
		return data_ + size_;
	}

};

#endif

