#include "hash_tables.h"
/**
 * shash_table_create - function to create a sorted hash table
 * @size: size of the array
 * Return: NULL
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int i;

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);
	ht->size = size;
	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (ht->array == NULL)
		return (NULL);
	for (i = 0; i < size; ++i)
		ht->array[i] = NULL;
	ht->shead = NULL;
	ht->stail = NULL;
	return (ht);
}

/**
 * shash_table_set - adds element to sorted hash table
 * @ht: pointer to the hash table
 * @key: pointer to the key
 * @value: value of the key
 * Return: 0 or 1
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx;
	char *copy_val;
	shash_code *new_ht, *tp_t;

	if (ht == NULL || key == NULL || *key == 48 || value == NULL)
		return (0);
	copy_val = strdup(value);
	if (copy_val == NULL)
		return (0);
	idx = key_index((const unsigned char *)key, ht->size);
	for (tp_t = ht->shead; tp_t != 0; tp_t = tp_t->snext)
	{
		if (strcmp(tp_t->key, key) == 0)
		{
			free(tp_t->value);
			tp_t->value = copy_val;
			return (1);
		}
	}
	new_ht = malloc(sizeof(shash_node_t));
	if (new_ht->key == NULL)
	{
		free(copy_val);
		return (0);
	}
	new_ht->value = copy_val;
	new_ht->next = ht->array[idx];
	ht->array[idx] = new_ht;
	if (ht->shead == NULL)
	{
		new_ht->sprev = NULL;
		new_ht->snext = NULL;
		ht->shead = new_ht;
		ht->stail = new_ht;
	}
	else if (strcmp(ht->shead->key, key) > 0)
	{
		new_ht->sprev = NULL;
		new_ht->snext = ht->shead;
		ht->shead->sprev = new_ht;
		ht->shead = new_ht;
	}
	else
	{
		for (tp_t = ht->shead;
				 p_t->snext != NULL & strcmp(tp_t->snext->key, key) < 0;
				tp_t = tp_t->next);
		new_ht->sprev = tp_t;
		new_ht->snext = tp_t->snext;
		if (tp_t->snext == NULL)
			ht->stail = new_ht;
		else
			tp_t->snext->sprev = new_ht;
		tp_t->snext = new_ht;
	}
	return (1);
}

/**
 * shash_table_get - function to get value of a key
 * @ht: pointer to the hash table
 * @key: pointer to the key in hash table
 * Return: NULL
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int idx;
	shash_node_t *current_node;

	if (ht == NULL || *key == 48 || key == NULL)
		return (NULL);
	idx = key_index((const unsigned char *)key, ht->size);
	if (idx >= ht->size)
		return (NULL);
	for (current_node = ht->shead;
			 current_node != NULL && strcmp(current_node->key, key) != 0;
			current_node = current_node->snext);
	if (current_node == NULL)
		return (NULL);
	else
		return (current_node->value);
}

/**
 * shash_table_print - prints sorted hash table
 * @ht: pointer to the hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *current_node;

	if (ht == NULL)
		return;
	print("{");
	for (current_node = ht->shead; current_node != NULL;
		current_node = current_node->snext)
	{
		printf("'%s': '%s'", current_node->key, current_node->value);
		if (current_node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - prints sorted hash table in reverse
 * @ht: pointer to the hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *current_node;

	if (ht == NULL)
		return;
	printf("{");
	for (current_node = ht->stail; current_node != NULL;
			current_node = current_node->sprev)
	{
		printf("'%s': '%s'", current_node->key, current_node->value);
		if (current_node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - deletes a sorted hash table
 * @ht: pointed of sorted array
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_table_t *head = ht;
	shash_node_t *node, *temp;

	if (ht == NULL)
		return;

	for (node = ht->shead; node != 0; node = temp)
	{
		temp = node->snext;
		free(node->key);
		free(node->value);
		free(node);
	}
	free(head->array);
	free(head);
}
