#include <iostream>
#include <string>
#include <ctime>

using namespace std;

//variables for sound representation
const string S_DOT = "\a"; //represents .
const string S_BAR = "\a\a\a"; //represents -

/**
pauses the program for sec seconds
@param sec number of seconds
*/
inline void timeSleep(clock_t sec)
{
    clock_t start_time = clock();
    clock_t end_time = sec * 1000 + start_time;
    while(clock() != end_time);
}

/**
pauses the program for 1 second
*/
inline void shortPause()
{
    timeSleep(1);
}

/**
pauses the program for 2 seconds
*/
inline void longPause()
{
    timeSleep(2);
}

/**
takes the Morse code and makes the sound representation
@param s string in Morse code
*/
void sound(string s)
{
    for(int i = 0; i < s.length(); i++)
    {
        if(s.substr(i,1) == ".")
        {
            cout << S_DOT;
            shortPause();
        }
        else if(s.substr(i,1) == "-")
        {
            cout << S_BAR;
            shortPause();
        }
        else //incorrect input
        {
            break;
        }
    }
}

/**
takes the ASCII decimal number of a character and prints its Morse code
@param a ASCII number of a character
@rturn the Morse code representation
*/
string morse_code(int a)
{
    if(a > 64 && a < 91)//capital letters
    {
        int n = (a - (int)'A' + 1);
        switch(n)
        {
        case 1: return ".-";//A
        case 2: return "-...";//B
        case 3: return "-.-.";//C
        case 4: return "-..";//D
        case 5: return ".";//E
        case 6: return "..-.";//F
        case 7: return "--.";//G
        case 8: return "....";//H
        case 9: return "..";//I
        case 10: return ".---";//J
        case 11: return "-.-";//K
        case 12: return ".-..";//L
        case 13: return "--";//M
        case 14: return "-.";//N
        case 15: return "---";//O
        case 16: return ".--.";//P
        case 17: return "--.-";//Q
        case 18: return ".-.";//R
        case 19: return "...";//S
        case 20: return "-";//T
        case 21: return "..-";//U
        case 22: return "...-";//V
        case 23: return ".--";//W
        case 24: return "-..-";//X
        case 25: return "-.--";//Y
        case 26: return "--..";//Z
        default: return "";
        }
    }
    else if(a > 96 && a < 123)//small letters
    {
        int n = (a - (int)'a' + 1);
        switch(n)
        {
        case 1: return ".-";//a
        case 2: return "-...";//b
        case 3: return "-.-.";//c
        case 4: return "-..";//d
        case 5: return ".";//e
        case 6: return "..-.";//f
        case 7: return "--.";//g
        case 8: return "....";//h
        case 9: return "..";//i
        case 10: return ".---";//j
        case 11: return "-.-";//k
        case 12: return ".-..";//l
        case 13: return "--";//m
        case 14: return "-.";//n
        case 15: return "---";//o
        case 16: return ".--.";//p
        case 17: return "--.-";//q
        case 18: return ".-.";//r
        case 19: return "...";//s
        case 20: return "-";//t
        case 21: return "..-";//u
        case 22: return "...-";//v
        case 23: return ".--";//w
        case 24: return "-..-";//x
        case 25: return "-.--";//y
        case 26: return "--..";//z
        default: return "";
        }
    }
    else if(a > 47 && a < 58)//digits
    {
        int n = (a - (int)'0');
        switch(n)
        {
        case 0: return "-----";
        case 1: return ".----";
        case 2: return "..---";
        case 3: return "...--";
        case 4: return "....-";
        case 5: return ".....";
        case 6: return "-....";
        case 7: return "--...";
        case 8: return "---..";
        case 9: return "----.";
        default: return "";
        }
    }
    else if(a==33)//\!
    {
        return "-.-.--";
    }
    else if(a==46)//.
    {
        return ".-.-.-";
    }
    else if(a==63)//?
    {
        return "..--..";
    }
    else return "Incorrect input!";
}

int main()
{
    //reads the input data and puts it into a string
    string input;
    getline(cin,input);

    //for every character of the input prints it in Morse code, then represents it as sound
    for(int i = 0; i < input.length(); i++)
    {
        if((int)input[i] != 32)//not a space
        {
            cout << morse_code((int)input[i]) << " ";
            sound(morse_code((int)input[i]));
        }
        else//if it is a space make a longer pause
        {
            longPause();
        }
    }
    return 0;
}
