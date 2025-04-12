class LinkedList
{
    private Node root;
    private int Size;

    public LinkedList()
    {
        this.root = null;
        this.Size = 0;
    }

    void pushFront(int value)
    {
        Node newOne = new Node(value, this.root);
        this.root = newOne;
        Size++;
    }
    void pushBack(int value)
    {
        Node newOne = new Node(value, null);
        if(this.root == null)
            this.root = newOne;
        else
        {
            Node actNode = this.root;
            while( actNode.getNext() != null )
            {
                actNode = actNode.getNext();
            }
            actNode.setNext(newOne);
        }
        this.Size++;
    }
    void delete(int value)
    {
        if(this.Size == 0)
        {
            System.out.println("The list is empty!");
            return;
        }
        if(this.root.getValue() == value)
        {
            this.root = this.root.getNext();
        }
        else
        {
            Node actNode = this.root;
            while( actNode.getNext() != null && (actNode.getNext()).getValue() != value)
                actNode = actNode.getNext();
            
            if(actNode.getNext() == null)
                System.err.println("The element is not in the list");
            else
                actNode.setNext( (actNode.getNext()).getNext() );
        }
        Size--;
    }

    void showList()
    {
        Node actNode = this.root;
        while(actNode.getNext() != null)
        {
            System.out.print(actNode.getValue() + " ");
            actNode = actNode.getNext();
        }
        System.out.print(actNode.getValue());
    }
}
