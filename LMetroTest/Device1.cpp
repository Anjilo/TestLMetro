#include "Device1.h"

Device1::Device1()
{}

Device1::Device1(int _id, const char* _answer) : AbstractDevice(_id, _answer)
{}

std::string Device1::Request(std::string _msg)
{
	std::stringstream answer;

	if (isChecksumCorrect(_msg))
	{
		std::string bufAnswerStr = answerString;
		bufAnswerStr += END_CMD;

		int checksum = calcChecksum(bufAnswerStr);
		answer << answerString << CHECKSUM_SEPAR << std::hex << checksum << END_CMD;
	}
	else
	{
		throw std::exception("Involid command checksum.");
	}

	return answer.str();
}

Device1::~Device1()
{}

int Device1::getChecksumByString(std::string _msg)
{
	int sepIndx = _msg.find(CHECKSUM_SEPAR);
	int endCmdSymbolIndx = _msg.find(END_CMD);
	int result = 0;

	if ((sepIndx != std::string::npos) && (endCmdSymbolIndx != std::string::npos))
	{
		result = std::stoi(_msg.substr(sepIndx + 1, endCmdSymbolIndx - 1), nullptr, 16);
	}
	else 
	{
		throw std::exception("Involid command format.");
	}

	return result;
}

bool Device1::isChecksumCorrect(std::string _msg)
{
	std::string bufMsg = _msg;

	int sepIndx = bufMsg.find(CHECKSUM_SEPAR);
	int endChecksumIndx = bufMsg.find(END_CMD);
	int calculatedChecksum = 0;
	int checksumFromMsg = 0;

	if ((sepIndx != std::string::npos) && (endChecksumIndx != std::string::npos))
	{
		calculatedChecksum = calcChecksum(bufMsg.erase(sepIndx, endChecksumIndx - sepIndx));
		checksumFromMsg = getChecksumByString(_msg);
	}
	else
	{
		throw std::exception("Involid command format.");
	}
	
	return (checksumFromMsg == calculatedChecksum);
}

int Device1::calcChecksum(std::string _msg)
{
	int result = 0;
	int lastIndx = _msg.find(END_CMD);
	
	if (lastIndx != std::string::npos)
	{
		for (int i = 0; i < lastIndx; i++)
		{
			result += _msg.c_str()[i];
		}

		result = result % CHECKSUM_MOD;
	}
	else
	{
		throw std::exception("Involid command format.");
	}

	return result;
}