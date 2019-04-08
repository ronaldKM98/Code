package com.DesignPatterns.Prototype;

public class Wall extends MapSite {
    public Wall(){};
    public Wall(Wall that){};

    public Wall clone() {
        return new Wall(this);
    }

    public void enter(){};
}