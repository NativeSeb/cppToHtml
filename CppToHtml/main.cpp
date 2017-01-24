#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <sys/stat.h>
#include <locale>

using namespace std;

void writeHTMLHeader(string filename);
void writeHTMLEnd(string filename);
bool checkExistance(const string& fileName);
void readFile(const string& filename);
bool isOption(string option);
void cppTohtml(const string &fileName);
string CharToString(char * contenant);


int main(int argc, char *argv[])
{
	const string STATS = "stats";
	const string COLOR = "color";
	vector<string> params;
	bool stats{ false }, color{ false };
	list<string> files;

	for (int i = 0; i < argc; ++i) params.push_back(CharToString(argv[i]));

	for (int i = 0; i < argc; ++i)
	{
		if (isOption(params[i]))
		{
			/*string test = transform(params[i].begin(), params[i].end(), params[i].begin(), ::tolower);*/
			if (params[i] == STATS)
				stats = true;
			else if (params[i] == COLOR)
				color = true;
		}
		else
			files.push_back(params[i]);
	}

	//for_each(params[1],params[argc], [&stats, &color, &files, &STATS, &COLOR](auto c) {
	//	string n;
	//	n = *c;
	//	if (isOption(n))
	//	{
	//		if (ToLower(n) == STATS)
	//			stats = true;
	//		else if (ToLower(n) == COLOR)
	//			color = true;
	//	}
	//	else if (n != "")
	//		//On vérifie pas si n est null ou du moins pointe sur qqch. J'ai essayé quelques trucs et ca marche pas
	//		files.push_back(n);
	//});

	for_each(begin(files), end(files), [](auto n) {cppTohtml(n); });
}

void writeHTMLHeader(string filename)
{
	ofstream out{ filename.substr(0, filename.find('.') - 1) + ".html" };

	out << "<!DOCTYPE html>" << endl;
	out << "<html>" << endl;
	out << "<head> <title>" + filename + "</title> </head>";
	out << "<body>" << endl;
}

void writeHTMLEnd(string filename)
{
	ofstream out{ filename.substr(0, filename.find('.') - 1) + ".html" };
	out << "</body>" << endl;
	out << "</html>" << endl;
}

bool checkExistance(const string& fileName)
{
	return !!ifstream{ fileName };
}
void readFile(const string& filename)
{
	if (checkExistance(filename))
	{
		cout << "exist";
	}
	else
		cout << "not exist";
}
bool isOption(string option)
{
	return option[0] == '-' || option[0] == '/';
}

string CharToString(char * contenant)
{
	string NouvelleString;

	return NouvelleString = contenant;
}