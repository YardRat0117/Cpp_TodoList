#pragma once
#include <vector>
#include "todoEvent.h"
#include <fstream>
#include <algorithm>
#include <json.hpp>


class eventManager {
    private:
        std::vector<todoEvent> events;

    public:
        void loadEvents(const std::string& filename);
        void saveEvents(const std::string& filename);
        void addEvent(const todoEvent& event);
        void removeEvent(const std::string& title);
        void reviseEvent(const std::string& title, const todoEvent& updatedEvent);
        std::vector<todoEvent> getSortedEvents() const;
        const std::vector<todoEvent>& getAllEvents() const;
};