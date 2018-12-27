package com.DesignPatterns.AbstractFactory;

public class BombedMazeFactory extends MazeFactory {
    public BombedMazeFactory(){};

    public Room makeRoom(int n) {
        return new RoomWithABomb(n);
    }

    public Wall makeWall() {
        return new BombedWall();
    }
}