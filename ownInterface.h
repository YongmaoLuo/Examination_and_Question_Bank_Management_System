#ifndef OWNINTERFACE
#define OWNINTERFACE

#include <QString>
#include <QDir>
#include <QDialog>

class Login{// 登录模块
protected:
    QString userName,identity;
    virtual void submit_login(QString userName,QString password)=0;// 提交登录请求
    virtual void store_login_information(QString userName,QString identity)=0;// 储存登录用户的信息，供未来操作中查询使用
public:
    virtual void open_login_panel()=0;// 打开登录窗口
};

class Admin{// 系统管理员模块
protected:
    virtual void read_applicants(QDir applicantsDir)=0; // 读取所有申请者的信息，并且呈现出来
    virtual void read_users(QDir usersDir)=0; // 读取所有系统用户，并且呈现出来
    virtual void agree_applicant(QString applicantName)=0; // 通过用户申请
    virtual void reject_applicant(QString applicantName)=0; // 拒绝用户申请
    virtual void delete_user(QString userName)=0; // 删除系统中的用户
    virtual void close_admin_panel()=0;// 关闭管理员窗口
public:
    virtual void open_admin_panel()=0;// 打开管理员窗口

};

class SignUp{// 注册模块
protected:
    virtual void submit_signup(QString userName,QString password,QString identity)=0;// 提交注册请求
    virtual void close_signup_panel()=0;// 关闭注册窗口
public:
    virtual void open_signup_panel()=0;// 打开注册窗口
};

class RuleMaker{// 试卷规则制定者模块
protected:
    QDir rulemakerDir;
    virtual void create_bulletin(QDir rulemakerDir,QString timeStamp)=0;// 创建新公告
    virtual void delete_bulletin(QDir rulemakerDir,QString timeStamp)=0;// 删除系统中自己以前发布的公告
    virtual void load_bulletin(QDir rulemakerDir,QString timeStamp)=0;// 加载选中的某个公告到编辑板
    virtual void write_bulletin(QDir rulemakerDir,QString timeStamp,QString bulletinText)=0;// 修改系统中存在的公告
    virtual void read_bulletins(QDir rulemakerDir)=0;// 读取自己在系统中的所有的公告
    virtual void close_rulemaker_panel()=0;// 关闭试卷规则制定者的界面
public:
    virtual void open_rulemaker_panel()=0;// 打开试卷规则制定者的界面
};

class QuestionManagement{// 题库管理模块
protected:
    QDir libraryDir;
    virtual void read_subjects(QDir libraryDir)=0;// 读取题库中含有的科目内容
    virtual void read_chapters(QString subject)=0;// 读取某个科目中所有的章节
    virtual void read_questions(QString subject,QString chapter)=0;// 读取某个科目某个章节中所有题目
    virtual void add_subject(QString subject)=0;// 在题库中添加科目
    virtual void add_chapter(QString subject,QString chapter)=0;// 给某一科目添加章节
    virtual void add_question(QString subject,QString chapter,QString timeStamp)=0;// 给某一科目某一章节添加题目
    virtual void delete_subject(QString subject)=0;// 在题库中删除题目
    virtual void delete_chapter(QString subject,QString chapter)=0;// 从某一科目删除章节
    virtual void delete_question(QString subject,QString chapter,QString timeStamp)=0;// 从某一科目某一章节删除题目
    virtual void load_question(QString subject,QString chapter,QString timeStamp)=0;// 从某科目某章节加载某题目
    virtual void write_question(QString subject,QString chapter,QString timeStamp,QString questionText)=0;// 修改某科目某章节某题目内容
    virtual void close_question_management_panel()=0;// 关闭题库管理窗口
public:
    virtual void open_question_management_panel()=0;// 打开题库管理窗口
};

class PaperProduction{// 制作试卷模块
protected:
    QStringList questionsList;// 储存试卷题目的列表
    virtual void delete_question(QString questionName)=0;// 在试卷中删除某题目
    virtual void output_paper(QDir paperDir,QStringList questionsList)=0;// 输出试卷
    virtual void read_questions(QStringList questionsList)=0;// 读取目前试卷题目列表中的所有题目，并且呈现出来
public:
    virtual void add_question(QString subject,QString chapter,QString timeStamp)=0;// 向试卷中添加某题目
    virtual void open_paper_production_panel()=0;// 打开试卷制作窗口
    virtual void close_paper_production_panel()=0;// 关闭试卷制作窗口
};

#endif
