#pragma once
/*

Name: Martin Harvey

Student ID: B00329330

I declare that the following code was produced by myself for the Algorithms & Collections - COMP09044 - module and that this is my own work.

I am aware of the penalties incurred by submitting in full or in part work that is not my own and that was developed by third parties that are not appropriately acknowledged.

*/
#include <warning.h>

#include "UtilityFunctions.h"
#include "AddEditWindow.h"

namespace InitiativeTracker {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Main Window for initiative tracker
	/// </summary>
	public ref class InitiativeWindow : public System::Windows::Forms::Form
	{
	//Variables
	private:
		Tree *initiativeTree_;
		TreeNode ^selectedNode_;

#pragma region Windows Forms Designer Constructor and Destructor
	public:
		/// <summary>
		/// Constructor for the main initiative window
		/// </summary>
		/// <param name=""></param>
		InitiativeWindow( void )
			: initiativeTree_( new Tree() )
		{
			InitializeComponent();

			ClearDetails();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~InitiativeWindow()
		{
			if ( components ) {
				delete components;
			}
		}
#pragma endregion

#pragma region Windows Forms Designer generated variables
	private:
		System::Windows::Forms::TreeView^ InitiativeTreeView;

		System::Windows::Forms::Label^ DetailsLabel;
		System::Windows::Forms::Panel^ DetailsPanel;

		System::Windows::Forms::Label^ NameIdentifierLabel;
		System::Windows::Forms::Label^ NameLabel;

		System::Windows::Forms::Label^ InitiativeIdentifierLabel;
		System::Windows::Forms::Label^ InitiativeLabel;

		System::Windows::Forms::Panel^ HPPanel;
		System::Windows::Forms::Label^ HPIdentifierLabel;
		System::Windows::Forms::NumericUpDown^ HPNumericUpDown;
		System::Windows::Forms::Label^ SlashLabel;
		System::Windows::Forms::Label^ MaxHPLabel;

		System::Windows::Forms::Button^ AddButton;
		System::Windows::Forms::Button^ EditButton;
		System::Windows::Forms::Button^ RemoveButton;
		System::Windows::Forms::Button ^ClearButton;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;
#pragma endregion

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->InitiativeTreeView = (gcnew System::Windows::Forms::TreeView());
			this->DetailsPanel = (gcnew System::Windows::Forms::Panel());
			this->InitiativeLabel = (gcnew System::Windows::Forms::Label());
			this->NameLabel = (gcnew System::Windows::Forms::Label());
			this->HPPanel = (gcnew System::Windows::Forms::Panel());
			this->HPNumericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->MaxHPLabel = (gcnew System::Windows::Forms::Label());
			this->SlashLabel = (gcnew System::Windows::Forms::Label());
			this->HPIdentifierLabel = (gcnew System::Windows::Forms::Label());
			this->InitiativeIdentifierLabel = (gcnew System::Windows::Forms::Label());
			this->NameIdentifierLabel = (gcnew System::Windows::Forms::Label());
			this->AddButton = (gcnew System::Windows::Forms::Button());
			this->EditButton = (gcnew System::Windows::Forms::Button());
			this->RemoveButton = (gcnew System::Windows::Forms::Button());
			this->ClearButton = (gcnew System::Windows::Forms::Button());
			this->DetailsLabel = (gcnew System::Windows::Forms::Label());
			this->DetailsPanel->SuspendLayout();
			this->HPPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->HPNumericUpDown))->BeginInit();
			this->SuspendLayout();
			// 
			// InitiativeTreeView
			// 
			this->InitiativeTreeView->Location = System::Drawing::Point( 12, 12 );
			this->InitiativeTreeView->Name = L"InitiativeTreeView";
			this->InitiativeTreeView->Size = System::Drawing::Size( 163, 243 );
			this->InitiativeTreeView->TabIndex = 0;
			this->InitiativeTreeView->AfterSelect += gcnew System::Windows::Forms::TreeViewEventHandler( this, &InitiativeWindow::InitiativeTreeView_AfterSelect );
			this->InitiativeTreeView->MouseDown += gcnew System::Windows::Forms::MouseEventHandler( this, &InitiativeWindow::InitiativeTreeView_MouseDown );
			// 
			// DetailsPanel
			// 
			this->DetailsPanel->Controls->Add( this->InitiativeLabel );
			this->DetailsPanel->Controls->Add( this->NameLabel );
			this->DetailsPanel->Controls->Add( this->HPPanel );
			this->DetailsPanel->Controls->Add( this->InitiativeIdentifierLabel );
			this->DetailsPanel->Controls->Add( this->NameIdentifierLabel );
			this->DetailsPanel->Location = System::Drawing::Point( 181, 38 );
			this->DetailsPanel->Name = L"DetailsPanel";
			this->DetailsPanel->Size = System::Drawing::Size( 191, 123 );
			this->DetailsPanel->TabIndex = 1;
			this->DetailsPanel->Visible = false;
			// 
			// InitiativeLabel
			// 
			this->InitiativeLabel->AutoSize = true;
			this->InitiativeLabel->Font = (gcnew System::Drawing::Font( L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
																		System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0) ));
			this->InitiativeLabel->Location = System::Drawing::Point( 106, 32 );
			this->InitiativeLabel->Name = L"InitiativeLabel";
			this->InitiativeLabel->Size = System::Drawing::Size( 30, 24 );
			this->InitiativeLabel->TabIndex = 6;
			this->InitiativeLabel->Text = L"00";
			this->InitiativeLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// NameLabel
			// 
			this->NameLabel->AutoSize = true;
			this->NameLabel->Font = (gcnew System::Drawing::Font( L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
																  static_cast<System::Byte>(0) ));
			this->NameLabel->Location = System::Drawing::Point( 83, 3 );
			this->NameLabel->Name = L"NameLabel";
			this->NameLabel->Size = System::Drawing::Size( 75, 24 );
			this->NameLabel->TabIndex = 5;
			this->NameLabel->Text = L"\"Name\"";
			// 
			// HPPanel
			// 
			this->HPPanel->Controls->Add( this->HPNumericUpDown );
			this->HPPanel->Controls->Add( this->MaxHPLabel );
			this->HPPanel->Controls->Add( this->SlashLabel );
			this->HPPanel->Controls->Add( this->HPIdentifierLabel );
			this->HPPanel->Location = System::Drawing::Point( 3, 60 );
			this->HPPanel->Name = L"HPPanel";
			this->HPPanel->Size = System::Drawing::Size( 185, 60 );
			this->HPPanel->TabIndex = 2;
			this->HPPanel->Visible = false;
			// 
			// HPNumericUpDown
			// 
			this->HPNumericUpDown->Location = System::Drawing::Point( 25, 37 );
			this->HPNumericUpDown->Maximum = System::Decimal( gcnew cli::array< System::Int32 >( 4 ) { 1000, 0, 0, 0 } );
			this->HPNumericUpDown->Name = L"HPNumericUpDown";
			this->HPNumericUpDown->Size = System::Drawing::Size( 69, 20 );
			this->HPNumericUpDown->TabIndex = 9;
			this->HPNumericUpDown->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->HPNumericUpDown->ValueChanged += gcnew System::EventHandler( this, &InitiativeWindow::HPNumericUpDown_ValueChanged );
			// 
			// MaxHPLabel
			// 
			this->MaxHPLabel->AutoSize = true;
			this->MaxHPLabel->Font = (gcnew System::Drawing::Font( L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
																   static_cast<System::Byte>(0) ));
			this->MaxHPLabel->Location = System::Drawing::Point( 118, 35 );
			this->MaxHPLabel->Name = L"MaxHPLabel";
			this->MaxHPLabel->Size = System::Drawing::Size( 30, 24 );
			this->MaxHPLabel->TabIndex = 8;
			this->MaxHPLabel->Text = L"00";
			this->MaxHPLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// SlashLabel
			// 
			this->SlashLabel->AutoSize = true;
			this->SlashLabel->Font = (gcnew System::Drawing::Font( L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
																   static_cast<System::Byte>(0) ));
			this->SlashLabel->Location = System::Drawing::Point( 100, 41 );
			this->SlashLabel->Name = L"SlashLabel";
			this->SlashLabel->Size = System::Drawing::Size( 12, 16 );
			this->SlashLabel->TabIndex = 6;
			this->SlashLabel->Text = L"/";
			// 
			// HPIdentifierLabel
			// 
			this->HPIdentifierLabel->AutoSize = true;
			this->HPIdentifierLabel->Font = (gcnew System::Drawing::Font( L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
																		  System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0) ));
			this->HPIdentifierLabel->Location = System::Drawing::Point( 0, 9 );
			this->HPIdentifierLabel->Name = L"HPIdentifierLabel";
			this->HPIdentifierLabel->Size = System::Drawing::Size( 110, 25 );
			this->HPIdentifierLabel->TabIndex = 0;
			this->HPIdentifierLabel->Text = L"Hit Points:";
			// 
			// InitiativeIdentifierLabel
			// 
			this->InitiativeIdentifierLabel->AutoSize = true;
			this->InitiativeIdentifierLabel->Font = (gcnew System::Drawing::Font( L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
																				  System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0) ));
			this->InitiativeIdentifierLabel->Location = System::Drawing::Point( 3, 31 );
			this->InitiativeIdentifierLabel->Margin = System::Windows::Forms::Padding( 3 );
			this->InitiativeIdentifierLabel->Name = L"InitiativeIdentifierLabel";
			this->InitiativeIdentifierLabel->Size = System::Drawing::Size( 97, 25 );
			this->InitiativeIdentifierLabel->TabIndex = 1;
			this->InitiativeIdentifierLabel->Text = L"Initiative:";
			// 
			// NameIdentifierLabel
			// 
			this->NameIdentifierLabel->AutoSize = true;
			this->NameIdentifierLabel->Font = (gcnew System::Drawing::Font( L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
																			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0) ));
			this->NameIdentifierLabel->Location = System::Drawing::Point( 3, 0 );
			this->NameIdentifierLabel->Margin = System::Windows::Forms::Padding( 3 );
			this->NameIdentifierLabel->Name = L"NameIdentifierLabel";
			this->NameIdentifierLabel->Size = System::Drawing::Size( 74, 25 );
			this->NameIdentifierLabel->TabIndex = 0;
			this->NameIdentifierLabel->Text = L"Name:";
			// 
			// AddButton
			// 
			this->AddButton->Font = (gcnew System::Drawing::Font( L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
																  static_cast<System::Byte>(0) ));
			this->AddButton->Location = System::Drawing::Point( 181, 167 );
			this->AddButton->Name = L"AddButton";
			this->AddButton->Size = System::Drawing::Size( 100, 41 );
			this->AddButton->TabIndex = 2;
			this->AddButton->Text = L"Add";
			this->AddButton->UseVisualStyleBackColor = true;
			this->AddButton->Click += gcnew System::EventHandler( this, &InitiativeWindow::AddButton_Click );
			// 
			// EditButton
			// 
			this->EditButton->Font = (gcnew System::Drawing::Font( L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
																   static_cast<System::Byte>(0) ));
			this->EditButton->Location = System::Drawing::Point( 287, 167 );
			this->EditButton->Name = L"EditButton";
			this->EditButton->Size = System::Drawing::Size( 92, 41 );
			this->EditButton->TabIndex = 3;
			this->EditButton->Text = L"Edit";
			this->EditButton->UseVisualStyleBackColor = true;
			this->EditButton->Click += gcnew System::EventHandler( this, &InitiativeWindow::EditButton_Click );
			// 
			// RemoveButton
			// 
			this->RemoveButton->Font = (gcnew System::Drawing::Font( L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
																	 static_cast<System::Byte>(0) ));
			this->RemoveButton->Location = System::Drawing::Point( 181, 214 );
			this->RemoveButton->Name = L"RemoveButton";
			this->RemoveButton->Size = System::Drawing::Size( 100, 41 );
			this->RemoveButton->TabIndex = 4;
			this->RemoveButton->Text = L"Remove";
			this->RemoveButton->UseVisualStyleBackColor = true;
			this->RemoveButton->Click += gcnew System::EventHandler( this, &InitiativeWindow::RemoveButton_Click );
			// 
			// ClearButton
			// 
			this->ClearButton->Font = (gcnew System::Drawing::Font( L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
																	static_cast<System::Byte>(0) ));
			this->ClearButton->Location = System::Drawing::Point( 287, 214 );
			this->ClearButton->Name = L"ClearButton";
			this->ClearButton->Size = System::Drawing::Size( 92, 41 );
			this->ClearButton->TabIndex = 5;
			this->ClearButton->Text = L"Clear";
			this->ClearButton->UseVisualStyleBackColor = true;
			this->ClearButton->Click += gcnew System::EventHandler( this, &InitiativeWindow::ClearButton_Click );
			// 
			// DetailsLabel
			// 
			this->DetailsLabel->AutoSize = true;
			this->DetailsLabel->Font = (gcnew System::Drawing::Font( L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
																	 static_cast<System::Byte>(0) ));
			this->DetailsLabel->Location = System::Drawing::Point( 184, 12 );
			this->DetailsLabel->Name = L"DetailsLabel";
			this->DetailsLabel->Size = System::Drawing::Size( 94, 29 );
			this->DetailsLabel->TabIndex = 6;
			this->DetailsLabel->Text = L"Details";
			// 
			// InitiativeWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF( 6, 13 );
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size( 384, 268 );
			this->Controls->Add( this->DetailsLabel );
			this->Controls->Add( this->ClearButton );
			this->Controls->Add( this->RemoveButton );
			this->Controls->Add( this->EditButton );
			this->Controls->Add( this->AddButton );
			this->Controls->Add( this->DetailsPanel );
			this->Controls->Add( this->InitiativeTreeView );
			this->MaximizeBox = false;
			this->Name = L"InitiativeWindow";
			this->ShowIcon = false;
			this->Text = L"Initiative Tracker";
			this->DetailsPanel->ResumeLayout( false );
			this->DetailsPanel->PerformLayout();
			this->HPPanel->ResumeLayout( false );
			this->HPPanel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->HPNumericUpDown))->EndInit();
			this->ResumeLayout( false );
			this->PerformLayout();

		}
