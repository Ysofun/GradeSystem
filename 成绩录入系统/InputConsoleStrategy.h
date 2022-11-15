#pragma once
#include "InputStrategy.h"

class InputConsoleStrategy : public InputStrategy
{
public:
	~InputConsoleStrategy() override;
	void DoAlgorithm() override;

};