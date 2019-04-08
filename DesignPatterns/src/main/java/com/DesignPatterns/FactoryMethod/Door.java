package com.DesignPatterns.FactoryMethod;

public class Door extends MapSite {
    public Door(Room a, Room b) {
        this.room1 = a;
        this.room2 = b;
        this.isOpen = false;
    }
    public void enter(){};
    public Room otherSideFrom(Room a){return a;}

    private Room room1;
    private Room room2;
    private Boolean isOpen;
}
