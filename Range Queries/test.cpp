#include<stdio.h>
typedef long long int lli;
lli c=0;
lli past=0;
void merge(lli *a,lli l,lli m,lli r){
    lli n1=m+1-l;
    lli n2=r-m;
    lli a1[n1],a2[n2];
    for(lli i=0;i<n1;i++){
        a1[i]=a[l+i];
    }
    for(lli i=0;i<n2;i++){
        a2[i]=a[m+1+i];
    }
    lli i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(a1[i]<=a2[j]){
            a[k++]=a1[i++];
        }
        else{
            a[k++]=a2[j++];
        c+=n1-i;
        }
    }
while(i<n1){
    a[k++]=a1[i++];

}
while(j<n2){
    a[k++]=a2[j++];
    
}
    
}
void mergesort(lli *a,lli l,lli r){
    if(l<r){
        lli m=(l+r)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,r);
        merge(a,l,m,r);
    }
}
lli insertionSort(lli n, lli *a) {
lli res;
    mergesort(a,0,n-1);
for(int i=0;i<n;i++)

    res= c-past;
    past=c;
    return res;
    
}

int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
    lli n;
    scanf("%lld",&n);
    lli a[n];
    for(lli i=0;i<n;i++)
    scanf("%lld",&a[i]);
    lli r=insertionSort(n,a);
    printf("%lld\n",r);
    }
}