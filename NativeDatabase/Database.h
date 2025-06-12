#pragma once

#include <vector>
#include <string>

struct Ticket {
	int id;
	std::string title;
	std::string description;
	std::string date;
	int count;
	std::string category;
};

bool registerUser(const std::string& username, const std::string& email, const std::string& password);

bool userExists(const std::string& username);

bool loginUser(const std::string& username, const std::string& password);

bool insertTicket(const std::string& title, const std::string& desc, const std::string& date, int count, const std::string& category);
std::vector<Ticket> loadTickets();

bool insertReservation(const std::string& username, int ticketId);

bool decrementTicketCount(int ticketId);

bool hasUserReserved(const std::string& username, int ticketId);