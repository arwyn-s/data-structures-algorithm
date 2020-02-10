#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>
#include <string.h>

using namespace std;

string from, to;

class railways
{
    string station;
    unsigned int distance;
    float fare;

public:
    void add_data()
    {
        cout << "Enter railway station name: ";
        //cin.ignore();
        getline(cin,station);
        cout << endl;
        cout << "Enter its distance from Jammu Tawi:";
        cin >> distance;
        cin.ignore();
        cout << endl;
    }
    void amount(int a, int b, int c)
    {
        cout << "Total distance =" << fabs((a - b)) << "\ncharges per km =" << c;
        fare = fabs((a - b)) * c;
        cout << "\nticket cost =" << fare;
        cout << endl;
    }
    unsigned int dist()
    {
        return distance;
    }
    string get_station()
    {
        return station;
    }
    void modify()
    {
        cout << "\n Enter new railway station: ";
        //cin.ignore();
        getline(cin, station);
        cout << "Enter its distance from Jammu Tawi: ";
        cin >> distance;
        cin.ignore();
    }
} train;

int main()
{
    //clrscr();
    unsigned int per_km = 5, choice, d1 = 0, d2 = 0, i;
    string station_searched;
    //cin.ignore();
    while (1)
    {
        cout << "\n\t\t\t WELCOME TO INDIAN RAILWAYS \n";
        // for (i = 0; i < 10; i++)
        // {
        //     cout << "~";
        // }
        cout << endl;
        cout << "||||||~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|||||" << endl;
        cout << "||           Enter your choice                                       ||" << endl;
        cout << "||           1 : ~ > Add new railway station                         ||" << endl;
        cout << "||           2 : ~ > Book ticket                                     ||" << endl;
        cout << "||           3 : ~ > change per km rate                              ||" << endl;
        cout << "||           4 : ~ > Modify database of train (TO DO:)               ||" << endl;
        cout << "||           5 : ~ > exit                                            ||" << endl;
        cout << "|||||~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|||||" << endl;

        //cout << endl;
        cin >> choice;
        cin.ignore();
        cout << endl;
        if (choice == 1)
        {
            ofstream of1("train.dat", ios::binary | ios::app);
            train.add_data();
            of1.write((char *)&train, sizeof(train));
            of1.close();
            //break;
        }
        if (choice == 2)
        {
            ifstream of1("train.dat", ios::binary);
            cout << "FROM: ";
            getline(cin, from);
            cout << "\nTO: ";
            getline(cin, to);
            d1 = 0; d2 =0;
            while (!of1.eof())
            {
                of1.read((char *)&train, sizeof(train));
                //cout << from << to << train.get_station() << endl;
                if (from.compare(train.get_station()) == 0)
                {
                    d1 = train.dist();
                }
                if (to.compare(train.get_station())==0)
                {
                    d2 = train.dist();
                }
                if (d1 > 0 && d2 > 0)
                {
                    train.amount(d1, d2, per_km);
                    break;
                }
            }
            if (of1.eof())
            {
                cout << "\n!!!!! stations not found check your spelling !!!!\n";
            }
            of1.close();
        }

        if (choice == 3)
        {
            cout << "Enter new per km rates: ";
            cin >> per_km;
            cin.ignore();
            cout << endl;
        }
        if (choice == 4)
        {
            cout << "Enter the railway station to be changed: ";
            //cin.ignore();
            getline(cin,station_searched);
            cout << endl;
            fstream f1("train.dat", ios::binary);
            //ofstream of1("train.dat", ios::binary);
            while (!f1.eof())
            {
                f1.read((char *)&train, sizeof(train));
                long pos = f1.tellg();
                cout << station_searched << endl;
                if (station_searched.compare(train.get_station()) == 0)
                {
                    f1.seekg((~1 * sizeof(train), ios::cur));
                    train.modify();
                    //f1.close();
                    //ofstream f1("train.dat", ios::app);
                    f1.seekp(pos, ios::beg);
                    cout << train.dist() << train.get_station()  << endl;
                    f1.write((char *)&train, sizeof(train));
                    cout << "record modified";
                    f1.close();
                    break;
                }
                else if (f1.eof())
                {
                    cout << "\n Station not found \n";
                    f1.close();
                }
            }
        }
        if (choice == 5)
        {
            cout << "\n THANK YOU FOR USING INDIAN RAILWAYS\n";
            exit(0);
        }

        if (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5)
        {
            cout << "entered wrong choice.. GOOD BYE !!!!!!\n";
            exit(0);
        }
    }

    return 0;
}
