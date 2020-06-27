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

// Debug
	for (string str : search_templates)
		std::cout << str << endl;

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
	for (string str : source_list)
		std::cout << str << endl;

	source_list_file.close();
	source_list_file.clear();
}

void squid_list_adm::comment_source_list(static string& Out_file)
{
	ofstream output_file;
	output_file.open(Out_file);

	for (string s_templ : search_templates)
		for (string s_line : source_list)
		{
			// Если запись включает "шаблон" (домен верхнего уровня) и уже не закомментирована - комментируем.
			if ((s_line.find(s_templ)) > 0 and (s_line.find(comment_symbol) < 0))
				std::cout << comment_symbol << '\t' << s_line << endl;
			else
				std::cout << s_line << endl;
		}

	output_file.close();
	output_file.clear();
}