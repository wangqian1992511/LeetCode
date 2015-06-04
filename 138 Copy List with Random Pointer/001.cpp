/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode*, RandomListNode*> hash;
        RandomListNode *t = head;
        RandomListNode *super = new RandomListNode(0);
        RandomListNode *ansTail = super;
        while (t) {
            RandomListNode *p;
            if (hash.find(t) != hash.end()) 
                p = hash[t];
            else {
                p = new RandomListNode (t->label);
                hash[t] = p;
            }
            ansTail->next = p;
            ansTail = p;
            if (t->random) {
                RandomListNode *q;
                if (hash.find(t->random) != hash.end()) 
                    q = hash[t->random];
                else {
                    q = new RandomListNode (t->random->label);
                    hash[t->random] = q;
                }
                p->random = q;
            }
            t = t->next;
        }
        return super->next;
    }
};