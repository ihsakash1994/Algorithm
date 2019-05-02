/*
1 -- > 2 -> 3 -->4 -->5
|           |         |  
65--->98   63-->90   99
|                     |
55                   88 


1-->2 -->3 --> 4 -->5 --> 65 --> 98 --> 63-->90 and so on.

1--> 2 -> 3 -> 4->5-65->98
QU(63, 99, 55)
*/

struct Node
{
    int data;
    struct Node* next;
    struct Node* child;
    
    Node(int val) : data(val), next(NULL), child(NULL) {}
};

void Flat(Node* root)
{
    Node* curr = root;
    
    Node* tail = root;
    while(tail->next != NULL) tail = tail->next;
    
    while(curr != NULL)
    {
        if (curr->child != NULL)
        {
            tail->next = curr->child;
            curr->child = NULL;
            while(tail->next != NULL) tail = tail->next;
        }
        
        curr = curr->next;
    }
}
