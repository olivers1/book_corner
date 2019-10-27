#include "Core.h"
#include <iostream>

using namespace std;

void Core::Initialize()
{
    Page* mainMenu = new Page("Main Menu");
    
    // set default page
    m_page = mainMenu;
    m_children = (&mainMenu->GetChildVec());
    m_parents = &(mainMenu->GetParentVec());
    
    Page* addBook = new Page("Add Book");
    Page* setTitle = new Page("Set Title");
    Page* setAuthor = new Page("Set Author");
    Page* setYear = new Page("Set Year");
    Page* setPrice = new Page("Set Price");
    Page* setStock = new Page("Set Stock");
    Page* dispBook = new Page("Display Book");
    
    Page* findBook = new Page("Find Book");
    
    // set children and parents for each page
    mainMenu->AddNChildren(2, addBook, findBook);
    addBook->AddParent(mainMenu);
    addBook->AddChild(setTitle);
    setTitle->AddParent(addBook);
    setTitle->AddChild(setAuthor);
    setAuthor->AddParent(setTitle);
    setAuthor->AddChild(setYear);
    setYear->AddParent(setAuthor);
    setYear->AddChild(setPrice);
    setPrice->AddParent(setYear);
    setPrice->AddChild(setStock);
    setStock->AddParent(setPrice);
    setStock->AddChild(dispBook);
    dispBook->AddParent(setStock);
    dispBook->AddChild(mainMenu);
}

void Core::Execute()
{
	while (m_input != -1)
	{
		ShowMenu();
		ReadInput();
		UpdateState();
	}
}

void Core::ShowMenu()
{
	cout << "\nPage: " << m_page->GetPageName();    // print current page name
    
    cout << "\nParents: ";      // print name of all parents of current page
    for(Page* parent : *m_parents)
    {
        cout << parent->GetPageName() << ", ";
    }
        
	cout << "\nChildren: ";     // print name of all children of current page
	for (Page* child : *m_children)
	{
		cout << child->GetPageName() << ", ";
	}
}

void Core::ReadInput()
{
	cout << "\nEnter selection: ";
	cin >> m_input;
	cin.ignore();
}

void Core::UpdateState()
{
	m_page = m_page->GetChild(m_input);     // update page child pointer to point at selected child menu
	m_parents = &m_page->GetParentVec();	// update parent pointer to point at the parent of current page
	m_children = &m_page->GetChildVec();	// update child vector pointer to point at children pages of new parent
}
