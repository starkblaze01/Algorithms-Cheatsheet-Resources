class MergeSort{

	int array[]={10,20,51,11,42,32,78,95,15};


	public void merge(int left, int mid, int right){

		int temp[]=new int[right-left+1];
		int i=left;
		int j=mid+1;
		int k=0;

		while(i<=mid && j<=right)
		{
			if(array[i] <= array[j])
			{
				temp[k]=array[i];
				k++;
				i++;
			}

			else
			{
				temp[k]=array[j];
				k++;
				j++;
			}
		}

		while(j<=right)
		{
			temp[k++]=array[j++];
		}

		while(i<=mid)
		{
			temp[k++]=array[i++];
		}

		for(k=0; k<temp.length; k++)
		{
			array[left+k]=temp[k];
		}

	}

	public void mergeSort(int left, int right)
	{
		if(left<right){

			int mid =(left + right)/2;

			mergeSort(left,mid);
			mergeSort(mid+1,right);
			merge(left,mid,right);
		}
	}

	public void print()
	{
		for(int i=0; i<array.length; i++)
		{
			System.out.print(array[i]+" ");
		}
		System.out.println();

	}

	public static void main(String args[])
	{
		MergeSort ob =new MergeSort();

		ob.print();
		//ob.merge(0,5,8);
		ob.mergeSort(0,8);

		ob.print();


	}
}