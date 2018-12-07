#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>

using namespace std;

struct Edge
{
        int source, destination, cost, duration;
};

struct Graph
{
        int V,E;
        struct Edge* edge;
};

struct Graph* createGraph(int V, int E)
{
        struct Graph* graph=(struct Graph*) malloc(sizeof(struct Graph));
        graph->V=V;
        graph->E=E;
        graph->edge=(struct Edge*)malloc(graph->E*sizeof(struct Edge));
        return graph;
};
void Solution(int duration[], int n, int end)
{
        int i;
        for(i=0; i<n; i++)
        {
                        if(i==end)
                        {
                                if(duration[i]==2147483647) //no flight found
                                        cout<<"0";
                                else
                                        cout<<duration[i];
                        }
                        //cout<<i<<" \t\t duration: "<<duration[i]<<endl;
                        //cout<<i<<" \t\t cost:     "<<cost[i]<<endl;
        }
}

void BellmanFord(struct Graph* graph, int source, int end, int maxPrice)
{
        int V=graph->V;
        int E=graph->E;
        int StoreDuration[V];
        int StoreCost[V];
        int i, j;

        for(i=0; i<V; i++)
        {
                StoreDuration[i]=2147483647;
                StoreCost[i]=2147483647;
        }

        StoreDuration[source]=0;
        StoreCost[source]=0;

        for(i=1; i<=V-1; i++)
        {
                for(j=0; j<E; j++)
                {
                        int u=graph->edge[j].source;
                        int v=graph->edge[j].destination;
                        int cost=graph->edge[j].cost;
                        int duration=graph->edge[j].duration;
                        //cout<<u<<" $"<<StoreCost[u]<<" ";
                        //cout<<"duration: "<<StoreDuration[u]<<endl;
                        //cout<<maxPrice<<endl;
                        //cout<<"Total Cost: "<<cost+StoreCost[u]<<" Total Duration: "<<StoreDuration[u]+duration<<endl;
                        if(StoreDuration[u]!=2147483647&&StoreDuration[u]+duration<StoreDuration[v]&&StoreCost[u]+cost<=maxPrice)
                        {
                                //cout<<u<<" "<<v<<endl<<endl;
                                StoreDuration[v]=StoreDuration[u]+duration;
                                StoreCost[v]=StoreCost[u]+cost;
                        }
                }
        }
        for(i=0; i<E; i++)
        {
                int u=graph->edge[j].source;
                int v=graph->edge[j].destination;
                //int cost=graph->edge[j].cost;
                int duration=graph->edge[j].duration;
                if(StoreDuration[u]+duration<StoreDuration[v])
                        cout<<"Negative Edge Cycle"<<endl;
        }
        Solution(StoreDuration,V,end);
        return;

}


int main(int argc, char* argv[])
{
        ifstream inFile;
        inFile.open(argv[1]);
        if(!inFile)
        {
                cout<<"Unable to open file";
                exit(1);
        }
        if(argc<4)
                cout<<"Too few arguments"<<endl;
        int start, end, totalCost;
        start=atoi(argv[2]);
        end=atoi(argv[3]);
        totalCost=atoi(argv[4]);
        int V;
        inFile>>V;
        int E;
        inFile>>E;
        int x;
        struct Graph* graph=createGraph(V,E);
        int i;
        for(i=0; i<E; i++)
        {
                inFile>>x;
                graph->edge[i].source=x;
                inFile>>x;
                graph->edge[i].destination=x;
                inFile>>x;
                graph->edge[i].cost=x;
                inFile>>x;
                graph->edge[i].duration=x;
        }

        BellmanFord(graph, start, end, totalCost);

        cout << endl;
        inFile.close();
        return 0;
}
