package com.DesignPatterns.AbstractFactory;

public class MazeGame {
    public MazeGame(){};

    public Maze createMaze(MazeFactory factory) {
        Maze aMaze = factory.makeMaze();
        return aMaze;
    }
}