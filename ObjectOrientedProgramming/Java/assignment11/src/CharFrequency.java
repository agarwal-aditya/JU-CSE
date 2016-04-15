/**
 * Created by adityaagarwal on 10/04/16.
 */
public class CharFrequency implements Comparable<CharFrequency>{
    private char ch;
    private int frequency;

    public CharFrequency(){
        ch = '\0';
        frequency = 0;
    }

    public CharFrequency(char c){
        ch = c;
        frequency = 0;
    }

    public CharFrequency(char c, int f){
        ch = c;
        frequency = f;
    }

    public void setChar(char c){
        ch = c;
    }

    public char getChar(){
        return ch;
    }

    public void setFrequency(int i){
        frequency = i;
    }

    public int getFrequency(){
        return frequency;
    }

    public int incrementFrequency(){
        frequency++;
        return frequency;
    }


    @Override
    public int compareTo(CharFrequency object2){
        return ( (Integer)frequency ).compareTo( (Integer)(object2.getFrequency()) );
    }


}
