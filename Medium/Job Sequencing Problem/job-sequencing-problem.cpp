//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    bool static comparator(struct Job j1, struct Job j2) {
    if(j1.profit > j2.profit) 
        return true;
    else if (j1.profit == j2.profit && j1.dead < j2.dead) 
        return true;
    return false;
}

    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
       // Sort the jobs according to the comparator
        sort(arr, arr + n, comparator);
        int max_dead = arr[0].dead;
        
        for (int i = 0; i < n; i++) {
            max_dead =max(max_dead, arr[i].dead);
        }
        
        vector<int> jobs(max_dead,-1);
        
        for (int i = 0; i < n; i++) {
            if(jobs[arr[i].dead-1] == -1){
                jobs[arr[i].dead-1] = arr[i].profit;
            }
            else{
                for(int j = arr[i].dead-1; j>=0; j--){
                    if(jobs[j] == -1){
                        jobs[j] = arr[i].profit;
                        break;
                    }
                }
            }
        }
        int sum =0;
        int count =  0;
        
        for(int i : jobs){
            if(i != -1){
                count++;
                sum += i;
            }
        }
        
        return vector<int> {count,sum};
        
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends