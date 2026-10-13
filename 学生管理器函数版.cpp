#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct Student{
	int id;
	string name;
	double score;
};

void showMenu();
void addStudents(vector<Student>&students);
void displayStudents(const vector<Student>students);

int main(){
	vector<Student> students;
	int choice;
	
	while(true){
		showMenu();
		cin >> choice;
		
		if(choice == 1){
			addStudents(students);
		}
		else if(choice == 2){
			displayStudents(students);
		}
		else if(choice == 3){
			cout << "感谢使用，再见！" <<endl;
			break;
		}
		else{
			cout << "输入有误，请重新输入！"<<endl;
		}
	}
	return 0;
}
void showMenu(){
	cout << "\n==========学生管理系统=========="<<endl;
	cout <<"1.批量添加学生"<<endl;
	cout <<"2.查询所有学生"<<endl;
	cout <<"3.退出系统"<<endl;
	cout <<"请输入你的选择:";
}

void addStudents(vector<Student>&students){
	cout << "进入批量添加模式，输入-1可退出" <<endl;
	while(true){
		Student temp;
		cout << "请输入学号：";
		cin >> temp.id;
		if(temp.id==-1) break;
		
		cout << "请输入姓名和成绩：";
		cin >> temp.name >> temp.score;
		bool isExist = false;
		for(int i = 0;i < (int)students.size();i++){
			if(students[i].id == temp.id){
				isExist = true;
				break;
			}
		}
		if(isExist){
			cout <<"学号"<<temp.id<<"已存在！\n";
		}else{
			students.push_back(temp);
			cout << "添加成功！当前有"<<students.size()<<"名学生。\n";
		}
	}
}

void displayStudents(const vector<Student>students){
	if(students.empty()){
		cout <<"当前没有录入学生"<<endl;
		return;
	}
	cout <<"\n---所有学生信息---"<<endl;
	for(int i = 0;i<(int)students.size();i++){
		cout <<"学号："<<students[i].id
		<<"\t姓名："<< students[i].name
		<<"\t成绩："<< students[i].score <<endl;
		
	}
}
