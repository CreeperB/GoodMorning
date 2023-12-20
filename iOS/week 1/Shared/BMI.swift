import SwiftUI

struct ContentView: View {
    @State var height: String = ""
    @State var weight: String = ""
    @State var BMI: Float = 0
    
    var body: some View {
        ZStack {
            Color.pink
                .opacity(0.2)
                .ignoresSafeArea()
            VStack {
                
                Text("BMI:\(BMI,specifier:"%.2f")")
                    .font(.title2)
                    .padding()
                    .background(Color.purple)
                    .opacity(0.4)
                    .cornerRadius(69)
                
                TextField("輸入身高" , text: $height)
                    .textFieldStyle(RoundedBorderTextFieldStyle())
                    .padding()
                TextField("輸入體重" , text: $weight)
                    .textFieldStyle(RoundedBorderTextFieldStyle())
                    .padding()
                
                Button(action: {
                    
                    var h = Float(height) ?? 1.0
                    let w = Float(weight) ?? 1.0
                    h = h / 100
                    BMI = w / (h * h)
                    
                }){
                    Text("Calculate")
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
