

//Can Karabulut


/*C++ program to Implement AVL Tree
*/
#include<iostream>
#include <algorithm>

#define pow2(n) (1 << (n))
using namespace std;



//Stack icin degiskenler olusturuluyor.
struct stackNode{

	string isim; 
	string soyisim;
	string bolumu;
	int ogrNo;
	int dersAlmaSayisi;
	stackNode* next;
	stackNode* prior;
	
};

//----->Yigina eleman ekleniyor . pushNode fonksiyonu ile. BASLA <-------//
struct stackNode* start = NULL; 
struct stackNode* top; 

struct stackNode* pushNode( string isim,string soyisim, string bolumu,int dersAlmaSayisi,int ogrNo) // stacke veri ekler.
{
	int index;
	if (start == NULL){
		index=0;
	}
	else
	{
		index=1;
	}
	if (index < 0) return NULL;

	int currIndex   =       1;
	struct stackNode* topNode  =  top;
	while (topNode && index > currIndex) {
		topNode = topNode->next;
		currIndex++;
	}//topNode dolu ve eleman sayisi 1 den fazla ise bu dongu yeni bir node olusturmak icin çalisiyor.
	if (index > 0 && topNode == NULL) return NULL;

	struct stackNode* newNode = new stackNode;
	newNode->isim = isim;
	newNode->soyisim = soyisim;
	newNode->bolumu = bolumu;
	newNode->dersAlmaSayisi = dersAlmaSayisi;
	newNode->ogrNo = ogrNo;
	if (index == 0) {
		newNode->prior = top;
		top = newNode;
		newNode->next=NULL;
	}//ilk eleman ekleniyorsa bu if geçerli olur
	else {
		newNode->next = topNode->next;
		newNode->prior = topNode;
		topNode->next = newNode;
	}
	start = newNode;
	return newNode;
}
// Zaman Karmasikligi: O(n)

//----->Yigina eleman ekleniyor . pushNode fonksiyonu ile. Bitir. <-------//



int algoritmaaliyormu(int ogrNo)//Veri yapilari ve algoritmalar dersi alip almadigini **
 {
	struct stackNode* topNode = top;
	int currIndex = 1;
	while (topNode && topNode->ogrNo != ogrNo) {
		topNode = topNode->next;
		currIndex++;
	}
	if (topNode) {
		return 1;
	}
	else
		
	return 0;
}
//Zaman Karmasikligi: O(n)

int algorit2denfazlaaliyormu(int ogrNo)//Algoritma dersini ikiden fazla alip almadigini kontrol eden fonks.**
 {
	struct stackNode* topNode = top;
	int currIndex = 1;
	while (topNode && topNode->ogrNo != ogrNo) {
		topNode = topNode->next;
		currIndex++;
	}
	if (topNode) {
		if (topNode->dersAlmaSayisi > 1)
		
		{
			return 1;
		}
		else
		{
			return 0;
		}
		
	}
	else
		
	return 0;
}
//Zaman Karmasikligi: O(n)


int FindNode(int ogrNo) //Burada ögrenci no ya göre ogrencinin bilgileri ekrana yazdirilmaktadir.**
{
	struct stackNode* topNode = top;
	int currIndex = 1;
	while (topNode && topNode->ogrNo != ogrNo) {
		topNode = topNode->next;
		currIndex++;
	}
	if (topNode) {
		cout<<"Aradiginiz kisi "<<currIndex<<".siradadir. "<<"Ogrenci No : "<<topNode->ogrNo<<"\nAdi: "<<topNode->isim<<"\nSoyadi: "<<topNode->soyisim<<"\nBolumu : "<<topNode->bolumu<<"\nDers Alma Sayisi: "<<topNode->dersAlmaSayisi<<endl;
	}
	else
		cout<<"Ogrenci bulunamadi."<<endl;
	return 0;
}
//Zaman Karmasikligi: O(n)

int  popNode(int ogrNo)//Yigindan ogrenci silen Pop fonksyonu . **
{
	struct stackNode* prevNode = NULL;
	struct stackNode* topNode = top;
	int currIndex =	1;
	while (topNode && topNode->ogrNo!=ogrNo) {
		prevNode = topNode;
		topNode = topNode->next;
		currIndex++;
	}
	if (topNode) {
		if (prevNode) {
			prevNode->next = topNode->next;
			topNode->prior = prevNode;
			delete topNode;
		}

		else {
			top = topNode->next;
			delete topNode;
		}
		return currIndex;
	}
	return 0;
};
//Zaman Karmasikligi: O(n)

void DisplayList()//Veri yapilari ve Algoritmalar dersi liste görüntüleme fonksiyonu. **

