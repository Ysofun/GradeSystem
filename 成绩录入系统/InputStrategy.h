#pragma once

/* ������Գ������ */
class InputStrategy
{
public:
	virtual ~InputStrategy() = default;
	virtual void DoAlgorithm() = 0;
};