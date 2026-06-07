/* Structure of a Linked List node
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node *compute(Node *head) {
        // code here
         if(!head or !head->next) return head;
        stack<int> st;
        while(head)
        {
            while(!st.empty() and st.top()<head->data) st.pop();
            st.push(head->data);
            head=head->next;
        }
        
        Node* temp = NULL;
        while(!st.empty())
        {
            Node* tempo = new Node(st.top());
            st.pop();
            tempo->next=temp;
            temp=tempo;
        }
        return temp;
    }
};