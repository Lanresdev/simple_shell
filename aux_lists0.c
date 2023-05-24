#include "shell.h"

/**
 * add_sep_node_end - adds a separator found at the end
 * of a sep__list.
 * @head: shows head of the linked list.
 * @sep: separator found (; | &).
 * Return: address of the head.
 */
sep__list *add_sep_node_end(sep__list **head, char sep)
{
	sep__list *new, *temp;

	new = malloc(sizeof(sep__list));
	if (new == NULL)
		return (NULL);

	new->separator = sep;
	new->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*head);
}

/**
 * free_sep_list - this frees a sep__list
 * @head: the head of the linked list.
 * Return: no return.
 */
void free_sep_list(sep__list **head)
{
	sep__list *temp;
	sep__list *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp);
		}
		*head = NULL;
	}
}

/**
 * add_line_node_end - adds a command line at the end
 * of a line__list.
 * @head: the head of the linked list.
 * @line: cmd line.
 * Return: address of the head.
 */
line__list *add_line_node_end(line__list **head, char *line)
{
	line__list *new, *temp;

	new = malloc(sizeof(line__list));
	if (new == NULL)
		return (NULL);

	new->line = line;
	new->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*head);
}

/**
 * free_line_list - this frees a line__list
 * @head: the head of the linked list.
 * Return: no return.
 */
void free_line_list(line__list **head)
{
	line__list *temp;
	line__list *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp);
		}
		*head = NULL;
	}
}
