#pragma once
#include <mutex>


template<typename T>
class SingletonInstance
{
public:
	virtual ~SingletonInstance() {}

	SingletonInstance(const SingletonInstance&) = delete;
	const SingletonInstance& operator=(const SingletonInstance&) = delete;

	static T*& GetInstance() noexcept(std::is_nothrow_constructible<T>::value)
	{
		if (m_Instance == nullptr)
		{
			m_Mutex.lock();
			if (m_Instance == nullptr)
			{
				m_Instance = new T();
			}
			m_Mutex.unlock();
		}
		return m_Instance;
	}

protected:
	SingletonInstance() {}

private:
	static T* m_Instance;
	static std::mutex m_Mutex;
};

template<typename T>
std::mutex SingletonInstance<T>::m_Mutex;

template<typename T>
T* SingletonInstance<T>::m_Instance = nullptr;
