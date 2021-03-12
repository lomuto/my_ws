# std::getline in < string >

There are two `getline` function.

1. std::cin.getline()
2. getline() inside std::string

`cin.getline` gets `getline(char* destBuf,int size,char delim)`

While `getline` in `std::string` gets `(istream& is, std::string dest, char delim)`

Same name but simaillar purpose (Receives character untill delimiter) and different parameter. (input stream and char\* or std::string...)
