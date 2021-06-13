# Upcasting derived class' instance from virtual class

```cpp
class ParentClass {
    private:
        string name;
        int type;
    public:
        void setName(string name){
            this->name = name;
        }

        string getName(){
            return name;
        }

        virtual void setType() = 0;

        int getType(){
            return type;
        }
};
```

Suppose such virtual class `ParentClass`.  
Inorder to upcast derived class `DerivedClass`

```cpp
class DerivedClass : public ParentClass {
    ...
    void setType();
    ...
};
```

It derives parent class as **`public`**.

If `ChildClass` has derived as `protected` or `private`, compiler won't understand derived class' member and method so would cause compile error in upcasting.

```cpp
ProtectedDerivedClass PTDC;
PublicDerivedclass PUDC;

ParentClass* PC = &PUDC // good
PC = &PDC  // compile error
```

<br/>

---

<br/>    
   
# Array of parent class ,upcasting derived classes

```cpp
Child c0;
Child c1;
Child c2;

Parent* arr = new Parent[3]{c0,c1,c2};    // error
```

Upcasting many derived class' instance with parent class type array is impossible while **virtual class' instance is prohibited, so as impossible to make an array with it**.  
In order to manage few children class' with upcasting with parent class....

```cpp
Child c0;
Child c1;
Child c2;

Parent *p0 = &c0;
Parent *p1 = &c1;
Parent *p2 = &c2;

Parent **arr = new Parent *[3] { p0, p1, p2 };
```

Make an array of pointer will do.
