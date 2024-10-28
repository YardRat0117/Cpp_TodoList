#pragma once
#include "todoEvent.h"
#include <stdexcept>

// Constructor
todoEvent::todoEvent(const std::string t, const std::string d, const int dl, const int wl)
    : title(t), description(d), deadline(dl), workload(wl) {}

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
void todoEvent::revise(const todoEvent& updatedEvent) {
    this->title = updatedEvent.getTitle();
    this->description = updatedEvent.getDescription();
    this->deadline = updatedEvent.getDeadline();
    this->workload = updatedEvent.getWorkload();
}

// Overloaded output stream operator
std::ostream& operator<<(std::ostream& os, const todoEvent& event) {
    os  << "Title: " << event.title << std::endl
        << "Description: " << event.description << std::endl
        << "Deadline(count in days): " << event.deadline << std::endl
        << "Workload Estimated(count in hours): " << event.workload << std::endl;
    return os;
}