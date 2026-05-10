using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Runtime.Serialization;
using System.Text;
using System.Threading.Tasks;

using Engine01Editor.Common;
using Engine01Editor.Utilities;

namespace Engine01Editor.GameProject
{
    [DataContract ]
    public class ProjectTemplate
    {
        [DataMember]
        public string ProjectType { get; set; } = string.Empty;
        [DataMember]
        public string ProjectFile { get; set; } = string.Empty;
        [DataMember]
        public List<string> Folders { get; set; } = new();

    }


    class NewProject : ViewModelBase
    {
        private readonly string _templatesPath = @"..\..\Engine01Editor\ProjectTemplates\";
        private string _name = "NewProject";
        public string Name
        {
            get => _name;
            set
            {
                if (_name != value)
                {
                    _name = value;
                    OnPropertyChanged(nameof(Name));
                }
            }
        }

        private string _path = $@"{Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments)}\Engine01Projects\";
        public string Path
        {
            get => _path;
            set
            {
                if (_path != value)
                {
                    _path = value;
                    OnPropertyChanged(nameof(Path));
                }
            }
        }

        public NewProject()
        {
            try
            {
                var templatesFiles = Directory.GetFiles(_templatesPath, "template.xml", SearchOption.AllDirectories);
                Debug.Assert(templatesFiles.Any());

                foreach (var file in templatesFiles)
                {
                    var template = new ProjectTemplate
                    {
                        ProjectType = "Empty Project",
                        ProjectFile = "project.Engine01",
                        Folders = new List<string> { ".Engine01", "Content", "GameCode" }
                    };
                    
                    Serializer.ToFile(template, file);
                }
            }
            catch (Exception ex)
            {
                // Handle exceptions (e.g., log the error, show a message to the user, etc.)
                Debug.WriteLine($"Error loading project templates: {ex.Message}");
            }
        }
    }
}
