#include <iostream>
#include <cstring>

using namespace std;

void Reverse(int a[][3]){
    /*cout<<"Reverse start!"<<endl;*/
    a=XOR(a);
    /*
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            a[i][j]=!(a[i][j]);
        }
    }*/
}

void InputData(char (*a1)[3], char (*a2)[3]){
    int i;char spass[2];

    for(i=0;i<3;i++){
        cin.getline(a1[i],4);
    }
    cin.getline(spass,2);
    for(i=0;i<3;i++){
        cin.getline(a2[i],4);
    }
}

void show_matrix(int a[][3]){/** a[][3] is equal to (*a)[3] **/
    /*cout<<"Showing now!"<<endl;*/
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++)
            cout<<a[i][j];
        cout<<endl;
    }
}

void PuzzleToArray(char (*p)[3], int (*a)[3]){
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(p[i][j]=='*')a[i][j]=1;
            else a[i][j]=0;
        }
    }
}

void row_operate(int (*A)[3], int (*M)[3]){
    /*cout<<"row_operate now!"<<endl;*/
    int i, j, k, mark=0;
    int a, b, c;
    for(i=0;i<3;i++){
        a = A[i][0];
        b = A[i][1];
        c = A[i][2];
        if(!(a||b||c)){
            mark=i+1;
            break;
        }
    }

    /**row[1]=000**/
    if(mark==1){
        for(i=0;i<3;i++){
            k=i+1;
            if(k==3)k=0;
            for(j=0;j<3;j++){
                M[i][j]=A[k][j];
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
            }
        }
    }

}

void col_operate(int (*A)[3], int (*M)[3]){
    /*cout<<"col_operate now!"<<endl;*/
    int i, j, k, mark=0;
    int a, b, c;
    for(i=0;i<3;i++){
        a = A[0][i];
        b = A[1][i];
        c = A[2][i];
        if(!(a||b||c)){
            mark=i+1;
            break;
        }
    }

    /**col[1]=000**/
    if(mark==1){
        for(i=0;i<3;i++){
            k=i+1;
            if(k==3)k=0;
            for(j=0;j<3;j++){
                M[j][i]=A[j][k];
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
            }
        }
    }

}


void Transform_90(int A[][3], int AT[][3]){
    /*cout<<"Transform_90 now!"<<endl;*/
    int i,j,n=3,dst=n-1;
    for(i=0;i<n;i++,dst--){
        for(j=0;j<n;j++){
            AT[j][dst]=A[i][j];
        }
    }
}

int equal_check(int a1[][3], int a2[][3]){
    /*cout<<"equal??"<<endl;*/
    int i,j,flag=0;
    /*
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(a1[i][j]==a2[i][j])flag=1;
            else{flag=0;break;}
        }
        if(flag==0)break;
    }*/
    flag = memcmp(a1,a2,sizeof(a1));

    return !(flag);
}

void Final_stress_test(int a1[][3], int a2[][3]){
    int TEMP[3][3];
    int TEMP2[3][3];
    int TEMP_opera[3][3];
    int flag=0;
    while(!flag){
        Transform_90(a2,TEMP);
        flag=equal_check(a1,TEMP);
        if(flag)break;
        Transform_90(TEMP,TEMP2);
        flag=equal_check(a1,TEMP2);
        if(flag)break;
        Transform_90(TEMP2,TEMP);
        flag=equal_check(a1,TEMP);
        if(flag)break;

        row_operate(a2,TEMP_opera);
        flag=equal_check(a1,TEMP_opera);
        if(flag)break;
        Transform_90(TEMP_opera,TEMP);
        flag=equal_check(a1,TEMP);
        if(flag)break;
        Transform_90(TEMP,TEMP2);
        flag=equal_check(a1,TEMP2);
        if(flag)break;
        Transform_90(TEMP2,TEMP);
        flag=equal_check(a1,TEMP);
        if(flag)break;

        col_operate(a2,TEMP_opera);
        flag=equal_check(a1,TEMP_opera);
        if(flag)break;
        Transform_90(TEMP_opera,TEMP);
        flag=equal_check(a1,TEMP);
        if(flag)break;
        Transform_90(TEMP,TEMP2);
        flag=equal_check(a1,TEMP2);
        if(flag)break;
        Transform_90(TEMP2,TEMP);
        flag=equal_check(a1,TEMP);
        if(flag)break;
    }

    if(flag)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}


char puzzle1[3][3];
char puzzle2[3][3];
int matrix1[3][3];
int matrix2[3][3];
int main(){
    InputData(puzzle1,puzzle2);
    PuzzleToArray(puzzle1,matrix1);
    PuzzleToArray(puzzle2,matrix2);
    Reverse(matrix2);
    /*show_matrix(matrix1);
    show_matrix(matrix2);*/
    Final_stress_test(matrix1,matrix2);
    return 0;
}
