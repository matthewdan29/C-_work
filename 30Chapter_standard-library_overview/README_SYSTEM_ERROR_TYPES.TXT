error_code	=	Holds a value identifying an error and the category of that error; system-specific

error_category	=	A base class for types used to identify the source and encoding of a particular kind of error code. 

system_error 	=	A runtime_error exception containing an error_code.

error_condition	=	Holds a vlaue identifying an error and the category of that error; potentially portable. 

errc		=	enum class with enumerators for error codes from <cerrno>; basically POSIX error codes 

future_errc	=	enum blass with enumerators for error codes for <future>

io_errc		=	enum class with enumerators for error codes from <ios>.


				"Exception Class "system_error"" 

system_error se {ec,s}	=	se holds {ec,s}; ec is an error_code; s is a st-				ring or a C-style string intended as part of an 				error message

system_error se{ec}; 	=	se holds {ec}, ec is an error_code

system_error se{n,cat,s}=	se holds {error_code{n,cat},s}; cat is an error_				category and n is an int representing an error  				in cat; s is a string of a C-style string inten-				ded as part of an error message

system_error se{n,cat};=	se holds error_code{n,cat}; cat is an error_cat-				ory and n is an int representing an error in cat

ec=se.code() 		=	ec is a referencec to se's error_code; noexcept

p=se.what()		=	p is a C-style string version of se's error str-				ing; noexcept