{
	int num = 0;
	struct stackNode* topNode = top; // Last in First Out icin node u top a ekleyecegiz
	top=topNode->prior++; //Lifo
	while (topNode != NULL){//Yigindaki dugum while döngüsü ile sifir olmamasi sartiyla
		cout << topNode->ogrNo <<":";
		cout << topNode->isim <<  " ";
		cout << topNode->soyisim <<" ";
		cout << topNode->bolumu <<" ";
		cout << topNode->dersAlmaSayisi<<'\n';
		
		topNode = topNode-> next;
		num++;
	}
	//kullanicidan almis oldugu ögrencinin bilgilerini(adi, soyadini, bölümünü, dersalmasayisi, numarasini) ekrana  getirir.her tekrarynda listedeki dügüm sayisini 1 arttyrarak, kaç tane dügümün oldugunuda ekranda gösterir.
	cout << "Toplam Kayit Sayisi: " << num << endl;

}
//Zaman Karmasikligi: O(n)


void veriyapilarigrupA()//veri yapilari ve algoritmalar dersi soyisimlerine gore (a-k) A grubunu listeleyen fonks. **
{
	struct stackNode* topNode;
	char alfabe[11]={'a','b','c','d','e','f','g','h','i','j','k'};
	cout<<"Veri Yapilari ve Algoritmalar Dersi A grubu : \n";
	for(topNode=top;topNode!=NULL;topNode=topNode->next){
		for (int i = 0; i < 11; i++)
		{
			if(toupper(topNode->soyisim[0])==toupper(alfabe[i])){
				cout<<topNode->ogrNo<<"  "<<topNode->isim<<"  "<<topNode->soyisim <<"  "<<topNode->bolumu<<"  "<<topNode->dersAlmaSayisi<<endl;
			}
		}
	}
	cout<<endl;
}
//Zaman Karmasikligi: O(n^2)


void veriyapilarigrupB()//veri yapilari ve algoritmalar dersi soyisimlerine gore (L-Z) B grubunu listeleyen fonks. **
{
	struct stackNode* topNode;
	cout<<"Veri Yapilari ve Algoritmalar Dersi B grubu : \n";
	char alfabe[15]={'l','m','n','o','p','q','r','s','t','u','v','w','y','x','z'};
	for(topNode=top;topNode!=NULL;topNode=topNode->next){
		for (int i = 0; i < 15; i++)
		{
			if(toupper(topNode->soyisim[0])==toupper(alfabe[i])){
				cout<<topNode->ogrNo<<"  "<<topNode->isim<<"  "<<topNode->soyisim <<"  "<<topNode->bolumu<<"  "<<topNode->dersAlmaSayisi<<endl;
			}
		}
	}
	cout<<endl;
}
//Zaman Karmasikligi: O(n^2)


/*
* Dugum degiskenleri
*/
struct avl_node
{
	int ogrNo;
	string isim;
	string soyisim; 
	string bolumu;
	int dersAlmaSayisi;
	struct avl_node *left;
	struct avl_node *right;
	int n;
}*root;

/*
* Classlar
*/
class avlTree
{
public:
	int height(avl_node *);
	int diff(avl_node *);
	avl_node *rr_rotation(avl_node *);
	avl_node *ll_rotation(avl_node *);
	avl_node *lr_rotation(avl_node *);
	avl_node *rl_rotation(avl_node *);
	avl_node* balance(avl_node *);
	avl_node* insert(avl_node *, int, string, string, string, int);
	void SadeceVeritabaniDersiniAlan(avl_node *, int);
	void IkiDersiBirdenFazlaAlan(avl_node *, int );
	void display(avl_node *, int);
	void AvlGrupA(avl_node *ptr, int level );
	void AvlGrupB(avl_node *ptr, int level );
	void inorder(avl_node *);
	void preorder(avl_node *);
	void postorder(avl_node *);
	avl_node* remove(avl_node* t,int);
	avl_node* findMin(avl_node*);
	avl_node* findMax(avl_node*);
	avlTree()
	{
		root = NULL;
	}
};




/*
* AVL agacinin Yuksekligi **
*/
int avlTree::height(avl_node *temp)
{
	int h = 0;
	if (temp != NULL)
	{
		int l_height = height(temp->left);
		int r_height = height(temp->right);
		int max_height = max(l_height, r_height);
		h = max_height + 1;
	}
	return h;
}
//Zaman Karmasikligi: O(n)

/*
* Yukseklik Farki **
*/
int avlTree::diff(avl_node *temp)
{
	int l_height = height(temp->left);
	int r_height = height(temp->right);
	int b_factor = l_height - r_height;
	return b_factor;
}
//Zaman Karmasikligi: O(n)

/*
* Sag-Sag Kurali **
*/
avl_node *avlTree::rr_rotation(avl_node *parent)
{
	avl_node *temp;
	temp = parent->right;
	parent->right = temp->left;
	temp->left = parent;
	return temp;
}
//Zaman Karmasikligi: O(n)

/*
* Sol-Sol Kurali **
*/
avl_node *avlTree::ll_rotation(avl_node *parent)
{
	avl_node *temp;
	temp = parent->left;
	parent->left = temp->right;
	temp->right = parent;
	return temp;
}
//Zaman Karmasikligi: O(n)

/*
* Sol-Sag Kurali **
*/
avl_node *avlTree::lr_rotation(avl_node *parent)
{
	avl_node *temp;
	temp = parent->left;
	parent->left = rr_rotation(temp);
	return ll_rotation(parent);
}
//Zaman Karmasikligi: O(n)

/*
* Sag-Sol Kurali **
*/
avl_node *avlTree::rl_rotation(avl_node *parent)
{
	avl_node *temp;
	temp = parent->right;
	parent->right = ll_rotation(temp);
	return rr_rotation(parent);
}
//Zaman Karmasikligi: O(n)

/*
* AVL agaci dengesi **
*/
avl_node *avlTree::balance(avl_node *temp)
{
	int bal_factor = diff(temp);
	if (bal_factor > 1)
	{
		if (diff(temp->left) > 0)
			temp = ll_rotation(temp);
		else
			temp = lr_rotation(temp);
	}
	else if (bal_factor < -1)
	{
		if (diff(temp->right) > 0)
			temp = rl_rotation(temp);
		else
			temp = rr_rotation(temp);
	}
	return temp;
}
//Zaman Karmasikligi: O(n)

/*
* AVL agacina Eleman insert etme
*/
avl_node *avlTree::insert(avl_node *root, int ogrNo,string isim, string soyisim, string bolumu, int dersAlmaSayisi )
{
	if (root == NULL)
	{
		root = new avl_node;
		root->ogrNo = ogrNo;
		root->isim = isim;
		root->soyisim = soyisim;
		root->bolumu = bolumu;
		root->dersAlmaSayisi= dersAlmaSayisi;
		root->left = NULL;
		root->right = NULL;
		return root;
	}
	else if (soyisim < root->soyisim)
	{
		root->left = insert(root->left, ogrNo,isim,soyisim,bolumu,dersAlmaSayisi );
		root = balance(root);
	}
	else if (soyisim >= root->soyisim)
	{
		root->right = insert(root->right, ogrNo,isim,soyisim,bolumu,dersAlmaSayisi );
		root = balance(root);
	}
	return root;
}
//Zaman Karmasikligi: O(n)

/*
* AVL agaci goruntule 
*/
void avlTree::display(avl_node *ptr, int level)
{
	int i;
	if (ptr != NULL)
	{
		display(ptr->right, level + 1);
		printf("\n");
		if (ptr == root)
			cout << "Root -> ";
		for (i = 0; i < level && ptr != root; i++)
			cout << "        ";
		cout << ptr->ogrNo;
		display(ptr->left, level + 1);
	}
}
//Zaman Karmasikligi: O(n)

/*
* Inorder
*/
void avlTree::inorder(avl_node *tree)
{
	if (tree == NULL)
		return;
	inorder(tree->left);
	cout << tree->ogrNo << "  ";
	inorder(tree->right);
}
//Zaman Karmasikligi: O(n)

/*
* Preorder
*/
void avlTree::preorder(avl_node *tree)
{
	if (tree == NULL)
		return;
	cout << tree->ogrNo << "  ";
	preorder(tree->left);
	preorder(tree->right);

}
//Zaman Karmasikligi: O(n)


avl_node* avlTree::findMin(avl_node* t) {
	if (t == NULL) return NULL;
	else if (t->left == NULL) return t; // Eleman  sola hareket ederse geri dönüyoruz
	else return findMin(t->left); // veya art arda sola hareket ettiriyoruz.
}
avl_node* avlTree:: findMax(avl_node* t) {
	if (t == NULL) return NULL;
	else if (t->right == NULL) return t;
	else return findMax(t->right);
}
//Zaman Karmasikligi: O(n)


/*
* Postorder
*/
void avlTree::postorder(avl_node *tree)
{
	if (tree == NULL)
		return;
	postorder(tree->left);
	postorder(tree->right);
	cout << tree->ogrNo << "  ";
}
//Zaman Karmasikligi: O(n)

avl_node* avlTree:: remove(avl_node* t, int x) {
	avl_node* temp;
	// element not found
	if (t == NULL) return NULL;
	// searching element
	else if (x < t->ogrNo) t->left = remove(t->left, x);
	else if (x >t->ogrNo) t->right = remove(t->right, x);

	// element found
	// element has 2 children
	else if (t->left && t->right) {
		temp = findMin(t->right);
		t->ogrNo = temp->ogrNo;
		t->right = remove(t->right, t->ogrNo);
	}
	// if element has 1 or 0 child
	else {
		temp = t;
		if (t->left == NULL) t = t->right;
		else if (t->right == NULL) t = t->left;
		delete temp;
	}
	if (t == NULL) return t;
	// check balanced)
	t = balance(t);
}
//Zaman Karmasikligi: O(n^2)


