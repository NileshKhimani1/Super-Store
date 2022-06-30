#include<iostream>
using namespace std;
#define size 10
#define l long long

int hash_function(l key)
{
    return (key%size);
}

struct purchased_items                                                 //structure to list the purchased items
{
    l item_id;
    string name;
    float rate;
    int quantity;
    float amount;
    purchased_items *next;
};

class inventory                                                     //inventory class for itmes
{
public:
    l item_id;
    string name;
    float rate;
    int quantity;
    inventory *next;

private:
    void insert_data(l item_id,string name,float rate,int quantity); // function to add items in item_database;
    void delete_item(l item_id);                                       //function to delete item from item dataset;
    void update_item(l item_id,float rate,int quantity);                //function to update stock and rate of the item;

public:
    void update_stock(l item_id,int quantity);                      //function to update stock of the item
    void get_product_info(l item_id);                               //function to get information about any item;
    friend class manager;

};

inventory *item_table[10];


void inventory::insert_data(l item_id,string name,float rate,int quantity)
{
    inventory *newhash = new inventory;
    newhash->item_id=item_id;
    newhash->name=name;
    newhash->rate=rate;
    newhash->quantity=quantity;

    int index=hash_function(item_id);
    if(item_table[index]==NULL)
        item_table[index]=newhash;
    else
    {
        inventory *temp=item_table[index];
         while(temp->next)
        {
            temp=temp->next;
        }
        temp->next=newhash;
    }
}

void inventory::delete_item(l item_id)
{
    int index=hash_function(item_id);
    inventory *temp=item_table[index];
    bool flag=false;
    inventory *temp1=NULL;

    while(temp != NULL)
    {
        if(temp->item_id == item_id)
        {
            flag=true;
            temp1->next=temp->next;
            delete temp;
            cout<<"Item Deleted!!"<<endl<<endl;
            break;
        }
        else
        {
            temp1=temp;
            temp=temp->next;
        }
    }
    if(flag == false)
        cout<<"Please enter valid Item_Id !"<<endl<<endl;
}

void inventory :: update_item(l item_id,float rate,int quantity)
{
    int index=hash_function(item_id);
    inventory *temp=item_table[index];
    bool flag=false;
    while(temp!=NULL)
    {
        if(temp->item_id == item_id)
        {
            flag=true;
            temp->rate=rate;
            temp->quantity=quantity;
            break;
        }
        else
            temp=temp->next;

    }

    if(flag==true)
        cout<<"Item with item_id "<<item_id<<" updated!"<<endl;
    else
        cout<<"Item with item_id "<<item_id<<" not found!"<<endl;
}

void inventory::update_stock(l item_id,int quantity)
{
    int index=hash_function(item_id);
    inventory *temp=item_table[index];
    bool flag=false;
    while(temp!=NULL)
    {
        if(temp->item_id == item_id)
        {
            flag=true;
            temp->quantity=quantity;
            break;
        }
        else
            temp=temp->next;

    }

    if(flag==true)
        cout<<"Stock of item  "<<item_id<<" updated!"<<endl;
    else
        cout<<"Item with item_id "<<item_id<<" not found!"<<endl;
}

void inventory::get_product_info(l item_id)
{
    int index=hash_function(item_id);
    inventory *temp=item_table[index];
    bool flag=false;
    while(temp!=NULL)
    {
        if(temp->item_id==item_id)
        {
            flag=true;
            break;
        }
        else
            temp=temp->next;
    }
    if(flag==false)
        cout<<"ITEM , NOT FOUND !!!!!!!!!"<<endl<<endl;
    else
        cout<<"Product Id : "<<temp->item_id<<" Product Name : "<<temp->name<<" Rate : "<<temp->rate<<" Quantity : "<<temp->quantity<<endl<<endl;
}

class customer                                           //customer class for customer for customer related informations
{
    l customer_id;
    string name;
    float points;
    customer *next;
public:

    void insert_customer_data(l customer_id,string name,float points);  //function to add new customer in dataset
    void update_points(l customer_id,float points);                     //function to update the points of customers
    void get_customer_info(l customer_id);                              //function to get information about the customer

