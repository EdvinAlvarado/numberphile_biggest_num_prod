#include<iostream>
#include<string>
#include<vector>
#include<algorithm> //for reverse
#include<numeric> // accumulate
#include <functional> // multiplies
using namespace std;

int multdigits(int n) {
	int counter = 0;
	// auto strn = to_string(n);
// 	(for auto&& c_digit : strn) {
// 		int digit  = c_digit - '0' 
// 		// this changes a char into their digit int
// 	}
	// n%10 gives you the last digit
	// n/10 gives you all the digits except the last one
	vector<double> v;
	while(n>0) {
		v.push_back(n % 10);
		n /= 10;
	}
	// vector is backwards as because we put the last number first 
	reverse(v.begin(), v.end());
	// for (auto &&i: v) {
	// 	cout << i << " ";
	// }
	// cout << "\n" << v[1] << endl;
	while (v.size() != 1) {		
		// checks if element is not in vector
		if(find(v.begin(), v.end(), 1) == v.end()) {
			if(find(v.begin(), v.end(), 0) == v.end()) {
				if(find(v.begin(), v.end(), 5) == v.end()) {
					n = accumulate(v.begin(), v.end(), 1, multiplies<double>());
					// cout << n << " ";
					v.clear();
					while(n>0) {
						v.push_back(n%10);
						n/=10;
					}
					reverse(v.begin(), v.end());
					counter += 1;
					// cout << counter << " " << v.size() << endl;
				}
				else {break;}
			}
			else {break;}
		}
		else {
			// cout << counter << endl;
			break;
		}	
	}
	// cout << counter << " ";
	return counter;

}

int main() {
	int max_counter = 0;
	for (int i = 1; i <= 1e6; i++ ) {
		// cout << "i " << i << "\n";
		max_counter = max(max_counter, multdigits(i));
	}
	cout << max_counter << endl;
	
}