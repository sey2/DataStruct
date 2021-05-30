int find_max(TreeNode* root) {
	int root_val, left, right, max = 0;

	if (root != NULL) {
		root_val = root->key;
		left = find_max(root->left);
		right = find_max(root->right);
		if (left > right)
			max = left;
		else max = right;
		if (root_val > max)
			max = root_val;
	}
	return max;
}

int find_min(TreeNode* root) {
	int root_val, left, right, min = INT_MAX;

	if (root != NULL) {
		root_val = root->key;
		left = find_min(root->left);
		right = find_min(root->right);
		if (left < right)
			min = left;
		else min = right;
		if (root_val < min)
			min = root_val;
	}
	return min;
}