//--------Veritabaný Yönetim Sistemleri dersi alan öðrenciler A grubunda numarasý tek sayý olanlar ve B grubunda ise numarasý çift sayý olanlar . BASLAR ---->


int noCiftmi(int OgNo){
	if(OgNo%2==0){
		return 1;
	}
	else
	return 0;
}
//Zaman Karmasikligi: O(n)


void avlTree::AvlGrupA(avl_node *ptr, int level )
{

	int i;
	if (ptr != NULL)
	{
		AvlGrupA(ptr->right, level + 1);
		if (noCiftmi(ptr->ogrNo) == 0 )
		{
		printf("\n");
		cout << ptr->ogrNo << " ";
		cout << ptr->isim << " ";
		cout << ptr->soyisim << " ";
	}
		AvlGrupA(ptr->left, level + 1);
	
	}
}
//Zaman Karmasikligi: O(n)


void avlTree::AvlGrupB(avl_node *ptr, int level )
{

	int i;
	if (ptr != NULL)
	{
		AvlGrupB(ptr->right, level + 1);
		if (noCiftmi(ptr->ogrNo) == 1 )
		{
		printf("\n");
		cout << ptr->ogrNo << " ";
		cout << ptr->isim << " ";
		cout << ptr->soyisim << " ";
	}
		AvlGrupB(ptr->left, level + 1);
	
	}

}
//Zaman Karmasikligi: O(n)


//--------Veritabaný Yönetim Sistemleri dersi alan öðrenciler A grubunda numarasý tek sayý olanlar ve B grubunda ise numarasý çift sayý olanlar . BITER ---->





//------>Sadece Veritabani Yonetim Sistemleri dersini alan ogrencilerin listesi \n (Bu ogrenciler Veri Yapilari ve Algortimalar dersini almiyor.) BASLAR<------//

void avlTree::SadeceVeritabaniDersiniAlan(avl_node *ptr, int level )
{

	int i;
	if (ptr != NULL)
	{
		SadeceVeritabaniDersiniAlan(ptr->right, level + 1);
		if (algoritmaaliyormu(ptr->ogrNo) == 0 )
		{
		printf("\n");
		cout << ptr->ogrNo << " ";
		cout << ptr->isim << " ";
		cout << ptr->soyisim << " ";
	}
		SadeceVeritabaniDersiniAlan(ptr->left, level + 1);
	
	}

}
//Zaman Karmasikligi: O(n)


//------>Sadece Veritabani Yonetim Sistemleri dersini alan ogrencilerin listesi (Bu ogrenciler Veri Yapilari ve Algortimalar dersini almiyor.) BITER<------//


//------>Her iki dersi de birden fazla kez alan öðrencileri listeleyiniz baslar<------//

void avlTree::IkiDersiBirdenFazlaAlan(avl_node *ptr, int level )
{
    int i;
    if (ptr != NULL)
                      {
        IkiDersiBirdenFazlaAlan(ptr->right, level + 1);
        if (ptr->dersAlmaSayisi > 1)
      {
        if (algorit2denfazlaaliyormu(ptr->ogrNo) == 1 )                
      {             
     printf("\n");
     cout << ptr->ogrNo << " ";
     cout << ptr->isim << " ";
     cout << ptr->soyisim << " ";
}
}
  IkiDersiBirdenFazlaAlan(ptr->left, level + 1);         
}
}
//Zaman Karmasikligi: O(n)


//------>Her iki dersi de birden fazla kez alan öðrencileri listeleyiniz biter.<------//


//------>Baska bolumden Her iki dersi de birden fazla kez alan öðrencileri listele BASLAR.<------//
void BaskaBolumdenherikiDersiAlan(avl_node *ptr, int level ){

	int i;
    if (ptr != NULL)
                      {
        BaskaBolumdenherikiDersiAlan(ptr->right, level + 1);
        if (ptr->bolumu!="BM")
      {
        if (algoritmaaliyormu(ptr->ogrNo) == 1 )                
      {             
     printf("\n");
     cout << ptr->ogrNo << " ";
     cout << ptr->isim << " ";
     cout << ptr->soyisim << " ";
     cout << ptr->bolumu << " ";
     cout << ptr->dersAlmaSayisi << " ";
}
}
  BaskaBolumdenherikiDersiAlan(ptr->left, level + 1);         
}
}
//Zaman Karmasikligi: O(n)


//------>Baska bolumden Her iki dersi de birden fazla kez alan öðrencileri listele BITER<------//






//-------->>>>> Hizli Sýralama Baþlar. <<<<------ //


int DogrNo[30];
string Disim[30];
string Dsoyisim[30];
string Dbolumu[30];
int DdersAlmaSayisi[30];

