package com.DesignPatterns.Builder;
/**
 * Provides an interface for creating actual mazes
 * Here are no implementations
 * Subclasses of this class do the actual work
 */
public class MazeBuilder {
    protected MazeBuilder(){};

    public void buildMaze(){};

    public void buildRoom(int roomNumber){};

    public void buildDoor(int roomFrom, int roomTo){};

    public Maze getMaze(){return null;};
}