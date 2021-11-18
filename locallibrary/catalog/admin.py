from django.contrib import admin
from .models import Author,Genre,Book,BookInstance,Language
# Register your models here.

#admin.site.register(Book)
#admin.site.register(Author)
admin.site.register(Genre)
#admin.site.register(BookInstance)
admin.site.register(Language)

#define main class
class BookInline(admin.TabularInline):
    model = Book
    extra = 0

class AuthorAdmin(admin.ModelAdmin):
    list_display = ('last_name', 'first_name', 'date_of_birth', 'date_of_death')
## orders the first and last names vertically, then the dob and dod horizontally
    fields = ['first_name', 'last_name', ('date_of_birth', 'date_of_death')]
    inlines = [BookInline]

# register admin class with its related model
admin.site.register(Author,AuthorAdmin)
# Now to create and register the new models; for the purpose of this demonstration, 
# we'll instead use the @register decorator to register the models 
# (this does exactly the same thing as the admin.site.register() syntax):

# Register the Admin classes for Book using the decorator
## adding creation of book instances from the book class
class BooksInstanceInline(admin.TabularInline):
    model = BookInstance
    extra = 0
    
@admin.register(Book)
class BookAdmin(admin.ModelAdmin):
    list_display = ('title', 'author', 'display_genre')
    inlines = [BooksInstanceInline]
    order = ('title')
# Register the Admin classes for BookInstance using the decorator
#In the BookInstance model we have information related to what the book is (i.e. name, imprint, and id) 
# and when it will be available (status, due_back). We can add these to our BookInstanceAdmin class as shown below,
#  using the fieldsets property.

@admin.register(BookInstance)
class BookInstanceAdmin(admin.ModelAdmin):
    list_display = ('book','status','due_back','id')
    order = ('-status','due_back')
    list_filter = ('status', 'due_back')

    fieldsets = (
        (None, {
            'fields': ('book', 'imprint', 'id')
        }),
        ('Availability', {
            'fields': ('status', 'due_back')
        }),
    )

