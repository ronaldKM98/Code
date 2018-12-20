package com.DesignPatterns.AbstractFactory;

public class Room extends MapSite {
    public Room Room(int roomno){};
    public MapSite getSide(Direction dir){};
    public void setSide(Direction dir, MapSite map){};

    public abstract void enter(){};

    private MapSite _sides[] = new MapSite[4];
    private int _roomNumber;
}