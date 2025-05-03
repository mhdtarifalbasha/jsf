#include <iostream>
#include <algorithm> 
#include <iomanip>
#include <string.h> 
#include <vector>
using namespace std;
#define loop for(int i=0;i<n;i++)
struct procees
{
	int id, brust_time, arrival_time,waiting_time;
};

bool compare(procees a, procees b)
{
	if (a.brust_time < b.brust_time)
		return true;
	return false;
}

int main()
{
	cout << "Enter the number of processes: \n";
	int n; cin >> n;
	vector<procees>b(n);
	vector<procees>a(n);

	loop
	{
		cout << "Enter arrival time of process " << i + 1 << ": ";
		cin >> a[i].arrival_time;
		cout << "Enter burst time of process " << i + 1 << ": ";
		cin >> b[i].brust_time;
		b[i].id = i + 1;
		cout << endl;
	}

	sort(b.begin(), b.end(), compare);
	b[0].waiting_time = 0;
	for (int i = 1; i < n; ++i)
	{
			b[i].waiting_time = (b[i - 1].waiting_time + b[i - 1].brust_time)-a[i-1].arrival_time ;
		//cout << a[i].arrival_time << "\n\n\n\n\n";
	}
	double tot = 0;
	cout << "\tGant\n";
	cout << "Id\tBrust\tArrival\tWaiting\n";
	loop
	{
		 cout << b[i].id << "\t" << b[i].brust_time << "\t" << a[i].arrival_time << "\t"<<b[i].waiting_time<<endl;
		tot = (b[i].waiting_time+tot);

	}

	cout << "TWT = " << tot << endl;
	cout << "AWT = " << tot/n << endl;
}
