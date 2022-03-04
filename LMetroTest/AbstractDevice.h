#pragma once

#include <string>

/// <summary>
/// Base device class.
/// </summary>
class AbstractDevice
{
	public:
		/// <summary>
		/// Constructor without. By default Id = 1, answer = "answer".
		/// </summary>
		AbstractDevice();

		/// <summary>
		/// Constructor with id and answer parameters.
		/// </summary>
		/// <param name="_id - ">Device id.</param>
		/// <param name="_answer - ">Device answer.</param>
		AbstractDevice(int _id, const char* _answer);

		/// <summary>
		/// Id getter.
		/// </summary>
		/// <returns>Device Id.</returns>
		int GetId();

		/// <summary>
		/// Answer getter.
		/// </summary>
		/// <returns>Device answer string.</returns>
		const char* GetAnswerString();

		/// <summary>
		/// Virtual method to get command answer.
		/// </summary>
		/// <param name="_msg - ">Command from master device.</param>
		/// <returns>Answer to master edvice.</returns>
		virtual std::string Request(std::string _msg) = 0;

		/// <summary>
		/// Virtual destructor.
		/// </summary>
		virtual ~AbstractDevice();

	protected:
		int id;
		const char* answerString;

		const char* END_CMD = "\r\n";
};

