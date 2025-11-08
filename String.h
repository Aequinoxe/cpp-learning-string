#pragma once

class String
{
private:

	char* array;
	int size;	

public:

	String();
		
	String(const char*);

	String(const String& source);

	~String();

	String& operator = (const char* rightOperand);
	
	String& operator = (const String& rightOperand);

	String operator + (const String& rightOperand) const;

	String operator * (int multiplier) const;

	bool operator == (const char* rightOperator) const;
	
	bool operator != (const char* rightOperator) const;

	bool operator == (const String& rightOperator) const;
	
	bool operator != (const String& rightOperator) const;

	char& operator [] (int index);
	
	const char& operator [] (int index) const;

	void print() const;

	int length() const;
};