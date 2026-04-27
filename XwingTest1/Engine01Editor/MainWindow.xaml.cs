using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace Engine01Editor
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            Loaded += OnMainWindowLoaded;
        }

        private void OnMainWindowLoaded(object sender, RoutedEventArgs e)
        {
            // Handle the Loaded event here
            Loaded -= OnMainWindowLoaded; // Unsubscribe to prevent multiple calls
            OpenProjectBrowserDialog();
        }

        private void OpenProjectBrowserDialog()
        {
            var projectBrowserDialog = new GameProject.ProjectBrowserDialog();
            if(projectBrowserDialog.ShowDialog() == false)
            {                 // User canceled the dialog, close the application
                Application.Current.Shutdown();
            }
            else
            { 
            
            }
        }
    }
}