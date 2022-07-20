#pragma once
/*

Name: Martin Harvey

Student ID: B00329330

I declare that the following code was produced by myself for the Algorithms & Collections - COMP09044 - module and that this is my own work.

I am aware of the penalties incurred by submitting in full or in part work that is not my own and that was developed by third parties that are not appropriately acknowledged.

*/
#include "UtilityFunctions.h"

namespace InitiativeTracker {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Enum of node types
	/// </summary>
	enum NodeType {
		Unselected = -1,
		GroupNode = 0,
		CharacterNode = 1,
	};

	/// <summary>
	/// Wrapper for std::shared_ptr
	/// </summary>
	struct Node_ptr
	{
		std::shared_ptr< Node > ptr;
	};

	/// <summary>
	/// Container for data to create nodes with
	/// </summary>
	struct NodeData
	{
		std::string name;
		unsigned int initiative;
		int maxHP;
		int hitPoints;
	};

	/// <summary>
	/// Window for adding nodes to the tree or editing existing nodes
	/// </summary>
	public ref class AddEditWindow : public System::Windows::Forms::Form
	{
	//Variables
	private:
		static unsigned int keyAccum = 0;
		
		Node_ptr* nodeToAddEdit_;

		bool isEditing = false;

#pragma region Windows Forms Designer Constructor and Destructor

	public:
		/// <summary>
		/// Constructor for adding a node
		/// </summary>
		AddEditWindow( void )
			: nodeToAddEdit_( new Node_ptr{} )
		{
			InitializeComponent();
		}

		/// <summary>
		/// Constructor for adding a child to a group
		/// </summary>
		/// <param name="group"> - to add the child to</param>
		AddEditWindow( std::shared_ptr< Group > group )
			: nodeToAddEdit_( new Node_ptr{} )
		{
			InitializeComponent();
			
			ChoiceListBox->SelectedIndex = NodeType::CharacterNode;
			ChoiceListBox->Enabled = false;
			AmountPanel->Visible = true;

			//Default the name to group name with a trailing number
			NameTextBox->Text = MarshalAs< String ^ >( group->getName() );

			InitativeNumericUpDown->Value = group->getInitiative();
			InitativeNumericUpDown->Enabled = false;
		}

		/// <summary>
		/// Constructor for editing a node
		/// </summary>
		/// <param name="node"> - to edit</param>
		AddEditWindow( std::shared_ptr< Node > node )
			: nodeToAddEdit_( new Node_ptr{ node } ),
			  isEditing( true )
		{
			InitializeComponent();

			NameTextBox->Text = MarshalAs< String ^ >( node->getName() );
			InitativeNumericUpDown->Value = node->getInitiative();

			ChoiceListBox->Enabled = false;

			if ( auto character = node->castToChild< Character >() ) {

				ChoiceListBox->SelectedIndex = NodeType::CharacterNode;
				HPNumericUpDown->Value = character->getHealth();
				MaxHPNumericUpDown->Value = character->getMaxHealth();
				return;
			}

			ChoiceListBox->SelectedIndex = NodeType::GroupNode;
		}

	protected:
		/// <summary>
		/// Clean up any resources
		/// </summary>
		~AddEditWindow()
		{
			if ( components ) {
				delete components;
			}

			delete nodeToAddEdit_;
		}

#pragma endregion

#pragma region Windows Forms Designer generated variables

	private:
		System::Windows::Forms::Label^ DetailsLabel;
		System::Windows::Forms::ListBox^ ChoiceListBox;

		System::Windows::Forms::Panel^ DetailsPanel;
		System::Windows::Forms::Label^ NameLabel;
		System::Windows::Forms::TextBox^ NameTextBox;
		System::Windows::Forms::Label^ InitiativeLabel;
		System::Windows::Forms::NumericUpDown^ InitativeNumericUpDown;

		System::Windows::Forms::Panel ^AmountPanel;
		System::Windows::Forms::Label ^AmountLabel;
		System::Windows::Forms::NumericUpDown ^AmountNumericUpDown;

		System::Windows::Forms::Panel^ HPPanel;
		System::Windows::Forms::Label^ HPLabel;
		System::Windows::Forms::Label^ SlashLabel;
		System::Windows::Forms::NumericUpDown^ HPNumericUpDown;
		System::Windows::Forms::NumericUpDown^ MaxHPNumericUpDown;

		System::Windows::Forms::Button^ OKButton;
		System::Windows::Forms::Button^ CancelButton;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma endregion

#pragma region Windows Form Designer generated code

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->DetailsLabel = (gcnew System::Windows::Forms::Label());
			this->NameLabel = (gcnew System::Windows::Forms::Label());
			this->InitiativeLabel = (gcnew System::Windows::Forms::Label());
			this->HPPanel = (gcnew System::Windows::Forms::Panel());
			this->SlashLabel = (gcnew System::Windows::Forms::Label());
			this->HPNumericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->MaxHPNumericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->HPLabel = (gcnew System::Windows::Forms::Label());
			this->ChoiceListBox = (gcnew System::Windows::Forms::ListBox());
			this->InitativeNumericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->NameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->OKButton = (gcnew System::Windows::Forms::Button());
			this->CancelButton = (gcnew System::Windows::Forms::Button());
			this->DetailsPanel = (gcnew System::Windows::Forms::Panel());
			this->AmountPanel = (gcnew System::Windows::Forms::Panel());
			this->AmountNumericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->AmountLabel = (gcnew System::Windows::Forms::Label());
			this->HPPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->HPNumericUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->MaxHPNumericUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->InitativeNumericUpDown))->BeginInit();
			this->DetailsPanel->SuspendLayout();
			this->AmountPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->AmountNumericUpDown))->BeginInit();
			this->SuspendLayout();
			// 
			// DetailsLabel
			// 
			this->DetailsLabel->AutoSize = true;
			this->DetailsLabel->Font = (gcnew System::Drawing::Font( L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
																	 static_cast<System::Byte>(0) ));
			this->DetailsLabel->Location = System::Drawing::Point( 12, 9 );
			this->DetailsLabel->Name = L"DetailsLabel";
			this->DetailsLabel->Size = System::Drawing::Size( 98, 31 );
			this->DetailsLabel->TabIndex = 0;
			this->DetailsLabel->Text = L"Details";
			// 
			// NameLabel
			// 
			this->NameLabel->AutoSize = true;
			this->NameLabel->Font = (gcnew System::Drawing::Font( L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
																  static_cast<System::Byte>(0) ));
			this->NameLabel->Location = System::Drawing::Point( 11, 0 );
			this->NameLabel->Name = L"NameLabel";
			this->NameLabel->Size = System::Drawing::Size( 74, 25 );
			this->NameLabel->TabIndex = 1;
			this->NameLabel->Text = L"Name:";
			// 
			// InitiativeLabel
			// 
			this->InitiativeLabel->AutoSize = true;
			this->InitiativeLabel->Font = (gcnew System::Drawing::Font( L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
																		System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0) ));
			this->InitiativeLabel->Location = System::Drawing::Point( 11, 30 );
			this->InitiativeLabel->Name = L"InitiativeLabel";
			this->InitiativeLabel->Size = System::Drawing::Size( 97, 25 );
			this->InitiativeLabel->TabIndex = 2;
			this->InitiativeLabel->Text = L"Initiative:";
			// 
			// HPPanel
			// 
			this->HPPanel->Controls->Add( this->SlashLabel );
			this->HPPanel->Controls->Add( this->HPNumericUpDown );
			this->HPPanel->Controls->Add( this->MaxHPNumericUpDown );
			this->HPPanel->Controls->Add( this->HPLabel );
			this->HPPanel->Location = System::Drawing::Point( 12, 135 );
			this->HPPanel->Name = L"HPPanel";
			this->HPPanel->Size = System::Drawing::Size( 225, 60 );
			this->HPPanel->TabIndex = 3;
			this->HPPanel->Visible = false;
			// 
			// SlashLabel
			// 
			this->SlashLabel->AutoSize = true;
			this->SlashLabel->Font = (gcnew System::Drawing::Font( L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
																   static_cast<System::Byte>(0) ));
			this->SlashLabel->Location = System::Drawing::Point( 105, 25 );
			this->SlashLabel->Name = L"SlashLabel";
			this->SlashLabel->Size = System::Drawing::Size( 15, 24 );
			this->SlashLabel->TabIndex = 4;
			this->SlashLabel->Text = L"/";
			// 
			// HPNumericUpDown
			// 
			this->HPNumericUpDown->Location = System::Drawing::Point( 16, 28 );
			this->HPNumericUpDown->Maximum = System::Decimal( gcnew cli::array< System::Int32 >( 4 ) { 1000, 0, 0, 0 } );
			this->HPNumericUpDown->Name = L"HPNumericUpDown";
			this->HPNumericUpDown->Size = System::Drawing::Size( 83, 20 );
			this->HPNumericUpDown->TabIndex = 3;
			this->HPNumericUpDown->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->HPNumericUpDown->ValueChanged += gcnew System::EventHandler( this, &AddEditWindow::HPNumericUpDown_ValueChanged );
			// 
			// MaxHPNumericUpDown
			// 
			this->MaxHPNumericUpDown->Location = System::Drawing::Point( 126, 28 );
			this->MaxHPNumericUpDown->Maximum = System::Decimal( gcnew cli::array< System::Int32 >( 4 ) { 1000, 0, 0, 0 } );
			this->MaxHPNumericUpDown->Name = L"MaxHPNumericUpDown";
			this->MaxHPNumericUpDown->Size = System::Drawing::Size( 83, 20 );
			this->MaxHPNumericUpDown->TabIndex = 2;
			this->MaxHPNumericUpDown->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->MaxHPNumericUpDown->ValueChanged += gcnew System::EventHandler( this, &AddEditWindow::MaxHPNumericUpDown_ValueChanged );
			// 
			// HPLabel
			// 
			this->HPLabel->AutoSize = true;
			this->HPLabel->Font = (gcnew System::Drawing::Font( L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
																static_cast<System::Byte>(0) ));
			this->HPLabel->Location = System::Drawing::Point( 11, 0 );
			this->HPLabel->Name = L"HPLabel";
			this->HPLabel->Size = System::Drawing::Size( 104, 25 );
			this->HPLabel->TabIndex = 0;
			this->HPLabel->Text = L"Hit Points";
			// 
			// ChoiceListBox
			// 
			this->ChoiceListBox->FormattingEnabled = true;
			this->ChoiceListBox->Items->AddRange( gcnew cli::array< System::Object ^  >( 2 ) { L"Group", L"Character" } );
			this->ChoiceListBox->Location = System::Drawing::Point( 116, 9 );
			this->ChoiceListBox->Name = L"ChoiceListBox";
			this->ChoiceListBox->Size = System::Drawing::Size( 120, 30 );
			this->ChoiceListBox->TabIndex = 4;
			this->ChoiceListBox->SelectedIndexChanged += gcnew System::EventHandler( this, &AddEditWindow::ChoiceListBox_SelectedIndexChanged );
			// 
			// InitativeNumericUpDown
			// 
			this->InitativeNumericUpDown->Location = System::Drawing::Point( 126, 32 );
			this->InitativeNumericUpDown->Name = L"InitativeNumericUpDown";
			this->InitativeNumericUpDown->Size = System::Drawing::Size( 83, 20 );
			this->InitativeNumericUpDown->TabIndex = 4;
			this->InitativeNumericUpDown->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// NameTextBox
			// 
			this->NameTextBox->Location = System::Drawing::Point( 87, 5 );
			this->NameTextBox->Name = L"NameTextBox";
			this->NameTextBox->Size = System::Drawing::Size( 122, 20 );
			this->NameTextBox->TabIndex = 5;
			// 
			// OKButton
			// 
			this->OKButton->Location = System::Drawing::Point( 24, 204 );
			this->OKButton->Name = L"OKButton";
			this->OKButton->Size = System::Drawing::Size( 86, 23 );
			this->OKButton->TabIndex = 6;
			this->OKButton->Text = L"Okay";
			this->OKButton->UseVisualStyleBackColor = true;
			this->OKButton->Click += gcnew System::EventHandler( this, &AddEditWindow::OKButton_Click );
			// 
			// CancelButton
			// 
			this->CancelButton->Location = System::Drawing::Point( 138, 204 );
			this->CancelButton->Name = L"CancelButton";
			this->CancelButton->Size = System::Drawing::Size( 86, 23 );
			this->CancelButton->TabIndex = 7;
			this->CancelButton->Text = L"Cancel";
			this->CancelButton->UseVisualStyleBackColor = true;
			this->CancelButton->Click += gcnew System::EventHandler( this, &AddEditWindow::CancelButton_Click );
			// 
			// DetailsPanel
			// 
			this->DetailsPanel->Controls->Add( this->NameLabel );
			this->DetailsPanel->Controls->Add( this->InitiativeLabel );
			this->DetailsPanel->Controls->Add( this->InitativeNumericUpDown );
			this->DetailsPanel->Controls->Add( this->NameTextBox );
			this->DetailsPanel->Location = System::Drawing::Point( 12, 45 );
			this->DetailsPanel->Name = L"DetailsPanel";
			this->DetailsPanel->Size = System::Drawing::Size( 224, 55 );
			this->DetailsPanel->TabIndex = 8;
			this->DetailsPanel->Visible = false;
			// 
			// AmountPanel
			// 
			this->AmountPanel->Controls->Add( this->AmountNumericUpDown );
			this->AmountPanel->Controls->Add( this->AmountLabel );
			this->AmountPanel->Location = System::Drawing::Point( 12, 104 );
			this->AmountPanel->Name = L"AmountPanel";
			this->AmountPanel->Size = System::Drawing::Size( 224, 28 );
			this->AmountPanel->TabIndex = 9;
			this->AmountPanel->Visible = false;
			// 
			// AmountNumericUpDown
			// 
			this->AmountNumericUpDown->Location = System::Drawing::Point( 126, 2 );
			this->AmountNumericUpDown->Maximum = System::Decimal( gcnew cli::array< System::Int32 >( 4 ) { 20, 0, 0, 0 } );
			this->AmountNumericUpDown->Minimum = System::Decimal( gcnew cli::array< System::Int32 >( 4 ) { 1, 0, 0, 0 } );
			this->AmountNumericUpDown->Name = L"AmountNumericUpDown";
			this->AmountNumericUpDown->Size = System::Drawing::Size( 83, 20 );
			this->AmountNumericUpDown->TabIndex = 6;
			this->AmountNumericUpDown->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->AmountNumericUpDown->Value = System::Decimal( gcnew cli::array< System::Int32 >( 4 ) { 1, 0, 0, 0 } );
			// 
			// AmountLabel
			// 
			this->AmountLabel->AutoSize = true;
			this->AmountLabel->Font = (gcnew System::Drawing::Font( L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
																	static_cast<System::Byte>(0) ));
			this->AmountLabel->Location = System::Drawing::Point( 11, -1 );
			this->AmountLabel->Name = L"AmountLabel";
			this->AmountLabel->Size = System::Drawing::Size( 91, 25 );
			this->AmountLabel->TabIndex = 6;
			this->AmountLabel->Text = L"Amount:";
			// 
			// AddEditWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF( 6, 13 );
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size( 248, 238 );
			this->Controls->Add( this->AmountPanel );
			this->Controls->Add( this->DetailsPanel );
			this->Controls->Add( this->CancelButton );
			this->Controls->Add( this->OKButton );
			this->Controls->Add( this->ChoiceListBox );
			this->Controls->Add( this->HPPanel );
			this->Controls->Add( this->DetailsLabel );
			this->Name = L"AddEditWindow";
			this->Text = L"AddEditWindow";
			this->HPPanel->ResumeLayout( false );
			this->HPPanel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->HPNumericUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->MaxHPNumericUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->InitativeNumericUpDown))->EndInit();
			this->DetailsPanel->ResumeLayout( false );
			this->DetailsPanel->PerformLayout();
			this->AmountPanel->ResumeLayout( false );
			this->AmountPanel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->AmountNumericUpDown))->EndInit();
			this->ResumeLayout( false );
			this->PerformLayout();

		}

