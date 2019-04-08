package com.DesignPatterns.FactoryMethod;

import java.util.ArrayList;

public class Maze {
    public Maze(){}

    private ArrayList<Room> rooms = new ArrayList<Room>();

    public void addRoom(Room a){
        rooms.add(a);
    }

    public Room roomNo(int roomNumber) {
        for (Room room : rooms) {
            if (room.getRoomNo() == roomNumber) return room;
        }
        return null;
    }

    public String toString() {
        String res = "";
        for(Room room: rooms) {
            res += Integer.toString(room.getRoomNo()) + '\n';
        }
        return res;
    }
}