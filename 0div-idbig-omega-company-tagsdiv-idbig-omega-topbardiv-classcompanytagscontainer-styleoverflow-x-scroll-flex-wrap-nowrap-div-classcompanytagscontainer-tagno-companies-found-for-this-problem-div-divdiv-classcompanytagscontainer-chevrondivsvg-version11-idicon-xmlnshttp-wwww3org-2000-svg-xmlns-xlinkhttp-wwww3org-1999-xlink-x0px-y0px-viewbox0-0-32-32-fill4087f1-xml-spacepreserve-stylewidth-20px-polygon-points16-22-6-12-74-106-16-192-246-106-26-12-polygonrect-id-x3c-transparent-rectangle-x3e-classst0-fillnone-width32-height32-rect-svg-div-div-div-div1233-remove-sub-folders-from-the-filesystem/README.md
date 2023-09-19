<h2><a href="https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag">No companies found for this problem</div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px;"><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>1233. Remove Sub-Folders from the Filesystem</a></h2><h3>Medium</h3><hr><div><p>Given a list of folders <code>folder</code>, return <em>the folders after removing all <strong>sub-folders</strong> in those folders</em>. You may return the answer in <strong>any order</strong>.</p>

<p>If a <code>folder[i]</code> is located within another <code>folder[j]</code>, it is called a <strong>sub-folder</strong> of it.</p>

<p>The format of a path is one or more concatenated strings of the form: <code>'/'</code> followed by one or more lowercase English letters.</p>

<ul>
	<li>For example, <code>"/leetcode"</code> and <code>"/leetcode/problems"</code> are valid paths while an empty string and <code>"/"</code> are not.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> folder = ["/a","/a/b","/c/d","/c/d/e","/c/f"]
<strong>Output:</strong> ["/a","/c/d","/c/f"]
<strong>Explanation:</strong> Folders "/a/b" is a subfolder of "/a" and "/c/d/e" is inside of folder "/c/d" in our filesystem.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> folder = ["/a","/a/b/c","/a/b/d"]
<strong>Output:</strong> ["/a"]
<strong>Explanation:</strong> Folders "/a/b/c" and "/a/b/d" will be removed because they are subfolders of "/a".
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> folder = ["/a/b/c","/a/b/ca","/a/b/d"]
<strong>Output:</strong> ["/a/b/c","/a/b/ca","/a/b/d"]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= folder.length &lt;= 4 * 10<sup>4</sup></code></li>
	<li><code>2 &lt;= folder[i].length &lt;= 100</code></li>
	<li><code>folder[i]</code> contains only lowercase letters and <code>'/'</code>.</li>
	<li><code>folder[i]</code> always starts with the character <code>'/'</code>.</li>
	<li>Each folder name is <strong>unique</strong>.</li>
</ul>
</div>