/*
 * --------------------------------------
 * @author tkorays <tkorays@hotmail.com>
 * 
 * @CreateTime 2013/10/10
 * 
 * @Description Sequenced String
 * --------------------------------------
 */
using System;

namespace tk
{
	/// <summary>
	/// Description of SequencedString.
	/// </summary>
	public class SequencedString{
		private char[] items;
		private int count = 0;
		
		public SequencedString(int n){
			items = new char[n];
			count = 0;
		}
		public SequencedString():this(16){}
		
		public SequencedString(char c):this(16){
			items[0] = c;
			count ++;
		}
		
		public SequencedString(char[] c):this(c.Length*2){
			Array.Copy(c,items,c.Length);
			count = c.Length;
		}
		public int Length{
			get{return count;}
		}
		public bool Empty{
			get{return count==0;}
		}
		public bool Full{
			get{return count==items.Length;}
		}
		
		public char this[int i]{
			get{
				if (i>=0 && i<count) {
					return items[i];
				}else{
					throw new IndexOutOfRangeException("Index Out Of Range Exception in :"+this.GetType());
				}
			}
			set{
				if (i>=0 && i<count) {
					items[i]=value;
				}else{
					throw new IndexOutOfRangeException("Index Out Of Range Exception in :"+this.GetType());
				}
			}
		}
		
		public void Concat(char c){
			if (Full) {
				DoubleCapacity();
			}	
			this.items[count] = c;
			count ++;
		}
		public void DoubleCapacity(){
			int len = Length;
			int capacity = 2* items.Length;
			char[] copy = new char[capacity];
			for (int i = 0; i < len; i++) {
				copy[i] =  items[i];
			}
			items = copy;
		}
		
		public void Concat(SequencedString s2){
			for (int i = 0; i < s2.Length; i++) {
				this.Concat(s2[i]);
			}
		}
		
		public static SequencedString operator +(SequencedString s1,SequencedString s2){
			SequencedString newstr = new SequencedString(s1.Length+s2.Length);
			newstr.Concat(s1);
			newstr.Concat(s2);
			return newstr;
		}
		
		public SequencedString Substring(int i,int n){
			int j=0;
			if ((i>=0 && n>=0) && (i+n<=this.Length)) {
				SequencedString sub = new SequencedString(n*2);
				while (j<n) {
					sub.items[j]= this.items[i+j];
					j++;
				}
				sub.count = j;
				return sub;
			}else{
				return null;
			}
		}
		
		public int IndexOf(SequencedString sub){
			int i=0,j;
			bool found = false;
			if (sub.Length == 0) {
				return 0;
			}
			while (i<count) {
				j=0;
				while (j<sub.Length && this.items[i+j] == sub[j]) {
					j++;
				}
				if (j == sub.Length) {
					found = true;
					break;
				}else{
					i++;
				}
			}
			if (found) {
				return i;
			}else{
				return -1;
			}
		}
		
		public void Show(){
			for (int i = 0; i < count; i++) {
				Console.Write(items[i]);
			}
			Console.WriteLine();
		}
		
		public char[] ToCharArray(){
			char[] tmp = new char[count];
			for (int i = 0; i < count; i++) {
				tmp[i] = items[i];
			}
			return tmp;
		}
		
		public override string ToString()
		{
			string s =new string(ToCharArray());
			return s;
		}
		public SequencedString Insert(int i,SequencedString s2){
			SequencedString sub1,sub2;
			sub1 = this.Substring(0,i);
			sub2 = this.Substring(i,this.Length -i);
			SequencedString newstr = new SequencedString(items.Length+s2.Length + 8);
			newstr.Concat(sub1);
			newstr.Concat(s2);
			newstr.Concat(sub2);
			return newstr;
		}
		
		public SequencedString Insert(int i,char c){
			SequencedString sub1,sub2;
			sub1 = this.Substring(0,i);
			sub2 = this.Substring(i,this.Length-i);
			SequencedString newstr = new SequencedString(items.Length+8);
			newstr.Concat(sub1);
			newstr.Concat(c);
			newstr.Concat(sub2);
			return newstr;
		}
		
		public SequencedString Remove(int i,int n){
			SequencedString sub1,sub2,sub3;
			sub1 = this.Substring(0,i);
			sub2 = this.Substring(i,n);
			sub3 = this.Substring(i+n,this.Length-i-n);
			SequencedString newstr = new SequencedString(items.Length);
			newstr.Concat(sub1);
			newstr.Concat(sub3);
			return newstr;
		}
		public SequencedString Replace(SequencedString oldsub,SequencedString newsub){
			int i,n;
			SequencedString sub1,sub3;
			SequencedString newstr = new SequencedString(items.Length+newsub.Length);
			i = this.IndexOf(oldsub);
			if (i!=-1) {
				sub1 = this.Substring(0,i);
				n = oldsub.Length;
				sub3 = this.Substring(i+n,this.Length-i-n);
				newstr.Concat(sub1);
				newstr.Concat(newstr);
				newstr.Concat(sub3);
			}
			return newstr;
		}
		public SequencedString Reverse(){
			int i;
			SequencedString newstr = new SequencedString(items.Length);
			for (i = this.Length-1; i >= 0; i--) {
				newstr.Concat(this.items[i]);
			}
			return newstr;
		}
 
	}
}
