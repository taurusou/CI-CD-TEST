#include <iostream>
#include <vector>
#include <string>
/* String functions section */

// Splits a single string on separator into a vector of strings
std::vector<std::string> Split(std::string whole, std::string separator){
    std::vector<std::string> parts; // final return parts
    // invalid input
    if (whole.empty()) {            
        return parts;             
    }
    // can't split
    if (separator.empty()) {   
        parts.push_back(whole);             
        return parts; // return whole
    }

    std::size_t i = 0;
    while (true) {
        // find separator, starting at index i = 0.
        std::size_t index = whole.find(separator, i);
        // if not found, take substring [i, end)
        if (index == std::string::npos) {
            parts.push_back(whole.substr(i));
            break;
        }
        // otherwise, take the part between i and the start of the separator.
        parts.push_back(whole.substr(i, index - i));
        // update i to the first character after the matched separator.
        i = index + separator.size();
    }

    return parts;
};
            

// takes two strings and returns a new string that is the result of removing all occurrences of s2 from s1.
std::string RemoveAllSubstrings(std::string s1, std::string s2){
    // no occurrence of s2
    if (s2.empty()){
        return s1;
    }
    std::size_t i = 0;
    // if found s2
    while ((i = s1.find(s2, i)) != std::string::npos) {
        // remove this occurrence
        s1.erase(i, s2.size());              
    }
    return s1;
};

// takes two strings and returns a new string that is the result of removing the first occurrence of s2 from s1.
std::string RemoveFirstSubstring(std::string s1, std::string s2);
    


/* Vector functions section */

// Joins all strings in a vector together, using the glue string in between them
std::string Join(const std::vector<std::string>& pieces, const std::string& glue){
    std::string new_string;
    // invalid glue input
    if(glue.empty()){
        return ""; // return an empty string
    }
    new_string += pieces[0];
    for(size_t i = 1; i < pieces.size(); i++){
        new_string += glue; // glue between elements
        new_string += pieces[i];
    }
    return new_string;
};
        

// takes two vectors of integers, a and b. The function then removes elements from a if they are also in b.
// If the integer is in b, but not in a, nothing happens.
std::vector<int> MatchVectors(std::vector<int> a, const std::vector<int>& b){
    if (a.empty() || b.empty()){ // if vector(s) is/are empty
        return a;
    }
    std::size_t i = 0; // index for a
    while (i < a.size()) {
        bool matched = false;
        for (std::size_t j = 0; j < b.size(); j++){ // j index for b
            if (a[i] == b[j]) {
                a.erase(a.begin() + i);  // remove and shifts elements left
                matched = true;
                break;
            }
        }
        if (!matched){
            i++; // update index only when not matched
        }
    }
    return a;
}

// divides an input integer by 2 until it is impossible to do so, then returns the final number.
// (16 = 2 * 2 * 2 * 2 * 1 -> 1, 7 -> 7, 26 = 2 * 13 -> 13, 52 = 2 * 2 * 13 -> 13)
int RemoveTwos(int original);

// takes a vector of integers and removes all elements evenly divisible by the passed in int
std::vector<int> MultiplesFilter(std::vector<int>, int divides_by);

// returns a vector with true for even numbers and false for odd numbers
std::vector<bool> EvenMask(std::vector<int>& vec){
    std::vector<bool> mask(vec.size());
    for (std::size_t i = 0; i < vec.size(); i ++){
        if (vec[i] % 2 == 0){
            mask[i] = true;
        }
        else{
            mask[i] = false;
        }
    }
    return mask;
};

// returns a vector with true for odd numbers and false for even numbers
std::vector<bool> OddMask(std::vector<int>);

// Sums all numbers in a vector and returns the resulting value
int Sum(std::vector<int> nums);

// Multiplies all numbers in a vector together and returns the resulting value
int Product(std::vector<int> nums);

// Adds an integer n to each element of a given vector
std::vector<int> VectorPlusN(std::vector<int> v, int n);

// Multiples an integer n with each element of a given vector
std::vector<int> VectorTimesN(std::vector<int> v, int n);

// takes in two integers and returns a vector of size n with
// values n*1, n*2, n*3... up to n*m
std::vector<int> Multiples(int n, int m);

// takes an integer n that is >= 0 and returns a vector of all squares up to n^n (1^1, 2^2, 3^3, .... n^n)
std::vector<int> SquaresUntil(int n);

// takes an int, n, and returns the nth value of the fibonacci sequence (1, 1, 2, 3, 5, 8, 13, ...)
int NthFibonacci(int n);

// returns -1 if the number is negative and 1 if positive
int Sign(int num);

// takes two vectors of doubles, a and b. The function then removes elements from a if they are also in b.
// If the double is in b, but not in a, nothing happens.
std::vector<double> MatchVectors(std::vector<double> a, std::vector<double> b);

// takes a vector of doubles and removes all elements evenly divisible by the passed in double
std::vector<double> MultiplesFilter(std::vector<double>, double divides_by);

// returns a vector with true for numbers greater than the second parameters and false for those less than or equal to
std::vector<bool> GreaterMask(std::vector<double> nums, double greater_than);

// returns a vector with true for numbers less than the second parameters and false for those greater than or equal to
std::vector<bool> LessMask(std::vector<double> nums, double less_than);

// returns a vector with true for numbers greater than the second parameters and false for those less than or equal to
std::vector<bool> GreaterMask(std::vector<int> nums, int greater_than);

// returns a vector with true for numbers less than the second parameters and false for those greater than or equal to
std::vector<bool> LessMask(std::vector<int> nums, int less_than);

// Sums all numbers in a vector and returns the resulting value
double Sum(std::vector<double> nums);

// Multiplies all numbers in a vector together and returns the resulting value
double Product(std::vector<double> nums);

// Adds an double n to each element of a given vector
std::vector<double> VectorPlusN(std::vector<double> v, double n);

// Multiples an double n with each element of a given vector
std::vector<double> VectorTimesN(std::vector<double> v, double n);

// takes in two doubles and returns a vector of size n with
// values n*1, n*2, n*3... up to n*m
std::vector<double> Multiples(double n, double m);

// returns -1 if the number is negative and 1 if positive
double Sign(double num);

// adds n to each element of the vector
std::vector<double> AddN(std::vector<double>, double n);

// adds n to each element of the vector
std::vector<std::string> AddN(std::vector<std::string>, std::string n);

// subtracts n to each element of the vector
std::vector<int> SubtractN(std::vector<int>, int n);

// subtracts n to each element of the vector
std::vector<double> SubtractN(std::vector<double>, double n);

// ====================================================================

// takes an int, n, and returns the factorial of that int (n!)
int Factorial(int n)
{
	if(n>1)
		return n*Factorial(n-1);
	else
		return 1;
}

// adds n to each element of the vector
std::vector<int> AddN(std::vector<int> v, int n)
{
	for(int i=0;i<(int)v.size();i++)
	{
		v[i]+=n;
	}
	return v;
}

// ====================================================================

/*int main()
{
	std::cout << Factorial (5) <<std::endl; // printing the value
	// assert(Factorial(0) == 1) // cassert
	std::vector<int> v{1,2,3};
	std::vector<int> res = AddN(v, 5);
	for(int i=0;i<res.size();i++)
	{
		std::cout<<res[i]<<" ";
	}
}*/
