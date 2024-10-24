#include "todoEvent.h"
#include <stdexcept>

// Constructor
todoEvent::todoEvent(const std::string t, const std::string d, const int dl, const int wl) {
    this->title = t;
    this->description = d;
    this->deadline = dl;
    this->workload = wl;
}

// Getter
std::string todoEvent::getTitle() const {
    return this->title;
}

std::string todoEvent::getDescription() const {
    return this->description;
}

int todoEvent::getDeadline() const {
    return this->deadline;
}

int todoEvent::getWorkload() const {
    return this->workload;
}

// Revise details
void todoEvent::revise(const std::string t, const std::string d, const int dl, const int wl) {
    if(wl < 0) {
        throw std::invalid_argument("Worklaod must be non-negative. ");
    }

    this->title = t;
    this->description = d;
    this->deadline = dl;
    this->workload = wl;
}

// Overloaded output stream operator
std::ostream& operator<<(std::ostream& os, const todoEvent& event) {
    os  << "Title: " << event.title << std::endl
        << "Description: " << event.description << std::endl
        << "Deadline(count in days): " << event.deadline << std::endl
        << "Workload Estimated(count in hours): " << event.workload << std::endl;
    return os;
}