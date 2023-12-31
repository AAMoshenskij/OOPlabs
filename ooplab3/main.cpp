#include <iostream>
#include "trapez.h"
#include "square.h"
#include "rectangle.h"

using std::cin;
using std::cout;
using std::endl;

#define FIGURE_COUNT 3

// Trapez Square Rectangle

int main() {

    try {

        Figure** figs = new Figure* [FIGURE_COUNT];

        Trapez t1;
        cin >> t1;
        double sq1 = t1; // square of Trapez t
        cout << "Trapez square: " << sq1 << endl;
        double sq2 = t1.figure_square_calc();
        cout << "Trapez square: " << sq2 << endl;
        t1.geo_center_calc();

        Trapez t2 = t1;
        cout << t2;

        cout << "Trapez3: " << endl;
        Trapez t3(1, 1, 3, 3, 5, 0);
        cout << t3;

        bool eq1 = (t1 == t2);
        cout <<  "eq1: "<< eq1 << endl;

        Square s1;
        cin >> s1;
        sq1 = s1; // square of square s1
        cout << "Square's square: " << sq1 << endl;
        s1.geo_center_calc();

        Square s2(1, 1, 3, 1, 1, 3, 3, 3);
        cout << s2;

        Square s3 = s2;

        bool eq2 = (s1 == s2);
        cout <<  "eq2: "<< eq2 << endl;

        Rectangle r1;
        cin >> r1;
        sq1 = r1; // square of square s1
        cout << "Rectangle's square: " << sq1 << endl;
        s1.geo_center_calc();

        Rectangle r2 = r1;
        cout << r2;

        bool eq3 = (r1 == r2);
        cout <<  "eq3: "<< eq3 << endl << endl;


        cout << "///////////////////////////////////////////////////////" << endl << endl;

        double total_sq = 0;

        figs[0] = &t1;
        figs[1] = &s1;
        figs[2] = &r1;
        int size = FIGURE_COUNT;

        for(int i = 0; i < size; ++i) {
            figs[i]->geo_center_calc();
            double sq = figs[i]->figure_square_calc();
            total_sq += sq;
        }

        cout << "total square: " << total_sq << endl << endl;

        
        cout << "Input the index of element to remove: ";
        int idx;
        cin >> idx;
        --idx;
        if(idx >= 0 && idx < size) {
            Figure** figs_new = new Figure*[size - 1];
            int dif = 0;
            for(int j = 0; j < size; ++j) {
                if(j ==  idx) {
                    dif = 1;
                    continue;
                }
                figs_new[j - dif] = figs[j];
            }
            --size;
            total_sq = 0;
            for(int i = 0; i < size; ++i) {
                figs_new[i]->geo_center_calc();
                double sq = figs_new[i]->figure_square_calc();
                total_sq += sq;
            }
            delete[] figs_new;
        }
        else {
            cout << "Invalid index!" << endl;

        }
        delete[] figs;
    } 
    catch(...) {
        cout << "Invalid input data!" << endl;
    }

    Square s;
    Rectangle r = s;

    return 0;
}

