#pragma once

#include "AbstractDevice.h"
#include <string>
#include <sstream>

class Device2 : AbstractDevice
{
	public:
		/// <summary>
		/// Constructor without. By default Id = 1, answer = "answer".
		/// </summary>
		Device2();

		/// <summary>
		/// Constructor with id and answer parameters.
		/// </summary>
		/// <param name="_id - ">Device id.</param>
		/// <param name="_answe - r">Device answer.</param>
		Device2(int _id, const char* _answer);


		/// <summary>
		/// Virtual method to get command answer. Overrides AbstractDevice.Request() method 
		/// </summary>
		/// <param name="_msg - ">Command from master device.</param>
		/// <returns>Answer to master edvice.</returns>
		virtual std::string Request(std::string _msg);

		/// <summary>
		/// Virtual destructor.
		/// </summary>
		virtual ~Device2();
	protected:

		/// <summary>
		/// Checking the given command for correctness.
		/// </summary>
		/// <param name="_msg - ">Command string.</param>
		/// <returns>True - command is correct, False - otherwise.</returns>
		bool cmdIsCorrect(std::string _msg);
};

