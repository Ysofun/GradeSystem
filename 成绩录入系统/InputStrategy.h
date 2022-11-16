#pragma once

/* 输入策略抽象基类 */
class InputStrategy
{
public:
	virtual ~InputStrategy() = default;
	virtual void DoAlgorithm() = 0;
};