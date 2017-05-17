#include <jni.h>
#include <stdio.h>
#include "Call.h"
#include "time.h"

JNIEXPORT jintArray JNICALL Java_Call_Heapsort(JNIEnv *env, jobject thisObj, jintArray in) 
{
   jint *source = (*env)->GetIntArrayElements(env, in, NULL);
   if (NULL == source) return NULL;

   jsize length = (*env)->GetArrayLength(env, in);
 
   int child, parent, best, left, right;
   int i, temp;

   for (i = 0; i < length; i++)
   {
	   child = i;
	   parent = child / 2;

	   while (parent != -1 && source[child] > source[parent])
	   {
		   temp = source[child];
		   source[child] = source[parent];
		   source[parent] = temp;

		   child = parent;
		   parent = child / 2;
	   }
   }

   for (i = length - 1; i > 0; i--)
   {
	   parent = 0;

	   temp = source[parent];
	   source[parent] = source[i];
	   source[i] = temp;

	   left = parent * 2;
	   right = left + 1;
	   best = ((left > i - 1 || left == i - 1 || source[left] > source[right]) ? left : right);


	   while (best < i && source[best] > source[parent])
	   {
		   temp = source[parent];
		   source[parent] = source[best];
		   source[best] = temp;

		   parent = best;

		   left = parent * 2;
		   right = left + 1;

		   best = ((left > i - 1 || left == i - 1 || source[left] > source[right]) ? left : right);
	   }

   }
 
   jintArray out = (*env)->NewIntArray(env, length); 
   if (NULL == out) return NULL;
   (*env)->SetIntArrayRegion(env, out, 0 , length, source); 
   return out;
}
