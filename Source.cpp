#include<iostream>
#include<list>
#include<vector>
#include<fstream>
#include<conio.h>
#include<string.h>
using namespace std;


class clockk {
public:
	int second;
	int hr;
	int min;

	clockk()
	{
		hr = 0;
		second = 0;
		min = 0;
	}
	void increment()
	{
		if (second < 60)
			second = second + 5;
		 if (second == 60)
		{
			if (min < 59)
				min++;
			else
				hr++;
		}
	}
	void operator=(clockk& x)
	{
		x.hr = this->hr;
		x.min = this->min;
		x.second = this->second;
	}
	void display()
	{
		
		cout << "0"<<hr << ":" <<"0"<< min << ":" <<"0"<< second;
		
	}


};
struct slot {
public:
	float price;
	bool occupied;
	string slottime;
	int slotnumber;
	clockk mytime;
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
	clockk times;
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

		for (int i = 0; i < slotlist.size(); i++)
		{
			if (slotlist[i].occupied == false)
			{
				cout << "Slot number : " << slotlist[i].slotnumber << " ";
				cout << " Slot time : ";
				slotlist[i].mytime.display();
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
			times.increment();
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
	
			cout << times.second<<" ";
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