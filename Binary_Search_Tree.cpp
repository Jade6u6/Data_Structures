#include<iostream>

typedef long long ll;
struct Node
{
    Node *Left,*Right;
    ll data;
    int counter; 
};
class Tree
{
    public:
    Node *root = nullptr;
    Node *Find(Node *p, ll x)
    {
        if(p == nullptr || p->data == x)
            return p;
        if(x < p->data)
            return Find(p->Left,x);
        else if(x > p->data)
            return Find(p->Right,x);
    }
    void Insert(ll x)
    {
        if(this->root == nullptr)
            root = new Node {nullptr,nullptr,x,1};
        else
        {
            Node *p = root;
            while(true)
            {
                if(p->data == x)
                {
                    p->counter++;
                    return;
                }
                else if(p->data > x)
                {
                    if(p->Left != nullptr)
                        p = p->Left;
                    else
                    {
                        Node *NewN = new Node {nullptr,nullptr,x,1};
                        p->Left = NewN;
                        return;
                    }
                }          
                else if(p->data < x)
                {
                    if(p->Right != nullptr)
                        p=p->Right;
                    else
                    {
                        Node *NewN = new Node {nullptr,nullptr,x,1};
                        p->Right = NewN;
                        return;
                    }
                }   
            }
        }
    }
};
int main()
{// ios_base::sync_with_stdio(0);cin.tie(0);
    int N_oper;
    ll x;
    char Oper_char;
    Tree A;
    std::cin >> N_oper;
    while(N_oper--)
    {
        std::cin >> Oper_char >> x;
        if(Oper_char == 'P')
        {
            Node *aux = A.Find(A.root,x);
            if(aux != nullptr)
                std::cout << aux->counter << "\n";
            else
                std::cout << "0\n";
        }
        else if(Oper_char == 'A')
            A.Insert(x);               
    }
    return 0;
}
