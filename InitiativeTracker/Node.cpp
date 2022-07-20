/*

Name: Martin Harvey

Student ID: B00329330

I declare that the following code was produced by myself for the Algorithms & Collections - COMP09044 - module and that this is my own work.

I am aware of the penalties incurred by submitting in full or in part work that is not my own and that was developed by third parties that are not appropriately acknowledged.

*/
#include "Node.h"

namespace InitiativeTracker {

	Node::Node( std::string &&name, unsigned int initiative, unsigned int key )
		: name_( name ), initiative_( initiative ), key_( key )
	{
	}
	

	std::shared_ptr<Node> Node::operator[]( unsigned int index )
	{
		return children_[index];
	}

	void Node::addChild( std::shared_ptr<Node> &&child )
	{
		children_.emplace_back( std::forward< std::shared_ptr< Node > >( child ) );
	}

	void Node::removeChild( const std::shared_ptr<Node> &node )
	{
		std::for_each( children_.begin(), children_.end(), [&]( auto &&child ) {
			child->removeChild( node );
		} );

		auto it = std::find( children_.begin(), children_.end(), node );
		if ( it != children_.end() )
			children_.erase( it );
	}

	std::shared_ptr<Node> Node::findIf( Predicate predicate )
	{
		for ( unsigned int i = 0; i < children_.size(); ++i ) {
			if ( auto result = children_[i]->findIf( predicate ) )
				return result;
		}

		if ( predicate( This() ) )
			return This();

		return nullptr;
	}

	void Node::forEach( Action action )
	{
		std::for_each( children_.begin(), children_.end(), [&]( auto &&child ) {
			child->forEach( action );
		} );

		action( This() );
	}

	void Node::sortChildren()
	{
		if ( children_.size() == 0 ) return;

		std::for_each( children_.begin(), children_.end(), [&]( auto &&child ) {
			child->sortChildren();
		} );

		quickSort( children_.begin(), std::prev( children_.end() ) );
	}

	void Node::quickSort( NodeVec::iterator low, NodeVec::iterator high )
	{
		if ( low >= high ) return;

		NodeVec::iterator part = partition( low, high );

		if ( part != low )
			quickSort( low, std::prev( part ) );

		quickSort( std::next( part ), high );
	}

	Node::NodeVec::iterator Node::partition( NodeVec::iterator low, NodeVec::iterator high )
	{
		NodeVec::iterator pivot = high;
		NodeVec::iterator it = low;

		for ( NodeVec::iterator jt = low; jt < high; jt++ ) {
			if ( compare( *jt, *pivot ) )
				std::iter_swap( it++, jt );
		}

		std::iter_swap( it, high );
		return it;
	}
}