#include <stdio.h>
#include <string.h>

void fastRead_int(int *a)
{
    register char c=0;
    while (c<33) c=getchar_unlocked();
    *a=0;
    while (c>33)
    {
        *a=*a*10+c-'0';
        c=getchar_unlocked();
    }
}


typedef struct node {
	int index;
	int sz;
	int v[20];
}node;

node arr[100005];
node tree[100005*4];
int lazy[100005*4];

node merge(node *a, node *b) {
	node tmp;

	tmp.index = 0;
	tmp.sz = 0;
	int i = a->index, j = b->index;
	while(i < a->sz && j < b->sz) {
		tmp.v[tmp.sz++] = ((a->v[i] > b->v[j]) ? a->v[i] : b->v[j]);
		i++, j++;
	}
	while(i < a->sz) tmp.v[tmp.sz++] = a->v[i++];
	while(j < b->sz) tmp.v[tmp.sz++] = b->v[j++];
	return tmp;
}
void build_tree(int ind, int l, int r) {
	if(l > r) return;
	if(l == r) {
		tree[ind] = arr[l];
		return;
	}
	int mid = (l + r) / 2;
	build_tree(ind*2+1, l ,mid);
	build_tree(ind*2+2, mid+1, r);

	tree[ind] = merge(&tree[ind*2+1],&tree[ind*2+2]);
}

int get_max(int ind, int l, int r, int p, int q) {

	if(lazy[ind] > 0) {
		tree[ind].index += lazy[ind];
		if(l != r) {
			lazy[ind*2+1] += lazy[ind];
			lazy[ind*2+2] += lazy[ind];
		}
		lazy[ind] = 0;
	}
	if(l > r && p > q || p > r || q < l) return 1;
	if(p <= l && r <= q)  {
		if(tree[ind].index >= tree[ind].sz) return 1;
		return tree[ind].v[tree[ind].index];
	}

	int mid = (l+r) / 2;
	int left = get_max(ind*2+1, l , mid, p ,q);
	int right = get_max(ind*2+2, mid+1, r, p ,q);

	return ((left < right) ? right : left);
}
void update_all(int ind, int l, int r, int p, int q) {
	if(lazy[ind] > 0) {
		tree[ind].index += lazy[ind];
		if(l != r) {
			lazy[ind*2+1] += lazy[ind];
			lazy[ind*2+2] += lazy[ind];
		}
		lazy[ind] = 0;
	}
	if(l > r && p > q || p > r || q < l) return;
	if(l >= p && r <= q) {
		tree[ind].index++;
		if(l != r) {
			lazy[ind*2+1]++;
			lazy[ind*2+2]++;
		}
		return;
	}

	int mid = (l+r) / 2;
	update_all(ind*2+1, l, mid, p, q);
	update_all(ind*2+2, mid+1, r, p, q);

	tree[ind] = merge(&tree[ind*2+1], &tree[ind*2+2]);

}
int main()
{

	int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997, 1009, 1013, 1019, 1021, 1031, 1033, 1039, 1049, 1051, 1061, 1063, 1069, 1087, 1091, 1093, 1097, 1103, 1109, 1117, 1123, 1129, 1151, 1153, 1163, 1171, 1181};
	int sz = sizeof(prime) / sizeof(prime[0]);
	int t,tp,l,r,n,m,x,i,j;
	fastRead_int(&t);
	while(t--) {
		memset(lazy, 0 , sizeof(lazy));
		fastRead_int(&n);fastRead_int(&m);
		for(i = 0; i < n; i++) {
			fastRead_int(&x);
			arr[i].index = 0;
			arr[i].sz = 0;
			for(j = 0; j < sz && prime[j]*prime[j] <= x; j++) {
				if(x % prime[j] == 0) {
					while(x%prime[j] == 0) {
						arr[i].v[arr[i].sz++] = prime[j];
						x = x / prime[j];
					}
				}
			}
			if(x > 1) arr[i].v[arr[i].sz++] = x;
		}
		build_tree(0,0,n-1);
		for(i = 0; i < m; i++) {
			fastRead_int(&tp);fastRead_int(&l);fastRead_int(&r);
			if(tp == 1) printf("%d ", get_max(0,0,n-1,l-1,r-1));
			else update_all(0,0,n-1,l-1,r-1);
		}
		printf("\n");
}
return 0;
}