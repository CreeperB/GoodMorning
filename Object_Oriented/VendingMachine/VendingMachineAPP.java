public class VendingMachineAPP {
    public static void main(String[] args) {
        VendingMachine vm = new VendingMachine();
        vm.select(VendingMachine.COCA_COLA);
        vm.select(VendingMachine.ORANGE_JUICE);
        vm.select(VendingMachine.EVIAN_MINERAL_WATER);
        vm.select(VendingMachine.MMS_CHOCOLATE);
        vm.select(VendingMachine.HERSHEY_CHOCOLATE_BAR);
        vm.select(VendingMachine.OREO_COOKIES);
        vm.select(VendingMachine.DORITOS_TORTILLA_CHIPS);
        vm.select(VendingMachine.PRINGLES_POTATO_CHIPS);
        vm.show();
        System.out.println("Total Price: USD " + vm.getTotalPrice());
    }
}
