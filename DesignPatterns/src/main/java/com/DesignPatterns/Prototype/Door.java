package com.DesignPatterns.Prototype;

public class Door extends MapSite {
    public Door(){}

    public Door(Room r1, Room r2){}

    public Door(Door that) {
        this.room1 = that.room1;
        this.room2 = that.room2;
        this.isOpen = that.isOpen;
    }

    public void initialize(Room r1, Room r2) {
        this.room1 = r1;
        this.room2 = r2;
        this.isOpen = false;
    };

    public Door clone() {
        return new Door(this);
    }

    public void enter(){};

    public Room otherSideFrom(Room a){return a;}

    private Room room1;
    private Room room2;
    private Boolean isOpen;
}
