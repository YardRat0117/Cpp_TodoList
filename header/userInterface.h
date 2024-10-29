#pragma once
#include "eventManager.h"

class userInterface {
private:
    eventManager eventManager;

public:
    void displayMenu();
    void addEventInput();
    void removeEventInput();
    void reviseEventInput();
    void displayEvents();
    void displaySortedEvents();
    void loadEventsFromFile();
    void saveEventsToFile();
};
