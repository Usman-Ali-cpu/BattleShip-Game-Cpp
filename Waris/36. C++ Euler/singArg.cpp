#include <cstdio>
#include <cmath>   // including library to use mathematical functions
#include <fstream> // including library for file handling
#include <string>  // including to use string
#include <iomanip>
#include <algorithm> // inlcuding to use some algorithm
using namespace std;
#define fst first  // define const value
#define snd second // define const value

const double pi = acos(-1); // define a value of pi

double M(pair<double, double> p, pair<double, double> q) // function take two pairs of numbers of type double
{
    return p.fst * q.fst * 4 + p.snd * q.snd; // return a number of double type (first of pair p multiply by  4 and  multiply with first of pair q,
                                              // added to  second of pair p multiply by  4 and  multiply with second of pair q)
}

pair<double, double> intersect(pair<double, double> p, double theta) // this function return intersect point, of a point at a given angle
{
    pair<double, double> dir = make_pair(cos(theta), sin(theta)); //  get pair
    double mu = -2 * M(dir, p) / M(dir, dir);                     // getting location of a point
    return make_pair(p.fst + mu * dir.fst, p.snd + mu * dir.snd); // return pair, by multiply first of pair by angle with firt of given point
                                                                  // and  by multiply second of pair by angle with second of given point
}

int main(int argc, char *argv[])
{
    double d = atof(argv[1]); // taking first double value  from argument
    double d2;
    auto p1 = make_pair(1.4, -d2);            // make a pair
    double dir = atan2(10.1 + d2, 0.0 - 1.4); // getting value of tan
    auto p_init = intersect(p1, dir);         // get value of intersection of point with angle
    dir = dir - pi;
    ofstream out("output3.txt");   // file to show outputs
    out << "reflections " << endl; // placing into txt file

    for (int n = 0;; ++n)
    {
        auto p = intersect(p_init, dir);                // get intersect value
        double ref = atan2(-4 * p.fst, p.snd) + pi / 2; // get tan angle value

        dir = 2 * ref - dir - pi;
        p_init = p;

        printf("%d: (%.6f, %.6f)\n", n, p.fst, p.snd);                      // print value of pair on the console
        out << fixed << setprecision(5) << p.fst << ",\t" << p.snd << endl; // right value of pair in file

        if (-0.01 <= p.fst && p.fst <= 0.01 && p.snd > 0) // if value of first part of pair is between -0.01 and 0.01 and second is positive
        {
            printf("Number of time  = %d\n", n); // number of times the beam is reflected off
            break;                               // end the program by breaking loop
        }
    }
    return 0;
}