#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 10

typedef struct _adj_list
{
	int item;
	struct _adj_list *next;
}adj_list;

typedef struct _node 
{
    int item;
   struct _node *next;
} node;

typedef struct _queue 
{
    node *top;
    int current_size;
}queue;


 typedef struct _graph 
{
	adj_list *vertices[MAX_SIZE];
	short visited[MAX_SIZE];
}graph;

graph* create_graph()

{

	graph *graph = (graph*) malloc(sizeof(graph));

	int i;

	for (i = 1; i <= MAX_SIZE - 1; i++)
	 {

		graph->vertices[i] = NULL;

		graph->visited[i] = 0;

	}

	return graph;

}

adj_list* create_adj_list(int item)

{

	adj_list *new_adj_list = (adj_list*) malloc(sizeof(adj_list));

	new_adj_list->item = item;

	new_adj_list->next = NULL;

	return new_adj_list;

}
void add_edge(graph *graph, int vertex1, int vertex2)

{

	adj_list *vertex = create_adj_list(vertex2);

	vertex->next = graph->vertices[vertex1];

	graph->vertices[vertex1] = vertex;

	//Undirected graph. Edge to the other direction as well.

	vertex = create_adj_list(vertex1);

	vertex->next = graph->vertices[vertex2];

	graph->vertices[vertex2] = vertex;

}

void dfs(graph *graph, int source)

{

	graph->visited[source] = 1;

	printf("%d\n", source);

	adj_list *adj_list = graph->vertices[source];

	while (adj_list != NULL) 
	{

		if (!graph->visited[adj_list->item])
		{

			dfs(graph, adj_list->item);

		}

		adj_list = adj_list->next;

	}

}

void bfs(graph *graph, int source)

{

	queue *queue = create_queue();

	int dequeued;

	adj_list * adj_list = graph->vertices[source];

	graph->visited[source] = 1;

	enqueue(queue, source);

	while (!is_empty(queue)) 
	{

		dequeued = dequeue(queue);

		adj_list = graph->vertices[dequeued];

		while (adj_list != NULL) 
		{

				if (!graph->visited[adj_list->item]) 
				{

					printf("%d\n", adj_list->item);

					graph->visited[adj_list->item] = 1;

					enqueue(queue, adj_list->item);

				}

				adj_list = adj_list->next;

		}

	}

}