#include <iostream>
#include <string.h>
#include<ctime>
#include<vector>
using namespace std;

class Medic{
    char* numeDoctor;
    char* specializare;
    int salariu;
    bool iaSpaga;
public:
    Medic();
    Medic(char* numeDoctor, char* specializare, int salariu, bool iaSpaga);
    Medic(char* numeDoctor, char* specializare, bool iaSpaga);
    Medic(char* numeDoctor, char* specializare);
    Medic(const Medic& obj);

    Medic& operator = (const Medic& obj);
    friend istream& operator >> (istream& in, Medic& obj);
    friend ostream& operator << (ostream& out, const Medic& obj);
    bool operator == (const Medic& obj);
    bool operator < (const Medic& obj);
    bool operator > (const Medic& obj);
    Medic& operator += (const Medic& obj);
    Medic& operator -= (const Medic& obj);
    Medic operator + ( Medic obj);
    Medic operator + (int x);
    friend Medic operator + (int x, Medic obj);
    Medic operator - ( Medic obj);
    Medic operator - (int x);
    friend Medic operator - (int x, Medic obj);
    Medic& operator ++ ();
    Medic operator ++ (int x);
    char operator [] (int i);
    operator string();


    int getSalariu(){return salariu;}
    const char* getNume() const {return numeDoctor;}
    bool getSpaga(){return iaSpaga;}
    void setSalariu(){salariu = 0;}
    void setNume();

    bool consultatie();

    ~Medic();
};

Medic :: Medic()
{
    this->numeDoctor = new char[strlen("cineva") + 1];
    strcpy(this->numeDoctor, "cineva");
    this->specializare = new char[strlen("ceva") + 1];
    strcpy(this->specializare, "ceva");
    this->salariu = 0;
    this->iaSpaga = false;
}
Medic :: Medic(char* numeDoctor, char* specializare, int salariu, bool iaSpaga)
{
    this->numeDoctor = new char[strlen(numeDoctor) + 1];
    strcpy(this->numeDoctor, numeDoctor);
    this->specializare = new char[strlen(specializare) + 1];
    strcpy(this->specializare, specializare);
    this->salariu = salariu;
    this->iaSpaga = iaSpaga;
}

Medic :: Medic(char* numeDoctor, char* specializare, bool iaSpaga)
{
    this->numeDoctor = new char[strlen(numeDoctor) + 1];
    strcpy(this->numeDoctor, numeDoctor);
    this->specializare = new char[strlen(specializare) + 1];
    strcpy(this->specializare, specializare);
    this->salariu = 0;
    this->iaSpaga = iaSpaga;
}

Medic :: Medic(char* numeDoctor, char* specializare)
{
    this->numeDoctor = new char[strlen(numeDoctor) + 1];
    strcpy(this->numeDoctor, numeDoctor);
    this->specializare = new char[strlen(specializare) + 1];
    strcpy(this->specializare, specializare);
    this->salariu = 0;
    this->iaSpaga = false;
}

Medic :: Medic(const Medic& obj)
{
    this->numeDoctor = new char[strlen(obj.numeDoctor)+1];
    strcpy(this->numeDoctor, obj.numeDoctor);
    this->specializare = new char[strlen(obj.specializare)+1];
    strcpy(this->specializare, obj.specializare);
    this->salariu = obj.salariu;
    this->iaSpaga = obj.iaSpaga;
}

Medic& Medic :: operator = (const Medic& obj)
{
    if(this != &obj){
        if(this->numeDoctor != NULL){
        delete[] this->numeDoctor;
        this->numeDoctor = NULL;
    }
        if(this->specializare != NULL){
            delete[] this->specializare;
            this->specializare = NULL;
        }
        this->numeDoctor = new char[strlen(obj.numeDoctor)+1];
        strcpy(this->numeDoctor, obj.numeDoctor);
        this->specializare = new char[strlen(obj.specializare)+1];
        strcpy(this->specializare, obj.specializare);
        this->salariu = obj.salariu;
        this->iaSpaga = obj.iaSpaga;
    }
    return *this;
}

ostream& operator << (ostream& out, const Medic& obj)
{
    out<<"Nume Medic: "<<obj.numeDoctor<<endl;
    out<<"Specializare: "<<obj.specializare<<endl;
    out<<"Salariu: "<<obj.salariu<<endl;
    if(obj.iaSpaga == true)
        out<<"Ia spaga"<<endl;
    else out<<"Nu ia spaga"<<endl;
    return out;
}

istream& operator >> (istream& in, Medic& obj)
{
    if(obj.numeDoctor != NULL){
        delete[] obj.numeDoctor;
        obj.numeDoctor = NULL;
    }
    if(obj.specializare != NULL){
        delete[] obj.specializare;
        obj.specializare = NULL;
    }
    char nume[100];
    cout<<"Nume medic: ";
    in.getline(nume, 100);
    obj.numeDoctor = new char[strlen(nume)+1];
    strcpy(obj.numeDoctor, nume);
    char specializare[100];
    cout<<"Specializare: ";
    in.getline(specializare, 100);
    obj.specializare = new char[strlen(specializare)+1];
    strcpy(obj.specializare, specializare);
    cout<<"Salariu: ";
    in>>obj.salariu;
    cout<<"Ia spaga? ";
    in>>obj.iaSpaga;
    return in;
}

bool Medic :: operator == (const Medic& obj)
{
    if(strcmp(this->numeDoctor, obj.numeDoctor))
        return false;
    if(strcmp(this->specializare, obj.specializare))
    if(this->salariu != obj.salariu)
        return false;
    if(this->iaSpaga != obj.iaSpaga)
        return false;
    return true;
}

bool Medic :: operator < (const Medic& obj)
{
    if(strcmp(this->numeDoctor, obj.numeDoctor) >= 0)
        return false;
    return true;
}

bool Medic :: operator > (const Medic& obj)
{
    if(strcmp(this->numeDoctor, obj.numeDoctor) <= 0)
        return false;
    return true;
}

Medic& Medic :: operator += (const Medic& obj)
{
    this->salariu = obj.salariu + this->salariu;
    return *this;
}

Medic Medic :: operator + ( Medic obj)
{
    obj.salariu += this->salariu;
    return obj;
}

Medic Medic :: operator + (int x)
{
    Medic obj(*this);
    obj.salariu += x;
    return obj;
}

Medic operator + (int x, Medic obj)
{
    obj.salariu += x;
    return obj;
}

Medic Medic :: operator - ( Medic obj)
{
    obj.salariu -= this->salariu;
    return obj;
}

Medic Medic :: operator - (int x)
{
    Medic obj(*this);
    obj.salariu -= x;
    return obj;
}

Medic operator - (int x, Medic obj)
{
    obj.salariu = x - obj.salariu;
    return obj;
}

Medic& Medic :: operator ++ ()
{
    this->salariu ++;
    return *this;
}

Medic Medic :: operator ++(int x)
{
    Medic obj(*this);
    this->salariu ++;
    return obj;
}

char Medic :: operator [] (int i)
{
    if(this->numeDoctor == NULL)
        throw runtime_error("Nu exista nume");
    if(i < 0 || i >= strlen(this->numeDoctor)){
        throw runtime_error("Index invalid");
    }
    return this->numeDoctor[i];
}

