#pragma once
/*

Name: Martin Harvey

Student ID: B00329330

I declare that the following code was produced by myself for the Algorithms & Collections - COMP09044 - module and that this is my own work.

I am aware of the penalties incurred by submitting in full or in part work that is not my own and that was developed by third parties that are not appropriately acknowledged.

*/
#include <memory>
#include <string>
#include <msclr/marshal_cppstd.h>

#include "Node.h"
#include "Group.h"
#include "Character.h"
#include "Tree.h"

namespace InitiativeTracker {

	using namespace System;
	using namespace System::Windows::Forms;

	/// <summary>
	/// Aliases CLI marshal_as
	/// </summary>
	/// <typeparam name="ToType"> - type to convert to</typeparam>
	/// <typeparam name="FromType"> - type to convert from </typeparam>
	/// <param name="item"> - to convert </param>
	/// <returns> item converted to given type </returns>
	template< typename ToType, typename FromType > inline ToType MarshalAs( const FromType &item )
	{
		return msclr::interop::marshal_as< ToType >( item );
	}

	/// <summary>
	/// Display a Message box with the provided warning message
	/// </summary>
	/// <param name="message"> -  to display </param>
	void DisplayWarningMessage( System::String ^message )
	{
		MessageBox::Show(
			message, "Warning",
			MessageBoxButtons::OK, MessageBoxIcon::Warning
		);
	}

	/// <summary>
	/// Obtains the name of a node, with HP value if it is in a group or initiative otherwise
	/// </summary>
	/// <param name="node"> - to get the name of</param>
	/// <returns>A string of the node's name</returns>
	std::string GetNodeName( const std::shared_ptr< Node > node )
	{
		if ( node->isInGroup() )
			return node->getName() + " - HP: " + std::to_string( node->castToChild< Character >()->getHealth() );

		return node->getName() + " - " + std::to_string( node->getInitiative() );
	}

	/// <summary>
	/// Converts Nodes to CLI TreeNodes
	/// </summary>
	/// <param name="node"> - to convert</param>
	/// <returns>The resultant TreeNode</returns>
	TreeNode ^ToTreeNode( const std::shared_ptr< Node > &node )
	{
		String ^description = MarshalAs<String ^>( GetNodeName( node ) );

		if ( !node->hasChildren() ) {

			TreeNode ^treeNode = gcnew TreeNode( description );
			treeNode->Tag = node->getKey();
			return treeNode;
		}

		array< TreeNode ^ > ^kids = gcnew array< TreeNode ^ >( node->numChildren() );

		for ( unsigned int i = 0; i < node->numChildren(); i++ )
			kids[i] = ToTreeNode( (*node)[i] );

		TreeNode ^treeNode = gcnew TreeNode( description, kids );
		treeNode->Tag = node->getKey();
		return treeNode;
	}
}