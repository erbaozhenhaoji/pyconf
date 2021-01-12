/*************************************************************************
	> File Name: test_conf.cpp
	> Author: Paul Yang
	> Mail: zhenhaoji@gmail.com 
	> Created Time: 五  1/ 8 15:14:50 2021
 ************************************************************************/

#include <stdio.h>
#include <assert.h>
#include <py_conf.h>

int main(int argc, char* argv[])
{
	int ret = 0;
	char value[1204];

	CONFDATA* confdata = NULL;

	confdata = confdata_create(100);
	assert(confdata);


	if(confdata_additem(confdata, "name", "Tom")<0){
		assert(0);
	}
	if(confdata_additem(confdata, "age", "23")<0){
		assert(0);
	}
	if(confdata_additem(confdata, "score", "99")<0){
		assert(0);
	}

	if(confdata_delitem(confdata, "age")==1){
		fprintf(stdout, "the item of %s has been deleted\n", "age");
	}

	if(confdata_save(confdata, "./", "myconf.ini")!=0){
		assert(0);
	}

	confdata_delete(confdata);

	confdata = confdata_load("./myconf.ini");
	assert(confdata);

	ret = confdata_getitem(confdata, "name", value, sizeof(value));
	if(ret==1){
		fprintf(stdout, "there is the key %s, value=%s\n", "name", value);
	}
	else if(ret==0){
		fprintf(stdout, "there is NO key %s\n", "name");
	}
	else {
		fprintf(stdout, "error when happend.\n");
	}

	confdata_delete(confdata);

	return 0;
}