#pragma endregion

#pragma region Helper Functions
	private:

		/// <summary>
		/// Empties details labels, numericUpDown and hides the panels
		/// </summary>
		void ClearDetails()
		{
			NameLabel->Text = "";
			InitiativeLabel->Text = "";
			MaxHPLabel->Text = " 0";
			HPNumericUpDown->Text = "0";
			DetailsPanel->Visible = false;
			HPPanel->Visible = false;
		}

		/// <summary>
		/// Updates the InitiativeTreeView
		/// </summary>
		void UpdateTree()
		{
			InitiativeTreeView->Nodes->Clear();

			initiativeTree_->Sort();

			TreeNode ^root = ToTreeNode( initiativeTree_->GetRoot() );

			for ( int i = 0; i < root->Nodes->Count; ++i )
				InitiativeTreeView->Nodes->Add( root->Nodes[i] );

			selectedNode_ = nullptr;

			ClearDetails();
		}

		/// <summary>
		/// Gets the key from the selected node
		/// </summary>
		/// <returns></returns>
		unsigned int GetSelectedKey()
		{
			return Convert::ToUInt32( selectedNode_->Tag->ToString() );
		}

#pragma endregion

#pragma region Adding New Nodes Helper Functions

		/// <summary>
		/// Sets the properties of the given window
		/// </summary>
		/// <param name="window"> - to set the properties of</param>
		/// <param name="name"> - to give the window</param>
		void SetWindowProperties( AddEditWindow ^window, String ^name )
		{
			window->Text = name;
			window->StartPosition = FormStartPosition::Manual;
			window->Location = this->Location;
			window->ShowDialog();
		}

		/// <summary>
		/// Add a node to the initiative tree
		/// </summary>
		void AddGeneralNode()
		{
			AddEditWindow ^addWindow = gcnew AddEditWindow();
			SetWindowProperties( addWindow, "Add Item" );

			if ( std::shared_ptr< Node > nodeToAdd = addWindow->GetNode() ) {
				initiativeTree_->AddNode( nodeToAdd );
				UpdateTree();
			}
		}

		/// <summary>
		/// Add multiple children to a group in the initiative tree
		/// </summary>
		/// <param name="parent">  - containing the children to add</param>
		/// <param name="group"> - to add the children to</param>
		void AddMultipleChildren( std::shared_ptr< Node > parent, std::shared_ptr< Group > group )
		{
			for ( unsigned int i = 0; i < parent->numChildren(); i++ ) {
				(*parent)[i]->setInitiative( group->getInitiative() );
				initiativeTree_->AddNodeToGroup( (*parent)[i], group->getKey() );
			}

			UpdateTree();
		}

		/// <summary>
		/// Add a child node to a group in the initiative tree
		/// </summary>
		/// <param name="group"> - to add the child to</param>
		void AddChildNode( std::shared_ptr< Group > group )
		{
			AddEditWindow ^addWindow = gcnew AddEditWindow( group );
			SetWindowProperties( addWindow, "Add Item" );

			if ( std::shared_ptr< Node > nodeToAdd = addWindow->GetNode() ) {

				if ( nodeToAdd->hasChildren() )
					return AddMultipleChildren( nodeToAdd, group );

				nodeToAdd->setInitiative( group->getInitiative() );
				initiativeTree_->AddNodeToGroup( nodeToAdd, group->getKey() );

				UpdateTree();
			}
		}
