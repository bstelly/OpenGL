#include "Number.h"

Number::Number(int value)
{
	mValue = value;
}

Number::~Number()
{

}

void Number::Add(int value)
{
	mValue += value;
}