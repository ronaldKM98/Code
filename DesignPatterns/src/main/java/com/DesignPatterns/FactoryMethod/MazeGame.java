package com.DesignPatterns.FactoryMethod;

public class MazeGame {
    public MazeGame(){};

    // Here generic implementations are provided but anyway,
    // this is going to be overridden in extension classes.

    public Maze createMaze() {
        Maze aMaze = makeMaze();
        Room r1 = makeRoom(1);
        Room r2 = makeRoom(2);
        Door aDoor = makeDoor(r1, r2);

        aMaze.addRoom(r1);
        aMaze.addRoom(r2);

        r1.setSide(Direction.North, makeWall());
        r1.setSide(Direction.East, aDoor);
        r1.setSide(Direction.South, makeWall());
        r1.setSide(Direction.West, makeWall());

        r1.setSide(Direction.North, makeWall());
        r1.setSide(Direction.East, makeWall());
        r1.setSide(Direction.South, makeWall());
        r1.setSide(Direction.West, aDoor);

        return aMaze;
    }

    // Factory Methods.
    public Maze makeMaze() {
        return new Maze();
    }

    public Room makeRoom(int n) {
        return new Room(n);
    }

    public Wall makeWall() {
        return new Wall();
    }

    public Door makeDoor(Room r1, Room r2) {
        return new Door(r1, r2);
    }
}