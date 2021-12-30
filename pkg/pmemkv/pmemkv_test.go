package pmemkv

import (
	"encoding/json"
	"fmt"
	"os"
	"testing"
)

func startFailureFunc(engine string, config string, msg string) {
	fmt.Printf("Error: %s, %s, %s\n", engine, config, msg)
	os.Exit(1)
}

func allFunc(key string) {
	fmt.Printf("%s\n", key)
}

// KVEachFunction -- callback prototype for each functions
func kvEachFunction(key string, value string) {
	fmt.Printf("k-> %s, v-> %s\n", key, value)
}

type Config struct {
	Path string `json:"path"`
}

func TestPMemKV(t *testing.T)  {
	bytes, err := json.Marshal(Config{
		Path: "/mnt/mem",
	})
	if err != nil {
		t.Error(err.Error())
	}
	kv, err := StartKVEngine("vsmap", string(bytes), startFailureFunc)
	if err != nil {
		panic(err)
	}
	defer kv.Stop()
	if err := kv.Put("key1", "value1"); err != nil {
		fmt.Println("Error: ", err)
		os.Exit(1)
	}
	if kv.Count() != 1 {
		fmt.Println("Count should be 1")
		os.Exit(1)
	}
	if err := kv.Put("key2", "value2"); err != nil {
		fmt.Println("Error: ", err)
		os.Exit(1)
	}
	if err := kv.Put("key3", "value3"); err != nil {
		fmt.Println("Error: ", err)
		os.Exit(1)
	}
	if kv.Count() != 3 {
		fmt.Println("Count should be 3")
		os.Exit(1)
	}
	kv.All(allFunc)

	if err := kv.Remove("key1"); err != nil {
		fmt.Println("Error: ", err)
		os.Exit(1)
	}

	kv.Each(kvEachFunction)

	if err := kv.Exists("key1"); err != nil {
		fmt.Println("Should not be able to find key1: ", err)
	}
}