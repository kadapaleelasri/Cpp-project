#include<iostream>
#include<fstream>
using namespace std;
class supermarket{
    private:
    int pcode;
    string pname;
    float price;
    float dis;
    public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void receipt();
    void list();
    void display()
    {
        
    cout<<"\n------------------------------------------SUPERMARKET BILLING SYSTEM PROJECT---------------------------------------------\n";
    }
};
void supermarket::menu()
{ 
    x:
    int choice;
    string email;
    string password;
    cout<<"\n----------SUPERMARKET MAIN MENU----------\n";
    cout<<"|                                       |"<<endl;
    cout<<"|          1.Administrator              |"<<endl;
    cout<<"|                                       |"<<endl;
    cout<<"|          2.Buyer                      |"<<endl;
    cout<<"|                                       |"<<endl;
    cout<<"|          3.Exit                       |\n"<<endl;
    cout<<"Please Select:";
    cin>>choice;
    switch(choice)
    {
        case 1:
        {
            cout<<"\nPlease Login"<<endl;
            cout<<"\nEnter Email:";
            cin>>email;
            cout<<"\nEnter Password:";
            cin>>password;
        if(email=="leela@gmail.com" && password=="leela#123")
              administrator();
            
            else{
                cout<<"Invalid Email or Password!";
            }
            break;
        }
        case 2:
        {
            buyer();
            break;
        }
        case 3:
        {
            exit(0);
        
        }
        default:
        {
            cout<<"\nPlease Enter Valid Choice!\n";
        }

    }
    goto x;

}
void supermarket::administrator()
{
    x:
    int choice;
    cout<<"\n---------ADMINISTRATOR MENU---------"<<endl;
    cout<<"|                                  |"<<endl;
    cout<<"|       1.Add the Product          |"<<endl;
    cout<<"|                                  |"<<endl;
    cout<<"|       2.Modify the Product       |"<<endl;
    cout<<"|                                  |"<<endl;
    cout<<"|       3.Delete the Product       |"<<endl;
    cout<<"|                                  |"<<endl;
    cout<<"|       4.Go back to Main Menu     |\n"<<endl;
    cout<<"Enter Your Choice:";
    cin>>choice;
    switch(choice)
    {
        case 1:
        {

            add();
            break;
        }
        case 2:
        {
            edit();
            break;
        }
        case 3:
        {
            rem();
            break;
        }
        case 4:
        {
          menu();
          break;
        }
        default:
        {
            cout<<"Invalid Choice!";
        }
    }
    goto x;
}
void supermarket::buyer()
{
    x:
    int choice;
    cout<<"\n";
    cout<<"------------Buyer------------"<<endl;
    cout<<"|                           |"<<endl;
    cout<<"|   1.Buy the product       |"<<endl;
    cout<<"|                           |"<<endl;
    cout<<"|   2.Go Back               |"<<endl;
    cout<<"\nPlease Enter Your Choice:";
    cin>>choice;
    switch(choice)
    {
        case 1:
        {
            receipt();
            break;
        }
        case 2:
        {
          menu();
          break;
        }
        default:
        {
            cout<<"Invalid Choice!";
        }
    }
    goto x;
}
void supermarket::add()
{
    x:
    fstream data;
    int c;
    float p;
    float d;
    string n;
    int token=0;
    cout<<"\nAdd the New Product"<<endl;
    cout<<"\nEnter the Product Code:";
    cin>>pcode;
    cout<<"\nEnter the Product Name:";
    cin>>pname;
    cout<<"\nEnter the Product Price:";
    cin>>price;
    cout<<"\nEnter the Discount on the  Product :";
    cin>>dis;
    data.open("products.txt",ios::in);
    if(!data)
    {
        data.open("products.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    else{
        data>>c>>n>>p>>d;
        while(!data.eof())
        {
            if(c==pcode)
            {
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();
        if(token==1)
        goto x;
        else{
             data.open("products.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
        }
    }
    cout<<"\nRecord is Created!";   
}

void supermarket::edit()
{
    fstream data,data1;
    int pkey;
  int c;
  int count=0;
  float p;
  float d;
  string n;
  cout<<"\nModify the Record"<<endl;
  cout<<"\nEnter the Product Code:";
  cin>>pkey;
  data.open("products.txt",ios::in);
  if(!data)
  {
    cout<<"File doesn't Exist!";
  }
  else{
    data1.open("products1.txt",ios::app|ios::out);
    data>>pcode>>pname>>price>>dis;
    while(!data.eof())
    {
        if(pkey==pcode)
        {
            cout<<"\nEnter the New Product Code:";
            cin>>c;
            cout<<"\nEnter the Product Name:";
            cin>>n;
             cout<<"\nEnter the Product Price:";
            cin>>p;
             cout<<"\nEnter the Product Discount:";
            cin>>d;
            data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
            cout<<"\nRecord Modified!";
             count++; 
        }
        else{
            data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        }
         data>>pcode>>pname>>price>>dis;
    }
    data.close();
        data1.close();
        remove("products.txt");
        rename("products1.txt","products.txt");
        if(count==0)
        {
            cout<<"\nRecord not Found!";
        }


  }
}
void supermarket::rem()
{
    fstream data,data1;
     
      int pkey;
      int count=0;
      cout<<"\nDelete the Product\n";
  cout<<"\nEnter the Product Code:";
  cin>>pkey;
  data.open("products.txt",ios::in);

  if(!data)
       {
        cout<<"File doesn't Exist!";
       }
       else{
        data1.open("products1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pcode==pkey)
            {
                cout<<"\nProduct deleted Successfully!";
                count++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
         data.close();
        data1.close();
        remove("products.txt");
        rename("products1.txt","products.txt");
        if(count==0)
        {
            cout<<"\nRecord not Found!";
        }

       }
}

void supermarket::list()
{
      fstream data;
      data.open("products.txt",ios::in);
      cout<<"\n\n-------------------------------------------------------------\n";
      cout<<"ProductNo\t\tName\t\t\tPrice\n";
      cout<<"\n-------------------------------------------------------------\n";
      data>>pcode>>pname>>price>>dis;
      while(!data.eof())
      {
        cout<<pcode<<"\t\t\t"<<pname<<"\t\t\t"<<price<<"\n";
        data>>pcode>>pname>>price>>dis;
      

}
data.close();
}
void supermarket ::receipt()
{
fstream data;
int arrc[200];
int arrq[200];
char choice;
int c=0;
float amount=0;
float dis=0;
float total=0;
cout<<"\n\t\t\tProducts List\t\t    ";
data.open("products.txt",ios::in);
if(!data)
{
    cout<<"\n\n Empty File";
}
else
{
    data.close();
    list();
    cout<<"\n----------------------------------------------------------------------\n";
    cout<<"\n                  please place order                                  \n";
    cout<<"\n----------------------------------------------------------------------\n";
    do
    { 
        x:
        cout<<"\n\nEnter Product Code : ";
        cin>>arrc[c];
        cout<<"\n\nEnter the Product Quantity : ";
        cin>>arrq[c];
        for(int i=0;i<c;i++)
        {
            if(arrc[c]==arrc[i])
            {
                cout<<"\n\n Duplicate Product Code.Please Try Again!";
                goto x;
            }
        }
        c++;
        cout<<"\n\n Do You Want To Buy Another Product? If Yes then Press y else n :";
        cin>>choice;
        
    }
    while(choice == 'y');
    cout<<"\n\n--------------------------------------RECEIPT------------------------------------------------\n";
    cout<<"\nProduct No\t Product Name\t Product Quantity\t Price\t Amount\t Amount with Discount\n";
    for(int i=0;i<c;i++)
    {
        data.open("products.txt",ios::in);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pcode==arrc[i])
            {
                amount=price*arrq[i];
                dis=amount-(amount*dis/100);
                total=total+dis;
                cout<<"\n"<<pcode<<"\t\t "<<pname<<"\t\t\t "<<arrq[i]<<"\t\t "<<price<<"\t "<<amount<<"\t  "<<dis;
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
}
    }
    
cout<<"\n\n---------------------------------------------------------------------------------------------";
cout<<"\n Total Amount :  "<<total;
cout<<"\n\n---------------------------------------------------------------------------------------------";

}
int main()
{
    supermarket s;
    s.display();
    s.menu();
    return 0;
}