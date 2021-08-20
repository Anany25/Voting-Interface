#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<fstream>
#include"data.h"

using namespace std;

int max_vote_to(int A[]);
void get_result();
void generate_result();

vector<string> party={"A","B","C","None"};
vector<int> votedList;
int inputID,currentID;
int partyChoice,choice2;
int p1=0,p2=0,p3=0,p4=0;
int m=0,m1=0,m2=0,m3=0,m4=0;
int f=0,f1=0,f2=0,f3=0,f4=0;
int age18=0,age_30=0,age_50=0,age_70=0,age_100=0,age_100p=0;
int age18m[4]={0,0,0,0};
int age_30m[4]={0,0,0,0};
int age_50m[4]={0,0,0,0};
int age_70m[4]={0,0,0,0};
int age_100m[4]={0,0,0,0};
int age_100pm[4]={0,0,0,0};

int main()
{
    bool exist;
    L1:
        exist= false;
        cout<<"Enter Voter ID number:";
        cin>>inputID;
        for(int i=0;i<votedList.size();i++)
        {
            if(votedList[i]==inputID)
            {
                cout<<"Already Voted! Input Another:\n";
                goto L1;
            }
            else
            {
                continue;
            }
        }
        for(int i=0;i<sizeof(data);i++)
        {
            if(data[i][0]==inputID)
            {
                currentID=i;
                exist=true;
            }
        }
        if(exist==false)
        {
            system("cls");
            cout<<"Input ID does not exist! Try Again.\n";
            goto L1;
        }
        L2:
            system("cls");
            cout<<"Enter 1 to vote for "<<party[0]<<endl;
            cout<<"Enter 2 to vote for "<<party[1]<<endl;
            cout<<"Enter 3 to vote for "<<party[2]<<endl;
            cout<<"Enter 4 to vote for "<<party[3]<<endl<<endl;
            cin>>partyChoice;
            if(partyChoice==1)
            {
                p1++;
            }
            else if(partyChoice==2)
            {
                p2++;
            }
            else if(partyChoice==3)
            {
                p3++;
            }
            else if(partyChoice==4)
            {
                p4++;
            }
            else
            {
                system("cls");
                cout<<"Invalid entry! Try Again.\n\n";
                goto L2;
            }
            votedList.push_back(inputID);
            if(data[currentID][2]==0)
            {
                m++;

                if(partyChoice==1)
                {
                    m1++;
                }
                else if(partyChoice==2)
                {
                    m2++;
                }
                else if(partyChoice==3)
                {
                    m3++;
                }
                else if(partyChoice==4)
                {
                    m4++;
                }
            }
            else
            {
                f++;

                if(partyChoice==1)
                {
                    f1++;
                }
                else if(partyChoice==2)
                {
                    f2++;
                }
                else if(partyChoice==3)
                {
                    f3++;
                }
                else if(partyChoice==4)
                {
                    f4++;
                }
            }
            if(data[currentID][1]==18)
            {
                age18++;
                if(partyChoice==1)
                {
                    age18m[0]++;
                }
                else if(partyChoice==2)
                {
                    age18m[1]++;
                }
                else if(partyChoice==3)
                {
                    age18m[2]++;
                }
                else if(partyChoice==4)
                {
                    age18m[3]++;
                }
            }
            else if(data[currentID][1]>18&&data[currentID][1]<=30)
            {
                age_30++;
                if(partyChoice==1)
                {
                    age_30m[0]++;
                }
                else if(partyChoice==2)
                {
                    age_30m[1]++;
                }
                else if(partyChoice==3)
                {
                    age_30m[2]++;
                }
                else if(partyChoice==4)
                {
                    age_30m[3]++;
                }
            }
            else if(data[currentID][1]>30&&data[currentID][1]<=50)
            {
                age_50++;
                if(partyChoice==1)
                {
                    age_50m[0]++;
                }
                else if(partyChoice==2)
                {
                    age_50m[1]++;
                }
                else if(partyChoice==3)
                {
                    age_50m[2]++;
                }
                else if(partyChoice==4)
                {
                    age_50m[3]++;
                }
            }
            else if(data[currentID][1]>50&&data[currentID][1]<=70)
            {
                age_70++;
                if(partyChoice==1)
                {
                    age_70m[0]++;
                }
                else if(partyChoice==2)
                {
                    age_70m[1]++;
                }
                else if(partyChoice==3)
                {
                    age_70m[2]++;
                }
                else if(partyChoice==4)
                {
                    age_70m[3]++;
                }
            }
            else if(data[currentID][1]>70&&data[currentID][1]<=100)
            {
                age_100++;
                if(partyChoice==1)
                {
                    age_100m[0]++;
                }
                else if(partyChoice==2)
                {
                    age_100m[1]++;
                }
                else if(partyChoice==3)
                {
                    age_100m[2]++;
                }
                else if(partyChoice==4)
                {
                    age_100m[3]++;
                }
            }
            else if(data[currentID][1]>100)
            {
                age_100p++;
                if(partyChoice==1)
                {
                    age_100pm[0]++;
                }
                else if(partyChoice==2)
                {
                    age_100pm[1]++;
                }
                else if(partyChoice==3)
                {
                    age_100pm[2]++;
                }
                else if(partyChoice==4)
                {
                    age_100pm[3]++;
                }
            }
            L3:
                system("cls");
                if(sizeof(data)/sizeof(data[0])==votedList.size())
                {
                    get_result();
                }
                cout<<"Enter 1 to continue voting:\nEnter 2 to get results:\n";
                cin>>choice2;
                if(choice2==1)
                {
                    goto L1;
                }
                else if(choice2==2)
                {
                    get_result();
                    generate_result();
                }
                else
                {
                    cout<<"Invalid Input! Try again.";
                    goto L3;
                }

}
int max_vote_to(int A[])
{
    int i,m=0,index;
    for(i=0;i<3;i++)
    {
        if(A[i]>m)
        {
            m=A[i];
            index=i;
        }
    }
    if(m==0)
    {
        index=3;
    }
    return index;
}


