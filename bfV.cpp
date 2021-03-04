#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

using namespace std;

char code[30000];

int main(int argc, char** argv) {
    unsigned int start_time = clock();
    vector<char> tape;
    char token;
    ifstream input(argv[1]);
    while (input) {
        input.get(token);
        tape.push_back(token);
    }
    input.close();
    unsigned int codePos = 0;
    int loop = 0;
    for (int tapePos= 0; tapePos< tape.size(); ++tapePos) {
        switch (tape[tapePos]) {
            case '>':
                codePos++;
                break;
            case '<':
                codePos--;
                break;
            case '+':
                code[codePos]++;
                break;
            case '-':
                code[codePos]--;
                break;
            case '.':
                cout << code[codePos];
                break;
            case ',':
                cin >> code[codePos];
                break;
            case '[':
            {
                if (!code[codePos]) {
                    ++loop;
                    while (loop) {
                        ++tapePos;
                        if (tape[tapePos] == '[')
                            ++loop;
                        if (tape[tapePos] == ']')
                            --loop;
                    }
                }
                break;
            }
            case ']':
            {
                if (!code[codePos])
                    continue;
                else {
                    if (tape[tapePos] == ']')
                        loop++;
                    while (loop) {
                        --tapePos;
                        if (tape[tapePos] == '[')
                            loop--;
                        if (tape[tapePos] == ']')
                            loop++;
                    }
                    --tapePos;
                }
            }
            default:
                break;
        }
    }
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;
    cout << '\n'  << search_time << '\n';
}