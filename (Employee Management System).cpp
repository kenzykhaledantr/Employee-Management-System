#include<iostream>
#include<string>
using namespace std;
class Employee
{
    private:
    string pFull_name;
    string pEmail;
    string pPosition;
    string pPhone;
    double pSalary;
    public:
    Employee(){};
    Employee(string FN,string EM,string PO,string PH,double SA)
    {
        pFull_name=FN;
        pEmail=EM;
        pPosition=PO;
        pPhone=PH;
        pSalary=SA;
        
    }

       



     void set_Full_name(string Full_name)
    {
        pFull_name=Full_name;

    }
     void set_Email(string email)
    {
        pEmail=email;

    }
     void set_position(string postion)
    {
        pPosition=postion;

    }
     void set_phone(string phone )
    {
        pPhone=phone;

    }
     void set_salary(double salary)
    {
        pSalary=salary;

    }
       string getfullname()
    {
        return(pFull_name);
    }
       string getemail()
    {
        return(pEmail);
    }
       string getposition()
    {
        return(pPosition);
    }
       string getphone()
    {
        return(pPhone);
    }
       double getsalary()

    {
        return(pSalary);
    }
     void display_information_of_employee()
     {
        cout<<"The employee Name is : " <<getfullname()<<endl;
        cout<<"The Employee Email is : "<<getemail()<<endl;
        cout<<"The Employee Position is : "<<getposition()<<endl;
        cout<<"The Employee Phone is : "<<getphone()<<endl;
        cout<<"The Employee Salary is : "<<getsalary()<<endl;
     }
void insert_information()
{
 string Name,email,position,phone;
    double salary;
    cout<<"Enter your Name :  "<<endl;
    cin>>Name;
    set_Full_name(Name);
    cout<<"Enter your Email :  "<<endl;
    cin>>email;
    set_Email(email);
    cout<<"Enter your position :  "<<endl;
    cin>>position;
    set_position(position);
    cout<<"Enter your phone :  "<<endl;
    cin>>phone;
    set_phone(phone);
    cout<<"Enter your salary :  "<<endl;
    cin>>salary;
    set_salary(salary);
}
};

template <class T>
class Node{
    public:
        T data;
        Node<T>* next;
        
        Node(T e)
        {
             
            data = e;
            next = NULL;
        }
};
template <class T>
class EmployeeList{
	Node<T>* head;
    public:
    	EmployeeList(){
    	    head= NULL;
    	}

        void display(){
 cout<<" Employee Information Details :  "<<endl;
 Node<T>* tmp = head;
 if(head == NULL){
 cout<<"No Employee"<<endl;
 }
 while(tmp != NULL){
 tmp->data.display_information_of_employee();
 tmp = tmp->next;
 }
 cout<<endl;
 }




