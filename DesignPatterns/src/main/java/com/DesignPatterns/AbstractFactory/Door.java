package com.DesignPatterns.AbstractFactory;

public class Door extends MapSite {
    public Door(Room a, Room b) {
        this._room1 = a;
        this._room2 = b;
        this.isOpen = false;
    }
    public void enter(){};
    public Room otherSideFrom(Room a){return a;};

    private Room _room1;
    private Room _room2;
    private Boolean isOpen;
}