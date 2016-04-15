import java.util.ArrayList;
import java.util.PriorityQueue;


public class HuffmanCoding {
    PriorityQueue <CharFrequency> priorityQueue;
    String input;

    public  HuffmanCoding(){
        priorityQueue = new PriorityQueue <CharFrequency>();
        input = new String();

    }

    public PriorityQueue <CharFrequency> makePriorityQueue(){
        int length = input.length();
        char c;
        int i, j;
        ArrayList<CharFrequency> tempList = new ArrayList<CharFrequency>();
        if(length >= 1){
            tempList.add(new CharFrequency(input.charAt(0), 1));
        }

        for (i = 1; i < length; i++) {
            c = input.charAt(i);
            for(j = 0; j < tempList.size(); j++){
                if(tempList.get(j).getChar() == c){
                    tempList.get(j).incrementFrequency();
                    break;
                }
            }
            if(j == tempList.size() ) {
                tempList.add(new CharFrequency(c, 1));
            }
        }

        for(j = 0; j < tempList.size(); j++){
            priorityQueue.add(tempList.get(j));
        }

        PriorityQueue <CharFrequency> priorityQueue1 = new PriorityQueue <CharFrequency> (priorityQueue);
        while(!priorityQueue1.isEmpty()){
            CharFrequency cf = priorityQueue1.remove();
            System.out.println(cf.getChar() + " " + cf.getFrequency());
        }

        return priorityQueue;

    }

    public static void main(String[] args) {
       /* HuffmanCoding hc = new HuffmanCoding();
        hc.input =   "mississippi";//"My name is Aditya"; "a";//
        System.out.println(hc.input + ",");
        //hc.makePriorityQueue();
        HuffmanTree ht = HuffmanTree.makeHuffmanTree(hc.makePriorityQueue());
        System.out.println(ht.root.cf.getFrequency());
        System.out.println(ht.root + " " + ht.root.left + " " + ht.root.right);
        HuffmanTree.codify(ht.root);
        ht.root.print();*/

        GUI huffman = new GUI();
        huffman.enterStringInput();
    }

}



