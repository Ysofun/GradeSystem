#pragma once
#include "InputStrategy.h"

class InputJsonStrategy : public InputStrategy
{

public:
	~InputJsonStrategy() override;
	void DoAlgorithm() override;

};