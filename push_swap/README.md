# push_swap
hey there
all go though the subject without further ado

the main thing in the push_swap project is the algo the you will use that's what this readme is for i will explain the algo that i use.
but absolutely not the bubble sort, yes we need it but not know as i sade the first thing after we sort little number like 2, by the way 
we don't have to use the algo to sort like two numbers is this situation is batter to hardcode it like two numbers if gnot sorted just do
sa(swap a) operation and well do

i'm here just to expalin the algo that i use noting other then that;
first thing first the lats call it chunk_sort becuse there's not enufe resurses in this way of sorting numbers
ok, we know the number up_5< just do it, here we explain just the up_to_5>

we have to create first an array of int size of the stack_a and we need to sort them first that will help us to sort the stack
and yes we need the bubble sort here to sort the stack number and put it to the array of sort intgers, well do naaaaah there's more then that
you need to know why we do that, well based on this array we will sort the stack_a that why we create it you will see

after we create the array and sort it, now we have to set the index of every element in the stack_a for example:
stack_a -> 2 1 5 3 6 4
index   -> 0 0 0 0 0 0
array   -> 1 2 3 4 5 6

we have to fill the index of every element(node) based in the array we set the index
if 2(stack_a) == 1(array)
if 2(stack_a) == 2(array) -> index = 1;

stack_a -> 2 1 5 3 6 4
index   -> 1 0 4 2 5 3
array   -> 1 2 3 4 5 6

the qustion is why we have to set the index and based on it we will sort the numbers?
is some examples it will be easey to sort a number like 2 1 5 3 6 4 becuse it in assanding order but what is we have a long random numbers
that's why we need a way to sort every number that ever is you will have to sort it like this and you have stack_b to sort some number on it
and bring them back we you need it to stack_a 

the final step is to do the best move you can do reduce the operateion as you can
