package assignment6;

import java.util.Scanner;
import java.util.*;
import java.io.*;


class Doctor{
    private String name;
    private int id;
    private ArrayList<Long> patients;
    
    public Doctor(){
        name = "";
        id = -1;
        
        patients = new ArrayList<Long>();
    }
    
    public void setDoctorName(String s){
        name = new String(s);
    }
    
    public void setDoctorId(int i){
        id = i;
    }
    
    public String getDoctorName(){
        return name;
    }
    
    public int getDoctorId(){
        return id;
    }
    
    public void addPatient(long ssid){
        Long ssidLong = new Long(ssid);
        if(patients.contains(ssidLong)){
            System.out.println("Doctor " + name + " is already treating patient with social security # " + ssidLong + ".");
        }
        else{
            patients.add(ssidLong);
        }
    }
    
    public void removePatient(long ssid){
        Long ssidLong = new Long(ssid);
        if(patients.contains(ssidLong)){
            patients.remove(ssidLong);
        }
        else{
            System.out.println("Doctor " + name + " is not treating patient with social security # " + ssidLong + ". Can't remove from list!");
        }
        
    }
}