#include <iostream>
#include <fstream>
#include "squid_list_adm.h"

squid_list_adm::squid_list_adm()
{
	
}

squid_list_adm::~squid_list_adm()
{

}

void squid_list_adm::get_search_templates(static string& St_file)
{
	ifstream search_templ_file;
	search_templ_file.open(St_file, ios::in);

	if (search_templ_file.is_open())
	{
		string s_templ;
		while (getline(search_templ_file, s_templ))
		{
			search_templates.push_back(s_templ);
		}
	}
	else
	{
		cout << "There is no such file!" << endl;
	}


	search_templ_file.close();
	search_templ_file.clear();
}

void squid_list_adm::get_source_list(static string& Sl_file)
{
	ifstream source_list_file;
	source_list_file.open(Sl_file);



	source_list_file.close();
}

void squid_list_adm::export_source_list(static string& Out_file)
{
	ofstream output_file;
	output_file.open(Out_file);



	output_file.close();
}

