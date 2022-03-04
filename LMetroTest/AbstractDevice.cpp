#include "AbstractDevice.h"

AbstractDevice::AbstractDevice() 
{
	id = 0;
	answerString = "Answer";
}

AbstractDevice::AbstractDevice(int _id, const char* _answer)
{
	id = _id;
	answerString = _answer;
}

int AbstractDevice::GetId()
{
	return id;
}

const char* AbstractDevice::GetAnswerString()
{
	return answerString;
}

AbstractDevice::~AbstractDevice()
{}