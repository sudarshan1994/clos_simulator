#include<iostream>
#include<vector>
#include<queue>
//#include "bfs.cpp"
using namespace std;
class clos
{
	public:
//	vector<int>glo;
//	int closgraph[1000][1000];
  	
	int numnodes (int);
  	
	int numstages(int);
	
	bool isconnected(vector < vector <int> > ,int ,int);
	
	vector<int> bfs(vector<vector < int > >,int ,int);
  	
	vector <int>  nodesperstage(int , int,int );//gices the nods per stages
	
	int stagefinder( vector <int> ,int ,int,int);//given the nodes gives the stage
  	
	void node_numbers_per_stage(vector<int>,int ,int);//
  	
	int endfinder(vector<int>,int,int,int);
	
	vector<vector <int> > matgen(vector<int>,int,int);
		
	//vector<int> pathgenerator(vector<int>,vector<int>,int,int ,int);
}ac;
bool clos::isconnected(vector< vector <int> >v2,int v,int u)
{
	
	if(v2[v][u]==1)
	{
//		cout<<"\n in isconected"<<v+1<<u+1;
//		cout<<"\t"<<1;
		return true;
	}
	else
	{
//		cout<<"\n in isconected"<<v+1<<u+1;
//		cout<<"\t"<<0;
		return false;
	}

}
vector<int> clos::bfs(vector< vector<int> >v2,int s,int n)
{
	int v;
	vector<int> temp;
	queue<int> q;
	queue<int> q1;
	vector<bool> explored;
	cout<<"\n in bfs"<<n;
	
	for(int i=1;i<=n;i++)
	{
		explored.push_back(false);
	}
	q.push(s);
	explored[s]=true;
	while(!q.empty())
	{
		v=q.front();
		q.pop();
		q1.push(v);
		for(int i=0;i<n;i++)
		{
			if((isconnected(v2,v,i)) && (!explored[i]) )
			{
				
				q.push(i);
				explored.push_back(true);
			
			}
		}
		
	}
	cout<<"\n in bfs for loop ptint";
	for(int i=1;i<n;i++ )
	{
		temp.push_back(q1.front()+1);
	//	cout<<"\n"<<temp.back();
		q1.pop();
		
	}
	return (temp);
}
int clos::numnodes (int number_of_ports)
{
  	int number_of_nodes;
  	clos c;
  	if (number_of_ports == 4)
    	{
      		number_of_nodes = 7;
      		return number_of_nodes;
    	}
  	else
    	{
      		number_of_nodes = number_of_ports + (3 * c.numnodes (number_of_ports/ 2));
      		return number_of_nodes;
    	}
}

