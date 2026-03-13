/* Create a list with two linked nodes.
Written by:
Date:
*/
#include <stdio.h>
#include <stdlib.h>
#include "lista.h" // Header file
int main (void)
{
    // Local Definitions
    int* newData;
    int* nodeData;
    NODE* node;
    // Statements
    newData = (int*)malloc (sizeof (int));
    *newData = 7;
    node = createNode (newData);
    newData = (int*)malloc (sizeof (int));
    *newData = 75;
    node->link = createNode (newData);
    nodeData = (int*)node->dataPtr;
    printf ("Data from node 1: %d\n", *nodeData);
    nodeData = (int*)node->link->dataPtr;
    printf ("Data from node 2: %d\n", *nodeData);
return 0;
} // main