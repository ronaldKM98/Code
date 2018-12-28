package com.DesignPatterns.Builder;
/**
 * Provides an interface for creating actual mazes
 * Here are general implementations
 * Subclasses of this class do the actual work
 */
public class MazeBuilder {
    protected MazeBuilder(){};

    public void buildMaze(){};
    public void buildRoom(int roomno){};
    public void buildDoor(int roomFrom, int roomRo){};
    public Maze getMaze(){return null;};
}