package assignment6;

import java.util.Scanner;
import java.util.*;
import java.io.*;


public class Hospital{
    private ArrayList <Doctor> doctorTeam;
    private ArrayList <Patient> patients;
    
    private String  name,
                    test,
                    result;
    private int id;
    private long ssid;
    
    private Scanner sc;
    
    public Hospital(){
        doctorTeam = new ArrayList <Doctor> ();
        patients = new ArrayList <Patient> ();
        name = "";
        test = "";
        result = "";
        id = 0;
        ssid = 0;
        sc = new Scanner(System.in);
    }
    
    public void registerPatient(){
        Patient p = new Patient();
        System.out.println("Enter the Name : ");
        name = sc.nextLine();
        p.setPatientName(name);
        System.out.println("Enter the Social Security Number : ");
        ssid = sc.nextLong();
        p.setPatientSocialSecurityNumber(ssid);
        System.out.println("Want to assign a doctor (Y/N)?");
        sc.nextLine();
        name = sc.nextLine();
        p.setDoctorAssignedState(name.equals("Y") || name.equals("y"));
        
        if(p.getDoctorAssignedState()){
            System.out.println("Enter the Doctor Id : ");
            id = sc.nextInt();
            sc.nextLine();
            int i;
            for( i = 0; i < doctorTeam.size(); i++){
                if(doctorTeam.get(i).getDoctorId() == id){
                    break;
                }
            }
            if(i == doctorTeam.size() ){
                System.out.println("Doctor with that id number does not exist. Try Again!");
                p.setDoctorAssignedState(false);
            }
            else{
                p.setPatientsDoctorID(id);
                doctorTeam.get(i).addPatient(ssid);
                patients.add(p);
            }
        }
    
    }
    
    public void checkoutPatient(){
        System.out.println("Enter the Social Security Number of the patient to be released : ");
        ssid = sc.nextLong();
        sc.nextLine();
        boolean flag = false;
        int i;
        for(i = 0; i < patients.size(); i++){
            if(patients.get(i).getPatientSocialSecurityNumber() == ssid){
                flag = true;
                break;
            }
        }
        if(!flag){
            System.out.println("Such a patient is not currently in the hospital. Try Again!");
        }
        else{
            Patient p = patients.get(i);
            patients.remove(i);
            System.out.println(p);
            for(i = 0; i < doctorTeam.size(); i++){
                if(doctorTeam.get(i).getDoctorId() == p.getPatientsDoctorID()){
                    break;
                }
            }
            doctorTeam.get(i).removePatient(p.getPatientSocialSecurityNumber());
            
        }
    }
    
    public void conductTest(){
        System.out.println("Enter the Social Security Number of the patient on whom the test is going to be conducted : ");
        ssid = sc.nextLong();
        sc.nextLine();
        boolean flag = false;
        int i;
        for(i = 0; i < patients.size(); i++){
            if(patients.get(i).getPatientSocialSecurityNumber() == ssid){
                flag = true;
                break;
            }
        }
        if(!flag){
            System.out.println("Such a patient is not currently in the hospital. Try Again!");
        }
        else{
            flag = true;
            Patient p = patients.get(i);
            while(flag){
                System.out.println("Enter the Test Name : ");
                test = sc.nextLine();
                System.out.println("Enter the Test Result : ");
                result = sc.nextLine();
                System.out.println(test + "  " + result);
                System.out.println("If this is correct, press Y else press N and re-enter.");
                name = sc.nextLine();
                if(name.equals("Y") || name.equals("y")){
                    flag = false;
                }
            }
            p.addTestResults(test, result);
            
        }
    }
    
    public void addNewDoctor(){
        System.out.println("Enter the Id Number of the Doctor : ");
        id = sc.nextInt();
        for(int i = 0; i < doctorTeam.size(); i++){
            if(doctorTeam.get(i).getDoctorId() == id){
                System.out.println("Doctor with that id number already exists. Enter new id :");
                id = sc.nextInt();
                i = 0;
            }
        }
        System.out.println("Enter the Name of the Doctor : ");
        sc.nextLine();
        name = sc.nextLine();
        Doctor d = new Doctor();
        d.setDoctorName(name);
        d.setDoctorId(id);
        doctorTeam.add(d);
        
    }
    
    public void removeExistingDoctor(){
        
        System.out.println("Enter the Doctor Id : ");
        id = sc.nextInt();
        int i;
        for( i = 0; i < doctorTeam.size(); i++){
            if(doctorTeam.get(i).getDoctorId() == id){
                break;
            }
        }
        if(i == doctorTeam.size() ){
            System.out.println("Doctor with that id number does not exist. Can't remove!");
        }
        else{
            doctorTeam.remove(i);
        }
        sc.nextLine();
    }
    
