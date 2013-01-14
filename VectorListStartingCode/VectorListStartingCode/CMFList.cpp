#include "CMFList.h"

CMFList::CMFList()
{
	this->p_FirstNode = 0;
	this->p_CurrentNode = 0;
}

CMFList::~CMFList() {}


std::string CMFList::get_value_at_current_location( void )
{
	// Is the 'current' location valid (i.e. is the pointer valid?)
	if ( this->p_CurrentNode != 0 )
	{
		return this->p_CurrentNode->value;
	}
	return "**CURRENT LOCATION IS INVALID**";
}

void CMFList::insert_at_current_location( std::string value )
{
	// Create a new node with this value
	CMFNode* pNewNode = new CMFNode();
	pNewNode->value = value;

	// Is this the first node we've added? 
	if ( this->p_CurrentNode == 0 )
	{	// Yes, so this is the first and current node.
		this->p_FirstNode = pNewNode;
		this->p_CurrentNode = pNewNode;
	}
	else
	{	// We already have some nodes...
		// Connect this new node to the "current" node
		this->p_CurrentNode->p_NextNode = pNewNode;	
		// And, set our current node to this new node
		this->p_CurrentNode = pNewNode;
	}
	// at this point, either we have one node or we've added a node.
	return;
}



bool CMFList::move_next(void)
{
	// This we look at the 'next node' pointer in the current node
	// Is this pointer OK?
	if ( this->p_CurrentNode->p_NextNode == 0 )
	{
		return false;// "**THERE ARE NO MORE NODES TO MOVE TO**";
	}
	// Next node is OK, so 'move' to it. i.e. set the 'current pointer'
	//	to the 'next node' pointer...
	this->p_CurrentNode = ( this->p_CurrentNode->p_NextNode );
	return true;
}

bool CMFList::move_to_start(void)
{
	this->p_CurrentNode = this->p_FirstNode;
	return true;
}

// Leave these...
bool CMFList::move_previous(void)
{
	return false;
}

// Recal, the STL has an 'iterator' class where we are using just the index;
void CMFList::insert_at( int index, std::string value )
{
}

std::string CMFList::get_value_at( int index )
{
	return "**THIS ISN'T AVAILABLE IN THE FREE VERSION**";
}