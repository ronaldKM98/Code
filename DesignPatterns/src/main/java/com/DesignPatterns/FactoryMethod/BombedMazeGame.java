package com.DesignPatterns.FactoryMethod;

public class BombedMazeGame extends MazeGame {
    public BombedMazeGame() {}

    @Override
    public Wall makeWall() {
        return new BombedWall();
    }

    @Override
    public Room makeRoom(int n) {
        return new RoomWithABomb(n);
    }
}
