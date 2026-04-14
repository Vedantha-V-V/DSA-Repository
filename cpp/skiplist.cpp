// Preprocessor directives
#include <bits/stdc++.h>
using namespace std; 
   
// Define node structure for the skip list
class Node 
{ 
    public: 
        int key; 
        Node **forward; 
        // Constructor to create a new node
        Node(int, int); 
}; 


Node::Node(int key, int level) 
{      
    this->key = key;
    // Create array of pointers initially NULL    
    forward = new Node*[level+1];    
    memset(forward, 0, sizeof(Node*)*(level+1)); 
}; 

class SkipList 
{ 
    // Maximum level for this skip list
    int MAXLVL;
    // Probability factor 
    float P;
    // Current level of the skip list 
    int level;
    // Start pointer 
    Node *header;
    // Constructor to define all the operations of skip list
    public: 
        SkipList(int, float); 
        int randomLevel(); 
        Node* createNode(int, int); 
        void insertElement(int); 
        void deleteElement(int); 
        void searchElement(int); 
        void displayList(); 
}; 

// Initialization of skip list
SkipList::SkipList(int MAXLVL, float P) 
{      this->MAXLVL = MAXLVL; 
       this->P = P; 
       level = 0; 
       header = new Node(-1, MAXLVL); 
}; 

// Decide random level for node
int SkipList::randomLevel() 
{ 
       float r = (float)rand()/RAND_MAX; 
       int lvl = 0; 
       while(r < P && lvl < MAXLVL) 
       {    lvl++; 
            r = (float)rand()/RAND_MAX;
       } 
       return lvl;
}; 

// Create a new node and return it
Node* SkipList::createNode(int key, int level) 
{ 
    // Constructor to create a new node
    Node *n = new Node(key, level); 
    return n; 
}; 
    
void SkipList::insertElement(int key) 
{ 
    Node *current = header; 
    Node *update[MAXLVL+1]; 
    // Update stores the elements before insertion of key
    memset(update, 0, sizeof(Node*)*(MAXLVL+1)); 
    // Check at each level 
    for(int i = level; i >= 0; i--) 
    { 
        while(current->forward[i] != NULL && current->forward[i]->key < key){
            current = current->forward[i]; 
            update[i] = current; 
        } 
       current = current->forward[0]; 
       // Insertion of the key if not present in the list
       if (current == NULL || current->key != key) 
       {    
            // Get random level for the new node  
            int rlevel = randomLevel();
            if(rlevel > level) { 
                for(int i=level+1;i<rlevel+1;i++) 
                    update[i] = header; 
                level = rlevel; 
            } 
            Node* n = createNode(key, rlevel); 
            for(int i=0;i<=rlevel;i++) {       
                n->forward[i] = update[i]->forward[i]; 
                update[i]->forward[i] = n; 
            }
        } 
    }
    cout<<"Successfully Inserted key "<<key<<"\n"; 
};  

// Delete element from skip list
void SkipList::deleteElement(int key)  
{ 
    Node *current = header; 
    Node *update[MAXLVL+1]; 
    memset(update, 0, sizeof(Node*)*(MAXLVL+1)); 
    // Check at each level
    for(int i = level; i >= 0; i--) { 
        while(current->forward[i] != NULL &&current->forward[i]->key < key){
            current = current->forward[i]; 
            update[i] = current; 
        } 
            
        current = current->forward[0];
        // If we find the key, we delete the node
        if(current != NULL and current->key == key){ 
            for(int i=0;i<=level;i++) {    
                if(update[i]->forward[i] != current) 
                    break; 
                update[i]->forward[i] = current->forward[i]; 
            } 
        }    
        // Traverse levels to make sure no level has no elements
        while(level>0 && header->forward[level] == 0) 
            level--;
    } 
    cout<<"Successfully deleted key "<<key<<"\n"; 
};  


// Search for an element in the skip list
void SkipList::searchElement(int key) 
{ 
    Node *current = header; 
    for(int i = level; i >= 0; i--) { 
        while(current->forward[i] && current->forward[i]->key< key) 
                current = current->forward[i]; 
        } 
        // Position current now refers to the node just before the target node
        current = current->forward[0];
        if(current and current->key == key) 
            cout<<"Found key: "<<key<<"\n"; 
}; 
     
// Display the skip list
void SkipList::displayList() {         
    cout<<"\n*****Skip List*****"<<"\n"; 
    // Traverse through every level of the skip list and print the elements
    for(int i=0;i<=level;i++) {  
        Node *node = header->forward[i]; 
        cout<<"Level "<<": "; 
        // Traverse through nodes of each level
        while(node != NULL) { 
            cout<<node->key<<" "; 
            node = node->forward[i]; 
        } 
        cout<<"\n"; 
    } 
}; 
      

int main() 
{          
    srand((unsigned)time(0));   
    // Create SkipList object with maximum level 3 and probability 0.5          
    SkipList lst(3, 0.5); 
    // Insert elements into the skip list
    lst.insertElement(3); 
    lst.insertElement(6); 
    lst.insertElement(7); 
    lst.insertElement(9); 
    lst.insertElement(12); 
    lst.insertElement(19); 
    lst.insertElement(17); 
    lst.insertElement(26); 
    lst.insertElement(21); 
    lst.insertElement(25); 
    // Display the nodes at each level of the skip list
    lst.displayList(); 
    // Search for 19 in the skip list            
    lst.searchElement(19); 
    // Delete 19 from the skip list             
    lst.deleteElement(19); 
    // Display the nodes at each level of the skip list after deletion of 19            
	lst.displayList(); 
} 