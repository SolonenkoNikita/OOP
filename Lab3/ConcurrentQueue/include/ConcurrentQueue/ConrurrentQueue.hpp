#ifndef _ConcurrentQueue_HPP_
#define _ConcurrentQueue_HPP_

#include <queue>
#include <thread>
#include <filesystem>
#include <future>

template<typename T>
class ConcurrentQueue
{
private:
	std::queue<T> queue_;
	 
	std::mutex qu_mutex;
public:

	void push(const T& data)
	{
		qu_mutex.lock();
		queue_.push(data);
		qu_mutex.unlock();
	}

	bool empty()
	{
		qu_mutex.lock();
		auto b = queue_.empty();
		qu_mutex.unlock();
		return b;
	}

	T& front()
	{
		qu_mutex.lock();
		auto b = queue_.front();;
		qu_mutex.unlock();
		return b;
	}

	void pop()
	{
		qu_mutex.lock();
		queue_.pop();
		qu_mutex.unlock();
	}
};


#endif