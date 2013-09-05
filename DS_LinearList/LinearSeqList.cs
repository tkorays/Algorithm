/*
 * --------------------------------------
 * @author tkorays <tkorays@hotmail.com>
 * 
 * @CreateTime 2013/9/2
 * 
 * @Description Linear Sequenced List
 * --------------------------------------
 */
using System;
using System.Collections;
using System.Text;

namespace LinearList
{
	/// <summary>
	/// 线性表类
	/// SequencedList为顺序表类
	/// </summary>
	public class SequencedList<T>
	{
		private T[] items;
		private int count=0;
		private int capacity;
		
		public SequencedList(int c){
			capacity = c;
			items = new T[capacity];
			count = 0;
		}
		public SequencedList():this(16){
		}
		public SequencedList(T[] itemArray){
			count = itemArray.Length;
			capacity = count + 16;
			items = new T[capacity];
			for (int i = 0; i < count; i++) {
				items[i] =  itemArray[i];
			}
		}
		
		public int Count{
			get{
				return count;
			}
		}
		public bool Empty{
			get{
				return count==0;
			}
		}
		public int Capacity{
			get{
				return capacity;
			}
			set{
				capacity = value;
				T[] copy = new T[capacity];
				if(count>capacity){
					count = capacity;
				}
				Array.Copy(items,copy,count);
				items = copy;
			}
		}
		public T this[int i]{
			get{
				if(i>=0&&i<count){
					return items[i];
				}else{
					throw new IndexOutOfRangeException("Index Out Of Range Exception in"+this.GetType());
				}
			}
			set{
				if(i>=0&&i<count){
					items[i] = value;
				}else{
					throw new IndexOutOfRangeException("Index Out Of Range Exception in"+this.GetType());
				}
			}
		}
		public bool Contains(T k){
			int j = IndexOf(k);
			if(j!=-1){
				return true;
			}else{
				return false;
			}
		}
		public int IndexOf(T k){
			int j=0;
			while (j<count && !k.Equals(items[j])) {
				j++;
			}
			if(j>=0 && j<count){
				return j;
			}else{
				return -1;	
			}
		}
		public void Insert(int i,T k){
			if (count >= capacity) {
				Capacity = capacity*2;
			}
			if(i<0){ i=0;}
			if(i>count){
				for (int j = count-1; j >=i; j--) {
					items[j+1] = items[j];
				}
			}
			items[i] = k;
			count++;
			return ;
		}
		public void	Add(T k){
			if (count>=capacity) {
				Capacity = capacity*2;
			}
			items[count] = k;
			count++;
		}
		public void RemoveAt(int i){
			if (i>=0&&i<count) {
				for (int j = i+1; j < count; j++) {
					items[j-1] = items[j];
				}
				count --;
			}else{
				throw new IndexOutOfRangeException("Index Out Of Range Exception in"+this.GetType());
			}
		}
		public void Remove(T k){
			int i= IndexOf(k);
			if (i!=-1) {
				for (int j = i+1; j < count; j++) {
					items[j-1] = items[j];
				}
				count --;
			}else{
				Console.WriteLine(k+" is not found,you can't remove it1");
			}
		}
		public void Show(bool showTypeName){
			if (showTypeName) {
				Console.WriteLine("SequencedList: ");
			}
			for (int i = 0; i < this.count; i++) {
				Console.Write(items[i] + " ");
			}
			Console.WriteLine();
		}
		public override string ToString(){
			StringBuilder s = new StringBuilder();
			for (int i = 0; i < this.count; i++) {
				s.Append(items[i]);
				s.Append(": ");
			}
			return s.ToString();
		}
	}
}
