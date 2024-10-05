//  Created by Matheus Jatobá da Silva on 04/10/24.

//Imports
#include <iostream>
#include <random>
#include <string>
#include <chrono>
#include <thread>
#include <ctime>


//test
//Namespace definition
using namespace std;

//Declaration of Random Number Generator function:
string randomNumberGenerator(int length){
    const string CHARACTERS
    = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    
    //Creating random number generator
    random_device rd;
    mt19937 generator(rd());
    
    uniform_int_distribution<> distribution(0, CHARACTERS.size() -1);
    
    string random_string;
    for (int i = 0; i < length; ++i){
        random_string += CHARACTERS[distribution(generator)];
    }
    return random_string;
}

int main() {
    
    bool active = true;
    
    using namespace std::chrono_literals;
    while (active == true){
        time_t timestamp;
        time(&timestamp);
        
        int length = 10;
        string random_string = randomNumberGenerator(length);
        cout << ctime(&timestamp) << "Random string = " << random_string << endl;
        std::this_thread::sleep_for(5000ms);
    }
    
    return 0;
}
