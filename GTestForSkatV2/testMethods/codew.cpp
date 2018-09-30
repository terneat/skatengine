#include <gtest/gtest.h>

#include <stdlib.h>
#include <stdio.h>

char* jumpf(char* code)
{
  int counter = 0;
  while(*code!=']' || counter != 0)
  {
      if(*code=='[')++counter;
      if(*code==']')--counter;
      ++code;
  }
  ++code;
  return code;
}

char* jumpb(char* code)
{
  int counter = 0;
  while(*code!='[' || counter != 0)
  {
      if(*code==']')++counter;
      if(*code=='[')--counter;
      --code;
  }
  ++code;

  return code;
}


char* brain_luck(char* code, char* input)
{
  char* result = (char*)calloc(100, sizeof(char));
  int lres = 0;
  char* rescp = result;
  int fdata[100] = {0};
  int* data = fdata;

  printf("%s\n",code);

  int counter=0;
  while(*code!='\0')
  {
      ++counter;
    if(*code=='>')
        {++data;++code;}
    else if(*code=='<')
        {--data;++code;}
    else if(*code=='+')
        {++code;++(*data);if(*data==256)*data=0;}
    else if(*code=='-')
        {++code;--(*data);if(*data==-1)*data=255;}
    else if(*code=='.')
        {if(result == '\0')break;++code;*result=*data;
        if(result == '\0')break;
        ++result;++lres;}
    else if(*code==',')
    {
            ++code;
            if(*input=='\0')*data=0;else{*data=*input;++input;}
    }
    else if(*code=='[')
        {if(*data==0){code = jumpf(++code);}else{++code;}}
    else if(*code==']')
        {if(*data!=0){code = jumpb(--code);}else{++code;}}
    else ++code;

  }

  *result='\0';++lres;
  char* ret = (char*)calloc(lres, sizeof(char));
  memcpy(ret, rescp, lres);
  result = rescp;
  rescp=0;
  free(result);
  return ret;
}

TEST (codew, bfuck) {

    char* second = brain_luck(",[>,]<[.<]", "test123");
    printf("%s \n",second);


    char* first = brain_luck(",+[-.,+]", "codewars");
    printf("%s \n",first);




    free(first);
    free(second);
}
