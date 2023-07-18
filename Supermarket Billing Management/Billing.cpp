#include<iostream>
#include<fstream>
using namespace std;

class shopping
{
private:
    int pcode; //product code
    float price;
    float dis; //discount
    string pname; //product name

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit(); //Modify any Product
    void rem(); //remove function
    void plist();
    void recepit();
};

void shopping:: menu()
{
m:
    int choice;
    string email;
    string password;

    cout<<"\t\t\t\t________________________________\n";
    cout<<"\t\t\t\t                                \n";
    cout<<"\t\t\t\t      Supermarket Main Menu     \n";
    cout<<"\t\t\t\t                                \n";
    cout<<"\t\t\t\t________________________________\n";
    cout<<"\t\t\t\t                                \n";
    cout<<"\t\t\t\t      1. Administrator          \n";
    cout<<"\t\t\t\t                                \n";
    cout<<"\t\t\t\t      2. Buyer                  \n";
    cout<<"\t\t\t\t                                \n";
    cout<<"\t\t\t\t      3. Exit                   \n";
    cout<<"\t\t\t\t                                \n";
    cout<<"\n\t\t\t Please Select: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        cout<<"\n\t\t\t Please Login \n";
        cout<<"\t\t\t Enter Email: ";
        cin>>email;
        cout<<"\t\t\t Password:    ";
        cin>>password;

        if(email=="satwikn@gmail.com" && password=="******")
        {
            administrator();
        }
        else
        {
            cout<<"\n\t\t\tInvalid Email/Password\n\n";
        }
        break;
    case 2:
        buyer();
        break;
    case 3:
        exit(0);
        break;
    default:
        cout<<"WRONG CHOICE";
        break;
    }
    goto m;
}

void shopping:: administrator()
{
m:
    int choice;
    cout<<"\n\n\n\t\t\t Administration Menu";
    cout<<"\n                           ";
    cout<<"\n\t\t\t 1. Add The Product";
    cout<<"\n                           ";
    cout<<"\n\t\t\t 2. Modify The Product";
    cout<<"\n                           ";
    cout<<"\n\t\t\t 3. Delete The Product";
    cout<<"\n                           ";
    cout<<"\n\t\t\t 4. Back to Main Menu";
    cout<<"\n\n\t Please Enter Your Choice ";
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
        cout<<"WRONG CHOICE";
        break;
    }
    goto m;
}

void shopping:: buyer()
{
m:
    int choice;
    cout<<"\n\n\t\t\t        Buyer        \n";
    cout<<"\t\t\t_____________________\n";
    cout<<"                           \n";
    cout<<"\t\t\t  1. Buy Product     \n";
    cout<<"                           \n";
    cout<<"\t\t\t  2. Go Back         \n";
    cout<<"\n\t\t\tEnter Choice: ";
    cin>>choice;
    switch(choice)
    {
    case 1:
        recepit();
        break;
    case 2:
        menu();
    default:
        cout<<"WRONG CHOICE";
    }
    goto m;
}

void shopping:: add()
{
m:
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;

    cout<<"\n\n\t\t\t Add New Products ";
    cout<<"\n\n\t Product Code: ";
    cin>>pcode;
    cout<<"\n\n\t Name Of Product: ";
    cin>>pname;
    cout<<"\n\n\t Price Of Product: ";
    cin>>price;
    cout<<"\n\n\t Discount on the Product: ";
    cin>>dis;

    data.open("Database.txt",ios::in);
    if(!data)
    {
        data.open("Database.txt",ios::app|ios::out);
        data<<"  "<<pcode<<"  "<<pname<<"  "<<price<<"  "<<dis<<"\n";
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
            data.open("Database.txt",ios::app|ios::out);
            data<<"  "<<pcode<<"  "<<pname<<"  "<<price<<"  "<<dis<<"\n";
            data.close();
        }
    }
    cout<<"\n\n\t\t Record Inserted ";
}