Medic :: operator string()
{
    return string(this->numeDoctor);
}

void Medic :: setNume()
{
    if(numeDoctor != NULL){
        delete[] numeDoctor;
        numeDoctor = NULL;
    }

    numeDoctor = new char[strlen("cineva")+1];
    strcpy(numeDoctor, "cineva");
}

bool Medic :: consultatie()
{
    system("CLS");
    cout<<"Cum te simti?"<<endl;
    cout<<"1.Bine"<<endl;
    cout<<"2.Nu prea bine"<<endl;
    cout<<"3.Simt ca mor"<<endl;
    int x;
    cin>>x;
    switch(x)
    {
    case 1:
        {
            system("CLS");
            cout<<"Atunci ce cauti aici?"<<endl;
            system("PAUSE");
            system("CLS");

            return 0;
        }
    case 2:
        {
            system("CLS");
            cout<<"Doriti sa va internam?"<<endl;
            cout<<"1.Da"<<endl;
            cout<<"2.Nu"<<endl;
            int x2;
            cin>>x2;
            if(x2 == 1){
                system("CLS");
                return 1;}
            else if(x2 == 2) {
                system("CLS");
                return 0;
            }
            else{
                system("CLS");
                cout<<"Input invalid!"<<endl;
                system("PAUSE");
                system("CLS");
                return 0;
            }

        }
    case 3:
        {
            system("CLS");
            cout<<"Va trebui sa va internam"<<endl;
            system("PAUSE");
            system("CLS");
            return 1;
        }
    default:
        {
            system("CLS");
            cout<<"Input invalid"<<endl;
            system("PAUSE");
            system("CLS");
            return 0;
        }
    }
}

Medic :: ~Medic()
{
    if(this->numeDoctor != NULL){
        delete[] this->numeDoctor;
        this->numeDoctor = NULL;
    }
    if(this->specializare != NULL){
        delete[] this->specializare;
        this->specializare = NULL;
    }
    this->salariu = 0;
    this->iaSpaga = false;
}

class Ambulanta {
    char* nrInmatriculare;
    bool esteOcupata;
    int nrPersoaneEchipaj;
    double distantaParcursa;
public:
    Ambulanta();
    Ambulanta(char* nrInmatriculare, bool esteOcupata, int nrPersoaneEchipaj, double distantaParcursa);
    Ambulanta(char* nrInmatriculare, bool esteOcupata, int nrPersoaneEchipaj);
    Ambulanta(char* nrInmatriculare, bool esteOcupata);
    Ambulanta(const Ambulanta& obj);

    Ambulanta& operator = (const Ambulanta& obj);
    friend istream& operator >> (istream& in, Ambulanta& obj);
    friend ostream& operator << (ostream& out, const Ambulanta& obj);
    bool operator == (const Ambulanta& obj);
    bool operator < (const Ambulanta& obj);
    bool operator > (const Ambulanta& obj);
    char operator [](int i);
    Ambulanta operator + (Ambulanta obj);
    Ambulanta operator + (int x);
    friend Ambulanta operator + (int x, Ambulanta obj);
    Ambulanta operator - (Ambulanta obj);
    Ambulanta operator - (int x);
    friend Ambulanta operator - (int x, Ambulanta obj);
    Ambulanta operator ++ ();
    Ambulanta operator ++(int);
    operator int();

    const char* getNrInmatriculare() const {return nrInmatriculare;}
    bool disponibil(){return esteOcupata;}
    void setDisponibil(){esteOcupata = false;}
    void setDisponibil2(){esteOcupata = true;}
    float getDistanta(){return distantaParcursa;}
    void setDistanta(){distantaParcursa = 0;}

    ~Ambulanta();
};

Ambulanta :: Ambulanta()
{
    this->nrInmatriculare = new char[strlen("ceva") + 1];
    strcpy(this->nrInmatriculare, "ceva");
    this->esteOcupata = false;
    this->nrPersoaneEchipaj = 0;
    this->distantaParcursa = 0;
}
Ambulanta :: Ambulanta(char* nrInmatriculare, bool esteOcupata, int nrPersoaneEchipaj, double distantaParcursa)
{
    this->nrInmatriculare = new char[strlen(nrInmatriculare) + 1];
    strcpy(this->nrInmatriculare, nrInmatriculare);
    this->esteOcupata = esteOcupata;
    this->nrPersoaneEchipaj = nrPersoaneEchipaj;
    this->distantaParcursa = distantaParcursa;
}

Ambulanta :: Ambulanta(char* nrInmatriculare, bool esteOcupata, int nrPersoaneEchipaj)
{
    this->nrInmatriculare = new char[strlen(nrInmatriculare) + 1];
    strcpy(this->nrInmatriculare, nrInmatriculare);
    this->esteOcupata = esteOcupata;
    this->nrPersoaneEchipaj = nrPersoaneEchipaj;
    this->distantaParcursa = 0;
}

Ambulanta :: Ambulanta(char* nrInmatriculare, bool esteOcupata)
{
    this->nrInmatriculare = new char[strlen(nrInmatriculare) + 1];
    strcpy(this->nrInmatriculare, nrInmatriculare);
    this->esteOcupata = esteOcupata;
    this->nrPersoaneEchipaj = 0;
    this->distantaParcursa = 0;
}

Ambulanta :: Ambulanta(const Ambulanta& obj)
{
    this->nrInmatriculare = new char[strlen(obj.nrInmatriculare) + 1];
    strcpy(this->nrInmatriculare, obj.nrInmatriculare);
    this->esteOcupata = obj.esteOcupata;
    this->nrPersoaneEchipaj = obj.nrPersoaneEchipaj;
    this->distantaParcursa = obj.distantaParcursa;
}

Ambulanta& Ambulanta :: operator = (const Ambulanta& obj)
{
    if(this != &obj){
        if(this->nrInmatriculare != NULL){
        delete[] this->nrInmatriculare;
        this->nrInmatriculare = NULL;
        }
        this->nrInmatriculare = new char[strlen(obj.nrInmatriculare)+1];
        strcpy(this->nrInmatriculare, obj.nrInmatriculare);
        this->esteOcupata = obj.esteOcupata;
        this->nrPersoaneEchipaj = obj.nrPersoaneEchipaj;
        this->distantaParcursa = obj.distantaParcursa;
    }
    return *this;
}

ostream& operator << (ostream& out, const Ambulanta& obj)
{
    out<<"Numar de inmatriculare: "<<obj.nrInmatriculare<<endl;
    if(obj.esteOcupata == true)
        out<<"Ambulanta este in misiune"<<endl;
    else out<<"Ambulanta este disponibila"<<endl;
    out<<"Echipaj de "<<obj.nrPersoaneEchipaj<<" persoane"<<endl;
    out<<"A parcurs "<<obj.distantaParcursa<<" km"<<endl;
    return out;
}

istream& operator >> (istream& in, Ambulanta& obj)
{
    if(obj.nrInmatriculare != NULL){
        delete[] obj.nrInmatriculare;
        obj.nrInmatriculare = NULL;
    }
    char nr[10];
    cout<<"Numar inmatriculare: ";
    in>>nr;
    obj.nrInmatriculare = new char[strlen(nr)+1];
    strcpy(obj.nrInmatriculare, nr);
    cout<<"Este ambulanta in misiune? ";
    in>>obj.esteOcupata;
    cout<<"Numar persoane echipaj: ";
    in>>obj.nrPersoaneEchipaj;
    cout<<"Numar km parcursi: ";
    in>>obj.distantaParcursa;
    return in;
}

