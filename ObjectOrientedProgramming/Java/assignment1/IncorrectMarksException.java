package assignment1;

import java.io.*;
import java.text.*;
import java.util.*;

class IncorrectMarksException extends Exception {

    public IncorrectMarksException(){
        System.out.println("No negative marks or extra marks for good handriting!\nTry again.\n\n");
    }

}