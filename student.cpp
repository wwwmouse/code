#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class student{
    private:
        string name;
        string num;
        double math=0.0;
        double English=0.0;
        double cpp=0.0;
    public:
        
        double getmath()const{
            return math;
        }

        double getEnglish()const{
            return English;
        }

        double getcpp()const{
            return cpp;
        }

        string getname()const{
            return name;
        }
        
        string getnum()const{
            return num;
        }

        int setdata(string&inname,string&innum){

            name=inname;
            num=innum;
            return 0;
        }

        int setscore(int choice){

            switch(choice){
                case 1:{
                    double inputm=-1;
                    cout<<"请输入数学成绩: ";
                    cin>>inputm;
                    if(inputm<0||inputm>100){
                        cout<<"*****************************************"<<endl;
                        cout<<"数学成绩输入有误，请检查成绩的范围"<<endl;
                        return 1;
                    }
                    else{
                        math=inputm;
                        cout<<"录入成绩成功!"<<endl;
                    }
                    break;
                }

                case 2:{
                    double inpute=-1;
                    cout<<"请输入英语成绩: ";
                    cin>>inpute;
                    if(inpute<0||inpute>100){
                        cout<<"*****************************************"<<endl;
                        cout<<"英语成绩输入有误，请检查成绩的范围"<<endl;
                        return 1;
                    }
                    else{
                        English=inpute;
                        cout<<"录入成绩成功!"<<endl;
                    }
                    break;
                }

                case 3:{
                    cout<<"请输入c++成绩:";
                    double inputc=-1;
                    cin>>inputc;
                    if(inputc<0||inputc>100){
                        cout<<"*****************************************"<<endl;
                        cout<<"c++成绩输入有误，请检查成绩的范围"<<endl;
                        return 1;
                    }
                    else{
                        cpp=inputc;
                        cout<<"录入成绩成功!"<<endl;
                    }
                    break;
                }

            }
            return 0;
        }

        void display(){
            cout<<"姓名:"<<name<<endl;
            cout<<"学号:"<<num<<endl;
        }

};
class clmanager{
    private:
        vector<student>students;
    
    public:
        clmanager(){
            students.reserve(1000);
        }
        //函数出生时自动执行的构造函数，特点是 没有返回值且函数名一定是类名^^

        int getsize()const{
            return students.size();
        }

        double averagescore(int choice){
            if(!students.size()){
                cout<<"暂无学生数据..."<<endl;
                return 0.0;
            }
            switch(choice){
                case 1:{
                    double summ=0;
                    for( const auto& i:students){
                        summ+=i.getmath();
                    }
                    summ/=students.size();
                    return summ;
                }

                case 2:{
                    double sume=0;
                    for(const auto& i:students){
                        sume+=i.getEnglish();
                    }
                    sume/=students.size();
                    return sume;
                }

                case 3:{
                    double sumc=0;
                    for(const auto& i:students){
                        sumc+=i.getcpp();
                    }
                    sumc/=students.size();
                    return sumc;
                }

                case 4:{
                    double sums=0;
                    for(const auto&i:students){
                        sums+=i.getcpp()+i.getEnglish()+i.getmath();
                    }
                    sums/=students.size();
                    return sums;
                }
            }
        }

        int addstudent(student&st){
            students.push_back(st);
            cout<<"成功添加"<<endl;
            return 0;
        }

        bool numexist(string num){
            for(auto i:students){
                if(i.getnum()==num){
                    return true;
                }
            }
            return false;
        }

        void displayclass(){
            for(auto i:students){
                cout<<"姓名:"<<i.getname() <<"  学号:"<<i.getnum()<<endl;
            }
            cout<<"显示完毕"<<endl;
        }

};
int main(){
        cout<<"您好,欢迎来到w的成绩管理系统^^"<<endl;
        clmanager con;
        
        int choice=10;
        while(1){
            cout<<"*****************************************"<<endl;
            cout<<"功能列表:"<<endl;
            cout<<"1.新建班级学生"<<endl;
            cout<<"2.管理班级"<<endl;
            cout<<"3.退出系统"<<endl;
            cout<<"请输入需要的功能序号:";
            cin>>choice;
            switch(choice){

                case 1:{
                    student stu;
                    string name;
                    string num;
                    cout<<"请输入学生姓名:";
                    cin>>name;
                    
                    cout<<"请输入学生十位学号:";
                    cin>>num;
                    while(num.length()!=10){
                            cout<<"*****************************************"<<endl;
                            cout<<"学号位数有误,请重新输入十位学号:";
                            cin>>num;
                    }
                        
                    while(con.numexist(num)){
                        cout<<"*****************************************"<<endl;
                        cout<<"学号已存在,请重新输入学号:";
                        cin>>num;
                    }
                    stu.setdata(name,num);
                    cout<<"*****************************************"<<endl;
                    cout<<"输入成功！"<<endl;
                    
                    int t=5;
                    while(t!=4){
                        cout<<"*****************************************"<<endl;
                        cout<<"科目列表"<<endl;
                        cout<<"1.数学"<<endl;
                        cout<<"2.英语"<<endl;
                        cout<<"3.C++"<<endl;
                        cout<<"4.退出"<<endl;
                        cout<<"请输入科目:";
                        cin>>t;
                        if(t>=1&&t<=3){
                            while(stu.setscore(t)){
                                
                            }
                        }
                        else if(t!=4){
                            cout<<"*****************************************"<<endl;
                            cout<<"输入无效!"<<endl;
                        }
                    }
                    con.addstudent(stu);
                    break;
                }

                case 2:{
                    int choice1=10;
                    while(choice1!=4){
                        cout<<"******************************"<<endl;
                        cout<<"管理班级:"<<endl;
                        cout<<"1.查看平均成绩"<<endl;
                        cout<<"2.统计学生总数"<<endl;
                        cout<<"3.展示全部学生"<<endl;
                        cout<<"4.退出"<<endl;
                        cout<<"请输入需要的功能序号:";
                        cin>>choice1;

                            if(choice1==1){
                                int k=INT_MAX;
                                while(k!=5){
                                    cout<<"*****************************"<<endl;
                                    cout<<"平均成绩查看:"<<endl;
                                    cout<<"1.数学"<<endl;
                                    cout<<"2.英语"<<endl;
                                    cout<<"3.C++"<<endl;
                                    cout<<"4.总分"<<endl;
                                    cout<<"5.退出"<<endl;
                                    cout<<"请输入您要查看的成绩:";
                                    cin>>k;
                                    if(k==1){
                                        cout<<"数学平均成绩为:"<<con.averagescore(k)<<endl;
                                    }
                                    else if(k==2){
                                        cout<<"英语平均成绩为:"<<con.averagescore(k)<<endl;
                                    }
                                    else if(k==3){
                                        cout<<"C++平均成绩为:"<<con.averagescore(k)<<endl;
                                    }
                                    else if(k==4){
                                        cout<<"总分平均成绩为:"<<con.averagescore(k)<<endl;
                                    }
                                }
                            }
                            //1.查看平均成绩

                            else if(choice1==2){
                                cout<<"*****************************"<<endl;
                                cout<<"学生总数为:"<<con.getsize()<<endl;
                            }
                            //2.统计学生总数

                            else if(choice1==3){
                                cout<<"*****************************"<<endl;
                                con.displayclass();
                                break;
                            }
                            //3.展示全部学生

                        }
                        break;
                    }

                case 3:{
                    cout<<endl;
                    cout<<"结束运行,Have a nice day!^^"<<endl;
                    return 0;
                    }
                
            }
        }
}