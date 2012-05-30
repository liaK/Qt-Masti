function writeInBrowser()
{
	var firstNumber = Number(document.getElementById('fName').value);
	var secNumber = Number(document.getElementById('sName').value);
	var sum = firstNumber+secNumber;
	document.getElementById('sum').value = firstNumber+secNumber;
	<!-->document.write("The sum is "+sum);<-->
}

		

function calculateSum()
{
	if(window.CPPWorker)
	{
		var successFun = function(){alert("Success")};
		var failureFun = function(){alert("Failure")};		

		var firstNumber = Number(document.getElementById('fName').value);
		var secNumber = Number(document.getElementById('sName').value);
		CPPWorker.success.connect(successFun);
		CPPWorker.failure.connect(failureFun);
		document.getElementById('sum').value = window.CPPWorker.sum(firstNumber,secNumber);
		<!-->document.getElementById('sum').value = "MayBe :)";<-->
	}
}

function valuesEntered()
{
	return "This is from javascript";
}

function cancelCalculation()
{
	document.getElementById('sum').value = CPPWorker.cppString();
}


