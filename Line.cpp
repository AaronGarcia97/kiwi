#include "Line.h"

using namespace std;

Line::Line(string) {
    cout << "Constructing line." << endl;
}

vector<string> Line::convert(string) {
    cout << "Converting line." << endl;
    vector<string> v;
    v.push_back("santiagoEsGay");
    return v;
}

void Line::display() {
    cout << "Line displaying stuff." << endl;
}