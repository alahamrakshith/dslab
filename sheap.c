// does not work just prototype

Max heap
Assume a[max] \\n=last index of max heap tree
n=n+1, ptr=n, ele=a[n]
While (ptr>0)
{
   par=(ptr-1)/2
  if(ele=<a[par])
    {
       a[ptr]=ele;
       Return;
  }
a[ptr]=a[par]
ptr=par;
}
a[ptr]=ele;
exit


//Deletion
Max heap
Assume a[max]
ele=a[n],n=n-1, ptr=0, left=1, right=2
While (right<=n)
{
   if(ele>=a[left] and ele>=a[right] )
    {
       a[ptr]=ele;
       Return;
   }
else if (a[left]<a[right])
 {
  a[ptr]=a[right]
  ptr=right;
 }
else if (a[left]>a[right])
 {
  a[ptr]=a[left]
  ptr=left;
 }
left=(2*ptr)+1;
right=left+1;
}
if(left==n and ele<=a[left])
 a[ptr]=ele;
else
  {
    a[ptr]=a[left]
    a[left]=ele;
  }
exit
