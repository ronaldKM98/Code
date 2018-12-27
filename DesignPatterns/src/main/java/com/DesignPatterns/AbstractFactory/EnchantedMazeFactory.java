package com.DesignPatterns.AbstractFactory;

public class EnchantedMazeFactory extends MazeFactory {
    public EnchantedMazeFactory(){};

    public Door makeDoor(Room r1, Room r2) {
        return new Door(r1, r2);
    }

    public Room makeRoom(int n) {
        return new Room(n);
    }
}