    customer* search_customer(l customer_id);                           // function to return customer information
    string search_customer_name(l customer_id);                         // function to get the name of customer
};

customer *customer_table[10];

void customer::insert_customer_data(l customer_id,string name,float points)
{
    customer *newhash = new customer;
    newhash->customer_id=customer_id;
    newhash->name=name;
    newhash->points=points;

    int index=hash_function(customer_id);
    if(customer_table[index]==NULL)
        customer_table[index]=newhash;
    else
    {
        customer *temp=customer_table[index];
         while(temp->next)
        {
            temp=temp->next;
        }
        temp->next=newhash;
    }
}

void customer::update_points(l customer_id,float points)
{
    int index=hash_function(customer_id);
    bool flag=false;
    customer *temp=customer_table[index];
    while(temp!=NULL)
    {
        if(temp->customer_id == customer_id)
        {
            flag=true;
            temp->points+=points;
            break;
        }
        else
            temp=temp->next;
    }
    if(flag == true)
    {
        cout<<"points of customer "<<customer_id<<" updated !!"<<endl<<endl;
    }
    else
        cout<<"Invalid Customer_Id !!"<<endl;

}

void customer::get_customer_info(l customer_id)
{
    int index=hash_function(customer_id);
    customer *temp=customer_table[index];
    bool flag=false;
    while(temp!=NULL)
    {
        if(temp->customer_id==customer_id)
        {
            flag=true;
            break;
        }
        else
            temp=temp->next;
    }
    if(flag==false)
        cout<<"Customer , NOT FOUND !!!!!!!!!"<<endl<<endl;
    else
        cout<<"Customer Id : "<<temp->customer_id<<" Customer Name : "<<temp->name<<" Points : "<<temp->points<<endl<<endl;
}

customer* customer::search_customer(l customer_id)
{
    int index=hash_function(customer_id);
    customer* temp=customer_table[index];

    while(temp != NULL)
    {
        if(temp->customer_id == customer_id)
            return temp;
        else
            temp=temp->next;
    }
    return NULL;
}

string customer::search_customer_name(l customer_id)
{
    int index=hash_function(customer_id);
    customer *temp=customer_table[index];

    while(temp != NULL)
    {
        if(temp->customer_id == customer_id)
            return (temp->name);
        else
            temp=temp->next;
    }
    return NULL;
}

class manager : public inventory                                //manager class for manager's information
{
    l manager_id;
    string name;
public:
    manager(l manager_id,string name)
    {
        this->manager_id=manager_id;
        this->name=name;
    }

    void insertdata(inventory *i1,l item_id,string name,float rate,int quantity)  //function to insert item i item table
    {
            i1->insert_data(item_id,name,rate,quantity);
    }
    void deleteitem(inventory *i1,l item_id)                                    //function to delete item from the table
    {
        i1->delete_item(item_id);
    }
    void updateitem(inventory *i1,l item_id,float rate,int quantity)        //function to update the item
    {
        i1->update_item(item_id,rate,quantity);
    }
};

class billing : public inventory,public customer                            //billing class for billings
{
    l customer_id;
    string transaction_id;
    float total_amount;
    purchased_items *head=NULL;

public:
    void set_customer_id(l customer_id){this->customer_id=customer_id;}     //function to set the id of customer
    void set_transaction_id(string transaction_id){this->transaction_id=transaction_id;}   //function for transaction id

    l get_customer_id(){return customer_id;}    //function to get customer id for make_payment
    string get_transaction_id(){return transaction_id;}     //function to get transaction id while  making payment

    void buy_item(l item_id,int quantity);                  //function to buy items for the cutomer
    void cancle_item(l item_id,int quantity);               //function to cancel item from the purchased list
    void make_payment();                                    //function for making payment
    int get_info_of_purchased_item(l item_id);          //function to get information of purchased item(number of items)
                                                // (when we are going to delete item from the purchased list,it is used)
};

