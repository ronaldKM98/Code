package com.DesignPatterns.AbstractFactory;

public class Door extends MapSite {
    public Door Door(Room a, Room b){};
    public void enter(){};
    public Room otherSideFrom(Room a){};

    private Room _room1;
    private Room _room2;
    private Boolean isOpen;
}