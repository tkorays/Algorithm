/*
 * --------------------------------------
 * @author tkorays <tkorays@hotmail.com>
 * 
 * @CreateTime 2013/9/15
 * 
 * @Description Linked Queue class
 * --------------------------------------
 */
using System;

namespace tk
{
	/// <summary>
	/// Description of LinkedQueue.
	/// </summary>
	public class LinkedQueue<T>{
		private SingleLinkedNode<T> front,rear;
		private SingleLinkedList<T> items;
		public LinkedQueue(){
			items = new SingleLinkedList<T>();
			front = items.Head.Next;
			rear = items.Head;
		}
		public int Count{
			get{return items.Count;}
		}
		public bool Empty{
			get{return (front == null)&&(rear == items.Head);}
		}
		public void Enqueue(T k){
			SingleLinkedNode<T> q = new SingleLinkedNode<T>(k);
			rear.Next = q;
			front = items.Head.Next;
			rear = q;
		}
		public T Dequeue(){
			T k = default(T);
			if (!Empty) {
				k=front.Item;
				front = front.Next;
				items.Head.Next = front;
				if (front==null) {
					rear = items.Head;
				}
				return k;
			}else{
				throw new InvalidOperationException("Queue is Empty: "+ this.GetType());
			}
		}
		public T Peek(){
			if (!Empty) {
				return front.Item;
			}else{
				throw new InvalidOperationException("Queue is Empty: "+ this.GetType());
			}
		}
	}
}
