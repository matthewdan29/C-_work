This is kind of important so I'm just going to write word from word of what hes saying. 

The abstract class design is flexible and almost as simple to deal with as the equivalent design that relies on a common base defining the user-interface system. 
The windows class "BBwidget" is the root of a tree. In the former, the original application class hierarchy appears unchanged as the root of classes that supply its implementation. 
From the application's point of view, these designs are equivalent in the strong sense that almost all code works unchanged and in the same way in the two cases. 
In both case, you can look at the "lval_box" family of classes without bothering with the window-related implementation details most of the time. 
You would not need to rewrite "interact()" from if you switched from one class hierarchy to the other.

The implementation of each "lval_box" class must be rewritten when the public interface of the user-interface system changes.
In the abstract class design, almost all user code is protected against changes to the implementation hierarchy and requires no recompilation after such a change. 
This is especially important when the supplier of the implementation hierarchy issues a new "almost compatible" release. 
Users of the abstract class hierarchy are in less danger of being locked into a proprietary implementation than are users of a classical hierarchy. 

The logical conslusion of this line of thought is a systemrepresented to users as a hierarchy of abstract classes and implemented by classical hierarchy.

			basicly 
1)	Use abstract classes to support interface inheritance. 
2) 	Use base classes with implementations of virtual functions to support implementation inheritance. 

