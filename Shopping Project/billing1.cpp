#include<iostream>
#include<fstream>

using namespace std;

class shopping
{
    private:
    int pcode;   // p for product
    float price;
    float dis;
    string pname;

    public:
      void menu();
      void administrator();
      void buyer();
      void add();
      void edit();
      void rem();
      void list();
      void receipt();

};

void shopping :: menu()
{
    m:
    int choice;
    string email;
    string password;

    cout<<"\t\t\t..................................\n";
    cout<<"\t\t\t                                  \n";
    cout<<"\t\t\t          Walmart Menu            \n";
    cout<<"\t\t\t                                  \n";
    cout<<"\t\t\t..................................\n";
    cout<<"\t\t\t                                  \n";

    cout<<"\t\t\t |  1) Administrator  |\n";
    cout<<"\t\t\t |                    |\n";
    cout<<"\t\t\t |  2) Customer       |\n";
    cout<<"\t\t\t |                    |\n";
    cout<<"\t\t\t |  3) EXIT           |\n";
    cout<<"\t\t\t |                    |\n";
    cout<<"\n\t\t\t Please select:";
    cin>>choice;

    switch(choice)
    {
        case 1:
           cout<<"\t\t\t Please Enter your login details \n ";
           cout<<"\t\t\t Enter your registered Email : \n";
           cin>>email;
           cout<<"\t\t\t Enter your Password : \n";
           cin>>password;

           if(email=="gaurav@gmail.com" && password=="gaurav")
           {
               administrator();
           }
           else{
               cout<<"Invalid Credentials";
           }
           break;

        case 2:
           {
               buyer();
           }

        case 3:
           {
               exit(0);  //For successful termination of my code
           }

           default :
             {
                 cout<<"Please Choose from only these options";
             }

    }
    
    goto m;

}

void shopping :: administrator()
{
    m:
    int choice;
    cout<<"\n\n\n\t\t\t  Admin Menu";
    cout<<"\n\t\t\t |_____  1) Add Product  _____|";
    cout<<"\n\t\t\t                                 ";
    cout<<"\n\t\t\t |_____  2) Modify Product  _____|";
    cout<<"\n\t\t\t                                 ";
    cout<<"\n\t\t\t |_____  3) Delete Product  _____|";
     cout<<"\n\t\t\t                                 ";
     cout<<"\n\t\t\t |_____  4) Return to Walmart Menu  _____|";

     cout<<"\n\n Please Enter";
     cin>>choice;

     switch(choice)
     {
         case 1:
            add();
            break;
         case 2:
            edit();
            break;
         case 3:
            rem();
            break;
         case 4:
            menu();
            break;
         default:
           cout<<"Choose from these options only";
     }

     goto m;
}

void shopping :: buyer()
{
    m:
    int choice;
    cout<<"\t\t\t   Customer        \n";
    cout<<"\t\t\t                   \n";
    cout<<"\t\t\t   1) Buy Product  \n";
    cout<<"\t\t\t                   \n";
    cout<<"\t\t\t   2) Return Back  \n";
    cout<<"\t\t\t Enter :             ";
    cin>>choice;

    switch(choice)
    {
        case 1:
           receipt();
           break;
        case 2:
           menu();
           break;
        default:
           cout<<"***Choose from given options only***";

    }
goto m;
}

void shopping :: add()
{
    m:
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;

    cout<<"\n\n\t\t\t Add New Product";
    cout<<"\n\n\t Product Code of the Product";

    cin>>pcode;
    cout<<"\n\n\t Name of Product ";
    cin>>pname;
    cout<<"\n\n\t Price :";
    cin>>price;
    cout<<"\n\n\n Discount on product";
    cin>>dis;

    data.open("database.txt",ios::in);  //to open in reading mode

    if(!data)
    {
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    else
    {
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
          {
             goto m;
          }   
          else
          {
              data.open("database.txt",ios::app|ios::out);
              data<<" "<<pcode<<" "<<pname<<" "<<" "<<price<<" "<<dis<<"\n";
              data.close();

          }
    }
    cout<<"\n\n\t\t  Product Listed ";

}

void shopping :: edit()
{
    fstream data,data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\t\t\t  Modify listed Products ";
    cout<<"\n\t\t\t  Enter the product code ";
    cin>>pkey;

    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n No Record Exist";

    }
    else{
        data1.open("database1.txt",ios::app|ios::out);

        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"\n\t\t Enter the New Code:";
                cin>>c;
                cout<<"\n\t\t Enter the Name:";
                cin>>n;
                cout<<"\n\t\t Enter the Price";
                cin>>p;
                cout<<"\n\t\t Discount :";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\t\t Record Updated";
                token++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0)
        {
            cout<<"\n\n Record Not Found";
        }

    }
}

void shopping :: rem()
{
    fstream data,data1;
    int pkey;
    int token=0;
    cout<<"\n\n\t Delete Product ";
    cout<<"\n\n\t Enter the Code of Product to be deleted ";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"File does not exist";
    }
    else
    {
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pcode==pkey)
            {
                cout<<"\n\n\t Product Deleted Successfully";
                token++;
            }
            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";

            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0)
        {
            cout<<"\n\n\t Record not found";
        }
       
    }

}

void shopping :: list()
{
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n|________________________________________\n";
    cout<<"Product No\t\tName\t\tPrice\n";
    cout<<"\n\n|________________________________________\n";
    data>>pcode>>pname>>price>>dis;
    while(!data.eof())
    {
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
        data>>pcode>>pname>>price>>dis;

    }
    data.close();

}

void shopping:: receipt()
{
    fstream data;

    int arrc[100];
    int arrq[100];
    char choice;
    int c=0;
    float amount=0;
    float dis=0;
    float total=0;

    cout<<"\n\n\t\t\t   RECEIPT  ";

    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n Empty Database";

    }
    else
    {
        data.close();

        list();
        cout<<"\n_________________________________\n";
        cout<<"\n                                  \n";
        cout<<"\n     Please Place your order      \n";
        cout<<"\n                                  \n"; 
        cout<<"\n_________________________________\n";     
        
        do{
            m:
            cout<<"\nEnter Product Code";
            cin>>arrc[c];
            cout<<"\n\n Enter the Quantity";
            cin>>arrq[c];
            for(int i=0;i<c;i++)
            {
                if(arrc[c]==arrc[i])
                {
                    cout<<"\n\n Duplicate Product Code. Please try again";
                    goto m;
                }
            }
            c++;
            cout<<"Want to buy another product? If yes press y else n";
            cin>>choice;


        } while(choice=='y');

        cout<<"\n\n\n\t\t _________________RECEIPT____________";
        cout<<"\n Product No\tProduct Name\tProduct Quantity\tPrice\tAmount\tAmount with Discount\n";

        for(int i=0;i<c;i++)
        {
            data.open("database.txt",ios::in);
            data>>pcode>>pname>>price>>dis;
            while(!data.eof())
            {
                if(pcode==arrc[i])
                {
                    amount = price*arrq[i];
                    dis= amount - (amount*dis/100);
                    total=total+dis;
                    cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<dis;
                }
                data>>pcode>>pname>>price>>dis;
            }
        }
        data.close();



    }
    cout<<"\n\n______________________________";
    cout<<"\n Total Amount is : "<<total;


}

int main()
{
    shopping s;
    s.menu();

}