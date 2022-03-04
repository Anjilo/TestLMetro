#pragma once
#include "AbstractDevice.h"
#include <cstring>
#include <cstdlib>
#include <string>
#include <sstream>
#include <exception>

class Device1 : AbstractDevice
{
	public:
		/// <summary>
		/// Constructor without. By default Id = 1, answer = "answer".
		/// </summary>
		Device1();

		/// <summary>
		/// Constructor with id and answer parameters.
		/// </summary>
		/// <param name="_id - ">Device id.</param>
		/// <param name="_answe - r">Device answer.</param>
		Device1(int _id, const char* _answer);
	
		/// <summary>
		/// Virtual method to get command answer. Overrides AbstractDevice.Request() method 
		/// </summary>
		/// <param name="_msg - ">Command from master device.</param>
		/// <returns>Answer to master edvice.</returns>
		virtual std::string Request(std::string _msg);

		/// <summary>
		/// Virtual destructor.
		/// </summary>
		virtual ~Device1();

	protected:
		const char CHECKSUM_SEPAR = '$';
		const int CHECKSUM_MOD = 256;

		/// <summary>
		/// Calculates checksum for the given string.
		/// </summary>
		/// <param name="_msg - ">Command string.</param>
		/// <returns>Calculated checksum.</returns>
		int getChecksumByString(std::string _msg);

		/// <summary>
		/// Checking the checksum for correctness.
		/// </summary>
		/// <param name="_msg - ">Command string from master device.</param>
		/// <returns>True - checksum is corerct, False - otherwise.</returns>
		bool isChecksumCorrect(std::string _msg);

		/// <summary>
		/// Calculates command checksum.
		/// </summary>
		/// <param name="_msg - ">Command string.</param>
		/// <returns>Command checksum.</returns>
		int calcChecksum(std::string _msg);
};

