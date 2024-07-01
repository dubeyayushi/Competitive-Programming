// https://www.geeksforgeeks.org/problems/sort-a-stack/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=sort-a-stack

/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

void sortedInsert(stack<int>&s, int x){
    if (s.empty() || x>s.top()){
        s.push(x);
        return;
    }
    
    int temp = s.top();
    s.pop();
    sortedInsert(s, x);
    
    s.push(temp);
}

/* The below method sorts the stack s 
you are required to complete the below method */
void SortedStack :: sort()
{
   //Your code here
   if (!s.empty()){
       int x = s.top();
       s.pop();
       sort();
       
       sortedInsert(s, x);
   }
   
   
}