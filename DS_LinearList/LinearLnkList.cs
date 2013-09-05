/*
 * --------------------------------------
 * @author tkorays <tkorays@hotmail.com>
 * 
 * @CreateTime 2013/9/2
 * 
 * @Description Linear Linked List
 * --------------------------------------
 */
using System;
using System.Text;

namespace LinearList
{
	public class SingleLinkedNode<T> {
		private T item;
		private SingleLinkedNode<T> next;
		
		public SingleLinkedNode(T k){
			item =k;
			next = null;
		}
		public SingleLinkedNode(){
			next = null;
		}
		
		public T Item {
			get{
				return item;
			}
			set{
				item = value;
			}
		}
		public SingleLinkedNode<T> Next {
			get{
				return next;
			}
			set{
				next = value;
			}
		}
		
		public void Show(){
			SingleLinkedNode<T> p =this;
			while (p != null) {
				Console.Write(p.Item);
				p = p.Next;
				if(p != null){
					Console.Write("-> ");
				}else{
					Console.WriteLine(".");
				}
			}
		}
		public override string ToString()
		{
			StringBuilder s = new StringBuilder();
			SingleLinkedNode<T> p = this;
			while (p != null) {
				s.Append(p.Item);
				p = p.Next;
				if( p != null){
					s.Append("-> ");
				}else{
					s.Append(".");
				}
			}
			return s.ToString();
		}
	}
	
	public class SingleLinkedList<T> {
		private SingleLinkedNode<T> head;
		public SingleLinkedNode<T> Head{
			get{
				return head;
			}
			set{
				head = value;
			}
		}
		public SingleLinkedList() {
			head = new SingleLinkedNode<T>();
		}
		public SingleLinkedList(SingleLinkedNode<T> f):this() {
			head.Next = f;
		}
		public SingleLinkedList(T[] itemArray):this() {
			SingleLinkedNode<T> rear,q;
			rear = head;
			for (int i = 0; i < itemArray.Length; i++) {
				q = new SingleLinkedNode<T>(itemArray[i]);
				rear.Next = q;
				rear =q;
			}
		}
		public virtual int Count {
			get{
				int n=0;
				SingleLinkedNode<T> p = head.Next;
				while (p != null) {
					n++;
					p = p.Next;
				}
				return n;
			}
		}
		
		public virtual bool Empty {
			get{
				return 	head.Next == null;
			}
		}
		
		public virtual bool Full {
			get{
				return false;
			}
		}
		public virtual T this[int i] {
			get{
				if(i<0){
					throw new IndexOutOfRangeException("Index is negative in "+this.GetType());
				}
				int n=0;
				SingleLinkedNode<T> q = head.Next;
				while (q != null && i !=n) {
					n++;
					q =  q.Next;
				}
				if (q == null) {
					throw new IndexOutOfRangeException("Index Out Of Range Exception in "+this.GetType());
				}
				return q.Item;
			}
			set{
				if (i<0) {
					throw new IndexOutOfRangeException("Index is negative in "+this.GetType());
				}
				int n=0;
				SingleLinkedNode<T> q = head.Next;
				while (q!=null && i!=n) {
					n++;
					q=q.Next;
				}
				if (q==null) {
					throw new IndexOutOfRangeException("Index Out of Range Exception in "+this.GetType());
				}
				q.Item = value;
			}
		}
		
		public virtual void Show(bool showTypeName){
			if (showTypeName) {
				Console.Write("SingleLinkedList: ");
			}
			SingleLinkedNode<T> q = head.Next;
			if (q!=null) {
				q.Show();
			}
		}
		public override string ToString()
		{
			SingleLinkedNode<T> q= head.Next;
			if (q!=null) {
				return q.ToString();
			}else{
				return null;
			}
		}
		public virtual void Reverse() {
			SingleLinkedNode<T> p = head.Next,q=null,front=null;
			while (p!=null) {
				q=p.Next;
				p.Next = front;
				front= p;
				p=q;
			}
			head.Next = front;
		}
		public virtual void Insert(int i,T k){
			int j=0;
			SingleLinkedNode<T> p = head;
			SingleLinkedNode<T> q = p.Next;
			if (i<0) {
				i=0;
			}
			SingleLinkedNode<T> t = new SingleLinkedNode<T>(k);
			while (q!=null) {
				if (i==j) {
					break;
				}
				p=q;
				q=q.Next;
				j++;
			}
			t.Next = p.Next;
			p.Next = t;
		}
		public void Remove(T k){
			SingleLinkedNode<T> p =head;
			SingleLinkedNode<T> q = p.Next;
			while (q!=null) {
				if (k.Equals(q.Item)) {
					p.Next = q.Next;
					return ;
				}
				p = q;
				q = p.Next;
			}
			Console.WriteLine(k+" is not found,you can't remove it!");
		}
		
		public void RemoveAt(int i){
			int j=0;
			SingleLinkedNode<T> p = head;
			SingleLinkedNode<T>q = p.Next;
			while (q!=null) {
				if (j==i) {
					p.Next = q.Next;
					return ;
				}
				p=q;
				q=q.Next;
				j++;
			}
			throw new IndexOutOfRangeException("Index Out Of Range in "+this.GetType());
		}

	}
}
