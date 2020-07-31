//Decode given reversed ASCII encoding of a string
//Permissible characters: space, A-Z, a-z (DEC: 32, 65-90 and 97-100 respectively)
#include <iostream>
#include <algorithm>

int main()
{
    std::string rascii;
    std::cin>>rascii;
    
    std::reverse(rascii.begin(), rascii.end());
    
    std::string str;
    for(int i = 0; i < rascii.size(); ++i)
    {
		//If character is a space, between A-Z, or between a-c
		if((stoi(rascii.substr(i, 2)) == 32) || ((stoi(rascii.substr(i, 2)) >= 65) && (stoi(rascii.substr(i, 2)) <= 90)) || ((stoi(rascii.substr(i, 2)) >= 97) && (stoi(rascii.substr(i, 2)) < 100)))
        {
            str.append(1, static_cast<char>(stoi(rascii.substr(i, 2))));
            ++i;	//so the loop next iterates from the start of the next character's DEC value
        }
		//If character is between d-z
        else if((stoi(rascii.substr(i, 3)) >= 100) && (stoi(rascii.substr(i, 3)) <= 122))
        {
            str.append(1, static_cast<char>(stoi(rascii.substr(i, 3))));
            i = i + 2;
        }
    }
    std::cout<<str;
}
/*
stdin: 501611211121301101792351110100110156
stdout: Aedes aegypti

Reversed: 651011001011153297101103121112116105
65 : A, 101 : e, 100 : d, 115 : s, 32 : space, 97 : a, 103 : g, 121 : y, 112 : p, 116 : t, 105 : i
*/