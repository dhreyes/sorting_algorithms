#include "sort.h"
void node_swap(listint_t *first, listint_t *second);

/**
 * insertion_sort_list - sorts a doubly link list in ascending order
 * @list: list to be sorted
 * Return: none
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *iterator, *node_1, *node_2;

	if (list == NULL || (*list)->next == NULL)
		return;

	temp = *list;
	iterator = temp->next;

	while (iterator)
	{
		if (temp->n > iterator->n)
		{
			node_swap(temp, iterator);
			if (*list == temp)
			{
				*list = iterator;
			}
			iterator = iterator->next;
			temp = iterator->prev;
			print_list(*list);
			node_1 = temp;
			node_2 = node_1->prev;
			while (node_2 && node_2->n > node_1->n)
			{
				printf("This is iterator: <%d>\n", iterator->n);
				printf("This is temp: <%d>\n", temp->n);
				printf("This is node_1: <%d>\n", node_1->n);
				printf("This is node_2: <%d>\n", node_2->n);
				node_swap(node_2, node_1);
				if (node_2 == *list)
				{
					*list = node_1;
				}
				print_list(*list);
				node_2 = node_1->prev;
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
		first->prev->next = first;
	second->next = first;
}
