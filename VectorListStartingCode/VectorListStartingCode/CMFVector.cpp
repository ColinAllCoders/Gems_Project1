#include "CMFVector.h"

CMFVector::CMFVector()
{
	this->m_nextInsertIndex = 0;

	// At start, allocate some default size array
	this->m_arraySize = 100;
	// std::string* m_p_Array;		// Pointer to a dynamically allocated array
	this->m_p_Array = new std::string[ this->m_arraySize ];
	// At this point, we have an dynamic array that's "m_arraySize" big..
}

CMFVector::~CMFVector()
{
	// Delete the array of data
	delete [] this->m_p_Array;
}

void CMFVector::push_back( std::string newString )
{
	// Check to see if there is room in the array
	if ( this->m_nextInsertIndex < this->m_arraySize )
	{
		//this->m_data[this->m_nextInsertIndex] = newString;

		this->m_p_Array[this->m_nextInsertIndex] = newString;

		this->m_nextInsertIndex++;	
	}
	else
	{	// Not big enough...
		// Calculate some new size (1.5x or 2x or whatever)
		int newSize = m_arraySize * 2;
		// Call m_AllocateNewArray() with an appropriate new size
		m_AllocateNewArray( newSize );
		//and try again (will work)
		push_back( newString );
	}

}

void CMFVector::insert_at( int index, std::string value )
{
	std::string* pNewArray =  new std::string[ m_arraySize + 1 ];
	int orginalArrayIndex = 0;

	for( int i = 0; i != m_arraySize + 1; i++ )
	{
		if(i == index)
		{
			pNewArray[i] = value;
			orginalArrayIndex--;
		}
		else
		{
			pNewArray[i] = m_p_Array[orginalArrayIndex];
		}
		orginalArrayIndex++;
	}

	m_p_Array = pNewArray;
}

void CMFVector::delete_at( int index )
{
	std::string* pNewArray =  new std::string[ m_arraySize - 1 ];
	int orginalArrayIndex = 0;

	for( int i = 0; i != m_arraySize + 1; i++ )
	{
		if(i != index)
		{
			pNewArray[i] = m_p_Array[orginalArrayIndex];
		}
		else
		{
			orginalArrayIndex++;
			pNewArray[i] = m_p_Array[orginalArrayIndex];
		}
		orginalArrayIndex++;
	}

	m_p_Array = pNewArray;
}

std::string CMFVector::at( int index )		//std::string operator[] ( int index );
{
	// Check to see if there is room in the array
	if ( index >= this->m_nextInsertIndex )
	{
		return "**NOTVALID**";		// Throw an exception
	}

	return this->m_p_Array[ index ];
}

bool CMFVector::m_AllocateNewArray( int newArraySize )
{
	// Allocate new array (of new size, perhaps)
	// Copy all the old data into the new array
	// Delete old array
	// Set "official" pointer to new array

	// Allocate an array of 'newArraySize'
	std::string* pNewArray = new std::string[ newArraySize ];

	// Copy the data from old array to new...
	for ( int index = 0; index != this->m_nextInsertIndex ; index++ )
	{
		pNewArray[index] = this->m_p_Array[index];
	}

	// Delete all the data in the old array
	delete [] this->m_p_Array;

	// Point the "official" array pointer to this new array...
	this->m_p_Array = pNewArray;

	// Record the new size of the array
	this->m_arraySize = newArraySize;


	return true;
}