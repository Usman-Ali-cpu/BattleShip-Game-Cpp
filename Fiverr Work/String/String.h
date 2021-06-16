#pragma once
#ifndef STRING_H
#define STRING_H
#include <iostream>

namespace HomeMadeString
{
	class String
	{
		// Number of characters in the string
		int elementNum;
		// Pointer to the memory segment containing the characters
		char*pData;
	
	public:
		// Default constructor (without arguments):
		String(){
			elementNum = 100;
			pData = new char[elementNum];
		}
		// Copy constructor:
		String & copy(const String &s ){
			this->elementNum = s.elementNum;
			this->pData = new char[elementNum];
			for (int i = 0; i < elementNum; i++){
				this->pData[i] = s.pData[i];
			}
			return *this;
		}


		// Conversion constructor that expects a char* with '\0' at the end
		// This constructor is responsible for the conversion char*-> String
		String(const char* str){
			int i = 0;
			while(str[i] != '\0'){
				pData[i] = str[i];
			}
		}


		// Constructor with a char (c) and an int parameter (times)
		// This constructor creates a string that contains 'times' pieces of the character c
		// e.g. if c='$' and times=5 then String="$$$$$"
		String(char c, int times);

		// Destructor:


		// Copies the string to the buffer and terminates it with '\0' (string terminating character)
		// Memory allocation for the buffer is to be done by a caller
		void getStr(char * pBuff){
			
		}
		
		// Returns with the string length
		int getLength(){return elementNum;}

		// Writes the string to the given stream		
		void print(std::ostream& os);

		// Returns with the character at the given position, othewise 0
		char getChar(int pos);

		// --- Static Class Members. They work with two strings passed as parameters. ---
		
		// Returns with a concatenated string
		static String concatenate(String string1, String string2);

		// Compares two strings
		static bool compare(String string1, String string2);

		// Copies string2 to string1
		static void copy(String& string1, String string2);
	};
}
#endif /* STRING_H */