import { StyleSheet, View , Text} from "react-native";
import { useNavigation } from "@react-navigation/native";
import AppButton from "../components/CustomButton";
import React from "react";
export default function Home() {


  
    const postData = async (id) => {
        try {
            await fetch(
                'http://192.168.100.34:8000/post', {
                    method: 'POST',
                    headers: {
                      Accept: 'application/json',
                      'Content-Type': 'application/json'
                    },
                    body: JSON.stringify({
                      value: id,

                    })
                  });
        }
        catch (error) {
            console.error(error);
        }
    }
  const navigation = useNavigation();
  const navigationHandler = (id) => {
      if (id === 0) {
        navigation.navigate("Manual");
      } else {
        navigation.navigate("Automatic");
          
      }
    
  };
  return (
    <View style={styles.container}>
        <AppButton  title="Manual" onPress={() => { postData(0); navigationHandler(0);} }/>
        <View style={styles.m1}/>
        <AppButton  title="Automatic"  onPress={() => { postData(1); navigationHandler(1);}}/>
    </View>

  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: "#fff",
    alignItems: "center",
    justifyContent: "center",
  },
  m1:{
    marginTop:20
  }
});
