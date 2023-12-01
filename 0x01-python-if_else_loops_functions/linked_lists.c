#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint - Prints every element within a list of type listint_t.
 * @h: Reference to the beginning of the list.
 * Return: nos of nodes
 */
size_t print_listint(const listint_t *h)
{
        const listint_t *current;
        unsigned int n; /* number of nodes */

        current = h;
        n = 0;
        while (current != NULL)
        {
                printf("%i\n", current->n);
                current = current->next;
                n++;
        }

        return (n);
}

/**
 * add_nodeint_end - this adds new node at the end of a listint_t list
 * @head: Pointer storing initial node's address in listint_t list.
 * @n: int value to be included in new node
 * Return: Memory location of the new element or NULL if unsuccessful.
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
        listint_t *new;
        listint_t *current;

        current = *head;

        new = malloc(sizeof(listint_t));
        if (new == NULL)
                return (NULL);

        new->n = n;
        new->next = NULL;

        if (*head == NULL)
                *head = new;
        else
        {
                while (current->next != NULL)
                        current = current->next;
                current->next = new;
        }

        return (new);
}

/**
 * free_listint - Deallocates memory occupied by a listint_t list.
 * @head: Pointer to the list intended for deallocation.
 * Return: empty
 */
void free_listint(listint_t *head)
{
        listint_t *current;

        while (head != NULL)
        {
                current = head;
                head = head->next;
                free(current);
        }
}

