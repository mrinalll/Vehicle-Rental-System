    #include <bits/stdc++.h>
    #include <conio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <iomanip>

    int num_cust=0;
    int num_car=2;

    using namespace std;

    void welcome();
    void cust_func();
    void owner_func();
    void reserve_car();
    void add_car();
    void delete_car();
    void update();
    void owner_data();
    string mark[20]  = {"Suzuki","Hyundai","Ford"};
    string model[20] = {"2016MD","2018AS","2018DS"};
    int price[20]  ={250,400,600} ;
    string max_speed[20] ={"100 Km/h ","150 Km/h","150 Km/h"};

    class customer
    {
        public:

        string customername;
        int carnumber;
        int car_arrival;
        int car_duration;
        int car_wait;
        int id;
        int rentalfee;

        int calculate(customer obj)
        {
            sleep(1);
            cout<<"Calculating rent. Please wait......"<<endl;
            sleep(2);
            int penalty;
            if(obj.car_wait>0&&obj.car_wait<=4)penalty=50;
            else if(obj.car_wait>4&&obj.car_wait<=8)penalty=100;
            else if(obj.car_wait>8&&obj.car_wait<=12)penalty=150;
            else if(obj.car_wait>12)penalty=250;
            cout << "\t\t	| Penalty Money :"<<"----------------|"<<setw(10)<<penalty<<" |"<<endl;
            obj.rentalfee=price[obj.carnumber]*obj.car_duration-penalty;
            return obj.rentalfee;
        }



        void list_func()
             {
          system("CLS");

             cout<<"\t\t\tThe list of available cars and their details are as follows : "<<endl;
             for (int i = 0;i!=num_car+1;++i)
             {
                 cout<<"\t\t\t\tCar name : "<<mark[i]<<endl;
                 cout<<"\t\t\t\tCar speed : "<<max_speed[i]<<endl;
                 cout<<"\t\t\t\tCar model : "<<model[i]<<endl;
                 cout<<"\t\t\t\tCar rental price per hour : "<<price[i]<<endl;
                 cout<<endl<<endl<<endl;
             }
             system("PAUSE");
             system("CLS");
             cust_func();
             }



             void add_car()
             {
                 num_car++;
                 cout<<endl<<"Enter Car's Name: ";
                 cin>>mark[num_car];
                 cout<<"\nEnter Car's Model: ";
                 cin>>model[num_car];
                 cout<<"\nEnter Car's Max speed: ";
                 cin>>max_speed[num_car];
                 cout<<"\nEnter Car's price per hour: ";
                 cin>>price[num_car];
                 system("CLS");
                 cout << "\n\n\n\t\t\t\t\t\tCar Added! \n";
                 owner_data();
                 }


            int find_string(string model[],string c_model)
            {
                for(int i=0;i<num_car+1;i++)
                    {
                        if(model[i]==c_model)
                {
                    return i;
                }
                    }
            }


            void erase_arr(int arr[],int it)
            {
                for(int j=it; j<num_car; j++)
              {
                  arr[j] = arr[j+1];

              }
            }



            void erase_arr(string arr[],int it)
            {
                for(int j=it; j<num_car; j++)
              {
                arr[j] = arr[j+1];

              }
    }



    void delete_car()
    {
        string c_name,c_model,c_price,c_mspeed;
        cout<<endl<<"Enter Car's Name: ";
        cin>>c_name;
        cout<<"\nEnter Car's Model: ";
        cin>>c_model;
        int it = find_string(model, c_model);
        erase_arr(model,it);
        erase_arr(mark,it);
        erase_arr(price,it);
        erase_arr(max_speed,it);
        num_car--;
        system("CLS");
        cout << "\n\n\n\t\t\t\t\t\tCar Deleted! \n"<<endl;
        owner_data();
    }



    void update()
    {
        string c_name,c_model,c_mspeed;
        int c_price;
        cout<<"\nEnter Car's Model: ";
        cin>>c_model;
        int it = find_string (model, c_model);
        cout<<endl<<"Enter Car's Name: ";
        cin>>c_name;
        mark[it]=c_name;
        cout<<"\nEnter Car's Max speed: ";
        cin>>c_mspeed;
        max_speed[it]=c_mspeed;
        cout<<"\nEnter Car's price per hour: ";
        cin>>c_price;
        price[it]=c_price;
        system("CLS");
        cout << "\n\n\n\t\t\t\t\t\tCar Details Updated! \n";
        owner_data();

    }



    void showrent(customer obj)
        {
        system("CLS");
        cout << "\n\t\t                       Car Rental - Customer Invoice                  "<<endl;
        cout << "\t\t	///////////////////////////////////////////////////////////"<<endl;
        cout << "\t\t	| Invoice No. :"<<"------------------|"<<setw(10)<<"#Cnb81353"<<" |"<<endl;
        cout << "\t\t	| Customer Name:"<<"-----------------|"<<setw(10)<<obj.customername<<" |"<<endl;
        cout << "\t\t	| Car Model :"<<"--------------------|"<<setw(10)<<model[obj.carnumber]<<" |"<<endl;
        cout << "\t\t	| Rented duration :"<<"---------------|"<<setw(10)<<obj.car_duration<<" |"<<endl;
        cout << "\t\t	| Caution Money :"<<"----------------|"<<setw(10)<<"0"<<" |"<<endl;
        cout << "\t\t	| Advanced :"<<"---------------------|"<<setw(10)<<"0"<<" |"<<endl;
        cout << "\t\t	 __"<<endl;
        int rent=calculate(obj);
        cout << "\t\t	| Total Rental Amount is :"<<"-------|"<<setw(10)<<rent<<" |"<<endl;
        cout << "\t\t	 __"<<endl;
        cout << "\t\t	 # This is a computer generated invoice and it does not"<<endl;
        cout << "\t\t	 require an authorised signture #"<<endl;
        cout <<" "<<endl;

        int f;
        system("PAUSE");
        system ("CLS");
        }



        void sjf(customer C[])
         {
            printf("*********\n\n");
            int et[20],at[10],n,i,j,temp,st[10],ft[10],wt[10],ta[10],id[10];
            int totwt=0,totta=0;
            float awt,ata;
            n=num_cust+1;
            for(i=0; i<n; i++)
                {
                    id[i]=i+1;
                    at[i]=C[i].car_arrival;
                    et[i]=C[i].car_duration;
                }
                for(i=0; i<n; i++)
                    for(j=0; j<n; j++)
                    {
                        if(at[i]<at[j])
                        {
                            temp=at[i];
                            at[i]=at[j];
                            at[j]=temp;
                            temp=et[i];
                            et[i]=et[j];
                            et[j]=temp;
                            temp=id[i];
                            id[i]=id[j];
                            id[j]=temp;
                        }
                        else if((et[i]<et[j])&&(at[i]==at[j]))
                        {
                            temp=at[i];
                            at[i]=at[j];
                            at[j]=temp;
                            temp=et[i];
                            et[i]=et[j];
                            et[j]=temp;
                            temp=id[i];
                            id[i]=id[j];
                            id[j]=temp;

                        }
                    }

                   for(i=0; i<n; i++)
                   {
                        if(i==0)
                           st[i]=at[i];
                        else
                           st[i]=ft[i-1];
                        wt[i]=st[i]-at[i];
                        ft[i]=st[i]+et[i];
                        ta[i]=ft[i]-at[i];
                  }
                  for( i=0;i<n-1;i++)
                {
                 for(j=0;j<n-1-i;j++)
               {
            if(id[j]>id[j+1])
            {
                temp=wt[j+1];
                wt[j+1]=wt[j];
                wt[j]=temp;
                temp=id[j+1];
                id[j+1]=id[j];
                id[j]=temp;
                temp=at[j+1];
                at[j+1]=at[j];
                at[j]=temp;
            }
        }
    }

    for(i=0;i<n;i++)
    {
        C[i].car_wait=wt[i];
        cout<<endl<<"Customer "<<C[i].customername<<"'s car will arrive at "<<at[i]+wt[i]<<endl;
    }
    system("PAUSE");
    getch();
    }

              void cust_func()
             {
              system("CLS");
              customer obj[20];
             for(int i=0;i<20;i++)
                {
             int a,id;
             cout<<endl<<endl;
             cout<<"\t\t\t\tEnter 1 to display the list of cars available. "<<endl;
             cout<<"\t\t\t\tEnter 2 to reserve a car. "<<endl;
             cout<<"\t\t\t\tEnter 3 to display bill. "<<endl;
             cout<<"\t\t\t\tEnter 4 to exit. "<<endl;
             cout<<endl<<endl;
             cout<<"Enter your choice : ";
             cin>>a;
             if(a==1)
             list_func();
             else if(a==2)
               reserve_car(obj);
             else if(a==3)
             {
                 cout<<"Enter customer id to print the bill : ";
                 cin>>id;
                 showrent(obj[id-1]);
             }
             else if(a==4)
                welcome();
             else{
             cout<<"Wrong choice entered , choose again !! "<<endl;
             cust_func();
             }
                   system("CLS");

             }
             }

             void reserve_car(customer obj[])
    {
        int choice;
        do{
        cout << "\n\n\t\t\t\tPlease Enter your Name: ";

        cin >> obj[num_cust].customername;
        cout<<"--------------------------------------------------------------------------"<<endl;
        for (int i = 0;i< num_car+1;++i)
             {
                 cout<<"\t\t\t";
                 cout<<"Enter " <<i+1<<"\t- To Select  "<<mark[i]<<endl;
             }
        cout << "\n\nPlease provide following information: "<<endl;
        cout<<"Please select a Car No. : ";
        cin >> obj[num_cust].carnumber;
        cout<<"Enter the arrival time of car : ";
        cin >> obj[num_cust].car_arrival;
        cout<<"Enter the duration of rental : ";
        cin >> obj[num_cust].car_duration;
        cout<<endl;
        cout<<"To add more bookings to the system press 1 , otherwise 0 : ";
        cin >> choice;
        if(choice) num_cust++;

        }while(choice);
       getchar();

        sjf(obj);


        }



       void owner_data()
        {
            int a;
             cout<<"\t\t\t\tEnter 1 to add a new car to the system. "<<endl;
             cout<<"\t\t\t\tEnter 2 to delete a car from the system. "<<endl;
             cout<<"\t\t\t\tEnter 3 to update car details of a car in the system"<<endl;
             cout<<"\t\t\t\tEnter 4 to return. "<<endl;
             cout<<endl<<endl;
             cout<<"Enter your choice : ";
             cin>>a;
             if(a==1)
             add_car();
             else if(a==2)
             delete_car();
             else if(a==3)
             update();
             else if(a==4)
             welcome();
             else{
             cout<<"Wrong choice entered , choose again !! "<<endl;
             owner_data();
        }

    }



             void owner_func()
             {
            system("CLS");
            string pass ="";
            char ch;
            cout<<"\n\t\t\t\t\t\t     LOGIN \n";
            cout<<"\t\t\t\t\t------------------------------\n\n";
            cout << "\t\t\t\t\tEnter Password: ";
            ch = _getch();
           while(ch != 13)
            {
           pass.push_back(ch);
           cout << '*';
           ch = _getch();
            }
       if(pass == "pass")
        {
          cout << "\n\n\n\t\t\t\t\t\tAccess Granted! \n";
          system("PAUSE");
          system ("CLS");
          owner_data();
        }
       else
       {
          cout << "\n\n\t\t\t\t\t\t\tAccess Aborted...\n\t\t\t\t\t\t\tPlease Try Again\n\n";
          system("PAUSE");
          system("CLS");
          welcome();
       }
       }
       };



         void welcome()
            {
            system("CLS");
        customer C;
        cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t       VEHICLE RENTAL SYSTEM \n\n";
       cout<<"\t\t\t\t\t------------------------------"<<endl;
       cout <<"\t\t\t\tPlease Select a portal"<<endl;
            cout<<"\t\t\t\tEnter 'A' for Owner."<<endl;
            cout<<"\t\t\t\tEnter 'B' for Customer."<<endl;
            cout<<"\t\t\t\tEnter 'C' for Exit."<<endl;
            char ch;
            cin>>ch;
            if(ch=='A'||ch=='a')
            {
                C.owner_func();
            }
            else if(ch=='B'||ch=='b')
            {
                C.cust_func();
            }
            else if(ch=='C'||ch=='c')
            {
                exit(0);
            }
    }



    int main()
    {
        welcome();
    return 0;
    }
//1 1 1 3 1 2 1 2 4 1 3 1 1 2 1 4 1 4 4
