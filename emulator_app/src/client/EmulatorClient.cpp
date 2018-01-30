#include <iostream>
#include <List.h>
#include <LinkedList.h>

#include <boost/filesystem.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>

using namespace std;
using namespace boost::filesystem;
using boost::is_any_of;

int main(int argc, char **argv) {


    string line;
    do {
        getline(cin, line);

        vector<string> result;

        split(result, line, is_any_of(" "), boost::token_compress_on);



        vector<string>::iterator i;
        for (i = result.begin(); i != result.end(); i++)
            cout << *i << endl;

        cout << create_directory("/tmp/test") << endl;

    } while (line != "stop");


    return 0;
}