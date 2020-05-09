int main(){ 
    int i,j,k,r;
    i =3;
    j=4;
    k=8;
    printf (i);
    r=(i+j)*(i+k/j);
    printf ( r );
    if(i == 3){
        i = 0;
    } else {
        i = i + 5;
    }
    return 0;
}
