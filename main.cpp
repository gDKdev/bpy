#include <fstream>
#include <iostream>
#include <sstream>
#include "trim_string.hpp"

using namespace std;

int main(int argc, char **argv) {
    if (argc <= 1) {
        cout << "Bracketed Python v1.0" << endl << endl;
        cout << "Usage: bpy <input> [output]" << endl;
        cout << "input: file to convert" << endl;
        cout << "output: file to output to" << endl;
        cout << "Use ##! for shebang replacement" << endl;
    } else {
        ifstream input(argv[1]);

        stringstream brackified;
        size_t indention_level = 0;
        bool increment_indention = false;
        int skip_reduce = 0;

        for (string line; getline(input, line);) {
            // Ignore shebang to bpy
            if (line.starts_with("#!"));
                // Rewrite shebang replacement
            else if (line.starts_with("##!"))
                brackified << "#!" << line.substr(3) << endl;
            else {
                // Remove spaces after line
                rtrim(line);

                // Only reduce indention if possible
                if (indention_level > 0) {
                    if (skip_reduce > 0) {
                        skip_reduce--;
                    }
                        // Reduce indention on } and skip symbol
                    else {
                        string ltrim = ltrim_copy(line);
                        if (ltrim.starts_with('}') && indention_level > 0) {
                            auto index = lsIndex(line);
                            line = line.replace(index, index + 1, "");
                            indention_level--;
                        }
                    }
                }

                if (line.ends_with('{')) {
                    // Mark to skip next decrease indention
                    if (line.ends_with("= {")) {
                        skip_reduce++;
                    }
                        // Mark to increase indention and skip symbol
                    else {
                        increment_indention = true;
                        line = line.substr(0, line.size() - 1);
                    }
                }

                // Add indented line
                brackified << string(indention_level, '\t') << line << endl;

                // Increase indention and clear marker
                if (increment_indention) {
                    indention_level++;
                    increment_indention = false;
                }
            }
        }
        input.close();

        // Output result to console
        if (argc == 2)
            cout << brackified.str();
            // Output to file
        else {
            cout << "Output to file '" << argv[2] << "'..." << endl;
            ofstream output(argv[2]);
            output << brackified.str();
            output.flush();
            output.close();
        }
    }

    return 0;
}
