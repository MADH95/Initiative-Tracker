#pragma once
/*

Name: Martin Harvey

Student ID: B00329330

I declare that the following code was produced by myself for the Algorithms & Collections - COMP09044 - module and that this is my own work.

I am aware of the penalties incurred by submitting in full or in part work that is not my own and that was developed by third parties that are not appropriately acknowledged.

*/
#include <string>

#include "Node.h"

namespace InitiativeTracker {

	//Group node child
	class Group : public Node
	{
	//Constructors
	public:
		/// <summary>
		/// Default Constructor
		/// </summary>
		explicit Group() = default;

		/// <summary>
		/// Data Constructor
		/// </summary>
		/// <param name="name"></param>
		/// <param name="initiative"></param>
		/// <param name="key"></param>
		explicit Group( std::string && name, unsigned int initiative, unsigned int key );
	};
}