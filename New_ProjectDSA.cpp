    #include<stdio.h>
    #include<stdlib.h>
    #include<time.h>
    #include<ctype.h>
    #include<conio.h>
    #include<windows.h>
    #include<string.h>
    #include<bits/stdc++.h>
    #define INF 0x3f3f3f3f
    using namespace std;
    typedef pair<int, int> iPair;
    void adminlogin();
    void userlogin();
    void userInterface(vector<pair<int, int> > adj[]);
    void UserChoices(vector<pair<int, int> > adj[]);
    int walletDebit(int);
    int i=0,V=9;//vector<pair<int, int> > adj[9];
    int en,fare=0,username;
    fstream admin,cycleId,station,fi,f2;
    int a[9][5];
    void delay(int number_of_seconds)
    {
        int milli_seconds =  number_of_seconds;
        clock_t start_time = clock();
        while (clock() < start_time + milli_seconds);
    }
    void gotoxy(int x,int y)
    {
        COORD c;
        c.X=x;
        c.Y=y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
    }
    void SetColor(int ForgC)
    {
         WORD wColor;
         HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
         CONSOLE_SCREEN_BUFFER_INFO csbi;
         if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
         {
              wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
              SetConsoleTextAttribute(hStdOut, wColor);
         }
    }
    void boxing()
    {
        int i,j,k,l;
        system("cls");
        for(i=1;i<=79;i++)
        {
            gotoxy(i,2);
            cout<<char(178);
        }
        for(j=2;j<=28;j++)
        {
            gotoxy(1,j);
            cout<<char(178);
        }
        for(k=1;k<=79;k++)
        {
            gotoxy(k,29);
            cout<<char(178);
        }
        for(l=28;l>=2;l--)
        {
            gotoxy(79,l);
            cout<<char(178);
        }

    }
    void start()
    {
        boxing();
        while(1)
        {
            SetColor(8);
        gotoxy(16,i+=10);
        //printf("Press any key to continue");
        //getch();
        system("cls");
        boxing();
        gotoxy(16,i=0);
        SetColor(8);
        printf("\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2B2 CAMPUS ON WHEELS \xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2");
        gotoxy(16,i+=2);
        //printf("________________________________________________");
        gotoxy(16,i=6);
        printf("1. Administration Login");
        gotoxy(16,i+=2);
        printf("2. User Login");
        gotoxy(16,i+=2);
        cout<<"  Enter 0 to Exit ";
        gotoxy(16,i+=2);
        printf("Enter your Choice : ");
        int ch;
        cin>>ch;
        switch(ch)
        {
          case 1:
        system("cls");
        boxing();
        gotoxy(16,i=0);
        SetColor(8);
        printf("\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2B2 CAMPUS ON WHEELS \xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2");
        gotoxy(16,i+=2);
        //printf("________________________________________________");
        adminlogin();
          break;
          case 2:
        system("cls");
        gotoxy(16,i=0);
        SetColor(8);
        printf("\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2B2 CAMPUS ON WHEELS \xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2");
        gotoxy(16,i+=2);
        //printf("________________________________________________");
        userlogin();
          break;
          case 0:
            exit(0);
            }
        }
    }
    void adjustcycle(int s,int d)
    {
        int sums=0,sumd=0;
        sums=accumulate(a[s],a[s]+5,0);
        sumd=accumulate(a[d],a[d]+5,0);
        if(sums==0)
        {
            int k=0,flag=0;
            while(k<9)
            {
                if(k==s || k==d)
                    continue;
                int sum=0;
                sum=accumulate(a[k],a[k]+5,0);
                if(sum>1)
                {
                    for(int j=0;j<5;j++)
                    {
                        if(a[k][j]==1)
                        {
                            a[k][j]=0;a[s][0]=1;
                            flag=1;break;
                        }
                    }
                    if(flag==1)break;
                }
                    k++;
            }
        }
        if(sumd==5)
        {
            int k=0,flag=0;
            while(k<9)
            {
                if(k==s || k==d)
                    continue;
                int sum=0;
                sum=accumulate(a[k],a[k]+5,0);
                if(sum<4)
                {
                    for(int j=0;j<5;j++)
                    {
                        if(a[k][j]==0)
                        {
                            a[k][j]=1;a[d][0]=0;
                            flag=1;break;
                        }
                    }
                    if(flag==1)break;
                }
                    k++;
            }
        }

         station.open("jaadu.txt",ios::out | ios::trunc);
    for(int i=0;i<9;i++)
    {
        station<<i<<" "<<a[i][0]<<" "<<a[i][1]<<" "<<a[i][2]<<" "<<a[i][3]<<" "<<a[i][4]<<endl;
    }
        station.close();
    }
    void addEdge(vector<pair<int, int> > adj[],int u, int v, int wt)
    {
        adj[u].push_back(make_pair(v, wt));
        adj[v].push_back(make_pair(u, wt));
    }
    void Make_verices_forbicycle()
    {
        int V = 9;
        vector<pair<int, int> > adj[V];
        addEdge(adj,0, 1, 4);
        addEdge(adj,0, 7, 8);
        addEdge(adj,1, 2, 8);
        addEdge(adj,1, 7, 11);
        addEdge(adj,2, 3, 7);
        addEdge(adj,2, 8, 2);
        addEdge(adj,2, 5, 4);
        addEdge(adj,3, 4, 9);
        addEdge(adj,3, 5, 14);
        addEdge(adj,4, 5, 10);
        addEdge(adj,5, 6, 2);
        addEdge(adj,6, 7, 1);
        addEdge(adj,6, 8, 6);
        addEdge(adj,7, 8, 7);
        UserChoices(adj);
        //userInterface(adj);
    }
    void shortestPath(vector<pair<int, int> > adj[],int src,int des)
    {
        priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
        vector<int> dist(V, INF);
        vector<int> parent(V,0);
        pq.push(make_pair(0, src));
        dist[src] = 0;
        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            //list< iPair >::iterator it;
            for ( auto it = adj[u].begin(); it != adj[u].end(); ++it)
            {

                int v = (*it).first;
                int weight = (*it).second;
                if (dist[v] > dist[u] + weight)
                {
                    dist[v] = dist[u] + weight;
                    pq.push(make_pair(dist[v], v));
                    parent[v]=u;
                }
            }
        }
        gotoxy(16,i+=2);
        printf("Your station     Distance from target station\n");
        gotoxy(16,i+=1);
        cout<<src<<"\t\t\t"<<dist[des];
            cout<<endl;
            fare=dist[des]/2;
            int d=walletDebit(username);
            gotoxy(16,i+=2);
            cout<<"Your final wallet balance is:Rs "<<d<<endl;
            char var=des;
            string route="";
            route=des +48;
            while(parent[des]!=0)
            {
                route+=parent[des]+48;
                des=parent[des];
            }
            //cout<<src<<"->";
            gotoxy(16,i+=2);
            cout<<"ROUTE : ";
            gotoxy(16,i+=1);
            for(int j=route.length()-1;j>=1;j--)
                cout<<route[j]<<"->";
                cout<<route[0];
                gotoxy(16,i+=2);
                cout<<"PRESS ENTER TO CONTINUE";
                getch();

    }
    int shortestPathWithAlternate(vector<pair<int, int> > adj[],int src,int des)
    {
        priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
        vector<int> dist(V, INF);
        vector<int> parent(V,0);
        pq.push(make_pair(0, src));
        dist[src] = 0;
        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            //list< iPair >::iterator it;
            for ( auto it = adj[u].begin(); it != adj[u].end(); ++it)
            {

                int v = (*it).first;
                int weight = (*it).second;
                if (dist[v] > dist[u] + weight)
                {
                    dist[v] = dist[u] + weight;
                    pq.push(make_pair(dist[v], v));
                    parent[v]=u;
                }
            }
        }
        gotoxy(16,i+=2);
        printf("Your station     Distance from target station\n");
        gotoxy(16,i+=1);
        cout<<src<<"\t\t\t"<<dist[des];
        int distanceprint=dist[des];
            cout<<endl;
            fare=dist[des]/2;
            walletDebit(username);
            //cout<<"Your final wallet balance is:Rs "<<b<<endl;
            char var=des;
            string route="";
            route=des +48;
            while(parent[des]!=0)
            {
                route+=parent[des]+48;
                des=parent[des];
            }
            //cout<<src<<"->";
            gotoxy(16,i+=2);
            cout<<"ROUTE : ";
            gotoxy(16,i+=1);
            for(int j=route.length()-1;j>=1;j--)
                cout<<route[j]<<"->";
                cout<<route[0];
                getch();
                return distanceprint;

    }
    void AlternatePath(vector<pair<int, int> > adj[])
    {
        system("cls");
        boxing();
        gotoxy(16,0);
        printf("\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2B2 CAMPUS ON WHEELS \xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2");


        gotoxy(16,i=4);
        cout<<"Enter your station :";
        int stn,dst,alt;

        gotoxy(16,i+=1);
        cout<<"Enter your destination :";

        gotoxy(16,i+=1);
        cout<<"Enter the station on the alternate path : ";

        gotoxy(36,i=4);
        cin>>stn;
        gotoxy(40,i+=1);
        cin>>dst;
        gotoxy(58,i+=1);
        cin>>alt;

        station.open("jaadu.txt",ios::in);
        for(int j=0;j<9;j++)
        {
            station>>j>>a[j][0]>>a[j][1]>>a[j][2]>>a[j][3]>>a[j][4];
        }
        station.close();
        for(int j=0;j<5;j++)
        {
            if(a[stn][j]==1)
            {
                gotoxy(16,i+=2);
                cout<<"cycle no:"<<j+1;
                a[stn][j]=0;break;
            }
        }
        for(int j=0;j<5;j++)
        {
            if(a[dst][j]==0)
            {
                a[dst][j]=1;
                break;
            }
        }
        station.open("jaadu.txt",ios::out | ios::trunc);
        for(int j=0;j<9;j++)
        {
            station<<j<<" "<<a[j][0]<<" "<<a[j][1]<<" "<<a[j][2]<<" "<<a[j][3]<<" "<<a[j][4]<<endl;
        }
        station.close();
        adjustcycle(stn,dst);
        int d1=shortestPathWithAlternate(adj,stn,alt);
        int d2=shortestPathWithAlternate(adj,alt,dst);
        gotoxy(16,i+=2);
        cout<<"Total Distance = "<<d1+d2;
        delay(1000);
        delay(1000);
        fare=(d1+d2)/2;
       int d=walletDebit(username);
       gotoxy(16,i+=2);
        cout<<"Your final wallet balance is Rs "<<d<<endl;
        delay(1000);
        gotoxy(16,i+=2);
        cout<<"PRESS ENTER TO CONTINUE";
        getch();

    }
        void walletRecharge()
        {
            int e,r;
            system("cls");
        boxing();
        gotoxy(16,0);
        printf("\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2B2 CAMPUS ON WHEELS \xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2");
        gotoxy(16,i=6);
        cout<<"Enter your ENROLMENT NUMBER :";
        gotoxy(16,i+=2);
        cout<<"Enter the Amount :";
        gotoxy(46,i=6);
        cin>>e;
        gotoxy(34,i+=2);
        cin>>r;
        system("cls");
        boxing();
        gotoxy(16,0);
        printf("\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2B2 CAMPUS ON WHEELS \xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2");
        gotoxy(34,6);
        cout<<"LOADING.........";
        delay(3000);
        gotoxy(34,6);
        cout<<"DONE             ";
        delay(800);
        fstream f1;
        vector<pair<int , int> > v;
        f1.open("wallet.txt",ios::in);
        while(!f1.eof())
        {
            int x,y;
            f1>>x>>y;
            if(x==e)
            {
                y+=r;
            }
            v.push_back(make_pair(x,y));
        }
        f1.close();
        f1.open("wallet.txt",ios::trunc | ios::out);
        for(auto x:v)
            f1<<x.first<<" "<<x.second<<endl;
        f1.close();
    }
    void userInterface(vector<pair<int, int> > adj[])
    {
        system("cls");
        gotoxy(16,i=0);
        SetColor(8);
        system("cls");
        boxing();
        gotoxy(16,0);
        printf("\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2B2 CAMPUS ON WHEELS \xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2");


        gotoxy(16,i=6);
        cout<<"Enter your station.";
        int stn,dst;
        cin>>stn;
        gotoxy(16,i+=2);
        cout<<"Enter your destination.";
        cin>>dst;
        station.open("jaadu.txt",ios::in);
        for(int j=0;j<9;j++)
        {
            station>>j>>a[j][0]>>a[j][1]>>a[j][2]>>a[j][3]>>a[j][4];
        }
        station.close();
        for(int j=0;j<5;j++)
        {
            if(a[stn][j]==1)
            {
                gotoxy(16,i+=2);
                cout<<"cycle no:"<<j+1;
                a[stn][j]=0;
                break;
            }
        }
        for(int j=0;j<5;j++)
        {
            if(a[dst][j]==0)
            {
                a[dst][j]=1;
                break;
            }
        }
        station.open("jaadu.txt",ios::out | ios::trunc);
        for(int j=0;j<9;j++)
        {
            station<<j<<" "<<a[j][0]<<" "<<a[j][1]<<" "<<a[j][2]<<" "<<a[j][3]<<" "<<a[j][4]<<endl;
        }
        station.close();
        adjustcycle(stn,dst);
                shortestPath(adj,stn,dst);

    }
    void UserChoices(vector<pair<int, int> > adj[])
    {

            system("cls");
               gotoxy(16,i=0);
               system("cls");
            boxing();
            gotoxy(16,0);
            printf("\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2B2 CAMPUS ON WHEELS \xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2");
            gotoxy(16,i=6);
            cout<<"1. Enter for Shortest Path";
             gotoxy(16,i+=2);
             cout<<"2. Enter for alternate path";
            gotoxy(16,i+=2);
            cout<<"Enter 0 to exit";
            int ch;
             gotoxy(16,i+=2);
             cout<<"Enter your choice: " ;
             cin>>ch;
             switch(ch)
             {
             case 1:
                 userInterface(adj);
                break;
             case 2:
                 AlternatePath(adj);
                break;
             case 3:
                break;
             }
    }
    void adminenterintofile()
    {
        system("cls");
        boxing();
        gotoxy(16,0);
        printf("\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2B2 CAMPUS ON WHEELS \xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2");
       // int en;
        gotoxy(16,i=6);
        cout<<"Enter the \"ENROLMENT NUMBER\" to be registered : ";
        cin>>en;
        admin.open("Administrator.txt",ios::app);
        admin<<en<<endl;
        admin.close();
        system("cls");
    }
    void maintain()
    {
        fstream f1;
        f1.open("CycleMaintain.txt",ios::in);
        while(!f1.eof())
        {
            int x,y;
            f1>>x>>y;
            cout<<x<<" "<<y<<endl;
        }
    }
    void userlogin()
    {
        system("cls");
        boxing();
        gotoxy(16,0);
        printf("\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2B2 CAMPUS ON WHEELS \xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2");

        vector<int>v;
        int j;
        //int username;
        char userpwd[4];
        gotoxy(16,i=6);
        cout<<"Enter your UserID(ENROLMENT NUMBER) : ";
        cin>>username;
        fstream f1;
        f1.open("Administrator.txt",ios::in);
        while(!f1.eof())
        {
            int x;
            f1>>x;
            v.push_back(x);
        }
        auto it=find(v.begin(),v.end(),username);
        if(it!=v.end())
        {
            gotoxy(16,i+=2);
            cout<<"HELLO!!! "<<username;
            delay(1000);
                        fstream bal;
            bal.open("wallet.txt",ios::in);
            while(!bal.eof())
            {
                int val1,val2;
                bal>>val1>>val2;
                if(val1==username)
                {
                    if(val2<5)
                        {
                            gotoxy(16,i+=2);
                        cout<<"Insufficient balance minimum Rs 5 balance required"<<endl;
                        delay(1000);
                        start();
                        }

                }
            }
            Make_verices_forbicycle();
        }
        else
        {
            gotoxy(16,i+=2);
           cout<<"ENROLLMENT NO. Not Registered : Please Register";
           gotoxy(16,i+=2);
           cout<<"PRESS ENTER TO CONTINUE";
           getch();
        }

    }
    void resetstands()
    {

        fi.open("jaadu.txt",ios::trunc | ios::out);

        int a[9][5],c=0;
        memset(a,0,sizeof(a));
        for(int i=0;i<9;i++)
        {
            fi<<i<<" "<<1<<" "<<1<<" "<<1<<" "<<0<<" "<<0<<endl;
        }
        fi.close();
    }
    void walletCreate()
      {
        fstream wlt,a;
        wlt.open("wallet.txt",ios::app);
        int defAmt=20;
        wlt<<en<<" "<<defAmt<<endl;
        wlt.close();
      }
    int walletDebit(int enroll)
    {
        fstream wlt;
        wlt.open("wallet.txt",ios::in);
        vector<pair<int , int>> bal;int c=0,a,b,d;
        while(!wlt.eof())
        {

            wlt>>a>>b;
            if(a==enroll)
           {
               b=b-fare;
               d=b;
               bal.push_back(make_pair(a,b));
               //cout<<"Your wallet balance is: Rs "<<b<<endl;
           }
            else
            {
                bal.push_back(make_pair(a,b));
            }
            c++;
        }
        wlt.close();
        wlt.open("wallet.txt",ios::trunc | ios::out);
        for(auto x:bal)
        {
            if(c==1)
                break;
            c-- ;
                wlt<<x.first<<" "<<x.second<<endl;
        }
        wlt.close();
        return d;
    }
    void adminlogin()
    {
         int ch;
        char username[20];
        char password[8];
        gotoxy(16,i+=2);
        cout<<"Enter your Username : ";

        gotoxy(16,i+=2);
        cout<<"Enter your Password : ";//password has to be of 6 characters
        gotoxy(38,i-=2);
        cin>>username;
        gotoxy(38,i+=2);
         for(int j=0;j<8;j++)
        {
           password[j]=getch();
           cout<<"*";
        }
        //cout<<password;
        gotoxy(16,i+=2);
        printf("Press any key to continue");
        getch();

    if(!strcmp(username,"tanmay") && !strcmp(password,"12345678tanmay"))
     {
        gotoxy(16,i+=2);
        printf("Logged In Successful");
        delay(500);
        system("cls");
        do
        {
            boxing();
            gotoxy(16,0);
            printf("\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2B2 CAMPUS ON WHEELS \xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2\xDB2");

            gotoxy(16,i=6);
            cout<<"1. Maintenance of the stands";
            gotoxy(16,i+=2);
            cout<<"2. Enter to add new students";
            gotoxy(16,i+=2);
            cout<<"3. Recharge Wallet";
            gotoxy(16,i+=2);
            cout<<"  Enter 0 to exit ";
            gotoxy(16,i+=2);
            cout<<"Enter your choice :";
            cin>>ch;
            switch (ch)
            {
                case 1:
                resetstands();
                break;
                case 2:
                adminenterintofile();
                walletCreate();
                break;
                case 3:
                    walletRecharge();
                    break;
             }
        }while(ch);

         }
         else
         {
             gotoxy(16,i+=2);
             printf("Incorrect username or password");
             getch();
         }
    }
    int main()
    {
        system("COLOR F2");
        start();
    }
