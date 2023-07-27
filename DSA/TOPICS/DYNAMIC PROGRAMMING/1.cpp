 vector<TreeNode*> rec(int start, int end){

   if(start > end) return {NULL};

   vector<TreeNode*> leftList, rightList, result;

   for(int i = start; i <= end); i++){
      leftList = rec(start, i -1);
      rightList = rec(i + 1, end);


      for(auto &l : leftList){
         for(auto &r : rightList){
            TreeNode* node = new TreeNode(i);
            node->left = l;
            node->right = r;

            res.push_back(node);
         }
      }
   }

   return res;
 }
 
 
 vector<TreeNode*> generateTrees(int n) {
   return rec(1, n);
 }