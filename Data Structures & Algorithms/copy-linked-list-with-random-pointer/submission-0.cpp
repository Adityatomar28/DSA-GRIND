/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        Node* it = head;
        while(it){
        //step 1 : clone kro beta
            Node* cloned = new Node(it->val);
            cloned->next = it->next;
            it->next = cloned;
            it = it->next->next;
        }
        //step:2 random pointer assign krna clone walo ko
        it = head;
        while(it){
            Node* cloned = it->next;
            cloned->random = it->random ? it->random->next:nullptr;
            it= it->next->next;
        }
        //Step:3 Detatch
         it = head;
         Node* clonedHead = it->next;
         while(it){
            Node* cloned = it->next;
            it->next = it->next->next;
            if(cloned->next){
                cloned->next = cloned->next->next;
            }
            it = it->next;

         }
         return clonedHead;



    }
};
