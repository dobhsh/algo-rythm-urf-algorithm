//job seq
#include<iostream>
using namespace std;

int min(int a, int b){
	if(a<b)
		return a;
	else
		return b;
}

int ts[10], dmax;

void jsd(int d[], int p[], int n){
	int i, j, k, t, a[10];
	for(i=0; i<n; i++)
		a[i] = i+1;
		
	dmax = d[0];
	
	for(i=0; i<n; i++){
		if(dmax<d[i])
			dmax = d[i];
	}
	
	for(i=0; i<n-1; i++){
		for(j=i+1; j<n; j++){
			if(p[1]<p[j]){
				t = p[i];
				p[i] = p[j];
				p[j] = t;
				
				t = d[i];
				d[i] = d[j];
				d[j] = t;
				
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
	
	for(i=0; i<min(n,dmax); i++)
		ts[i] = 0;
		
	for(i=0; i<n; i++){
		k=min(n-1, d[i]-1);
		while(k>=0){
			if(ts[k]==0)
			{ts[k]=a[i]; break;
			}
			k--;
		}
	}
}

int main(){
	int i, n, d[10], p[10];
	cout<<"no of jobs ";
	cin>>n;
	cout<<" d and p\n";
	for(i=0; i<n; i++){
		cin>>d[i]>>p[i];
	}
	cout<<"res\n";
	jsd(d,p,n);
	
	for(int i=0; i<min(dmax, n); i++){
		if(ts[i]!=0){
			cout<<"job"<<ts[i]<<" ";
		}
	}
	return 0;
}