#pragma endregion

#pragma region Accessor Function

	public:
		/// <summary>
		/// Gets the std::shared_ptr from the wrapper struct
		/// </summary>
		/// <returns>The node to add/edit</returns>
		std::shared_ptr< Node > GetNode()
		{
			return std::move(nodeToAddEdit_->ptr);
		}

#pragma endregion

#pragma region Helper Functions

	private:
		/// <summary>
		/// Checks if the fields of the window are filled with usable data
		/// </summary>
		/// <returns>The result of the check</returns>
		bool ValidData()
		{
			//Check a node type is selected, display a warning if not
			if ( ChoiceListBox->SelectedIndex == NodeType::Unselected ) return DisplayWarningMessage( "Please select a node type." ), false;

			//Check valid name and initiative, displaying a warning if invalid
			if ( String::IsNullOrEmpty( NameTextBox->Text ) ) return DisplayWarningMessage( "Please enter a name." ), false;
			if ( InitativeNumericUpDown->Value == 0 ) return DisplayWarningMessage( "Initiative cannot be zero." ), false;
			
			//Exit early if node type is group
			if ( ChoiceListBox->SelectedIndex == NodeType::GroupNode ) return true;

			//Check valid MaxHP, displaying a warning if invalid
			if ( MaxHPNumericUpDown->Value == 0 ) return DisplayWarningMessage( "Max hit points cannot be zero." ), false;
			
			//Exit early if node type is character
			if ( ChoiceListBox->SelectedIndex == NodeType::CharacterNode ) return true;

			return false;
		}

		/// <summary>
		/// Obtains the data from the fields of the window
		/// </summary>
		/// <returns>A NodeData object containing the obtained data</returns>
		NodeData GetData()
		{
			NodeData data{};

			data.name = MarshalAs< std::string >( NameTextBox->Text );
			data.initiative = Convert::ToUInt32( InitativeNumericUpDown->Value );

			if ( ChoiceListBox->SelectedIndex == NodeType::CharacterNode ) {

				data.maxHP = Convert::ToInt32( MaxHPNumericUpDown->Value );
				data.hitPoints = Convert::ToInt32( HPNumericUpDown->Value );
			}

			return data;
		}

		/// <summary>
		/// Creates multiple characters with the given data, named with an index
		/// </summary>
		/// <param name="data"> - the characters should have</param>
		/// <returns>The parent node containing all the characters</returns>
		std::shared_ptr< Node > CreateMultipleCharacters( NodeData data )
		{
			int numToAdd = Convert::ToInt32( AmountNumericUpDown->Value );

			std::shared_ptr< Node > parent = std::make_shared< Node >();

			for ( int i = 0; i < numToAdd; i++ ) {

				parent->addChild( std::make_shared< Character >(
					data.name + std::to_string( i + 1 ),
					data.initiative,
					data.hitPoints,
					data.maxHP,
					keyAccum++ )
				);
			}

			return parent;
		}

		/// <summary>
		/// Creates a character node
		/// </summary>
		/// <param name="data"> - the character should have</param>
		/// <returns>The created node</returns>
		std::shared_ptr< Node > CreateCharacter(NodeData data)
		{
			//If the amount of characters to add is 1 (default) return one character
			if ( AmountNumericUpDown->Value == 1 )
				return std::make_shared< Character >( std::move( data.name ), data.initiative, data.hitPoints, data.maxHP, keyAccum++ );

			//Otherwise create multiple characters
			return CreateMultipleCharacters( data );
		}

		/// <summary>
		/// Creates the nodeToAddEdit
		/// </summary>
		void AddNode()
		{
			NodeData data = GetData();

			if ( ChoiceListBox->SelectedIndex == NodeType::GroupNode ) 
				nodeToAddEdit_->ptr = std::make_shared< Group >( std::move( data.name ), data.initiative, keyAccum++ );

			if ( ChoiceListBox->SelectedIndex == NodeType::CharacterNode )
				nodeToAddEdit_->ptr = CreateCharacter( data );
		}

		/// <summary>
		/// Edits the nodeToAddEdit
		/// </summary>
		void EditNode()
		{
			NodeData data = GetData();

			nodeToAddEdit_->ptr->setName( std::move( data.name ) );
			nodeToAddEdit_->ptr->setInitiative( data.initiative );

			if ( ChoiceListBox->SelectedIndex == NodeType::CharacterNode ) {

				auto character = nodeToAddEdit_->ptr->castToChild<Character>();
				character->setMaxHealth( data.maxHP );
				character->setHealth( data.hitPoints );
			}
		}