void shopping:: edit()
{
    fstream data, data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;
    cout<<"\n\t\t\t Modify the Record ";
    cout<<"\n";
    cout<<"\n\t\t\t Product Code: ";
    cin>>pkey;
    data.open("Database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n File Does't Exist ";
    }
    else
    {
        data1.open("Database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"\n\t\t Product New Code: ";
                cin>>c;
                cout<<"\n\t\t Name Of the Product: ";
                cin>>n;
                cout<<"\n\t\t Price: ";
                cin>>p;
                cout<<"\n\t\t Discount: ";
                cin>>d;
                data1<<"  "<<c<<"  "<<n<<"  "<<p<<"  "<<d<<"\n";
                cout<<"\n\n\t\t Record Edited ";
                token++;
            }
            else
            {
                data1<<"  "<<pcode<<"  "<<pname<<"  "<<price<<"  "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();

        remove("Database.txt");
        rename("Database1.txt","Database.txt");
        if(token==0)
        {
            cout<<"\n\n Record Not Found. Sorry!!!";
        }
    }
}

void shopping:: rem()
{
    fstream data,data1;
    int pkey;
    int token=0;
    cout<<"\n\n\t Delete Product ";
    cout<<"\n\n\t Enter Product Code: ";
    cin>>pkey;
    data.open("Database.txt",ios::in);
    if(!data)
    {
        cout<<"File Doesn't Exist ";
    }
    else
    {
        data1.open("Database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pcode==pkey)
            {
                cout<<"\n\n\t Product Deleted Succesfully ";
                token++;
            }
            else
            {
                data1<<"  "<<pcode<<"  "<<pname<<"  "<<price<<"  "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("Database.txt");
        rename("Database1.txt","Database.txt");
        if(token==0)
        {
            cout<<"\n\n Record Not Found. Sorry!!!";
        }
    }
}

void shopping:: plist()
{
    fstream data;
    data.open("Database.txt",ios::in);
    cout<<"\n\n__________________________________________________\n";
    cout<<"Product No. \t\t Name \t\t Price \n";
    cout<<"\n\n__________________________________________________\n";
    data>>pcode>>pname>>price>>dis;
    while(!data.eof())
    {
        cout<<pcode<<" \t\t\t "<<pname<<" \t\t "<<price<<"\n";
        data>>pcode>>pname>>price>>dis;
    }
    data.close();
}

void shopping:: recepit()
{
    fstream data;
    int arrc[100]; //Array Of Product Codes
    int arrq[100]; //Array of Quantity
    char choice;
    int c=0;
    float amount=0;
    float dis=0;
    float total=0;

    cout<<"\n\n\t\t\t\t RECEPIT ";
    data.open("Database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n EMPTY DATABASE";
    }
    else
    {
        data.close();

        plist();
        cout<<"\n\t\t\t_____________________________________\n";
        cout<<"\n\t\t\t        Please Place The Order       \n";
        cout<<"\n\t\t\t_____________________________________\n";
        do
        {
m:
            cout<<"\n\n Enter Product Code: ";
            cin>>arrc[c];
            cout<<"\n\n Enter The Quantity: ";
            cin>>arrq[c];
            for(int i=0; i<c; i++)
            {
                if(arrc[c]==arrc[i])
                {
                    cout<<"\n\n Duplicate Product Code, Please Try Again";
                    goto m;
                }
            }
            c++;
            cout<<"\n\n Do You Want To Buy Another Product? Press 'y' if Yes and 'n' if No: ";
            cin>>choice;
        }
        while(choice=='y');

        cout<<"\n\n\t\t\t______________________RECEPIT______________________\n";
        cout<<"\n Product No. \t Product Name \t Product Quantity \tPrice \t   Amount\tAmount with Discount\n";
        data.open("Database.txt", ios::in);
        if (!data)
        {
            cout << "\n\n ERROR: Unable to open database file";
        }
        else
        {
            while (data >> pcode >> pname >> price >> dis)
            {
                for (int i = 0; i < c; i++)
                {
                    if (pcode == arrc[i])
                    {
                        amount = price * arrq[i];
                        dis = amount - (amount * dis / 100);
                        total += dis;
                        cout << "\n" << pcode << "\t\t   " << pname << "\t\t" << arrq[i] << "\t\t" << price << "\t\t" << amount << "\t\t" << dis;
                    }
                }
            }
            data.close();
        }
    }
    cout<<"\n\n________________________________________";
    cout<<"\n Total Amount: "<<total;
    cout<<"\n\n";
}

int main()
{
    shopping s;
    s.menu();
}


