#include "sort.h"

/**
 * cocktail_sort_list - sorts a doubly linked list
 * @list: doubly linked list
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *temp, *iterator, *iterator2;

	if (!list || !(*list))
		return;

	temp = *list;
	iterator = temp->next;
	iterator2 = temp->prev;

	while (iterator)
	{
		if (temp->n > iterator->n)
		{
			iterator2 = iterator;
			node_swap(temp, iterator);
			if (*list == temp)
				*list = iterator;
			iterator = iterator->next;
			temp = iterator->prev;
			print_list(*list);
			while (iterator2)
			{
				if (temp->n < iterator2->n)
				{
					iterator = iterator2;
					node_swap(iterator2, temp);
					if (*list == iterator2)
						*list = temp;
					iterator2 = iterator2->prev;
					temp = iterator2->next;
					print_list(*list);
				}
				temp = iterator2;
				iterator2 = temp->prev;
			}
		}
		temp = iterator;
		iterator = iterator->next;
	}
}

/**
 * node_swap - swap nodes on a dlinklist
 * @first: first node
 * @second: second node
 * Return: none
 */
void node_swap(listint_t *first, listint_t *second)
{
	first->next = second->next;
	second->prev = first->prev;
	if (second->prev)
		second->prev->next = second;
	first->prev = second;
	if (first->next)
		first->next->prev = first;
	second->next = first;
}
