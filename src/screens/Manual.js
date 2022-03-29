import { StyleSheet, Text, View  } from "react-native";
import React from "react";
import AppButton from "../components/CustomButton";

// const PostURL ="http://127.0.0.1:8000/post"


export default function Manual() {
  const clickHandler = (id) => {
    console.log(id)
    const PostURL =`http://192.168.100.34:8000/get/?val=${id}`
    fetch(PostURL)
    
    .catch((error) => alert(error)) // 
  };
  return (
    <View style={styles.container}>
      <Text style={styles.title}>Manual Mode</Text>
      <AppButton  title="up" icon="upcircleo" onPress={()=> {clickHandler(1)}} />
      <View style={styles.m1}/>
      <AppButton  title="down" icon="downcircleo" onPress={()=> {clickHandler(2)}} />
      <View style={styles.m1}/>
      <AppButton title="left" icon="leftcircleo" onPress={()=> {clickHandler(3)}} />
      <View style={styles.m1}/>
      <AppButton title="right" icon="rightcircleo" onPress={()=> {clickHandler(4)}} />

    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    padding: 24,
    backgroundColor: "#eaeaea",
    alignItems:"center"
  },
  title: {
    marginTop: 30,
    paddingVertical: 8,
    color: "#20232a",
    textAlign: "center",
    fontSize: 30,
    fontWeight: "bold"
  },
  m1:{
    marginTop:20
  }

});
// export default Manual;


