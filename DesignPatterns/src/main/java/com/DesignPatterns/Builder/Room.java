package com.DesignPatterns.Builder;

public class Room extends MapSite {
    public Room(int roomno) {
        this._roomNumber = roomno;
    }
    public MapSite getSide(Direction dir) {
        if(dir == Direction.North) return _sides[0];
        else if(dir == Direction.South) return _sides[1];
        else if(dir == Direction.East) return _sides[2];
        else return _sides[3];
    }

    public void setSide(Direction dir, MapSite map) {
        if(dir == Direction.North) _sides[0] = map;
        if(dir == Direction.South) _sides[1] = map;
        if(dir == Direction.East)  _sides[2] = map;
        if(dir == Direction.West)  _sides[3] = map;
    }

    public int getRoomNo() {
        return _roomNumber;
    }

    public void enter(){};

    private MapSite _sides[] = new MapSite[4];
    protected int _roomNumber;
}