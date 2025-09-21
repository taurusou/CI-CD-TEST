#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
std::vector<std::string> Split(std::string whole, std::string separator);
std::string RemoveAllSubstrings(std::string s1, std::string s2);
std::string Join(const std::vector<std::string>& pieces, const std::string& glue);
std::vector<int> MatchVectors(std::vector<int> a, const std::vector<int>& b);
std::vector<bool> EvenMask(std::vector<int>& vec);

#include <vector>
#include <string>

// test case for Split
TEST_CASE ("splitting a string on a separator", "[Split]")
{
    SECTION("multi-char separator") {
        auto res = Split("a--b--c", "--");
        REQUIRE(res == std::vector<std::string>{"a","b","c"});
    }
    SECTION("edge case 1: empty input returns empty vector") {
        auto res = Split("", ",");
        REQUIRE(res.empty());
    }
    SECTION("edge case 2: empty separator returns whole string as one part") {
        auto res = Split("hello", "");
        REQUIRE(res == std::vector<std::string>{"hello"});
    }
}

// test case for RemoveAllSubstrings
TEST_CASE ("remove all occurrences of s2 from s1", "[RemoveAllSubstrings]"){
    SECTION("basic removal") {
        REQUIRE(RemoveAllSubstrings("abcabc", "ab") == "cc");
    }
    SECTION("edge case: empty s2 leaves s1 unchanged") {
        REQUIRE(RemoveAllSubstrings("hello", "") == "hello");
    }
}

// test case for Join
TEST_CASE ("use the glue to join a string", "[Join]"){
    SECTION("basic join") {
        std::vector<std::string> v{"a","b","c"};
        REQUIRE(Join(v, "-") == "a-b-c");
    }
    SECTION("edage case 1:single element") {
        std::vector<std::string> v{"x"};
        REQUIRE(Join(v, ",") == "x");
    }
    SECTION("glue empty") {
        std::vector<std::string> v{"a","b"};
        REQUIRE(Join(v, "") == "");
    }
}

// test case for MatchVectors
TEST_CASE ("remove elements of a if they appear in b", "[MatchVectors]"){
    SECTION("multiple elements to remove") {
        std::vector<int> a{1,2,2,3,4};
        std::vector<int> b{2,5};
        auto res = MatchVectors(a, b);
        REQUIRE(res == std::vector<int>{1,3,4});
    }
    SECTION("if b empty, a unchanged") {
        std::vector<int> a{9,8,7};
        std::vector<int> b{};
        auto res = MatchVectors(a, b);
        REQUIRE(res == a);
    }
}

// test case for EvenMask
TEST_CASE ("a vector with true for even numbers otherwise false", "[EvenMask]"){
    std::vector<int> v{-2,-1,0,1,2};
    auto mask = EvenMask(v); 
    REQUIRE(mask == std::vector<bool>{true,false,true,false,true});
}
    
/*TEST_CASE ( "Factorials are computed", "[factorial]") // tag
{
  CHECK( Factorial(0) == 1 ); // assertion
  REQUIRE( Factorial(1) == 1 );
  REQUIRE( Factorial(2) == 2 );
  REQUIRE( Factorial(3) == 6 );
  REQUIRE( Factorial(10) == 3628800 );
}

TEST_CASE("incrementing values in integer vector", "[addN]")
{
	std::vector<int> v{1,2,3,5,6,7,8,10};

	SECTION("checking with +ve n")
  {
		int n=5;
		std::vector<int> res = AddN(v, n);
		srand(time(NULL));
		int random = rand()%v.size();
		REQUIRE(v.size() == res.size());
		REQUIRE( res[0] == 6 );
		REQUIRE( res[v.size()-1] == 15 );
		REQUIRE(res[random] == v[random]+n);
	}
	SECTION("checking with -ve n")
  {
		int n=-5;
		std::vector<int> res = AddN(v, n);
		srand(time(NULL));
		int random = rand()%v.size();
		REQUIRE(v.size() == res.size());
		REQUIRE( res[0] == -4 );
		REQUIRE( res[v.size()-1] == 5 );
		REQUIRE(res[random] == v[random]+n);
	}

}*/
//
