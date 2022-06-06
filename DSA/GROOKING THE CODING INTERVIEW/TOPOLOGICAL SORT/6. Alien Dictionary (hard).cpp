There is a dictionary containing words from an alien language for which we don’t know the ordering of the alphabets. Write a method to find the correct order of the alphabets in the alien language. It is given that the input is a valid dictionary and there exists an ordering among its alphabets.

Example 1:

Input: Words: ["ba", "bc", "ac", "cab"]
Output: bac
Explanation: Given that the words are sorted lexicographically by the rules of the alien language, so
from the given words we can conclude the following ordering among its characters:

1. From "ba" and "bc", we can conclude that 'a' comes before 'c'.
2. From "bc" and "ac", we can conclude that 'b' comes before 'a'

From the above two points, we can conclude that the correct character order is: "bac"
Example 2:

Input: Words: ["cab", "aaa", "aab"]
Output: cab
Explanation: From the given words we can conclude the following ordering among its characters:

1. From "cab" and "aaa", we can conclude that 'c' comes before 'a'.
2. From "aaa" and "aab", we can conclude that 'a' comes before 'b'

From the above two points, we can conclude that the correct character order is: "cab"
Example 3:

Input: Words: ["ywx", "wz", "xww", "xz", "zyy", "zwz"]
Output: ywxz
Explanation: From the given words we can conclude the following ordering among its characters:

1. From "ywx" and "wz", we can conclude that 'y' comes before 'w'.
2. From "wz" and "xww", we can conclude that 'w' comes before 'x'.
3. From "xww" and "xz", we can conclude that 'w' comes before 'z'
4. From "xz" and "zyy", we can conclude that 'x' comes before 'z'
5. From "zyy" and "zwz", we can conclude that 'y' comes before 'w'

From the above five points, we can conclude that the correct character order is: "ywxz"



class AlienDictionary {
 public:
  static string findOrder(const vector<string> &words) {
    if (words.empty() || words.empty()) {
      return "";
    }

    // a. Initialize the graph
    unordered_map<char, int> inDegree;       // count of incoming edges for every vertex
    unordered_map<char, vector<char>> graph; // adjacency list graph
    for (auto word : words) {
      for (char character : word) {
        inDegree[character] = 0;
        graph[character] = vector<char>();
      }
    }

    // b. Build the graph
    for (int i = 0; i < words.size() - 1; i++) {
      // find ordering of characters from adjacent words
      string w1 = words[i], w2 = words[i + 1]; 
      for (int j = 0; j < min(w1.length(), w2.length()); j++) {
        char parent = w1[j], child = w2[j];
        if (parent != child) {             // if the two characters are different
          graph[parent].push_back(child);  // put the child into it's parent's list
          inDegree[child]++;               // increment child's inDegree
          break;  // only the first different character between the two words will help 
                  // us find the order
        }
      }
    }

    // c. Find all sources i.e., all vertices with 0 in-degrees
    queue<char> sources;
    for (auto entry : inDegree) {
      if (entry.second == 0) {
        sources.push(entry.first);
      }
    }

    // d. For each source, add it to the sortedOrder and subtract one from all of its 
    // children's in-degrees if a child's in-degree becomes zero, add it to sources queue
    string sortedOrder;
    while (!sources.empty()) {
      char vertex = sources.front();
      sources.pop();
      sortedOrder += vertex;
      vector<char> children =
          graph[vertex];  // get the node's children to decrement their in-degrees
      for (char child : children) {
        inDegree[child]--;
        if (inDegree[child] == 0) {
          sources.push(child);
        }
      }
    }

    // if sortedOrder doesn't contain all characters, there is a cyclic dependency 
    // between characters, therefore, we will not be able to find the correct ordering 
    // of the characters
    if (sortedOrder.length() != inDegree.size()) {
      return "";
    }

    return sortedOrder;
  }
};

