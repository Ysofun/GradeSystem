#pragma once
#include "InputStrategy.h"

class InputCsvStrategy : public InputStrategy
{

public:
	~InputCsvStrategy() override;
	void DoAlgorithm() override;
};