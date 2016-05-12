
#ifndef SOURCE_HASH_TABLE_H_
#define SOURCE_HASH_TABLE_H_

extern struct index *insert_index(struct index *start, int data, int pos);

extern struct index *append_index(struct index *start,int data);

extern struct index *insert_node(struct index *start_I, int pos, int data, int indexNo);

extern struct index *append_node(struct index *start_I, int data, int indexNo);

extern struct index *delete_index(struct index *start, int data);

extern struct index *delete_node(struct index *start_I, int data, int indexNo);

extern void *freeallnow(struct index *start);

extern void display(struct index *start);


#endif /* SOURCE_HASH_TABLE_H_ */
