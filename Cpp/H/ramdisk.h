#pragma once
#include "cstring.h"
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

class Directory {
private:
	Directory childDir[100];
	int childdir;
	int childfile;
	File childFile[100];
	char* fileName;
	int currentDirIndex = -1;
	File emptyFile;
public:
	Directory(const char* Name) {
		fileName = Name;
	}
	
	void cd(const char* Name) {
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

	File *open(const char* Name, const char* ext) {
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

	void mkdir(const char* Name) {
		if (currentDirIndex == -1){
			childDir[chalddir+1]=Directory( Name);
			childdir++;
        }
		else
			childDir[currentDirIndex].mkdir( Name);
	}

	void mkfile(char*  Name, char* ext) {
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
			for (const Directory &dir : childDir) {
				puts("> ");puts(dir.fileName);puts("\r\n");
			}
			for (const File &file : childFile) {
				puts(": ");puts(file.name);puts(".");puts(file.extention);puts("\n\r");
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