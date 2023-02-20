class Monster
{
public:
    virtual ~Monster(){}
    virtual Monster* clones() = 0;
};