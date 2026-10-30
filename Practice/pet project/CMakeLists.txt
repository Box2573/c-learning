cmake_minimum_required(VERSION 3.20)

project(DesktopPet LANGUAGES CXX)

add_executable(pet
    main.cpp
    Pet.cpp
    Cat.cpp
    Dog.cpp
    PetManager.cpp
)
