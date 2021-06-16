//
//  Runner.cpp
//  Project 5 - Templates

#ifndef RUNNER_CPP // check if class is not already define 
#define RUNNER_CPP // define class 

#include <cstdlib>  // to use built in function 
#include <iomanip>  // library for output format 
#include "Vect.cpp" // including vector class 
using namespace std;


template <class T> // templating class Runner 
class Runner {
public:
    // Name: Default Constructor
    // Precondition: None
    // Postcondition: Initiates state/environment
    Runner(Vector<T>*v1, Vector<T>*v2){
        this->m_vector1 = v1;
        this->m_vector2 = v2;
        this->working();
    }

    // Name: mainMenu
    // Desc: Main Menu
    // Precondition: Existing Vectors
    // Postcondition: Handles various menu commands
    int mainMenu(){
        // options in main menu 
        cout << "\nChoose an option " << endl;
        cout << "1. Display Vectors " << endl;
        cout << "2. Vector comparison(<)" << endl;
        cout << "3. Vector comparison(==)" << endl;
        cout<<  "4. Vector addition"<< endl;
        cout << "5. Vector multiplication" << endl;
        cout << "6. Compute median" << endl;
        cout << "7. Compute mean:" << endl;
        cout << "8. Compute Standard Derivation" << endl;
        cout << "9. Exit" << endl;
        int input;  // for input choice 
        cout << "Enter your choice : ";
        cin >> input; 
        return input; // returning choice 
    }

    void working(){
        int x = 0;
        while (x <= 9){
            int choice = mainMenu(); // getting choice from main menu what user Entered
            switch (choice) // switching choice 
            {
            case 1:  // if choice is 1
            {
                cout << "Vector1: ";
                m_vector1.Display(); // display first vector 
                cout << "Vector2: ";
                m_vector2.Display(); // display second vector  
            }
            break;
            case 2: // if choice is 2
            {   
                Vector<char> v;
                v = m_vector1 < m_vector2;  // using overloaded operator < 
                // if value will be less than than at that index it would display T otherwise F
                cout<< "Vector1 < Vector2 :  ";
                v.Display();
            } 
            break;
            case 3:  // if choice is 3
            { 
                Vector<char> v;
                v = m_vector1 == m_vector2; // using overloaded operator ==
                // if value will be equal  at that index it would display T otherwise F
                cout<< "Vector1 == Vector2 :  ";
                v.Display();
            } 
            break;
            case 4:  // if choice is 4
            { 
                Vector<T> v; 
                v = m_vector1 + m_vector2; // using overloaded operators placing sum of two vector in one vector 
                cout<< "Vector1 + Vector2 :  ";
                v.Display();  // display sum vector 
            } 
            break;
            case 5:  // if choice is 5
            { 
                Vector<T> v;
                v = m_vector1 * m_vector2; // using overloaded operators placing multiply of two vector in one vector 
                cout<< "Vector1 x Vector2 :  ";
                v.Display();   // display multiplied  vector 
            } 
            break;
            case 6: // if choice is 6
            {
                // displaying median of vectors
                cout << "Median of Vector1: " <<fixed<<m_vector1.Median() << endl;
                cout << "Median of Vector2: " << fixed<<m_vector2.Median() << endl;
            }
            break;
            case 7: // if choice is 7
            {
                // displaying mean of vectors
                cout << setprecision(4)<< "Mean of Vector1: " << m_vector1.Mean() << endl;
                cout << setprecision(4)<< "Mean of Vector2: " << m_vector2.Mean() << endl;
            }
            break;
            case 8: // if choice is 8
            {
                // displaying Standard derivation of vectors
                cout << setprecision(4)<<fixed<< "Standard derivation of Vector1: " << m_vector1.StDev() << endl;
                cout << setprecision(4)<<fixed<< "Standard derivation of Vector2: " << m_vector2.StDev() << endl;
            }
            break;
            case 9: // if choice is 9
            {
                exit(0); // end program
            }
            break;
            default: // if any choice else 1-9
                cout << "Invalid input ! " << endl;
                break;
            }
        }
    }

private:
    Vector<T> m_vector1; // private vector
    Vector<T> m_vector2; // private vector 
};

// **** Add class definition below ****


#endif /* Runner_h */


