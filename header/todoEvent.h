#pragma once
#include <iostream>
#include <string>

class todoEvent {
    private:
        std::string title;
        std::string description;
        int deadline; // count in days
        int workload; // count in hours

    public:
        todoEvent(const std::string t, const std::string d, const int dl, const int wl);

        // Getters
        std::string getTitle() const;
        std::string getDescription() const;
        int getDeadline() const;
        int getWorkload() const;

        // Method to revise event details
        void revise(const todoEvent& updatedEvent);

        // Friend function to overload output stream operator
        friend std::ostream& operator<<(std::ostream& os, const todoEvent& event);
};