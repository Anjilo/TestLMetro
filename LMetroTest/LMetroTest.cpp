#include <iostream>
#include "Device1.h"
#include "Device2.h"
#include "LMetroTest.h"
#include <string>
#include <exception>
#include <cstdio>

std::string OnDevice1Cmd(std::string _cmd)
{
    Device1 device1(1, "OK");
    return device1.Request(_cmd);
}

std::string OnDevice2Cmd(std::string _cmd)
{
    Device2 device2(2, "OK");
    return device2.Request(_cmd);
}

std::string deviceMapping(int _deviceType, std::string _cmd)
{
    switch (_deviceType)
    {
        case DEVICE_1:
        {
            return OnDevice1Cmd(_cmd);
        }
        case DEVICE_2:
        {
            return OnDevice2Cmd(_cmd);
        }
        default:
        {
            throw std::exception("Unknown device");

            break;
        }
    }
}

int main()
{
    std::string inputData;
    std::cin >> inputData;
    
    try
    {
        //transform input string
        inputData.replace(inputData.find("\\r"), 2, "\r");
        inputData.replace(inputData.find("\\n"), 2, "\n");

        //getting command string without type of device
        std::string deviceCmd = inputData;
        int sepIndx = inputData.find(DEVICE_TYPE_SEP);
        deviceCmd.erase(0, sepIndx + 1);

        //executes cmd
        std::cout << deviceMapping(atoi(inputData.substr(0, sepIndx + 1).c_str()), deviceCmd);
    }
    catch (std::exception &ex)
    {
        std::cout << ex.what() << std::endl;
    }
}