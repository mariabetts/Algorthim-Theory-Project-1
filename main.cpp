#include <iostream>
#include <string>
using namespace std;

class CarTypes // creating class to set up main Car Registration componenets
{
public:
    string CarRegisration;
    int CarType;
    int CarTime;
    CarTypes* pNext;
                
    CarTypes(string dCarRegistraton, char dCarType, int dCarTime) : CarRegisration(dCarRegistraton), CarTime(dCarTime),CarType(dCarTime), pNext(NULL)
    { }
    
    // classifer and constructor
    
    void showCarForCustoms() // this will show end list
    {
        cout << " Car Registration [" << CarRegisration << "] Car Type [" << CarType<< "]" << endl;
    }

};


class LinkListForCars // setting up the queue and linklist for main program
{
private: // declaring first and last for queue
   CarTypes* pFirst;
   CarTypes* pLast;

public:
    CarTypes* pFound;
    CarTypes* pBeforeFound;

    LinkListForCars() : pFirst(NULL), pLast(NULL) // constructors and finalize set up
    { }
    ~LinkListForCars() // to clear the constrcutors
    {
        CarTypes* pCurrent = pFirst;
        while (pCurrent != NULL)
        {
            CarTypes* pTemp = pCurrent;
            pCurrent = pCurrent->pNext;
            delete pTemp;
        }
    }
 
    bool isEmpty()
    {
        return pFirst == NULL;
    }

    void insertFirst(string dCarRegistration, char dCarType, int dCarTime)
    {
       CarTypes* pNewLink = new CarTypes(dCarRegistration, dCarType, dCarTime);
        if (isEmpty())
            pLast = pNewLink;

        pNewLink->pNext = pFirst;
        pFirst = pNewLink;
    }
   
    void insertLast(string dCarRegistration, char dCarType, int dCarTime)
    {
        CarTypes* pNewLink = new CarTypes(dCarRegistration, dCarType, dCarTime);
        if (isEmpty())
            pFirst = pNewLink;
        else
            pLast->pNext = pNewLink;

        pLast = pNewLink;
    }
   
    void deleteFirst()
    {
        CarTypes* pTemp = pFirst;

        if (pFirst->pNext == NULL)
            pLast = NULL;

        pFirst = pFirst->pNext;
        delete pTemp;
    }
    
    void showList()
    {
        CarTypes* pCurrent = pFirst;
        int i=0;

        if (!isEmpty()) {
            cout << "List contents:" << endl;
            while (pCurrent != NULL)
            {
                cout << "[" << i << "] >>";
                i++;

                pCurrent->showCarForCustoms();
                pCurrent = pCurrent->pNext;
            }
            cout << endl;
        }
        else cout << "No Cars are registered" << endl;
    }
}
;

void MenuForCar() // what is printed to screen
{
    cout << "Car Queue System" << endl;
    cout << "Press 1 to input a car" << endl;
    cout << "Press 2 to remove a car" << endl;
    cout << "Press 3 to print list of Cars" << endl;
    cout << "Press 4 to print list of Car Types" << endl;
    cout << "Press 5 to see current wait time to inspect" << endl;
    cout << "Press 6 to end system" << endl;
}

void Menu(int *keyPass) // ensures that input leads to function
{
    char keyOperation;
   MenuForCar();
    do {
        keyOperation = getchar();
        if ((isdigit(keyOperation) == false) && (keyOperation != '\n')) {
            cout << "You must pick a number between 1-6" << endl;
            MenuForCar();
        }
    } while (isdigit((unsigned char)keyOperation) == false);
    *keyPass = (int)keyOperation - '0';
}

string iCarRegistration;
char iCarType;
int iCarTime;
int Tcarcount = 0;
int Ccarcount = 0;
int Vcarcount = 0;

void getCarInformation() // main for car inspection, and queue alignment

{
    cout << "Input the registration of the Car" << endl;
    cin >> iCarRegistration;
    cout << "Specify what kind of car it is: T for Tourist, C for commerical, and V for VIP" << endl;
    cin >> iCarType;
    if (iCarType == 'T')
    {
        Tcarcount ++;
        cout << "Car is registered" << endl;
    }
    else if (iCarType == 'C')
    {
        Ccarcount ++;
        cout << "Car is registered" << endl;
    }

    else if (iCarType == 'V')
             
    {
        Vcarcount ++;
        cout << "Car is registered" << endl;
    }
    
    else
    {
        cout << "please input either T,C,or V" << endl;
    }
}

void PrintCarTypes() // Prints amount of Cars per type
{
    char CarCountIn;
    cout << "Which count do you want? Input T,V, or C" <<endl;
    cin >> CarCountIn;
    
    if (CarCountIn == 'T')
    {
        cout << Tcarcount;
    }
    if (CarCountIn == 'C')
    {
        cout << Ccarcount;
    }
    if (CarCountIn == 'V')
    {
        cout << Vcarcount;
    }
    
}

void  GetTimeToWait () // calculates how long it will take to inspect all cars in queue
{
    int Tcurrent = Tcarcount * 5;
    int Ccurrent = Ccarcount * 10;
    int Vcurrent = Vcarcount * 1;
    iCarTime =   Tcurrent + Ccurrent + Vcurrent;
    cout << "Time to wait is: " << iCarTime << "minutes" << endl;
    
}

int main() // final menu system
{
    int CaseKey;
    LinkListForCars InputforCars;
    LinkListForCars RemovingOfCars;

    do
    {
        Menu(&CaseKey);
        switch (CaseKey)
        {
        case 1:

                getCarInformation();
                InputforCars.insertLast(iCarRegistration, iCarType, iCarTime);
                getchar();
                getchar();
                break;
                break;
        case 2:
                cout << "This will remove the latest car in the queue" << endl;
                InputforCars.deleteFirst();
                cout << endl;
                getchar();
                getchar();
                break;
        case 3:
                cout << "This will print all Cars in queue" << endl;
                InputforCars.showList();
                getchar();
                getchar();
                break;
        case 4:
                PrintCarTypes();
                getchar();
                getchar();
                break;
        case 5:
                GetTimeToWait();
                getchar();
                getchar();
                break;
        }
                
    } while (CaseKey != 6);
        
    return 0;
    
}