bool Ambulanta :: operator == (const Ambulanta& obj)
{
    if(strcmp(this->nrInmatriculare, obj.nrInmatriculare))
        return false;
    if(this->esteOcupata != obj.esteOcupata)
        return false;
    if(this->nrPersoaneEchipaj != obj.nrPersoaneEchipaj)
        return false;
    if(this->distantaParcursa != obj.distantaParcursa)
        return false;
    return true;
}

bool Ambulanta :: operator < (const Ambulanta& obj)
{
    if(strcmp(this->nrInmatriculare, obj.nrInmatriculare) > 0)
        return false;
    return true;
}

bool Ambulanta :: operator > (const Ambulanta& obj)
{
    if(strcmp(this->nrInmatriculare, obj.nrInmatriculare) < 0)
        return false;
    return true;
}

char Ambulanta :: operator [](int i)
{
    if(this->nrInmatriculare == NULL)
        throw runtime_error("Nu exista numar de inmatriculare");
    if(i < 0 || i >= strlen(this->nrInmatriculare)){
        throw runtime_error("Index invalid");
    }
    return this->nrInmatriculare[i];
}
Ambulanta Ambulanta :: operator + (Ambulanta obj)
{
    obj.nrPersoaneEchipaj += this-> nrPersoaneEchipaj;
    return obj;
}
Ambulanta Ambulanta :: operator + (int x)
{
    Ambulanta obj(*this);
    obj.nrPersoaneEchipaj += x;
    return obj;
}
Ambulanta operator + (int x, Ambulanta obj)
{
    obj.nrPersoaneEchipaj += x;
    return obj;
}
Ambulanta Ambulanta :: operator - (Ambulanta obj)
{
    obj.nrPersoaneEchipaj -= this-> nrPersoaneEchipaj;
    return obj;
}
Ambulanta Ambulanta :: operator - (int x)
{
    Ambulanta obj(*this);
    obj.nrPersoaneEchipaj -= x;
    return obj;
}
Ambulanta operator - (int x, Ambulanta obj)
{
    obj.nrPersoaneEchipaj = x - obj.nrPersoaneEchipaj;
    return obj;
}
Ambulanta Ambulanta :: operator ++ ()
{
    this-> distantaParcursa++;
    return *this;
}
Ambulanta Ambulanta :: operator ++(int )
{
    Ambulanta obj(*this);
    obj.distantaParcursa++;
    return obj;
}

Ambulanta :: operator int()
{
    return int(this->distantaParcursa);
}

Ambulanta :: ~Ambulanta()
{
    if(this->nrInmatriculare != NULL){
        delete[] this->nrInmatriculare;
        this->nrInmatriculare = NULL;
    }
    esteOcupata = false;
    nrPersoaneEchipaj = 0;
    distantaParcursa = 0;
}

class Medicament {
    char* numeMedicament;
    char* formaMedicament;
    int* dataExpirare;
    bool trebuieReteta;
public:
    Medicament();
    Medicament(char* numeMedicament, char* formaMedicament, int* dataExpirare, bool trebuieReteta);
    Medicament(char* numeMedicament, int* dataExpirare, bool trebuieReteta);
    Medicament(char* numeMedicament, int* dataExpirare);
    Medicament(const Medicament& obj);

    Medicament& operator = (const Medicament& obj);
    friend istream& operator >> (istream& in, Medicament& obj);
    friend ostream& operator << (ostream& out, const Medicament& obj);
    bool operator == (const Medicament& obj);
    bool operator < (const Medicament& obj);
    bool operator > (const Medicament& obj);
    Medicament& operator += (const Medicament& obj);
    Medicament& operator -= (const Medicament& obj);
    Medicament operator + ( Medicament obj);
    Medicament operator + (int x);
    friend Medicament operator + (int x, Medicament obj);
    Medicament operator - ( Medicament obj);
    Medicament operator - (int x);
    friend Medicament operator - (int x, Medicament obj);
    Medicament& operator ++ ();
    Medicament operator ++ (int x);
    int operator [] (int i);
    operator string();

    void setDataExpirare();
    const int* getDataExpirare() const {return this-> dataExpirare;}

    bool esteExpirat();

    ~Medicament();
};

Medicament :: Medicament()
{
    this->numeMedicament = new char[strlen("ceva") + 1];
    strcpy(this->numeMedicament, "ceva");
    this->formaMedicament = new char[strlen("ceva") + 1];
    strcpy(this->formaMedicament, "ceva");
    this->dataExpirare = new int[3];
    for(int i=0; i<3; i++)
        this->dataExpirare[i] = 0;
    this->trebuieReteta = false;
}

Medicament :: Medicament(char* numeMedicament, char* formaMedicament, int* dataExpirare, bool trebuieReteta)
{
    this->numeMedicament = new char[strlen(numeMedicament) + 1];
    strcpy(this->numeMedicament, numeMedicament);
    this->formaMedicament = new char[strlen(formaMedicament) + 1];
    strcpy(this->formaMedicament, formaMedicament);
    this->dataExpirare = new int[3];
    for(int i=0; i<3; i++)
        this->dataExpirare[i] = dataExpirare[i];
    this->trebuieReteta = trebuieReteta;
}

Medicament :: Medicament(char* numeMedicament, int* dataExpirare, bool trebuieReteta)
{
    this->numeMedicament = new char[strlen(numeMedicament) + 1];
    strcpy(this->numeMedicament, numeMedicament);
    this->formaMedicament = new char[strlen("capsule") + 1];
    strcpy(this->formaMedicament, "capsule");
    this->dataExpirare = new int[3];
    for(int i=0; i<3; i++)
        this->dataExpirare[i] = dataExpirare[i];
    this->trebuieReteta = trebuieReteta;
}

Medicament :: Medicament(char* numeMedicament, int* dataExpirare)
{
    this->numeMedicament = new char[strlen(numeMedicament) + 1];
    strcpy(this->numeMedicament, numeMedicament);
    this->formaMedicament = new char[strlen("capsule") + 1];
    strcpy(this->formaMedicament, "capsule");
    this->dataExpirare = new int[3];
    for(int i=0; i<3; i++)
        this->dataExpirare[i] = dataExpirare[i];
    this->trebuieReteta = false;
}

Medicament :: Medicament(const Medicament& obj)
{
    this->numeMedicament = new char[strlen(obj.numeMedicament) + 1];
    strcpy(this->numeMedicament, obj.numeMedicament);
    this->formaMedicament = new char[strlen(obj.formaMedicament) + 1];
    strcpy(this->formaMedicament, obj.formaMedicament);
    this->dataExpirare = new int[3];
    for(int i=0; i<3; i++)
        this->dataExpirare[i] = obj.dataExpirare[i];
    this->trebuieReteta = obj.trebuieReteta;
}

