int a[100000000],a1,b[100000000];
void q()
{
	int i,j;
	for(i=2;i<100000000;++i)
	b[i]=1;
	for(i=0;i*i<100000000;++i)
	if(b[i])
	for(j=2*i;j<100000000;j+=i)
	b[j]=0;
	a1=0;
	for(i=0;i<100000000;++i)
	if(b[i])
	a[a1++]=i;
}
