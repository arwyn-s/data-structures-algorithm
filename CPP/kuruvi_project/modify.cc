#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;
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
        getline(cin, station);
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
    ifstream file;
    file.open("train.dat", ios::binary );
    long pos = file.tellg();
    file.read((char *)&train, sizeof(train)); cout << train.get_station() << endl;
    file.read((char *)&train, sizeof(train)); cout << train.get_station() << endl;
    file.read((char *)&train, sizeof(train)); cout << train.get_station() << endl;
    file.seekg((~1 * sizeof(train), ios::cur));
    file.read((char *)&train, sizeof(train)); cout << train.get_station() << endl;
    file.tellg();
    file.seekg(sizeof(train),ios::beg); cout << train.get_station() << endl;
    file.read((char *)&train, sizeof(train)); cout << train.get_station() << endl;
    file.read((char *)&train, sizeof(train)); cout << train.get_station() << endl;
    file.seekg(-1*sizeof(train), ios::end); cout << train.get_station() << endl;
    file.read((char *)&train, sizeof(train)); cout << train.get_station() << endl;
    file.close();
    return 0;
}