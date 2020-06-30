// squid_blacklist_parser.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include "squid_list_adm.h"

int main()
{
    string output_file = "D:\\log\\squid\\conf_param_sites_blocked_upd.txt";
    string domain_name_file = "D:\\log\\squid\\domain_list.txt";
    string blacklist_file = "D:\\log\\squid\\conf_param_sites_blocked.txt";
    string comment = "#";
 
    squid_list_adm s_adm{ comment };

    //s_adm.get_search_templates(domain_name_file);
    //s_adm.get_source_list(blacklist_file);
    //s_adm.comment_source_list(output_file);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
