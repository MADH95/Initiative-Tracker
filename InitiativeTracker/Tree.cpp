/*

Name: Martin Harvey

Student ID: B00329330

I declare that the following code was produced by myself for the Algorithms & Collections - COMP09044 - module and that this is my own work.

I am aware of the penalties incurred by submitting in full or in part work that is not my own and that was developed by third parties that are not appropriately acknowledged.

*/
#include "Tree.h"

namespace InitiativeTracker {


    Tree::Tree() 
        : root_( std::make_shared< Node >( "Initiative", 100, UNFINDABLE ) ),
          count_( 0 )
    {
    }

    std::shared_ptr< Node > Tree::FindNode( unsigned int key )
    {
        return root_->findIf( [&]( auto &&node ) {
            return node->getKey() == key;
        } );
    }

    std::shared_ptr< Group > Tree::FindGroup( unsigned int key )
    {
        auto node = FindNode( key );
        return node->castToChild<Group>();
    }

    void Tree::AddNode( std::shared_ptr< Node > &node )
    {
        root_->addChild( std::move( node ) );
        count_++;
    }

    void Tree::AddNodeToGroup( std::shared_ptr< Node > &node, unsigned int key)
    {
        auto group = FindGroup( key );
        if ( group == nullptr ) return;

        node->addedToGroup();
        group->addChild( std::move( node ) );
        count_++;
    }

    void Tree::RemoveNode( unsigned int key )
    {
        auto nodeToRemove = FindNode( key );
        if ( nodeToRemove == nullptr ) return;

        root_->removeChild( nodeToRemove );
        count_--;
    }

    void Tree::Clear()
    {
        root_ = std::make_shared< Node >( "Initiative", 100, UNFINDABLE );
        count_ = 0;
    }

    void Tree::Sort()
    {
        root_->sortChildren();
    }
}