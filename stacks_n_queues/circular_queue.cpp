/*
 *
 * private data:
 *  an array: arr
 *  an int: head
 *  an int: tail
 *  an int: count
 *
 *  to init, set 'count = head = tail = 0'
 *  to insert a new item, place it in arr[tail],
 *      and increment count  tail
 *
 *  to deqeue the head, fetch arr[head], increment head,
 *      and decrement count
 *
 *  if the had or tail go past, set it back to 0
