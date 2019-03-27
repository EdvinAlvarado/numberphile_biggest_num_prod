#include<iostream>
#include<string>
#include<vector>
#include<algorithm> //for reverse
#include<numeric> // accumulate
#include <functional> // multiplies
#include <chrono>
using namespace std;

int multdigits(int n) {
	int counter = 0;
	// auto strn = to_string(n);
	// (for auto&& c_digit : strn) {
	// 	int digit  = c_digit - '0' 
	// 	// this changes a char into their digit int
	// }
	// for (auto &&i: v) {
	// 	cout << i << " ";
	// }
	// cout << "\n" << v[1] << endl;			
	
	int v_parser = n;
	vector<double> v;
	while(v_parser>0) {
		v.push_back(v_parser % 10); // n%10 gives you the last digit
		v_parser /= 10; // n/10 gives you all the digits except the last one
	}
	// vector is backwards as because we put the last number first 
	reverse(v.begin(), v.end());	

	// checks if element is not in vector
	if(find(v.begin(), v.end(), 1) == v.end()) {
		if(find(v.begin(), v.end(), 0) == v.end()) {
			if(find(v.begin(), v.end(), 5) == v.end()) {
				// cout << "number: " << n << "\t";
				while (v.size() != 1) {	
					// cout << "number: " << n << "\n";	
					n = accumulate(v.begin(), v.end(), 1, multiplies<double>());
					// cout << "mult: "<< n << "\t";
					v.clear();
					v_parser = n;
					while(v_parser>0) {
						v.push_back(v_parser % 10);
						v_parser /= 10;
					}
					reverse(v.begin(), v.end());
					counter += 1;
					// cout << "counter: " << counter << "\tv_size: " << v.size() << endl;
				}
				// cout << "counter: " << counter << endl;
			}
		}
	}
	return counter;
}

int main() {
	auto start = chrono::steady_clock::now();
	int max_counter = 0;
	for (int i = 1; i <= 1e6; i++ ) {
		// cout << "i " << i << "\n";
		max_counter = max(max_counter, multdigits(i));
	}
	cout << max_counter << endl;
	auto end = chrono::steady_clock::now();
	cout << "T: " << chrono::duration_cast<chrono::milliseconds>(end-start).count() << " msec" << endl;
}