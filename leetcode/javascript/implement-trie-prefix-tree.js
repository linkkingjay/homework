/**
 * @constructor
 * Initialize your data structure here.
 */
var TrieNode = function() {
  this.isWord = false
};

var Trie = function() {
  this.root = new TrieNode();
};

/**
 * @param {string} word
 * @return {void}
 * Inserts a word into the trie.
 */
Trie.prototype.insert = function(word) {
  var i 
  var node = this.root

  for (i = 0; i < word.length; i++) {
    if (typeof node[word[i]] === 'undefined') {
      node[word[i]] = new TrieNode()
    }
    node = node[word[i]]
    if (i === word.length - 1) {
      node.isWord = true
    }
  }
};

/**
 * @param {string} word
 * @return {boolean}
 * Returns if the word is in the trie.
 */
Trie.prototype.search = function(word) {
  var node = this.root
  for (var i = 0; i < word.length; i++) {
    if (typeof node[word[i]] === 'undefined') {
      return false
    }
    node = node[word[i]]
  }
  return node.isWord
};

/**
 * @param {string} prefix
 * @return {boolean}
 * Returns if there is any word in the trie
 * that starts with the given prefix.
 */
Trie.prototype.startsWith = function(prefix) {
  var node = this.root
  for (var i = 0; i < prefix.length; i++) {
    if (typeof node[prefix[i]] === 'undefined') {
      return false
    }
    node = node[prefix[i]]
  }
  return true
};

/**
 * Your Trie object will be instantiated and called as such:
 * var trie = new Trie();
 * trie.insert("somestring");
 * trie.search("key");
 */

var trie = new Trie()
trie.insert('ab')
trie.insert('abc')
trie.insert('abcd')

console.log(JSON.stringify(trie))

