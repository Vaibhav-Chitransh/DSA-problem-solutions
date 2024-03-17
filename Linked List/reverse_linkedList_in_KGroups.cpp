#include<iostream>
using namespace std;

/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as */
struct node
{
    int data;
    struct node* next;

    node(int x){
        data = x;
        next = NULL;
    }

}*head;

// Approach 1 - Recursive way 

class Solution
{
    public:
    struct node *reverseIt (struct node *head, int k)
    { 
        // TC = O(n)
        // SC = O(n/k)
        
        if(head == NULL) {
            return NULL;
        }
        
        int cnt = 0;
        node* curr = head;
        node* prev = NULL;
        node* temp = NULL;
        
        while(curr != NULL && cnt < k) {
            temp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
            cnt++;
        }
        
        head -> next = reverseIt(curr, k);
        return prev;
    }
};



// Approach 2 - Iterative way 

class Solution
{
    public:
    struct node *reverseIt (struct node *head, int k)
    { 
        node* curr = head;
        node* prev = NULL;
        node* temp = NULL;
        
        int cnt = 0;
        
        while(curr != NULL && cnt < k) {
            temp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
            cnt++;
        }
        
        node* updated_head = prev;
        
        head -> next = curr;
        node* second = curr;
        node* first = head;
        
        while(second != NULL) {
            cnt = 0;
            
            // update curr and prev
            curr = second;
            prev = first;
            
            while(curr != NULL && cnt < k) {
                temp = curr -> next;
                curr -> next = prev;
                prev = curr;
                curr = temp;
                cnt++;
            }
            
            // Link kar diya
            first -> next = prev;
            second -> next = curr;
            
            // first and next pointers arrange karo
            first = second;
            second = curr;
        }
        
        return updated_head;
    }
};