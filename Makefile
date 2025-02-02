bin/testTableEntry: testTableEntry.cpp TableEntry.h
		mkdir -p bin
		g++ -o bin/testTableEntry testTableEntry.cpp
bin/testHashTable: testHashTable.cpp Dict.h HashTable.h TableEntry.h 
		mkdir -p bin
		g++ -o bin/testHashTable testHashTable.cpp
bin/testBSTree: testBSTree.cpp BSNode.h BSTree.h
		mkdir -p bin
		g++ -o bin/testBSTree testBSTree.cpp
bin/testBSTreeDict: testBSTreeDict.cpp BSTreeDict.h Dict.h TableEntry.h
		mkdir -p bin
		g++ -o bin/testBSTreeDict testBSTreeDict.cpp
bin/praD: praD.cpp examen.h BSNode.h
		mkdir -p bin
		g++ -o bin/praD praD.cpp
clean:
		rm -rf *.o *.gch bin
