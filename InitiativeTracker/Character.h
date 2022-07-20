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
	
	/// <summary>
	/// Character node child
	/// </summary>
	class Character : public Node
	{
	//Variables
	private:
		int health_, maxHealth_;

	//Constructors
	public:
		/// <summary>
		/// Default Constructor
		/// </summary>
		explicit Character() = default;

		/// <summary>
		/// Data Constructor
		/// </summary>
		/// <param name="name"></param>
		/// <param name="initiative"></param>
		/// <param name="health"></param>
		/// <param name="maxHealth"></param>
		/// <param name="key"></param>
		explicit Character( std::string&& name, unsigned int initiative, int health, int maxHealth, unsigned int key );

	//Getters and Setters
	public:
		const int getHealth() const { return health_; }
		const int getMaxHealth() const { return maxHealth_; }

		void setHealth( int newHealth ) { health_ = newHealth; }
		void setMaxHealth( int newMaxHealth ) { maxHealth_ = newMaxHealth; }
	};
}