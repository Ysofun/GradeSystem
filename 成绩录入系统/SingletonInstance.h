#pragma once
#include <mutex>


/* 单例模式基类 */
template<typename T>
class SingletonInstance
{
public:
	virtual ~SingletonInstance() {}

	SingletonInstance(const SingletonInstance&) = delete;
	const SingletonInstance& operator=(const SingletonInstance&) = delete;

	/* 懒汉式实现 */
	//static T*& GetInstance() noexcept(std::is_nothrow_constructible<T>::value)
	//{
	//	if (m_Instance == nullptr)
	//	{
	//		std::lock_guard<std::mutex> LockGuard(m_Mutex);
	//		//m_Mutex.lock();
	//		if (m_Instance == nullptr)
	//		{
	//			m_Instance = new T();
	//		}
	//		//m_Mutex.unlock();
	//	}
	//	return m_Instance;
	//}

	static T& GetInstance()
	{
		static T m_Instance;
		return m_Instance;
	}

protected:
	SingletonInstance() {}

private:
	//static T* m_Instance;
	//static std::mutex m_Mutex;
};

//template<typename T>
//std::mutex SingletonInstance<T>::m_Mutex;
//
//template<typename T>
//__declspec(selectany) T* SingletonInstance<T>::m_Instance = nullptr;
