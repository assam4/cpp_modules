/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saslanya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:07:59 by saslanya          #+#    #+#             */
/*   Updated: 2025/08/16 20:51:24 by saslanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Contact.hpp"
# include "Phonebook.hpp"

const std::string	Prompt = "> ";
// General Menu outputs
const std::string	Gmenu = "General Menu\n";
const std::string	Add = "ADD";
const std::string	Search = "SEARCH";
const std::string	Exit = "EXIT";
const std::string	Select = "Please enter one of the following commands\n";
const std::string	AddInfo = " ADD: for add a new contact\n";
const std::string	SearchInfo = " SEARCH: for search and for view contacts\n";
const std::string	ExitInfo = " EXIT: for quit the program\n";
// Search mode outputs
const std::string	Smode = "Search Mode\n";
const std::string	Sselect = "For complete information, select the contact index: (or press enter)";
const std::string	NonNumeric = "Invalid index. Input only digits!\n";
const std::string	Index_error = "Incorrect index";
// Add mode outputs
const std::string	Amode = "Add Mode\n";
const std::string	WrongInput = "Wrong Input.Try again!. attempts count : ";
const std::string	AttemptsEnd = "Attempts end. Back to General Menu\n";
const std::string	FirstName = "Insert First Name";
const std::string	LastName = "Insert Last Name";
const std::string	NickName = "Insert NickName";
const std::string	PhoneNumber = "Insert PhoneNumber";
const std::string	Secret = "Insert Secret";
const std::string   SucAdded = "Contact successfully added to phone book\n";

// Simulation constants
const std::string	StreamError = "Stream closed! Crash exit";
const size_t		Required_length = 10;
const int			Start_index = 0;
