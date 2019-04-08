package com.DesignPatterns;

//import com.DesignPatterns.Builder.*;
import com.DesignPatterns.FactoryMethod.MazeGame;
import com.DesignPatterns.Prototype.*;

public class App
{
    public static void main( String[] args ) {
        prototype();
    }

    /*public static void countingBuilder() {
        MazeGame game = new MazeGame();
        CountingMazeBuilder builder = new CountingMazeBuilder();

        game.createMaze(builder);
        int a [] = builder.getCounts();

        String res = String.format("The maze has \n %d rooms and \n %d doors \n",
        a[0], a[1]);
        System.out.println(res);
    }

    public static void builder() {
        Maze maze;
        MazeGame game = new MazeGame();
        StandardMazeBuilder builder = new StandardMazeBuilder();

        game.createMaze(builder);
        maze = builder.getMaze();
        System.out.println(maze.toString());
        countingBuilder();
    }

    /** public static void abstractFactory() {
        MazeGame game = new MazeGame();
        BombedMazeFactory factory = new BombedMazeFactory();

        Maze m = game.createMaze(factory);
        System.out.println(m.toString());
    }*/

    public static void prototype() {
        MazeGame game;
        MazePrototypeFactory simpleMazeFactory =
                new MazePrototypeFactory(new Maze(), new Wall(), new Room(), new Door());

        MazePrototypeFactory bombed =
                new MazePrototypeFactory(new Maze(), new BombedWall(), new RoomWithABomb(), new Door());
    }
}
