#pragma once

#include <iostream>
#include <deque>
#include <string>
#include <cmath>
#include <list>

#define CONTAINER1 std::deque<int>
#define CONTAINER2 std::list<int>

bool is_interger(char *str);

template <class TCONTAINER>
TCONTAINER merge (CONTAINER1 &a, CONTAINER2 &b)
{
	TCONTAINER c;

	while (a.size() && b.size())
	{
		if (a[0] > *b.begin())
		{
			c.push_back(*b.begin());
			b.erase(b.begin());
		}
		else
		{
			c.push_back(a[0]);
			a.erase(a.begin());
		}
	}
	while (a.size())
	{
		c.push_back(a[0]);
		a.erase(a.begin());
	}
	while (b.size())
	{
		c.push_back(*b.begin());
		b.erase(b.begin());
	}
	return c;
}

template <class TCONTAINER>
TCONTAINER sortmerge (TCONTAINER &a)
{
	if (a.size() <= 1)
		return a;

	CONTAINER1 b;
	CONTAINER2 c;

	typename TCONTAINER::iterator itermid = a.begin();
	for(size_t i = 0; i < a.size() / 2; i++)
		itermid++;
	for(typename TCONTAINER::iterator it = a.begin(); it != itermid; it++)
		b.push_back(*it);
	for(typename TCONTAINER::iterator it = itermid; it != a.end(); it++)
		c.push_back(*it);
	b = sortmerge(b);
	c = sortmerge(c);
	return merge<TCONTAINER>(b, c);
}