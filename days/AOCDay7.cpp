#include "AOCDay7.h"

#include <Helpers.h>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <numeric>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <thread>

namespace GDL
{

struct SystemObject
{
  std::string name;

  virtual int getSize() = 0;
};

struct File : SystemObject
{
  int size;

  File( int size )
  {
    this->size = size;
  }

  int getSize() override
  {
    return size;
  }
};

struct Directory : SystemObject
{
  std::shared_ptr< Directory > parentDirectory;

  std::vector< std::shared_ptr< SystemObject > > children;

  std::shared_ptr< Directory > tryGetChildDirectory( std::string lookingFor )
  {
    for ( auto& child : children )
    {
      auto cast = dynamic_pointer_cast< Directory >( child );
      if ( cast && cast->name == lookingFor )
      {
        return cast;
      }
    }
    return nullptr;
  }

  std::shared_ptr< File > tryFindFile(std::string lookingFor)
  {
    for (auto& child : children)
    {
      auto cast = dynamic_pointer_cast< File >(child);
      if (cast && cast->name == lookingFor)
      {
        return cast;
      }
    }
    return nullptr;
  }

  int getSize() override
  {
    int total = 0;
    for ( auto& child : children )
    {
      total += child->getSize();
    }
    return total;
  }
};

int part1( std::shared_ptr< Directory > top) {
  int toReturn = 0;

  int thisSize = top->getSize();
  if(thisSize <= 100000)
    toReturn += thisSize;
  for (auto& child : top->children)
  {
    auto cast = dynamic_pointer_cast<Directory>(child);
    if (cast)
    {
      toReturn += part1( cast );
    }
  }

  return toReturn;
}

int part2Recursive(std::shared_ptr< Directory > current, int& requiredDeletion) {
  int toReturn = 0;
  int thisSize = current->getSize();
  if (thisSize >= requiredDeletion)
    toReturn = thisSize;

  for (auto& child : current->children)
  {
    auto cast = dynamic_pointer_cast<Directory>(child);
    if (cast)
    {
      int childSize = part2Recursive(cast, requiredDeletion);
      if (childSize >= requiredDeletion) {
        toReturn = std::min( toReturn, childSize );
      }
    }
  }
  return toReturn;
}

int part2(std::shared_ptr< Directory > top) {
  int topSize = top->getSize();
  int requiredDeletion = 30000000 - (70000000 - topSize);
 

  int toReturn = 0;
  toReturn = part2Recursive( top, requiredDeletion );
  return toReturn;
}


void AOCDay7::processDayInternal( std::istream& stream )
{
  std::string line;
  std::shared_ptr< Directory > top = std::make_shared< Directory >();
  std::shared_ptr< Directory > current = top;
  current->name = "TOPDIRECTORY";
  std::getline(stream, line);
  while ( stream.good() )
  {
    std::getline( stream, line );
    auto split = splitByDelimiter( line, ' ' );
    if ( split[1] == "cd" )
    {
      if ( split[2] == ".." )
      {
        if ( current->parentDirectory == nullptr )
        {
          current->parentDirectory = std::make_shared< Directory >();
        }
        else
        {
          current = current->parentDirectory;
        }
      }
      else
      {
        auto tryFind = current->tryGetChildDirectory( split[1] );
        if (!tryFind)
        {
          auto childDirectory = std::make_shared< Directory >();
          childDirectory->name = split[2];
          childDirectory->parentDirectory = current;
          current->children.push_back(childDirectory);
          current = childDirectory;
        }
      }
    }
    else if ( split[1] == "ls" )
    {
      while ( stream.peek() != '$' && stream.good())
      {
        std::getline( stream, line );
        auto splitLS = splitByDelimiter( line, ' ' );
        if ( splitLS[0] != "dir" )
        {
          auto tryFind = current->tryFindFile(splitLS[1]);
          if ( tryFind == nullptr ) {
            auto newFile = std::make_shared< File >(stoi(splitLS[0]));
            newFile->name = splitLS[1];
            current->children.push_back(newFile);
          }
        }
      }
    }
  }
  std::cout << "Part1: " << part1(top) << "\n";
  std::cout << "Part2: " << part2(top) << "\n";
}

} // namespace GDL
