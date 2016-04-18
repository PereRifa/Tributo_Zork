#ifndef __VECTOR_H__
#define __VECTOR_H__

#include<stdio.h>
#include<assert.h>

template<class TYPE>

class mVector{
private:
	TYPE *buffer;
	unsigned int max_length = 10;
	unsigned int nelements = 0;


public:
	mVector(){
		buffer = new TYPE[max_length];
	}
	mVector(const mVector& other){
		max_length = other.max_length;
		nelements = other.nelements;
		buffer = new TYPE[max_length];
		for (unsigned int i = 0; i < nelements; i++){
			buffer[i] = other.buffer[i];
		}
	}
	mVector(unsigned int size) : max_length(size)
	{
		buffer = new TYPE[max_length];
	}
	~mVector(){
		delete[] buffer;
	}

	//pushback, add type to end of vector
	void pushback(const TYPE& otherbuffer){
		if (nelements == max_length){
			TYPE* temp;
			max_length *= 2;
			temp = new TYPE[max_length];
			for (unsigned int i = 0; i < nelements; i++){
				temp[i] = buffer[i];
			}
			delete[] buffer;
			buffer = temp;
		}
		*(buffer + (nelements++)) = otherbuffer;
	}

	//pushfront method, add type to the vector[0];
	void pushfront(const TYPE& item){
		if (max_length == nelements){
			max_length *= 2;
			TYPE* temp;
			temp = new TYPE[max_length];
			for (int i = 0; i < nelements; i++){
				temp[i] = buffer[i];
			}
			delete[] buffer;
			buffer = temp;
		}

		for (int i = nelements; i >= 0; --i){
			buffer[i + 1] = buffer[i];
		}
		*(buffer) = item;
		++nelements;
	}

	bool pop_back()
	{
		if (nelements > 0){
			nelements--;
			return true;
		}
		return false;
	}

	//return vector.buffer[i]
	TYPE operator[](unsigned int i) const
	{
		assert(i < nelements);
		return buffer[i];
		
	}
	TYPE& operator[](unsigned int i)
	{
		assert(i < nelements);
		return buffer[i];

	}
	//empty vector
	bool empty()const{
	
		if (nelements != 0){
			return false;
		}
		else return true;
	}

	unsigned int size() const
	{
		return nelements;
	}
	void clean()
	{
		nelements = 0;
	}

};
#endif