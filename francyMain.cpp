//#include "francy.h"
#include "francy.cpp"
#include <vector>

using namespace std;

int main()
{
    int k=0;
    Francy** frc=new Francy*[2];
    while(int i=1)
    {

        int c=0;
        cout<<"to Create a new Francy class press to 0"<<endl
            <<"to show of Francs elements press 1"<<endl
            <<"to '<' of Francs number press 2"<<endl
            <<"to '=' of Francs number press 3"<<endl
            <<"to 'bool' of Francs number press 4"<<endl
            <<"to '+' of Francs number press 5"<<endl
            <<"to '-' of Francs number press 6"<<endl
            <<"to cout of Francs number press 7"<<endl
            <<"to creat a new Francs press 8"<<endl
            <<"to end of Program press 9"<<endl
            <<"What do you want?"<<endl;
        cin>>c;
        if(c==0)
        {
            try
            {
                if(k<2)
                {
                    frc[k]=new Francy;
                    int a;
                    cout<<"A new Class will be created. Please give nom and denom of "<<(k+1)<<". Francy"<<endl;
                    cout<<"Give a nom:"<<endl;
                    cin>>a;
                    frc[k]->setNom(a);
                    cout<<"Give a denom:"<<endl;
                    cin>>a;
                    frc[k]->setDenom(a);
                    cout<<*frc[k]<<endl;
                    k++;
                }
                else
                {
                    throw(k);
                }
            }
            catch(...)
            {
                cout<<"you cann creat only to 2 Element."<<endl;
            }

        }
        else if(c==1)
        {
            for(int i=0; i<2; i++)
            {
                cout<<"Nom and Denom of "<<(i+1)<<". element"<<endl;
                cout<<*frc[i];
            }
        }
        else if(c==2)
        {
            int t;
            cout<<"do you want compare first Francy to second Francy if so press to one or for vice versa press to two?"<<endl;
            cin>>t;
            if(t==1)
            {
                cout<<boolalpha<<(frc[1]<frc[2])<<endl;
            }
            else
            {
                cout<<boolalpha<<(frc[2]<frc[1])<<endl;
            }
        }
        else if(c==3)
        {
            cout<<boolalpha<<(frc[1]==frc[2])<<endl;
        }
        else if(c==4)
        {
            if(frc[0]) cout<<"first Francy is pozitif."<<endl;
            else cout<<"first Francy is negatif."<<endl;
            if(frc[1]) cout<<"second Francy is pozitif."<<endl;
            else cout<<"second Francy is negatif."<<endl;
        }
        else if(c==5)
        {
            Francy* temp;
            temp=frc[0]+frc[1];
            //cout<<*temp;
        }
        else if(c==9) break;

    }
}