void billing::buy_item(l item_id,int quantity)
{
    int index=hash_function(item_id);
    inventory *temp=item_table[index];
    bool flag=false;

    while(temp != NULL)
    {
        if(temp->item_id == item_id)
        {
            flag=true;
            break;
        }
        else
            temp=temp->next;
    }

    if(flag==true)
    {
        purchased_items *newnode=new purchased_items;

        newnode->item_id=temp->item_id;
        newnode->name=temp->name;
        newnode->rate=temp->rate;
        newnode->quantity=quantity;
        newnode->amount=(temp->rate)*(quantity);
        newnode->next=NULL;

        temp->quantity-=quantity;
        total_amount+=newnode->amount;

        if(head == NULL)
            head=newnode;
        else
        {
            purchased_items *temp=head;
            while(temp->next != NULL)
                temp=temp->next;
            temp->next=newnode;
        }
    }
    else
        cout<<"Item Not Found!!!"<<endl;

}

int billing :: get_info_of_purchased_item(l item_id)
{
    purchased_items *temp=head;
    while(temp!=NULL)
    {
        if(temp->item_id == item_id)
            return (temp->quantity);
        else
            temp=temp->next;
    }
    return 0;
}

void billing :: cancle_item(l item_id,int quantity)
{
    purchased_items *temp=head;
    bool flag=false;
    purchased_items *temp1=NULL;

    while(temp != NULL)
    {
        if(temp == head)
        {
            if(temp->item_id == item_id)
            {
                flag=true;
                head=temp->next;
                total_amount=total_amount-(temp->amount);
                delete temp;
                update_stock(item_id,quantity);
                cout<<"Item Cancelled!!"<<endl<<endl;
                break;
            }
            else
            {
                temp1=temp;
                temp=temp->next;
            }
        }
        else if(temp->item_id == item_id)
        {
            temp1->next=temp->next;
            flag=true;
            total_amount=total_amount-(temp->amount);
            update_stock(item_id,quantity);
            cout<<"Item Cancelled!!"<<endl<<endl;
            delete temp;
            break;
        }
        else
        {
            temp1=temp;
            temp=temp->next;
        }
    }
    if(flag == false)
        cout<<"Please enter valid Item_Id !"<<endl<<endl;

}

void billing :: make_payment()
{
    cout<<"\t\t\t\t\t\t\t***Invoice***\n\n"<<endl;
    cout<<"Transaction Id :     "<<get_transaction_id()<<endl;
    cout<<"Customer Id :        "<<get_customer_id()<<endl<<endl;
    cout<<"Product-ID       Name        Rate        Quantity        Amount"<<endl<<endl;

        purchased_items *temp=head;
        while(temp!=NULL)
        {
            cout<<temp->item_id<<"      "<<temp->name<<"         "<<temp->rate<<"            "<<temp->quantity<<"             "<<temp->amount<<endl;
            temp=temp->next;
        }

    cout<<endl<<"                                          Total Amount :-"<<total_amount<<endl<<endl;
    update_points(get_customer_id(),total_amount);
}

