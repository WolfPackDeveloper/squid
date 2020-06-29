#include <iostream>
#include <fstream>
#include "squid_list_adm.h"

squid_list_adm::squid_list_adm(string symbol_commment)
{
	set_comment_symbol(symbol_commment);
}

squid_list_adm::~squid_list_adm()
{

}

void squid_list_adm::set_comment_symbol(string symbol_commment)
{
	comment_symbol = symbol_commment;
}

void squid_list_adm::get_search_templates(static string& St_file)
{
	ifstream search_templ_file;
	search_templ_file.open(St_file, ios_base::in);

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

// Debug
//	for (string str : search_templates)
//		std::cout << str << endl;

	search_templ_file.close();
	search_templ_file.clear();
}

void squid_list_adm::get_source_list(static string& Sl_file)
{
	ifstream source_list_file;
	source_list_file.open(Sl_file);

	if (source_list_file.is_open())
	{
		string s_source;
		while (getline(source_list_file, s_source))
		{
			source_list.push_back(s_source);
		}
	}
	else
	{
		cout << "There is no such file!" << endl;
	}

// Debug
//	for (string str : source_list)
//		std::cout << str << endl;

	source_list_file.close();
	source_list_file.clear();
}

void squid_list_adm::comment_source_list(static string& Out_file)
{
	ofstream output_file;
	output_file.open(Out_file);

	for (int i=0; i<source_list.size(); ++i)
	{

		for (string domain_templ : search_templates)
		{
			int in_domain = source_list[i].find(domain_templ);
			int commented = source_list[i].find(comment_symbol);

			// Домен .co попадает в совпадение во всех сайтах *.com. Надо это как-то обходить.
			int with_co = in_domain + domain_templ.size();
			int with_com = source_list[i].size();

			if (in_domain > 0 and commented != 0 and with_co == with_com)
			{
				source_list[i] = comment_symbol + '\t' + source_list[i];

				//Debug - Log
				std::cout << "Line number: " << i+1 << endl;
				std::cout << domain_templ << endl;
				std::cout << source_list[i] << endl;

				break;
			}
		}

	}

	for (string sl_line : source_list)
		output_file << sl_line << endl;

	output_file.close();
	output_file.clear();
}