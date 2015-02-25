#include <iostream>
#include <vector>

using namespace std;

void FindSubs(vector<vector<int> > Subs, int* S, int n, int etape)
{
    if(etape!= n)
    {
        int taille=Subs.size();
        for(int i=0; i<taille; i++)
        {
            vector<int> ajout;
            for(int j=0; j<Subs[i].size(); j++)
                ajout.push_back(Subs[i][j]);
            Subs.push_back(ajout);
        }
        
        for(int i=0; i<taille; i++)
        {
            Subs[i].push_back(S[etape]);
        }
        vector<int> temp;
        temp.push_back(S[etape]);
        Subs.push_back(temp);
        FindSubs(Subs,S,n,etape+1);
    }
    
    else
    {
        for(int i=0; i<Subs.size(); i++)
        {
            for(int j=0; j<Subs[i].size(); j++)
            {
                cout<<Subs[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<Subs.size();;
    }
}

int main (int argc, char** argv){
    int n=6;
    int S[6]={3,1,1,2,2,1};
    vector<vector<int> > Subs;
    FindSubs(Subs,S,n,0);
    
    for(int i=0; i<Subs.size(); i++)
    {
        for(int j=0; j<Subs[i].size(); j++)
        {
            cout<<Subs[i][j]<<" ";
        }
        cout<<endl;
    }

}