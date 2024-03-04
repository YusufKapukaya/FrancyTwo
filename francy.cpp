#include <iostream>
#include <string>
#include "francy.h"


void simplification(Francy& frc)
{
    int smallNum=0;
    (frc.nom)<(frc.denom) ? smallNum=(frc.nom) : smallNum=(frc.denom);
    for(int i=2; i<=smallNum; i++)
    {
        while((frc.nom)%i==0 && (frc.denom)%i==0)
        {
            (frc.nom)=(frc.nom)/i;
            frc.denom/=i;
        }
    }

}



void simplificationPointer(Francy* frc)
{
    int smallNum=0;
    (frc->nom)<(frc->denom) ? smallNum=(frc->nom) : smallNum=(frc->denom);
    for(int i=2; i<=smallNum; i++)
    {
        while((frc->nom)%i==0 && (frc->denom)%i==0)
        {
            (frc->nom)=(frc->nom)/i;
            frc->denom/=i;
        }
    }
}
int Francy::getNom()
{
    return nom;
}
int Francy::getDenom()
{
    return denom;
}

void Francy::setNom(const int a)
{
    nom =a;
}
void Francy::setDenom(const int a)
{
    denom =a;
}

bool Francy::operator<(const Francy* other)
{
    if(other->denom==this->denom)
    {
        if(this->nom<other->denom )
        {
            return true;
        }else{
            return false;
        };
    }
    else
    {
        return ((this->nom*other->denom)<(this->denom*other->nom) ? true : false);
    }
}

bool Francy::operator==(const Francy& other)
{
    if(other.denom==this->denom)
    {
        if(this->nom==other.nom) return true;
        return false;
    }
    else
    {
        return ((this->nom*other.denom)==(this->denom*other.nom) ? true : false);
    }
}

Francy Francy::operator*=(const Francy& other)
{
    this->nom*=other.nom;
    this->denom*=other.denom;
    simplificationPointer(this);
}

Francy Francy::operator+=(const Francy& other)
{
    if(this->denom==other.denom)
    {
        this->nom+=other.nom;
    }
    else
    {
        this->nom=(this->nom*other.denom)+((this->denom)*(other.nom));
        this->denom=this->denom*other.denom;
    }
    simplification(*this);
}


Francy::Francy(int Nom, int Denom):nom{Nom},denom{Denom}
{
    int result;
    result=nom%denom;
    if(result==0)
    {
        nom/=denom;
        denom=1;
    }
    else
    {
        simplification(*this);
    }
    cout<<"You have wrote "<<nom<<"/"<<denom<<endl;
}

Francy* Francy::operator+(const Francy* other)const
{
    Francy* temp;

    if(denom==other->denom)
    {
        temp->nom=nom+other->nom;
        temp->denom=denom;
    }
    else
    {
        temp->nom=(nom*other->denom)+(other->nom*denom);
        temp->denom=denom*other->denom;
    }
    simplificationPointer(temp);
    cout<<temp->nom<<"/"<<temp->denom<<endl;
    return temp;
}


Francy Francy::operator-(const Francy& other)const
{
    Francy temp;

    if(denom==other.denom)
    {
        temp.nom=nom-other.nom;
        temp.denom=denom;
    }
    else
    {
        temp.nom=(nom*other.denom)-(other.nom*denom);
        temp.denom=denom*other.denom;
    }
    simplification(temp);
    cout<<temp.nom<<"/"<<temp.denom<<endl;
    return temp;
}

Francy Francy::operator*(const Francy& other)const
{
    Francy temp;
    temp.nom=nom*(other.nom);
    temp.denom=denom*(other.denom);
    simplification(temp);
    cout<<temp.nom<<"/"<<temp.denom<<endl;
    return temp;
}

Francy Francy::operator/(const Francy& other)const
{
    Francy temp;
    temp.nom=nom*(other.denom);
    temp.denom=denom*(other.nom);
    simplification(temp);
    cout<<temp.nom<<"/"<<temp.denom<<endl;
    return temp;
}


Francy::Francy(const Francy& frc):nom{frc.nom},denom{frc.denom}
{
    simplification(*this);
    cout<<"I am hier";
}

Francy::Francy(Francy&& frc)
{
    nom=frc.nom;
    denom=frc.denom;

    frc.nom=0;
    frc.denom=0;
    simplification(*this);
}

Francy& Francy::operator=(Francy&& frc)
{
    if(this!=&frc)
    {
        nom=frc.nom;
        denom=frc.denom;

        frc.nom=0;
        frc.denom=0;
        simplification(*this);
    }
    return *this;
}

Francy::operator bool()const
{
    return this->nom ? true : false;
}


ostream& operator<<(ostream& os, const Francy& frc)
{
    return os<<frc.nom<<"/"<<frc.denom<<endl;
}


//How cann I declarien istream !


istream& operator>>(istream& is, const Francy& frc)
{
    return is>>frc.nom>>frc.denom;
}


void Francy::operator()(const Francy& other, const int a)
{
    if(this->denom==other.denom)
    {
        this->nom+=other.nom;
    }
    else
    {
        this->nom=((this->nom*other.denom)+(this->denom*other.nom)+a);
        this->denom=(this->denom*other.denom);
    }
    simplification(*this);
    cout<<*this;
}


Francy& Francy::operator=(const Francy& frc)
{
    cout<<"Copy Assigment has called."<<endl;
    nom=frc.nom;
    denom=frc.denom;
    simplification(*this);
    return *this;
}



