#include "Device2.h"

Device2::Device2()
{}

Device2::Device2(int _id, const char* _answer) : AbstractDevice(_id, _answer)
{}

std::string Device2::Request(std::string _msg)
{
    std::stringstream result;

    if (cmdIsCorrect(_msg))
    {
        result << answerString << END_CMD;
    }
    else
    {
        throw std::exception("Incorrect command format.");
    }

    return result.str();
}

Device2::~Device2()
{}

bool Device2::cmdIsCorrect(std::string _msg)
{
    return (_msg.find(END_CMD) != std::string::npos);
}
