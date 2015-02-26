#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void afficherVectorInt(vector<vector<int> > Subs)
{
    for(int i=0; i<Subs.size(); i++)
    {
        for(int j=0; j<Subs[i].size(); j++)
            cout<<Subs[i][j]<<" ";
        cout<<endl;
    }
}

void ecritureFichier(vector<vector<int> > Subs)
{
    ofstream fichier("test.txt", ios::out | ios::trunc);  //déclaration du flux et ouverture du fichier
    int somme;
    if(fichier)  // si l'ouverture a réussi
    {
        //On écrit la fonction objective
        fichier<<"minimize p = ";
        for(int i=0; i<Subs.size(); i++)
        {
            somme=0;
            for(int j=0; j<Subs[i].size(); j++)
                somme+= Subs[i][j];
            if(i!= Subs.size()-1)
                fichier<<somme<<"x"<<i+1<<" + ";
            else
                fichier<<somme<<"x"<<i+1<<" ";
        }
        fichier<<" subject to"<<endl;
        
        //Il faut rajouter que chaque variable est entre 0 et 1
        for(int i=0; i<Subs.size(); i++)
        {
            fichier<<"x"<<i+1<<" <= 1"<<endl;
            fichier<<"x"<<i+1<<" >= 0"<<endl;
        }
        
        
        
        fichier.close();  // on referme le fichier
    }
    else  // sinon
        cerr << "Erreur à l'ouverture !" << endl;
    

}
                     
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
        ecritureFichier(Subs);
        afficherVectorInt(Subs);
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