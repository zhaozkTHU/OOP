class a {
	const static int b = 1;
};

class b :private a {

};



int main() {
	b *ptr;
}