#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct jobs
{
	char cmd[255];
	pid_t *pidList;
	struct jobs *next;
}Jobs;
Jobs* appendList(Jobs* head,char *cmd,pid_t* pidList)
{
		Jobs* newNode = malloc(sizeof(Jobs));
		strcpy(newNode->cmd,cmd);
		newNode->pidList = pidList;
		newNode->next = NULL;
		// Find the last node
		if(head == NULL)
		{
			return newNode;
		}
		Jobs* temp;
		for(temp = head;temp->next != NULL;temp=temp->next);
		temp->next = newNode;
		return head;
}
void printList(Jobs* head)
{
	if(head == NULL)
	{
		printf("No Suspended Jobs\n");
		return;
	}

	Jobs* temp;
	int i = 1;
	for(temp=head;temp != NULL;temp=temp->next,i++)
	{
		printf("[%d] %s\n",i,temp->cmd);
	}
}
Jobs* deleteNode(Jobs*head,int id)
{
	Jobs* temp = head;
	int i;
	if(head == NULL)
	{
		return NULL;
	}
	else if (id == 1)
	{
		Jobs* newHead = head->next;
		free(head->pidList);
		free(head);
		return newHead;
	}
	else
	{
		for(i = 0;temp !=NULL && i != id-1;i++,temp=temp->next);
		if(temp->next != NULL)
		{
				Jobs* delPtr = temp->next;
				temp->next = temp->next->next;
				free(delPtr->pidList);
				free(delPtr);
		}
	}
}
int main (int argc,char *argv[])
{
	Jobs* jobList = NULL;
	char cmd1[] = "ls -al";
	char cmd2[] = "cat | cat";
	pid_t *pids = malloc(sizeof(pid_t)*2);
	pid_t *pids2 = malloc(sizeof(pid_t)*2);
	jobList = appendList(jobList,cmd1,pids);
	jobList = appendList(jobList,cmd2,pids2);
	// jobList = deleteNode(jobList,1);
	// jobList = deleteNode(jobList,1);
	// jobList = appendList(jobList,2,NULL,NULL);
	printList(jobList);
	return 0;
}
