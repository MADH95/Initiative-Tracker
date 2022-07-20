#pragma once
/*

Name: Martin Harvey

Student ID: B00329330

I declare that the following code was produced by myself for the Algorithms & Collections - COMP09044 - module and that this is my own work.

I am aware of the penalties incurred by submitting in full or in part work that is not my own and that was developed by third parties that are not appropriately acknowledged.

*/
#include <vector>
#include <algorithm>
#include <functional>

namespace InitiativeTracker {
	
	/// <summary>
	/// Node in a Tree
	/// </summary>
	class Node : public std::enable_shared_from_this< Node >
	{
		//Type alias for a vector of nodes
		using NodeVec = std::vector< std::shared_ptr< Node > >;

		//Type alias for a function that takes a node and returns bool
		using Predicate = std::function< bool( const std::shared_ptr< Node > & ) >;

		using Action = std::function< void( std::shared_ptr< Node > & ) >;

		/// <summary>
		/// Compares the initiative of two nodes
		/// </summary>
		/// <returns>The result of the comparison</returns>
		static constexpr auto compare = []( auto &&first, auto &&second ) {
			return first->getInitiative() >= second->getInitiative();
		};

	//Variables
	protected:
		unsigned int key_;
		bool inGroup_ = false;
		
		std::string name_;
		unsigned int initiative_;
		
		NodeVec children_;

	//Constructors & Destructor
	public:
		/// <summary>
		/// Default Constructor
		/// </summary>
		explicit Node() = default;

		/// <summary>
		/// Data Constructor
		/// </summary>
		/// <param name="name"></param>
		/// <param name="initiative"></param>
		/// <param name="key"></param>
		explicit Node( std::string &&name, unsigned int initiative, unsigned int key );

		/// <summary>
		/// Default Destructor
		/// </summary>
		virtual ~Node() = default;

	//This function
	private:
		/// <summary>
		/// alias for shared_from_this
		/// </summary>
		/// <returns>A std::shared_ptr to the calling object</returns>
		std::shared_ptr< Node > This() { return shared_from_this(); }
	
	//Getters and Setters
	public:
		unsigned int getKey() const { return key_; }
		unsigned int getInitiative() const { return initiative_; }
		const std::string &getName() const { return name_; }
		bool isInGroup() const { return inGroup_; }

		void setInitiative( unsigned int initiative ) { initiative_ = initiative; }
		void setName( std::string &&newName ) { name_ = newName; }
		void addedToGroup() { inGroup_ = true; }

	//Children functions
	public:
		/// <summary>
		/// Obtain the number of children the node has
		/// </summary>
		/// <returns>The number of children</returns>
		unsigned int numChildren() const { return children_.size(); }

		/// <summary>
		/// Checks if the node has children
		/// </summary>
		/// <returns>The result of the check</returns>
		bool hasChildren() const { return children_.size() > 0; }

		/// <summary>
		/// Obtains the node at a given index
		/// </summary>
		/// <param name="index"> - of the node</param>
		/// <returns>The node at that index</returns>
		std::shared_ptr< Node > operator[]( unsigned int index );

		/// <summary>
		/// Adds a child to the node
		/// </summary>
		/// <param name="child"> - to add</param>
		void addChild( std::shared_ptr< Node > &&child );

		/// <summary>
		/// Removes a node
		/// </summary>
		/// <param name="node"> - to remove</param>
		void removeChild( const std::shared_ptr< Node > &node );

	//Utility functions
	public:
		/// <summary>
		/// Finds a node based on a predicate
		/// </summary>
		/// <param name="predicate"> - to check with</param>
		/// <returns>The node which returned true from the predicate</returns>
		std::shared_ptr< Node > findIf( Predicate predicate );

		/// <summary>
		/// Perform an action on the node and each of it's children
		/// </summary>
		/// <param name="action"> - to perform</param>
		void forEach( Action action );
		
		/// <summary>
		/// Sorts the children_ vector
		/// </summary>
		void sortChildren();

	//Sorting functions
	private:

		/// <summary>
		/// Sorts a given range
		/// </summary>
		/// <param name="low"> - value of the range</param>
		/// <param name="high"> - value of the range</param>
		void quickSort( NodeVec::iterator low, NodeVec::iterator high );

		/// <summary>
		/// Partitions a given range
		/// </summary>
		/// <param name="low"> - value of the range</param>
		/// <param name="high"> - value of the range</param>
		/// <returns>An iterator pointing to the partition</returns>
		NodeVec::iterator partition( NodeVec::iterator low, NodeVec::iterator high );

	//Conversion function
	public:
		/// <summary>
		/// Converts a node to a child
		/// </summary>
		/// <typeparam name="Type"> - to convert to</typeparam>
		/// <returns>The converted node</returns>
		template< typename Type > std::shared_ptr< Type > castToChild()
		{
			return std::dynamic_pointer_cast< Type >( This() );
		}
	};
}