Medicament& Medicament :: operator = (const Medicament& obj)
{
    if(this != &obj){
        if(this->numeMedicament != NULL){
        delete[] this->numeMedicament;
        this->numeMedicament= NULL;
        }
        if(this->formaMedicament != NULL){
            delete[] this->formaMedicament;
            this->formaMedicament = NULL;
        }
        if(this->dataExpirare != NULL){
            delete[] this->dataExpirare;
            this->dataExpirare = NULL;
        }
        this->numeMedicament = new char[strlen(obj.numeMedicament) + 1];
        strcpy(this->numeMedicament, obj.numeMedicament);
        this->formaMedicament = new char[strlen(obj.formaMedicament) + 1];
        strcpy(this->formaMedicament, obj.formaMedicament);
        this->dataExpirare = new int[3];
        for(int i=0; i<3; i++)
            this->dataExpirare[i] = obj.dataExpirare[i];
        this->trebuieReteta = obj.trebuieReteta;

    }
    return *this;
}

ostream& operator << (ostream& out, const Medicament& obj)
{
    out<<"Nume: "<<obj.numeMedicament<<endl;
    out<<"Forma medicament: "<<obj.formaMedicament<<endl;
    out<<"Data expirarii: ";
    if(obj.dataExpirare[0] < 10)
        out<<0<<obj.dataExpirare[0]<<'.';
    else out<<obj.dataExpirare[0]<<'.';
    if(obj.dataExpirare[1] < 10)
        out<<0<<obj.dataExpirare[1]<<'.';
    else out<<obj.dataExpirare[1]<<'.';
    out<<obj.dataExpirare[2]<<endl;
    if(obj.trebuieReteta == true)
        out<<"Se prescrie numai cu reteta"<<endl;
    else out<<"Se prescrie si fara reteta"<<endl;
    return out;
}

istream& operator >> (istream& in, Medicament& obj)
{
    if(obj.numeMedicament != NULL){
        delete[] obj.numeMedicament;
        obj.numeMedicament= NULL;
    }
    if(obj.formaMedicament != NULL){
        delete[] obj.formaMedicament;
        obj.formaMedicament = NULL;
    }
    if(obj.dataExpirare != NULL){
        delete[] obj.dataExpirare;
        obj.dataExpirare = NULL;
    }
    char nume[100], aux[10];
    cout<<"Nume medicament: ";
    in.getline(nume, 100);
    obj.numeMedicament = new char[strlen(nume)+1];
    strcpy(obj.numeMedicament, nume);
    char forma[100];
    cout<<"Forma medicament: ";
    in.getline(forma, 100);
    obj.formaMedicament = new char[strlen(forma)+1];
    strcpy(obj.formaMedicament, forma);
    obj.dataExpirare = new int[3];
    cout<<"Data expirarii: ";
    for(int i=0; i<3; i++)
        in>>obj.dataExpirare[i];
    cout<<"Se prescrie doar cu reteta? ";
    in>>obj.trebuieReteta;
    return in;
}

bool Medicament :: operator == (const Medicament& obj)
{
    if(strcmp(this->numeMedicament, obj.numeMedicament))
        return false;
    if(strcmp(this->formaMedicament, obj.formaMedicament))
        return false;
    for(int i=0; i<3; i++)
        if(this->dataExpirare[i] != obj.dataExpirare[i])
            return false;
    if(this->trebuieReteta != obj.trebuieReteta)
        return false;
    return true;
}

bool Medicament :: operator < (const Medicament& obj)
{
    for(int i=2; i>=0; i--){
        if(this->dataExpirare[i] > obj.dataExpirare[i])
            return false;
        else if(this->dataExpirare[i] < obj.dataExpirare[i])
            return true;
        }
    return false;
}
bool Medicament :: operator > (const Medicament& obj)
{
    for(int i=2; i>=0; i--){
        if(this->dataExpirare[i] < obj.dataExpirare[i])
            return false;
        else if(this->dataExpirare[i] > obj.dataExpirare[i])
            return true;
        }
    return false;
}
Medicament& Medicament :: operator += (const Medicament& obj)
{
    this->dataExpirare[2] += obj.dataExpirare[2];
    return *this;
}
Medicament& Medicament :: operator -= (const Medicament& obj)
{
    this->dataExpirare[2] -= obj.dataExpirare[2];
    return *this;
}
Medicament Medicament :: operator + ( Medicament obj)
{
    obj.dataExpirare[2] += this->dataExpirare[2];
    return obj;
}
Medicament Medicament :: operator + (int x)
{
    Medicament obj(*this);
    obj.dataExpirare[2] += x;
    return obj;
}
Medicament operator + (int x, Medicament obj)
{
    obj.dataExpirare[2] += x;
    return obj;
}

Medicament Medicament :: operator - ( Medicament obj)
{

    obj.dataExpirare[2] -= this->dataExpirare[2];
    return obj;
}

Medicament Medicament :: operator - (int x)
{
    Medicament obj(*this);
    obj.dataExpirare[2] -= x;
    return obj;
}

Medicament operator - (int x, Medicament obj)
{
    obj.dataExpirare[2] = x - obj.dataExpirare[2];
    return obj;
}
Medicament& Medicament :: operator ++ ()
{
    this->dataExpirare[2]++;
    return *this;
}
Medicament Medicament :: operator ++ (int x)
{
    Medicament obj(*this);
    this->dataExpirare[2] ++;
    return obj;
}
int Medicament :: operator [] (int i)
{
    if(this->dataExpirare == NULL)
        throw runtime_error("Nu exista data expirarii");
    if(i < 0 || i >= 3){
        throw runtime_error("Index invalid");
    }
    return this->dataExpirare[i];
}
Medicament :: operator string()
{
    return string(this->numeMedicament);
}

void Medicament :: setDataExpirare()
{
    if(dataExpirare != NULL){
        delete[] dataExpirare;
        dataExpirare = NULL;
    }
    dataExpirare = new int[3];
    for(int i=0; i<3; i++)
        dataExpirare[i] = 0;
}

bool Medicament :: esteExpirat()
{
    int zi, luna, an;
    cout<<"Introdu data de astazi: ";
    cin>>zi>>luna>>an;
    if(an > this->dataExpirare[2]){
        cout<<"Medicamentul este expirat."<<endl;
        return true;
    }
    else if(an < this->dataExpirare[2]){
        cout<<"Medicamentul nu este expirat."<<endl;
        return false;
    }
    else{
        if(luna > this->dataExpirare[1]){
            cout<<"Medicamentul este expirat."<<endl;
            return true;
        }
        else if(luna < this->dataExpirare[1]){
            cout<<"Medicamentul nu este expirat."<<endl;
            return false;
        }
        else{
            if(zi >= this->dataExpirare[0]){
                cout<<"Medicamentul este expirat."<<endl;
                return true;
            }
            else{
                cout<<"Medicamentul nu este expirat."<<endl;
                return false;
            }
        }
    }
}

Medicament :: ~Medicament()
{
    if(this->numeMedicament != NULL){
        delete[] this->numeMedicament;
        this->numeMedicament= NULL;
    }
    if(this->formaMedicament != NULL){
        delete[] this->formaMedicament;
        this->formaMedicament = NULL;
    }
    if(this->dataExpirare != NULL){
        delete[] this->dataExpirare;
        this->dataExpirare = NULL;
    }
    this->trebuieReteta = false;
}

