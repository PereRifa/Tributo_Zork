#ifndef _MY_STRING
#define _MY_STRING

#include<string.h>
#include "mVector.h"

class mString
{
private:
	char* buffer = nullptr;
	unsigned int max_size = 20;
	

public:
	mString(const char* str)
	{
		int len = strlen(str);
		buffer = new char[len + 1];
		strcpy_s(buffer, strlen(str) + 1, str);
		max_size = len + 1;
	}
	mString(char* str)
	{
		int len = strlen(str);
		buffer = new char[len + 1];
		strcpy_s(buffer, strlen(str) + 1, str);
		max_size = len + 1;
	}
	mString(const mString& str)
	{
		int len = strlen(str.buffer);
		buffer = new char[len + 1];
		strcpy_s(buffer, strlen(str.buffer) + 1, str.buffer);
	};
	~mString()
	{
		delete[] buffer;
	};

	unsigned int mstring_lenght() const
	{
		return strlen(buffer);
	};
	unsigned int capacity() const
	{
		return max_size;
	}
	const char* C_Str() const
	{
		return buffer;
	};
	bool empty() const
	{
		return (strlen(buffer) == 0);
	};
	bool operator==(const mString& str) const
	{
		return (strcmp(buffer, str.buffer) == 0);
	};
	bool operator==(const char* str)
	{
		return (strcmp(buffer, str))== 0;
	}
	
	void operator=(const mString& other)
	{
		unsigned int len = strlen(other.buffer) + 1;
		if (len > max_size){
			
			delete[] buffer;
			max_size = other.max_size;
			buffer = new char[max_size];
		}
		strcpy_s(buffer, len, other.buffer);
	}
	void operator+=(const mString& other)
	{
		unsigned int len = max_size + strlen(other.buffer);
		if (max_size < len){
			max_size += len;
			char *p = new char[max_size];
			p = buffer;
			delete[] buffer;
			buffer = new char[max_size];
			*buffer = *p;

		}
	}

	mVector<mString*> tokenize()
	{
		int start_point = 0;
		int aux = 0;
		int capacity = 0;
		char* temp = nullptr;
		mVector<mString*> commands;
		for (unsigned int i = 0; i < max_size; i++)
		{
			if ((*(buffer + i) == ' ') || (*(buffer + i) == NULL))
			{
				aux = capacity +1;
				temp = new char[capacity+1];
				for(int j = 0; j < capacity; j++)
				{
					*(temp + j) = *(buffer + (start_point + j));
				}
				*(temp + capacity) = NULL;
				commands.pushback(new mString(temp));
				delete[] temp;
				capacity = 0;
				start_point += aux;
			}
			else capacity++;
		}
		return commands;
	}
};

#endif