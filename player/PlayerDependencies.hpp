//It is true that function code should not be placed in a header file, there is no point in making a .cpp for these two functions

/*-----------------------Functions to help in chain-----------------------*/
void merge(Holding *up,Holding *sub){
	sub->setU();
	up->setS();
	if(up->return_type()==3 && sub->return_type()==2 && sub->has_subholding())
	{	up->setFC();  //full chain has been closed
		//middle holding has both upper and sub Holdings
		//the FC(boolen) is a cheap and  easy way to check if a cyrstal mine is connected to a full chain
	}
}

bool Compatible(Holding *a,Holding *b){
	if(a->return_type() == b->return_type()) //no possible chain
		return false;
	if(a->return_type() > b->return_type()){ //b >> a possible up-sub relationship
		if(!a->has_subholding() && !b->has_upperholding())
			return true;
		else //a and/or b have up/sub holdings no possible connection
			return false;
	}
	if(a->return_type() < b->return_type()){  // a <<b possible connection
		if(!a->has_upperholding() && !b->has_subholding())
			return true;
		return false;
	}
}