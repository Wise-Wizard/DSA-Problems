class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
        {
            return nullptr;
        }

        // Step 1: Create a new node for each original node and insert it next to the original node
        Node *temp = head;
        while (temp != nullptr)
        {
            Node *newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = newNode->next;
        }

        // Step 2: Assign random pointers for the new nodes
        temp = head;
        while (temp != nullptr)
        {
            if (temp->random != nullptr)
            {
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }

        // Step 3: Separate the original and copied lists
        Node *newHead = head->next;
        Node *newPtr = newHead;
        temp = head;

        while (temp != nullptr)
        {
            temp->next = temp->next->next;
            temp = temp->next;

            if (temp != nullptr)
            {
                newPtr->next = newPtr->next->next;
                newPtr = newPtr->next;
            }
        }

        return newHead;
    }
};