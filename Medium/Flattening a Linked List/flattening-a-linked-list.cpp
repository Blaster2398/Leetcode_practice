//{ Driver Code Starts
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}

// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
    
Node* convert(Node* head, vector<int> & arr){
    if(arr.size() == 0){
        return NULL;
    }
    head = new Node(arr[0]);
    Node* temp = head;
    for(int i = 1; i < arr.size(); i++ ){
        Node* new_node = new Node(arr[i]);
        temp->bottom = new_node;
        temp = temp->bottom;
    }
    return head;
}

Node *flatten2(Node *root)
{
    vector<int> arr;
    Node* temp = root;
    while(temp != NULL){
        Node* temp2 = temp;
        while(temp2 != NULL){
            arr.push_back(temp2->data);
            temp2 = temp2->bottom;
        }
        temp =  temp-> next;
    }
    
    sort(arr.begin(),arr.end());
    
    root = convert(root,arr);
    
    return root;
}

// Recursion Method
Node* mergeTwoLists(Node* list1, Node* list2) {
        Node* dummy = new Node(-1);
        Node* curr = dummy;

        //add all the items till one of them becomes NULL
        while(list1 != NULL && list2 != NULL){
            if(list1->data <= list2->data){
                curr-> bottom = list1;
                list1 = list1->bottom;
            }
            else{
                curr->bottom = list2;
                list2 = list2->bottom;
            }
            // dont forget to move the curr pointer also 
            curr = curr-> bottom;
        }
        // now it may happen one of them is still has elements 
        // we just need to append the whole part in one go 
        if(list1 != NULL){
            curr->bottom = list1;
        }
        else{
            curr->bottom = list2;
        }

        if(dummy->bottom != NULL){
            dummy->bottom->next = NULL;
        }
        return dummy->bottom;
    }

Node *flatten(Node *head)
{
    if(head == NULL || head->next == NULL){
        return head;
    }
    
    //after running this code for a while when the things are returned you will get the merged head here 
    Node* merged_head = flatten(head->next); //at last it will return you the last line for merge sort 
    head = mergeTwoLists(head, merged_head);
    
    return head;
}