class Pacient {
    static int contorId;
    const int idPacient;
    char* numePacient;
    char* motivInternare;
    double sanseSupravietuire;
    char grupaSange;

public:
    Pacient();
    Pacient(char* numePacient, char* motivInternare, double sanseSupravietuire, char grupaSange);
    Pacient(char* numePacient, char* motivInternare, char grupaSange);
    Pacient(char* numePacient, char grupaSange);
    Pacient(const Pacient& obj);

    Pacient& operator = (const Pacient& obj);
    friend istream& operator >> (istream& in, Pacient& obj);
    friend ostream& operator << (ostream& out, const Pacient& obj);
    bool operator == (const Pacient& obj);
    bool operator < (const Pacient& obj);
    bool operator > (const Pacient& obj);
    Pacient& operator += (const Pacient& obj);
    Pacient& operator -= (const Pacient& obj);
    Pacient operator + ( Pacient obj);
    Pacient operator + (int x);
    friend Pacient operator + (int x, Pacient obj);
    Pacient operator - ( Pacient obj);
    Pacient operator - (int x);
    friend Pacient operator - (int x, Pacient obj);
    Pacient& operator ++ ();
    Pacient operator ++ (int x);
    char operator [] (int i);
    operator int();
    Pacient operator + (Medicament b);
    friend Pacient operator + (Medicament b, Pacient a);

    char getGrupaSange(){return grupaSange;}
    void setGrupaSange(){grupaSange = 'A';}
    double getSanseSupravietuire(){return sanseSupravietuire;}
    void setSanseSupravietuire(){sanseSupravietuire = 100;}
    static int getContorId(){return contorId;}
    void setContorId(){contorId = 0;}

    bool supravietuieste();

    ~Pacient();
};

int Pacient::contorId = 0;

Pacient :: Pacient():idPacient(contorId++)
{
    this->numePacient = new char[strlen("cineva") + 1];
    strcpy(this->numePacient, "cineva");
    this->motivInternare = new char[strlen("ceva") + 1];
    strcpy(this->motivInternare, "ceva");
    this->sanseSupravietuire = 100;
    this->grupaSange = '-';
}

Pacient :: Pacient(char* numePacient, char* motivInternare, double sanseSupravietuire, char grupaSange):idPacient(contorId++)
{
    this->numePacient = new char[strlen(numePacient) + 1];
    strcpy(this->numePacient, numePacient);
    this->motivInternare = new char[strlen(motivInternare) + 1];
    strcpy(this->motivInternare, motivInternare);
    this->sanseSupravietuire = sanseSupravietuire;
    this->grupaSange = grupaSange;
}

Pacient :: Pacient(char* numePacient, char* motivInternare, char grupaSange):idPacient(contorId++)
{
    this->numePacient = new char[strlen(numePacient) + 1];
    strcpy(this->numePacient, numePacient);
    this->motivInternare = new char[strlen(motivInternare) + 1];
    strcpy(this->motivInternare, motivInternare);
    this->sanseSupravietuire = 100;
    this->grupaSange = grupaSange;
}

Pacient :: Pacient(char* numePacient, char grupaSange):idPacient(contorId++)
{
    this->numePacient = new char[strlen(numePacient) + 1];
    strcpy(this->numePacient, numePacient);
    this->motivInternare = new char[strlen("control") + 1];
    strcpy(this->motivInternare, "control");
    this->sanseSupravietuire = 100;
    this->grupaSange = grupaSange;
}

Pacient :: Pacient(const Pacient& obj):idPacient(obj.idPacient)
{
    this->numePacient = new char[strlen(obj.numePacient) + 1];
    strcpy(this->numePacient, obj.numePacient);
    this->motivInternare = new char[strlen(obj.motivInternare) + 1];
    strcpy(this->motivInternare, obj.motivInternare);
    this->sanseSupravietuire = obj.sanseSupravietuire;
    this->grupaSange = obj.grupaSange;
}

Pacient& Pacient :: operator = (const Pacient& obj)
{
    if(this != &obj){
        if(this->numePacient != NULL){
        delete[] this->numePacient;
        this->numePacient = NULL;
    }
        if(this->motivInternare != NULL){
            delete[] this->motivInternare;
            this->motivInternare = NULL;
        }
        this->numePacient = new char[strlen(obj.numePacient) + 1];
        strcpy(this->numePacient, obj.numePacient);
        this->motivInternare = new char[strlen(obj.motivInternare) + 1];
        strcpy(this->motivInternare, obj.motivInternare);
        this->sanseSupravietuire = obj.sanseSupravietuire;
        this->grupaSange = obj.grupaSange;
    }
    return *this;
}

ostream& operator << (ostream& out, const Pacient& obj)
{
    out<<"ID: "<<obj.idPacient<<endl;
    out<<"Nume: "<<obj.numePacient<<endl;
    out<<"Motiv internare: "<<obj.motivInternare<<endl;
    out<<"Sanse supravietuire: "<<obj.sanseSupravietuire<<"%"<<endl;
    out<<"Grupa sanguina: ";
    if(obj.grupaSange == 'C')
        out<<"AB"<<endl;
    else out<<obj.grupaSange<<endl;
    return out;
}

istream& operator >> (istream& in, Pacient& obj)
{
    if(obj.numePacient != NULL){
        delete[] obj.numePacient;
        obj.numePacient = NULL;
    }
    if(obj.motivInternare != NULL){
        delete[] obj.motivInternare;
        obj.motivInternare = NULL;
    }
    char nume[100];
    cout<<"Nume pacient: ";
    in.getline(nume, 100);
    obj.numePacient = new char[strlen(nume)+1];
    strcpy(obj.numePacient, nume);
    char motiv[100];
    cout<<"Motiv internare: ";
    in.getline(motiv, 100);
    obj.motivInternare = new char[strlen(motiv)+1];
    strcpy(obj.motivInternare, motiv);
    cout<<"Sanse supravietuire: ";
    in>>obj.sanseSupravietuire;
    cout<<"Grupa sanguina: ";
    in>>obj.grupaSange;
    return in;
}

bool Pacient :: operator == (const Pacient& obj)
{
    if(strcmp(this->numePacient, obj.numePacient))
        return false;
    if(strcmp(this->motivInternare, obj.motivInternare))
        return false;
    if(this->sanseSupravietuire != obj.sanseSupravietuire)
        return false;
    if(this->grupaSange != obj.grupaSange)
        return false;
    return true;
}

bool Pacient :: operator < (const Pacient& obj)
{
    if(strcmp(this->numePacient, obj.numePacient) >= 0)
        return false;
    return true;
}
bool Pacient :: operator > (const Pacient& obj)
{
    if(strcmp(this->numePacient, obj.numePacient) < 0)
        return false;
    return true;
}
Pacient& Pacient :: operator += (const Pacient& obj)
{
    this->sanseSupravietuire+= obj.sanseSupravietuire;
    return *this;
}
Pacient& Pacient :: operator -= (const Pacient& obj)
{
    this->sanseSupravietuire-= obj.sanseSupravietuire;
    return *this;
}
Pacient Pacient :: operator + ( Pacient obj)
{
    obj.sanseSupravietuire += this->sanseSupravietuire;
    return obj;
}

