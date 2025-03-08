#include <iostream>
#include <string>
using namespace std;
class BankAccount{
  int balance;
  int previous_transaction;
  const string IFSC="HNS09234";
  string token="greeshma";
  const string acc="98765";
  void deposit(int amount){
      if(amount>=0){
          balance=balance+amount;
          previous_transaction=amount;
      }
  }
  void withdraw(int amount){
      if(amount>=0){
          balance=balance-amount;
          previous_transaction=-amount;
      }
  }
  
  protected:
  string aadhar="\0";
  string pan="\0";
  long long phoneNumber;
  string customerName;
  string customerId="00001";
  string DoB;
  string get_customerid(){
      return customerId;
  }
  string get_token(){
      return token;
  }
  bool valid_date(string date){
       string str1,str2,str3;
       
       int dd,mm,yy;
       dd=stoi(date.substr(0,2));
       mm=stoi(date.substr(3,2));
       yy=stoi(date.substr(6,4));
       if(date[2]!='-'||date[5]!='-'){
           return false;
       }
      if(yy>0&&yy<2023)
       {
         if(mm==1 || mm==3 || mm==5|| mm==7|| mm==8||mm==10||mm==12 && dd>0 && dd<=31)
         return true;
         else
          if(mm==4 || mm==6 || mm==9|| mm==11 && dd>0 && dd<=30)
            return true;
         else
            if(mm==2)
               {
               if((yy%400==0 || (yy%100!=0 && yy%4==0)) && dd>0 && dd<=29)
                 return true;
               else if(dd>0 && dd<=28)
                  return true;
               else{
                  return false;
               }
               }
         else{
              return false;
         }
              
      }
    else{
              return false;
    }
        
  }
  void update_details(){
      cout<<"A. update phoneNumber"<<endl;
      cout<<"B. add AadharNumber"<<endl;
      cout<<"C. add pan number"<<endl;
      cout<<"D. Exit"<<endl;
      char opt='\0';
      do{ cout<<"Enter an option"<<endl;
          cin>>opt;
      switch(opt){
          case 'A':{
              cout<<"please enter phoneNumber"<<endl;
            long long phone;
            do{
                cin>>phone;
            int length =  std::to_string(phone).length();
            if(length!=10){
                cout<<"Please enter valid phone number."<<endl;
            }
            else{
                phoneNumber=phone;
                break;
            }
            }while(1);
            break;
          }
            
          case 'B':{
              if(aadhar=="\0"){
                    cout<<"please enter AadharNumber"<<endl;
                    string adhar;
                    do{
                        cin>>adhar;
                    if(adhar.length()!=12){
                       cout<<"plese enter valid AadharNumber"<<endl;
                    }
                    else{
                       aadhar=adhar;
                       break;
                    }   
                    }while(1);
                        
                }
            else{
                    cout<<"AadharNumber:"<<aadhar<<endl;
                    cout<<"For updating please contact Maneger"<<endl;
                }
            break;
          }
            
           case 'C':{
               if(pan=="\0"){
                    cout<<"please enter PAN Number"<<endl;
                    string adhar;
                    do{
                        cin>>adhar;
                    if(adhar.length()!=10){
                       cout<<"plese enter valid PAN Number"<<endl;
                    }
                    else{
                       pan=adhar;
                       break;
                    }
                    }while(1);
                        
                }
            else{
                    cout<<"PAN Number:"<<pan<<endl;
                    cout<<"For updating please contact Manager"<<endl;
                }
            break;
           }
            
          default:
              cout<<"*******************"<<endl;
            break;
      }
      }while(opt!='D');
  }
  
  public:
  void create_new_account(){
      cout<<"Enter your Name"<<endl;
                cin>>customerName;
                cout<<"Enter your DoB(dd-mm-yy)"<<endl;
                do{
                    string Date;
                    cin>>Date;
                    if(!valid_date(Date)){
                        cout<<"Please enter valid Date-of-Birth(dd-mm-yy)"<<endl;
                    }
                    else{
                        DoB=Date;
                        break;
                    }
                }while(1);
                
                customerId+=1;
                cout<<"Enter your Phone Number"<<endl;
                long long phone;
                
                do{  
                    cin>>phone;
                    int int_length = to_string(phone).length();
                    if(int_length!=10){
                      cout<<"Please enter valid phone number."<<endl;
                    }
                    else{
                       phoneNumber=phone;
                       break;
                    }
                }while(1);
                cout<<"Enter your AadharNumber"<<endl;
                string adhar;
                do{
                    cin>>adhar;
                    if(adhar.length()!=12){
                       cout<<"plese enter valid AadharNumber"<<endl;
                    }
                    else{
                        aadhar=adhar;
                        break;
                    }
                }while(1);
                cout<<"Enter your PAN Number"<<endl;
                do{
                    cin>>adhar;
                    if(adhar.length()!=10){
                       cout<<"plese enter valid PAN Number"<<endl;
                    }
                    else{
                        pan=adhar;
                        break;
                    }
                }while(1);
                
                cout<<"please deposit minimum of 500"<<endl;
                int amount;
                do{
                    cin>>amount;
                if(amount>=500){
                    deposit(amount);
                    break;
                }
                else{
                    cout<<"please deposit minimum of 500"<<endl;
                }
                }while(1);
                
  }
};

int main() {
    Customer person;
    cout<<"A.Sign up"<<endl;
    cout<<"B.Login in"<<endl;
    char c='\0';
    cout<<"Please enter option"<<endl;
    
    do{ cin>>c;
        if(c=='A'){
        person.create_new_account();
        person.show_menu();
        break;
        }
        else if(c=='B'){
        person.details(); 
        person.show_menu();
        break;
        }
        else{
        cout<<"Please enter valid option"<<endl;
        }
    }while(1);
    Manager m;
    m.change();
    
}
