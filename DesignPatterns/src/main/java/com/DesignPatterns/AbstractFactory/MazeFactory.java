package com.DesignPatterns.AbstractFactory;

public class MazeFactory {
    public MazeFactory(){};
    
    public Maze makeMaze() {
        return new Maze();
    }

    public Door makeDoor(Room r1, Room r2) {
        return new Door(r1, r2);
    }

    public Room makeRoom(int n) {
        return new Room(n);
    }

    public Wall makeWall() {
        return new Wall();
    }
}