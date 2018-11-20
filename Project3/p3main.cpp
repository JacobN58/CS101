#include <iostream>
#include "doList.cpp"

int main(){
	const int size = 10;
	float avgSpeed[size] = {93,99,96,97,91,100,94,98,92,95};
	float fuelEfficiency[size] = {194,201,196,196,190,200,194,198,192,193};

	doList dl = doList(avgSpeed,fuelEfficiency,size);

	cout << "First Output"<<endl;
	dl.out('d');
	//100, 98,  97,  95,  92,  91
	//200, 198, 196, 193, 192, 190

	dl.increase_speed(3,1.1);
	//100,  98.1,  95,  92,  91
	//200,  196, 193, 192, 190

	dl.decrease_fuel(8,2.1);
	//100,  98.1,  95,  92
	//200,  196, 193, 189.9

	cout << endl << "Second Output"<<endl;
	dl.out('d');
	//100, 98.1,  95,  92
	//200, 196, 193, 189.9

	dl.increase_speed(3,3.0);
	//101.1, 95,  92
	//196,  193, 189.9

	// cout << endl << "Third Output"<<endl;
	// dl.out(2,'d');
	// //101.1, 95,  92
	// //196,  193, 189.9
	//
	// dl.insert(98.0, 195);
	// //101.1, 98,  95,  92
	// //196,  195, 193, 189.9
	//
	// cout << endl << "Last Output"<<endl;
	// dl.out('a');
	// //101.1, 98,  95,  92
	// //196,  195, 193, 189.9

	return 0;
}

/*
Output should be:
First Output
Speed 100  Fuel 200
Speed 98  Fuel 198
Speed 97  Fuel 196
Speed 95  Fuel 193
Speed 92  Fuel 192
Speed 91  Fuel 190

Second Output
Speed 100  Fuel 200
Speed 98.1  Fuel 196
Speed 95  Fuel 193
Speed 92  Fuel 189.9

Third Output
Speed 101.1  Fuel 196
Speed 95  Fuel 193

Last Output
Speed 101.1  Fuel 196
Speed 98  Fuel 195
Speed 95  Fuel 193
Speed 92  Fuel 189.9
*/
