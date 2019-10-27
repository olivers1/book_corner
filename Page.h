#pragma once

#include <vector>
#include <iostream>

using namespace std;

class Page
{
private:
	vector<Page>* m_parent;     // pointer to vector that contains the parents of the current page
    vector<Page*> m_vecParents;  // vector containing all parents of current page
	vector<Page>* m_child;	// pointer to vector that contains the children pages of the current page
	vector<Page*> m_vecChildren;		// vector containing all children of current page
	string m_pageName;		// name of the page
public:
	Page(string pageName) : m_pageName(pageName) {}
	void AddChild(Page*);
    void AddNChildren(int, ...);
    Page* GetChild(int&) const;
    vector<Page*>& GetChildVec();
	void AddParent(Page*);
    void AddNParents(int, ...);
	Page* GetParent(int&) const;
    vector<Page*>& GetParentVec();
	const string& GetPageName();
};