    	bool insert_employee(T e){
    	Node<T>* newNode = new Node<T>(e);
        
            Node<T>* tmp = head;
            if(head == NULL){
            head = newNode;
            return true;
            }
            
             while(tmp!=NULL)
            {
            if(tmp->data.getemail()==newNode->data.getemail())
            
            {
                cout<<"the employee already exist"<<endl;
                return false;
            }
            tmp = tmp->next;
            }
            
            Node<T>* tmp1 = head;
            
            while(tmp1->next!=NULL)
            {
    
                tmp1 = tmp1->next;
            }
            tmp1->next = newNode;
            return true;
           
        }
bool edit_salary(string email,double new_salary)
{
    Node<T>* tmp1 = head;
   
    while(tmp1!=NULL)
    {
         if(email!=tmp1->data.getemail())
         {
         cout<<"The Employee is not found"<<endl;
         }
    
     else
     {
        
            tmp1->data.set_salary(new_salary);
     }
        
        tmp1=tmp1->next;

    }
    return true;
}

     
bool delete_employee(string email){
         if (head==NULL)
			{cout << "No employee to delete "<<endl;
            return true;}
		Node<T>* ptr = head;

		if (ptr->data.getemail() == email)
		{
			
			head = head->next;
			delete ptr;
            cout<<"the employee deleted"<<endl;
		}
		else if (ptr->data.getemail() != email)
		{
			Node<T>* prv = NULL;
			ptr = head;
			while (ptr->data.getemail() != email)
			{
				prv = ptr;
				ptr = ptr->next;
                if (ptr==NULL)
                {
                    cout<<"the employee does not exist"<<endl;
                    return true;
                }
			}
			prv->next = ptr->next;
			delete ptr;
            
            cout<<"the employee deleted"<<endl;
            return true;
		}
       
         return true;

           
}

void update(int n,Node<T>* tmp2)
{
     string Name,email,position,phone;
    double salary;
    Employee emp( Name,email,position,phone,salary);
   


     switch (n)
   {
   case 1:
   cout<<"enter the name you want to change";
   cin>>Name;
   tmp2->data.set_Full_name(Name);
   
    break;
    case 2:
   cout<<"enter the email you want to change";
   cin>>email;
   tmp2->data.set_Email(email);
   
    break;
    case 3:
    cout<<"enter the position you want to change";
   cin>>position;
   tmp2->data.set_position(position);
  
    break;
    case 4:
    cout<<"enter the phone you want to change";
   cin>>phone;
   tmp2->data.set_phone(phone);
   
    break;
    case 5:
    cout<<"enter the salary you want to change";
   cin>>salary;
   tmp2->data.set_salary(salary);
   
   case 6:
   display();
   break;

   }

}

bool update_info(string email)
{

Node<T>* temp = head;
if(temp==NULL)
{
cout<<"the employee doesn't exist"<<endl;
}


    
while(temp!=NULL)
{
     
    
    if(temp->data.getemail()==email){

    int n;
    while(n!=7)
    {
    cout<<"choose from the menu information"<<endl;
    cout<<"********menu*******"<<endl;
    cout<<"1-change My name "<<endl;
    cout<<"2-change My email "<<endl;
    cout<<"3-change My position "<<endl;
    cout<<"4-change My phone "<<endl;
    cout<<"5-change My salary "<<endl;
    cout<<"6-Display the new information"<<endl;
    cout<<"7-close the program "<<endl;
    cout<<"Enter the number : "<<endl;
    cin>>n;
        update(n,temp);


    }
    cout<<"The program closed"<<endl;
    break;
    }
   
    temp=temp->next;

   
    
}

while(temp!=NULL){
 if(temp->data.getemail()!=email)
    {
        cout<<"the employee doesn't exist"<<endl;
    }
temp=temp->next;
}
cout<<"please try again "<<endl;

 
return true;
}
 	




void choose(int h)
{
     string Name,email,position,phone;
    double salary;
    Employee emp( Name,email,position,phone,salary);
     
   double newsalary;
   string mail;


     switch (h)
   {
   case 1:
   emp.insert_information();
    insert_employee(emp);
    display();
    break;
    case 2:
    cout<<"Enter your email please "<<endl;
    cin>>mail;
    cout<<"enter the salary you want to edit"<<endl;
    cin>>newsalary;
    edit_salary(mail,newsalary);
    display();
    break;
    case 3:
    cout<<"enter the email you want to delete"<<endl;
    cin>>mail;
    delete_employee(mail);
    break;
    case 4:
    display();
    break;
    case 5:
    cout<<"enter the email you want to update"<<endl;
cin>>email;
update_info( email);
break;



   }

}


    	
};


int main()
{
   
    EmployeeList<Employee> l;
    string email;
    
int n;

   while(n!=6)
   {
   cout<<"Welcome to the Employee Management System"<<endl;
   cout<<"please choose from the menu the option you need "<<endl;
   cout<<"************Menu***********"<<endl;
   cout<<" 1- Insert a new employee."<<endl;
   cout<<" 2- Edit employee's salary."<<endl;
   cout<<" 3- Delete an employee."<<endl;
   cout<<" 4- Print all employees."<<endl;
   cout<<" 5- update the information."<<endl;
   cout<<" 6- Close the program."<<endl;
   cout<<"Enter The number: "<<endl;
   cin>>n;

    
   l.choose(n);
    
   
   

   }
   cout<<"The program closed thank you for your choose :)"<<endl;
   
    return 0;
   
}