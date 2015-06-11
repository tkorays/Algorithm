/*
 * 由SharpDevelop创建。
 * 用户： tkorays
 * 日期: 2013/9/28
 * 时间: 20:40
 * 
 * 表达式括号匹配
 */
using System;
using System.Collections.Generic;

namespace EX_MatchingBracket{
	class Program{
		public static void Main(string[] args){
			String expstr = "(5*6-6/3)*((6-9*9+8)*(9+9))(";
			Console.WriteLine("括号匹配结果：{0}",MatchingBracket(expstr));
			Console.Write("Press any key to continue . . . ");
			Console.ReadKey(true);
		}
		public static string MatchingBracket(String expstr){
			Stack<char> bracketStack = new Stack<char>();
			bool isOK = true;
			for (int i = 0; i < expstr.Length; i++) {
				switch (expstr[i]) {
					case '(':
						bracketStack.Push(expstr[i]);
						break;
					case ')':
						if (bracketStack.Count == 0) {
							isOK =  false;
						}else{
							bracketStack.Pop();
						}
						break;
					default:
						
						break;
				}
			}
			if (isOK) {
				if(bracketStack.Count == 0){
					return "OK";
				}else{
					return "期望)!";
				}
			}else{
				return "期望(!";
			}
		}
	}
}