void get_result()
{
    system("cls");
    cout<<"RESULT:"<<endl<<endl;
    cout<<"Party "<<party[0]<<" Votes : "<<p1<<endl;
    cout<<"Party "<<party[1]<<" Votes : "<<p2<<endl;
    cout<<"Party "<<party[2]<<" Votes : "<<p3<<endl;
    cout<<"None of the above : "<<p4<<endl<<endl;

    if((static_cast<float>(p1)/(m+f))*100>50)
    {
        cout<<"Party "<<party[0]<<" wins by majority!"<<endl<<endl;
    }
    else if((static_cast<float>(p2)/(m+f))*100>50)
    {
        cout<<"Party "<<party[1]<<" wins by majority!"<<endl<<endl;
    }
    else if((static_cast<float>(p3)/(m+f))*100>50)
    {
        cout<<"Party "<<party[2]<<" wins by majority!"<<endl<<endl;
    }
    else
    {
        cout<<"No Party Wins by Majority"<<endl<<endl;
    }
        cout<<"REPORT:"<<endl<<endl;
        cout<<"Total Votes: "<<m+f<<endl;
        cout<<"Male Votes: "<<m<<endl;
        cout<<"Female Votes: "<<f<<endl<<endl;
        cout<<"Male Votes to "<<party[0]<<": "<<m1<<endl;
        cout<<"Male Votes to "<<party[1]<<": "<<m2<<endl;
        cout<<"Male Votes to "<<party[2]<<": "<<m3<<endl;
        cout<<"Male Votes to "<<party[3]<<": "<<m4<<endl<<endl;
        cout<<"Female Votes to "<<party[0]<<": "<<f1<<endl;
        cout<<"Female Votes to "<<party[1]<<": "<<f2<<endl;
        cout<<"Female Votes to "<<party[2]<<": "<<f3<<endl;
        cout<<"Female Votes to "<<party[3]<<": "<<f4<<endl<<endl;
        cout<<"New Voters: "<<age18<<"\t\tMajority vote to: "<<party[max_vote_to(age18m)]<<endl;
        cout<<"Age Group 19-30: "<<age_30<<"\tMajority vote to: "<<party[max_vote_to(age_30m)]<<endl;
        cout<<"Age Group 31-50: "<<age_50<<"\tMajority vote to: "<<party[max_vote_to(age_50m)]<<endl;
        cout<<"Age Group 51-70: "<<age_70<<"\tMajority vote to: "<<party[max_vote_to(age_70m)]<<endl;
        cout<<"Age Group 71-100: "<<age_100<<"\tMajority vote to: "<<party[max_vote_to(age_100m)]<<endl;
        cout<<"Aged Above 100: "<<age_100p<<"\tMajority vote to: "<<party[max_vote_to(age_100pm)]<<endl;
}

