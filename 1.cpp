//25 ВП2, Варламова Елизавета
//2.
k = k++;
x = x--;
do {
	k++;
	x--;
} while (x >= 0)
cout << k << x;
//4.
do {
	k = k++;
	x = x--;
} while (x < 0)
cout << k << x;
//6.
k = k++;
x = x++;
if (k < 0) {
	k=0
}
else {
	while (x > 0) {
		x--;
		k++;
	}
}
cout << k << x;
//8.
k = 1;
x = x--;
while (k < N) and (x > 0) {
	k = k++;
}
while (k < N) and (x <= 0){
	x = x--;
}
cout << k << x;
//10.
if (x > 0) {
	k=0
}
else {
	k = -1;
}
do {
	k = k++;
	x = x--;
}while (x>=0)
cout << k << x;
//12.
if (k < 0) {
	k = 0;
}
else {
	do {
		k = k++;
		x = x++;
	} while(x<=0)
}
cout << k << x;