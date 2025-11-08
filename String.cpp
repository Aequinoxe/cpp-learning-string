#include <iostream>
#include "String.h"
#include <stdexcept>

using namespace std;

String::String()
	: array(nullptr),
	  size(0)
{}

String::String(const char* source)
{
	if (!source)
	{
		size = 0;
		array = new char[size + 1];
		array[0] = '\0';
		
		return;
	}

	int length = 0;

	while (source[length] != '\0')
	{
		length++;
	}

	this->size = length;
	array = new char[size + 1]; 

	for (int i = 0; i < size; i++)
	{
		array[i] = source[i];
	}

	array[size] = '\0';
}

String::String(const String& source)
{
	size = source.size;
	array = new char[size+1];

	for (int i = 0; i <size; i++)
	{
		array[i] = source.array[i];
	}

	array[size] = '\0';
}

String::~String()
{
	if (array != nullptr)
	{
		delete[] array;
	}
}
	
String& String::operator=(const char* rightOperand)
{
	if (array != nullptr)
	{
		delete[] array;
	}
	
	if (!rightOperand)
	{
		size = 0;
		array = new char[size + 1];
		array[0] = '\0';
		
		return *this;
	}
	
	int length = 0;

	while (rightOperand[length] != '\0')
	{
		length++;
	}

	this->size = length; 
	array = new char[size+1];

	for (int i = 0; i < size; i++)
	{
		array[i] = rightOperand[i];
	}

	array[size] = '\0';
	
	return *this;
}

String& String::operator=(const String& rightOperand)
{
	if (this == &rightOperand) 
	{
		return *this;
	}

	if (array != nullptr)
	{
		delete[] array;
	}

	size = rightOperand.size;
	
	array = new char[size + 1];

	for (int i = 0; i < size; i++)
	{
		array[i] = rightOperand.array[i];
	}

	array[size] = '\0';

	return *this;	
}

String String::operator+(const String& rightOperand) const
{
	String result;
	int shift = 0;
	
	int newSize = size + rightOperand.size;
	result.size = newSize;
	result.array = new char[newSize+1];

	while (shift < size)
	{
		result.array[shift] = array[shift];
		shift++;
	}
	while (shift < newSize)
	{
		result.array[shift] = rightOperand.array[shift-size];
		shift++;
	}

	result.array[newSize] = '\0';
	
	return result;
}

String String::operator*(int multiplier) const
{
	if (multiplier < 0)
	{
		return String();
	}
	
	String result;

	int newSize = multiplier*size;

	result.array = new char[newSize + 1];
	result.size = newSize;

	for (int i = 0; i < multiplier; i++)
	{
		for (int j = 0; j < size; j++)
		{
			result.array[i * size + j] = array[j];
		}
	}
	
	result.array[newSize] = '\0';

	return result;
}

bool String::operator==(const char* rightOperator) const
{
	if (!rightOperator) 
	{
		return size == 0;
	}

	int length = 0;
	
	while (rightOperator[length] != '\0')
	{
		length++;
	}

	if (length != size)
	{
		return false;
	}

	for (int i = 0; i < length; i++)
	{
		if (array[i] != rightOperator[i])
		{
			return false;
		}
	}

	return true;
}

bool String::operator!=(const char* rightOperator) const
{
	return !(*this == rightOperator);
}

bool String::operator==(const String& rightOperator) const
{
	if (size != rightOperator.size)
	{
		return false;
	}

	for (int i = 0; i < size; i++)
	{
		if (array[i] != rightOperator.array[i])
		{
			return false;
		}
	}

	return true;
}

bool String::operator!=(const String& rightOperator) const
{
	return !(*this == rightOperator);
}

char& String::operator[](int index)
{
	if (size == 0)
	{
		throw out_of_range("Index out of range");
	}
	
	if (index < 0)
	{
		index = 0;
	}

	if (index >= size) 
	{
		index = size - 1;
	}

	return array[index];
}

const char& String::operator[](int index) const
{
	if (size == 0)
	{
		throw out_of_range("Index out of range");
	}
	
	if (index < 0)
	{
		index = 0;
	}

	if (index >= size)
	{
		index = size - 1;
	}

	return array[index];
}

void String::print() const
{
	cout << array;
}

int String::length () const
{
	return size;
}