void generate_result()
{
    ofstream resultFile;

    string resultFileName = "Result.txt";

    resultFile.open(resultFileName);

    if(resultFile.is_open())
    {
        resultFile<<"RESULT:"<<endl<<endl;
        resultFile<<"Party "<<party[0]<<" Votes : "<<p1<<endl;
        resultFile<<"Party "<<party[1]<<" Votes : "<<p2<<endl;
        resultFile<<"Party "<<party[2]<<" Votes : "<<p3<<endl;
        resultFile<<"None of the above : "<<p4<<endl<<endl;

        if((static_cast<float>(p1)/(m+f))*100>50)
        {
            resultFile<<"Party "<<party[0]<<" wins by majority!"<<endl<<endl;
        }
        else if((static_cast<float>(p2)/(m+f))*100>50)
        {
            resultFile<<"Party "<<party[1]<<" wins by majority!"<<endl<<endl;
        }
        else if((static_cast<float>(p3)/(m+f))*100>50)
        {
            resultFile<<"Party "<<party[2]<<" wins by majority!"<<endl<<endl;
        }
        else
        {
            resultFile<<"No Party Wins by Majority"<<endl<<endl;
        }
            resultFile<<"REPORT:"<<endl<<endl;
            resultFile<<"Total Votes: "<<m+f<<endl;
            resultFile<<"Male Votes: "<<m<<endl;
            resultFile<<"Female Votes: "<<f<<endl<<endl;
            resultFile<<"Male Votes to "<<party[0]<<": "<<m1<<endl;
            resultFile<<"Male Votes to "<<party[1]<<": "<<m2<<endl;
            resultFile<<"Male Votes to "<<party[2]<<": "<<m3<<endl;
            resultFile<<"Male Votes to "<<party[3]<<": "<<m4<<endl<<endl;
            resultFile<<"Female Votes to "<<party[0]<<": "<<f1<<endl;
            resultFile<<"Female Votes to "<<party[1]<<": "<<f2<<endl;
            resultFile<<"Female Votes to "<<party[2]<<": "<<f3<<endl;
            resultFile<<"Female Votes to "<<party[3]<<": "<<f4<<endl<<endl;
            resultFile<<"New Voters: "<<age18<<"\t\tMajority vote to: "<<party[max_vote_to(age18m)]<<endl;
            resultFile<<"Age Group 19-30: "<<age_30<<"\tMajority vote to: "<<party[max_vote_to(age_30m)]<<endl;
            resultFile<<"Age Group 31-50: "<<age_50<<"\tMajority vote to: "<<party[max_vote_to(age_50m)]<<endl;
            resultFile<<"Age Group 51-70: "<<age_70<<"\tMajority vote to: "<<party[max_vote_to(age_70m)]<<endl;
            resultFile<<"Age Group 71-100: "<<age_100<<"\tMajority vote to: "<<party[max_vote_to(age_100m)]<<endl;
            resultFile<<"Aged Above 100: "<<age_100p<<"\tMajority vote to: "<<party[max_vote_to(age_100pm)]<<endl;

            resultFile.close();
        }
        else
        {
            resultFile<<"\nWARNING! : Could not generate result file!";
        }
}