int clos :: numstages(int number_of_ports)//gives the number of  nodes in each stage
{
    	int number_of_stages;
    	clos c;
    	if(number_of_ports==4)
    	{
    		number_of_stages=3;
    		return number_of_stages;
    	}
    	else
    	{
    		number_of_stages=2+c.numstages(number_of_ports/2);
    		return number_of_stages;
    	}
}
vector<int>clos :: nodesperstage(int r,int s,int n )//return the number of niodes in each stage
{
        int t1;   
        int  t;
	vector<int>nodes_per_stage;
     	t=s/2;
    	t=t+1;
	nodes_per_stage.push_back(0);
    	int parameters[10000];
        parameters[1]=r;
        for(int i=2;i<=t;i++)
        {
            	parameters[i]=(parameters[i-1]*3)/2;
       
        }
        t1=t+1;
        for(;t1<=s;t1++)
        {   
            	parameters[t1]=parameters[t-1];
                t--;   
        }   
	
    	for(int i=1;i<=s;i++)
	{
		nodes_per_stage.push_back(parameters[i]);
	}
       	return(nodes_per_stage);
}
void clos:: node_numbers_per_stage(vector<int> glo,int n,int s)//has no significance was done to print stuff the function has been comented in main
{
        int marker=1;
        for(int i=1;i<=s;i++)
        {
        	cout<<"\n the node numbers in the "<<i<<"th stage are ";
        	for(int k=1;k<=glo[i];k++)
        	{
            		cout<<"\t"<<marker;
            		marker++;   
        	}
    	}  
}
int clos:: stagefinder(vector<int> nodes_per_stage,int n,int s,int m)//finds the stage of the node of interest
{	
	int stage;
        int marker=1;
//	cout<<"\n in stage finder";
	for(int i=1;i<=s;i++)
        {
	//	cout<<"\niiii"<<i;
	//	cout<<"\n iiiiiiii"<<i;
	//	cout<<"\n glo[]"<<glo[i];
		int k=1;
	//	cout<<"\n stg i"<<i;
                for(;k<=nodes_per_stage[i];k++)
                {
	//		cout<<"\n stg k"<<k;
                	if(m == marker)
			{
			
				stage= i;						
			}
                marker++;
                }
	}
	return stage;
}
int clos:: endfinder(vector<int>nodes_per_stage,int n,int s,int e)
 {
	//n is the total number of nodes
	//s is the tot number of stages
	//e is the stage whose last node is to be found
	int r;//temp var
      	int stage;//
        int marker=1;//to poin to the node
        for(int i=1;i<=s;i++)
        {
	
                for(int k=1;k<=nodes_per_stage[i];k++)
                {
        
                        marker++;
                }  
                if(i == e )
                {
                       r=marker-1;
                }
	
        }
        return r ;
 }
