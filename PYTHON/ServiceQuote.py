#A class allows to get/set parts charges, estimated labor charges, sales tax, and total estimated charges.
#Write  statements that use the class to call these get/set methods. 
class ServiceQuote:
    def __init__(self,parts,labor,sales_t):
        self.__parts = parts
        self.__labor = labor
        self.__sales_t = sales_t
    def set_parts(self,parts):
        self.__parts = parts
    def set_labor(self,labor):
        self.__labor = labor
    def set_sales_t(self,sales_t):
        self.__sales_t = sales_t * self.__parts
    def get_parts(self):
        return self.__parts
    def get_labor(self):
        return self.__labor
    def get_sales_t (self):
        return self.__sales_t * self.__parts
    def get_t_charge(self):
        return (self.__parts + self.__labor + (self.__parts*self.__sales_t))
def main():
    new_service = ServiceQuote(520,250,0.075)
    print(f'''Parts: {new_service.get_parts()}''')
    print(f'''Labor: {new_service.get_labor()}''')
    print(f'''Tax: {new_service.get_sales_t()}''')
    print(f'''------------------------
Total: {new_service.get_t_charge()}''')

if __name__ == '__main__':
    main()
    