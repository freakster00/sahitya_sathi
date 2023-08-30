#include <gtk/gtk.h>
#include <stdlib.h>
#include <dirent.h>
void list_blogs();
char file_names[100][256];
int num_files = 0;
struct poem_{
        char lines[10000];
        char title[100];
        char description[100];
        char date[100];
        char category[100];
        char author[100];
    };

void custom_cleanup_function(GtkWidget *widget, gpointer data) {
    
    
    gtk_widget_destroy(widget);
    gtk_main_quit();

    

}

static void view_all_blogs(GtkWidget *widget, gpointer data) {

        // Create a new window for the scrollable content
        list_blogs();
        char label_text[100000];
        struct poem_ poem_instance1;
    GtkWidget *scrollable_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(scrollable_window), "All Blogs");
    gtk_window_set_default_size(GTK_WINDOW(scrollable_window), 1000, 800);

    GtkWidget *scrolled_window = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window),
                                   GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);

    GtkWidget *content_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);

    // Add multiple strings to the content box using a loop
    
    for (int i = 0; i < num_files; i++) {
        
       
        struct poem_ poem_fetchers[num_files];
        char available_blogs[1000];
        snprintf(available_blogs, sizeof(available_blogs), "logs/%s", file_names[i]);
    
        FILE* poem_db11 = fopen(available_blogs, "r");
    if (poem_db11 == NULL) {
        perror("Error opening poem_db.txt");
        
    }
while (fscanf(poem_db11, "%[^-]--%[^-]--%[^-]--%[^-]--%[^-]--%[^\n]\n",
                  poem_instance1.lines,
                  poem_instance1.title,
                  poem_instance1.description,
                  poem_instance1.date,
                  poem_instance1.category,
                  poem_instance1.author) != EOF) {

       
    }
        char text[50000];
        snprintf(text, sizeof(text), "Title:%s\n\n\nContent:\n%s\nDescription:\n\n%s\nDate:%s\n\nCategory:\n%s\n\nAuthor:\n%s\n"
        "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------",poem_instance1.title,poem_instance1.lines,poem_instance1.description,poem_instance1.date,poem_instance1.category,poem_instance1.author);

        // Create labels to display strings
        GtkWidget *label = gtk_label_new(text);
        gtk_box_pack_start(GTK_BOX(content_box), label, FALSE, FALSE, 0);
        
    }

    gtk_container_add(GTK_CONTAINER(scrolled_window), content_box);
    gtk_container_add(GTK_CONTAINER(scrollable_window), scrolled_window);

    gtk_widget_show_all(scrollable_window);


}


void on_entry_activate(GtkEntry *entry, gpointer user_data) {

    const gchar *text = gtk_entry_get_text(entry);
    
    char x[100];
   strcpy(x,text);
    char filename1[1000];
    char filename2[1000];
    snprintf(filename1, sizeof(filename1), "./logs/%s.txt", x);
    snprintf(filename2, sizeof(filename2),"/mnt/e/first_year_c_project/sahitya_sathi/content/posts/%s.md", x);

    const char *filename = filename1;
    const char *filename_web = filename2;

    if (remove(filename) == 0) {
        printf("File '%s' deleted successfully.\n", filename);

        if (remove(filename_web) == 0) {
        printf("File '%s' deleted successfully.\n", filename_web);
        gtk_main_quit();
        
    } else {
        perror("Error deleting file");
    }
        gtk_main_quit();
        
    } else {
        perror("Error deleting file");
    }
    
    gtk_main_quit();
    
    
   
   
    
}
static void delete_a_blog(GtkWidget *widget, gpointer data,int argc, char *argv[]) {
    // g_print("You clicked the Rohan\n");
     gtk_init(&argc, &argv);

    GtkWidget *window;
    GtkWidget *label;
    GtkWidget *labels[num_files];
    GtkWidget *entry;
    GtkWidget *button;

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Input Window");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 150);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_widget_hide), NULL);
    
    
    label = gtk_label_new("Please enter the slug of the blog:");
    entry = gtk_entry_new();
    g_signal_connect(entry, "activate", G_CALLBACK(on_entry_activate), NULL);

    button = gtk_button_new_with_label("Submit");
    g_signal_connect_swapped(button, "clicked", G_CALLBACK(on_entry_activate), entry);

    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_container_add(GTK_CONTAINER(window), box);
    gtk_box_pack_start(GTK_BOX(box), label, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), entry, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), button, FALSE, FALSE, 0);

    gtk_widget_show_all(window);

    gtk_main();

    
}
static void add_new_blog(GtkWidget *widget, gpointer data) {
    const char *exePath = "./program_.exe"; // Replace with the actual path to your .exe file

    int status = system(exePath);

    if (status == 0) {
        printf("Record SuccessFully Created.\n");
    } else {
        printf("Error Occured.\n");
    }

    
}

int main(int argc, char *argv[]) {
    GtkWidget *window;
    GtkWidget *button1;
    
    GtkWidget *button3;
    GtkWidget *button4;
    GtkWidget *box;

    // Initialize GTK
    gtk_init(&argc, &argv);

    // Create the main window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Sahitya Sathi");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 700);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Create a vertical box container
    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

    gtk_container_add(GTK_CONTAINER(window), box);

    // Create buttons and adjust their sizes
    button1 = gtk_button_new_with_label("View All Blogs");
    
    button3 = gtk_button_new_with_label("Delete A Blog");
    button4 = gtk_button_new_with_label("Add A New Blog");

    gtk_widget_set_size_request(button1, 10, 40);  // Width, Height
    
    gtk_widget_set_size_request(button3, 150, 40);
    gtk_widget_set_size_request(button4, 150, 40);

    // Connect signals
    g_signal_connect(button1, "clicked", G_CALLBACK(view_all_blogs), NULL);
    
    g_signal_connect(button3, "clicked", G_CALLBACK(delete_a_blog), NULL);
    g_signal_connect(button4, "clicked", G_CALLBACK(add_new_blog), NULL);

    // Pack buttons in the box
    gtk_box_pack_start(GTK_BOX(box), button1, TRUE, TRUE, 10);
    gtk_box_pack_start(GTK_BOX(box), button3, TRUE, TRUE, 20);
    gtk_box_pack_start(GTK_BOX(box), button4, TRUE, TRUE, 20);

    // Show all the elements
    gtk_widget_show_all(window);

    // Run the GTK main loop
    gtk_main();

    return 0;
}

void list_blogs(){
    // Adjust sizes as needed
    
    const char *folder_path = "./logs"; // Use "." for the current folder
    DIR *dir;
    struct dirent *entry;

    dir = opendir(folder_path);
    if (dir == NULL) {
        perror("Error opening directory");
        
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // Check if it's a regular file
            strcpy(file_names[num_files], entry->d_name);
            num_files++;
        }
        }
    
    
    closedir(dir);
    
    

}