Pacient Pacient :: operator + (int x)
{
    Pacient obj(*this);
    obj.sanseSupravietuire += x;
    return obj;
}

Pacient operator + (int x, Pacient obj)
{
    obj.sanseSupravietuire += x;
    return obj;
}

Pacient Pacient :: operator - ( Pacient obj)
{
    obj.sanseSupravietuire -= this->sanseSupravietuire;
    return obj;
}
Pacient Pacient :: operator - (int x)
{
    Pacient obj(*this);
    obj.sanseSupravietuire -= x;
    return obj;
}
Pacient operator - (int x, Pacient obj)
{
    obj.sanseSupravietuire = x - obj.sanseSupravietuire;
    return obj;
}
Pacient& Pacient :: operator ++ ()
{
    this->sanseSupravietuire++;
    return *this;
}
Pacient Pacient :: operator ++ (int x)
{
    Pacient obj(*this);
    this->sanseSupravietuire++;
    return obj;
}
char Pacient :: operator [] (int i)
{
    if(this->numePacient == NULL)
        throw runtime_error("Nu exista nume");
    if(i < 0 || i >= strlen(this->numePacient)){
        throw runtime_error("Index invalid");
    }
    return this->numePacient[i];
}
Pacient :: operator int()
{
    return int(this->sanseSupravietuire);
}

bool Pacient :: supravietuieste()
{
    srand(time(NULL));
    if((rand() % 101) < this->sanseSupravietuire)
        return true;
    return false;
}

Pacient :: ~Pacient()
{
    if(this->numePacient != NULL){
        delete[] this->numePacient;
        this->numePacient = NULL;
    }
    if(this->motivInternare != NULL){
        delete[] this->motivInternare;
        this->motivInternare = NULL;
    }
    sanseSupravietuire = 0;
    grupaSange = '-';
}

Pacient Pacient :: operator + (Medicament b)
{
    Pacient a(*this);
    if(b.esteExpirat() == true)
        a.sanseSupravietuire -= 10;
    else a.sanseSupravietuire += 10;
    return a;
}
Pacient operator + (Medicament b, Pacient a)
{
    if(b.esteExpirat() == true)
        a.sanseSupravietuire -= 10;
    else a.sanseSupravietuire += 10;
    return a;
}

