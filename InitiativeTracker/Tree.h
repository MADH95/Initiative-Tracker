#pragma once
/*

Name: Martin Harvey

Student ID: B00329330

I declare that the following code was produced by myself for the Algorithms & Collections - COMP09044 - module and that this is my own work.

I am aware of the penalties incurred by submitting in full or in part work that is not my own and that was developed by third parties that are not appropriately acknowledged.

*/
#include <iostream>

#include "Node.h"
#include "Group.h"
#include "Character.h"

namespace InitiativeTracker {

	/// <summary>
	/// Tree data structure
	/// </summary>
	class Tree
	{
		static constexpr unsigned int UNFINDABLE = UINT_MAX;

		//Variables
	private:
		std::shared_ptr< Node > root_;
		unsigned int count_;

		//Constructor & Destructor
	public:
		/// <summary>
		/// Tree Constructor
		/// </summary>
		explicit Tree();

		/// <summary>
		/// Tree Destructor
		/// </summary>
		~Tree() = default;

		//Functions
	public:
		/// <summary>
		/// Size of the tree
		/// </summary>
		/// <returns>The number of nodes in the tree</returns>
		unsigned int Size() const { return count_; }

		/// <summary>
		/// Get root node
		/// </summary>
		/// <returns>The root node of the tree</returns>
		std::shared_ptr< Node > GetRoot() { return root_; }

		/// <summary>
		/// Finds a node in the tree
		/// </summary>
		/// <param name="key"> - of node to find</param>
		/// <returns>The found node</returns>
		std::shared_ptr< Node > FindNode( unsigned int key );

		/// <summary>
		/// Find a group in the tree
		/// </summary>
		/// <param name="key"> - of group to find</param>
		/// <returns>The found group</returns>
		std::shared_ptr< Group > FindGroup( unsigned int key );

		/// <summary>
		/// Add a node to the tree
		/// </summary>
		/// <param name="node"> - to add</param>
		void AddNode( std::shared_ptr< Node > &node );

		/// <summary>
		/// Add a node to a group in the tree
		/// </summary>
		/// <param name="node"> - to add</param>
		/// <param name="key"> - of the group to add to</param>
		void AddNodeToGroup( std::shared_ptr< Node > &node, unsigned int key );

		/// <summary>
		/// Remove a node from the tree
		/// </summary>
		/// <param name="key"> - of the node to remove</param>
		void RemoveNode( unsigned int key );

		/// <summary>
		/// Remove all nodes from the tree
		/// </summary>
		void Clear();

		/// <summary>
		/// Sort the tree based on initiative
		/// </summary>
		void Sort();
	};
}