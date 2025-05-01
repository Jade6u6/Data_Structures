public class BST 
{
    private Node root;

    public BST()
    {
        this.root = null;
    }
    private Node search(Node actNode, int value)
    {
        if(actNode.getValue() == value)
            return actNode;
        Node nexNode;
        if(value < actNode.getValue())
        {
            if(actNode.getLeft() == null)
                return actNode;
            nexNode = actNode.getLeft();
        }
        else
        {
            if(actNode.getRight() == null)
                return actNode;
            nexNode = actNode.getRight();
        }
        return search(nexNode,value);
    }
    private void show(Node actNode)
    {
        if(actNode == null)
            return;
        System.out.println(actNode.getValue() + " ");
        show(actNode.getLeft());
        show(actNode.getRight());
    }
    public void insertValue(int value)
    {
        Node newOne = new Node(value,null,null);
        if(this.root == null)
        {
            this.root = newOne;
            return;
        }
        Node actNode = this.root;
        actNode = search(actNode, value);

        if(value == actNode.getValue())
        {
            System.out.print("The value is already in the tree!\n");
            return;
        }
        if(value < actNode.getValue())
            actNode.setLeft(newOne);
        else
            actNode.setRight(newOne);
        return;
    }
    public void showTree()
    {
        Node actNode = this.root;
        show(actNode);
        return;
    }
}
