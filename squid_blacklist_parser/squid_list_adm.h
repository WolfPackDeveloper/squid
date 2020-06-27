#pragma once

#include <string>
#include <vector>

using namespace std;

class squid_list_adm
{
public:
	squid_list_adm(string symbol_commment);
	~squid_list_adm();

	void get_search_templates(string& St_file);
	void get_source_list(string& Sl_file);
	void comment_source_list(string& Out_file);
	void set_comment_symbol(string symbol_commment);
private:
	vector <std::string> search_templates;
	vector <std::string> source_list;
	string comment_symbol;
};