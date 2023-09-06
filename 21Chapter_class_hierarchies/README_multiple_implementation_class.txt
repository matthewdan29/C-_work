This is an important concept so I'm putting word for word what he says down.

Consider a simulation of bodies orbiting the Earth in which orbiting objects are represented as objects of "Satellite". 
A "Satellite" object would contain orbital, size, shape, albedo, desity parameters, etc., and provide operations for orbital calculations, modifying attributes, etc. These kinds of satellites would be objects of classes derived from "Satellite". Such derved classes would add data members and functions and would override some of "Satellite" virtual functions to adjust their meaning suitably. 
