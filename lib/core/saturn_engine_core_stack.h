// public
void saten_stack_init(saten_stack **sptr, size_t s)
{
    if (*sptr != NULL)
        saten_errhandler(13);
    *sptr = (saten_stack*)saten_malloc(sizeof(saten_stack));
    (*sptr)->size = s;
}

// public
int saten_stack_grow(saten_stack **sptr, int n)
{
    int i = (*sptr)->num;
    (*sptr)->num += n;
    (*sptr)->data = saten_realloc((*sptr)->data, (*sptr)->num * (*sptr)->size);
    return i; // return index of lowest new item
}

// public
/*
 * Removes items from the end
*/
void saten_stack_shrink(saten_stack **sptr, int n)
{
    (*sptr)->num -= n;
    (*sptr)->data = saten_realloc((*sptr)->data, (*sptr)->num * (*sptr)->size);
}
