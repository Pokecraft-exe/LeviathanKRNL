#pragma once
#include "cstring.h"
#include "stddef.h"
class File {
private:
	string data;
public:
	string name;
	string extention;
	string Read() {
		return data;
	}
	void Write(string newData) {
 		data = newData;
	}
	void Append(string newData) {
		data = strncat(data,newData,strlen(newData));
	}
	void Rename(string NewName, string NewExtention) {
		name = NewName;
		extention = NewExtention;
	}
};

class Directory {
private:
	Directory* childDir;
	int childdir;
	int childfile;
	File childFile[100];
	string fileName;
	int currentDirIndex = -1;
	File emptyFile;
public:
	Directory(string Name) {
		fileName = Name;
	}
	
	void cd(string Name) {
		if (Name == "..")
			currentDirIndex = -1; // -1 is root
		else {
			if (currentDirIndex == -1) {
				for (int i = 0; i < 100; i++)
					if (childDir[i].fileName == Name)
						currentDirIndex = i;
			} else
				childDir[currentDirIndex].cd(Name);
		}
	}

	File *open(string Name, string ext) {
		if (currentDirIndex == -1) {
			for (int i = 0; i < 100; i++) {
				if (childFile[i].name == Name &&
					childFile[i].extention == ext) {
					return &childFile[i];
				}
			}
			return &emptyFile;
		} else
			return childDir[currentDirIndex].open( Name, ext);
	}

	void mkdir(string Name) {
		if (currentDirIndex == -1){
			childDir[childdir+1]=Directory( Name);
			childdir++;
        }
		else
			childDir[currentDirIndex].mkdir( Name);
	}

	void mkfile(string  Name, string ext) {
		File newfile;
		newfile.name =  Name;
		newfile.extention = ext;
		if (currentDirIndex == -1){
			childFile[childfile+1]=newfile;
			childfile++;
        }
		else
			childDir[currentDirIndex].mkfile( Name, ext);
	}

	void ls() {
		if (currentDirIndex == -1) {
			puts(">>> ");puts(IntToStr(childdir));puts(" directory(s) found in ");puts(fileName);puts(":\n\r");
			puts("::: ");puts(IntToStr(childfile));puts(" file(s) found in ");puts(fileName);puts(":\r\n");
			for (int i; i<=childdir;i++) {
				puts("> ");puts(childDir[i].fileName);puts("\r\n");
			}
			for (int i;i<=childfile;i++) {
				puts(": ");puts(childFile[i].name);puts(".");puts(childFile[i].extention);puts("\n\r");
			}
		} else
			childDir[currentDirIndex].ls();
	}
};

extern Directory Partition("RAM://");

void initRAMDISK(){
	puts("Partition on RAM://\n\r");
	Partition.ls();
}