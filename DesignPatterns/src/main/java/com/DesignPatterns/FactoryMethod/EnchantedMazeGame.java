package com.DesignPatterns.FactoryMethod;

public class EnchantedMazeGame extends MazeGame {
    public EnchantedMazeGame(){}

    @Override
    public Room makeRoom(int n) {
        return new EnchantedRoom(n, castSpell());
    }

    @Override
    public Door makeDoor(Room r1, Room r2) {
        return new DoorNeedingSpell(r1, r2);
    }

    protected Spell castSpell() {
        return new Spell();
    }
}