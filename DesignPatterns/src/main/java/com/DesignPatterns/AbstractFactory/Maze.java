package com.DesignPatterns.AbstractFactory;
import java.util.ArrayList;
public class Maze {
    public Maze(){};
    public void addRoom(Room a){
        rooms.add(a);
    }

    public Room roomNo(int roomno){
        for (Room room : rooms) {
            if (room.getRoomNo() == roomno) return room;
        }
        return null;
    }

    private ArrayList<Room> rooms = new ArrayList<Room>();

    public String toString() {
        String res = "";
        for(Room room: rooms) {
            res += Integer.toString(room.getRoomNo()) + '\n';
        }
        return res;
    }
}