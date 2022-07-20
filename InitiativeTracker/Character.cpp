/*

Name: Martin Harvey

Student ID: B00329330

I declare that the following code was produced by myself for the Algorithms & Collections - COMP09044 - module and that this is my own work.

I am aware of the penalties incurred by submitting in full or in part work that is not my own and that was developed by third parties that are not appropriately acknowledged.

*/
#include "Character.h"

namespace InitiativeTracker {

	Character::Character(std::string&& name, unsigned int initiative, int health, int maxHealth, unsigned int key)
		: Node( std::forward< std::string >( name ), initiative, key ), health_( health ), maxHealth_( maxHealth )
	{
	}
}