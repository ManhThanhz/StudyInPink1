/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Spring 2022
* Author: Vu Van Tien
* Date: 10.02.2022
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef studyInPink_h
#define studyInPink_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

////////////////////////////////////////////////////////////////////////
///STUDENT'S ANSWER BEGINS HERE
///Complete the following functions
///DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////



string notebook1(string ntb1) {
    // Complete this function to gain point
    ifstream file1(ntb1);
    string n1, n2;
    getline(file1, n1);
    getline(file1, n2);

    for (int i = 11; i <= 13; i++) {
        if (n1[i] < 48 || n1[i] > 57) {
            return "0000000000";
        }
    }

    int n1_num = 0;
    n1_num = stoi(n1.substr(11, 3));
    if (n1_num > 999 || n1_num < 1) {
        return "0000000000";
    }

    string result_ntb1;

    for (int i = 0; i <= 9; i++) {
        stringstream a(n2);
        int count = 0;
        for (int j = 0; j < n1_num; j++) {
            int b;
            a >> b;
            if (b == i) {
                count++;
            }
        }
        if (count >= 10) {
            count = count % 10;
        }
        result_ntb1 = result_ntb1 + to_string(count);
    }
    return result_ntb1;



    return "000000000";
}
string notebook2(string ntb2) {
    // Complete this function to gain point
    ifstream file2(ntb2);
    string n3, n4;
    getline(file2, n3);

    int cntP = 0;
    int length_n3 = n3.length();
    

    if (length_n3 != 5) {
        return "1111111111";
    }

    for (int i = 0; i < 5; i++) {
        if (n3[i] < '0' || n3[i] > '9') {
            return "1111111111";
        }
    }

    int c = stoi(n3);
    if (c < 5 || c > 100) return "1111111111";

    
    else {
        while (getline(file2, n4)) {
            int found1 = n4.find("Pink");
            int found2 = n4.find("pink");          
            while (found1 != string::npos || found2 != string::npos) {
                if (found1 != string::npos) {
                    cntP++;
                    found1 = n4.find("Pink", found1 + 1);
                }
                if (found2 != string::npos) {
                    cntP++;
                    found2 = n4.find("pink", found2 + 1);
                }
            }
        }
        
        if (cntP == 0) {
            return "0999999999";
        }

        if (cntP < 10000) {
            cntP = cntP * cntP;
        }

        int cntP_length = to_string(cntP).length();
        if (cntP_length >= 10) {
            return to_string(cntP).substr(0, 10);
        }
        else {
            string res;
            res = res + to_string(cntP);
            for (int i = 0; i < 10 - cntP_length; i++) {
                res = res + "9";
            }
            return res;
        }
    }
    return "000000000";
}

bool isPrime(int n) {
    if (n < 2)
        return false;
    for (long i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int closest_prime(int n) {
    while (isPrime(n) == false) {
        n = n + 1;
    }
    return n;
}

int closest_fibo(int n) {
    if (n <= 1) {
        return n;
    }
    int a = 1, b = 1, c = 1;
    while (c < n) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

string notebook3(string ntb3) {
    // Complete this function to gain point
    ifstream file3(ntb3);
    string n5;

    int a[10][10];
    int n5_num;

    string result_ntb3;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            file3 >> a[i][j];
            file3.ignore();
            if (a[i][j] < 0)
                a[i][j] = -a[i][j];
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (j > i) {
                a[i][j] = closest_prime(a[i][j]);
            }
            if (j < i) {
                a[i][j] = closest_fibo(a[i][j]);
            }
        }
    }


    int max_index, max;
    for (int i = 0; i < 10; i++) {
        max_index = 0;
        max = 0;
        for (int j = 0; j < 10; j++) {
            if (a[i][j] >= max) {
                max = a[i][j];
                max_index = j;
            }
        }
        if (max_index == 7 || max_index == 8) {
            max_index = 9;
        }
        result_ntb3 = result_ntb3 + to_string(max_index);
    }
    return result_ntb3;
}

string add(string pass1, string pass2) {
    string result_add;
    int reminder = 0; 
    int res;
    for (int i = 0; i < 10; i++) {
        string a, b;
        a = pass1[i];
        b = pass2[i];
        int a1 = stoi(a);
        int b1 = stoi(b);
        res = (a1 + b1 + reminder) % 10;
        result_add = result_add + to_string(res);
        if (a1 + b1 + reminder > 9) {
            reminder = 1;
        }
        else reminder = 0;
    }
    return result_add;
}

string generateListPasswords(string pwd1, string pwd2, string pwd3) {
    // Complete this function to gain point
    string result_gen;
    result_gen = result_gen + pwd1 + ';';
    result_gen = result_gen + pwd2 + ';';
    result_gen = result_gen + pwd3 + ';';
    result_gen = result_gen + add(pwd1, pwd2) + ';';
    result_gen = result_gen + add(pwd1, pwd3) + ';';
    result_gen = result_gen + add(pwd2, pwd3) + ';';
    result_gen = result_gen + add(add(pwd1, pwd2), pwd3) + ';';
    result_gen = result_gen + add(pwd1, add(pwd2, pwd3)) + ';';
    result_gen = result_gen + add(add(pwd1, pwd2), add(pwd1,pwd3));
    return result_gen;
    return "000000000";
}

bool chaseTaxi(
    int arr[100][100],
    string points,
    string moves,
    string& outTimes,
    string& outCatchUps
) {
    // Complete this function to gain point
    return true;
    return false;
}

string enterLaptop(string tag, string message) {
    // Complete this function to gain point
    ifstream file4(tag);
    string pwdL;
    string n6;
    getline(file4, n6);
    string email = n6.substr(7, n6.length() - 7);

    string n7;
    int a = 0;
    file4 >> n7 >> a;
    for (int i = 0; i < a; i++) {
        pwdL = pwdL + message;
    }
    pwdL = email + ';' + pwdL;
    return pwdL;
}

////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* studyInPink_h */
