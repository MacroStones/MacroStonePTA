/*Problem Description
把一个字符三角形掏空，就能节省材料成本，减轻重量，但关键是为了追求另一种视觉效果。在设计的过程中，需要给出各种花纹的材料和大小尺寸的三角形样板，通过电脑临时做出来，以便看看效果。

Input
每行包含一个字符和一个整数n(0<n<41)，不同的字符表示不同的花纹，整数n表示等腰三角形的高。显然其底边长为2n-1。如果遇到@字符，则表示所做出来的样板三角形已经够了。

Output
每个样板三角形之间应空上一行，三角形的中间为空。显然行末没有多余的空格。

Sample Input
X 2
A 7
@

Sample Output
 X
XXX
　
      A
     A A
    A   A
   A     A
  A       A
 A         A
AAAAAAAAAAAAA
*/