/*
 * --------------------------------------
 * @author tkorays <tkorays@hotmail.com>
 * 
 * @CreateTime 2013/9/15
 * 
 * @Description Sequenced Queue class
 * --------------------------------------
 */
using System;

namespace tk
{
	/// <summary>
	/// Description of SequencedQueue.
	/// </summary>
	public class SequencedQueue<T>{
		private T[] items;
		private int front,rear;
		public SequencedQueue(int n){
			items = new T[n+1];
			front = rear = 0;
		}
		public SequencedQueue():this(16){}
		
		public int Count{
			get{return (front - rear + items.Length)%items.Length;}
		}
		public bool Empty{
			get{return front == rear;}
		}
		public bool Full{
			get{
				return front == (rear+1)%items.Length;
			}
		}
		public void Enqueue(T k){
			if (Full) {
				DoubleCapacity();
			}
			items[rear] = k;
			rear = (rear+1)%items.Length;
		}
		public void DoubleCapacity(){
			int i,j;
			int capacity = 2*items.Length-1;
			int count = Count;
			T[] copy = new T[capacity];
			for (i = 0; i < count; i++) {
				j = (i+front)%items.Length;
				copy[i] = items[j];
			}
			front = 0;
			rear = count;
			items = copy;
		}
		public T Dequeue(){
			T k = default(T);
			if (!Empty) {
				k = items[front];
				front = (front+1)%items.Length;
				return k;
			}else{
				throw new InvalidOperationException("Queue is Empty: "+this.GetType());
			}
		}
		public T Peek(){
			if (!Empty) {
				return items[front];
			}else{
				throw new InvalidOperationException("Queue is Empty: "+ this.GetType());
			}
		}
		public void Show(bool showTypeName){
			if (showTypeName) {
				Console.Write("Queue：");
			}
			int i = this.front;
			int n = i;
			if (!Empty) {
				if (i<this.rear) {
					n = this.rear - 1;
				}else{
					n = this.rear + this.items.Length - 1;
				}
				for (;i  < n;i ++) {
					Console.Write(items[i%items.Length]+" ");
				}
			}
			Console.WriteLine();
		}
		
	}
}