void HizliSiralamaNumara(int ilk,int son){

	int i; // Ilk elemani tutacak sayaç degiskeni
	int j; // Son elemani tutacak sayaç degiskeni
	int pivot; // Pivot elemani tutacak sayaç degiskeni

	int tmpDogrNo;	// Yer degistirme islemi için kullanilacak degisken
	string tmpDisim;	// Yer degisterime islemi için kullanylacak degisken
	string tmpDsoyisim;	  // Yer degisterime islemi için kullanylacak degisken
	string tmpDbolumu;	   // Yer degisterime islemi için kullanylacak degisken
	int tmpDdersAlmaSayisi;  // Yer degisterime islemi için kullanylacak degisken

	pivot=ilk; // Pivot ilk eleman seçilir
	// Burada yapilan islem son eleman ilk elemandan büyükse, son eleman ilk elemandan büyük oldugu sürece bastan ve sondan pivottan büyük olan ve
	// pivottan küçük olan bir eleman seçilip yer degistirilir.
		j=son;
if(son>ilk)
	{
		pivot=ilk;
		i=ilk;
		j=son;
		while (i<j)
		{
			while (DogrNo[i]<=DogrNo[pivot] && i<son && j>i){ // Ba?tan pivottan büyük olan bir eleman bulunur
				i++;
			}
			while (DogrNo[j]>=DogrNo[pivot] && j>=ilk && j>=i){ // Sondan pivottan küçük olan bir eleman bulunur
				j--;
			}
			if (i>j){ // Swap islemi yapiliyor.
			
			
				tmpDogrNo=DogrNo[i];
				DogrNo[i]=DogrNo[j];
				DogrNo[j]=tmpDogrNo;
				
				tmpDisim=Disim[i];
				Disim[i]=Disim[j];
				Disim[j]=tmpDisim;

				tmpDsoyisim=Dsoyisim[i];
				Dsoyisim[i]=Dsoyisim[j];
				Dsoyisim[j]=tmpDsoyisim;

				tmpDbolumu=Dbolumu[i];
				Dbolumu[i]=Dbolumu[j];
				Dbolumu[j]=tmpDbolumu;

				tmpDdersAlmaSayisi=DdersAlmaSayisi[i];
				DdersAlmaSayisi[i]=DdersAlmaSayisi[j];
				DdersAlmaSayisi[j]=tmpDdersAlmaSayisi;

			}
		}
		}
	// Yeniden pivot seçilir ve bölünen bagli listenin diger parçalari tekrar quick sort fonksiyonuna gönderilir

	
	tmpDogrNo=DogrNo[j];
	DogrNo[j]=DogrNo[pivot];
	DogrNo[pivot]=tmpDogrNo;
	
	tmpDisim=Disim[j];
	Disim[j]=Disim[pivot];
	Disim[pivot]=tmpDisim;
	
	tmpDsoyisim=Dsoyisim[j];
	Dsoyisim[j]=Dsoyisim[pivot];
	Dsoyisim[pivot]=tmpDsoyisim;

	tmpDbolumu=Dbolumu[j];
	Dbolumu[j]=Dbolumu[pivot];
	Dbolumu[pivot]=tmpDbolumu;

	tmpDdersAlmaSayisi=DdersAlmaSayisi[j];
	DdersAlmaSayisi[j]=DdersAlmaSayisi[pivot];
	DdersAlmaSayisi[pivot]=tmpDdersAlmaSayisi;

	if (j<son){
		HizliSiralamaNumara(j+1,son);}

}
//Zaman Karmasikligi: O(n^2*n)

void HizliSirala(avl_node *ptr, int level){

	int num = 0;

	stackNode* topNode = top;
	while (topNode != NULL){
		
		if (algoritmaaliyormu(ptr->ogrNo) == 1 ){
			DogrNo[num]=topNode->ogrNo;
			Disim[num]=topNode->isim;
			Dsoyisim[num]=topNode->soyisim;
			Dbolumu[num]=topNode->bolumu;
			DdersAlmaSayisi[num]=topNode->dersAlmaSayisi;
			num++;
		}

		topNode = topNode->next;

	}
	if (num>1)	HizliSiralamaNumara(0,num-1)	;
	cout<<"Sadece veri yapilari ve algoritmalar dersi alan ogrencilerin NUMARALARINA gore siralanmis listesi :: \n";
	for (int i = 0; i < num; i++) {

		cout <<DogrNo[i]<<" "<<Disim[i]<<" "<<Dsoyisim[i]<<"  "<<Dbolumu[i]<<" "<<DdersAlmaSayisi[i]<<endl;
	}

}
//Zaman Karmasikligi: O(n^2)


//-------->>>>> Hizli Sýralama Biter. <<<<------ //

int avl_size;

//------>>>>> Radiks sýralama Baþlar-------


