package student.model;

/**
 * Created by adityaagarwal on 06/04/16.
 */
public class IncorrectMarksException extends Throwable {

    private String message;

    //Constructor initialises according to error.
    IncorrectMarksException(boolean flag){
        if(flag){
            message = new String("Cannot give student negative marks!\nTry again.\n");
        }
        else{
            message = new String("Cannot give student extra marks for good handriting!\nTry again.\n");
        }
    }

    public String toString(){
        return message;
    }
}
