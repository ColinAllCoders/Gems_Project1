#ifndef _CMFNode_HG_
#define _CMFNode_HG_

#include <string>

class CMFNode
{
public:
	CMFNode();
	~CMFNode();
	std::string value;
	// Singly linked list has pointer to next node
	CMFNode* p_NextNode;

	// Doubly would have pointer to previous, too
	//CMFNode* p_PreviousNode;
};

#endif