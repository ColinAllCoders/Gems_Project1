#ifndef _CMFVector_HG_
#define _CMFVector_HG_

#include <string>

class CMFVector
{
public:
	CMFVector();
	~CMFVector();

	void push_back( std::string newString );
	std::string at( int index );		//std::string operator[] ( int index );

	void insert_at( int index, std::string value );	
	void delete_at( int index );

	int size(void);
	int capacity(void);

	// Called whenever we need a 'bigger' array
	// **THIS IS PUBLIC, but it SHOULDN'T BE**
	bool m_AllocateNewArray( int newArraySize );
private:
	//static const int m_arraySize = 100;
	//std::string m_data[m_arraySize];

	std::string* m_p_Array;		// Pointer to a dynamically allocated array
	int m_arraySize;

	int m_nextInsertIndex;// = 0;

};

#endif