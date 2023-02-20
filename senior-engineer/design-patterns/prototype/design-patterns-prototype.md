# Design Patterns - Prototype

```plain text
"Specify the kinds of objects to create using a prototypical instance,
and create new objects by copying it's prototype."
```

The Prototype pattern aims to remove boilerplate code by removing the 
need to have classes that generate objects by providing objects the ability to clone themselves,
essentially acting as the "Prototype" for each subsequently generated instance.

example, instead of doing:

[Spawner.cpp](Spawner.cpp)
```c++
class Spawner
{
public:
    virtual ~Spawner(){}
    virtual Monster* spawnMonster() = 0;
};
```

[GhostSpawner.cpp](GhostSpawner.cpp)
```c++
class GhostSpawner : public Spawner
{
public:
    virtual Monster* spawnMonster()
    {
        return new Ghost();
    }
};
```

[DemonSpawner.cpp](DemonSpawner.cpp)
```c++
class DemonSpawner: public Spawner
{
public:
    virtual Monster* spawnMonster()
    {
        return new Demon();
    }
};
```

etc...


We can give this functionality to the Monster that we are generating. 
That way as long as we already have a monster that is defined and exists, 
then we can continue to clone additional monsters based off the defined prototype.

example:

[Monster.cpp](Monster.cpp)
```c++
class Monster
{
public:
    virtual ~Monster(){}
    virtual Monster* clones() = 0;
};
```

declaring this functionality in the Monster base class means that any additional classes
that inherit from the Monster base class will need to define the declared method

for instance if we want to create a Ghost monster, we would do the following:

[Ghost.cpp](Ghost.cpp)
```c++
class Ghost: public Monster
{
public:
    Ghost(int health, int speed)
    : health_(health),
      speed_(speed)
    { }

    virtual Monster* clone()
    {
        return new Ghost(health_, speed_);
    }

private:
    int health_;
    int speed_;
};
```

After all the monsters have the `clone` method defined, we no longer need multiple spawners for each type of monster, 
we only need a single one:

[PrototypeMonsterSpawner.cpp](PrototypeMonsterSpawner.cpp)
```c++
class Spawner
{
  public:
    Spawner(Monster* prototype):
      prototype_(prototype){}

    Monster* spawnMonster()
    {
      return prototype_->clone();
    }
    
  private:
  Monster* prototype_;
}
```
