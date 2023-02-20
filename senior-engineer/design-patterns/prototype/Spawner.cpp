class Spawner
{
public:
    virtual ~Spawner(){}
    virtual Monster* spawnMonster() = 0;
};