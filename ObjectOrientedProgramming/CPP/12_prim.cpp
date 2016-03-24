#include <iostream>
#include <climits>
#include <cstdio>
#include <vector>
#include <queue>
#include <functional>

struct node{
	int dest;
	int wt;
    
    //User defined greater than operator to make priority queue with least wt(cost)
    bool operator > (const node& rhs)const{
        return (wt > rhs.wt);
    }
};

// typedef of priority queue
typedef std::priority_queue< node, std::vector <node> , std::greater<node> > v_n;

/*
Graph having an array of std::priority queues. each index equal to a vertex. (v_n *)
in _mst boolean array to store if vertex with index 'i' is in mst or not.
*/
class graph{
	int n, m;
	//std::priority_queue< node, std::vector <node> , std::greater<int> > *v_n;
	bool *in_mst;
	v_n *arr;

public:
	//ONE AND ONLY CONSTRUCTOR. NO DEFAULT CONSTRUCTOR.
	graph(int x, int y){
		n = x;
		m = y;
		arr = new v_n[n+1];
		in_mst = new bool[n+1];
        for(int i = 0; i <= n; i++)
            in_mst[i] = false;
	}
    
    
    //DESTRUCTOR
    ~graph(){
        delete [] arr;
        delete [] in_mst;
    }
	//Generate Prims_mst
	void prims_mst(void);

	//Add edge to graph.
	void add_edge(int src, int dest, int cost){
		node temp;
		temp.dest = dest;
		temp.wt = cost;
		arr[src].push(temp);
	}

};

void graph::prims_mst(void){
    int dst, i, min_vertex, min_cost ;
    in_mst[1] = true;
    int total_in_mst = 1;
    
    unsigned int sum = 0;
    
    min_cost = (arr[1].top()).wt;
    
    while( total_in_mst < n ){
        /*for(int j = 1; j<=n; j++){
        		std::cout <<  in_mst[j]  <<" ";
    		}	
    		std::cout << "\n\n";*/
        min_cost = INT_MAX;
        min_vertex = 0;
        for(i = 1; i <= n; i++){
            
            //While there are edges to vertices which are already in mst, pop the edges.
            
            while(  !arr[i].empty() && in_mst[ (arr[i].top()).dest ] && in_mst[ i ] ){
                arr[i].pop();
            }
            
        
            
            if(  !arr[i].empty() && in_mst[ i ] &&  !in_mst[ (arr[i].top()).dest ] && (arr[i].top()).wt < min_cost){
                min_cost = (arr[i].top()).wt;
                min_vertex = i;
            }
            
        }
        sum += min_cost;
       
        std::cout << "In mst : Edge # " << total_in_mst << ": " << min_vertex << " < - - > " << (arr[min_vertex].top()).dest;
        std::cout << " with cost : " << min_cost << "\n";

        total_in_mst ++;

        in_mst[(arr[min_vertex].top()).dest] = true;

        if(!arr[min_vertex].empty() )
            arr[min_vertex].pop();
        
    }
    std::cout << "\n\tMinimum Cost is : " << sum << "\n";
    
}


int main(void){
	int n, m, wt, src, dest, i ;
	std::cout << "Enter the number of vertices in the graph and the number of edges with a space in between.\n";
	std::cin >> n >> m;
	if(n < 3 || n > 250 || m < n || m > 250){
		std::cout << "Incorrect Value Entered. Bye! Try Again.\n";
		return 0;
	}
	graph g(n,m);
	for(i = 0;i < m; i++){
		std::cin >> src >> dest >> wt;
		g.add_edge(src, dest, wt);
		g.add_edge(dest, src, wt);
    }
    g.prims_mst();




	return 0;
}

//    std::cout << "\t" << i << "; " << (arr[i].top()).dest << " "<< (arr[i].top()).wt  << ";   empty ? " << arr[i].empty()  << "\n";
/*
    for(i = 1; i<=n; i++){
        std::cout << i << " empty =  " << arr[i].empty() << "; " << (arr[i].top()).dest << " "<< (arr[i].top()).wt  <<"\n";
        //std::cout << i << " In mst : Edge # " << total_in_mst << ": " << min_vertex << " < - - > " << (arr[min_vertex].top()).dest << "\n";

    }
    for(i = 1; i<=n; i++){
        std::cout <<  in_mst[i]  <<" ";
    }
    std::cout << "\n"<< total_in_mst ;
    
    */
