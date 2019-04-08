package com.DesignPatterns.AbstractFactory;

public class Room extends MapSite {
    public Room(int roomNumber) {
        this.roomNumber = roomNumber;
    }

    private MapSite sides[] = new MapSite[4];
    protected int roomNumber;

    public MapSite getSide(Direction dir) {
        if(dir == Direction.North) return sides[0];
        else if(dir == Direction.South) return sides[1];
        else if(dir == Direction.East) return sides[2];
        else return sides[3];
    }

    public void setSide(Direction dir, MapSite map) {
        if(dir == Direction.North) sides[0] = map;
        if(dir == Direction.South) sides[1] = map;
        if(dir == Direction.East)  sides[2] = map;
        if(dir == Direction.West)  sides[3] = map;
    }

    public int getRoomNo() {
        return roomNumber;
    }

    public void enter(){};
}