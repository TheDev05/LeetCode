<h2><a href="https://leetcode.com/problems/node-with-highest-edge-score/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag">No companies found for this problem</div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px;"><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>2374. Node With Highest Edge Score</a></h2><h3>Medium</h3><hr><div><p>You are given a directed graph with <code>n</code> nodes labeled from <code>0</code> to <code>n - 1</code>, where each node has <strong>exactly one</strong> outgoing edge.</p>

<p>The graph is represented by a given <strong>0-indexed</strong> integer array <code>edges</code> of length <code>n</code>, where <code>edges[i]</code> indicates that there is a <strong>directed</strong> edge from node <code>i</code> to node <code>edges[i]</code>.</p>

<p>The <strong>edge score</strong> of a node <code>i</code> is defined as the sum of the <strong>labels</strong> of all the nodes that have an edge pointing to <code>i</code>.</p>

<p>Return <em>the node with the highest <strong>edge score</strong></em>. If multiple nodes have the same <strong>edge score</strong>, return the node with the <strong>smallest</strong> index.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img src="https://assets.leetcode.com/uploads/2022/06/20/image-20220620195403-1.png" style="width: 450px; height: 260px;">
<pre><strong>Input:</strong> edges = [1,0,0,0,0,7,7,5]
<strong>Output:</strong> 7
<strong>Explanation:</strong>
- The nodes 1, 2, 3 and 4 have an edge pointing to node 0. The edge score of node 0 is 1 + 2 + 3 + 4 = 10.
- The node 0 has an edge pointing to node 1. The edge score of node 1 is 0.
- The node 7 has an edge pointing to node 5. The edge score of node 5 is 7.
- The nodes 5 and 6 have an edge pointing to node 7. The edge score of node 7 is 5 + 6 = 11.
Node 7 has the highest edge score so return 7.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img src="https://assets.leetcode.com/uploads/2022/06/20/image-20220620200212-3.png" style="width: 150px; height: 155px;">
<pre><strong>Input:</strong> edges = [2,0,0,2]
<strong>Output:</strong> 0
<strong>Explanation:</strong>
- The nodes 1 and 2 have an edge pointing to node 0. The edge score of node 0 is 1 + 2 = 3.
- The nodes 0 and 3 have an edge pointing to node 2. The edge score of node 2 is 0 + 3 = 3.
Nodes 0 and 2 both have an edge score of 3. Since node 0 has a smaller index, we return 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == edges.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= edges[i] &lt; n</code></li>
	<li><code>edges[i] != i</code></li>
</ul>
</div>