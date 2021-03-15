
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int ClassID;
    int StuID;
    int Grade;
    struct node *next;
}StudentLinkedListNode;


/* 打印单个节点 */
void printLinkedListNode(StudentLinkedListNode * node){
    printf("{name:%s, ID:%d, Grade:%d}",node->ClassID, node->StuID, node->Grade);
    if(node->next!=NULL){
        printf("->");
    }else
    {
        printf("\n");
    }

}

/* 输出该表的成绩情况 */
void outputStudentLinkedList(StudentLinkedListNode* head){
    // 用于单个节点输出的函数printLinkedListNode已提供
    //请你实现遍历链表的逻辑
	//TODO
}


/** 新建一个链表node并返回 */
StudentLinkedListNode* studentLinkedListCreate( int class_id,int student_id,int grade) {
    //tips:malloc的时候记得为转化为结构体指针
	//TODO
}

/** copy一个已有的node */
StudentLinkedListNode* studentLinkedListCopy(StudentLinkedListNode* src){
    StudentLinkedListNode* tempNode = studentLinkedListCreate(src->ClassID,src->StuID,src->Grade);
    return tempNode;
}



/** 按照降序插入学生的成绩情况,并返回链表头指针 */
StudentLinkedListNode* studentLinkedListAdd(StudentLinkedListNode* head, StudentLinkedListNode* node) {
//TODO

}
/** 根据学号搜索某个学生的成绩情况 如果没有,请printf("this class  has no such student as id=%d",id)； */
void searchByID(StudentLinkedListNode*head ,int id){
//TODO
}

/** 根据学号删除某个学生的成绩情况 如果没有,请printf("this class has no such student as id=%d",id);*/
StudentLinkedListNode* deleteByID(StudentLinkedListNode* head,int id){
//TODO
}


/** 合并两个班级的成绩情况 */
StudentLinkedListNode* mergeLinkedList(StudentLinkedListNode* heads[]){
    //tips:因为传入的都是指针,为了防止拆分过程中影响了原来总链表的存储,
    //在链表node赋值的时候可以用上面提供的studentLinkedListCopy函数
    //如 node->next = temp_node 改为 node->next = studentLinkedListCopy(temp_node)
	//TODO
}

StudentLinkedListNode* reverseLinkedList(StudentLinkedListNode*head){
//TODO
}

int main(){
        StudentLinkedListNode* Class[2]={NULL};
        StudentLinkedListNode* All=NULL;
		StudentLinkedListNode* reAll=NULL;
        printf("1.insert 2.search by StuID 3.delete by StuID  4.merge 5.reverse 6.output  \n");

        int op;
        int i;
		
        int tempClass;
        int tempStuId;
        int tempGrade;
        char name[10];
        StudentLinkedListNode *tempNode;
        while (scanf("%d", &op) != EOF) {
            switch (op) {
                case 1:
                    printf("How many rows of data do you need to input?\n");
                    scanf("%d",&i);
                    printf("input the i row data format as:class_id,student_id,grade\n");
                    while (i!=0){
                        scanf("%d,%d,%d", &tempClass,,&tempStuId, &tempGrade);
                        tempNode = studentLinkedListCreate(tempClass, tempStuId, tempGrade);
                        Class[tempClass]=studentLinkedListAdd(Class[tempClass], tempNode);
                        i--;
                    }
                    break;
                case 2:
                    printf("input thedata format as: ClassID, StuID\n");
                    scanf("%d,%s",&tempClass,tempName);
                    searchByID(Class[tempClass], tempName);
                    break;
                case 3:
                    printf("input the data format as: ClassID, StuID\n");
                    scanf("%d,%d",&tempClass,&tempStuId);
                    Class[tempClass]=deleteByID(Class[tempClass], tempStuId);
                    break;
                case 4:
                    All=mergeLinkedList(Class);
                    outputStudentLinkedList(All);
                    break;
                case 5:
                    reAll=reverseLinkedList(All);
                    outputStudentLinkedList(reAll);
                    break;
                case 6:
                    printf("Class 0:\n");
                    outputStudentLinkedList(Class[0]);
                    printf("\nClass 1:\n");
                    outputStudentLinkedList(Class[1]);
                    break;

            }
            printf("\n###################################\n");
            printf("1.insert 2.search by studentID 3.delete by studentID 4.merge 5. reverse 6.output  \n");
    }
}