#pragma endregion

#pragma region Event Callbacks
	private:
		/// <summary>
		/// Updates selected node's hit points
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		/// <returns></returns>
		System::Void HPNumericUpDown_ValueChanged( System::Object ^sender, System::EventArgs ^e )
		{
			if ( selectedNode_ == nullptr ) return;

			auto character = initiativeTree_->FindNode( GetSelectedKey() )->castToChild< Character >();
			if ( character == nullptr ) return;

			character->setHealth( Convert::ToInt32( HPNumericUpDown->Value ) );

			if( character->isInGroup() )
				selectedNode_->Text = MarshalAs< String ^ >( character->getName() + " - HP: " + std::to_string( character->getHealth() ) );
		}

		/// <summary>
		/// Displays information in the details panel when a node is selected
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		/// <returns></returns>
		System::Void InitiativeTreeView_AfterSelect( System::Object ^sender, System::Windows::Forms::TreeViewEventArgs ^e )
		{
			selectedNode_ = InitiativeTreeView->SelectedNode;

			auto node = initiativeTree_->FindNode( GetSelectedKey() );

			DetailsPanel->Visible = true;
			NameLabel->Text = MarshalAs< String ^ >( node->getName() );
			InitiativeLabel->Text = MarshalAs< String ^ >( std::to_string( node->getInitiative() ) );

			auto character = node->castToChild< Character >();
			if ( character == nullptr ) return;

			HPPanel->Visible = true;
			MaxHPLabel->Text = MarshalAs< String ^ >( std::to_string( character->getMaxHealth() ) );
			HPNumericUpDown->Maximum = character->getMaxHealth();
			HPNumericUpDown->Value = character->getHealth();
		}

		/// <summary>
		/// Deselects the selected node and clears the details panel when the TreeView panel is clicked
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		/// <returns></returns>
		System::Void InitiativeTreeView_MouseDown( System::Object ^sender, System::Windows::Forms::MouseEventArgs ^e )
		{
			InitiativeTreeView->SelectedNode = nullptr;
			selectedNode_ = nullptr;

			ClearDetails();
		}