int RogrNo[30];
string Risim[30];
string Rsoyisim[30];
string Rbolumu[30];
int RdersAlmaSayisi[30];
int ii;

void veridrcdiziyap(avl_node *ptr, int level)
{


	if (ptr != NULL)
	{
		veridrcdiziyap(ptr->right, level + 1);
		if (algoritmaaliyormu(ptr->ogrNo) == 1 )
		{
			Risim[avl_size] = ptr->isim ;
			Rsoyisim[avl_size] = ptr->soyisim;
			RogrNo[avl_size] = ptr->ogrNo;
			Rbolumu[avl_size] = ptr->bolumu;
			RdersAlmaSayisi[avl_size] = ptr->dersAlmaSayisi;
			avl_size = avl_size + 1;	
		}
		veridrcdiziyap(ptr->left, level + 1);

	}
}
//Zaman Karmasikligi: O(n)


size_t getMax(string arr[], int n){
    size_t max = arr[0].size();
    for (int i = 1; i < n; i++){
        if (arr[i].size()>max)
            max = arr[i].size();
    }
    return max;
}
//Zaman Karmasikligi: O(n*n/(n+1))


void countSort(string a[], int size, size_t k){
    string *b = NULL; int *c = NULL;

	b = new string[size];
    int 	xRogrNo[size];
	string 	xRisim[size];
	string 	xRbolumu[size];
	int 	xRdersAlmaSayisi[size];

    c = new int[257];



    for (int i = 0; i <257; i++){
        c[i] = 0;
        //cout << c[i] << "\n";
    }
    for (int j = 0; j <size; j++){
        c[k < a[j].size() ? (int)(unsigned char)a[j][k] + 1 : 0]++;            //a[j] is a string
        //cout << c[a[j]] << endl;
    }

    for (int f = 1; f <257; f++){
        c[f] += c[f - 1];
    }

    for (int r = size - 1; r >= 0; r--){
        b[c[k < a[r].size() ? (int)(unsigned char)a[r][k] + 1 : 0] - 1] = a[r];
        xRogrNo[c[k < a[r].size() ? (int)(unsigned char)a[r][k] + 1 : 0] - 1] = RogrNo[r] ;
        xRisim[c[k < a[r].size() ? (int)(unsigned char)a[r][k] + 1 : 0] - 1] = Risim[r] ;
        xRbolumu[c[k < a[r].size() ? (int)(unsigned char)a[r][k] + 1 : 0] - 1] = Rbolumu[r];
        xRdersAlmaSayisi[c[k < a[r].size() ? (int)(unsigned char)a[r][k] + 1 : 0] - 1] = RdersAlmaSayisi[r];

        c[k < a[r].size() ? (int)(unsigned char)a[r][k] + 1 : 0]--;
    }

    for (int l = 0; l < size; l++){
        a[l] = b[l];
        RogrNo[l]=xRogrNo[l];
        Risim[l]=xRisim[l];
       	Rbolumu[l]=xRbolumu[l];
		RdersAlmaSayisi[l]=xRdersAlmaSayisi[l];
    }

  
}
//Zaman Karmasikligi: O(n)


void radixSort(){

    veridrcdiziyap(root,1);
    ii = avl_size;
	size_t max = getMax(Rsoyisim, ii);
    for (size_t digit = max; digit > 0; digit--){ // size_t is unsigned, so avoid using digit >= 0, which is always true
        countSort(Rsoyisim, ii, digit - 1);
    }
    for (int t=0; t<avl_size;t++){
    	cout<<Rsoyisim[t] <<" " << Risim[t] <<" "<<Rbolumu[t]<<" "<<RogrNo[t]<<" "<<RdersAlmaSayisi[t]<<endl;
	}

}
//Zaman Karmasikligi: O(n)



//<<<<<<<<---------Radiks Sýralama Biter<<<<<<----------------//

//<<<<<<<<---------Secmeli Sýralama Baslar<<<<<<----------------//

//void swapping(int &a, int &b) {         //swap - a and b -
//   int temp;
//   temp = a;
//   a = b;
//   b = temp;
//}
/*void ekranabas(avl_node *p, int size) {
   for(int i = 0; i<size; i++)
      cout << p->isim[i] << " ";
   cout << endl;
}*/



void avl_diziaktar (avl_node *ptr, int level)

{


	if (ptr != NULL)
	{
		avl_diziaktar(ptr->right, level + 1);
		if (algoritmaaliyormu(ptr->ogrNo) == 0 )
		{
			Disim[avl_size] = ptr->isim ;
			avl_size = avl_size + 1;	
		}
		avl_diziaktar(ptr->left, level + 1);

	}
	
}
//Zaman Karmasikligi: O(n)



