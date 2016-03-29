package assignment6;

import java.util.Scanner;
import java.util.*;
import java.io.*;

class NoSuchTestTakenException extends Exception {
    private String test;
    
    public NoSuchTestTakenException(String testName){
        test = new String(testName);
    }
    
    public String toString(){
        return ("Test with name : " + test + " not taken by patient.");
    }
}

class Patient{
	private String name;
	private int doctorID;
	private long socialSecurityNumber;
	private boolean isDoctorAssigned;
	private HashMap<String, String> testsPerformed;

	public Patient(){
		name = "";
		doctorID = -1;
		socialSecurityNumber = -1;
		isDoctorAssigned = false;
		testsPerformed = new HashMap<String, String>();
	}
	
	public void setPatientName(String s){
		name = new String(s);
	}

    public void setPatientSocialSecurityNumber(long ssid){
        socialSecurityNumber = ssid;
    }
    
    public void setPatientsDoctorID(int i){
        doctorID = i;
    }
    
    public void setDoctorAssignedState(boolean bool){
        isDoctorAssigned = bool;
    }
    
    public String getPatientName(){
        return name;
    }
    
    public long getPatientSocialSecurityNumber(){
        return socialSecurityNumber;
    }
    
    public int getPatientsDoctorID(){
        return doctorID;
    }
    
    public boolean getDoctorAssignedState(){
        return isDoctorAssigned;
    }
    
    public void addTestResults(String testName, String testResult){
        if(testsPerformed.containsKey(testName)){
            testsPerformed.remove(testName);
        }
        testsPerformed.put(testName, testResult);
    }
    
    public String getTestResults(String testName){
        try{
            if(testsPerformed.containsKey(testName)){
                return testsPerformed.get(testName);
            }
            else{
                throw new NoSuchTestTakenException(testName);
            }
        } catch (NoSuchTestTakenException e){
            System.out.println(e);
        }
        return null;
    }
    
    public String toString(){
        StringBuilder s = new StringBuilder(80);
        s.append("Name : " + name + "\n");
        s.append("Social Security Number : " + socialSecurityNumber + "\n");
        s.append("Id#  of attending doctor : " + doctorID + "\n");
        s.append("\n\t\tREPORTS\nTestName & Result\n");
        for(String testName : testsPerformed.keySet()){
            s.append(testName + "  \t\t " + testsPerformed.get(testName) + "\n");
        }
        return s.toString();
    
    }
}