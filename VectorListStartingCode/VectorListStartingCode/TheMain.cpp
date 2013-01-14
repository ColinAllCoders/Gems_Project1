#include <iostream>

#include <vector>
#include <list>

#include <string>


#include "CMFVector.h"
#include "CMFList.h"

void PrintVector( CMFVector &myVec );


int main()
{
	CMFList myList;
	// 1. Insert ....
	myList.insert_at_current_location( "Ted" );
	myList.insert_at_current_location( "Lady Gaga" );	
	myList.insert_at_current_location( "Bob" );	

	myList.move_to_start();
	do 
	{
		std::cout << myList.get_value_at_current_location() << std::endl;
	}
	while ( myList.move_next() );

	return 0;
}

int mainCMFVector()
{
	CMFVector myVec;
	// 1. Insert at the end of the vector....
	myVec.push_back( "Ted" );
	myVec.push_back( "Lady Gaga" );
	myVec.push_back( "Bob" );

	//for ( int x = 0; x != 200; x++ )
	//{
	//	myVec.push_back( "Yikes!");
	//}
	PrintVector( myVec );

	myVec.m_AllocateNewArray( 500 );
	PrintVector( myVec );

	return 0;
}

void PrintVector( CMFVector &myVec )
{
	for ( int x = 0; x != 10; x++ )		// x != myVec.size() should be here instead...
	{
		std::cout << x << ":" << myVec.at( x ) << std::endl;
	}
}



// Use strings and use the "US Census" information

void PrintVector( std::vector< std::string > &myVec );
void PrintList( std::list< std::string > &myList );

int mainList()
{
	std::list< std::string > myList;

	//myList.push_back( "Hey" );
	myList.insert( myList.end(), "Ted" );
	myList.insert( myList.end(), "Lady Gaga" );
	myList.insert( myList.end(), "Bob" );
	myList.insert( myList.begin(), "Hey There!" );		// Fast with list
	PrintList( myList );

	// 2. Delete anywhere...say, location 2
	int index = 0;
	std::list< std::string >::iterator itList = myList.begin();
	while ( index != 2 )
	{
		itList++;
		index++;
	}
	myList.erase( itList );
	PrintList( myList );

	// 4. Size of list
	std::cout << myList.size() << std::endl;

	// Insert lots of stuff into a list...
	for ( int x = 1; x != 100000000; x++ )
	{
		myList.insert( myList.begin(), " Hello " );
	}

	return 0;
}

int mainVector()
{
	std::vector<std::string> myVec;
	//myVec.reserve( 1000 );
	// 1. Insert at the end of the vector....
	myVec.push_back( "Ted" );
	myVec.push_back( "Lady Gaga" );
	myVec.push_back( "Bob" );
	PrintVector( myVec );

	//std::string myArray[100];
	//myArray[0] = "Ted";
	//myArray[1] = "Lady Gaga";

	// 2. Insert at some other point in the vector...
	// Example: I want to insert at location "1"
	int index = 0;
	std::vector< std::string >::iterator itVec = myVec.begin();
	while ( index != 1 )
	{
		itVec++;
		index++;
	}
	// 
	std::cout << *itVec << std::endl;
	myVec.insert( itVec, "Jacob" );
	PrintVector( myVec );


	// begin() + x;
	myVec.insert( myVec.begin() + 1, "Fraser" );
	PrintVector( myVec );

	// If you have C11, you can use the "std_advance" "std_next" "std_previous" 
	// ** asssuming you have C11 **

	// 3. Delete at a location 
	std::vector< std::string >::iterator itDeleteLocation = myVec.begin() + 1;
	myVec.erase( itDeleteLocation ); 
	PrintVector( myVec );

	std::cout << myVec[2] << std::endl;
	std::cout << myVec.at(2) << std::endl;
	std::cout << myVec.size() << std::endl;
	std::cout << myVec.capacity() << std::endl;

	myVec.push_back( "A" ); myVec.push_back( "B" ); myVec.push_back( "C" );
	std::cout << myVec.capacity() << std::endl;

	myVec.resize( 100 );
	std::cout << myVec.capacity() << std::endl;

	//for ( int x = 1; x != 100000000; x++ )
	//{
	//	myVec.push_back(" Hello ");
	//}

	return 0;
}


void PrintVector( std::vector< std::string > &myVec )
{
	int index = 0;
	for ( std::vector< std::string >::iterator itVec = myVec.begin(); itVec != myVec.end(); itVec++, index++ )
	{
		std::cout << index << ":" << *itVec << std::endl;
	}
	std::cout << std::endl;
}

void PrintList( std::list< std::string > &myList )
{
	int index = 0;
	for ( std::list< std::string >::iterator itList = myList.begin(); 
		itList != myList.end(); itList++, index++ )
	{
		std::cout << index << ":" << *itList << std::endl;
	}
	std::cout << std::endl;
}