vector<vector<int> > clos:: matgen(vector<int>nodes_per_stage,int number_of_nodes,int number_of_stages)
{
	clos c;
	int g;
	int h;
	int s;
	int t;
	int adj[500][500];
	int N;//temp VAR THIS is used to store the val of j int the  scnd loop since j will be chnged to tget the splitup value
	//int splitj_c;//
	//int splitup1;
	//int checker1;
	int checker;//to check if any node has received more than three links from the prev stage
	//int counter1;
	int counter;//to chck if any node has given more than two link ups to the nodes in the next sec
	//int *temp;
	int stage_of_the_node_to_be_mapped;//stage of the node to be mapped
	int temp_determines_pattern;//temp var receives  the vlaue of the  stage of the node to b mapped which fixes the patern in whch the network is to be woven
	int stage_of_the_node_from_which_mappings_made;//stage of the node from which mapings made
	//int v;
	//int nodes[500];
	int splitup;//factor in whch the to be pointed variable is to be increased
	int lastnode;//the node which is the last node of the to be conected stage
	int tempi;//holds the number of nodes in the stage where is mapin is performed from 
	int tempj;//holds the number of nodes in the stage where maping is to be performed to
	int spliti;
	int splitj;
	int lastnode_i;
	int lastnode_inner;
	int midlestage;//the midlle stage in the network required becos there is a change in the input output of the swicths
	int temp__i;//holds the value of i so that the value of i can be restored when alterations take place insise the computing loop
	int q;
	int newarr[500][500];
	int row;//for inversr transpose
	int col;//for inverse transpose
	int lastnode_prev;
	int splitj_f;
	int lastnode_outer;
	int lastnode_inner1;
	int lastnode_inner2;
	int lastnode_outer1;
	int lastnode_outer2;
	int closgraph[500][500];
	vector<vector<int> > v2;
	midlestage=number_of_stages/2+1;
	//cout<<"\nglo"<<glo[1];
	//cout<<"\n midlestage"<<midlestage;
	temp__i=1;
	for(int i=1;i<=number_of_nodes;i=i+1)//maping begins here i loop is for the parent node
	{
//		cout<<"\n i "<<i;
		temp__i=i;
//		cout<<"\n iteration for i"<<i;
		N=1;
		int j=1;
		for(;N<=number_of_nodes;)//j loop is for the child node
		{
			//counter1=0;
			//checker1=0;
			counter=0;
			checker=0;
			j=N;
			//cout<<"\n iteration for (i,j) is "<<"("<<i<<","<< j<<")";
			stage_of_the_node_from_which_mappings_made=c.stagefinder(nodes_per_stage,number_of_nodes,number_of_stages,i);//stage of the node i th nodei
		//	temp=p;
			stage_of_the_node_to_be_mapped=c.stagefinder(nodes_per_stage,number_of_nodes,number_of_stages,j);// stage of the j th node 
			//cout<<"\n the stage of "<<j<<"th node is "<<l;
			//cout<<"\n the stage of "<<i<<"th node is "<<k;
			lastnode_i=c.endfinder(nodes_per_stage,number_of_nodes,number_of_stages,stage_of_the_node_from_which_mappings_made);//last node 
			lastnode = c.endfinder(nodes_per_stage,number_of_nodes,number_of_stages,stage_of_the_node_to_be_mapped);
			q=stage_of_the_node_from_which_mappings_made-1;//to cal the stage of the previous  outer interation 
			lastnode_prev = c.endfinder(nodes_per_stage,number_of_nodes,number_of_stages,q);
		//	temp=p;
			N++;
		//	b=nodes[j];
		//	cout<<"\n the value of b is"<<b;
			//splitup=b/3;
			if(stage_of_the_node_from_which_mappings_made == stage_of_the_node_to_be_mapped-1)
			{
			//	splitup=b/3;
				if(stage_of_the_node_from_which_mappings_made==1 || stage_of_the_node_to_be_mapped==number_of_stages)
				{  
					if(stage_of_the_node_from_which_mappings_made==1)
					{	
				//		cout<<"\n ingress";
						temp_determines_pattern=nodes_per_stage[stage_of_the_node_to_be_mapped];//  is a stage , "nodes" gives us the number of nodes in the given stage ;
						splitup=temp_determines_pattern/3;
						//splitup1=b/3;	
		//				splitup1=1;//if any prob comes uncomnt it else keep it like this
						
						for(;j<=lastnode;j=j+splitup)
						{
				//			cout<<"\nthe value of j"<<j;
							for(int y=1;y<=number_of_nodes;y++)
							{
								if(adj[i][y]==1)
								{
									counter++;		
								}
							}
							for(int z=1;z<=number_of_nodes;z++)
							{
								if(adj[z][j]==1)
								{
									checker++;
								}

							}
							if(counter >=3  || checker >=2 ) //sec print
							{
								if(adj[i][j]!=1)
								{
								
									adj[i][j]=0;
								
								}		
							}
							else
							{
								checker=0;
								counter=0;

				       				adj[i][j]=1;
								adj[i+1][j]=1;
							
							}	

						} 
					}
					else//engress
					{
						adj[i][j]=0;
				//		cout<<"\n engress";
					}
				}//between ingress anid the midlle stage 
				else
				{
					if(stage_of_the_node_to_be_mapped<=midlestage)
					{       
				//		cout<<"\n betwenn igress and midle stages";       
						tempi=nodes_per_stage[stage_of_the_node_from_which_mappings_made];
						tempj=nodes_per_stage[stage_of_the_node_to_be_mapped];
						spliti=tempi/3;//the previous stage is split into its comps
						splitj=tempj/3;//the current stage """"""""""
						splitj_f=splitj/3;//incremental
						lastnode_inner=lastnode_i+splitj;//finer spliting
						lastnode_outer=lastnode_prev+spliti;
						for(;i<=lastnode_outer;)
						{//code to check if extra mapings been done
							for(;j<=lastnode_inner;)
							{
								for(int y=1;y<=number_of_nodes;y++)//this for loop checks if the are extra mapings onto one node
                                                         	{
                                                                	if(adj[i][y]==1)
                                                                 	{
                                                                        	counter++;
                                                                 	}
                                                         	}
                                                         	for(int z=1;z<=number_of_nodes;z++)//this loop chechks if extra mapings been done from one node
                                                         	{
                                                                	if(adj[z][j]==1)
                                                                 	{
                                                                        	checker++;
                                                                 	}
 
                                                         	}
                                                         	if(counter >=3  || checker >=2 )// here extra mapings prevented
                                                         	{
                                                                	if(adj[i][j]!=1)
                                                                 	{
 
                                                                        	adj[i][j]=0;
 
                                                                 	}
                                                         	}
                                                         	else//if no extra mapins been done control comes here and the two nodes are maped 
                                                         	{
                                                                	checker=0;
                                                                	counter=0;
 
                                                                 	adj[i][j]=1;
                                                                 	adj[i+1][j]=1;
 
                                                         	}
								j=j+splitj_f;		
							}
							i=i+2;				
						}
						lastnode_outer1=lastnode_outer+spliti;
						lastnode_inner1=lastnode_inner+splitj;
						for(;i<=lastnode_outer1;)
                                                {//maping measeures look at the above section to no why eaxh for loops been written
                                                         for(;j<=lastnode_inner1;)
                                                         {
                                                                 for(int y=1;y<=number_of_nodes;y++)
                                                                 {
                                                                         if(adj[i][y]==1)
                                                                         {
                                                                                 counter++;
                                                                         }
                                                                 }  
                                                                 for(int z=1;z<=number_of_nodes;z++)
                                                                 {  
                                                                         if(adj[z][j]==1)
                                                                         {
                                                                                 checker++;
                                                                         }
 
                                                                 }
                                                                 if(counter >=3  || checker >=2 ) //sec print
                                                                 {
                                                                         if(adj[i][j]!=1)
                                                                         {
 
                                                                                 adj[i][j]=0;
 
                                                                         }
                                                                 }   
                                                                 else
                                                                 {
                                                                         checker=0;
                                                                         counter=0;
 
                                                                         adj[i][j]=1;
                                                                         adj[i+1][j]=1;
 
                                                                 }
                                                                 j=j+splitj_f;
                                                         }
                                                 i=i+2;            
						}
						lastnode_outer2=lastnode_outer1+spliti;
                                                lastnode_inner2=lastnode_inner1+splitj;
                                                for(;i<=lastnode_outer2;)
                                                {//mapin measures look at the above section
                                                         for(;j<=lastnode_inner2;)
                                                         {
                                                                 for(int y=1;y<=number_of_nodes;y++)
                                                                 {
                                                                         if(adj[i][y]==1)
                                                                         {
                                                                                 counter++;
                                                                         }
                                                                 }
                                                                 for(int z=1;z<=number_of_nodes;z++)
                                                                 {
                                                                         if(adj[z][j]==1)
                                                                         {
                                                                                 checker++;
                                                                         }
 
                                                                 }
                                                                 if(counter >=3  || checker >=2 ) //sec print
                                                                 {
                                                                         if(adj[i][j]!=1)
                                                                         {
 
                                                                                 adj[i][j]=0;
 
                                                                         }
                                                                 }
                                                                 else
                                                                 {
                                                                         checker=0;
                                                                         counter=0;
 
                                                                         adj[i][j]=1;
                                                                         adj[i+1][j]=1;
 
                                                                 }
							j=j+splitj_f;
							}
						i=i+2;
						}
					}
					else
					{
				//		cout<<"betwenn the midle and the engress";
					}
				}
			}
			else
			{
				//cout<<"\n indeterminste region";
				adj[i][j]=0;
				

			}	
		}
		i=temp__i;
	}//with this the mapin for the first haf the network s been done tat s in adj
	int x;
	int z;
	col=number_of_nodes;
	row=number_of_nodes;
	for(int i=1;i<=number_of_nodes;i++)//perform inverse transpose
	{
		row=number_of_nodes;
		for(int j=1;j<=number_of_nodes;j++)
		{
			
			
			newarr[row][col]=adj[i][j];//inverse transpose been done here 
			row--;
		
		}
		col--;
	}
/*	for(int l=1;l<=n;l++)//to print the new arr
	{
	//	cout<<"\n";
		for(int m=1;m<=n;m++)
		{
	//		cout<<newarr[l][m];
		}
	}
	for(int i=1;i<=n;i++)
	{
	//	cout<<"\n";
		for(int j=1;j<=n;j++)
		{
	//		cout<<adj[i][j];
		}
	}*/
	for(int g=1;g<=number_of_nodes;g++)//to print the graph tat represnts the clos fabric
	{
		cout<<"\n";
		for(int h=1;h<=number_of_nodes;h++)
		{
			closgraph[g][h]=newarr[g][h]+adj[g][h];
		//	cout<<closgraph[g][h];			
		}
	}
	for (int s = 0; s <number_of_nodes ; s++) 
	{
    		vector<int> row; // Create an empty row
    		for (int t = 0; t <number_of_nodes ; t++) 
		{
			g=s+1;
			h=t+1;
        		row.push_back(closgraph[g][h]); // Add an element (column) to the row
    		}
    		v2.push_back(row); // Add the row to the main vector
	}
/*	for(int s=0;s<number_of_nodes;s++)
	{
		cout<<"\n";
		for(int t=0;t<number_of_nodes;t++)
		{	
		//	v2[s][t].push_back(0);
			cout<<v2[s][t];
		}
	}*/
	return (v2);
}
/*vector<int>path(vector<int>route,int dest)
{
	vector<int>optimal;
	int c;
	int n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			c=stagefinder()	
		}
	}
}*/

