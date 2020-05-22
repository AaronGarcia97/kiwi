#include "IO.h"

using namespace std;

IO::IO() {
    cerr << "IO constructor." << endl;
    is_ascendente_ = true;
}

void IO::add_line(Line line) {
    lines_.push_back(line);
}

void IO::display_datos() {
    for(auto& line : lines_)
        line.display();
}

vector<vector <string> > IO::vector_string_lines() {
    vector<vector <string> > v;
    for(auto& line : lines_){
        v.push_back(line.object());
    }
    return v;
}

// INPUT methods
Input::Input() {
    cerr << "Input constructor." << endl;
}

string clean_input_string(string str) {
    // remove " and . and make it lower case.
    string trimmed_str = str.substr(1, str.length()-3);
    transform(trimmed_str.begin(), trimmed_str.end(), trimmed_str.begin(), ::tolower);
    return trimmed_str;
}

// pedir nomrbe de archivo y leer de ahi


// reads data lines from stdin till EOF
vector<Line> leer_lineas() {
    vector<Line> v;
    string archivo, string_line;
    cout << "Archivo: ";
    cin >> archivo;
    ifstream infile(archivo);

    while (getline(infile, string_line)) {
        // no la limpio porque el profe deicidio cambiar el input
        string trimmed_line = string_line; // clean_input_string(string_line);
        Line line = Line(trimmed_line, Line::convert_to_vector(trimmed_line));
        v.push_back(line);
    }
    return v;
}

// reads stop words
void leer_stops(unordered_set<string>& set) {
    string archivo, stop;
    cout << "Archivo: ";
    cin >> archivo;
    ifstream infile(archivo);
    while (infile >> stop) set.insert(stop);
    
    // display stops
    // cerr << "stops: " << endl;
    // for( auto& stop : set)
    //    cerr << stop << endl;
}

// le si es ascendiente o no
bool leer_ascendencia() {
    string c;
    cout << "Ascendente? (y/n): ";
    cin >> c;
    return tolower(c[0]) == 'y';
}

// pregunta que lineas borrar
void IO::borrar_lineas(vector<Line>& lines) {
    string lineas_a_borrar;
    cout << "Lineas a borrar seaparadas con commas (e.g. 1,2,3): ";
    cin >> lineas_a_borrar;

    vector<string> v_lineas_a_borrar;
    unordered_set<int> s_lineas_a_borrar;
    vector<Line> new_lines;

    Line::split(lineas_a_borrar, ',', back_inserter(v_lineas_a_borrar));
    for(auto& num_string : v_lineas_a_borrar)
        s_lineas_a_borrar.insert(stoi(num_string));

    for(int i = 0; i < lines.size(); i++) {
        if(s_lineas_a_borrar.find(i+1) == s_lineas_a_borrar.end()) {
            new_lines.push_back(lines[i]);
        }
    }

    lines = new_lines;
}

void IO::display_numbered_lines(vector<Line> lines) {
    int i = 1;
    for(auto& line : lines) {
        cout << to_string(i++) << " " << line.original_string() << endl;
    }
}

void Input::filtrar_stop_words(){
    cerr << "Filtrando palabras con stops." << endl;
    vector <Line> new_lines;
    for(auto& line : lines_) {
    vector<string> string_line; 
        for(auto& word : line.object()) {
            if (stop_words_.find(word) == stop_words_.end())
                string_line.push_back(word);
        }
    new_lines.push_back(Line(Line::convert_to_string(string_line, " "), string_line));
    }
    lines_ = new_lines;
}

void Input::pedir_datos() {
    cerr << "Pidiendo datos a usuario." << endl;
    lines_ = leer_lineas();
    cerr << "Lineas leidas:" << endl;
    display_numbered_lines(lines_);
    borrar_lineas(lines_);
    display_numbered_lines(lines_); // new lines after deleting
    leer_stops(stop_words_);
    is_ascendente_ = leer_ascendencia();
    filtrar_stop_words();
    cerr << "Lineas filtradas:" << endl;
    display_datos();
}

Output::Output() {
    cerr << "Output constructor." << endl;
}

Output::Output(vector<Line> lines) {
    cerr << "Output receiving vector<Line> constructor." << endl;
    lines_ = lines;
}

// lexicogrphical comparator
//(Hotfix): Instead of adding const to each parameter,const at the end tells the
// the compiler explicitly that this funtion doesn't modify any member.
struct less_than_line {
    inline bool operator() (Line& line1, Line& line2) const {
            return 
                lexicographical_compare(
                    line1.original_string().begin(),
                    line1.original_string().end(),
                    line2.original_string().begin(),
                    line2.original_string().end());
    }
};

// reverse vector eceived in-place
void reverse_vector(vector<Line>& lines) {
    cerr << "Reverseando datos." << endl;
    reverse(lines.begin(), lines.end());
}

// TODO: figure out if we should just modify private variable and return void instead.
void Output::alter_lines() {
    cerr << "Alterando datos del output." << endl;
    modified_lines_ = lines_;
    sort(modified_lines_.begin(), modified_lines_.end(), less_than_line());
    if(!is_ascendente()) reverse_vector(modified_lines_);
    display_numbered_lines(modified_lines_);
    borrar_lineas(modified_lines_);
}

// Displays modified lines
void Output::display_datos_debug(vector<Line> lines) {
    for(auto& line : lines)
        line.display();    
}

void Output::display_datos() {
    cout << "---------EXPECTED OUTPUT---------" << endl;
    for(auto& line : modified_lines_)
        cout << line.original_string() << endl;
    cout << "-----------END OUTPUT------------" << endl;
}