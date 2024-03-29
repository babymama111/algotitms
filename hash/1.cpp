#include <iostream>

int simple_string_hash(std::string word);

int main(int argc, char *argv[]) {
	std::string word;
	do {
		std::cout << "Введите строку: ";
		std::cin >> word;
		std::cout << "Наивный хэш строки " << word << " = "<< simple_string_hash( word)<< std::endl;
	} while (word != "exit");
		return 0;
}

int simple_string_hash(std::string word){
	int res = 0;
	for(int i = 0; i < word.size() ;i++){
		res += static_cast<int>(word[i]);
	}
	return res;
}


//Вам нужно реализовать функцию, которая рассчитывает хэш для строки с помощью наивного алгоритма. Функция будет называться simple_string_hash.
//
//Функция должна принимать на вход строку, а возвращать хэш этой функции — целое число. Наивный алгоритм вычисления хэша строки заключается в сложении кодов всех символов строки.
//
//После написания функции её необходимо протестировать. Для этого организуйте работу с пользователем: просите его ввести строку и в ответ выводите на консоль значение хэша этой строки, посчитанного по реализованному вами алгоритму. Делайте это до тех пор, пока пользователь не введёт exit. Когда пользователь введёт exit, посчитайте хэш этой строки, выведите его на консоль и завершите работу программы.
//
//Подумайте, какая сигнатура должна быть у функции simple_string_hash.