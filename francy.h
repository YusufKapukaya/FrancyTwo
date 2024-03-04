

using namespace std;

class Francy
{
    int nom;
    int denom;
    double result;
public:
    Francy()=default;
    Francy(int Nom, int Denom=1);
    Francy(const Francy& frc);
    Francy(Francy&& frc);
    Francy& operator=(const Francy& frc);
    Francy& operator=(Francy&& frc);

    int getNom();
    int getDenom();

    void setNom(const int a);
    void setDenom(const int a);

    explicit operator bool()const;

    Francy* operator+(const Francy* other)const;
    Francy operator-(const Francy& other)const;
    Francy operator*(const Francy& other)const;
    Francy operator/(const Francy& other)const;

    void operator()(const Francy& other, const int a=1);

    Francy operator+=(const Francy& other);
    Francy operator*=(const Francy& other);

    bool operator<(const Francy* other);
    bool operator==(const Francy& other);


    friend ostream& operator<<(ostream& os, const Francy& frc);
    friend istream& operator>>(istream& is, const Francy& frc);
    friend void simplification(Francy& frc);
    friend void simplificationPointer(Francy* frc);
};
