#include "Page.h"
#include <vector>
#include <iostream>
#include<stdarg.h>

using namespace std;

void Page::AddChild(Page* pageObj)
{
    m_vecChildren.push_back(pageObj);
}

void Page::AddNChildren(int num, ...)   // add n-number of children  to page
{
    va_list args;
    va_start(args, num);
    for(int i=0; i<num; i++)
    {
        Page* pageObj = va_arg(args, Page*);
        m_vecChildren.push_back(pageObj);
    }
    va_end(args);
}

Page* Page::GetChild(int& i) const
{
    return m_vecChildren[i];
}

vector<Page*>& Page::GetChildVec()
{
    return m_vecChildren;
}

void Page::AddParent(Page* pageObject)
{
    m_vecParents.push_back(pageObject);
}

void Page::AddNParents(int num, ...)    // add n-number of parents to page
{
    va_list args;
    va_start(args, num);
    for(int i=0; i<num; i++)
    {
        Page* pageObj = va_arg(args, Page*);
        m_vecParents.push_back(pageObj);
    }
    va_end(args);
}

Page* Page::GetParent(int& i) const
{
	return m_vecParents[i];
}

vector<Page*>& Page::GetParentVec()
{
    return m_vecParents;
}

const string& Page::GetPageName()
{
	return m_pageName;
}
