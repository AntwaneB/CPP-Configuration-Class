### C++ Configuration Class

This project is a small class designed during my 2nd year of studies (2015) that provides a super easy and convenient way to store and access configuration keys.

It supports the following types:

 - bool
 - char
 - short
 - int
 - long
 - double
 - float
 - std::string

And it is very easy to add new ones.

### Usage example

Code:

    int main(void)
    {
    	Config	cfg;

    	cfg["mybool"] = false;
    	cfg["myint"] = 42;
    	cfg["mydouble"] = 42.42;
    	cfg["player"]["health"]["current"] = 42;
    	cfg["player"]["health"]["max"] = 100.05;

    	bool mybool = cfg["mybool"];
    	int myint = cfg["myint"];
    	double mydouble = cfg["mydouble"];
    	int current_player_health = cfg["player"]["health"]["current"];
    	double max_player_health = cfg["player"]["health"]["max"];

    	std::cout << "Value of 'mybool' : '" << mybool << "'" << std::endl;
    	std::cout << "Value of 'myint' : '" << myint << "'" << std::endl;
    	std::cout << "Value of 'mydouble' : '" << mydouble << "'" << std::endl;
    	std::cout << "Value of 'current_player_health' : '" << current_player_health << "'" << std::endl;
    	std::cout << "Value of 'max_player_health' : '" << max_player_health << "'" << std::endl;

    	return 0;
    }

Output:

    Value of 'mybool' : '0'
    Value of 'myint' : '42'
    Value of 'mydouble' : '42.42'
    Value of 'current_player_health' : '42'
    Value of 'max_player_health' : '100.05'

