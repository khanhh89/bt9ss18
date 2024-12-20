#include<stdio.h>
#include<string.h>
int main(){
		int choice;
		int count = 4;
		struct Dish{
			int id;
			char name[50];
			double price;
		};
		struct Dish Menu[100]={
			{1,"Com muoi",30},{2,"Xoi trang",15},{3,"Thit kho",50},{4,"Xoi lac",10},
			};
	do{
		printf("__________MENU__________\n");
		printf("1.In ra cac gia tri cac phan tu co trong menu theo mon an.\n");
		printf("2.Them mot phan tu vao vi tri chi dinh\n");
		printf("3.Sua mot phan tu o vi tri chi dinh\n");
		printf("4.Xoa phan tu o vi tri chi dinh.\n");
		printf("5.Sap xep cac phan tu.\n");
		printf("6.Tim kiem cac phan tu.\n");
		printf("7.Thoat.\n");
		printf("Nhap lua chon cua ban: ");
		scanf("%d",&choice);
		switch (choice){
			case 1: 
				printf("Cac mon an co trong menu: \n");
				for(int i=0;i<count;i++){
					printf("%d",Menu[i].id);
					printf("%s",Menu[i].name);
					printf("\t%.3f\n",Menu[i].price);
					}
				break;
			case 2: 
				if(count<100){
					Menu[count].id=count+1;
					printf("Nhap ten mon an moi di: ");
					getchar();
					fgets(Menu[count].name,sizeof(Menu[count].name),stdin);
					Menu[count].name[strcspn(Menu[count].name, "\n")] ='\0';
					printf("Nhap gia mon an moi di: ");
					scanf("%lf",&Menu[count].price);
				count++;
				printf("Them thanh cong");
				}
				break;
			case 3: 
				int edit;
				printf("Nhap so mon an can sua: ");
				scanf("%d",&edit);
				int fount =0;
				for(int i=0;i<count;i++){
					if(Menu[i].id==edit){
						fount=1;
						printf("Nhap ten mon an moi: ");
						getchar();
						char news[50];
						fgets(news,sizeof(news),stdin);
						news[strcspn(news,"\n")]='\0';
						if (strlen(news) > 0) {
                            strcpy(Menu[i].name, news);
						}
//						printf("Nhap gia moi: ");
//						double newss;
//						scanf("%lf",&newss);
//					}
					printf("Sua thanh cong");
				break;
			case 4: {
				int deletes;
				printf("Nhap thu tu mon an can xoa: ");
				scanf("%d",&deletes);
                int found=0;
                for (int i=0;i<count;i++) {
                    if (Menu[i].id ==deletes) {
                        found=1;
                        for (int j=i;j<count-1; j++) {
                            Menu[j]=Menu[j+1];
                        }
                        count--;
                        printf("Xoa thanh cong mon %d.\n",deletes);
                        break;
                    }
                }
                }
				break;
			case 5: 
				for(int i=0;i<count-1;i++){
					for(int j=i+1;j<count;j++){
						if(Menu[i].price>Menu[j].price){
							struct Dish temp=Menu[i];
							Menu[i]=Menu[j];
							Menu[j]=temp;
							}
						}
					}
					printf("Sap xep thanh cong gia!!\n");
					for(int i=0;i<count;i++){
						printf("%d",Menu[i].id);
						printf("%s",Menu[i].name);
						printf("\t%.3f\n",Menu[i].price);
						}
				break;
			case 6: 
				char search[50];
				getchar();
				printf("Nhap mon an muon tim kiem: ");
				fgets(search,sizeof(search),stdin);
				search[strcspn(search,"\n")]='\0';
				printf("Ket qua tim kiem mon an la:\n");
				for(int i=0;i<count;i++){
					if(strstr(Menu[i].name,search)){
						printf("%d",Menu[i].id);
						printf("%s",Menu[i].name);
						printf("\t%.3f\n",Menu[i].price);
					}
				}
				break;
			case 7: 
				printf("Thoat.");
				break;
			default: 
				printf("Lua chon khong hop le, vui long chon lai!!");
			}
	} while (choice != 7);
	return 0;
}

