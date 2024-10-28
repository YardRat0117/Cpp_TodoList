#pragma once
#include "eventManager.h"

using json = nlohmann::json;

void eventManager::loadEvents(const std::string& filename) {
    std::ifstream inputFile(filename);
    if(!inputFile.is_open()) {
        std::cerr << "Cannot open file: " << filename << std::endl;
        return;
    }

    json j;
    inputFile >> j;

    for (const auto& item : j) {
        std::string title = item["title"];
        std::string description = item["description"];
        int deadline = item["deadline"];
        int workload = item["workload"];
        events.emplace_back(title, description, deadline, workload);
    }
}

void eventManager::saveEvents(const std::string& filename) {
    std::ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        std::cerr << "Cannot open file: " << filename << std::endl;
        return;
    }

    json j;
    for (const auto& event : events) {
        j.push_back({
            {"title", event.getTitle()},
            {"description", event.getDescription()},
            {"deadline", event.getDeadline()},
            {"workload", event.getWorkload()}
        });
    }

    outputFile << j.dump(4); // Format output with 4 spaces indentation
}

void eventManager::addEvent(const todoEvent& event) {
    events.push_back(event);
}

void eventManager::removeEvent(const std::string& title) {
    events.erase(std::remove_if(events.begin(), events.end(),
                [&title](const todoEvent& event) { return event.getTitle() == title; }),
                events.end());
}

void eventManager::reviseEvent(const std::string& title, const todoEvent& updatedEvent) {
    for (auto& event : events) {
        if (event.getTitle() == title) {
            event.revise(updatedEvent);
            break;
        }
    }
}

std::vector<todoEvent> eventManager::getSortedEvents() const {
    std::vector<todoEvent> sortedEvents = events;
    std::sort(sortedEvents.begin(), sortedEvents.end(), [](const todoEvent& a, const todoEvent& b) {
        int remainingTimeA = a.getDeadline() - a.getWorkload(); // Calculate remaining time
        int remainingTimeB = b.getDeadline() - b.getWorkload();
        return remainingTimeA < remainingTimeB;
    });
    return sortedEvents;
}

const std::vector<todoEvent>& eventManager::getAllEvents() const {
    return events;
}