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
	}
	void displayschedule()
	{
		cout << " SLOT SCHEDULE \n";

		for (int i = 0; i < slotlist.size(); i++)
		{
			if (slotlist[i].occupied == false)
			{
				cout << "Slot number : " << slotlist[i].slotnumber << " ";
				cout << " Slot time: ";
				slotlist[i].mytime.displayTheCurrentTime();
              	cout<< " " << " Slot Price :" << slotlist[i].price;
              	if(slotlist[i].price==50){
		         	cout<<"  Peak time!!"<<endl;
		        }
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
	
			if (tmp == 35)
			{
				nn.occupied = true;
			}
			else{
			
				nn.occupied = false;
			}
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
	bool valid(int num){
		for(int i=0; i<slotlist.size(); i++)
			{
			if(num==slotlist[i].slotnumber && slotlist[i].occupied==false){
				return true;
	        }
	        
	    }
	    return false;
	}
	void select_slot(){
		
		cout<<"Enter the slot number/numbers you want to select and press enter to exit: "<<endl;
		char check='\0';
		vector<int> number;
		int num=0;
		int i=0;
		bool exit=false;
		while(check!='e'){
			cin>>num;
			if(valid(num)){
		    number.push_back(num);
		    cout<<"Selected"<<endl;
			cout<<"Enter e to exit: ";
			cin>>check;
			if(check=='e'){
				exit=true;
			} 
		    }
		    else{
		    	cout<<"Invalid slot number!"<<" Enter again: "<<endl;
			}
			if(exit==true){
				break;
			}
		}
		cout<<"You have selected your slots that are: "<<endl;
		for(int i=0; i<number.size(); i++){
			cout<<"Slot: "<<number[i]<<endl;
		}
		char opt;
		system("cls");
		cout<<"\t\t\tPress Y to confirm your selection and generate rate card."<<endl;
		cout<<"\t\t\tPress X to change your selected slots"<<endl;
		cin>>opt;
		if(opt=='Y'){
			generate_ratecard(number);
		}
		if(opt=='X'){
			this->select_slot();
		}
		
		
	}
	void generate_ratecard(vector<int>& arr){
		cout<<"\t\t\tYour Selected time slots with prices are as follows: "<<endl;
		for(int i=0; i<arr.size(); i++){
			slotlist[arr[i]-1].occupied==true;
			cout << "\t\tSlot number : " << slotlist[arr[i]-1].slotnumber << " ";
				cout << " \t\tSlot time: ";
				slotlist[arr[i]-1].mytime.displayTheCurrentTime();
              	cout<< " " << " \t\tSlot Price :" << slotlist[arr[i]-1].price;
              	if(slotlist[arr[i]-1].price==50){
		         	cout<<"  \tPeak time!!"<<endl;
		        }
				//cout << "  Slot status : " << slotlist[i].occupied;
				cout << endl;
		}
		
	}
	void getmenu(){
		cout<<"\t\t\t\tWelcome to airtime sales system!!"<<endl;
		cout<<"\t\t\tPress 1 to get schedule of available slots."<<endl;
		cout<<"\t\t\tPress 2 to select slots."<<endl;
		
		
		int option;
		cin>>option;
		if(option==1){
			system("cls");
			displayschedule();
			
		}
		if(option==2){
			system("cls");
			displayschedule();
			select_slot();
		}
		
	}

};

int main()
{
	idkname A;
	A.getmenu();
	
	

}
