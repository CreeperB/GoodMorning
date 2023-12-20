import SwiftUI

struct ContentView: View {
    
    @State var firstname = ""
    @State var lastname = ""
    @State var BD = Date()
    @State var noti: Bool = false
    @State var times = 1
    @State var fullName = ""
    
    var body: some View
    {
        VStack
        {
            Form
            {
                Section(header: Text("個人資料"))
                {
                    TextField("名字", text: $firstname)
                    TextField("姓氏", text: $lastname)
                    DatePicker("生日", selection: $BD, displayedComponents: .date)
                }
                Section(header: Text("個人設定")){
                    Toggle("接收通知", isOn: $noti)
                        .toggleStyle(SwitchToggleStyle(tint: .purple))
                    if(noti){
                        Stepper("一週願意收到\(times)次通知", value: $times, in: 1...7)
                    }
                }
                Text(fullName)
                Button(action: {
                    fullName = lastname + firstname
                })
                {
                    Text("儲存我的資料")
                }
            }
        }
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
