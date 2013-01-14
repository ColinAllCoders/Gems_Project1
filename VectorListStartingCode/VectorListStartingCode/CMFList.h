#ifndef _CMFList_HG_
#define _CMFList_HG_

#include <string>

#include "CMFNode.h"

class CMFList
{
public:
	CMFList();
	~CMFList();

	// Recal, the STL has an 'iterator' class where we are using just the index;
	void insert_at_current_location( std::string value );
	void insert_at( int index, std::string value );
	std::string get_value_at_current_location( void );
	bool move_next(void);
	bool move_previous(void);
	bool move_to_start(void);

	std::string get_value_at( int index );

private:
	CMFNode* p_FirstNode;
	CMFNode* p_CurrentNode;
};

#endif