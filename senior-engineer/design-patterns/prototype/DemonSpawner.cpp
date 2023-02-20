class DemonSpawner: public Spawner
{
public:
    virtual Monster* spawnMonster()
    {
        return new Demon();
    }
};