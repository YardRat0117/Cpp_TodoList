#include "userInterface.h"
#include <iostream>

void userInterface::displayMenu() {
    int choice;
    do {
        std::cout << "1. Add Event\n";
        std::cout << "2. Remove Event\n";
        std::cout << "3. Revise Event\n";
        std::cout << "4. Display Events\n";
        std::cout << "5. Display Sorted Events\n";
        std::cout << "6. Load Events from File\n";
        std::cout << "7. Save Events to File\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: addEventInput(); break;
            case 2: removeEventInput(); break;
            case 3: reviseEventInput(); break;
            case 4: displayEvents(); break;
            case 5: displaySortedEvents(); break;
            case 6: loadEventsFromFile(); break;
            case 7: saveEventsToFile(); break;
        }
    } while (choice != 0);
}

void userInterface::addEventInput() {
    std::string title, description;
    int deadline, workload;
    std::cout << "Enter title: ";
    std::cin.ignore();
    std::getline(std::cin, title);
    std::cout << "Enter description: ";
    std::getline(std::cin, description);
    std::cout << "Enter deadline (in days): ";
    std::cin >> deadline;
    std::cout << "Enter workload (in hours): ";
    std::cin >> workload;
    manager.addEvent(todoEvent(title, description, deadline, workload));
}

void userInterface::removeEventInput() {
    std::string title;
    std::cout << "Enter title of the event to remove: ";
    std::cin.ignore();
    std::getline(std::cin, title);
    manager.removeEvent(title);
}

void userInterface::reviseEventInput() {
    std::string title;
    std::cout << "Enter title of the event to revise: ";
    std::cin.ignore();
    std::getline(std::cin, title);

    std::string newTitle, newDescription;
    int newDeadline, newWorkload;
    std::cout << "Enter new title: ";
    std::getline(std::cin, newTitle);
    std::cout << "Enter new description: ";
    std::getline(std::cin, newDescription);
    std::cout << "Enter new deadline (in days): ";
    std::cin >> newDeadline;
    std::cout << "Enter new workload (in hours): ";
    std::cin >> newWorkload;

    manager.reviseEvent(title, todoEvent(newTitle, newDescription, newDeadline, newWorkload));
}

void userInterface::displayEvents() {
    for (const auto& event : manager.getAllEvents()) {
        std::cout << event << std::endl;
    }
}

void userInterface::displaySortedEvents() {
    auto sortedEvents = manager.getSortedEvents();
    for (const auto& event : sortedEvents) {
        std::cout << event << std::endl;
    }
}

void userInterface::loadEventsFromFile() {
    std::string filename;
    std::cout << "Enter filename to load events from: ";
    std::cin >> filename;
    manager.loadEvents(filename);
}

void userInterface::saveEventsToFile() {
    std::string filename;
    std::cout << "Enter filename to save events to: ";
    std::cin >> filename;
    manager.saveEvents(filename);
}
