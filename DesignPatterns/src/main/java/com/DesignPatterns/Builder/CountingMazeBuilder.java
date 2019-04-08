package com.DesignPatterns.Builder;

/** Specific implementation of Maze Builder, this one only
 * counts the number of instances requested but actually doesn't create them
 */
public class CountingMazeBuilder extends MazeBuilder {
    public CountingMazeBuilder() {
        rooms = 0;
        doors = 0;
    }

    public void buildMaze(){}

    public void buildRoom(int roomNumber){
        rooms++;
    }

    public void buildDoor(int roomFrom, int roomTo){
        doors++;
    }

    public void addWall(int a, Direction dir){}

    public int [] getCounts(){
        int [] a = {doors, rooms};
        return a;
    }

    private int doors;
    private int rooms;
}