import javax.swing.*;
import javax.swing.border.EmptyBorder;
import javax.swing.border.EtchedBorder;
import javax.swing.border.TitledBorder;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.PriorityQueue;

/**
 * Created by adityaagarwal on 11/04/16.
 */

public class GUI {
    private JFrame mainFrame;

    private JPanel  panelForStringInput,
            panelForHuffmanCode,
            superPanel;

    private JButton confirmButton;

    private PanelType1 stringInput;


    public GUI(){
        mainFrame = new JFrame("HUFFMAN ENCODING");
        mainFrame.pack();

        panelForStringInput = new JPanel( new FlowLayout(FlowLayout.LEFT) );
        stringInput = new PanelType1("Enter the string : ", 35);
        panelForStringInput.add(stringInput);
        panelForStringInput.setBorder( new TitledBorder( new EtchedBorder(EtchedBorder.RAISED), "String Input" ) );

        panelForHuffmanCode = new JPanel(new GridLayout(0,1,40,10));
        panelForHuffmanCode.setBorder( new TitledBorder( new EtchedBorder(EtchedBorder.RAISED), "Huffman Codes" ) );
        panelForHuffmanCode.setVisible(false);
        //panelForHuffmanCode.add( new PanelType1("Abc", 30));

        superPanel = new JPanel(new GridLayout(0,1,5,5));

        confirmButton = new JButton("CONFIRM");
        confirmButton.setToolTipText("You can also press Enter to confirm.");
        mainFrame.getRootPane().setDefaultButton(confirmButton);

        superPanel.add(panelForStringInput);
        superPanel.add(confirmButton);

        confirmButton.setVisible(true);

        superPanel.setBorder(new EmptyBorder(15,15,15,15));

        mainFrame.add(superPanel);

        mainFrame.pack();
        mainFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        mainFrame.setVisible(true);
    }

    public void enterStringInput(){

        confirmButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                superPanel.remove(confirmButton);
                HuffmanCoding hc = new HuffmanCoding();
                hc.input = stringInput.textField.getText();
                HuffmanTree ht = HuffmanTree.makeHuffmanTree(hc.makePriorityQueue());
                HuffmanTree.codify(ht.root);
                panelForHuffmanCode.setVisible(true);
                displayHuffmanCode( new PriorityQueue<CharFrequency>(hc.priorityQueue), hc.priorityQueue.size() );
            }
        });
    }

    public void displayHuffmanCode(PriorityQueue<CharFrequency> priorityQueue, int size){

        //panelForHuffmanCode = new JPanel(new GridLayout(size,1,40,10));

        PanelType1  huffmanCode[] = new PanelType1[size];

        for(int i = 0; i < size; i++) {
            String  character = String.valueOf(priorityQueue.remove().getChar()),
                    code = HuffmanTree.huffmanCode.get(character);
            System.out.println("character = " + character + "\tcode = " + code );
            huffmanCode[i] = new PanelType1(character + " -> ", 10);
            huffmanCode[i].setLayout( new FlowLayout(FlowLayout.LEFT) );
            huffmanCode[i].textField.setText(code);
            huffmanCode[i].textField.setEditable(false);
            panelForHuffmanCode.add(huffmanCode[i]);
            huffmanCode[i].setVisible(true);
        }
        superPanel.add(panelForHuffmanCode);
        mainFrame.pack();

    }


}


class PanelType1 extends JPanel {
    JTextField textField;
    private JLabel label;


    PanelType1(String labelName, int fieldWidth ){
        super(new FlowLayout(FlowLayout.LEFT));
        textField = new JTextField(fieldWidth);
        label = new JLabel(labelName);
        add(label);
        add(textField);
    }

}