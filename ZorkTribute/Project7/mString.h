#ifndef _MY_STRING
#define _MY_STRING
#include<string.h>
#include<stdio.h>



class mString
{
private:
	char* buffer = nullptr;
	unsigned int max_size;

public:
	mString(const char* str)
	{
		int len = strlen(str);
		buffer = new char[len + 1];
		strcpy_s(buffer, strlen(str) + 1, str);
		//printf("\nLa Classe String se esta construiendo con %s ", buffer);
		max_size = len + 1;
	}
	mString(const mString& str)
	{
		int len = strlen(str.buffer);
		buffer = new char[len + 1];
		strcpy_s(buffer, strlen(str.buffer) + 1, str.buffer);
		//printf("\nLa Classe Second se esta construiendo con %s ", buffer);
	};

	~mString()
	{
		//printf("\nLa Classe String se esta destruiendo con %s ", buffer);
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
/*	void cpy(const char* otherbuffer){
		unsigned int len = strlen(otherbuffer) + 1;
		if (len > max_size){
			printf("\nNew/Telete Needed");
			delete[] buffer;
			max_size = len;
			buffer = new char[max_size];
		}
		else{
			printf("\nno New/Telete Needed");
		}
		strcpy_s(buffer, len, otherbuffer);
	}*/
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
};

#endif