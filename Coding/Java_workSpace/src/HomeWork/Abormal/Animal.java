package src.HomeWork.Abormal;

abstract class Animal {
    public abstract void cry();

    public abstract String getAnimalName();
}

class Dog extends Animal {
    @Override
    public void cry() {
        System.out.println("狗叫");
    }

    @Override
    public String getAnimalName() {
        return "狗";
    }
}

class Cat extends Animal {
    @Override
    public void cry() {
        System.out.println("猫叫");
    }

    @Override
    public String getAnimalName() {
        return "猫";
    }
}

class Simulator {
    public void playSound(Animal animal) {
        animal.cry();
        System.out.println("动物名字是: " + animal.getAnimalName());
    }
}
