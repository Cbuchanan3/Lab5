#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
    node *temp = head;
    int i = 0;

    while(temp != NULL)
        {
            i++;
            temp = temp->next;
        }

        return i;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
    node* temp = head;
    int i = 0, len = length(temp);
    char *cstring = (char*)malloc(sizeof(char) * (len + 1));

        for(i = 0; i < len; i++)
        {
            cstring[i] = temp->letter;
            temp = temp->next;
        }
            cstring[i] = '\0';

    return cstring;
}

// inserts character to the linkedlist
// if the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
    node* new = (node*)malloc(sizeof(node));
    node* temp = *pHead;

    if(temp == NULL)
    {
        new->letter = c;
        new->next = NULL;
        *pHead = new;

        return;
    }
   
        new->letter = c;
        new->next = NULL;

        while(temp->next != NULL)
            temp = temp->next;

        temp->next = new;

}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
    node* temp = (*pHead)->next;
    
    while(temp != NULL)
    {
        free(*pHead);
        *pHead = temp;
        temp = (*pHead)->next;
    }
    
    free(*pHead);
    *pHead = NULL;
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);

	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}
