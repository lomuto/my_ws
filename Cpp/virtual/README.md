# virtual keyword

**Everything method is virtual in java**.  
So its speed is a bit slow, but always gaureentes a right method to call in instances. If you want it to run faster, adding `final` keyword in method will make it static binding.

In Cpp, every method is default is non-virtual. So calling a overridden method inside of derived class' instance which is upcasted, it will call a base class' method. Adding a virtual keyword will bind a method dynamically, call a right one.

So, how does this virtual table works?

Adding a `virtual` keyword to method will yeild a compiler to **store a memory address of virtual table to function memory** when instance is created.
