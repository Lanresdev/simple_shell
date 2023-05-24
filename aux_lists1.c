#include "shell.h"

/**
 * add_rvar_node - a variable is added at the end
 * of a r__var list.
 * @head: the head of the linked list.
 * @lvar: the length of the variable.
 * @val: value of the variable.
 * @lval: length of the value.
 * Return: address of the head.
 */
r__var *add_rvar_node(r__var **head, int lvar, char *val, int lval)
{
	r__var *new, *temp;

	new = malloc(sizeof(r__var));
	if (new == NULL)
		return (NULL);

	new->len_var = lvar;
	new->val = val;
	new->len_val = lval;

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
 * free_rvar_list - frees a r__var list
 * @head: the head of the linked list.
 * Return: no return.
 */
void free_rvar_list(r__var **head)
{
	r__var *temp;
	r__var *curr;

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