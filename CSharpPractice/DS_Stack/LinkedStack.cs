/*
 * --------------------------------------
 * @author tkorays <tkorays@hotmail.com>
 * 
 * @CreateTime 2013/9/8
 * 
 * @Description Linked Stack
 * --------------------------------------
 */
using System;

using LinearList;

namespace XStack
{
	// 使用了以前写的SingleLinkedList类
	public class LinkedStack<T>:SingleLinkedList<T>
	{
		private SingleLinkedNode<T> top;
		public LinkedStack():base()
		{
			top = base.Head.Next;
		}
		public override bool Empty
		{
			get{
				return top==null;
			}
		} 
		public void Push(T k){
			SingleLinkedNode<T> q = new SingleLinkedNode<T>(k);
			q.Next = top;
			top = q;
			base.Head.Next=top;
		}
		public T Pop(){
			T k = default(T);
			if (!Empty) {
				k=top.Item;
				top= top.Next;
				base.Head.Next = top;
				return k;
			}else{
				throw new InvalidOperationException("Stack is Empty: "+this.GetType());
			}
		}
		public T Peek(){
			if (!Empty) {
				return top.Item;
			}else{
				throw new InvalidOperationException("Stack is Empty: "+this.GetType());
			}
		}
	}
}
