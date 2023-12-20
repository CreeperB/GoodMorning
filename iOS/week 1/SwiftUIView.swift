import SwiftUI

struct SwiftUIView: View {
    @State var red:Double = 1.0
    @State var blue:Double = 1.0
    @State var green:Double = 1.0
    @State var change:Bool = false
    var body: some View {
        ZStack{
            Color(red :red, green: green, blue: blue)
                .ignoresSafeArea()
            VStack{
                HStack{
                    Text("R: \(Int(red*255))")
                        .font(.title)
                        .fontWeight(.light)
                    Text("G: \(Int(green*255))")
                        .font(.title)
                        .fontWeight(.light)
                    Text("B: \(Int(blue*255))")
                        .font(.title)
                        .fontWeight(.light)
                }
                Spacer()
                Toggle("我是開關", isOn: $change)
                    .padding()
                if(change){
                    Group{
                        Slider(value:$red)
                        Slider(value:$green)
                        Slider(value:$blue)
                    }
                    .border(.green)
                    .padding()
                }
            }
            .padding()
            
            
        }
    }
}

struct SwiftUIView_Previews: PreviewProvider {
    static var previews: some View {
        SwiftUIView()
    }
}
