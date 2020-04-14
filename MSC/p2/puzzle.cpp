#include <iostream>
using namespace std;
/*
void Reverse(int a[][3]){*/
    /*cout<<"Reverse start!"<<endl;*/
    /*int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            a[i][j]=!(a[i][j]);
        }
    }
}*/
/**
void InputData(char (*a1)[3], char (*a2)[3]){
    int i;char spass[2];

    for(i=0;i<3;i++){
        cin.getline(a1[i],4);
    }
    cin.getline(spass,2);
    for(i=0;i<3;i++){
        cin.getline(a2[i],4);
    }
}**/
/*
void show_matrix(int a[][3]){*/
    /*cout<<"Showing now!"<<endl;*/
    /*int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++)
            cout<<a[i][j];
        cout<<endl;
    }
}*/
/*
void PuzzleToArray(char (*p)[3], int (*a)[3]){
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(p[i][j]=='*')a[i][j]=1;
            else a[i][j]=0;
        }
    }
}*/

int row_operate(char P[][3], char (*A)[3], char (*M)[3]){
    /*cout<<"row_operate now!"<<endl;*/
    int i, j, k, mark=0, flag=1;
    char a, b, c;
    for(i=0;i<3;i++){
        a = A[i][0];
        b = A[i][1];
        c = A[i][2];
        if((a=='.')&&(a==b)&&(b==c)){
            mark=i+1;
        }
    }

    /**row[1]=000**/
    if(mark==1){
        for(i=0;i<3;i++){
            k=i+1;
            if(k==3)k=0;
            for(j=0;j<3;j++){
                M[i][j]=A[k][j];
                if(!(P[i][j]&M[i][j])){
                flag=0;break;
                }
            }
        }
    }
    /**row[3]=000**/
    if(mark==3){
        for(i=2;i>=0;i--){
            k=i-1;
            if(k==-1)k=2;
            for(j=0;j<3;j++){
                M[i][j]=A[k][j];
                if(!(P[i][j]&M[i][j])){
                flag=0;break;
                }
            }
        }
    }
    return flag;
}

int col_operate(char P[][3], char (*A)[3], char (*M)[3]){
    /*cout<<"col_operate now!"<<endl;*/
    int i, j, k, mark=0, flag=1;
    char a, b, c;
    for(i=0;i<3;i++){
        a = A[0][i];
        b = A[1][i];
        c = A[2][i];
        if(a=='.'&&(a==b)&&(b==c)){
            mark=i+1;
        }
    }

    /**col[1]=000**/
    if(mark==1){
        for(i=0;i<3;i++){
            k=i+1;
            if(k==3)k=0;
            for(j=0;j<3;j++){
                M[j][i]=A[j][k];
                if(!(P[j][i]&M[j][i])){
                flag=0;break;
                }
            }
        }
    }
    /**col[3]=000**/
    if(mark==3){
        for(i=2;i>=0;i--){
            k=i-1;
            if(k==-1)k=2;
            for(j=0;j<3;j++){
                M[j][i]=A[j][k];
                if(!(P[j][i]&M[j][i])){
                flag=0;break;
                }
            }
        }
    }
    return flag;
}


int Transform_90(char P[][3], char A[][3], char AT[][3]){
    /*cout<<"Transform_90 now!"<<endl;*/
    int i,j,n=3,dst=n-1,flag=1;
    for(i=0;i<n;i++,dst--){
        for(j=0;j<n;j++){
            AT[j][dst]=A[i][j];
            if(!(P[i][j]&AT[j][dst])){
                flag=0;break;
            }
        }
        if(!(flag))break;
    }

    return flag;
}

int equal_check(int a1[][3], int a2[][3]){
    /*cout<<"equal??"<<endl;*/
    int i,j,flag=0;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(a1[i][j]==a2[i][j])flag=1;
            else{flag=0;break;}
        }
        if(flag==0)break;
    }

    return flag;
}

void Final_stress_test(char a1[][3], char a2[][3]){
    char TEMP[3][3];
    char TEMP2[3][3];
    char TEMP_opera[3][3];
    int flag=0;
    while(!flag){
        flag = Transform_90(a1, a2, TEMP);
        if(flag)break;
        flag = Transform_90(a1, TEMP,TEMP2);
        if(flag)break;
        flag = Transform_90(a1,TEMP2,TEMP);
        if(flag)break;

        flag = row_operate(a1, a2,TEMP_opera);
        if(flag)break;
        flag = Transform_90(a1, TEMP_opera,TEMP);
        if(flag)break;
        flag = Transform_90(a1, TEMP,TEMP2);
        if(flag)break;
        flag = Transform_90(a1, TEMP2,TEMP);
        if(flag)break;

        flag = col_operate(a1, a2,TEMP_opera);
        if(flag)break;
        flag = Transform_90(a1, TEMP_opera,TEMP);
        if(flag)break;
        flag = Transform_90(a1, TEMP,TEMP2);
        if(flag)break;
        flag = Transform_90(a1, TEMP2,TEMP);
        if(flag)break;
    }

    if(flag)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}


char puzzle1[3][3];
char puzzle2[3][3];
/*int matrix1[3][3];
int matrix2[3][3];*/
int main(){
    while(cin>>puzzle1[0][0]>>puzzle1[0][1]>>puzzle1[0][2]>>puzzle1[1][0]>>puzzle1[1][1]>>puzzle1[1][2]>>puzzle1[2][0]>>puzzle1[2][1]>>puzzle1[2][2]>>puzzle2[0][0]>>puzzle2[0][1]>>puzzle2[0][2]>>puzzle2[1][0]>>puzzle2[1][1]>>puzzle2[1][2]>>puzzle2[2][0]>>puzzle2[2][1]>>puzzle2[2][2])
    {
    /**InputData(puzzle1,puzzle2)**/
    /*PuzzleToArray(puzzle1,matrix1);
    PuzzleToArray(puzzle2,matrix2);
    Reverse(matrix2);*/
    /*show_matrix(matrix1);
    show_matrix(matrix2);*/
    Final_stress_test(puzzle1,puzzle2);
    }
    return 0;
}
