#pragma chala de compiler bhaiya!

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <tr1/unordered_map>

using namespace std;
using namespace std::tr1;

typedef vector< vector<string> > vect;
typedef unordered_map <string,string> mer;

void Tokenize(const string& str,vector<string>& tokens,const string& delimiters = " ")
{
    // Skip delimiters at beginning.
    string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    // Find first "non-delimiter".
    string::size_type pos     = str.find_first_of(delimiters, lastPos);

    while (string::npos != pos || string::npos != lastPos)
    {
        // Found a token, add it to the vector.
        tokens.push_back(str.substr(lastPos, pos - lastPos));
	//cout<< str.substr(lastPos, pos - lastPos)<<"\t";
        // Skip delimiters.  Note the "not_of"
        lastPos = str.find_first_not_of(delimiters, pos);
        // Find next "non-delimiter"
        pos = str.find_first_of(delimiters, lastPos);
    }
    //cout<<tokens.size()<<"\t";
	//cout<<endl<<endl;
}	

void vectorise(const char *file, vect& exp, const char &b){
	cout<<endl<<endl;
	ifstream f;
	f.open(file);
	string omit,line;
	getline(f,omit, '\n');

	while(f.good()){
		//cout<<lin;
		getline(f,line);

		vector <string> vec;
        
            //read value
	    //getline(f, value, '\n');
	    //cout<<line<<"\n";

	    Tokenize(line,vec,",");
	    if(vec[0] == &b)
            exp.push_back(vec);
        
	}
	//cout<<exp.size()<<endl;
	f.close();

}


void map(const char *file, mer& umap){
	ifstream f;
	f.open(file);
	string omit,lin,key;
	getline(f,omit, '\n');

	while(f.good()){
		int i=0;
		string key, value;
	//try to read key, if there is none, break
		if (!getline(f, key, ',')){
			break;
		}
	//read value
		getline(f, value, '\n');
		umap[key] = value;
	}

	f.close();
}

int main(int argc, char *argv[]){

	if(argc<2){
		cout<<"Usage: ./madness [args]"<<endl;
		return -1;
	}

	
	mer  mymap1,mymap2;
	vect myvect1, myvect2;
	const char season = *argv[1];
	cout<<season<<endl;

	map("teams.csv",mymap1);
	map("seasons.csv",mymap2);
	vectorise("regular_season_results.csv", myvect1,season);
	vectorise("tourney_results.csv", myvect2,season);

	cout <<myvect1.size()<< endl;
	cout <<myvect2.size()<< endl;
	cout <<mymap1.size()<< endl;
	cout <<mymap2.size()<< endl;


	return 0;
}