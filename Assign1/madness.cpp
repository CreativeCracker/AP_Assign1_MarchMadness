#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <tr1/unordered_map>

using namespace std;
using namespace std::tr1;

typedef unordered_map <string, vector<string> > mer_map;

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
	cout<< str.substr(lastPos, pos - lastPos)<<"\t";
        // Skip delimiters.  Note the "not_of"
        lastPos = str.find_first_not_of(delimiters, pos);
        // Find next "non-delimiter"
        pos = str.find_first_of(delimiters, lastPos);
    }
	cout<<endl<<endl;
}	

mer_map *map(const char *file, mer_map *exp){
	cout<<endl<<endl<<endl;
	ifstream f;
	f.open(file);
	string omit;
	getline(f,omit, '\n');

	while(f.good()){
		int i=0;
		string key, value;
		vector <string> vec;
            //try to read key, if there is none, break
            if (!getline(f, key, ',')){
			 break;
	    }
            //read value
	    
            getline(f, value, '\n');

	    Tokenize(value,vec,",");
	    //cout<<vec[0]<<endl;
            (*exp)[key] = vec;
            
	}
	
	f.close();
	return exp;
}

int main(int argc, char *argv[]){

	if(argc<2){
		cout<<"Usage: ./madness [args]"<<endl;
		return -1;
	}

	
	mer_map  mymap,mymap2,mymap3,mymap4;
	
	map("teams.csv", &mymap);
	map("seasons.csv", &mymap2);
	map("tourney_results.csv", &mymap3);
	map("regular_season_results.csv", &mymap4);


	
	cout <<mymap.size()<< endl;
	cout <<mymap2.size()<< endl;
	cout <<mymap3.size()<< endl;
	cout <<mymap4.size()<< endl;


	return 0;
}