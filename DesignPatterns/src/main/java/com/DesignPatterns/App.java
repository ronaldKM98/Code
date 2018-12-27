package com.DesignPatterns;
import com.DesignPatterns.AbstractFactory.*;
/**
 * Hello world!
 *
 */
public class App 
{
    public static void main( String[] args ) {
        MazeGame game = new MazeGame();
        BombedMazeFactory factory = new BombedMazeFactory();

        Maze m = game.createMaze(factory);
        System.out.println(m.toString());

    }
}
