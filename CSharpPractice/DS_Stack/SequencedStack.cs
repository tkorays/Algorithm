/*
 * --------------------------------------
 * @author tkorays <tkorays@hotmail.com>
 * 
 * @CreateTime 2013/9/8
 * 
 * @Description Sequenced Stack
 * --------------------------------------
 */
using System;

namespace XStack
{

	public class SequencedStack<T>
	{
		private T[] items;
		private const int empty = -1;
		private int top = empty;
		
		public SequencedStack(int n)
		{
			items = new T[n];
			top = empty;
		}
		public SequencedStack():this(16){}
		
		public int Count{
			get{
				return top+1;
			}
		}
		public bool Empty{
			get{
				return top==empty;
			}
		}
		public bool Full{
			get{
				return top>=items.Length-1;
			}
		}
		public void Push(T k){
			if (Full) {
				DoubleCapacity();
			}
			top++;
			items[top]=k;
		}
		private void DoubleCapacity(){
			int count = Count;
			int capacity = 2*items.Length;
			T[] copy = new T[capacity];
			for (int i = 0; i < count; i++) {
				copy[i] = items[i];
			}
			items = copy;
		}
		public T Pop(){
			T k = default(T);
			if (!Empty) {
				k=items[top];
				top --;
				return k;
			}else{
				throw new InvalidOperationException("Stack is Empty: "+this.GetType());
			}
		}
		public T Peek(){
			if (!Empty) {
				return items[top];
			}else{
				throw new InvalidOperationException("Stack is Empty: "+this.GetType());
			}
		}
		public void Show(bool showTypeName){
			if (showTypeName) {
				Console.Write("Stack: ");
			}
			if (!Empty) {
				for (int i = this.top; i >= 0; i--) {
					Console.Write(items[i]+" ");
				}
				Console.WriteLine();
			}
		}
	}
}