    public void changePatientsDoctor(){
        int i, k = -1;
        System.out.println("Enter the Social Security Number : ");
        ssid = sc.nextLong();
        for(i = 0; i < patients.size(); i++){
            if(patients.get(i).getPatientSocialSecurityNumber() == ssid){
                k = i;
                break;
            }
        }
        if(i == patients.size()){
            System.out.println("Such a patient is not currently in the hospital. Try Again!");
        }
        else{
            id = patients.get(i).getPatientsDoctorID();
            
            for( i = 0; i < doctorTeam.size(); i++){
                if(doctorTeam.get(i).getDoctorId() == id){
                    break;
                }
            }
            if(i == doctorTeam.size() ){
                System.out.println("Doctor with that id number does not exist. Can't unassign from patient!");
            }
            else{
                System.out.println("Enter the Doctor Id you want the patient to be reassigned to: ");
                id = sc.nextInt();
                int j;
                for(j = 0; j < doctorTeam.size(); j++){
                    if(doctorTeam.get(j).getDoctorId() == id){
                        break;
                    }
                }
                if(j == doctorTeam.size() ){
                    System.out.println("Doctor with that id number does not exist. Can't reassign patient!");
                }
                else{
                    doctorTeam.get(i).removePatient(ssid);
                    doctorTeam.get(j).addPatient(ssid);
                    patients.get(k).setPatientsDoctorID( doctorTeam.get(j).getDoctorId() );
                }
            }
        }
        sc.nextLine();
    }
    
    
    public void assignPatientsDoctor(){
        int i;
        System.out.println("Enter the Social Security Number : ");
        ssid = sc.nextLong();
        for(i = 0; i < patients.size(); i++){
            if(patients.get(i).getPatientSocialSecurityNumber() == ssid){
                break;
            }
        }
        if(i == patients.size()){
            System.out.println("Such a patient is not currently in the hospital. Try Again!");
        }
        else{
            System.out.println("Enter the Doctor Id : ");
            id = sc.nextInt();
            int j;
            for( j = 0; j < doctorTeam.size(); j++){
                if(doctorTeam.get(j).getDoctorId() == id){
                    break;
                }
            }
            if(j == doctorTeam.size() ){
                System.out.println("Doctor with that id number does not exist. Try Again!");
            }
            else{
                patients.get(i).setPatientsDoctorID(id);
                patients.get(i).setDoctorAssignedState(true);
                doctorTeam.get(j).addPatient(ssid);
            }

        }
        sc.nextLine();
    }
    
//}
    
    private void displayMenu(){
        System.out.println("-------------------------------------------------------");
        System.out.println("\t\tMENU");
        System.out.println("-------------------------------------------------------");
        System.out.println("\t<0> Exit.\n");
        System.out.println("\t<1> Register new patient.\n");
        System.out.println("\t<2> Perform test on patient.\n");
        System.out.println("\t<3> Check out patient.\n");
        System.out.println("\t<4> Add new doctor.\n");
        System.out.println("\t<5> Remove an existing doctor.\n");
        System.out.println("\t<6> Assign doctor to a patient.\n");
        System.out.println("\t<7> Reassign new Doctor to a patient.\n");
        System.out.println("\t<9> Reprint options menu.");
    }

//public class HospitalMain{
    
    public static void main(String args[]){
        Hospital h1 = new Hospital();
        Scanner scanInput = new Scanner(System.in);
        int choice;
        h1.displayMenu();
        do{
            System.out.print("\nEnter a suitable choice:\t");
            choice = scanInput.nextInt();
            //scanInput.nextLine();
            switch(choice){
                case 0:
                    break;
                case 1:
                {
                    h1.registerPatient();
                    break;
                }
                    
                case 2:
                {
                    h1.conductTest();
                    break;
                }
                    
                case 3:
                {
                    h1.checkoutPatient();
                    break;
                }
                    
                case 4:
                    h1.addNewDoctor();
                    break;
                    
                case 5:
                {
                    h1.removeExistingDoctor();
                    break;
                }
                    
                case 6:
                {
                    h1.assignPatientsDoctor();
                    break;
                }
                    
                case 7:
                {
                    h1.changePatientsDoctor();
                    break;
                }
                    
                case 9:
                    h1.displayMenu();
                    break;
                    
                default:
                    System.out.println("Incorrect option chosen. Exiting. Bye!");
                    choice = 0;
                    break;
            }
            
        }while(choice != 0);

    }
}