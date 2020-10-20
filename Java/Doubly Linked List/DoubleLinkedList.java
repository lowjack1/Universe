public class DoubleLinkedList {
	
	private Node head;
	private Node tail;
	private Node current;
	private int size;
	
	public DoubleLinkedList() {
		this.head = null;
		this.tail = null;
		this.current = null;
		this.size = 0;
	}
	 
	public void insertLast(int value) {
		Node newNode = new Node(value);
		if(isEmpty()) {
			head = newNode;
			tail = newNode;
		} else {
			tail.setNext(newNode);
			newNode.setPrevious(tail);
			tail = newNode;
		}
		size++;
	}
	
	public void insertFirst(int value) {
		Node newNode = new Node(value);
		if(isEmpty()) {
			head = newNode;
			tail = newNode;
		} else {
			head.setPrevious(newNode);
			newNode.setNext(head);
			head = newNode;
		}
		size++;
	}
	
	public void remove(int value) {
		if(head.getValor() == value) {
			head = head.getNext();
		} else if(tail.getValue() == value) {
			tail = tail.getPrevious();
		}
		if(search(value)) {
			current.getPrevious().setNext(current.getNext());
			current.getNext().setPrevious(current.getPrevious());
		}
	}
	
	public int size() {
		return this.size;
	}
	
	public boolean search(int value) {
		current = head;
		while(current != null) {
			if(current.getValue() == value) {
				return true;
			}
			current = current.getNext();
		}
		return false;
	}
	
	public boolean isEmpty() {
		if(this.head == null) {
			return true;
		}
		return false;
	}
	
	public String toString() {
		Node current = head;
		String string = "Contents: \n <-->";
		
		while(current != null) {
			string = string + current.getValue() + "<--->";
			current = current.getNext();
		}
		return string;
	}
	
}