int main()
{
    vector<Medic> a;
    vector<Ambulanta> b;
    vector<Medicament> c;
    vector<Pacient> d;
    Medic a1("Baesu Serban", "Psihiatrie", 12000, false), a2("Ionescu Bogdan", "Chirurgie", 10000, true),
    a3("Popescu Andrei", "Oftalmologie", 9500, false), a4("Popa Stefan", "Chirurgie", 11500, true),
    a5("Andreescu Ion", "Pediatrie", 12000, false) ;
    a.push_back(a1); a.push_back(a2); a.push_back(a3); a.push_back(a4); a.push_back(a5);

    Ambulanta b1("B153CSG", false, 3, 56.2), b2("AG53AVG", true, 3, 56.6), b3("BT09FWG", false, 2, 120.5), b4("B231AAF", true, 4, 34.2),
    b5("B263DPA", true, 3, 55.1);
    b.push_back(b1); b.push_back(b2); b.push_back(b3); b.push_back(b4); b.push_back(b5);
    int z1[] = {12, 01, 2023}, z2[] = {02, 01, 2024}, z3[] = {31, 12, 2020}, z4[] = {13, 04, 1999}, z5[] = {25, 11, 2025};
    Medicament c1("Paracetamol", "Capsule", z1, false), c2("Morfina", "Injectat", z2, true), c3("Nurofen", "Capsule", z3, false),
    c4("Ketamina", "Anestezic", z4, true), c5("Ibuprofen", "Capsule", z5, false);
    c.push_back(c1); c.push_back(c2); c.push_back(c3); c.push_back(c4); c.push_back(c5);
    Pacient d1("Popescu Dan", "Gripa", 90, 'O'), d2("Calinescu Mihai", "Tuberculoza", 55.5, 'A'), d3("Popa Daniela", "Accident masina", 25, 'B'),
    d4("Ionescu Nicolae", "Cancer", 12.4, 'O'), d5("Constantin George", "Fractura picior", 95, 'O');
    d.push_back(d1); d.push_back(d2); d.push_back(d3); d.push_back(d4); d.push_back(d5);

    int k=1;
    cout<<"BINE ATI VENIT LA SPITALUL 132"<<endl<<endl;
    while(k == 1){
        int x;

        cout<<"Alegeti clasa in care vreti sa lucrati"<<endl;
        cout<<"1: Medic"<<endl;
        cout<<"2: Ambulanta"<<endl;
        cout<<"3: Medicament"<<endl;
        cout<<"4: Pacient"<<endl;
        cout<<"0: Stop"<<endl;
        cin>>x;
        cout<<endl;
        switch(x)
        {
            case 1:{
                int k1=1;
                while(k1 == 1){
                int x1;
                system("CLS");
                cout<<"1: Creati obiect nou"<<endl;
                cout<<"2: Cititi obiect nou"<<endl;
                cout<<"3: Editati obiect deja existent"<<endl;
                cout<<"4: Stergeti obiect"<<endl;
                cout<<"5: Afisati toate obiectele existente"<<endl;
                cout<<"6: Consultatie"<<endl;
                cout<<"0: Inapoi"<<endl;
                cin>>x1;
                cout<<endl;
                switch(x1)
                {
                    case 1:
                        {
                        system("CLS");
                        Medic obj;
                        a.push_back(obj);
                        break;
                        }
                    case 2:
                        {
                        system("CLS");
                        Medic obj;
                        char aux[1];
                        cin.getline(aux, 1);
                        cin>>obj;
                        a.push_back(obj);
                        system("CLS");
                        break;
                        }
                    case 3:
                        {
                        system("CLS");
                        for(int i=0; i<a.size(); i++)
                            cout<<a.at(i)<<endl;
                        int j;
                        cout<<"Introduceti indicele obiectului pe care vreti sa il modificati(indexare de la 0)"<<endl;
                        cin>>j;
                        if(j < 0 || j >=a.size()){
                            system("CLS");
                            cout<<"Indice invalid!"<<endl;
                            system("PAUSE");
                            system("CLS");
                            break;}
                        else{
                            Medic obj;
                            char aux[1];
                            cin.getline(aux, 1);
                            cin>>obj;
                            a.at(j) = obj;
                            system("CLS");
                            break;
                            }
                        }
                    case 4:
                        {
                        system("CLS");
                        for(int i=0; i<a.size(); i++)
                            cout<<a.at(i)<<endl;
                        int j;
                        cout<<"Introduceti indicele obiectului pe care vreti sa il stergeti(indexare de la 0)"<<endl;
                        cin>>j;
                        if(j < 0 || j >= a.size()){
                            system("CLS");
                            cout<<"Indice invalid!"<<endl;
                            system("PAUSE");
                            system("CLS");
                            break;
                        }
                        else{
                            vector<Medic>::iterator it = a.begin() + j;
                            a.erase(it);
                            system("CLS");
                            break;
                            }
                        }
                    case 5:
                        {
                        system("CLS");
                        for(int i=0; i<a.size(); i++)
                            cout<<a.at(i)<<endl;
                        system("PAUSE");
                        system("CLS");
                        break;
                        }
                    case 6:
                        {
                        system("CLS");
                        for(int i=0; i<a.size(); i++)
                            cout<<a.at(i)<<endl;
                        cout<<"Introduceti indicele medicului care va va consulta(indexare de la 0)"<<endl;
                        int j;
                        cin>>j;
                        if(j < 0 || j >= a.size()){
                            system("CLS");
                            cout<<"Indice invalid!"<<endl;
                            system("PAUSE");
                            system("CLS");
                            break;
                        }
                        if(a.at(j).consultatie()){
                            system("CLS");
                            Pacient obj;
                            char a[1];
                            cin.getline(a, 1);
                            cin>>obj;
                            d.push_back(obj);
                            system("PAUSE");
                            system("CLS");
                            break;
                        }
                        }
                    case 0:
                        system("CLS");
                        k1 = 0;
                        break;
                    default:{
                        system("CLS");
                        cout<<"Input invalid!"<<endl;
                        system("PAUSE");
                        system("CLS");
                        break;}
                }
                }

                break;}
            case 2:{
                system("CLS");
                int k2 = 1;
                while(k2 == 1){
                int x2;
                cout<<"1: Creati obiect nou"<<endl;
                cout<<"2: Cititi obiect nou"<<endl;
                cout<<"3: Editati obiect deja existent"<<endl;
                cout<<"4: Stergeti obiect"<<endl;
                cout<<"5: Afisati toate obiectele existente"<<endl;
                cout<<"6: Trimite o ambulanta in misiune"<<endl;
                cout<<"7: Intoarce o ambulanta din misiune"<<endl;
                cout<<"0: Inapoi"<<endl;
                cin>>x2;
                cout<<endl;
                switch(x2)
                {
                    case 1:
                        {
                        system("CLS");
                        Ambulanta obj;
                        b.push_back(obj);
                        break;
                        }
                    case 2:
                        {
                        system("CLS");
                        Ambulanta obj;
                        cin>>obj;
                        b.push_back(obj);
                        system("CLS");
                        break;
                        }
                    case 3:
                        {
                        system("CLS");
                        for(int i=0; i<b.size(); i++)
                            cout<<b.at(i)<<endl;
                        int j;
                        cout<<"Introduceti indicele obiectului pe care vreti sa il modificati(indexare de la 0)"<<endl;
                        cin>>j;
                        if(j < 0 || j >= b.size()){
                            system("CLS");
                            cout<<"Indice invalid!"<<endl;
                            system("PAUSE");
                            system("CLS");
                            break;
                        }
                        else{
                            system("CLS");
                            Ambulanta obj;
                            cin>>obj;
                            b.at(j) = obj;
                            system("CLS");
                            break;
                            }
                        }
                    case 4:
                        {
                        system("CLS");
                        for(int i=0; i<b.size(); i++)
                            cout<<b.at(i)<<endl;
                        int j;
                        cout<<"Introduceti indicele obiectului pe care vreti sa il stergeti(indexare de la 0)"<<endl;
                        cin>>j;
                        if(j < 0 || j >= b.size()){
                            system("CLS");
                            cout<<"Indice invalid!"<<endl;
                            system("PAUSE");
                            system("CLS");
                            break;
                        }
                        else{
                            vector<Ambulanta>::iterator it = b.begin() + j;
                            b.erase(it);
                            system("CLS");
                            break;
                            }
                        }
                    case 5:
                        {
                        system("CLS");
                        for(int i=0; i<b.size(); i++)
                            cout<<b.at(i)<<endl;
                        system("PAUSE");
                        system("CLS");
                        break;
                        }
                    case 6:
                        {
                        system("CLS");
                        int x;
                        for(int i=0; i<b.size(); i++)
                            cout<<b.at(i)<<endl;
                        cout<<"Introduceti indicele albulantei pe care vreti sa o trimiteti(indexare de la 0)"<<endl;
                        cin>>x;
                        if(x < 0 || x >= b.size()){
                            system("CLS");
                            cout<<"Indice invalid!"<<endl;
                            system("PAUSE");
                            system("CLS");
                            break;
                            }
                        if(b.at(x).disponibil()){
                            system("CLS");
                            cout<<"Ambulanta este deja in misiune"<<endl;
                            system("PAUSE");
                            system("CLS");
                            break;
                            }
                        b.at(x).setDisponibil2();
                        system("CLS");
                        break;
                        }
                    case 7:
                        {
                        system("CLS");
                        int x;
                        for(int i=0; i<b.size(); i++)
                            cout<<b.at(i)<<endl;
                        cout<<"Introduceti indicele albulantei pe care vreti sa o intoarceti(indexare de la 0)"<<endl;
                        cin>>x;
                        if(x < 0 || x >= b.size()){
                            system("CLS");
                            cout<<"Indice invalid!"<<endl;
                            system("PAUSE");
                            system("CLS");
                            break;
                            }
                        if(!b.at(x).disponibil()){
                            system("CLS");
                            cout<<"Ambulanta este deja la spital"<<endl;
                            system("PAUSE");
                            system("CLS");
                            break;
                            }
                        b.at(x).setDisponibil();
                        system("CLS");
                        cout<<"Cati pacienti sunt in ambulanta?"<<endl;
                        cin>>x;
                        system("CLS");
                        for(int i=0; i<x; i++){
                            Pacient obj;
                            char a[1];
                            cin.getline(a, 1);
                            cin>>obj;
                            d.push_back(obj);
                            system("CLS");
                            }
                        break;
                        }
                    case 0:
                        system("CLS");
                        k2 = 0;
                        break;
                    default:{
                        system("CLS");
                        cout<<"Input invalid!"<<endl;
                        system("PAUSE");
                        system("CLS");
                        break;
                        }
                }
                }
                break;}
            case 3:{
                system("CLS");
                int k3=1;
                while(k3 == 1){
                int x3;
                cout<<"1: Creati obiect nou"<<endl;
                cout<<"2: Cititi obiect nou"<<endl;
                cout<<"3: Editati obiect deja existent"<<endl;
                cout<<"4: Stergeti obiect"<<endl;
                cout<<"5: Afisati toate obiectele existente"<<endl;
                cout<<"6: Verificati daca un medicament este expirat"<<endl;
                cout<<"0: Inapoi"<<endl;
                cin>>x3;
                cout<<endl;
                switch(x3)
                {
                    case 1:
                        {
                        system("CLS");
                        Medicament obj;
                        c.push_back(obj);
                        break;
                        }
                    case 2:
                        {
                        system("CLS");
                        Medicament obj;
                        char aux[1];
                        cin.getline(aux, 1);
                        cin>>obj;
                        c.push_back(obj);
                        system("CLS");
                        break;
                        }
                    case 3:
                        {
                        system("CLS");
                        for(int i=0; i<c.size(); i++)
                            cout<<c.at(i)<<endl;
                        int j;
                        cout<<"Introduceti indicele obiectului pe care vreti sa il modificati(indexare de la 0)"<<endl;
                        cin>>j;
                        if(j < 0 || j >= c.size()){
                            system("CLS");
                            cout<<"Indice invalid!"<<endl;
                            system("PAUSE");
                            system("CLS");
                            break;
                        }
                        else{
                            system("CLS");
                            Medicament obj;
                            char aux[1];
                            cin.getline(aux, 1);
                            cin>>obj;
                            c.at(j) = obj;
                            system("CLS");
                            break;
                            }
                        }
                    case 4:
                        {
                        system("CLS");
                        for(int i=0; i<c.size(); i++)
                            cout<<c.at(i)<<endl;
                        int j;
                        cout<<"Introduceti indicele obiectului pe care vreti sa il stergeti(indexare de la 0)"<<endl;
                        cin>>j;
                        if(j < 0 || j >= c.size()){
                            system("CLS");
                            cout<<"Indice invalid!"<<endl;
                            system("PAUSE");
                            system("CLS");
                            break;
                        }
                        else{
                            vector<Medicament>::iterator it = c.begin() + j;
                            c.erase(it);
                            system("CLS");
                            break;
                            }
                        }
                    case 5:
                        {
                        system("CLS");
                        for(int i=0; i<c.size(); i++)
                            cout<<c.at(i)<<endl;
                        system("PAUSE");
                        system("CLS");
                        break;
                        }
                    case 6:
                        {
                        system("CLS");
                        for(int i=0; i<c.size(); i++)
                            cout<<c.at(i)<<endl;
                        int x;
                        cout<<"Introduceti indicele medicamentului pe care vreti sa il verificati(indexare de la 0)"<<endl;
                        cin>>x;
                        if(x < 0 || x >= c.size()){
                            system("CLS");
                            cout<<"Indice invalid!"<<endl;
                            system("PAUSE");
                            system("CLS");
                            break;
                            }
                        system("CLS");
                        c.at(x).esteExpirat();
                        system("PAUSE");
                        system("CLS");
                        break;
                        }
                    case 0:
                        system("CLS");
                        k3 = 0;
                        break;
                    default:{
                        system("CLS");
                        cout<<"Input invalid!"<<endl;
                        system("PAUSE");
                        system("CLS");
                        break;
                        }
                }
                }
                break;
            }
            case 4:{
                system("CLS");
                int k4 = 1;
                while(k4 == 1){
                int x4;
                cout<<"1: Creati obiect nou"<<endl;
                cout<<"2: Cititi obiect nou"<<endl;
                cout<<"3: Editati obiect deja existent"<<endl;
                cout<<"4: Stergeti obiect"<<endl;
                cout<<"5: Afisati toate obiectele existente"<<endl;
                cout<<"6: Administrati pacientului un medicament"<<endl;
                cout<<"7: Supravietuieste pacientul?"<<endl;
                cout<<"0: Inapoi"<<endl;
                cin>>x4;
                cout<<endl;
                switch(x4)
                {
                    case 1:
                        {
                        system("CLS");
                        Pacient obj;
                        d.push_back(obj);
                        break;
                        }
                    case 2:
                        {
                        system("CLS");
                        Pacient obj;
                        char aux[1];
                        cin.getline(aux, 1);
                        cin>>obj;
                        d.push_back(obj);
                        system("CLS");
                        break;
                        }
                    case 3:
                        {
                        system("CLS");
                        for(int i=0; i<d.size(); i++)
                            cout<<d.at(i)<<endl;
                        int j;
                        cout<<"Introduceti indicele obiectului pe care vreti sa il modificati(indexare de la 0)"<<endl;
                        cin>>j;
                        if(j < 0 || j >= d.size()){
                            system("CLS");
                            cout<<"Indice invalid!"<<endl;
                            system("PAUSE");
                            system("CLS");
                            break;
                        }
                        else{
                            system("CLS");
                            Pacient obj;
                            char aux[1];
                            cin.getline(aux, 1);
                            cin>>obj;
                            d.at(j) = obj;
                            system("CLS");
                            break;
                            }
                        }
                    case 4:
                        {
                        system("CLS");
                        for(int i=0; i<d.size(); i++)
                            cout<<d.at(i)<<endl;
                        int j;
                        cout<<"Introduceti indicele obiectului pe care vreti sa il stergeti(indexare de la 0)"<<endl;
                        cin>>j;
                        if(j < 0 || j >= d.size()){
                            system("CLS");
                            cout<<"Indice invalid!"<<endl;
                            system("PAUSE");
                            system("CLS");
                            break;
                        }
                        else{
                            system("CLS");
                            vector<Pacient>::iterator it = d.begin() + j;
                            d.erase(it);
                            system("CLS");
                            break;
                            }
                        }
                    case 5:
                        {
                        system("CLS");
                        for(int i=0; i<d.size(); i++)
                            cout<<d.at(i)<<endl;
                        system("PAUSE");
                        system("CLS");
                        break;
                        }
                    case 6:
                        {
                        system("CLS");
                        for(int i=0; i<d.size(); i++)
                            cout<<d.at(i)<<endl;
                        int j, k;
                        cout<<"Introduceti indicele pacientului pe care vreti sa il tratati(indexare de la 0)"<<endl;
                        cin>>j;
                        system("CLS");
                        if(j < 0 || j >= d.size()){
                            cout<<"Indice invalid!"<<endl;
                            system("PAUSE");
                            system("CLS");
                            break;}
                        for(int i=0; i<c.size(); i++)
                            cout<<c.at(i)<<endl;
                        cout<<"Introduceti indicele medicamentului pe care vreti sa il administrati pacientului(indexare de la 0)"<<endl;
                        cin>>k;
                        system("CLS");
                        if(k < 0 || k >= c.size()){
                            cout<<"Indice invalid!"<<endl;
                            system("PAUSE");
                            system("CLS");
                            break;}
                        d.at(j) = d.at(j) + c.at(k);
                        system("PAUSE");
                        system("CLS");
                        cout<<d.at(j)<<endl;
                        system("PAUSE");
                        system("CLS");
                        break;
                        }
                    case 7:
                        {
                        system("CLS");
                        for(int i=0; i<d.size(); i++)
                            cout<<d.at(i)<<endl;
                        cout<<"Introduceti ID-ul pacientului caruia vreti sa-i aflati soarta(indexare de la 0)"<<endl;
                        int j;
                        cin>>j;
                        if(j < 0 || j >= d.size()){
                            system("CLS");
                            cout<<"Indice invalid!"<<endl;
                            system("PAUSE");
                            system("CLS");
                        }
                        system("CLS");
                        if(d.at(j).supravietuieste() == true){
                                system("CLS");
                                cout<<"Pacientul a supravietuit!"<<endl;
                                system("PAUSE");
                                system("CLS");
                                break;
                            }
                        system("CLS");
                        cout<<"Pacientul a decedat"<<endl;
                        vector<Pacient>::iterator it = d.begin() + j;
                        d.erase(it);
                        break;
                        }
                    case 0:
                        system("CLS");
                        k4 = 0;
                        break;
                    default:
                    {
                        system("CLS");
                        cout<<"Input invalid!"<<endl;
                        system("PAUSE");
                        system("CLS");
                        break;
                    }
                }
                }
                break;
            }
            case 0:
                k = 0;
                system("CLS");
                break;
            default:
                system("CLS");
                cout<<"Input invalid!"<<endl;
                system("PAUSE");
                system("CLS");
                break;
        }
    }
    return 0;
}