int main ()
{   
	clos c;
	vector<vector<int> > v2;
	vector<int> path;
	vector<int>number_of_nodes_per_stage;//stores the number of nodes in each stage
	int number_of_ports;
      	int number_of_stages;
      	int number_of_nodes;
      	int haf_numberof_nodes;//required to calculate the number of nodes per stages
	int source=0;
	int destination=7;
	//int b;

//	int q;
 //       int *t;
   //     int *v;           
//	int stage;
//	int last;             
        cout<<"\n enter the number of ports";
        cin >> number_of_ports;
//	cout<<"\n enter the node whose stage is to  be found ";
//	cin>>q;
//	cout<<"\n enter the stage whose last node is to be obtained";
//	cin>>last;
//*/
        haf_numberof_nodes=number_of_ports/2;
        number_of_nodes = c.numnodes (number_of_ports);//to calculate the toatal numberof npdes required to construct the entire network
        number_of_stages= c.numstages(number_of_ports);//to calculate thhe stages required to construct the netwrk
        number_of_nodes_per_stage=c.nodesperstage(haf_numberof_nodes,number_of_stages,number_of_nodes);//number of nodes in each stage
     /*   for(int i=1;i<=number_of_stages;i++)
        { 
        	cout<<"\nthe number of nodes in the" <<i<<"th stage-------"<<number_of_nodes_per_stage[i];
        }
        cout <<"\n number of nodes required to realise the network-----"<< number_of_nodes ;
        cout<<"\nnumber of stages required to realise the network-----"<< number_of_stages<<"\n";*/
    	//c.node_numbers_per_stage(number_of_nodes_per_stage, number_of_nodes, number_of_stages);
	v2=c.matgen(number_of_nodes_per_stage,number_of_nodes,number_of_stages);//generates the adjmat for the clos structure
	for(int i=0;i<number_of_nodes;i++)
	{
		cout<<"\n";
		for(int j=0;j<number_of_nodes;j++)
		{
			cout<<v2[i][j];
		}
	}
	path=c.bfs(v2,source,number_of_nodes);
	cout<<"in main";
	for(int g=0;g<path.size();g++)
	{
	//	cout<<"\n"<<path[g];
	}
/*	for(int i=1;i<=n;i++)//to check stagefinder and endfinder
	{
		b=c.stagefinder(n,s,i);
		cout<<"\n the value of node"<<i;
		cout<<"\n the value of the stage"<<b;
	}
	for(int i=1;i<=s;i++)
	{
		stage=c.endfinder(n,s,i);
		cout<<"\n the given stage is "<<i;
		cout<<"\n the end node is"<<stage;
	}*/
//	cout<<"\n the given nodes stage is "<<b;
//	cout<<"\n the last node of the givemn stage"<<stage;
		return 0;

}
