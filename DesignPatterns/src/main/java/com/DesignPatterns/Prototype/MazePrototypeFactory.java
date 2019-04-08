package com.DesignPatterns.Prototype;

public class MazePrototypeFactory extends MazeFactory {
    public MazePrototypeFactory(Maze maze, Wall wall, Room room, Door door) {
        prototypeMaze = maze;
        prototypeRoom = room;
        prototypeWall = wall;
        prototypeDoor = door;
    }

    // Factory Methods.
    public Maze makeMaze() {
        return prototypeMaze.clone();
    }

    public Room makeRoom(int n) {
        Room room = prototypeRoom.clone();
        room.initialize(n);
        return room;
    }

    public Wall makeWall() {
        return prototypeWall.clone();
    }

    public Door makeDoor(Room r1, Room r2) {
        Door door = prototypeDoor.clone();
        door.initialize(r1, r2);
        return door;
    }

    private Maze prototypeMaze;
    private Room prototypeRoom;
    private Wall prototypeWall;
    private Door prototypeDoor;
}
