/************************************************************************
 * This program is Copyright (C) 1986-1999 by Jonathan Payne.  JOVE is  *
 * provided to you without charge, and with no warranty.  You may give  *
 * away copies of JOVE, including sources, provided that this notice is *
 * included in all the files.                                           *
 ************************************************************************/

#include "jove.h"
#include "list.h"

private List *
list_new()
{
	List	*new;

	new = (List *) emalloc(sizeof (List));
	new->car = NULL;
	return new;
}

/* push an object to the beginning of list */

UnivPtr
list_push(list, element)
register List	**list;
UnivPtr element;
{
	List	*new;

	new = list_new();
	new->cdr = *list;
	new->car = element;
	*list = new;
	return element;
}

UnivPtr
list_pop(list)
List	**list;
{
	List	*cell = *list;
	UnivPtr	element;

	if (cell == NULL)
		return NULL;

	element = cell->car;
	*list = cell->cdr;
	free((UnivPtr) cell);
	return element;
}