int main()
{
    long long int INVENTORY_DATASET[100][4] = {
{111100000001,1,100,20},{111100000002,2,110,20},{111100000003,3,120,20},{111100000004,4,130,20},{111100000005,5,140,20},{111100000006,6,150,20},{111100000007,7,160,20},{111100000008,8,170,20},{111100000009,9,180,20},{111100000010,10,190,20},
{111100000011,11,200,20},{111100000012,12,210,20},{111100000013,13,220,20},{111100000014,14,230,20},{111100000015,15,240,20},{111100000016,16,250,20},{111100000017,17,260,20},{111100000018,18,270,20},{111100000019,19,280,20},{111100000020,20,290,20},
{111100000021,21,300,20},{111100000022,22,310,20},{111100000023,23,320,20},{111100000024,24,330,20},{111100000025,25,340,20},{111100000026,26,350,20},{111100000027,27,360,20},{111100000028,28,370,20},{111100000029,29,380,20},{111100000030,30,390,20},
{111100000031,31,400,20},{111100000032,32,410,20},{111100000033,33,420,20},{111100000034,34,430,20},{111100000035,35,440,20},{111100000036,36,450,20},{111100000037,37,460,20},{111100000038,38,470,20},{111100000039,39,480,20},{111100000040,40,490,20},
{111100000041,41,500,20},{111100000042,42,510,20},{111100000043,43,520,20},{111100000044,44,530,20},{111100000045,45,540,20},{111100000046,46,550,20},{111100000047,47,560,20},{111100000048,48,570,20},{111100000049,49,580,20},{222200001111,50,590,20},
{222200001114,51,600,20},{222200001117,52,610,20},{222200001120,53,620,20},{222200001123,54,630,20},{222200001126,55,640,20},{222200001129,56,650,20},{222200001132,57,660,20},{222200001135,58,670,20},{222200001138,59,680,20},{222200001141,60,690,20},
{222200001144,61,700,20},{222200001147,62,710,20},{222200001150,63,720,20},{222200001153,64,730,20},{222200001156,65,740,20},{222200001159,66,750,20},{222200001162,67,760,20},{222200001165,68,770,20},{222200001168,69,780,20},{222200001171,70,790,20},
{222200001174,71,800,20},{222200001177,72,810,20},{222200001180,73,820,20},{222200001183,74,830,20},{222200001186,75,840,20},{222200001189,76,850,20},{222200001192,77,860,20},{222200001195,78,870,20},{222200001198,79,880,20},{222200001201,80,890,20},
{222200001204,81,900,20},{222200001207,82,910,20},{222200001210,83,920,20},{222200001213,84,930,20},{222200001216,85,940,20},{222200001219,86,950,20},{222200001222,87,960,20},{222200001225,88,970,20},{222200001228,89,980,20},{222200001231,90,990,20},
{222200001234,91,1000,20},{222200001237,92,1010,20},{222200001240,93,1020,20},{222200001243,94,1030,20},{222200001246,95,1040,20},{222200001249,96,1050,20},{222200001252,97,1060,20},{222200001255,98,1070,20},{222200001258,99,1080,20},{222200001261,100,1090,20},
};

    long long int CUSTOMER_DATASET[100][3] = {
{9400000001,1,0},{9400000002,2,0},{9400000003,3,0},{9400000004,4,0},{9400000005,5,0},{9400000006,6,0},{9400000007,7,0},{9400000008,8,0},{9400000009,9,0},{9400000010,10,0},
{9400000011,11,0},{9400000012,12,0},{9400000013,13,0},{9400000014,14,0},{9400000015,15,0},{9400000016,16,0},{9400000017,17,0},{9400000018,18,0},{9400000019,19,0},{9400000020,20,0},
{9400000021,21,0},{9400000022,22,0},{9400000023,23,0},{9400000024,24,0},{9400000025,25,0},{9400000026,26,0},{9400000027,27,0},{9400000028,28,0},{9400000029,29,0},{9400000030,30,0},
{9400000031,31,0},{9400000032,32,0},{9400000033,33,0},{9400000034,34,0},{9400000035,35,0},{9400000036,36,0},{9400000037,37,0},{9400000038,38,0},{9400000039,39,0},{9400000040,40,0},
{9400000041,41,0},{9400000042,42,0},{9400000043,43,0},{9400000044,44,0},{9400000045,45,0},{9400000046,46,0},{9400000047,47,0},{9400000048,48,0},{9400000049,49,0},{9400000050,50,0},
{9400000051,51,0},{9400000052,52,0},{9400000053,53,0},{9400000054,54,0},{9400000055,55,0},{9400000056,56,0},{9400000057,57,0},{9400000058,58,0},{9400000059,59,0},{9400000060,60,0},
{9400000061,61,0},{9400000062,62,0},{9400000063,63,0},{9400000064,64,0},{9400000065,65,0},{9400000066,66,0},{9400000067,67,0},{9400000068,68,0},{9400000069,69,0},{9400000070,70,0},
{9400000071,71,0},{9400000072,72,0},{9400000073,73,0},{9400000074,74,0},{9400000075,75,0},{9400000076,76,0},{9400000077,77,0},{9400000078,78,0},{9400000079,79,0},{9400000080,80,0},
{9400000081,81,0},{9400000082,82,0},{9400000083,83,0},{9400000084,84,0},{9400000085,85,0},{9400000086,86,0},{9400000087,87,0},{9400000088,88,0},{9400000089,89,0},{9400000090,90,0},
{9400000091,91,0},{9400000092,92,0},{9400000093,93,0},{9400000094,94,0},{9400000095,95,0},{9400000096,96,0},{9400000097,97,0},{9400000098,98,0},{9400000099,99,0},{9400000100,100,0},
};
    manager m1(201901432,"NILESH");
    inventory i1;
    billing b1;
    customer c1;
    for(int i=0;i<100;i++)
    {
        m1.insertdata(&i1,INVENTORY_DATASET[i][0],to_string(INVENTORY_DATASET[i][1]),INVENTORY_DATASET[i][2],INVENTORY_DATASET[i][3]);
    }


    for(int j=0;j<100;j++)
    {
        c1.insert_customer_data(CUSTOMER_DATASET[j][0],to_string(CUSTOMER_DATASET[j][1]),CUSTOMER_DATASET[j][2]);
    }
    bool flag=true;
    int choice;
    do
    {
        cout<<"1. To see a sample Test Case :- "<<endl;
        cout<<"2. To buy a item "<<endl;
        cout<<"3. To make payment "<<endl;
        cout<<"4. To cancel item "<<endl;
        cout<<"5. To see products information "<<endl;
        cout<<"6. To see customer information "<<endl;
        cout<<"7. To exit "<<endl;
        cout<<"enter your choice ;"<<endl;
        cin>>choice;

        switch(choice)
        {
            case 1:
                {
                    cout<<"Before Buying episode , information of some items ; "<<endl<<endl;

                    m1.deleteitem(&i1,111100000020);

                    b1.get_product_info(111100000020);
                    b1.get_product_info(111100000021);
                    b1.get_product_info(932873319197);
                    b1.get_product_info(111100000022);
                    b1.get_product_info(111100000023);

                    b1.get_customer_info(9400000008);

                    b1.set_customer_id(9400000008);
                    b1.set_transaction_id("NILESH");

                    b1.buy_item(111100000020,1);
                    b1.buy_item(111100000021,4);
                    b1.buy_item(111100000022,2);
                    b1.buy_item(111100000023,3);

                    b1.make_payment();

                    cout<<"after buying episode , information of some items ;"<<endl<<endl;
                    b1.get_product_info(111100000020);
                    b1.get_product_info(111100000021);
                    b1.get_product_info(111100000022);
                    b1.get_product_info(111100000023);

                    b1.get_customer_info(9400000008);

                    flag=false;
                    break;
                }
            case 2:
                {
                    l item_id;
                    int quantity;
                    cout<<"Enter product ID for the item and quantity of the item"<<endl;
                    cin>>item_id>>quantity;
                    b1.buy_item(item_id,quantity);
                    break;
                }
            case 3:
                {
                    l customer_id;
                    string name;
                    cout<<"enter your mobile number ;"<<endl;
                    cin>>customer_id;

                    if(c1.search_customer(customer_id) == NULL)
                    {
                        cout<<"enter your name ;"<<endl;
                        cin>>name;
                        c1.insert_customer_data(customer_id,name,0);
                    }
                    b1.set_customer_id(customer_id);
                    b1.set_transaction_id((c1.search_customer_name(customer_id)));

                    b1.make_payment();
                    break;
                }
            case 4:
                {
                    cout<<"Enter item_id to cancel"<<endl;
                    l item_id;
                    cin>>item_id;
                    int num=b1.get_info_of_purchased_item(item_id);
                    b1.cancle_item(item_id,num);
                    break;
                }
            case 5:
                {
                    l item_id;
                    cout<<"enter product id to see information ;"<<endl;
                    cin>>item_id;
                    b1.get_product_info(item_id);
                    break;
                }
            case 6:
                {
                    l customer_id;
                    cout<<"enter number to see customer info ;"<<endl;
                    cin>>customer_id;
                    b1.get_customer_info(customer_id);
                    break;
                }
            case 7:
                {
                    flag=false;
                    break;
                }
            default:
                cout<<"Enter valid Number !!"<<endl;
        }
    }while(flag);

    return 0;
}


