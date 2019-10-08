/*
name Aditya Gupta
The object of the game is for the player to find their way out of a challenging maze before their opponent. 
-->Users can play as single player and compete against the computer or play against a friend in two player mode.
-->In this this there will be exit and a starting point.

*/

#include <iostream>

using namespace std;
int stackA[100],stackB[100] ;//stackA for rows and stackb for columns
int topa=-1,topb=-1;
bool check(int a,int b)
{
    int i;
    if(topa>=0)
    {
        for(i=topa;i>=0;i--)
        {
            if(stackA[i]==a&&stackB[i]==b)
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        return true;
    }
}
void pushA(int a)
{
    if(topa==40)
    {
        cout<<"stackA is full";
        return;
    }
    else
    {
        stackA[++topa]=a;
    }
}
void pushB(int b)
{
    if(topb==40)
    {
        cout<<"stackB is full";
        return;
    }
    else
    {
        stackB[++topb]=b;
    }
}
int popA()
{
    if(topa==-1)
    {
        cout<<"stackA is empty";
    } 
    else
    {
        return stackA[topa--];
    }
}
int popB()
{
    if(topb==-1)
    {
        cout<<"stackB is empty";
    }
    else
    {
        return stackB[topb--];
    }
}
int main()
{
    int n,i,j,visiti=-1,visitj=-1,a;
    cout<<"enter the size of square maze"<<endl;
    cin>>n;
    int maze [n+2][n+2];
    cout<<"enter the maze"<<endl;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            cin>>maze[i][j];
    for(i=0;i<n+2;i++)
        maze[0][i]=0;
    for(i=0;i<n+2;i++)
        maze[i][0]=0;
    for(i=0;i<n+2;i++)
        maze[n+1][i]=0;
     for(i=0;i<n+2;i++){
        maze[i][n+1]=0;
        }
    cout<<endl;
    
    if(maze[1][1]==0)
    {
        cout<<"enter a valid matrix"<<endl;
    }
    else
    {
        i=1;
        j=1;
        while(true)
        {
            if(i==n&&j==n)
            {
                break;
            }
            if(maze[i-1][j]==1&&(i-1!=visiti)&&(check(i,j)))
            {
                a=1;
                visiti=i;
                visitj=j;
                pushA(i);
                pushB(j);
                i=i-1;
                continue;
            }
             if(maze[i][j+1]==1&&(j+1!=visitj)&&(check(i,j)))
            {
                a=2;
                visiti=i;
                visitj=j;
                pushA(i);
                pushB(j);
                j=j+1;
                continue;
            }
             if(maze[i+1][j]==1&&(i+1!=visiti)&&(check(i,j)))
            {
                a=3;
                visiti=i;
                visitj=j;
                pushA(i);
                pushB(j);
                i=i+1;
                continue;
            }
             if(maze[i][j-1]==1&&(j-1!=visitj)&&(check(i,j)))
            {
                a=4;
                visiti=i;
                visitj=j;
                pushA(i);
                pushB(j);
                 j=j-1;
                continue;
            }
            else
            {
                maze[i][j]=0;
                i=popA();
                j=popB();
                if(a==1)
                {
                    visiti=i+1;
                    visitj=j;
                }
                if(a==2)
                {
                  visiti=i;
                    visitj=j-1;  
                }
                if(a==3)
                {
                    visiti=i-1;
                    visitj=j;
                }
                if(a==4)
                {
                    visiti=i;
                    visitj=j+1;
                }
            }
        }
        cout<<"the path  is(final point to initial point) "<<endl;
        cout<<"("<<i<<","<<j<<")"<<"<--";
        while(topa!=0)
        {
            cout<<"("<<popA()<<","<<popB()<<")"<<"<--";
        }
        cout<<"("<<popA()<<","<<popB()<<")";
    }
    return 0;
}
