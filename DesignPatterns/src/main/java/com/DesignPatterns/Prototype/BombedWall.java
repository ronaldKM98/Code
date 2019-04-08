package com.DesignPatterns.Prototype;

public class BombedWall extends Wall {
    public BombedWall(){};

    public BombedWall(BombedWall that){}

    @Override
    public BombedWall clone() {
        return new BombedWall(this);
    }

    public void enter(){};
}