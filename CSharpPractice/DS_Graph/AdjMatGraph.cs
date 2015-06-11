/*
 * --------------------------------------
 * @author tkorays <tkorays@hotmail.com>
 * 
 * @CreateTime 2013/9/5
 * 
 * @Description Adjacency Matrix Graph
 * --------------------------------------
 */
using System;
using System.Collections.Generic;

namespace Graph
{
	public class Vertex<T> {
		private T data;
		private bool visited;
		public Vertex() {
			data = default(T);
			visited = false;
		}
		public Vertex(T data,bool visited) {
			this.data = data;
			this.visited = visited;
		}
		public Vertex(T data) {
			this.data = data;
			this.visited = false;
		}
		public T Data {
			get{
				return data;
			}
			set{
				data = value;
			}
		}
		public bool Visited {
			get{
				return visited;
			}
			set{
				visited = value;
			}
		}
		public void Show() {
			Console.Write("-"+this.data+"->");
		}
		public override string ToString()
		{
			return string.Format("->{0}->", this.data);
		}
	}
	
	public class AdjacencyMatrixGraph<T> {
		private int count = 0;
		private IList<Vertex<T>> vertexList;
		private int[,] AdjMat;
		private int MaxVertexCount=10;
		
		public AdjacencyMatrixGraph(int[,] adjmat) {
			int n = adjmat.GetLength(0);
			AdjMat = new int[n,n];
			Array.Copy(adjmat,AdjMat,n*n);
			vertexList = new List<Vertex<T>>();
			count = n;
		}
		public AdjacencyMatrixGraph() {
			AdjMat = new int[MaxVertexCount,MaxVertexCount];
			vertexList = new List<Vertex<T>>();
			count = 0;
		}
		public int Count {
			get{
				return count;
			}
			set{
				count = value;
			}
		}
		public T this[int i] {
			get{
				if(i>=0 && i<count){
					return vertexList[i].Data;
				}else{
					throw new IndexOutOfRangeException("Index Out Of Range Exception in "+ this.GetType());
				}
			}
			set{
				if(i>=0 && i<count) {
					vertexList[i].Data = value;
				}else{
					throw new IndexOutOfRangeException("Index Out Of Range Exception in "+this.GetType());
				}
			}
		}
		public void AddNodes(IList<Vertex<T>> nodes) {
			vertexList = nodes;
			count = vertexList.Count;
		}
		public int IndexOf(T k){
			int j = 0;
			while(j<count && !k.Equals(vertexList[j].Data)) {
				j++;
			}
			if (j>=0 && j<count) {
				return j;
			}else{
				return -1;
			}
		}
	}
	
}
