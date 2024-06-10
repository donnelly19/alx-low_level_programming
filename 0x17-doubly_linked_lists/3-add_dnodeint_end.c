#include "lists.h"
/**
 * add_dnodeint_end -  adds node at the end of list
 * @head: pointer to head of list
 * @n: value of new node
 * Return: address of new element or NULL
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	/*allocate memory for the new node*/
	dlistint_t *new_node = malloc(sizeof(dlistint_t));
	dlistint_t *current;

	if (new_node == NULL)
		return (NULL);
	/*assign value to new node*/
	new_node->n = n;
	/*set prev pointer to NULL*/
	new_node->prev = NULL;
	/*set next pointer to NULL*/
	new_node->next = NULL;

	if (*head == NULL)
		*head = new_node;
	current = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = new_node;
	new_node->prev = current;
	return (new_node);
}
