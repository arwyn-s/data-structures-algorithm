#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>
#include <string.h>

using namespace std;

char from[30], to[30];

class railways
{
    char station[30];
    unsigned int distance;
    float fare;

public:
    void set_val(string stat, unsigned int dist)
    {
        strcpy(station, stat.c_str());
        distance = dist;
    }
    void add_data()
    {
        cout << "Enter railway station name: ";
        cin.getline(station, 30);
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
    char *get_station()
    {
        return station;
    }
    void modify()
    {
        cout << "\n Enter new railway station: ";
        cin.getline(station, 30);
        cout << "Enter its distance from Jammu Tawi: ";
        cin >> distance;
        cin.ignore();
    }
} train;
void open_file_write()
{
    ofstream file("train.dat", ios::binary | ios::app);
    train.add_data();
    file.write((char *)&train, sizeof(train));
    file.close();
}
void find_compute(int per_km)
{
    ifstream of1("train.dat", ios::binary);
    cout << "FROM: ";
    cin.getline(from, 30);
    //cout << from << endl;
    cout << "\nTO: ";
    cin.getline(to, 30);
    //cout << to << endl;
    int d1 = 0, d2 = 0;
    while (!of1.eof())
    {
        of1.read((char *)&train, sizeof(train));
        if (strcmp(from, train.get_station()) == 0)
        {
            d1 = train.dist();
        }
        if (strcmp(to, train.get_station()) == 0)
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
int change_rate()
{
    int per_km;
    cout << "Enter new per km rates: ";
    cin >> per_km;
    cin.ignore();
    cout << endl;
    return per_km;
}

void modify_station()
{
    char station_searched[30];
    cout << "Enter the railway station to be changed: ";
    cin.getline(station_searched, 30);
    cout << endl;
    ifstream f1("train.dat", ios::binary);
    while (!f1.eof())
    {
        f1.read((char *)&train, sizeof(train));
        long pos = f1.tellg();
        if (strcmp(station_searched, train.get_station()) == 0)
        {

            train.modify();
            f1.close();
            ofstream f2("train.dat", ios::binary | ios::ate | ios::in);
            f2.seekp(pos - sizeof(train), ios::beg);
            f2.write((char *)&train, sizeof(train));
            cout << "record modified";
            f2.close();
            break;
        }
        else if (f1.eof())
        {
            cout << "\n Station not found \n";
            f1.close();
        }
    }
}
int main()
{
    unsigned int per_km = 5, choice, d1 = 0, d2 = 0, i;
    char station_searched[30];
    while (1)
    {
        cout << "\n\t\t\t WELCOME TO INDIAN RAILWAYS \n";

        cout << endl;
        cout << "||||||~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|||||" << endl;
        cout << "||           Enter your choice                                       ||" << endl;
        cout << "||           1 : ~ > Add new railway station                         ||" << endl;
        cout << "||           2 : ~ > Book ticket                                     ||" << endl;
        cout << "||           3 : ~ > change per km rate                              ||" << endl;
        cout << "||           4 : ~ > Modify database of train                        ||" << endl;
        cout << "||           5 : ~ > exit                                            ||" << endl;
        cout << "|||||~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|||||" << endl;

        //cout << endl;
        cin >> choice;
        cin.ignore();
        cout << endl;
        if (choice == 1)
        {
            open_file_write();
        }
        else if (choice == 2)
        {
            find_compute(per_km);
        }
        else if (choice == 3)
        {
            per_km = change_rate();
        }
        else if (choice == 4)
        {   
            modify_station();
        }
        else if (choice == 5)
        {
            cout << "\n~~~~~~~~~~~~~~~THANK YOU FOR USING INDIAN RAILWAYS~~~~~~~~~~~~~~~" << endl;
            //break;
            exit(0);
        }
        else
        {
            cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!WRONG CHOICE!!!!!!!!!!!!!!!!!!!!!!\n";
            continue;
        }
    }
    ifstream ifile;
    ifile.open("train.dat", ios::binary);
    cout << "~~~~~~~~~~~~" << endl;
    while (ifile)
    {
        ifile.read((char *)&train, sizeof(train));
        cout << train.get_station() << endl;
        if (ifile.eof())
            break;
    }
    ifile.close();
    return 0;
}
