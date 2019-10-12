public class Linked_List<T extends Comparable<T>> {

	private class Node implements Comparable<Node> {
		T data;
		Node next;

		Node(T data, Node next) {
			this.data = data;
			this.next = next;
		}

		public int compareTo(Linked_List<T>.Node node) {
			return this.data.compareTo(node.data);
		}
	}

	private Node head;
	private Node tail;
	private int size;

	public Linked_List() {
		this.head = null;
		this.tail = null;
		size = 0;
	}

	public int size() {
		return this.size;
	}

	public boolean isEmpty() {
		return size() == 0;
	}

	public T getFirst() throws Exception {
		if (isEmpty()) {
			throw new Exception("Invalid Operation");
		}

		return this.head.data;
	}

	public T getLast() throws Exception {
		if (isEmpty()) {
			throw new Exception("Invalid Operation");
		}

		return this.tail.data;
	}

	public T getAt(int idx) throws Exception {
		Node temp = getNodeAt(idx);
		return temp.data;
	}

	private Node getNodeAt(int idx) throws Exception {      // O(N) complexity
		if (idx < 0 || idx >= this.size()) {
			throw new Exception("Invalid Operation");
		}

		int counter = 0;
		Node temp = this.head;

		while (counter < idx) {
			temp = temp.next;
			counter++;
		}

		return temp;
	}

	public void addFirst(T data) {
		Node newNode = new Node(data, this.head);
		this.head = newNode;
		if (isEmpty()) {
			this.tail = newNode;
		}
		this.size++;
	}

	public void addLast(T data) {
		Node newNode = new Node(data, null);

		if (isEmpty()) {
			this.head = newNode;
			this.tail = newNode;
		} else {
			this.tail.next = newNode;
			this.tail = newNode;
		}
		this.size++;
	}

	public void addAt(T data, int idx) throws Exception {
		if (idx < 0 || idx > size()) {
			throw new Exception("Invalid Operation");
		}

		if (idx == 0) {
			addFirst(data);
		} else if (idx == size()) {
			addLast(data);
		} else {
			Node temp = getNodeAt(idx - 1);
			Node newNode = new Node(data, temp.next);
			temp.next = newNode;

			this.size++;
		}
	}

	public T removeFirst() throws Exception {
		if (isEmpty()) {
			throw new Exception("Invalid Operation");
		}

		T temp = this.head.data;
		this.head = this.head.next;

		if (this.size() == 1)
			this.tail = null;

		size--;
		return temp;
	}

	public T removeLast() throws Exception {
		if (isEmpty()) {
			throw new Exception("Invalid Operation");
		}

		T tempdata = this.tail.data;

		if (this.size() == 1) {
			this.head = null;
			this.tail = null;
		} else {
			Node temp = getNodeAt(this.size() - 2);
			temp.next = null;
			this.tail = temp;
		}
		this.size--;
		return tempdata;
	}

	public T removeAt(int idx) throws Exception {
		if (idx < 0 || idx >= this.size()) {
			throw new Exception("Invalid Operation");
		}

		if (idx == 0) {
			return removeFirst();
		} else if (idx == this.size() - 1) {
			return removeLast();
		} else {
			Node temp = getNodeAt(idx - 1);
			T retval = temp.next.data;

			temp.next = temp.next.next;
			this.size--;

			return retval;
		}

	}

	public void display() {
		System.out.println(this);
	}

	public String toString() {
		String retval = "";

		Node temp = this.head;
		while (temp != null) {
			retval += temp.data + " => ";
			temp = temp.next;
		}
		retval += "END";

		return retval;
	}

}
