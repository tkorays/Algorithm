/*
 * --------------------------------------
 * @author tkorays <tkorays@hotmail.com>
 * 
 * @CreateTime 2013/9/2
 * 
 * @Description Double Linked List
 * --------------------------------------
 */
using System;

namespace tk
{
	/// <summary>
	/// 双向链表节点类
	/// </summary>
	public class DoubleLinkedNode<T>{
		private T item;
		private DoubleLinkedNode<T> prior,next;
		
		public DoubleLinkedNode(T k){
			item = k;
			prior = next = null;
		}
		public DoubleLinkedNode(){
			prior=next=null;
		}
		public T Item{
			get{return item;}
			set{item = value;}
		}
		public DoubleLinkedNode<T> Next{
			get{return next;}
			set{next=value;}
		}
		public DoubleLinkedNode<T> Prior{
			get{return prior;}
			set{prior=value;}
		}
	}
	
	/// <summary>
	/// 双向链表类
	/// </summary>
	public class DoubleLinkedList<T>{
		private DoubleLinkedNode<T> head;
		public DoubleLinkedList(){
			head = new DoubleLinkedNode<T>(); // 指向作为标志的头节点
		}
		protected DoubleLinkedNode<T> Head{
			get{return head;}
			set{head = value;}
		}
		public virtual bool Empty{
			get{return head.Next==null;}
		}
		public virtual void Insert(int i,T k){
			int j=0;
			DoubleLinkedNode<T> p = head;
			DoubleLinkedNode<T> q= head.Next;
			if (i<0) {
				i=0;
			}
			DoubleLinkedNode<T> t = new DoubleLinkedNode<T>(k);
			while (q!=null) {
				if (i==j) {
					break;
				}
				p=q;
				q=q.Next;
				j++;
			}
			t.Next = p.Next;
			t.Prior = p;
			p.Next = t;
			if (q!=null) {
				q.Prior = t;
			}
		}
		
		public void RemoveAt(int i){
			int j=0;
			DoubleLinkedNode<T> p = head;
			DoubleLinkedNode<T> q = head.Next;
			while(q!=null){
				if (i==j) {
					p.Next = q.Next;
					(p.Next).Prior = p;
					return ;
				}
				p=q;
				q=q.Next;
				j++;
			}
			throw new IndexOutOfRangeException("Index Out Of Range Exception in "+this.GetType());
		}
		
	}
}
