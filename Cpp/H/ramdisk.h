#pragma once
#include "cstring.h"
#include <vector.h>
using namespace std;

class File {
private:
	char* data;
public:
	char* name;
	char* extention;
	char* Read() {
		return data;
	}
	void Write(char* newData) {
 		data = newData;
	}
	void Append(char* newData) {
		data = strncat(data,newData,strlen(newData));
	}
	void Rename(char* NewName, char* NewExtention) {
		name = NewName;
		extention = NewExtention;
	}
};

class Directory {//cr�er une classe nom�e directory (aussi le type directory)
private: // seul la classe peut untiliser ces fonctions
	std::vector<Directory> childDir;
	std::vector<File> childFile;
	char* fileName;
	int currentDirIndex = -1;
	File emptyFile; // cr�er un fichier nomm� emptyFile
public: // tout le code peut utiliser ces fonctions
	Directory(char* char*__fileName) {
		fileName = __fileName;
	}
	
	
	void cd(char* char*__fileName) {
		if (__fileName == "..")
			currentDirIndex = -1; // -1 is root
		else {
			if (currentDirIndex == -1) {
				for (int i = 0; i < childDir.size(); i++)
					if (childDir.at(i).fileName == __fileName)
						currentDirIndex = i;
			} else
				childDir.at(currentDirIndex).cd(__fileName);
		}
	}

	File *open(char* __fileName, char* ext) {
		if (currentDirIndex == -1) {
			for (int i = 0; i < childFile.size(); i++) {
				if (childFile.at(i).name == __fileName &&
					childFile.at(i).extention == ext) {
					return &childFile.at(i);
				}
			}
			return &emptyFile;
		} else
			return childDir.at(currentDirIndex).open(__fileName, ext);
	}

	void mkdir(char* char*__fileName) {
		if (currentDirIndex == -1)
			childDir.push_back(Directory(__fileName));
		else
			childDir.at(currentDirIndex).mkdir(__fileName);
	}
	void mkfile(char* __fileName, char* ext) {
		File newfile;
		newfile.name = __fileName;
		newfile.extention = ext;
		if (currentDirIndex == -1)
			childFile.push_back(newfile);
		else
			childDir.at(currentDirIndex).mkfile(__fileName, ext);
	}
	void ls() {
		if (currentDirIndex == -1) {
			puts(">>> ");puts(IntToStr(childDir.size()));puts(" directory(s) found in ");puts(fileName;puts(":\n\r");
			puts("::: ");puts(IntToStr(childFile.size()));puts(" file(s) found in ");puts(fileName);puts(":\r\n");
			for (Directory &dir : childDir) {
				puts("> ");puts(dir.fileName);puts("\r\n");
			}
			for (File &file : childFile) {
				puts(": ");puts(file.name);puts(".");puts(file.extention);puts("\r\n");
			}
		} else
			childDir.at(currentDirIndex).ls();
	}
};

extern Directory Partition("RAM://");

void initRAMDISK(){
	puts("Partition on RAM://\n\r");
	Partition.ls();
}