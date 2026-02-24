//committing and pushing!
//added sakura ai!
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype> 
#include <random>
#include <ctime>

typedef std::string string;

string cleanInput(string s) {
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char currentLetter){
        return std::tolower(currentLetter);
    });
    
    s.erase(std::remove_if(s.begin(), s.end(), [](unsigned char currentLetter){
        return std::ispunct(currentLetter) && currentLetter != '+' && currentLetter != '-' && currentLetter != '*' && currentLetter != '/';
    }), s.end());
    return s;
}

//randoms
std::mt19937 rng(static_cast<unsigned int>(std::time(nullptr)));



//prompting
class prompt {
    public:
        int num = 1;
        string question = "";
        prompt(int num) : num(num) {}
};

std::map<string, std::vector<string>> memory;

//Ai responding
void respond(string input) {
    if(memory.count(input)) {
        
        std::vector<string>& answers = memory[input];
        
        std::uniform_int_distribution<int> picker(0, answers.size() - 1);
        int randint = picker(rng);
        
        std::cout<<"Sakura: "<< answers[picker(rng)] <<"\n";
        
        
        
        
    } else {
        string choice = "y";
        
        while(choice == "y") {
        
        std::cout<<"Sakura: I'm not sure how to respond to that, would you happen to know?\n";
        string tempstr;
        std::cout<<"\n\t\t\t\t\t\t";
        std::getline(std::cin, tempstr);
        
        memory[input].push_back(tempstr);
        
        
        
        std::ofstream sFile("memory.txt", std::ios::app);
        sFile << input << "|" << tempstr << "\n";
        
        std::cout<<"\nSakura: Add another? (y/n) ";
        std::getline(std::cin, choice);
        
        }
        
        
        
        
        
        std::cout<<std::endl;
        std::cout << "Sakura: " << memory[input].back() << "\n";
    }
}

//useless
std::vector<string> knownWords = {
    "Hello", "my", "name", "is", "sakura", "ai", "what", "is", "on", "your", "mind", "today"
};

//loads memory
void loadMemory() {
    std::ifstream rFile("memory.txt");
    string line;
    while(std::getline(rFile, line)) {
        size_t pos = line.find("|");
        if(pos != string::npos) {
            string key = line.substr(0, pos);
            string value = line.substr(pos + 1);
            memory[key].push_back(value);
        }
    }
}

int main() {
    loadMemory();
    int pnm = 1;
    std::cout<<"Hello, my name is Sakura ai, what is on your mind today?\n";
    
    prompt* currentPrompt = new prompt(pnm);
    string ask = "";
    
    while(true) {
        std::cout<<"\n\t\t\t\t\t\t";
        std::getline(std::cin, currentPrompt->question);
        ask = cleanInput(currentPrompt->question);
        
        if(ask == "06062014") {
            break;
        }
        respond(ask);
    }
    return 0;
}
//update