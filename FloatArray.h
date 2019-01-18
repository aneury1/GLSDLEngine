#pragma once


template<const int array>
class FloatArray
{
  float floats[array];
  int len;
  public:
     FloatArray( float initial_value =0.0)
     {
         len = array;
         for(int i=0;i<len;i++)
         {
             floats[i]=initial_value;
         }
     }
     const float get(int index)const{
         return floats[index]; 
     }
};