#pragma endregion

#pragma region Event Callbacks
	private:

		/// <summary>
		/// Sets which panels are active based on node type
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		/// <returns></returns>
		System::Void ChoiceListBox_SelectedIndexChanged( System::Object^ sender, System::EventArgs^ e )
		{
			HPPanel->Visible = false;
			DetailsPanel->Visible = false;
			
			if ( ChoiceListBox->SelectedIndex == NodeType::GroupNode )
				DetailsPanel->Visible = true;

			if ( ChoiceListBox->SelectedIndex == NodeType::CharacterNode ) {
				DetailsPanel->Visible = true;
				HPPanel->Visible = true;
			}
		}

		/// <summary>
		/// Caps HPNumericUpDown to always be less than or equal to MaxHPNumericUpDown
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		/// <returns></returns>
		System::Void MaxHPNumericUpDown_ValueChanged( System::Object^ sender, System::EventArgs^ e )
		{
			if ( HPNumericUpDown->Value > MaxHPNumericUpDown->Value )
				HPNumericUpDown->Value = MaxHPNumericUpDown->Value;
		}

		/// <summary>
		/// Caps MaxHPNumericUpDown to always be greater than or equal to HPNumericUpDown
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		/// <returns></returns>
		System::Void HPNumericUpDown_ValueChanged( System::Object^ sender, System::EventArgs^ e )
		{
			if ( MaxHPNumericUpDown->Value < HPNumericUpDown->Value )
				MaxHPNumericUpDown->Value = HPNumericUpDown->Value;
		}

		/// <summary>
		/// Calls the EditNode or AddNode function depending on the window's purpose
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		/// <returns></returns>
		System::Void OKButton_Click( System::Object^ sender, System::EventArgs^ e )
		{
			if ( !ValidData() ) return;

			if ( isEditing )
				EditNode();
			else
				AddNode();

			this->Close();
		}

		/// <summary>
		/// Closes the window
		/// </summary>
		/// <param name="sender"></param>
		/// <param name="e"></param>
		/// <returns></returns>
		System::Void CancelButton_Click( System::Object^ sender, System::EventArgs^ e )
		{
			this->Close();
		}
#pragma endregion
	};
}