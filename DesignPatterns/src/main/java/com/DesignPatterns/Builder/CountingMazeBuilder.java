package com.DesignPatterns.Builder;

public class CountingMazeBuilder extends MazeBuilder {
    public CountingMazeBuilder() {
        rooms = 0;
        doors = 0;
    }

    public void buildMaze(){}
    public void buildRoom(int roomno){
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