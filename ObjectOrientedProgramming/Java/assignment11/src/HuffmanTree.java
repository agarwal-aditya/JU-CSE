import java.util.HashMap;
import java.util.PriorityQueue;

/**
 * Created by adityaagarwal on 11/04/16.
 */
public class HuffmanTree implements Comparable <HuffmanTree> {

    Node root;

    public static HashMap <String, String> huffmanCode = new HashMap<String, String>();

    public HuffmanTree (HuffmanTree leftSubTree, HuffmanTree rightSubTree) {

        root = new Node();
        root.left = leftSubTree.root;
        root.right = rightSubTree.root;
        root.cf = new CharFrequency(' ', leftSubTree.root.cf.getFrequency() + rightSubTree.root.cf.getFrequency());

    }

    public HuffmanTree (CharFrequency charFrequency){
        root = new Node(charFrequency);
    }


    @Override
    public int compareTo(HuffmanTree o) {
        return ( root.cf.compareTo(o.root.cf) );
    }

    public static HuffmanTree makeHuffmanTree(PriorityQueue <CharFrequency> priorityQueue ) {
        PriorityQueue <HuffmanTree> pQueueTree = new PriorityQueue<HuffmanTree>();

        PriorityQueue <CharFrequency> priorityQueueDeepCopy = new PriorityQueue<CharFrequency>(priorityQueue);

        while (priorityQueueDeepCopy.size() != 0){
            pQueueTree.add(new HuffmanTree(priorityQueueDeepCopy.remove()));
        }

        while(pQueueTree.size() > 1){
            HuffmanTree treeLeft = pQueueTree.remove();
            HuffmanTree treeRight = pQueueTree.remove();
            pQueueTree.add(new HuffmanTree(treeLeft, treeRight));

        }

        return pQueueTree.remove();
    }

    public static void codify(Node root){
        if((root.left == null) && (root.right == null))
            root.code = "0";

        if(root.left != null){
            root.left.code = root.code + "0";
            huffmanCode.put(String.valueOf(root.left.cf.getChar()), root.left.code);
            codify(root.left);
        }
        if (root.right != null) {
            root.right.code = root.code + "1";
            huffmanCode.put(String.valueOf(root.right.cf.getChar()), root.right.code);
            codify(root.right);
        }

    }

}


class Node {

    CharFrequency cf;
    String code;
    Node left, right;

    public Node(){
        code = "";
        cf = new CharFrequency();
        left = right = null;
    }

    public Node(CharFrequency charFrequency){
        code = "";
        cf = charFrequency;
        left = right = null;
    }

    public boolean isLeaf(){
        return ( (left==null) && ( right == null ) );
    }

    public void print(){
        if( !isLeaf() ){
            this.left.print();
            this.right.print();
        }
        else {
            System.out.println(cf.getChar() + " -> " + code);
        }
    }

}
