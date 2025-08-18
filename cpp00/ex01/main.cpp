/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saslanya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 15:50:59 by saslanya          #+#    #+#             */
/*   Updated: 2025/08/17 11:28:44 by saslanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "Phonebook.hpp"

static int	usdef_compare(int letter) {
	return (std::isalnum(letter) || std::isspace(letter));
}

static bool	get_param(std::istream& in, std::ostream& out, std::string& input, int (*compare)(int)) {
	int		attempts = 3;
	bool	valid = true; 

	do {
		valid = true;
		if (attempts != 3)
			out << WrongInput << attempts << std::endl;

		out << Prompt;
		std::getline(in,input);
		if (in.eof())
			throw std::runtime_error(StreamError);
		else if (in.fail()) {
			in.clear();
			in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			valid = false;
			continue ;
		}
		else if (input.empty()) {
			--attempts;
			valid = false;
		}
		else
			for (size_t i = Start_index; i < input.length(); ++i)
				if (!compare(static_cast<unsigned char>(input[i]))) {
					valid = false;
					--attempts;
					break ;
				}
		}
		while (attempts && !valid);
	if (!attempts && !valid)
		out << AttemptsEnd;
	return valid;
}

static void	add_state(std::istream& in, std::ostream& out, Phonebook& book) {

	std::string params[5];
	
	out << std::endl << Amode << std::endl <<  FirstName;
	if (!get_param(in, out, params[0], std::isalpha))
		return ;
	out << LastName;
	if (!get_param(in, out, params[1], std::isalpha))
		return ;
	out << NickName;
	if (!get_param(in, out, params[2], usdef_compare))
		return ;
	out << PhoneNumber;
	if (!get_param(in, out, params[3], std::isdigit))
		return ;
	out << Secret;
	if (!get_param(in, out, params[4], usdef_compare))
		return ;
	book.add(params[0], params[1], params[2], params[3], params[4]);
	out << SucAdded;
}

static void	search_state(std::istream& in, std::ostream& out, const Phonebook& book) {
	int	index = Start_index;

	out << std::endl << Smode << std::endl;
	if (!book.list_print(out)) {
		out << "Empty list" << std::endl;
		return ;
	}
	out << Sselect;
	do {
		out << Prompt;
		char letter = in.get();
		if (letter == '\n') 
		   return ;
		in.putback(letter);	
		in >> index;
		if (in.eof())
			throw std::runtime_error(StreamError);
		if (in.fail()) {
			out << NonNumeric;
			in.clear();
			in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
			break ;
	} while (true);
	in.get();
	if (index)
		book.single_print(index, out);
}

static void	gmenu_state(std::istream& in, std::ostream& out) {
	Phonebook book;

	out << Gmenu ;
	do {
	std::string	input;
	out << std::endl << Select << AddInfo << SearchInfo << ExitInfo << Prompt;
	std::getline(in, input);
	if (in.bad() || in.eof())
		throw std::runtime_error("Stream closed!Crash exit");
	else if (in.fail()) {
		in.clear();
		in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	else if (input.empty())
		continue;
	else if (input == Add)
		add_state(in, out, book);
	else if (input == Search)
		search_state(in, out, book);
	else if (input == Exit)
		break ;
	} while (true);
}


int	main() {
	try {
		gmenu_state(std::cin, std::cout);
		return EXIT_SUCCESS;
	}
	catch (std::runtime_error& err) {
		std::cerr << std::endl << err.what() << std::endl;
		return EXIT_FAILURE;
	}
	catch (...) {
		std::cerr << "Undefined Error!.Crash Exit!" << std::endl;
		return EXIT_FAILURE;
	}
}
