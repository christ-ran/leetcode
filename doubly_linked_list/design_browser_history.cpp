#include <string>

struct Node
{
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *next) : val(x), next(next) {}
};

class Node
{
public:
    std::string url = "";
    Node *next = nullptr;
    Node *prev = nullptr;

    Node(std::string url)
    {
        this->url = url;
    }
};

class BrowserHistory
{
private:
    int length = 0;
    int position = 0;
    Node *current = nullptr;

public:
    BrowserHistory(std::string homepage)
    {
        Node *newNode = new Node(homepage);
        this->current = newNode;
        this->position = 1;
        this->length++;
    }

    void visit(std::string url)
    {
        Node *newNode = new Node(url);

        this->current->next = newNode;
        newNode->prev = this->current;
        this->current = newNode;
        this->length = position;
        this->length++;
        this->position++;
    }

    std::string back(int steps)
    {
        Node *temp = this->current;

        for (int i = 0; i < steps; i++)
        {
            if (temp->prev)
            {
                temp = temp->prev;
                this->position--;
            }
        }

        this->current = temp;
        return temp->url;
    }

    std::string forward(int steps)
    {
        Node *temp = this->current;

        for (int i = 0; i < steps; i++)
        {
            if (temp->next)
            {
                temp = temp->next;
                this->position++;
            }
        }

        this->current = temp;
        return temp->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */