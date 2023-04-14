interface Hello {
    public void sayHello();
}
class HelloKorean implements Hello{
    public void sayHello(){
        System.out.println("한국어로 인사");
    }
}
class HelloChinese implements Hello{
    public void sayHello(){
        System.out.println("중국어로 인사");
    }
}
class HelloMain{
    public static void main(String[] args){
        Hello h = new HelloKorean();
        h.sayHello();
        h = new HelloKorean();
        h.sayHello();
        h = new HelloChinese();
        h.sayHello();
    }
}