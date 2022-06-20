#include <iostream>
#include <list>
#include "dlist.cpp"
#include "hash.cpp"
#include "set.cpp"
#include<fstream>

using namespace std;

class word {
public:
    std::string s;
    word() :s("") {};
    word(std::string s1) :s(s1) {};
    bool operator==(word a) { return s == a.s; }
    bool operator!=(word a) { return s != a.s; }
    bool operator>(word a) { return s > a.s; }
    bool operator<(word a) { return s < a.s; }
    void operator=(word a) {    s = a.s; }

    unsigned long long hash() {
        unsigned long long temp = 0;
        for (int i = 0; i < s.size(); i++) {
            temp += s[i] * pow(53, i);
        }
        return temp;
    }
    friend std::ostream& operator<<(std::ostream& out, word a) {
        out << a.s;
        return out;
    }
};
int main()
{
    Set<word> Za;
    Set<word> Donbass;

    std::ifstream input;
    std::ofstream output;
    input.open("input.txt");
    output.open("output.txt");
    if (!input.is_open() || !output.is_open()) {
        std::cout << "Files not open";
        return 0;
    }
    else
    {
        int i;
        input >> i;
        for (int j = 0; j < i; j++)
        {
            std::string tmp;
            input >> tmp;
            word Duk(tmp);
            Za.add(Duk);
        }
        Za.print(output);
        output << '\n';
        input >> i;
        for (int j = 0; j < i; j++)
        {
            std::string tmp;
            input >> tmp;
            word Duk(tmp);
            Za.remove(Duk);
        }
        Za.print(output);
        output << '\n';
        input >> i;
        for (int j = 0; j < i; j++)
        {
            std::string tmp;
            input >> tmp;
            word Duk(tmp);
            Donbass.add(Duk);
        }
        Donbass.print(output);
        Set<word> SSS = Za.merge(Donbass);
        output << '\n' << "Merged: "<< '\n';
        SSS.print(output);
    }    
}