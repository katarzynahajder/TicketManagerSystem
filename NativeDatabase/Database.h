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

struct Reservation {
	int ticketId;
	std::string username;
	std::string title;
	std::string description;
	std::string date;
	std::string category;
};

struct UserInfo {
	std::string username;
	std::string email;
	std::string password;
};

bool registerUser(const std::string& username, const std::string& email, const std::string& password);

bool userExists(const std::string& username);

bool loginUser(const std::string& username, const std::string& password);

bool insertTicket(const std::string& title, const std::string& desc, const std::string& date, int count, const std::string& category);

std::vector<Ticket> loadTickets();

bool insertReservation(const std::string& username, int ticketId);

bool decrementTicketCount(int ticketId);

bool hasUserReserved(const std::string& username, int ticketId);

std::vector<Reservation> loadReservations(const std::string& username);

int getUserTicketCount(const std::string& username);

std::vector<UserInfo> getUserInfo(const std::string& username);

bool updateUserInfo(const std::string& oldUsername, const std::string& newUsername, const std::string& email, const std::string& password);

bool cancelUserTicket(const std::string& username, int ticketId);

bool updateEvent(int eventId, const std::string& newTitle, const std::string& newDesc, const std::string& newDate, int newCount, const std::string& newCategory);

bool removeEvent(int eventId);

std::vector<Ticket> getEventInfo(int eventId);