void SecmeliSiralama(int size) {

  int i, j, imin;
 	
   for(i = 0; i<size; i++) {
      imin = i;   //minumum datayi indexle
      for(j = i+1; j<size; j++)
         if(Disim[j] < Disim[imin])
            imin = j;
         swap(Disim[i], Disim[imin]);//Dogru yere yerlestir.
   }
   
   for(i = 0; i<size; i++) {
   	cout << "\n";
   	cout<< Disim[i];
   }
   
}
//Zaman Karmasikligi: O(n^2+1)


//<<<<<<<<---------Secmeli Sýralama Biter<<<<<<----------------//

//Bolum kontrol

string Bolumkontrol(){
	string b;
	cout<<"Ogrenci bolumunu (BM,EM,IM,ES,EE) giriniz: ";
	cin>>b;
	if (b!="BM" && b!="EM" && b!="IM" && b!="ES" && b!="EE"){
		cout<<"\nLutfen gecerli bir bolum giriniz:\n";
		Bolumkontrol();
	}
	else{
		return b;
	}
}
//Zaman Karmasikligi: O(n)



/*
* Anamenu
*/
int main()
{
	int x ;
	int choice, item;
	int gogrNo;
	string gisim;
	string gsoyisim; 
	string gbolumu;
	int gdersAlmaSayisi;
	
	avlTree avl;
	while (1)
	{
		cout << "\n---------------------" << endl;
		cout << "AVL Tree ve Stack ile Islem Yapan Veri Yapilari Odevi" << endl;
		cout << "\n---------------------" << endl;
		cout << "01-(1. )Veritabani Yonetim Sistemleri dersine ogrenci ekle.(AVL)" << endl;
		cout << "02-(1. )Veritabani Yonetim Sistemleri dersinden ogrenci sil" << endl;
		cout << "03-(1. )Veritabani Yonetim Sistemleri dersi sinifinin AVL agicini goruntule" << endl;
		cout << "04-(1. )Veritabani Yonetim Sistemleri dersi sinifinin InOrder traversal listesi" << endl;
		cout << "05-(1. )Veritabani Yonetim Sistemleri dersi sinifinin PreOrder traversal listesi" << endl;
		cout << "06-(1. )Veritabani Yonetim Sistemleri dersi sinifinin PostOrder traversal listesi" << endl;
		cout<<  "07-(2. ) Veri yapilari ve algoritmalar dersine ogrenci ekle(Stack) "<< endl;
		cout<<  "08-(2. ) Veri yapilari ve algoritmalar dersinden ogrenci sil "<< endl;
		cout<<	"09-(2. ) Veri yapilari ve algoritmalar dersi sinif Listesini goster "<< endl;
		cout<<	"10-(2.c.ii) Veri yapilari ve algoritmalar dersi soyadi A grubu (A-K) ve B grubu (L-Z) ile baslayanlari listeleme"<< endl;
		cout<<	"11-(2.c.i) Veritabani Yonetim Sistemleri dersi A grubu (Tek numarali) ve B grubu (Cift numarali) listeleme "<< endl;
		cout<<	"12-(2.a) Her iki dersi birden fazla alan ogrencileri listele "<< endl;
		cout<<	"13-(2.b) Sadece Veritabani Yonetim Sistemleri dersini alan ogrencilerin listesi \n (Bu ogrenciler Veri Yapilari ve Algortimalar dersini almiyor.) "<< endl;
		cout<<	"14-(2.d) Her iki dersi birden fazla alan ogrencileri listele "<< endl;
		cout<<  "15-(3.c) Hizli siralama ile veri yapilari ve algoritmalar dersi alanlari NUMARALARINA gore sirala "<< endl;
		cout<<	"16-(3.a) Radiks siralama ile her iki dersi alanlari SOYADLARINA gore sirala "<< endl;
		cout<<	"17-(3.b) Secmeli siralama ile sadece Veritabaný Yonetim Sistemleri dersini alanlari ADLARINA gore sirala "<< endl;
		cout<<	"18-Hazir data"<< endl;
		cout << "19-Cikis" << endl;
		cout << "Secimi Giriniz: \n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Ogrenci No Griniz: ";
			cin >> gogrNo;

			cout << "Ogrenci isim Griniz: ";
			cin >> gisim;
			
			cout << "Ogrenci Soyisim Giriniz: ";
			cin >> gsoyisim;
		
			gbolumu = Bolumkontrol();
			
			cout<<"Ogrenci ders alis sayisi: ";
			cin>>gdersAlmaSayisi;
			
			root = avl.insert(root, gogrNo,gisim,gsoyisim,gbolumu,gdersAlmaSayisi  );
			
			break;
		case 2:
			cout << "Girilen ogrenci no silindi: ";
			cin >> item;
			root = avl.remove(root, item);
			break;
		case 3:
			if (root == NULL)
			{
				cout << "Agac Bos." << endl;
				continue;
			}
			cout << " AVL Tree:" << endl;
			avl.display(root , 1);
			break;
		case 4:
			cout << "Inorder Traversal:" << endl;
			avl.inorder(root);
			cout << endl;
			break;
		case 5:
			cout << "Preorder Traversal:" << endl;
			avl.preorder(root);
			cout << endl;
			break;
		case 6:
			cout << "Postorder Traversal:" << endl;
			avl.postorder(root);
			cout << endl;
			break;
		case 7:
			cout<<"Ogrenci no girin: " ;
			cin>>gogrNo;
			cout<<"Ad girin: ";
			cin>>gisim;
			cout<<"Soyad girin: ";
			cin>>gsoyisim;
			gbolumu=Bolumkontrol();
			cout<<"Ders alis sayisi: ";
			cin>>gdersAlmaSayisi;
			pushNode(gisim,gsoyisim,gbolumu,gdersAlmaSayisi,gogrNo ) ;
			break;
		case 8:
			cout<<"Silmek istediginiz ogrenci numarasi :";
			cin>>x;
			popNode(x);
			break;
		case 9: 
		DisplayList();
			break;
			
		case 10:
			veriyapilarigrupA();
			veriyapilarigrupB();
			break;
			
		case 11:
			cout<<"\n Grup A Ogrencileri: "<< endl;
			avl.AvlGrupA(root,1);
			cout<<"\n \n Grup B Ogrencileri:"<< endl;
			avl.AvlGrupB(root,1);
			break;
			
		case 12:
			cout<<"Her iki dersi birden fazla alanlarin listesi : \n";
			avl.IkiDersiBirdenFazlaAlan(root,1);
			break;
		case 13:
			cout<<"Sadece Veritabani Yonetim Sistemleri dersini alan ogrencilerin listesi \n (Bu ogrenciler Veri Yapilari ve Algortimalar dersini almiyor.) : \n "<< endl;
				if (root == NULL)
			{
				cout << "Agac Bos." << endl;
				continue;
			}
			cout << " AVL Tree:" << endl;
			avl.SadeceVeritabaniDersiniAlan(root , 1);
			break;
			
		case 14:
			cout<<"Her iki dersi alan ve baska bolum ogrencileri olan liste"<< endl;
			BaskaBolumdenherikiDersiAlan(root,1);
			break;
			
		case 15:
			
			
			HizliSirala(root,1);
			break;
			
		case 16:
			cout<<"Radix siralama ile her iki dersi alanlarin soyadina gore siralanmasi"<< endl;
			for(int i=0; i<30; i++)
				{	
				 	RogrNo[i] = 0;
					Risim[i]="";
					Rsoyisim[i]="";
					Rbolumu[i]="";
					RdersAlmaSayisi[i]=0;
	    		}
	    	avl_size=0;
			radixSort();
			break;
			
		case 17:
			
			cout<<"Secmeli siralama ile sadece veri tabani yonetim sistemleri dersi alanlarin siralanmasi"<< endl;
			avl_size = 0;
				int i;
				for(i=0; i<30; i++)
				{	
					Disim[i]="";
	    		}
	    	avl_diziaktar(root,1);	
			SecmeliSiralama(avl_size);
			
			break;

		case 18: 
			
			cout<<"Hazir data girildi. \n "<< endl;
				
			pushNode("Bekir","Ciftler","BM",2,  100);
			pushNode("Can","Karabulut","BM",1,  101);
			pushNode("Altug","Teke","BM",1,     102);
			pushNode("Aleyna","Ilhan","BM",1,    103);
			pushNode("Ali","Veli","IM",2,       104);
			pushNode("Omer","Seyfettin","EE",2,105);
			pushNode("Hasan","Bayrak","EE",2,106);
			pushNode("Zeynep","Kale","EE",2,107);
			
			//veri yapilari ve algoritmalar dersine hizli data eklemek icin
			
			
			root=avl.insert(root,100,"Bekir","Ciftler", "BM",2);
			root=avl.insert(root,101,"Can","Karabulut","BM",1);
			root=avl.insert(root,102,"Altug","Teke","BM",1);
			root=avl.insert(root,103,"Aleyna","Ilhan","BM",1);
			root=avl.insert(root,104,"Ali","Veli","IM",2);
			root=avl.insert(root,105,"Omer","Seyfettin","EE",2);
			root=avl.insert(root,108,"Ahmet","Mumtaz","BM",2);
			root=avl.insert(root,109,"Zeynep","Güler","BM",2);
			root=avl.insert(root,110,"Bahadir","Akmaz","BM",2);
			root=avl.insert(root,111,"Osman","Durmaz","BM",2);
			//veritabani Yonetim Sistemleri dersine hizli data eklemek icin */


			break;
			
		default:
			cout << "Yanlis Secim" << endl;
		}
	}
	return 0;
}
//Zaman Karmasikligi: O(n^2)



