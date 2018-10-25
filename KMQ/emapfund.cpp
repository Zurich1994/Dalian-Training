#include"emap.h"
#include<cstring>
#include<cstdlib>

extern Road *roads;
// 保存所有道路的数组
extern int roadsSize;
// 道路数量

/* 实现部分 */
Road::Road(){
	linkID=0;
	nameFlag=false;
	branch=0;
	dispClass=0;
	name[0]=0;  
}
Road::Road(const unsigned int linkID, const bool nameFlag, const int branch,
		const int dispClass, char* const name){
	this->linkID=linkID;
	this->nameFlag=nameFlag;
	this->branch=branch;
	this->dispClass=dispClass;
	if (name!=NULL){
		strcpy(this->name,name);
	} else{
		strcpy(this->name,"");
	}
}
Road::Road(const Road &source){
	this->linkID=source.linkID;
	this->nameFlag=source.nameFlag;
	this->branch=source.branch;
	this->dispClass=source.dispClass;
	if (source.name!=NULL){
		strcpy(this->name,source.name);
	} else{
		strcpy(this->name,"");
	}
}
Road& Road::operator =(const Road that){
	this->linkID=that.linkID;
	this->nameFlag=that.nameFlag;
	this->branch=that.branch;
	this->dispClass=that.dispClass;
	if (that.name!=NULL){
		strcpy(this->name,that.name);
	} else{
		strcpy(this->name,"");
	}
	return *this;
}
bool Road::operator <(const Road that)const{
	return (this->linkID<that.linkID);
}
bool Road::operator <=(const Road that)const{
	return (this->linkID<=that.linkID);
}
bool Road::operator ==(const Road that)const{
	return (this->linkID==that.linkID);
}
Road::~Road(){
}
void swap(Road * a, Road * b){
	
	Road t=*a;
	*a=*b;
	*b=t;
}
void swap(Road &a, Road &b){
	swap(&a,&b);
}
