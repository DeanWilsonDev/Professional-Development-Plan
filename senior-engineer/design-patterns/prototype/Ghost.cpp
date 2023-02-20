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
