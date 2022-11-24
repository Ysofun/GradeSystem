#include "pch.h"
#include "..\�ɼ�¼��ϵͳ\SingletonInstance.h"

class TestSingleton : public SingletonInstance<TestSingleton>
{
	friend class SingletonInstance<TestSingleton>;
public:
	~TestSingleton() = default;
	TestSingleton(const TestSingleton&) = delete;
	TestSingleton(TestSingleton&&) = delete;

private:
	TestSingleton() {}
};

TEST(SingletonTest, Func_GetInstance)
{
	EXPECT_STREQ(typeid(TestSingleton::GetInstance()).name(), "class TestSingleton");
}