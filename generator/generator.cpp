#include <bits/stdc++.h>
#include <cinttypes>
#include <random>
#include "generator.h"
#include "graph.h"
#include "pvector.h"
#include "reader.h"
#include "timer.h"
#include "util.h"
using namespace std;
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef EdgePair<int , int> Edge;
typedef pvector<Edge> EdgeList;

int main()
{
	int scale,degree,uniform;
	printf("Please input scale:\n");
	scanf("%d",&scale);
	printf("Please input degree:\n");
	scanf("%d",&degree);
	printf("Use RMAT(or not):\n");
	scanf("%d",&uniform);
	Generator<int, int> gen(scale, degree);
    EdgeList el = gen.GenerateEL(uniform);
    printf("Edgelist size:%d\n",el.size());
    //return 0;
    int sum=0;
    printf("Edgelist:\n");
    #pragma omp parallel for
  	for (Edge* ptr=el.begin(); ptr < el.end(); ptr++)
    {
    	sum++;
    	Edge ed=*ptr;
    	printf("%d : %d %d\n",sum,ed.u,ed.v);
    }
    //printf("%d\n",el.empty());
	return 0;
}

