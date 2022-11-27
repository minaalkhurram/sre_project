#include<iostream>
#include<list>
#include<vector>
#include<fstream>
#include<conio.h>
#include<string.h>
#include<cmath>
#include <iomanip>
#include <cstdio>

using namespace std;

class Clock
{
	public:
	double hour, minute, second; 
public:
	Clock(); 
	Clock(double hour, double minute = 00, double second = 00);
	void tick();
	void adder(double hour, double minute, double second); 
	void displayTheCurrentTime(); 
};
Clock::Clock(): hour(00), minute(00), second(00) {}

Clock::Clock(double hour, double minute, double second): hour(hour), minute(minute), second(second) {}

void Clock::tick() {

	if (second < 59 && minute <= 59 && hour <= 23){
		second++;
	}
	else if (second >= 59 && minute < 59 && hour <= 23) {
		second = 00;
		minute++;
	}
	else if (second >= 59 && minute >= 59 && hour < 23){
		minute = 00;
		second = 00;
		hour++;
	}
	else{
		minute = 00;
		second = 00;
		hour = 00;
		cout << "We've got a new day, hopefully it's not monday!\n";
	}
}
void Clock::displayTheCurrentTime() {
	if (second <= 59 && minute <= 59 && hour <= 23)
	{
		cout << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << minute << ":" << setw(2) << setfill('0') << second << " - "<< setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << minute << ":" << setw(2) << setfill('0')<<second+05<<endl;
	}
}
struct slot {
public:
	float price;
	bool occupied;
	string slottime;
	int slotnumber;
	Clock mytime;
	slot()
	{
		price = 2;
		occupied = false;
		slottime = "00:00:00";

	}

};
class idkname {
	int totalmins;
	int totalslots;
	Clock times;
	vector<slot> slotlist;
public:
	idkname()
	{
		totalslots = 0;
		readslots();
		//shows schedule of unocupied slots
		displayschedule();
	}
	void displayschedule()
	{
		cout << " SLOT SCHEDULE \n";

		for (int i = 0,  k=0; i < slotlist.size(); i++)
		{
			if (slotlist[i].occupied == false)
			{
				cout << "Slot number : " << slotlist[i].slotnumber << " ";
				cout << " Slot time: ";
				slotlist[i].mytime.displayTheCurrentTime();
              	cout<< " " << " Slot Price :" << slotlist[i].price;
				//cout << "  Slot status : " << slotlist[i].occupied;
				cout << endl;
				
				
			}
		}

	}

	void readslots()
	{
		ifstream fin;
		fin.open("input.txt", ios::in);
		int line;
		char tmp;
		int count = 0;
		int secs = 5;
		while (!fin.eof())
		{
			times.tick();
			slot nn;
			fin >> line;
		
			nn.slotnumber = line;
			fin.get(tmp);
			fin.get(tmp);
	
			if (tmp == 42)
			{
				nn.occupied = true;
			}
			else
				nn.occupied = false;
			fin.get(tmp);
			fin >> line;
			nn.price = line;
	        
			//cout << times.second<<" ";
			nn.mytime = times;
			slotlist.push_back(nn);
			totalslots++;
			count++;
			if (count == 12)
			{
				totalmins++;
				count = 0;
			}
		

		}
	}

};

int main()
{
	idkname A;

}
