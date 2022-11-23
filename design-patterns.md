# Design Patterns

#senior-engineer 

There are a plethora of Design Patterns in programming that tend to be common place and I want to be able to understand what these patterns are, how to implement them and when to implement them. Design Patterns are usually split up into 3 Categories: Creational Patterns, Structural Patterns, and Behavioural Patterns.

The book `Game Programming Patterns` by Robert Nystrom extends this list with additional patterns relevant to games with three new categories: Sequencing Patterns, Decoupling Patterns, and Optimization Patterns. As well as extending the Behavioural Patterns with three additional patterns: Bytecode, Subclass Sandbox, and Type Object.

Below is the full list of Design Patterns that I wish to understand, I will add explinations of each along with references to where I learned about them and also examples of implementations of each that I have created to show progress on my understanding of each one.


## Creational Patterns

### Factory Method

### Abstract Factory

### Builder

### Singleton

Singletons are the "One of a kind" pattern. The idea behind the Singleton pattern is to simply ensure that only one instance of an Object can be instantiated. It also allows for global access to the object.

	What are Singletons good for?

Singletons are good for Objects that you would like global access to but you only need one instance of the object. Examples of this include:

- Threadpools
- Caches
- Dialog Boxes
- Game Managers
- Objects that handle Preferences and Registry settings
- Objects used for logging
- Objects that act as device drivers. i.e.
	* Printers
	* Graphics Cards
	* etc.

Instantiating more than one of these kinds of objects could lead to:
- Incorrect program behaviour
- Overuse of resources
- Inconsistent Results

Singletons act like global variables without the downsides.

	What are the downsides to global variables?

Global variables are created on application start and exist before they are used. If these Global variables are performance intensive then this is a waste. Singletons allow for these global objects to be created when they are needed.

Example of a Singleton in C++

``` C++
  
class Singleton{  
  
public:  
    static Singleton& GetInstance(){  
        static Singleton instance;  
        return instance;  
    };  
  
private:  
    Singleton(){};  
  
public:  
    Singleton(Singleton const&) = delete;  
    void operator=(Singleton const&) = delete;  
  
};
```

References:

[Head First Design Patterns 2nd Edition](https://www.oreilly.com/library/view/head-first-design/9781492077992/)
[Stackoverflow](https://stackoverflow.com/questions/1008019/c-singleton-design-pattern  )


### Prototype


## Structural Patterns:

### Adapter

### Bridge

### Composite

### Decorator

### Facade

### Flyweight

### Proxy

## Behavioural Patterns

### Chain of Responsibility

### Command

### Iterator

### Mediator

### Memento

### Observer

### State

### Strategy

### Template Method

### Bytecode

### Subclass Sandbox

### Type Object

## Sequencing Patterns

### Double Buffer

### Game Loop

### Update Method

## Decoupling Patterns

### Component

### Event Queue

### Service Locator

## Optimization Patterns

### Data Locality

### Dirty Flag

### Object Pool

### Spatial Partition