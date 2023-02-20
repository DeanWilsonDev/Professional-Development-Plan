lass Spawner{public :virtual ~sSpawner() {{}virtual MOster*o

Singletons are the "One of a kind" pattern. The idea behind the Singleton pattern is to simply ensure that only one instance of an Object can be instantiated. It also allows for global access to the object. Despite its intentions, it's often noted that Singletons usually do more harm than good. It's also noted that his pattern should be used sparingly but they are so often overused.

```plain text
When much of the industry moved to object-oriented programming from C, one problem they ran into was "how do i get an instance?" They had some method they wanted to call but didn't have an instance of the object that provides that method in hand. Singletons (in other words, making it global) were an easy way out.

Game Programming Patterns - Robert Nystrom pg. 73
```

Example of a Singleton in C++ :

```C++
class Singleton
{
public:
    // Note: In C++11 the initializer for a
    // local static variable is only run once.
    static FileSystem& instance(){
        static FileSystem *instance = new FileSystem();
        return *instance;
    };

private:
    FileSystem(){};
};
```

## What are Singletons good for?

Singletons are good for Objects that you would like global access to but you only need one instance of the object. Examples of this include:

- Threadpools
- Caches
- Dialog Boxes
- Game Managers?
- Objects that handle Preferences and Registry settings
- Objects used for logging
- Objects that act as device drivers. i.e.
  - Printers
  - Graphics Cards
  - etc.

Instantiating more than one of these kinds of objects could lead to:

- Incorrect program behaviour
- Overuse of resources
- Inconsistent Results

Singletons act like global variables without the downsides.

Another often overlooked capability of the Singleton pattern is that you can subclass a Singleton class.

## What are the downsides to global variables?

Global variables are created on application start and exist before they are used. If these Global variables are performance intensive then this is a waste. Singletons allow for these global objects to be created when they are needed.

## References:

[Game Programming Patterns](https://gameprogrammingpatterns.com/)

[Head First Design Patterns 2nd Edition](https://www.oreilly.com/library/view/head-first-design/9781492077992/)

[Stackoverflow](https://stackoverflow.com/questions/1008019/c-singleton-design-pattern)
