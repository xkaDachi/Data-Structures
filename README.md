# Data-Structures
```diff
-Node** vs Node*
node** means a double pointer to a single pointer who points to a node object. 
You need node** pointer to make the head of a linked list at caller scope to point to something else 
(like a new node when you add a node ahead in the linked list or to point to NULL when you delete the only element present in the linked list).

So, when the above function gets called and if you had used node* instead of node** for head in function parameter, 
then changes made for pointing by head pointer inside function scope would not get reflected in the actual head pointer variable present at caller scope. 
This will happen because when you write node* head inside function argument, the address value will be passed from the calling function which will be stored inside node* head. 
So any future changes within function like making node* head to point to something else will be made on node* head present at function scope instead of actual node* head present at caller scope.
Hence, when you want to change the actual head pointer present at caller scope to point something else, 
you must pass the address of actual head pointer to a double pointer function argument. 
So, like in above code, within if block, you can see by using *head you can make actual head pointer present at caller scope to point NULL.
The above concept can be similarly applied to a delete function for a linked list.
The bottom line is “Changes made for pointing at a single pointer function parameter won’t get reflected in caller scope. 
You can manipulate the objects or values pointed by node* from inside function but you cannot manipulate the pointer present at caller scope to point something else by just using node*. 
Therefore, you use node** for manipulating pointers at caller scope and node* for manipulating objects at caller scope”.

Typically everywhere, coders use node** for pointing head pointer and node* for iterating. 
This does not mean that you cannot iterate over linked list using node**. 
All the things that can be achieved by node* can also be achieved by node**. 
It just makes simpler and cleaner to use node* for iteration stuff while node** for manipulating heads.
```
https://stackoverflow.com/questions/55654934/what-is-the-difference-between-node-head-versus-node-head
