#include "Robot.h"
#include <iostream>
#include "Pet.h"
#include "Dog.h"
#include "Fish.h"
#include "Bird.h"

Robot::Robot()
    : Machine()
    , name("")
    , eyeColour("")
    , weight(0)
    , price(0)
    , colourResponse()
    , robotPet(nullptr)
{
    std::cout << "Robot " << serialNumber << " constructed!" << std::endl;
}

Robot::Robot(std::string newName, std::string newEyeColour, float newWeight, float newPrice, Pet* newPet)
    : Machine()
    , name(newName)
    , eyeColour(newEyeColour)
    , weight(newWeight)
    , price(newPrice)
    , colourResponse()
    , robotPet(newPet)
{
    std::cout << "Robot " << name << "-" << serialNumber << " constructed using parameters!" << std::endl;
}

Robot::~Robot()
{
    std::cout << "Robot " << name << "-" << serialNumber << " destroyed." << std::endl;
}

void Robot::IntroduceSelf()
{
    std::cout << "HELLO MY NAME IS " << name
        << ". I HAVE " << eyeColour << " EYES AND WEIGH "
        << weight << " WEIGHT UNITS." << std::endl
        << "I COST " << price << " POUNDS." << std::endl
        << "NICE TO MEET YOU." << std::endl;

    std::cout << "MY MEMORY ADDRESS IS " << this << std::endl;

    IntroducePet();
}

void Robot::IntroducePet()
{
    if (robotPet != nullptr)
    {
        std::cout << "I HAVE A PET NAMED " << robotPet->GetName() << std::endl;
        robotPet->Speak();
    }
    /*
    Dog* dogPet = dynamic_cast<Dog*>(robotPet);
    Fish* fishPet = dynamic_cast<Fish*>(robotPet);
    Bird* birdPet = dynamic_cast<Bird*>(robotPet);

    if (dogPet != nullptr)
    {
        std::cout << "I HAVE A DOG NAMED " << dogPet->GetName() << std::endl;
        dogPet->Speak();
    }
    if (birdPet != nullptr)
    {
        std::cout << "I HAVE A BIRD NAMED " << birdPet->GetName() << std::endl;
        birdPet->Speak();
    }
    if (fishPet != nullptr)
    {
        std::cout << "I HAVE A FISH NAMED " << fishPet->GetName() << std::endl;
        fishPet->Speak();
    }
    */
}

void Robot::AddColourResponse(std::string colour, std::string response)
{
    colourResponse[colour] = response;
}

std::string Robot::GetColourResponseFor(std::string colour)
{
    return colourResponse[colour];
}

void Robot::SetPet(Pet* newPet)
{
    robotPet = newPet;

    Dog* dogPet = dynamic_cast<Dog*>(robotPet);
    if (dogPet != nullptr)
    {
        dogPet->SetMaster(this);
    }
}

void Robot::RespondToName(std::string& playerName)
{
    std::cout << "HELLO " + playerName + "!" << std::endl;
    std::string shortName = playerName.substr(0, 3);
    std::cout << "CAN I CALL YOU " + shortName + "? (Y/N)" << std::endl;
    std::string response;
    std::cin >> response;

    if (response == "Y")
    {
        playerName = shortName;
        std::cout << "OKAY NICE TO MEET YOU " + playerName << std::endl;
    }
    else
    {
        std::cout << "OKAY I WILL CALL YOU " + playerName << std::endl;
    }
}

void Robot::CreateDog(std::string dogName)
{
    // If there is already a pet
    if (robotPet != nullptr)
    {
        // do nothing, pet already exists
        return;
    }

    // We know there is no pet
    // Create one!
    robotPet = new Dog(); // TODO: Name!
}