#pragma endregion

#pragma region Button Click Callbacks
		/// <summary>
		/// Opens an AddEditWindow, then adds the node it creates to the tree
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		/// <returns></returns>
		System::Void AddButton_Click( System::Object^ sender, System::EventArgs^ e )
		{
			if ( selectedNode_ == nullptr )
				return AddGeneralNode();

			if ( std::shared_ptr< Group > parent = initiativeTree_->FindGroup( GetSelectedKey() ) )
				return AddChildNode( parent );

			DisplayWarningMessage( "Cannot add a child to a character." );
		}

		/// <summary>
		/// Opens an AddEditWindow, and updates the node based on the changes
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		/// <returns></returns>
		System::Void EditButton_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if ( selectedNode_ == nullptr )
				return DisplayWarningMessage( "No node is selected." );

			auto nodeToEdit = initiativeTree_->FindNode( GetSelectedKey() );

			AddEditWindow ^editWindow = gcnew AddEditWindow( nodeToEdit );
			SetWindowProperties( editWindow, "Edit item" );

			UpdateTree();
		}

		/// <summary>
		/// Removes the selected node
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		/// <returns></returns>
		System::Void RemoveButton_Click( System::Object ^sender, System::EventArgs ^e )
		{
			if ( selectedNode_ == nullptr )
				return DisplayWarningMessage( "No node is selected." );

			initiativeTree_->RemoveNode( GetSelectedKey() );

			selectedNode_ = nullptr;

			UpdateTree();
		}

		/// <summary>
		/// Clears the initiative tree
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		/// <returns></returns>
		System::Void ClearButton_Click( System::Object ^sender, System::EventArgs ^e )
		{
			if ( initiativeTree_->Size() == 0 )
				return DisplayWarningMessage( "Initiative is already empty." );

			initiativeTree_->Clear();
			UpdateTree();
		}
#pragma endregion
};
}