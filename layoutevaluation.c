
Assume a postfix expression in p[]
  	while(p[i]!='\0')
  	{
  	if(p[i] is equal to ('+','-','/','*'))
  	{
  	op2=pop();
  	op1=pop();
  	switch(p[i])
  	{
  	case '+' : push(op1+op2);
  	break.
  	case '-' : push(op1-op2);
  	break.
  	case '/' : push(op1/op2);
 	 break.
 	 case '*' : push(op1*op2);
  	break.
    }
    }
 	else
 	   push(p[i]-'0').
 	          i++;
  	}
  	print (result = pop()).
