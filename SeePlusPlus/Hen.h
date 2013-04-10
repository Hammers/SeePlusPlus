#ifndef HEN_CLASS
#define HEN_CLASS

class Hen {
public:
	friend class Nest;
	class Nest {
	private:
		int data;
	public:
		friend class Egg;
		class Egg {
		private:
			int data;
		public:
			void display(void);
		};
		void display(void);
	};
	void display(void);
};

#endif