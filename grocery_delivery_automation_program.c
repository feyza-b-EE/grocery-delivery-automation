#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Define structures for customer, product, and store
typedef struct Customer 
{
    int customer_id;
    char name[50];
    int address;
    struct Product *purchasedProducts;
    double totalSpent;
    struct Customer *next;
} Customer;

typedef struct Product 
{
    int product_id;
    char name[50];
    int type; 
    double price;
    int quantity;
    struct Product *next;
} Product;

typedef struct Store 
{
    int store_id;
    char name[50];
    int address;
    struct Store *next;
} Store;


void salesMenu(Customer *customers, Store *stores, Product *products);
void customerInformationMenu(Customer *customers);
void storeInformationMenu(Store *stores);
void productInformationMenu(Product *products);
void customerAnalysisMenu(Customer *customers, Product *products, Store *stores);
void displayCustomers(Customer *customers);
void displayStores(Store *stores);
void displayProducts(Product *products);
double calculateShippingFee(int customer_address, int store_address);
Customer *findCustomer(Customer *customers, int customer_id);
Store *findStore(Store *stores, int store_id);
Product *findProduct(Product *products, int product_id);
void listProductsPurchasedByCustomer(Customer *customers, Product *products);
void totalAmountByCustomer(Customer *customers, Product *products);
void totalAmountByAllCustomers(Customer *customers, Product *products);
void totalShippingCosts(Customer *customers, Store *stores);

int main() 
{
    //Sample data for customers, stores, and products
    Customer *customers = NULL;
    Store *stores = NULL;
    Product *products = NULL;
    int choice;
    
    //Populate customers linked list
    Customer *customer1 = malloc(sizeof(Customer));
    customer1->customer_id = 1;
    strcpy(customer1->name, "Ayse Feyza");
    customer1->address = 1;
    
    Customer *customer2 = malloc(sizeof(Customer));
    customer2->customer_id = 2;
    strcpy(customer2->name, "Emir");
    customer2->address = 3;
    
    Customer *customer3 = malloc(sizeof(Customer));
    customer3->customer_id = 3;
    strcpy(customer3->name, "Murat");
    customer3->address = 10;
    
    Customer *customer4 = malloc(sizeof(Customer));
    customer4->customer_id = 4;
    strcpy(customer4->name, "Dilara");
    customer4->address = 7;
    
    Customer *customer5 = malloc(sizeof(Customer));
    customer5->customer_id = 5;
    strcpy(customer5->name, "Aylin");
    customer5->address = 6;
    
    Customer *customer6 = malloc(sizeof(Customer));
    customer6->customer_id = 6;
    strcpy(customer6->name, "Soner");
    customer6->address = 2;
    
    customer1->next = customer2;
    customer2->next = customer3;
    customer3->next = customer4;
    customer4->next = customer5;
    customer5->next = customer6;
    customer6->next = NULL;
    
    customers = customer1;
    
    //Populate stores linked list 
    Store *store1 = malloc(sizeof(Store));
    store1->store_id = 1;
    strcpy(store1->name, "Store 1");
    store1->address = 1;
    
    Store *store2 = malloc(sizeof(Store));
    store2->store_id = 2;
    strcpy(store2->name, "Store 2");
    store2->address = 2;
    
    Store *store3 = malloc(sizeof(Store));
    store3->store_id = 3;
    strcpy(store3->name, "Store 3");
    store3->address = 4;
    
    Store *store4 = malloc(sizeof(Store));
    store4->store_id = 4;
    strcpy(store4->name, "Store 4");
    store4->address = 6;
    
    Store *store5 = malloc(sizeof(Store));
    store5->store_id = 5;
    strcpy(store5->name, "Store 5");
    store5->address = 7;
    
    Store *store6 = malloc(sizeof(Store));
    store6->store_id = 6;
    strcpy(store6->name, "Store 6");
    store6->address = 8;
    
    store1->next = store2;
    store2->next = store3;
    store3->next = store4;
    store4->next = store5;
    store5->next = store6;
    store6->next = NULL;
    
    stores = store1;
    
    //Populate products linked list 
    Product *product1 = malloc(sizeof(Product));
    product1->product_id = 1;
    strcpy(product1->name, "Portakal Sikma");
    product1->type = 1;
    product1->price = 5.99;
    
    Product *product2 = malloc(sizeof(Product));
    product2->product_id = 2;
    strcpy(product2->name, "Muz Yerli");
    product2->type = 1;
    product2->price = 12.95;
    
    Product *product3 = malloc(sizeof(Product));
    product3->product_id = 3;
    strcpy(product3->name, "Sogan");
    product3->type = 2;
    product3->price = 7.45;
    
    Product *product4 = malloc(sizeof(Product));
    product4->product_id = 4;
    strcpy(product4->name, "Pirasa");
    product4->type = 2;
    product4->price = 3.95;
    
    Product *product5 = malloc(sizeof(Product));
    product5->product_id = 5;
    strcpy(product5->name, "Lahana");
    product5->type = 2;
    product5->price = 5.95;
    
    Product *product6 = malloc(sizeof(Product));
    product6->product_id = 6;
    strcpy(product6->name, "Limon");
    product6->type = 1;
    product6->price = 7.45;
    
    Product *product7 = malloc(sizeof(Product));
    product7->product_id = 7;
    strcpy(product7->name, "Hamsi");
    product7->type = 3;
    product7->price = 15;
    
    product1->next = product2;
    product2->next = product3;
    product3->next = product4;
    product4->next = product5;
    product5->next = product6;
    product6->next = product7;
    product7->next = NULL;
    
    products = product1;
    
    do 
    {
        //Display main menu
        printf("\nMain Menu\n");
        printf("1. Sales\n");
        printf("2. Customer Information\n");
        printf("3. Store Information\n");
        printf("4. Product Information\n");
        printf("5. Customer Analysis\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        
        switch (choice) 
		{
            case 1:
                salesMenu(customers, stores, products); 
                break;
            case 2:
                customerInformationMenu(customers);
                break;
            case 3:
                storeInformationMenu(stores);
                break;
            case 4:
                productInformationMenu(products);
                break;
            case 5:
                customerAnalysisMenu(customers, products, stores); 
                break;
            case 6:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void displayCustomers(Customer *customers)
{
    printf("\nCustomer ID\tCustomer Name\tCustomer Address\n");
    printf("_________________________________________________\n");
    while (customers != NULL)
    {
        printf("%-15d%-22s%-10d\n", customers->customer_id, customers->name, customers->address);
        customers = customers->next;
    }
}

void customerInformationMenu(Customer *customers) 
{
    int choice, choice2;
    do 
	{
        //Display customer information menu
        printf("\nCustomer Information Menu\n");
        printf("1. All customers\n");
        printf("2. Single customer\n");
        printf("3. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                displayCustomers(customers);
                break;
            case 2:
                printf("\nEnter ID number of customer to see the information: ");
                scanf("%d", &choice2);
                Customer *foundCustomer = findCustomer(customers, choice2);
                if (foundCustomer != NULL) 
				{
                    printf("\nCustomer Name: %s\nCustomer Address: %d\n", foundCustomer->name, foundCustomer->address);
                } else 
				{
                    printf("\nCustomer not found.\n");
                }
                break;
            case 3:
                printf("Returning to Main Menu.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);
}

void displayStores(Store *stores)
{
    printf("\nStore ID\tStore Name\tStore Address\n");
    printf("_________________________________________________\n");
    while (stores != NULL)
    {
        printf("%d\t\t%s\t\t%d\n", stores->store_id, stores->name, stores->address);
        stores = stores->next;
    }
}

void storeInformationMenu(Store *stores)
{
    int choice, choice2;
    do 
	{
        //Display store information menu
        printf("\nStore Information Menu\n");
        printf("1. All stores\n");
        printf("2. Single store\n");
        printf("3. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
		{
            case 1:
                displayStores(stores);
                break;
            case 2:
                printf("Enter ID of Store to see the information: ");
                scanf("%d", &choice2);
                Store *foundStore = findStore(stores, choice2);
                if (foundStore != NULL) 
				{
                    printf("\nStore Name: %s\nStore Address: %d\n", foundStore->name, foundStore->address);
                } else 
				{
                    printf("\nStore not found.\n");
                }
                break;
            case 3:
                printf("\nReturning to Main Menu.\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 3);
}

void displayProducts(Product *products)
{
    printf("\nProduct ID\tProduct Name\tProduct Type\tProduct Price\n");
    printf("_________________________________________________\n");
    while (products != NULL)
    {
         printf("%-13d%-18s%-15d%-10.2f\n", products->product_id, products->name, products->type, products->price);
        products = products->next;
    }
}

void productInformationMenu(Product *products)
{
    int choice, choice2;
    Product *currentProduct = products; //Store the original pointer to the head of the linked list
    do 
	{
        //Display product information menu
        printf("\nProduct Information Menu\n");
        printf("1. All products\n");
        printf("2. According to product type\n");
        printf("3. Single product\n");
        printf("4. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
		{
            case 1:
                displayProducts(products);
                break;
        	case 2:
        		printf("\nType 1 Products:\n");
                while (products != NULL)
                {
                	if(products->type == 1)
                	{
                    	printf("Product Name: %s\n", products->name);
                	}
                	products = products->next;
            	}
            	printf("\nType 2 Products:\n");
            	products = currentProduct; //Reset pointer to the head of the linked list
            	while (products != NULL)
                {
                	if(products->type == 2)
                	{
                    	printf("Product Name: %s\n", products->name);
                	}
                	products = products->next;
            	}
            	printf("\nType 3 Products:\n");
            	products = currentProduct; //Reset pointer to the head of the linked list
            	while (products != NULL)
                {
                	if(products->type == 3)
                	{
                    	printf("Product Name: %s\n", products->name);
                	}
                	products = products->next;
            	}
            	break;
            case 3:
                printf("\nEnter ID of Product to see the information: ");
                scanf("%d", &choice2);
                Product *foundProduct = findProduct(currentProduct, choice2); 
                if (foundProduct != NULL) {
                    printf("\nProduct Name: %s\nProduct Type: %d\nProduct Price: %.2f liras\n", foundProduct->name, foundProduct->type, foundProduct->price);
                } else {
                    printf("\nProduct not found.\n");
                }
                break;
            case 4:
                printf("Returning to Main Menu.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
}


Customer *findCustomer(Customer *customers, int customer_id)
{
    while (customers != NULL)
    {
        if (customers->customer_id == customer_id)
        {
            return customers;
        }
        customers = customers->next;
    }
    return NULL;
}

Store *findStore(Store *stores, int store_id)
{
    while (stores != NULL)
    {
        if (stores->store_id == store_id)
        {
            return stores;
        }
        stores = stores->next;
    }
    return NULL;
}

Product *findProduct(Product *products, int product_id)
{
    while (products != NULL)
    {
        if (products->product_id == product_id)
        {
            return products;
        }
        products = products->next;
    }
    return NULL;
}

Store *findNearestStore(int customer_address, Store *stores)
{
    Store *nearestStore = NULL;
    double minDistance = 1000; 

    //Iterate through stores to find the nearest one
    while (stores != NULL) 
	{
        double distance = fabs(customer_address - stores->address); //Calculate distance
        if (distance < minDistance) 
		{
            minDistance = distance;
            nearestStore = stores;
        }
        stores = stores->next;
    }

    return nearestStore;
}


void listProductsPurchasedByCustomer(Customer *customers, Product *products)
{
    int customer_id;
    printf("Enter the customer ID: ");
    scanf("%d", &customer_id);
    Customer *customer = findCustomer(customers, customer_id);
    if (customer != NULL)
    {
        printf("Products purchased by %s:\n", customer->name);
        //Iterate through the products purchased by the customer
        while (customer->purchasedProducts != NULL)
        {
            printf("%s\n", customer->purchasedProducts->name);
            customer->purchasedProducts = customer->purchasedProducts->next;
        }
    }
    else
    {
        printf("Customer not found.\n");
    }
}

void totalAmountByCustomer(Customer *customers, Product *products)
{
    int customer_id;
    double total_amount = 0.0;
    printf("Enter the customer ID: ");
    scanf("%d", &customer_id);
    Customer *customer = findCustomer(customers, customer_id);
    if (customer != NULL)
    {
        Product *purchasedProduct = customer->purchasedProducts;
        while (purchasedProduct != NULL) 
        {
            total_amount += purchasedProduct->price * purchasedProduct->quantity;
            purchasedProduct = purchasedProduct->next;
        }
        printf("Total amount spent by %s: %.2f liras\n", customer->name, total_amount);
    }
    else
    {
        printf("Customer not found.\n");
    }
}

void totalAmountByAllCustomers(Customer *customers, Product *products)
{
    double total_amount = 0.0;
    while (customers != NULL)
    {
        Product *purchasedProduct = customers->purchasedProducts;
        while (purchasedProduct != NULL) 
        {
            total_amount += purchasedProduct->price * purchasedProduct->quantity;
            purchasedProduct = purchasedProduct->next;
        }
        customers = customers->next;
    }
    printf("Total amount spent by all customers: %.2f liras\n", total_amount);
}





double calculateShippingFee(int customer_address, int store_address)
{
    //Calculating shipping fee calculation based on distance
    double distance = fabs(customer_address - store_address) ;
    //12.5 lira per kilometer
    double shipping_fee = 25 + (distance * 12.5);
    return shipping_fee;
}



void totalShippingCosts(Customer *customers, Store *stores)
{
    double total_shipping_costs = 0.0;
    while (customers != NULL)
    {
        Customer *customer = customers;
        Store *nearestStore = findNearestStore(customer->address, stores);
        if (nearestStore != NULL) 
        {
            double shipping_fee = calculateShippingFee(customer->address, nearestStore->address);
            total_shipping_costs += shipping_fee;
        }
        customers = customers->next;
    }
    printf("Total shipping costs: %.2f liras\n", total_shipping_costs);
}


void salesMenu(Customer *customers, Store *stores, Product *products) 
{
    int i, customer_id, product_id, quantity;
    double total_cost = 0.0, shipping_fee = 0.0;
    Customer *customer = NULL;
    Store *store = NULL;
    Product *product = NULL;

    //Define a structure to keep track of products purchased by the customer
    typedef struct 
    {
        Product *product;
        int quantity;
    } CartItem;
    
    CartItem cart[100]; 
    int cartIndex = 0; //Index to keep track of the current position in the cart
    

    printf("Enter customer number: ");
    scanf("%d", &customer_id);

    //Find the customer
    while (customers != NULL) 
	{
        if (customers->customer_id == customer_id) 
		{
            customer = customers;
            break;
        }
        customers = customers->next;
    }

    //If customer not found, return
    if (customer == NULL) 
	{
        printf("\nCustomer not found.\n");
        return;
    }

    //Start purchasing process
    printf("Purchasing process started for customer: %s\n", customer->name);

    do 
	{
        //Ask for product number and quantity
        printf("\nEnter product number and quantity (0, 0 to finish): ");
        scanf("%d %d", &product_id, &quantity);

        //If product_id is 0, exit the loop
        if (product_id == 0 && quantity == 0)
            break;

        //Find the product
        product = findProduct(products, product_id);
        if (product != NULL) 
		{
            //Calculate product cost and add to total cost
            double product_cost = product->price * quantity;
            total_cost += product_cost;
            //Add the product to the cart
            cart[cartIndex].product = product;
            cart[cartIndex].quantity = quantity;
            cartIndex++;
            printf("Added %d units of %s to the cart. Cost: %.2f liras\n", quantity, product->name, product_cost);
        }
        else 
		{
            printf("Product not found.\n");
        }

    } while (product_id != 0 || quantity != 0);

    // Add purchased products to the customer's purchasedProducts linked list
    for (i = 0; i < cartIndex; i++) 
	{
        Product *purchasedProduct = malloc(sizeof(Product));
        purchasedProduct->product_id = cart[i].product->product_id;
        strcpy(purchasedProduct->name, cart[i].product->name);
        purchasedProduct->price = cart[i].product->price;
        purchasedProduct->next = customer->purchasedProducts;
        customer->purchasedProducts = purchasedProduct;
    }

    //Find the nearest store to the customer
    store = findNearestStore(customer->address, stores);

    //Display the nearest store information
    if (store != NULL) 
	{
        printf("\nNearest store: %s\n", store->name);
        printf("Store address: %d\n", store->address);
        // Calculate shipping fee based on distance between customer and store
        shipping_fee = calculateShippingFee(customer->address, store->address);
    }
    else 
	{
        printf("\nNo store found nearby.\n");
    }

    //Update total spending for the customer
    customer->totalSpent += total_cost;

    //Complete purchase process
    printf("\nPurchase completed for customer: %s\n", customer->name);
    printf("Total cost: %.2f liras\n", total_cost);
    printf("Shipping fee: %.2f liras\n", shipping_fee);
    printf("Total amount to pay: %.2f liras\n", total_cost + shipping_fee);
}


void customerAnalysisMenu(Customer *customers, Product *products, Store *stores)
{
    int choice;
    do 
	{
        //Display customer analysis menu
        printf("\nCustomer Analysis Menu\n");
        printf("1. List products purchased by customer\n");
        printf("2. Total amount spent by customer\n");
        printf("3. Total amount spent by all customers\n");
        printf("4. Total shipping costs\n");
        printf("5. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

       
        switch (choice)
        {
            case 1:
                listProductsPurchasedByCustomer(customers, products);
                break;
            case 2:
                totalAmountByCustomer(customers, products);
                break;
            case 3:
                totalAmountByAllCustomers(customers, products);
                break;
            case 4:
                totalShippingCosts(customers, stores);
                break;
            case 5:
                printf("Returning to Main Menu.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
}



