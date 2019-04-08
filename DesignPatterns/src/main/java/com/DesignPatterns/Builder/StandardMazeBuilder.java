package com.DesignPatterns.Builder;

/** Specific implementation of MazeBuilder
 * Only one maze at a time, no reentrant */
public class StandardMazeBuilder extends MazeBuilder {
    public StandardMazeBuilder() {
        currentMaze = null;
    }

    public void buildMaze(){
        currentMaze = new Maze();
    }

    public void buildRoom(int roomNumber) {
        if(currentMaze != null) {
            Room room = new Room(roomNumber);
            currentMaze.addRoom(room);

            room.setSide(Direction.North, new Wall());
            room.setSide(Direction.South, new Wall());
            room.setSide(Direction.East, new Wall());
            room.setSide(Direction.West, new Wall());
        }
    }
    
    public void buildDoor(int roomFrom, int roomTo) {
        Room r1 = currentMaze.roomNo(roomFrom);
        Room r2 = currentMaze.roomNo(roomTo);
        Door door = new Door(r1, r2);

        r1.setSide(commonWall(r1, r2), door);
        r2.setSide(commonWall(r1, r2), door);
    }
    
    public Maze getMaze(){
        return currentMaze;
    }

    private Direction commonWall(Room r1, Room r2){
        return Direction.North;
    }

    private Maze currentMaze;
}